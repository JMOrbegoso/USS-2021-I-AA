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

  branch_Bolognesi = buildBranch("Av. Bolognesi 446");
  branch_JPrado = buildBranch("Av. Javier Prado 146");
  branch_FCabrera = buildBranch("Av. Francisco Cabrera 754");

  worker1 = buildWorker("12411284", "Isabela", "Apolinario", 1200);
  worker2 = buildWorker("12411284", "Joel", "Rojas", 1200);
  worker3 = buildWorker("12411284", "Felipe", "Gonzales", 1200);
  worker4 = buildWorker("12411284", "Marcelo", "Marquez", 1200);
  worker5 = buildWorker("12411284", "Josefina", "Fernandez", 1200);

  client1 = buildClient("12411284", "Nico", "Lopez", true);
  client2 = buildClient("12411284", "Lucia", "Castañeda", false);
  client3 = buildClient("12411284", "Jose", "Perez", true);
  client4 = buildClient("12411284", "Micaela", "Espinoza", false);
  client5 = buildClient("12411284", "Eusebia", "Mendez", true);

  insert(branch_Bolognesi.clients, client1);
  insert(branch_Bolognesi.clients, client2);
  insert(branch_JPrado.clients, client3);
  insert(branch_JPrado.clients, client4);
  insert(branch_FCabrera.clients, client5);

  insert(branch_Bolognesi.workers, worker1);
  insert(branch_Bolognesi.workers, worker2);
  insert(branch_JPrado.workers, worker3);
  insert(branch_JPrado.workers, worker4);
  insert(branch_FCabrera.workers, worker5);

  insert(bank.branches, branch_Bolognesi);
  insert(bank.branches, branch_JPrado);
  insert(bank.branches, branch_FCabrera);
}
