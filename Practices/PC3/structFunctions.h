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
