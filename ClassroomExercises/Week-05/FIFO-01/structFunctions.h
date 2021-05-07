#include "helpers.h"
#include "structs.h"
#include <iostream>

using namespace std;

void collectionsInitialization(personsQueue &persons) {
  persons.head = NULL;
  persons.tail = NULL;
  persons.length = 0;
}

personStruct buildPerson(string firstName, string lastName, string address,
                         char genre, unsigned short age) {
  personStruct person;
  person.firstName = firstName;
  person.lastName = lastName;
  person.address = address;
  person.genre = genre;
  person.age = age;

  return person;
}

void enqueue(personsQueue &persons, personStruct newPerson) {
  personNode *aux = new personNode;

  aux->person = newPerson;
  aux->next = NULL;

  if (persons.head == NULL) {
    persons.head = aux;
  } else {
    persons.tail->next = aux;
  }

  persons.tail = aux;
  persons.length++;
}

void dequeue() {}

void dataInitialization(personsQueue &persons) {
  personStruct person_1, person_2, person_3, person_4, person_5, person_6;

  person_1 = buildPerson("Julio", "Gomez", "Av. Los Algoritmos #111", 'm', 47);
  person_2 =
      buildPerson("Maria", "Izquierdo", "Av. Los Algoritmos #112", 'f', 15);
  person_3 = buildPerson("Luis", "Lopez", "Av. Los Algoritmos #113", 'm', 27);
  person_4 = buildPerson("Tulio", "Rojas", "Av. Los Algoritmos #113", 'm', 11);
  person_5 = buildPerson("Rosa", "Jimenez", "Av. Los Algoritmos #121", 'f', 72);
  person_6 =
      buildPerson("Alex", "Rodrigez", "Av. Los Algoritmos #123", 'm', 28);

  enqueue(persons, person_1);
  enqueue(persons, person_2);
  enqueue(persons, person_3);
  enqueue(persons, person_4);
  enqueue(persons, person_5);
  enqueue(persons, person_6);
}

void showPersonsListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Nombres";
  gotoxy(20, y);
  cout << "Apellidos";
  gotoxy(40, y);
  cout << "Dirección";
  gotoxy(70, y);
  cout << "Genero";
  gotoxy(85, y);
  cout << "Edad";
}

void showPerson(personStruct person, int i, int y) {
  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << person.firstName;
  gotoxy(20, y);
  cout << person.lastName;
  gotoxy(40, y);
  cout << person.address;
  gotoxy(70, y);
  cout << getGenre(person.genre);
  gotoxy(85, y);
  cout << person.age;
}
