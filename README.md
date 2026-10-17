# Piedra, Papel o Tijera

## Descripción del proyecto

Este proyecto consiste en un mini juego de Piedra, Papel o Tijera desarrollado en C++ para la materia Laboratorio de Programación de 5.º año.

El juego permite que el usuario juegue contra la computadora. En cada partida, ambos realizan una elección y el programa determina si el resultado es una victoria, una derrota o un empate.

Además, el programa guarda automáticamente los resultados en un archivo de texto llamado `historial_partidas.txt`, para poder consultar las partidas anteriores aunque se cierre el programa.

## Datos del proyecto

- **Estudiante:** Alma Olivola
- **Materia:** Laboratorio de Programación
- **Curso:** 5.º año
- **Actividad:** 7 - Mini juego Piedra, Papel o Tijera con persistencia de datos
- **Lenguaje de programación:** C++
- **Año:** 2026

## Objetivos

- Crear un juego utilizando C++.
- Utilizar una estructura `struct` para organizar los datos de cada partida.
- Practicar el uso de funciones y estructuras condicionales.
- Generar elecciones aleatorias para la computadora.
- Guardar y leer información mediante archivos de texto.
- Comprender cómo funciona la persistencia de datos.

## Tecnologías utilizadas

- C++
- Visual Studio Code
- Compilador g++
- Librería `iostream`
- Librería `fstream`
- Librería `string`
- Librería `cstdlib`
- Librería `ctime`

## Estructura del proyecto

```text
piedrapapelotijera/
│
├── src/
│   ├── main.cpp
│   └── historial_partidas.txt
│
├── docs/
│   └── manuales/
│
├── capturas/
├── README.md
├── .gitignore
├── .gitattributes
└── LICENSE
```

El archivo `historial_partidas.txt` se genera al guardar la primera partida, siempre que la ruta sea correcta.

## Cómo jugar

Al iniciar el programa, aparece un menú con tres opciones:

1. Jugar partida: permite ingresar el nombre del jugador y elegir una jugada.
2. Ver historial: muestra las partidas guardadas en el archivo de texto.
3. Salir: cierra el programa.

Las opciones disponibles son piedra, papel y tijera.

Las reglas son las siguientes:

- Piedra le gana a tijera.
- Tijera le gana a papel.
- Papel le gana a piedra.
- Si ambos eligen lo mismo, hay empate.

## Guardado de datos

El programa utiliza un archivo de texto llamado `historial_partidas.txt` para guardar los resultados de las partidas.

Para guardar los datos utiliza `ofstream` y el modo `ios::app`, que permite agregar nuevas partidas sin borrar las anteriores.

Para consultar el historial utiliza `ifstream`.

Los datos guardados incluyen el identificador de la partida, el nombre del jugador, las elecciones realizadas y el resultado.

## Compilación y ejecución

Para compilar el programa desde la carpeta principal del proyecto, ejecutar el siguiente comando en la terminal:

```powershell
g++ -std=c++11 src/main.cpp -o src/piedrapapelotijera.exe
```

Luego, ejecutar el programa con:

```powershell
.\src\piedrapapelotijera.exe
```

Estos comandos suponen que el archivo `main.cpp` está dentro de la carpeta `src` y que se utiliza Windows con g++ instalado.

## Pruebas del programa

Para comprobar el funcionamiento del programa, se pueden realizar las siguientes pruebas:

- Iniciar el juego y comprobar que aparece el menú.
- Jugar una partida y verificar el resultado.
- Consultar el historial de partidas.
- Jugar varias partidas y comprobar que se guardan los resultados anteriores.
- Cerrar y volver a abrir el programa para comprobar que el historial continúa disponible.

## Documentación

En la carpeta `docs/manuales/` se encuentran los manuales del proyecto:

- Manual de usuario: explica cómo utilizar el juego.
- Manual de programador: explica cómo está organizado el código y cómo funcionan sus principales componentes.

En la carpeta `capturas/` se guardan las imágenes que muestran el funcionamiento del programa.

## Autora

Proyecto realizado por Alma Olivola para la materia Laboratorio de Programación.

**Año:** 2026
