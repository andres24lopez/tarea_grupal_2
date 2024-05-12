#include <iostream>
#include <string>
#include <vector>

using namespace std;

string traducirCodigo(const string& codigo, const string& idiomaDestino) {
    // Aquí podrías agregar la lógica para traducir el codigo
    return codigo;
}

int main() {
    cout << "Bienvenido al programa de traduccion de codigo." << endl;
    cout << "Por favor, ingresa tu codigo linea por linea. Escribe 'fin' para finalizar la entrada." << endl;
    
    vector<string> lineasCodigo;
    string linea;
    while (true) {
        getline(cin, linea);
        if (linea == "fin") {
            break;
        }
        lineasCodigo.push_back(linea);
    }