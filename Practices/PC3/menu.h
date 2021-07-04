#include "menuOptions.h"

using namespace std;

int requestMenuOption(bankStruct bank) {
  int selectedOption;

  clearScreen();
  showAppTitle(bank);

  cout << endl
       << "Esta aplicación tiene las siguientes opciones:" << endl
       << endl;

  cout << "[1] Registrar sucursal" << endl;
  cout << "[2] Registrar relación entre sucursales" << endl;
  cout << "[3] Registrar cliente" << endl;
  cout << "[4] Registrar trabajador" << endl;
  cout << endl;
  cout << "[5] Buscar cliente" << endl;
  cout << endl;
  cout << "[6] Ver sucursales" << endl;
  cout << "[7] Ver cola de clientes en sucursal" << endl;
  cout << "[8] Ver lista de trabajadores en sucursal" << endl;

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

void mainMenu(bankStruct &bank) {
  int selectedOption;

  do {
    selectedOption = requestMenuOption(bank);

    if (selectedOption != 0) {
      switch (selectedOption) {
        case 1:
          registerNewBankBranch(bank);
          addDelay(1.5);
          break;

        case 2:
          registerBankBranchesRelation(bank);
          addDelay(1.5);
          break;

        case 3:
          registerNewClient(bank);
          addDelay(1.5);
          break;

        case 4:
          registerNewWorker(bank);
          addDelay(1.5);
          break;

        case 5:
          findClient(bank);
          pauseProcess();
          break;

        case 6:
          showBankBranches(bank);
          pauseProcess();
          break;

        case 7:
          showClientsByBankBranch(bank);
          pauseProcess();
          break;

        case 8:
          showWorkersByBankBranch(bank);
          pauseProcess();
          break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}
