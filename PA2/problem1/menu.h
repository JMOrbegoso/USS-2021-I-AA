#include "structFunctions.h"

using namespace std;

void showAppTitle(companyStruct company) {
  cout << endl
       << "-----------------------------------------------------------" << endl;
  cout << "\t Sistema Virtual de la empresa " << company.businessName << endl;
  cout << "RUC: " << company.ruc;
  cout << "Ventas realizadas en total" << company.sales.length << endl;
  cout << "Almacenes: " << company.warehouses.length << endl;
  cout << "-----------------------------------------------------------" << endl;
}

int requestMenuOption(companyStruct company) {
  int selectedOption;

  clearScreen();
  showAppTitle(company);

  cout << endl << "Este sistema tiene las siguientes opciones:" << endl << endl;

  cout << "[1] Registrar un almacén" << endl;
  cout << "[2] Registrar un producto" << endl;
  cout << endl;
  cout << "[3] Abastecer un producto";
  cout << "[4] Proveer un producto" << endl;
  cout << endl;
  cout << "[5] Listar almacenes" << endl;
  cout << "[6] Listar categorias de productos en un almacén" << endl;
  cout << "[7] Listar productos un almacén" << endl;
  cout << "[8] Listar ventas realizadas" << endl;
  cout << "[9] Listar productos ventidos en una ventas especifica" << endl;
  cout << endl;
  cout << "[10] Buscar producto en todos los almacenes" << endl;
  cout << endl;
  cout << "[0] Cerrar" << endl;

  cout << endl << "Por favor ingrese una de las opciones:" << endl;
  cin >> selectedOption;
  while (!(0 <= selectedOption && selectedOption <= 10)) {
    cout << "La opcion seleccionada fue inválida, por favor seleccione una "
            "opcion válida:"
         << endl;
    cin >> selectedOption;
  }
  return selectedOption;
}

void mainMenu(companyStruct &company) {
  int selectedOption;

  do {
    selectedOption = requestMenuOption(company);

    if (selectedOption != 0) {
      switch (selectedOption) {
        case 1:
          // showAllRooms(company);
          pauseProcess();
          break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}
