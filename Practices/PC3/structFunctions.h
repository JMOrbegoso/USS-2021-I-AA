#include "helpers.h"
#include "structs.h"

using namespace std;

// Factories

clientStruct buildClient(string dni, string firstName, string lastName,
                         bool hasSavingsAccount) {
  clientStruct client;

  client.dni = dni;
  client.firstName = firstName;
  client.lastName = lastName;
  client.hasSavingsAccount = hasSavingsAccount;

  return client;
}

workerStruct buildWorker(string dni, string firstName, string lastName,
                         float salary) {
  workerStruct worker;

  worker.dni = dni;
  worker.firstName = firstName;
  worker.lastName = lastName;
  worker.salary = salary;

  return worker;
}

branchStruct buildBranch(string address) {
  branchStruct branch;

  branch.address = address;

  branch.clients.head = NULL;
  branch.clients.length = 0;

  branch.workers.head = NULL;
  branch.workers.length = 0;

  return branch;
}

void addBranchRelation(branchNode *aux1, branchNode *aux2,
                       branchEdge *newBranchEdge) {
  branchEdge *temp;

  if (aux1->adjacent == NULL) {
    aux1->adjacent = newBranchEdge;
    newBranchEdge->destiny = aux2;
  } else {
    temp = aux1->adjacent;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    newBranchEdge->destiny = aux2;
    temp->next = newBranchEdge;
  }
}

// Insert to collection

void insert(branchesGraph &branches, branchStruct newBranch) {
  branchNode *auxBranchNode;

  branchNode *newBranchNode = new struct branchNode;
  newBranchNode->next = NULL;
  newBranchNode->adjacent = NULL;
  newBranchNode->branch = newBranch;

  if (branches.node == NULL) {
    branches.node = newBranchNode;
  } else {
    auxBranchNode = branches.node;
    while (auxBranchNode->next != NULL) {
      auxBranchNode = auxBranchNode->next;
    }
    auxBranchNode->next = newBranchNode;
  }

  branches.length++;
}

void insert(workersList &workers, workerStruct newWorker) {
  workerNode *workerNodePointer = new struct workerNode;

  workerNode *lastNode = workers.head;

  workerNodePointer->worker = newWorker;
  workerNodePointer->next = NULL;

  if (workers.head == NULL) {
    workers.head = workerNodePointer;
  } else {
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }

    lastNode->next = workerNodePointer;
  }

  workers.length++;
}

void enqueue(clientsQueue &clients, clientStruct newClient) {
  clientNode *clientNodePointer = new struct clientNode;

  clientNodePointer->client = newClient;
  clientNodePointer->next = NULL;

  if (clients.head == NULL) {
    clients.head = clientNodePointer;
  } else {
    clients.tail->next = clientNodePointer;
  }

  clients.tail = clientNodePointer;
  clients.length++;
}

clientStruct dequeue(clientsQueue &clients) {
  clientNode *clientNodePointer;
  clientStruct deletedClient;

  clientNodePointer = clients.head;
  deletedClient = clientNodePointer->client;

  clients.head = clients.head->next;
  clients.length--;

  delete clientNodePointer;

  return deletedClient;
}

// Init

void collectionsInitialization(bankStruct &bank) {
  bank.branches.node = NULL;
  bank.branches.edge = NULL;
  bank.branches.length = 0;
}

void dataInitialization(bankStruct &bank) {
  workerStruct worker1, worker2, worker3, worker4, worker5;
  clientStruct client1, client2, client3, client4, client5;
  branchStruct branch_Bolognesi, branch_JPrado, branch_FCabrera;

  bank.businessName = "Brav S.A.C.";
  bank.ruc = "12345678910";

  branch_Bolognesi = buildBranch("Av. Bolognesi 446");
  branch_JPrado = buildBranch("Av. Javier Prado 146");
  branch_FCabrera = buildBranch("Av. Francisco Cabrera 754");

  worker1 = buildWorker("97561243", "Isabela", "Apolinario", 1200);
  worker2 = buildWorker("82419984", "Joel", "Rojas", 1200);
  worker3 = buildWorker("10606284", "Felipe", "Gonzales", 1200);
  worker4 = buildWorker("97612743", "Marcelo", "Marquez", 1200);
  worker5 = buildWorker("30411284", "Josefina", "Fernandez", 1200);

  client1 = buildClient("10110284", "Nico", "Lopez", true);
  client2 = buildClient("32411284", "Lucia", "Castañeda", false);
  client3 = buildClient("11061283", "Jose", "Perez", true);
  client4 = buildClient("12411284", "Micaela", "Espinoza", false);
  client5 = buildClient("85561243", "Eusebia", "Mendez", true);

  enqueue(branch_Bolognesi.clients, client1);
  enqueue(branch_Bolognesi.clients, client2);
  enqueue(branch_JPrado.clients, client3);
  enqueue(branch_JPrado.clients, client4);
  enqueue(branch_FCabrera.clients, client5);

  insert(branch_Bolognesi.workers, worker1);
  insert(branch_Bolognesi.workers, worker2);
  insert(branch_JPrado.workers, worker3);
  insert(branch_JPrado.workers, worker4);
  insert(branch_FCabrera.workers, worker5);

  insert(bank.branches, branch_Bolognesi);
  insert(bank.branches, branch_JPrado);
  insert(bank.branches, branch_FCabrera);
}

// Selectors/Pickers

branchNode *iterateBranchesGraph(branchesGraph branches, int index) {
  branchNode *branchNodePointer;

  if (0 >= index) {
    return NULL;
  }

  if (index > branches.length) {
    return NULL;
  }

  branchNodePointer = branches.node;

  for (int i = 1; branchNodePointer != NULL; i++) {
    if (i == index) {
      return branchNodePointer;
    }
    branchNodePointer = branchNodePointer->next;
  }

  return NULL;
}

branchNode *requestBranch(branchesGraph branches, string message) {
  int selectedOption;
  branchNode *branchNodePointer;

  cout << endl
       << message << "." << endl
       << "Escoja entre las " << branches.length
       << " sucursales siguientes:" << endl
       << endl;

  branchNodePointer = branches.node;

  for (int i = 1; branchNodePointer != NULL; i++) {
    cout << "[" << i << "] - " << branchNodePointer->branch.address << endl;
    branchNodePointer = branchNodePointer->next;
  }

  cout << endl << "Introduzca la opción deseada:" << endl;
  cin >> selectedOption;

  while (!(1 <= selectedOption && selectedOption <= branches.length)) {
    cout << "Por favor, introduzca un valor entre 1 y " << branches.length
         << "." << endl;
    fflush(stdin);
    cin >> selectedOption;
  }

  return iterateBranchesGraph(branches, selectedOption);
}

// Printers

void showBranchesListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Dirección";
  gotoxy(40, y);
  cout << "Destinos";
}

void showBranch(branchNode *node, int i, int y) {
  branchEdge *edge;
  int x = 0;

  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << node->branch.address;

  edge = node->adjacent;

  if (edge == NULL) {
    gotoxy(40, y);
    cout << "No hay sucursales relacionadas a esta";
    return;
  }

  while (edge != NULL) {
    gotoxy(40 + x, y);
    cout << edge->destiny->branch.address;

    if (edge->next != NULL) cout << ", ";

    x += (edge->destiny->branch.address.length() + 2);
    edge = edge->next;
  }
}

void showWorkersListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Nombres";
  gotoxy(25, y);
  cout << "Apellidos";
  gotoxy(50, y);
  cout << "DNI";
  gotoxy(60, y);
  cout << "Salario";
}

void showWorker(workerStruct worker, int i, int y) {
  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << worker.firstName;
  gotoxy(25, y);
  cout << worker.lastName;
  gotoxy(50, y);
  cout << worker.dni;
  gotoxy(60, y);
  cout << worker.salary;
}

void showClientsListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Nombres";
  gotoxy(25, y);
  cout << "Apellidos";
  gotoxy(50, y);
  cout << "DNI";
  gotoxy(60, y);
  cout << "Tiene Cuenta de Ahorros";
}

void showClient(clientStruct client, int i, int y) {
  string hasSavingsAccountText;

  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << client.firstName;
  gotoxy(25, y);
  cout << client.lastName;
  gotoxy(50, y);
  cout << client.dni;
  gotoxy(60, y);
  hasSavingsAccountText = client.hasSavingsAccount ? "Si" : "No";
  cout << hasSavingsAccountText;
}