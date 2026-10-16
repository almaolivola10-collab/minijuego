/* 
   ====================================================================
   Materia: Laboratorio de Programación (LPR) — 5° Año
   Institución: E.E.S.T. N° 1 — Vicente López
   Archivo: src/main.cpp
   Actividad 7: Mini Juego Piedra, Papel o Tijera + Persistencia en Disco
   ====================================================================
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Estructura para guardar los datos de una partida
struct Partida {
    int idPartida;
    string jugador;
    string eleccionJugador;
    string eleccionIA;
    string resultado;
};

// Prototipos de las funciones
void jugarPartida(int& contadorID);
void guardarEnDisco(const Partida& p);
void leerHistorialDisco();

int main() {
    srand(time(0));

    int contadorID = 1;
    int opcion = 0;

    cout << "========================================" << endl;
    cout << "     PIEDRA, PAPEL O TIJERA" << endl;
    cout << "========================================" << endl;
    cout << "Estudiante: Alma Olivola " << endl;

    do {
        cout << "\n--- MENU PRINCIPAL ---" << endl;
        cout << "1. Jugar partida" << endl;
        cout << "2. Ver historial de partidas" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            jugarPartida(contadorID);
        }
        else if (opcion == 2) {
            leerHistorialDisco();
        }
        else if (opcion == 3) {
            cout << "\nSaliendo del programa..." << endl;
            cout << "Las partidas quedaron guardadas." << endl;
        }
        else {
            cout << "\nOpcion incorrecta. Intente nuevamente." << endl;
        }

    } while (opcion != 3);

    return 0;
}

// Funcion para jugar una partida
void jugarPartida(int& contadorID) {
    Partida p;

    p.idPartida = contadorID++;

    cout << "\n--- NUEVA PARTIDA ---" << endl;
    cout << "Ingrese su nombre: ";

    cin.ignore();
    getline(cin, p.jugador);

    int opcJugador;

    cout << "\nElija su jugada:" << endl;
    cout << "1. Piedra" << endl;
    cout << "2. Papel" << endl;
    cout << "3. Tijera" << endl;
    cout << "Opcion: ";
    cin >> opcJugador;

    // Guardar la eleccion del jugador
    if (opcJugador == 1) {
        p.eleccionJugador = "Piedra";
    }
    else if (opcJugador == 2) {
        p.eleccionJugador = "Papel";
    }
    else if (opcJugador == 3) {
        p.eleccionJugador = "Tijera";
    }
    else {
        cout << "Opcion invalida. Se cancelo la partida." << endl;
        contadorID--;
        return;
    }

    // Eleccion aleatoria de la computadora
    int opcIA = (rand() % 3) + 1;

    if (opcIA == 1) {
        p.eleccionIA = "Piedra";
    }
    else if (opcIA == 2) {
        p.eleccionIA = "Papel";
    }
    else {
        p.eleccionIA = "Tijera";
    }

    // Mostrar las elecciones
    cout << "\n" << p.jugador << " eligio: "
         << p.eleccionJugador << endl;

    cout << "La computadora eligio: "
         << p.eleccionIA << endl;

    // Determinar el resultado
    if (p.eleccionJugador == p.eleccionIA) {
        p.resultado = "Empate";
    }
    else if (
        (p.eleccionJugador == "Piedra" && p.eleccionIA == "Tijera") ||
        (p.eleccionJugador == "Papel" && p.eleccionIA == "Piedra") ||
        (p.eleccionJugador == "Tijera" && p.eleccionIA == "Papel")
    ) {
        p.resultado = "Victoria";
    }
    else {
        p.resultado = "Derrota";
    }

    cout << "\nResultado: " << p.resultado << endl;

    // Guardar la partida en el archivo
    guardarEnDisco(p);
}

// Funcion para guardar los datos en el archivo
void guardarEnDisco(const Partida& p) {
    ofstream archivo("src/historial_partidas.txt", ios::app);

    if (!archivo.is_open()) {
        cout << "Error al guardar la partida." << endl;
        return;
    }

    archivo << p.idPartida << ","
            << p.jugador << ","
            << p.eleccionJugador << ","
            << p.eleccionIA << ","
            << p.resultado << endl;

    archivo.close();

    cout << "Partida guardada correctamente." << endl;
}

// Funcion para mostrar el historial
void leerHistorialDisco() {
    ifstream archivo("src/historial_partidas.txt");

    if (!archivo.is_open()) {
        cout << "\nTodavia no hay partidas guardadas." << endl;
        return;
    }

    cout << "\n========================================" << endl;
    cout << "       HISTORIAL DE PARTIDAS" << endl;
    cout << "========================================" << endl;

    string id, jugador, eleccionJugador, eleccionIA, resultado;
    int total = 0;

    while (
        getline(archivo, id, ',') &&
        getline(archivo, jugador, ',') &&
        getline(archivo, eleccionJugador, ',') &&
        getline(archivo, eleccionIA, ',') &&
        getline(archivo, resultado)
    ) {
        cout << "\nPartida #" << id << endl;
        cout << "Jugador: " << jugador << endl;
        cout << "Eleccion del jugador: " << eleccionJugador << endl;
        cout << "Eleccion de la computadora: " << eleccionIA << endl;
        cout << "Resultado: " << resultado << endl;

        total++;
    }

    archivo.close();

    if (total == 0) {
        cout << "El historial esta vacio." << endl;
    }
    else {
        cout << "\nTotal de partidas: " << total << endl;
    }
}