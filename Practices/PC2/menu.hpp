#include "structFunctions.hpp"

using namespace std;

void showAppTitle(libraryStruct library) {
  cout << endl
       << "-----------------------------------------------------------" << endl;
  cout << "\t Sistema de la biblioteca de la universidad "
       << library.universityName << endl
       << endl
       << endl;
  cout << "-----------------------------------------------------------" << endl;
}

int requestMenuOption(libraryStruct library) {
  int selectedOption;

  clearScreen();
  showAppTitle(library);

  cout << endl
       << "Esta aplicación tiene las siguientes opciones:" << endl
       << endl;

  cout << "[1] Listar todas las salas de la biblioteca" << endl;
  cout << "[2] Listar alumnos haciendo cola en TODAS las salas de la biblioteca"
       << endl;
  cout << "[3] Listar alumnos haciendo cola en una sala de la biblioteca"
       << endl;
  cout << "[4] Listar TODOS los libros por ser prestados a TODOS los "
          "estudiantes en las colas"
       << endl;
  cout << "[5] Listar libros por ser prestados a un estudiante" << endl;
  cout << endl;
  cout << "[6] Registrar nuevo alumno/a" << endl;
  cout << "[7] Añadir libro a pila de libros de alumno" << endl;
  cout << "[8] Prestar libros a alumno" << endl;
  cout << endl;
  cout << "[0] Cerrar" << endl;

  cout << endl << "Por favor ingrese una de las opciones:" << endl;
  cin >> selectedOption;
  while (!(0 <= selectedOption && selectedOption <= 8)) {
    cout << "La opcion seleccionada fue inválida, por favor seleccione una "
            "opcion válida:"
         << endl;
    cin >> selectedOption;
  }
  return selectedOption;
}

void mainMenu(libraryStruct &library) {
  int selectedOption;

  do {
    selectedOption = requestMenuOption(library);

    if (selectedOption != 0) {
      switch (selectedOption) {
        case 1:
          // showAllRooms(library);
          pauseProcess();
          break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}
