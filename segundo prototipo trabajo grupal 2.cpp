#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void agregarPalabra(const string& archivo) {
    ofstream file(archivo, ios::binary | ios::app);
    if (!file.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    char palabra[50];
    char traduccion[50];
    char funcionalidad[100];

    cout << "Ingrese Palabra: ";
    cin >> palabra;
    cout << "Ingrese Traduccion: ";
    cin >> traduccion;
    cout << "Ingrese Funcionalidad: ";
    cin.ignore();
    cin.getline(funcionalidad, sizeof(funcionalidad));

    file.write(palabra, sizeof(palabra));
    file.write(traduccion, sizeof(traduccion));
    file.write(funcionalidad, sizeof(funcionalidad));

    file.close();
}

void mostrarPalabras(const string& archivo) {
    ifstream file(archivo, ios::binary);
    if (!file.is_open()) {
        cout << "El archivo esta vacio." << endl;
        return;
    }

    cout << "Palabra\t\tTraduccion\t\tFuncionalidad" << endl;
    cout << "-----------------------------------------------" << endl;

    char palabra[50];
    char traduccion[50];
    char funcionalidad[100];

    while (file.read(palabra, sizeof(palabra))) {
        file.read(traduccion, sizeof(traduccion));
        file.read(funcionalidad, sizeof(funcionalidad));

        cout << palabra << "\t\t" << traduccion << "\t\t" << funcionalidad << endl;
    }

    file.close();
}

void actualizarPalabra(const string& archivo) {
    ifstream file(archivo, ios::binary);
    ofstream tempFile("temp.dat", ios::binary | ios::app);

    if (!file.is_open() || !tempFile.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    string palabraBuscada;
    cout << "Ingrese la palabra que desea actualizar: ";
    cin >> palabraBuscada;

    char palabra[50];
    char traduccion[50];
    char funcionalidad[100];
    bool encontrado = false;

    while (file.read(palabra, sizeof(palabra))) {
        file.read(traduccion, sizeof(traduccion));
        file.read(funcionalidad, sizeof(funcionalidad));

        if (palabraBuscada == palabra) {
            encontrado = true;
            cout << "Ingrese nueva traduccion: ";
            cin >> traduccion;
            cout << "Ingrese nueva funcionalidad: ";
            cin.ignore();
            cin.getline(funcionalidad, sizeof(funcionalidad));
        }

        tempFile.write(palabra, sizeof(palabra));
        tempFile.write(traduccion, sizeof(traduccion));
        tempFile.write(funcionalidad, sizeof(funcionalidad));
    }

    file.close();
    tempFile.close();

    if (!encontrado) {
        cout << "Palabra no encontrada." << endl;
        remove("temp.dat");
        return;
    }

    remove(archivo.c_str());
    rename("temp.dat", archivo.c_str());
    cout << "Palabra actualizada exitosamente." << endl;
}

void borrarPalabra(const string& archivo) {
    ifstream file(archivo, ios::binary);
    ofstream tempFile("temp.dat", ios::binary | ios::app);

    if (!file.is_open() || !tempFile.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    string palabraBuscada;
    cout << "Ingrese la palabra que desea borrar: ";
    cin >> palabraBuscada;

    char palabra[50];
    char traduccion[50];
    char funcionalidad[100];
    bool encontrado = false;

    while (file.read(palabra, sizeof(palabra))) {
        file.read(traduccion, sizeof(traduccion));
        file.read(funcionalidad, sizeof(funcionalidad));

        if (palabraBuscada == palabra) {
            encontrado = true;
            continue;
        }

        tempFile.write(palabra, sizeof(palabra));
        tempFile.write(traduccion, sizeof(traduccion));
        tempFile.write(funcionalidad, sizeof(funcionalidad));
    }

    file.close();
    tempFile.close();

    if (!encontrado) {
        cout << "Palabra no encontrada." << endl;
        remove("temp.dat");
        return;
    }

    remove(archivo.c_str());
    rename("temp.dat", archivo.c_str());
    cout << "Palabra borrada exitosamente." << endl;
}

int main() {
    const string archivo = "diccionario.dat";
    int opcion;

    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Agregar Palabra" << endl;
        cout << "2. Mostrar Palabras" << endl;
        cout << "3. Actualizar Palabra" << endl;
        cout << "4. Borrar Palabra" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarPalabra(archivo);
                break;
            case 2:
                mostrarPalabras(archivo);
                break;
            case 3:
                actualizarPalabra(archivo);
                break;
            case 4:
                borrarPalabra(archivo);
                break;
            case 5:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion invalida. Intentelo de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}
