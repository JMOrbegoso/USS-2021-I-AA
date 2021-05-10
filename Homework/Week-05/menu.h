#include "structFunctions.h"

using namespace std;

void showAppTitle(bankStruct bank) {
  cout << endl
       << "-----------------------------------------------------------" << endl;
  cout << "\t\t Sistema Virtual del Banco " << bank.name << endl;
  cout << "-----------------------------------------------------------" << endl;
  cout << "Dirección: " << bank.address << endl;
  cout << "RUC: " << bank.ruc << endl;
  cout << "-----------------------------------------------------------" << endl;
}

int requestMenuOption(bankStruct bank) {
  int selectedOption;

  clearScreen();
  showAppTitle(bank);

  cout << endl
       << "Esta aplicación tiene las siguientes opciones:" << endl
       << endl;

  cout << "[1] Registrar cajero" << endl;
  cout << "[2] Registrar cliente" << endl;
  cout << "[3] Registrar expediente" << endl;

  cout << "[4] Listar cajeros" << endl;
  cout << "[5] Listar clientes" << endl;
  cout << "[6] Listar expedientes" << endl;

  cout << "[7] Buscar cajero por apellido" << endl;
  cout << "[8] Buscar cliente por apellido" << endl;
  cout << "[9] Buscar expediente por nombre" << endl;

  cout << "[10] Listar clientes por cajero" << endl;
  cout << "[11] Listar expedientes por persona" << endl;

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

void registerNewCashier(bankStruct &bank) {
  string firstName, lastName, dni;
  char genre;
  cashierStruct newCashier;

  clearScreen();
  showAppTitle(bank);

  gotoxy(40, 10);
  cout << "Registrar nuevo cajero:" << endl;

  firstName = requestText("Ingrese los nombres del nuevo cajero", 2);
  lastName = requestText("Ingrese los apellidos del nuevo cajero", 2);
  genre = requestGenre("Ingrese el genero del nuevo cajero");
  dni = requestText("Ingrese el DNI del nuevo cajero", 8, 8);

  newCashier = buildCashier(dni, firstName, lastName, genre);

  addToCollection(bank.cashiers, newCashier);

  cout << "El cajero fue añadida de forma exitosa" << endl;
}

void registerNewClient(bankStruct &bank) {
  string firstName, lastName, dni;
  char genre;
  cashierNode *cashierNodePointer;
  clientStruct newClient;

  clearScreen();
  showAppTitle(bank);

  gotoxy(40, 10);
  cout << "Registrar nuevo cliente:" << endl;

  firstName = requestText("Ingrese los nombres del nuevo cliente", 2);
  lastName = requestText("Ingrese los apellidos del nuevo cliente", 2);
  genre = requestGenre("Ingrese el genero del nuevo cliente");
  dni = requestText("Ingrese el DNI del nuevo cliente", 8, 8);

  newClient = buildClient(dni, firstName, lastName, genre);

  cashierNodePointer = requestCashierWithSelector(
      bank.cashiers, "Ingrese el cajero al que este cliente se dirije:");

  enqueue(cashierNodePointer->cashier.clients, newClient);

  cout << "El cliente fue añadido de forma exitosa" << endl;
}

void mainMenu(bankStruct &bank) {
  int selectedOption;

  do {
    selectedOption = requestMenuOption(bank);

    if (selectedOption != 0) {
      switch (selectedOption) {
      case 1:
        registerNewCashier(bank);
        addDelay(2);
        break;

      case 2:
        registerNewClient(bank);
        addDelay(2);
        break;

      case 3:
        // registerNewRecord(bank);
        addDelay(2);
        break;

      case 4:
        // showAllCashiers(bank);
        pauseProcess();
        break;

      case 5:
        // showAllClients(bank);
        pauseProcess();
        break;

      case 6:
        // showAllRecords(bank);
        pauseProcess();
        break;

      case 7:
        // findCashierByLastName(bank);
        pauseProcess();
        break;

      case 8:
        // findClientByLastName(bank);
        pauseProcess();
        break;

      case 9:
        // findRecordByName(bank);
        pauseProcess();
        break;

      case 10:
        // showClientsByCashier(bank);
        pauseProcess();
        break;

      case 11:
        // showRecordsByClient(bank);
        pauseProcess();
        break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}
