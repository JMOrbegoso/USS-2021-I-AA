#include "helpers.h"
#include "structs.h"
#include <iostream>

using namespace std;

authorStruct buildAuthor(string firstName, string lastName,
                         unsigned short age) {
  authorStruct author;
  author.firstName = firstName;
  author.lastName = lastName;
  author.age = age;

  return author;
}

void addToCollection(authorsList &authors, authorStruct newAuthor) {
  authorNode *newNode = new authorNode();

  authorNode *lastNode = authors.firstNode;

  newNode->author = newAuthor;
  newNode->next = NULL;

  if (authors.firstNode == NULL) {
    authors.firstNode = newNode;
    authors.firstNode->previous = NULL;
    return;
  }

  while (lastNode->next != NULL) {
    lastNode = lastNode->next;
  }

  lastNode->next = newNode;
  newNode->previous = lastNode;

  authors.length++;
}

void collectionsInitialization(authorsList &authors) {
  authors.firstNode = NULL;
  authors.length = 0;
}

void dataInitialization(authorsList &authors) {
  authorStruct gabo, platero;

  gabo = buildAuthor("Gabriel", "Garcia Marquez", 87);
  platero = buildAuthor("Julio Ramon", "Jimenez", 70);

  addToCollection(authors, gabo);
  addToCollection(authors, platero);
}

void showAuthorsListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Nombre";
  gotoxy(20, y);
  cout << "Apellido";
  gotoxy(40, y);
  cout << "Edad";
}

void showAuthor(authorStruct author, int i) {
  gotoxy(0, 10 + i);
  cout << i;
  gotoxy(5, 10 + i);
  cout << author.firstName;
  gotoxy(20, 10 + i);
  cout << author.lastName;
  gotoxy(40, 10 + i);
  cout << author.age;
}
