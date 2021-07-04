#include "structFunctions.h"

void showAppTitle(bankStruct bank) {
  cout << endl;
  cout << "-----------------------------------------------------------";
  cout << endl << endl;
  cout << "\t\t Sistema virtual del banco ";
  cout << bank.businessName;
  cout << endl << endl;
  cout << "\t RUC: " << bank.ruc;
  cout << "\t\t # Sucusales: " << bank.branches.length;
  cout << endl << endl;
  cout << "-----------------------------------------------------------";
  cout << endl;
}

void registerNewBankBranch(bankStruct &bank) {
  branchStruct newBranch;
  string address;

  clearScreen();
  showAppTitle(bank);

  gotoxy(20, 8);
  cout << "Registrar nueva sucursal del banco:" << endl;

  address = requestText("Ingrese la dirección de la nueva sucursal", 1);

  newBranch = buildBranch(address);

  insert(bank.branches, newBranch);

  cout << "La nueva sucursal fue registrada de forma exitosa.";
  cout << endl << endl;
}

void registerBankBranchesRelation(bankStruct &bank) {
  branchNode *originBranchNodePointer, *destinationBranchNodePointer;
  branchEdge *newBranchEdge = new struct branchEdge;

  clearScreen();
  showAppTitle(bank);

  gotoxy(20, 8);
  cout << "Registrar nuevo enlace entre dos sucursales:" << endl;

  if (bank.branches.node == NULL || bank.branches.node->next == NULL) {
    cout << "Primero debe de añadir al menos 2 sucursales al grafo.";
    cout << endl << endl;
    return;
  }

  newBranchEdge->next = NULL;

  originBranchNodePointer =
      requestBranch(bank.branches, "Escoja la sucursal de origen");

  if (originBranchNodePointer == NULL) {
    cout << "Introdujo una sucursal no valida";
    cout << endl << endl;
    return;
  }

  destinationBranchNodePointer =
      requestBranch(bank.branches, "Escoja la sucursal de destino");

  if (destinationBranchNodePointer == NULL) {
    cout << "Introdujo una sucursal no valida";
    cout << endl << endl;
    return;
  }

  addBranchRelation(originBranchNodePointer, destinationBranchNodePointer,
                    newBranchEdge);
}

void registerNewClient(bankStruct &bank) {
  clientStruct newClient;
  string dni, firstName, lastName;
  bool hasSavingsAccount;
  branchNode *branchNodePointer;

  clearScreen();
  showAppTitle(bank);

  gotoxy(20, 8);
  cout << "Registrar nuevo cliente:" << endl;

  dni = requestText("Ingrese el DNI del nuevo cliente", 8, 8);
  firstName = requestText("Ingrese el nombre del nuevo cliente", 3);
  lastName = requestText("Ingrese el apellido del nuevo cliente", 3);
  hasSavingsAccount =
      requestBool("¿El cliente tiene una cuenta de ahorros en este banco?");

  newClient = buildClient(dni, firstName, lastName, hasSavingsAccount);

  branchNodePointer = requestBranch(
      bank.branches, "Escoja la sucursal en la que se encuentra el cliente");

  if (branchNodePointer == NULL) {
    cout << "No seleccionó una sucursal valida para el cliente.";
    cout << endl << endl;
    return;
  }

  enqueue(branchNodePointer->branch.clients, newClient);

  cout << "El cliente fue registrado de forma exitosa.";
  cout << endl << endl;
}

void registerNewWorker(bankStruct &bank) {
  workerStruct newWorker;
  string dni, firstName, lastName;
  float salary;
  branchNode *branchNodePointer;

  clearScreen();
  showAppTitle(bank);

  gotoxy(20, 8);
  cout << "Registrar nuevo cliente:" << endl;

  dni = requestText("Ingrese el DNI del nuevo empleado", 8, 8);
  firstName = requestText("Ingrese el nombre del nuevo empleado", 3);
  lastName = requestText("Ingrese el apellido del nuevo empleado", 3);
  salary = requestMoney("Ingrese el salario del nuevo empleado", 1, 10000);

  newWorker = buildWorker(dni, firstName, lastName, salary);

  branchNodePointer = requestBranch(
      bank.branches, "Escoja la sucursal en la que se encuentra el empleado");

  if (branchNodePointer == NULL) {
    cout << "No seleccionó una sucursal valida para el empleado.";
    cout << endl << endl;
    return;
  }

  insert(branchNodePointer->branch.workers, newWorker);

  cout << "El empleado fue registrado de forma exitosa.";
  cout << endl << endl;
}

void findClient(bankStruct bank) {
  branchNode *branchNodePointer;
  clientNode *clientNodePointer;
  string lastNameToFind;

  lastNameToFind =
      requestText("Ingrese el apellido del cliente que quiere buscar", 1);

  clearScreen();
  showAppTitle(bank);

  gotoxy(20, 10);
  cout << "Clientes registrados con un apellido similar a " << lastNameToFind
       << ":" << endl;

  showClientsListHeader(12);

  branchNodePointer = bank.branches.node;

  int i = 1;
  while (branchNodePointer != NULL) {
    clientNodePointer = branchNodePointer->branch.clients.head;

    while (clientNodePointer != NULL) {
      if (containsText(clientNodePointer->client.lastName, lastNameToFind)) {
        showClient(clientNodePointer->client, i, i + 13);
        i++;
      }

      clientNodePointer = clientNodePointer->next;
    }

    branchNodePointer = branchNodePointer->next;
  }

  cout << endl << endl;
}

void showBankBranches(bankStruct bank) {
  branchNode *auxBranchNode;

  clearScreen();
  showAppTitle(bank);

  gotoxy(20, 8);
  cout << "Lista de todas las sucursales:" << endl;

  showBranchesListHeader(10);

  auxBranchNode = bank.branches.node;

  for (int i = 1; auxBranchNode != NULL; i++) {
    showBranch(auxBranchNode, i, 12 + i);
    auxBranchNode = auxBranchNode->next;
  }

  cout << endl << endl;
}

void showClientsByBankBranch(bankStruct bank) {
  branchNode *branchNodePointer;
  clientNode *clientNodePointer;

  branchNodePointer =
      requestBranch(bank.branches,
                    "Ingrese la sucursal de la que desea revisar sus clientes");

  clearScreen();
  showAppTitle(bank);

  gotoxy(20, 10);
  cout << "Clientes en la sucursal de " << branchNodePointer->branch.address
       << ":" << endl;

  clientNodePointer = branchNodePointer->branch.clients.head;

  showClientsListHeader(12);

  for (int i = 1; clientNodePointer != NULL; i++) {
    showClient(clientNodePointer->client, i, i + 13);
    clientNodePointer = clientNodePointer->next;
  }

  cout << endl << endl;
}

void showWorkersByBankBranch(bankStruct bank) {
  branchNode *branchNodePointer;
  workerNode *workerNodePointer;

  branchNodePointer = requestBranch(
      bank.branches,
      "Ingrese la sucursal de la que desea revisar sus trabajadores");

  clearScreen();
  showAppTitle(bank);

  gotoxy(20, 10);
  cout << "Trabajadores en la sucursal de " << branchNodePointer->branch.address
       << ":" << endl;

  workerNodePointer = branchNodePointer->branch.workers.head;

  showWorkersListHeader(12);

  for (int i = 1; workerNodePointer != NULL; i++) {
    showWorker(workerNodePointer->worker, i, i + 13);
    workerNodePointer = workerNodePointer->next;
  }

  cout << endl << endl;
}
