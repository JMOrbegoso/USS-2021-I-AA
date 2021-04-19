#include "helpers.h"
#include "structs.h"
#include <iostream>

using namespace std;

// Forward declarations

void collectionsInitialization(authorsList &authors);

authorStruct buildAuthor(string firstName, string lastName, unsigned short age);
void addToCollection(authorsList &authors, authorStruct author);

// Functions

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

void showAuthor(authorStruct author, int i) {
  gotoxy(0, 13 + i);
  cout << i;
  gotoxy(5, 13 + i);
  cout << author.firstName;
  gotoxy(20, 13 + i);
  cout << author.lastName;
  gotoxy(40, 13 + i);
  cout << author.age;
}
