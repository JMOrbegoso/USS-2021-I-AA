#include <iostream>

using namespace std;

// Record

struct recordStruct {
  string code;
  string name;
};

struct recordNode {
  recordStruct record;
  recordNode *next;
};

struct recordsStack {
  recordNode *top;
  int length;
};

// Client

struct clientStruct {
  string firstName;
  string lastName;
  char genre;
  string dni;
  recordsStack records;
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

// Cashier

struct cashierStruct {
  string firstName;
  string lastName;
  char genre;
  string dni;
  clientsQueue clients;
};

struct cashierNode {
  cashierStruct cashier;
  cashierNode *next;
};

struct cashiersList {
  cashierNode *head;
  int length;
};

// Bank

struct bankStruct {
  string name;
  string motto;
  string address;
  string ruc;
  cashiersList cashiers;
};
