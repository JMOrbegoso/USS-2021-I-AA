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
  unsigned short age;
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
  unsigned short age;
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
  string address;
  string ruc;
  cashiersList cashiers;
};
