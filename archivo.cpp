cout << "Ingresa el idioma al que quieres traducir el codigo (ej. 'es' para espanol): ";
    string idiomaDestino;
    cin >> idiomaDestino;
    cin.ignore(); // Limpiar el buffer de entrada

    // Concatenar todas las líneas de código en una sola cadena
    string codigoCompleto;
    for (const string& l : lineasCodigo) {
        codigoCompleto += l + "\n";
    }

    // Llamar a la función para traducir el código
    string codigoTraducido = traducirCodigo(codigoCompleto, idiomaDestino);

    // Mostrar el código original y el código traducido
    cout << "\nCódigo original:\n" << codigoCompleto << endl;
    cout << "\nCódigo traducido:\n" << codigoTraducido << endl;

    return 0;
}
