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

  cout << "[4] Listar cajeros del banco" << endl;
  cout << "[5] Listar clientes haciendo cola" << endl;
  cout << "[6] Listar expedientes de los clientes haciendo cola" << endl;

  cout << "[7] Buscar cajero por apellido" << endl;
  cout << "[8] Buscar cliente por apellido" << endl;
  cout << "[9] Buscar expediente por nombre de expediente" << endl;

  cout << "[10] Listar clientes por cajero" << endl;
  cout << "[11] Listar expedientes por persona" << endl;

  cout << "[0] Cerrar" << endl;

  cout << endl << "Por favor ingrese una de las opciones:" << endl;
  cin >> selectedOption;
  while (!(0 <= selectedOption && selectedOption <= 11)) {
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

void registerNewRecord(bankStruct bank) {
  string code, name, dniToFind;
  cashierNode *cashierNodePointer;
  clientNode *clientNodePointer;
  recordStruct newRecord;
  bool clientFound = false;

  dniToFind = requestText("Ingrese el DNI del cliente que desea buscar", 2);

  cashierNodePointer = bank.cashiers.head;

  while (cashierNodePointer != NULL) {
    clientNodePointer = cashierNodePointer->cashier.clients.head;
    while (clientNodePointer != NULL) {
      if (clientNodePointer->client.dni == dniToFind) {
        clientFound = true;
      }
      clientNodePointer = clientNodePointer->next;
    }
    cashierNodePointer = cashierNodePointer->next;
  }

  if (!clientFound) {
    cout << endl
         << endl
         << "No se encontro ningun cliente con ese apellido haciendo cola."
         << endl
         << endl;
    return;
  }

  clearScreen();
  showAppTitle(bank);

  gotoxy(40, 10);
  cout << "Registrar nuevo expediente en el cliente "
       << clientNodePointer->client.lastName << " "
       << clientNodePointer->client.firstName << ":" << endl;

  code = requestText("Ingrese el codigo del nuevo expediente", 2);
  name = requestText("Ingrese el nombre/tipo del nuevo expediente", 2);

  newRecord = buildRecord(code, name);

  push(clientNodePointer->client.records, newRecord);

  cout << "El expediente fue añadido de forma exitosa en el cliente "
       << clientNodePointer->client.lastName << " "
       << clientNodePointer->client.firstName << "." << endl;
}

void showAllCashiers(bankStruct bank) {
  cashierNode *cashierNodePointer;

  clearScreen();
  showAppTitle(bank);

  gotoxy(40, 10);
  cout << "Todos los cajeros del banco " << bank.name << endl;

  cashierNodePointer = bank.cashiers.head;

  showCashiersListHeader(12);

  for (int i = 1; cashierNodePointer != NULL; i++) {
    showCashier(cashierNodePointer->cashier, i, i + 13);
    cashierNodePointer = cashierNodePointer->next;
  }

  cout << endl << endl;
}

void showAllClients(bankStruct bank) {
  cashierNode *cashierNodePointer;
  clientNode *clientNodePointer;

  clearScreen();
  showAppTitle(bank);

  gotoxy(40, 10);
  cout << "Todos los clientes formando cola en el banco " << bank.name << endl;

  cashierNodePointer = bank.cashiers.head;

  showClientsListHeader(12);

  int i = 1;
  while (cashierNodePointer != NULL) {
    clientNodePointer = cashierNodePointer->cashier.clients.head;
    while (clientNodePointer != NULL) {
      showClient(cashierNodePointer->cashier, clientNodePointer->client, i,
                 i + 13);
      clientNodePointer = clientNodePointer->next;
      i++;
    }
    cashierNodePointer = cashierNodePointer->next;
  }

  cout << endl << endl;
}

void showAllRecords(bankStruct bank) {
  cashierNode *cashierNodePointer;
  clientNode *clientNodePointer;
  recordNode *recordNodePointer;

  clearScreen();
  showAppTitle(bank);

  gotoxy(40, 10);
  cout << "Todos los expedientes de los clientes haciendo cola en el banco "
       << bank.name << endl;

  cashierNodePointer = bank.cashiers.head;

  showRecordsListHeader(12);

  int i = 1;
  while (cashierNodePointer != NULL) {
    clientNodePointer = cashierNodePointer->cashier.clients.head;
    while (clientNodePointer != NULL) {
      recordNodePointer = clientNodePointer->client.records.top;
      while (recordNodePointer != NULL) {
        showRecord(cashierNodePointer->cashier, clientNodePointer->client,
                   recordNodePointer->record, i, i + 12);
        recordNodePointer = recordNodePointer->next;
        i++;
      }
      clientNodePointer = clientNodePointer->next;
    }
    cashierNodePointer = cashierNodePointer->next;
  }

  cout << endl << endl;
}

void findCashierByLastName(bankStruct bank) {
  cashierNode *cashierNodePointer;
  string lastNameToFind;
  bool cashierFound = false;

  lastNameToFind = requestText("Ingrese el apellido del cajero a buscar", 2);

  clearScreen();
  showAppTitle(bank);

  gotoxy(40, 10);
  cout << "Cajeros del banco con un apellido similar a " << lastNameToFind
       << ":" << endl;

  cashierNodePointer = bank.cashiers.head;

  showCashiersListHeader(12);

  int i = 1;
  while (cashierNodePointer != NULL) {
    if (containsText(cashierNodePointer->cashier.lastName, lastNameToFind)) {
      cashierFound = true;
      showCashier(cashierNodePointer->cashier, i, i + 13);
      i++;
    }
    cashierNodePointer = cashierNodePointer->next;
  }

  if (!cashierFound)
    cout << endl << endl << "No se encontro ningun cajero con ese apellido.";

  cout << endl << endl;
}

void findClientByLastName(bankStruct bank) {
  cashierNode *cashierNodePointer;
  clientNode *clientNodePointer;
  string lastNameToFind;
  bool clientFound = false;

  lastNameToFind =
      requestText("Ingrese el apellido del cliente que desea buscar", 2);

  clearScreen();
  showAppTitle(bank);

  gotoxy(40, 10);
  cout << "Clientes haciendo cola con un apellido similar a " << lastNameToFind
       << ":" << endl;

  cashierNodePointer = bank.cashiers.head;

  showClientsListHeader(12);

  int i = 1;
  while (cashierNodePointer != NULL) {
    clientNodePointer = cashierNodePointer->cashier.clients.head;
    while (clientNodePointer != NULL) {
      if (containsText(clientNodePointer->client.lastName, lastNameToFind)) {
        clientFound = true;
        showClient(cashierNodePointer->cashier, clientNodePointer->client, i,
                   i + 13);
        i++;
      }
      clientNodePointer = clientNodePointer->next;
    }
    cashierNodePointer = cashierNodePointer->next;
  }

  if (!clientFound)
    cout << endl
         << endl
         << "No se encontro ningun cliente con ese apellido haciendo cola.";

  cout << endl << endl;
}

void findRecordByName(bankStruct bank) {
  cashierNode *cashierNodePointer;
  clientNode *clientNodePointer;
  recordNode *recordNodePointer;
  string nameToFind;
  bool recordFound = false;

  nameToFind =
      requestText("Ingrese el nombre/tipo de expediente que desea buscar", 2);

  clearScreen();
  showAppTitle(bank);

  gotoxy(40, 10);
  cout << "Expedientes con un nombre/tipo similar a " << nameToFind << ":"
       << endl;

  cashierNodePointer = bank.cashiers.head;

  showRecordsListHeader(12);

  int i = 1;
  while (cashierNodePointer != NULL) {
    clientNodePointer = cashierNodePointer->cashier.clients.head;
    while (clientNodePointer != NULL) {
      recordNodePointer = clientNodePointer->client.records.top;
      while (recordNodePointer != NULL) {
        if (containsText(recordNodePointer->record.name, nameToFind)) {
          recordFound = true;
          showRecord(cashierNodePointer->cashier, clientNodePointer->client,
                     recordNodePointer->record, i, i + 13);
          i++;
        }
        recordNodePointer = recordNodePointer->next;
      }
      clientNodePointer = clientNodePointer->next;
    }
    cashierNodePointer = cashierNodePointer->next;
  }

  if (!recordFound)
    cout << endl
         << endl
         << "No se encontro ningun expediente con ese nombre/tipo.";

  cout << endl << endl;
}

void showClientsByCashier(bankStruct bank) {
  cashierNode *cashierNodePointer;
  clientNode *clientNodePointer;

  cashierNodePointer = requestCashierWithSelector(
      bank.cashiers, "Ingrese el cajero de la cola de clientes que desea ver:");

  clearScreen();
  showAppTitle(bank);

  gotoxy(40, 10);
  cout << "Clientes haciendo cola con el cajero "
       << cashierNodePointer->cashier.lastName << " "
       << cashierNodePointer->cashier.firstName << ":" << endl;

  clientNodePointer = cashierNodePointer->cashier.clients.head;

  showClientsListHeader(12);

  int i = 1;
  while (clientNodePointer != NULL) {
    showClient(cashierNodePointer->cashier, clientNodePointer->client, i,
               i + 13);
    clientNodePointer = clientNodePointer->next;
  }

  cout << endl << endl;
}

void showRecordsByClient(bankStruct bank) {
  cashierNode *cashierNodePointer;
  clientNode *clientNodePointer;
  recordNode *recordNodePointer;

  cashierNodePointer = requestCashierWithSelector(
      bank.cashiers, "Ingrese el cajero de la persona que desea revisar:");
  clientNodePointer = requestClientWithSelector(
      cashierNodePointer->cashier.clients,
      "Ingrese el cliente de los expedientes que desea listar:");

  clearScreen();
  showAppTitle(bank);

  gotoxy(40, 10);
  cout << "Expedientes de " << clientNodePointer->client.lastName << " "
       << clientNodePointer->client.firstName << ":" << endl;

  recordNodePointer = clientNodePointer->client.records.top;

  showRecordsListHeader(12);

  int i = 1;
  while (recordNodePointer != NULL) {
    showRecord(cashierNodePointer->cashier, clientNodePointer->client,
               recordNodePointer->record, i, i + 13);
    recordNodePointer = recordNodePointer->next;
    i++;
  }

  cout << endl << endl;
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
        registerNewRecord(bank);
        addDelay(2);
        break;

      case 4:
        showAllCashiers(bank);
        pauseProcess();
        break;

      case 5:
        showAllClients(bank);
        pauseProcess();
        break;

      case 6:
        showAllRecords(bank);
        pauseProcess();
        break;

      case 7:
        findCashierByLastName(bank);
        pauseProcess();
        break;

      case 8:
        findClientByLastName(bank);
        pauseProcess();
        break;

      case 9:
        findRecordByName(bank);
        pauseProcess();
        break;

      case 10:
        showClientsByCashier(bank);
        pauseProcess();
        break;

      case 11:
        showRecordsByClient(bank);
        pauseProcess();
        break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}
