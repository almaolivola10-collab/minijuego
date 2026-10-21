/*
============================================================
Materia: Laboratorio de Programacion (LPR) - 5to Ano
Institucion: E.E.S.T. N° 1 - Vicente Lopez
Archivo: src/main.cpp
Actividad 7: Piedra, Papel o Tijera
Persistencia e historial de partidas
============================================================
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

struct Partida {
int idPartida;
string jugador;
string eleccionJugador;
string eleccionIA;
string resultado;
};

const string ARCHIVO_HISTORIAL = "historial_partidas.txt";

void jugarPartida(int& contadorID);
void guardarEnDisco(const Partida& p);
void leerHistorialDisco();
int obtenerSiguienteID();

int main() {
srand(static_cast<unsigned int>(time(0)));

int contadorID = obtenerSiguienteID();
int opcion;

cout << "========================================\n";
cout << " PIEDRA, PAPEL O TIJERA\n";
cout << "========================================\n";

do {
cout << "\n--- MENU PRINCIPAL ---\n";
cout << "1. Jugar partida\n";
cout << "2. Ver historial de partidas\n";
cout << "3. Salir\n";
cout << "Ingrese una opcion: ";

if (!(cin >> opcion)) {
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "\nIngrese un numero valido.\n";
continue;
}

if (opcion == 1) {
jugarPartida(contadorID);
}
else if (opcion == 2) {
leerHistorialDisco();
}
else if (opcion == 3) {
cout << "\nSaliendo del programa...\n";
cout << "Las partidas quedaron guardadas.\n";
}
else {
cout << "\nOpcion incorrecta. Intente nuevamente.\n";
}

} while (opcion != 3);

return 0;
}

// Obtiene el numero de la siguiente partida
int obtenerSiguienteID() {
ifstream archivo(ARCHIVO_HISTORIAL);

int id, ultimoID = 0;
string jugador, eleccionJugador, eleccionIA, resultado;

while (
archivo >> id &&
archivo.ignore(numeric_limits<streamsize>::max(), ',') &&
getline(archivo, jugador, ',') &&
getline(archivo, eleccionJugador, ',') &&
getline(archivo, eleccionIA, ',') &&
getline(archivo, resultado)
) {
if (id > ultimoID) {
ultimoID = id;
}
}

return ultimoID + 1;
}

// Permite jugar una partida
void jugarPartida(int& contadorID) {
Partida p;
p.idPartida = contadorID;

cout << "\n--- NUEVA PARTIDA ---\n";
cout << "Ingrese su nombre: ";

cin.ignore(numeric_limits<streamsize>::max(), '\n');
getline(cin, p.jugador);

if (p.jugador.empty()) {
p.jugador = "Jugador";
}

int opcJugador;

cout << "\nElija su jugada:\n";
cout << "1. Piedra\n";
cout << "2. Papel\n";
cout << "3. Tijera\n";
cout << "Opcion: ";

if (!(cin >> opcJugador)) {
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "Entrada invalida. Se cancelo la partida.\n";
return;
}

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
cout << "Opcion invalida. Se cancelo la partida.\n";
return;
}

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

cout << "\n" << p.jugador << " eligio: "
<< p.eleccionJugador << "\n";

cout << "La computadora eligio: "
<< p.eleccionIA << "\n";

if (p.eleccionJugador == p.eleccionIA) {
p.resultado = "Empate";
}
else if (
(p.eleccionJugador == "Piedra" &&
p.eleccionIA == "Tijera") ||
(p.eleccionJugador == "Papel" &&
p.eleccionIA == "Piedra") ||
(p.eleccionJugador == "Tijera" &&
p.eleccionIA == "Papel")
) {
p.resultado = "Victoria";
}
else {
p.resultado = "Derrota";
}

cout << "\nResultado: " << p.resultado << "\n";

guardarEnDisco(p);

// Avanza el numero solo si la partida se guardo correctamente
ifstream comprobacion(ARCHIVO_HISTORIAL);
if (comprobacion.is_open()) {
contadorID++;
}
}

// Guarda la partida en el archivo de texto
void guardarEnDisco(const Partida& p) {
ofstream archivo(ARCHIVO_HISTORIAL, ios::app);

if (!archivo.is_open()) {
cout << "Error: no se pudo guardar la partida.\n";
return;
}

archivo << p.idPartida << ","
<< p.jugador << ","
<< p.eleccionJugador << ","
<< p.eleccionIA << ","
<< p.resultado << "\n";

if (archivo.good()) {
cout << "Partida guardada correctamente.\n";
}
else {
cout << "Error al escribir la partida.\n";
}

archivo.close();
}

// Muestra el historial de partidas guardadas
void leerHistorialDisco() {
ifstream archivo(ARCHIVO_HISTORIAL);

if (!archivo.is_open()) {
cout << "\nTodavia no hay partidas guardadas.\n";
return;
}

cout << "\n========================================\n";
cout << " HISTORIAL DE PARTIDAS\n";
cout << "========================================\n";

string linea;
int total = 0;

while (getline(archivo, linea)) {
if (linea.empty()) {
continue;
}

// Separa los datos guardados usando las comas
size_t pos1 = linea.find(',');
size_t pos2 = linea.find(',', pos1 + 1);
size_t pos3 = linea.find(',', pos2 + 1);
size_t pos4 = linea.find(',', pos3 + 1);

if (pos1 == string::npos ||
pos2 == string::npos ||
pos3 == string::npos ||
pos4 == string::npos) {
continue;
}

string id = linea.substr(0, pos1);
string jugador = linea.substr(pos1 + 1, pos2 - pos1 - 1);
string eleccionJugador = linea.substr(pos2 + 1, pos3 - pos2 - 1);
string eleccionIA = linea.substr(pos3 + 1, pos4 - pos3 - 1);
string resultado = linea.substr(pos4 + 1);

cout << "\nPartida #" << id << "\n";
cout << "Jugador: " << jugador << "\n";
cout << "Eleccion del jugador: " << eleccionJugador << "\n";
cout << "Eleccion de la computadora: " << eleccionIA << "\n";
cout << "Resultado: " << resultado << "\n";

total++;
}

archivo.close();

if (total == 0) {
cout << "El historial esta vacio.\n";
}
else {
cout << "\nTotal de partidas: " << total << "\n";
}
}

