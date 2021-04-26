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
  } else {
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }

    lastNode->next = newNode;
    newNode->previous = lastNode;
  }

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
  } else {
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }

    lastNode->next = newNode;
    newNode->previous = lastNode;
  }

  writers.length++;
}

void collectionsInitialization(libraryStruct &library) {
  library.name = "Las Condes";
  library.address = "Las Condes #444";

  library.books.head = NULL;
  library.books.length = 0;
}

void dataInitialization(libraryStruct &library) {
  bookStruct platero, color, tercer, quijote, granja, divina;
  writerStruct jimenez, lovecraft, lobsang, cervantes, orwell, dante, virgilio;

  platero = buildBook("Platero y Yo", "pla", 10, 200);
  color = buildBook("El color que caýo del cielo", "col", 20, 150);
  tercer = buildBook("La apertura del tercer ojo", "ojo", 30, 250);
  quijote = buildBook("Quijote de la mancha", "quj", 40, 120);
  granja = buildBook("Revelion en la granja", "gra", 20, 130);
  divina = buildBook("La Divina Comedia", "ldc", 10, 140);

  jimenez = buildWriter("Julio Ramon", "Jimenez", 70, 'm');
  lovecraft = buildWriter("H.P.", "Lovecraft", 70, 'm');
  lobsang = buildWriter("Lobsang", "Rampa", 70, 'm');
  cervantes = buildWriter("Miguel", "De Cervantes", 70, 'm');
  orwell = buildWriter("George", "Orwell", 70, 'm');
  dante = buildWriter("Dante", "Alighieri", 70, 'm');
  virgilio = buildWriter("-", "Virgilio", 70, 'm');

  addToCollection(platero.writers, jimenez);
  addToCollection(color.writers, lovecraft);
  addToCollection(tercer.writers, lobsang);
  addToCollection(quijote.writers, cervantes);
  addToCollection(granja.writers, orwell);
  addToCollection(divina.writers, dante);
  addToCollection(divina.writers, virgilio);

  addToCollection(library.books, platero);
  addToCollection(library.books, color);
  addToCollection(library.books, tercer);
  addToCollection(library.books, quijote);
  addToCollection(library.books, granja);
  addToCollection(library.books, divina);
}

bookStruct *iterateBooksList(booksList books, int index) {
  if (0 >= index) {
    return NULL;
  }

  if (index > books.length) {
    return NULL;
  }

  bookNode *book_node = books.head;

  for (int i = 1; book_node != NULL; i++) {
    if (i == index) {
      return &(book_node->book);
    }
    book_node = book_node->next;
  }

  return NULL;
}

bookStruct *requestBookWithSelector(libraryStruct library) {
  int selectedOption;

  cout << endl << "Escoja una libro para añadir el autor:" << endl << endl;

  bookNode *book_node = library.books.head;

  for (int i = 1; book_node != NULL; i++) {
    cout << "[" << i << "] - " << book_node->book.title << endl;
    book_node = book_node->next;
  }

  cout << endl << "Introduzca la opción deseada:" << endl;

  do {
    cin >> selectedOption;
  } while (!(0 < selectedOption && selectedOption <= library.books.length));

  return iterateBooksList(library.books, selectedOption);
}

bookStruct *requestBookWithSearcher(libraryStruct library) {
  string textToFind;
  bookNode *book_node;

  textToFind = requestText("Ingrese el titulo exacto del libro del autor", 1);

  book_node = library.books.head;

  while (book_node != NULL) {
    if (book_node->book.title == textToFind) {
      return &(book_node->book);
    }
    book_node = book_node->next;
  }
  return NULL;
}

void showWritersListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Nombres";
  gotoxy(20, y);
  cout << "Apellidos";
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
  cout << getGenre(writer.genre);
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

void showBooksWithWritersListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Nombre";
  gotoxy(44, y);
  cout << "Codigo";
  gotoxy(60, y);
  cout << "Escritores";
}

void showBookWithWriter(bookStruct book, int i, int y) {
  string writers;
  writerNode *writer_node = book.writers.head;

  while (writer_node != NULL) {
    writers = concatenateStrings(writers,
                                 writer_node->writer.firstName + " " +
                                     writer_node->writer.lastName,
                                 ", ");
    writer_node = writer_node->next;
  }

  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << book.title;
  gotoxy(44, y);
  cout << book.code;
  gotoxy(60, y);
  cout << writers;
}
