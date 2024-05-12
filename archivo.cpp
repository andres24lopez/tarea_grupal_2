cout << "Ingresa el idioma al que quieres traducir el codigo (ej. 'es' para espanol): ";
    string idiomaDestino;
    cin >> idiomaDestino;
    cin.ignore(); // Limpiar el buffer de entrada

    // Concatenar todas las l�neas de c�digo en una sola cadena
    string codigoCompleto;
    for (const string& l : lineasCodigo) {
        codigoCompleto += l + "\n";
    }

    // Llamar a la funci�n para traducir el c�digo
    string codigoTraducido = traducirCodigo(codigoCompleto, idiomaDestino);

    // Mostrar el c�digo original y el c�digo traducido
    cout << "\nC�digo original:\n" << codigoCompleto << endl;
    cout << "\nC�digo traducido:\n" << codigoTraducido << endl;

    return 0;
}
