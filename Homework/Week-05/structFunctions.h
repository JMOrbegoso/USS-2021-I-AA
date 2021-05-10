#include "helpers.h"
#include "structs.h"
#include <iostream>

using namespace std;

void collectionsInitialization(bankStruct &bank) {
  bank.cashiers.head = NULL;
  bank.cashiers.length = 0;
}

cashierStruct buildCashier(string firstName, string lastName, char genre,
                           unsigned short age) {
  cashierStruct cashier;

  cashier.firstName = firstName;
  cashier.lastName = lastName;
  cashier.genre = genre;
  cashier.age = age;

  cashier.clients.head = NULL;
  cashier.clients.tail = NULL;
  cashier.clients.length = 0;

  return cashier;
}

clientStruct buildClient(string firstName, string lastName, char genre,
                         unsigned short age) {
  clientStruct client;

  client.firstName = firstName;
  client.lastName = lastName;
  client.genre = genre;
  client.age = age;

  client.records.top = NULL;
  client.records.length = 0;

  return client;
}

recordStruct buildRecord(string code, string name) {
  recordStruct record;

  record.code = code;
  record.name = name;

  return record;
}

void addToCollection(cashiersList &cashiers, cashierStruct newCashier) {
  cashierNode *newNode = new cashierNode();

  cashierNode *lastNode = cashiers.head;

  newNode->cashier = newCashier;
  newNode->next = NULL;

  if (cashiers.head == NULL) {
    cashiers.head = newNode;
  } else {
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }

    lastNode->next = newNode;
  }

  cashiers.length++;
}

void enqueue(clientsQueue &clients, clientStruct newClient) {
  clientNode *clientNodePointer = new clientNode;

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

bool isQueueEmpty(clientsQueue clients) { return clients.head == NULL; }

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

void push(recordsStack &records, recordStruct newRecord) {
  recordNode *newWriterNode = new recordNode();

  newWriterNode->record = newRecord;
  newWriterNode->next = records.top;

  records.top = newWriterNode;
  records.length++;
}

void dataInitialization(bankStruct &bank) {
  cashierStruct cashier_1, cashier_2, cashier_3;
  clientStruct client_1, client_2, client_3, client_4, client_5, client_6;
  recordStruct record_1, record_2, record_3, record_4, record_5, record_6,
      record_7, record_8, record_9, record_10, record_11, record_12;

  bank.name = "El Banco";
  bank.address = "Av. Los Algoritmos #444";
  bank.ruc = "12345678910";

  cashier_1 = buildCashier("Julio", "Gomez", 'm', 47);
  cashier_2 = buildCashier("Maria", "Izquierdo", 'f', 15);
  cashier_3 = buildCashier("Luis", "Lopez", 'm', 27);

  client_1 = buildClient("Tulio", "Rojas", 'm', 11);
  client_2 = buildClient("Rosa", "Jimenez", 'f', 72);
  client_3 = buildClient("Teodoro", "Rodriguez", 'm', 75);
  client_4 = buildClient("Mario", "Flores", 'm', 32);
  client_5 = buildClient("Fabricia", "Marquez", 'f', 19);
  client_6 = buildClient("Paolo", "Fermi", 'm', 40);

  record_1 = buildRecord("r-01", "Prestamo");
  record_2 = buildRecord("r-02", "Pago de deuda");
  record_3 = buildRecord("r-03", "Prestamo");
  record_4 = buildRecord("r-04", "Pago de deuda");
  record_5 = buildRecord("r-05", "Prestamo");
  record_6 = buildRecord("r-06", "Pago de deuda");
  record_7 = buildRecord("r-07", "Prestamo");
  record_8 = buildRecord("r-08", "Pago de deuda");
  record_9 = buildRecord("r-09", "Prestamo");
  record_10 = buildRecord("r-10", "Pago de deuda");
  record_11 = buildRecord("r-11", "Prestamo");
  record_12 = buildRecord("r-12", "Pago de deuda");

  push(client_1.records, record_1);
  push(client_1.records, record_2);
  push(client_2.records, record_3);
  push(client_2.records, record_4);
  push(client_3.records, record_5);
  push(client_3.records, record_6);
  push(client_4.records, record_7);
  push(client_4.records, record_8);
  push(client_5.records, record_9);
  push(client_5.records, record_10);
  push(client_6.records, record_11);
  push(client_6.records, record_12);

  enqueue(cashier_1.clients, client_1);
  enqueue(cashier_1.clients, client_2);
  enqueue(cashier_2.clients, client_3);
  enqueue(cashier_2.clients, client_4);
  enqueue(cashier_3.clients, client_5);
  enqueue(cashier_3.clients, client_5);

  addToCollection(bank.cashiers, cashier_1);
  addToCollection(bank.cashiers, cashier_2);
  addToCollection(bank.cashiers, cashier_3);
}

cashierNode *iterateCashiersList(cashiersList cashiers, int index) {
  cashierNode *cashierNodePointer;

  if (0 >= index) {
    return NULL;
  }

  if (index > cashiers.length) {
    return NULL;
  }

  cashierNodePointer = cashiers.head;

  for (int i = 1; cashierNodePointer != NULL; i++) {
    if (i == index) {
      return cashierNodePointer;
    }
    cashierNodePointer = cashierNodePointer->next;
  }

  return NULL;
}

clientNode *iterateClientsQueue(clientsQueue clients, int index) {
  clientNode *clientNodePointer;

  if (0 >= index) {
    return NULL;
  }

  if (index > clients.length) {
    return NULL;
  }

  clientNodePointer = clients.head;

  for (int i = 1; clientNodePointer != NULL; i++) {
    if (i == index) {
      return clientNodePointer;
    }
    clientNodePointer = clientNodePointer->next;
  }

  return NULL;
}

cashierNode *requestCashierWithSelector(cashiersList &cashiers,
                                        string message) {
  int selectedOption;
  cashierNode *cashierNodePointer;

  cout << endl
       << message << ". Escoja entre los " << cashiers.length
       << " cajeros siguientes:" << endl
       << endl;

  cashierNodePointer = cashiers.head;

  for (int i = 1; cashierNodePointer != NULL; i++) {
    cout << "[" << i << "] - " << cashierNodePointer->cashier.firstName << " "
         << cashierNodePointer->cashier.lastName << " - "
         << cashierNodePointer->cashier.clients.length
         << " clientes en fila para este cajero" << endl;
    cashierNodePointer = cashierNodePointer->next;
  }

  cout << endl << "Introduzca la opción deseada:" << endl;

  while (!(1 <= selectedOption && selectedOption <= cashiers.length)) {
    cout << "Por favor, introduzca un valor entre 1 y " << cashiers.length
         << "." << endl;
    fflush(stdin);
    cin >> selectedOption;
  }

  return iterateCashiersList(cashiers, selectedOption);
}

clientNode *requestClientWithSelector(clientsQueue &clients, string message) {
  int selectedOption;
  clientNode *clientNodePointer;

  clientNodePointer = clients.head;

  cout << endl
       << message << ". Escoja entre los " << clients.length
       << " clientes siguientes:" << endl
       << endl;

  for (int i = 1; clientNodePointer != NULL; i++) {
    cout << "[" << i << "] - " << clientNodePointer->client.firstName << " "
         << clientNodePointer->client.lastName << " - Con "
         << clientNodePointer->client.records.length << " expedientes." << endl;
    clientNodePointer = clientNodePointer->next;
  }

  cout << endl << "Introduzca la opción deseada:" << endl;

  while (!(1 <= selectedOption && selectedOption <= clients.length)) {
    cout << "Por favor, introduzca un valor entre 1 y " << clients.length << "."
         << endl;
    fflush(stdin);
    cin >> selectedOption;
  }

  return iterateClientsQueue(clients, selectedOption);
}

void showCashiersListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Nombres";
  gotoxy(20, y);
  cout << "Apellidos";
  gotoxy(40, y);
  cout << "Genero";
  gotoxy(55, y);
  cout << "Edad";
  gotoxy(65, y);
  cout << "# de clientes en cola";
}

void showCashier(cashierStruct cashier, int i, int y) {
  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << cashier.firstName;
  gotoxy(20, y);
  cout << cashier.lastName;
  gotoxy(40, y);
  cout << getGenre(cashier.genre);
  gotoxy(55, y);
  cout << cashier.age;
  gotoxy(65, y);
  cout << cashier.clients.length;
}

void showClientsListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Nombres";
  gotoxy(20, y);
  cout << "Apellidos";
  gotoxy(40, y);
  cout << "Genero";
  gotoxy(55, y);
  cout << "Edad";
  gotoxy(65, y);
  cout << "# de expedientes";
  gotoxy(80, y);
  cout << "En el cajero";
}

void showClient(cashierStruct cashier, clientStruct client, int i, int y) {
  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << client.firstName;
  gotoxy(20, y);
  cout << client.lastName;
  gotoxy(40, y);
  cout << getGenre(client.genre);
  gotoxy(55, y);
  cout << client.age;
  gotoxy(65, y);
  cout << client.records.length;
  gotoxy(80, y);
  cout << cashier.firstName + " " + cashier.lastName;
}

void showRecordsListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Codigo";
  gotoxy(15, y);
  cout << "Nombre";
  gotoxy(40, y);
  cout << "Del cliente";
  gotoxy(65, y);
  cout << "En el cajero";
}

void showClient(cashierStruct cashier, clientStruct client, recordStruct record,
                int i, int y) {
  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << record.code;
  gotoxy(15, y);
  cout << record.name;
  gotoxy(40, y);
  cout << client.firstName + " " + client.lastName;
  gotoxy(65, y);
  cout << cashier.firstName + " " + cashier.lastName;
}
