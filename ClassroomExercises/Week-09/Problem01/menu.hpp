#include "structFunctions.hpp"

using namespace std;

void showAppTitle() {
  cout << endl
       << "-----------------------------------------------------------" << endl;
  cout << "\t Problema - Semana 08 - Arboles " << endl << endl << endl;
  cout << "-----------------------------------------------------------" << endl;
}

int requestMenuOption(peopleThree people) {
  int selectedOption;

  clearScreen();
  showAppTitle();

  cout << endl
       << "Esta aplicación tiene las siguientes opciones:" << endl
       << endl;

  cout << "[1] Registrar persona" << endl;
  cout << "[2] Mostrar personas en pre-orden" << endl;
  cout << "[3] Mostrar personas en in-orden" << endl;
  cout << "[4] Mostrar personas en post-orden" << endl;
  cout << "[5] Buscar persona" << endl;
  cout << "[6] Eliminar persona" << endl;
  cout << "[7] Calcular altura" << endl;
  cout << endl;
  cout << "[0] Cerrar" << endl;

  cout << endl << "Por favor ingrese una de las opciones:" << endl;
  cin >> selectedOption;
  while (!(0 <= selectedOption && selectedOption <= 7)) {
    cout << "La opcion seleccionada fue inválida, por favor seleccione una "
            "opcion válida:"
         << endl;
    cin >> selectedOption;
  }
  return selectedOption;
}

void mainMenu(peopleThree &people) {
  int selectedOption;

  do {
    selectedOption = requestMenuOption(people);

    if (selectedOption != 0) {
      switch (selectedOption) {
        case 1:
          // showAllRooms(library);
          // pauseProcess();
          break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}
