#include "menuOptions.h"

using namespace std;

int requestMenuOption() {
  int selectedOption;

  clearScreen();
  showAppTitle();

  cout << endl
       << "Esta aplicación tiene las siguientes opciones:" << endl
       << endl;

  cout << "[1] Registrar ciudad" << endl;
  cout << "[2] Registrar arista" << endl;
  cout << "[3] Registrar vivienda" << endl;
  cout << "[4] Registrar persona" << endl;
  cout << endl;
  cout << "[5] Mostrar todas las ciudades" << endl;
  cout << "[6] Mostrar todas las ciudades con sus destinos" << endl;
  cout << "[7] Mostrar todas las viviendas" << endl;
  cout << "[8] Mostrar todas las personas" << endl;
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

void mainMenu(citiesGraph &cities) {
  int selectedOption;

  do {
    selectedOption = requestMenuOption();

    if (selectedOption != 0) {
      switch (selectedOption) {
        case 1:
          registerCity(cities);
          addDelay(1.5);
          break;

        case 2:
          addCitiesLink(cities);
          addDelay(1.5);
          break;

        case 3:
          registerHouse(cities);
          addDelay(1.5);
          break;

        case 4:
          registerPerson(cities);
          addDelay(1.5);
          break;

        case 5:
          showCities(cities);
          pauseProcess();
          break;

        case 6:
          showCitiesWithDestinations(cities);
          pauseProcess();
          break;

        case 7:
          showHouses(cities);
          pauseProcess();
          break;

        case 8:
          showPeople(cities);
          pauseProcess();
          break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}
