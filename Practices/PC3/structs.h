#include <iostream>

using namespace std;

struct branchEdge;

// Estructura base de Persona
struct personStruct {
  string dni;
  string firstName;
  string lastName;
};

// Cliente
struct clientStruct : personStruct {
  bool hasSavingsAccount;
};

struct clientNode {
  clientStruct client;
  clientNode *next;
};

struct clientsQueue {
  clientNode *head;
  clientNode *tail;
  int length;
};

// Trabajador
struct workerStruct : personStruct {
  float salary;
};

struct workerNode {
  workerStruct worker;
  workerNode *next;
};

struct workersList {
  workerNode *head;
  int length;
};

// Sucursales
struct branchStruct {
  string address;
  workersList workers;
  clientsQueue clients;
};

struct branchNode {
  branchStruct branch;
  branchNode *next;
  branchEdge *adjacent;
};

struct branchEdge {
  branchNode *destiny;
  branchEdge *next;
};

struct branchesGraph {
  branchNode *node;
  branchEdge *edge;
  int length;
};

// Banco
struct bankStruct {
  string businessName;
  string ruc;
  branchesGraph branches;
};