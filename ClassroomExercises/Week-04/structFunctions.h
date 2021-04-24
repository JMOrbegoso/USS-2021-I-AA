#include "helpers.h"
#include "structs.h"
#include <iostream>

using namespace std;

writerStruct buildWriter(string firstName, string lastName, unsigned short age,
                         char genre) {
  writerStruct writer;
  writer.firstName = firstName;
  writer.lastName = lastName;
  writer.age = age;
  writer.genre = genre;

  return writer;
}

bookStruct buildBook(string title, string code, float price,
                     unsigned short pagesQuantity) {
  bookStruct book;
  book.title = title;
  book.code = code;
  book.price = price;
  book.pagesQuantity = pagesQuantity;

  book.writers.head = NULL;
  book.writers.length = 0;

  return book;
}

void addToCollection(booksList &books, bookStruct newBook) {
  bookNode *newNode = new bookNode();

  bookNode *lastNode = books.head;

  newNode->book = newBook;
  newNode->next = NULL;

  if (books.head == NULL) {
    books.head = newNode;
    books.head->previous = NULL;
    return;
  }

  while (lastNode->next != NULL) {
    lastNode = lastNode->next;
  }

  lastNode->next = newNode;
  newNode->previous = lastNode;

  books.length++;
}

void addToCollection(writersList &writers, writerStruct newWriter) {
  writerNode *newNode = new writerNode();

  writerNode *lastNode = writers.head;

  newNode->writer = newWriter;
  newNode->next = NULL;

  if (writers.head == NULL) {
    writers.head = newNode;
    writers.head->previous = NULL;
    return;
  }

  while (lastNode->next != NULL) {
    lastNode = lastNode->next;
  }

  lastNode->next = newNode;
  newNode->previous = lastNode;

  writers.length++;
}

void collectionsInitialization(libraryStruct &library) {
  library.name = "Las Condes";
  library.address = "Las Condes #444";

  library.books.head = NULL;
  library.books.length = 0;
}

void dataInitialization(libraryStruct &library) {
  bookStruct platero, color, tercer, quijote, cid, odisea;
  writerStruct jimenez, lovecraft, lobsang, cervantes, anonimo, homero;

  platero = buildBook("Platero y Yo", "py", 10, 200);
  color = buildBook("El color que caýo del cielo", "cc", 20, 150);
  tercer = buildBook("La apertura del tercer ojo", "ojo", 30, 250);
  quijote = buildBook("Quijote de la mancha", "quj", 40, 120);
  cid = buildBook("Mio Cid", "cid", 20, 130);
  odisea = buildBook("La Odisea", "od", 10, 140);

  jimenez = buildWriter("Julio Ramon", "Jimenez", 70, 'm');
  lovecraft = buildWriter("H.P.", "Lovecraft", 70, 'm');
  lobsang = buildWriter("Lobsang", "Rampa", 70, 'm');
  cervantes = buildWriter("Miguel", "De Cervantes", 70, 'm');
  anonimo = buildWriter("Anonimo", "-", 70, 'm');
  homero = buildWriter("Homero", "-", 70, 'm');

  addToCollection(platero.writers, jimenez);
  addToCollection(color.writers, lovecraft);
  addToCollection(tercer.writers, lobsang);
  addToCollection(quijote.writers, cervantes);
  addToCollection(cid.writers, anonimo);
  addToCollection(odisea.writers, homero);

  addToCollection(library.books, platero);
  addToCollection(library.books, color);
  addToCollection(library.books, tercer);
  addToCollection(library.books, quijote);
  addToCollection(library.books, cid);
  addToCollection(library.books, odisea);
}

void showWritersListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Titulo";
  gotoxy(20, y);
  cout << "";
  gotoxy(40, y);
  cout << "Edad";
  gotoxy(45, y);
  cout << "Genero";
}

void showWriter(writerStruct writer, int i, int y) {
  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << writer.firstName;
  gotoxy(20, y);
  cout << writer.lastName;
  gotoxy(40, y);
  cout << writer.age;
  gotoxy(45, y);
  cout << writer.genre;
}

void showBooksListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Nombre";
  gotoxy(44, y);
  cout << "Codigo";
  gotoxy(54, y);
  cout << "Precio (S/)";
  gotoxy(70, y);
  cout << "Nº Hojas";
}

void showBook(bookStruct book, int i, int y) {
  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << book.title;
  gotoxy(44, y);
  cout << book.code;
  gotoxy(54, y);
  cout << book.price;
  gotoxy(70, y);
  cout << book.pagesQuantity;
}
