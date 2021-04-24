#include "structFunctions.h"

using namespace std;

// Main menu function

void showAppTitle(libraryStruct library) {
  cout << endl
       << "--------------------------------------------------------------------"
          "------------------"
       << endl;
  cout << "\t\t\t\t Bienvenido a la biblioteca " << library.name << endl;
  cout << "\t-> Dirección: " << library.address;
  cout << endl
       << "--------------------------------------------------------------------"
          "------------------"
       << endl;
}

int requestMenuOption(libraryStruct library) {
  int selectedOption;

  clearScreen();
  showAppTitle(library);

  cout << endl << "Por favor seleccione la opción deseada:" << endl << endl;

  cout << "[1] Registrar nuevo libro" << endl;
  cout << "[2] Registrar nuevo autor en un libro" << endl;
  cout << "[3] Listar libros" << endl;
  cout << "[4] Listar libros y sus autores" << endl;
  cout << "[5] Buscar libro por titulo" << endl;
  cout << "[6] Buscar autor por apellidos" << endl;
  cout << "[7] Borrar autor" << endl;

  cout << "[0] Cerrar" << endl;

  cout << endl << "Por favor ingrese una de las opciones:" << endl;
  cin >> selectedOption;
  while (!(0 <= selectedOption && selectedOption <= 7)) {
    cout << "La opcion seleccionada fue inválida, por favor seleccione una "
            "opcion válida:"
         << endl;
    cin >> selectedOption;
  }
  return selectedOption;
}

void registerBook(libraryStruct &library) {
  string title, code;
  float price;
  unsigned short pagesQuantity;
  bookStruct newBook;

  clearScreen();
  showAppTitle(library);

  gotoxy(40, 6);
  cout << "Registrar nuevo libro:" << endl;

  title = requestText("Ingrese el titulo del nuevo libro", 1);
  code = requestText("Ingrese el codigo del nuevo libro", 3);
  price = requestMoney("Ingrese el precio del nuevo libro (S/)", 1);
  pagesQuantity =
      requestIntegerNumber("Ingrese la cantidad de hojas del nuevo libro", 1);

  newBook = buildBook(title, code, price, pagesQuantity);

  addToCollection(library.books, newBook);

  cout << "El libro fue añadido de forma exitosa" << endl;
}

void showBooks(libraryStruct library) {
  clearScreen();
  showAppTitle(library);

  gotoxy(40, 6);
  cout << "Libros existentes:" << endl;

  bookNode *book_node = library.books.head;

  showBooksListHeader(8);

  int i = 1;
  while (book_node != NULL) {
    showBook(book_node->book, i, i + 9);
    book_node = book_node->next;
    i++;
  }

  cout << endl << endl;
}

void showBooksWithWriters(libraryStruct library) {
  clearScreen();
  showAppTitle(library);

  gotoxy(40, 6);
  cout << "Libros existentes y sus escritores:" << endl;

  bookNode *book_node = library.books.head;

  showBooksWithWritersListHeader(8);

  int i = 1;
  while (book_node != NULL) {
    showBookWithWriter(book_node->book, i, i + 9);
    book_node = book_node->next;
    i++;
  }

  cout << endl << endl;
}

void findBookByTitle(libraryStruct library) {
  string textToFind;
  bool bookFound = false;

  clearScreen();
  showAppTitle(library);

  textToFind = requestText("Ingrese el titulo del libro a buscar", 3);

  gotoxy(40, 6);
  cout << "Libros con un titulo similar a " << textToFind << endl;

  bookNode *node = library.books.head;

  showBooksListHeader(8);

  int i = 1;
  while (node != NULL) {
    if (containsText(node->book.title, textToFind)) {
      bookFound = true;
      showBook(node->book, i, i + 9);
      i++;
    }
    node = node->next;
  }

  cout << endl << endl;
}

void findWriterByLastName(libraryStruct library) {
  string textToFind;
  bookNode *book_node;
  writerNode *writer_node;

  textToFind = requestText("Ingrese el apellido del escritor a buscar", 3);

  clearScreen();
  showAppTitle(library);

  gotoxy(40, 6);
  cout << "Escritores con un apellido similar a :" << textToFind << endl;

  book_node = library.books.head;

  showWritersListHeader(8);

  int i = 1;
  while (book_node != NULL) {
    writer_node = book_node->book.writers.head;
    while (writer_node != NULL) {
      if (containsText(writer_node->writer.lastName, textToFind)) {
        showWriter(writer_node->writer, i, i + 9);
        i++;
      }
      writer_node = writer_node->next;
    }
    book_node = book_node->next;
  }

  cout << endl << endl;
}

void mainMenu(libraryStruct &library) {

  int selectedOption;

  do {
    selectedOption = requestMenuOption(library);

    if (selectedOption != 0) {
      switch (selectedOption) {
      case 1:
        registerBook(library);
        addDelay(2);
        break;

      case 3:
        showBooks(library);
        pauseProcess();
        break;

      case 4:
        showBooksWithWriters(library);
        pauseProcess();
        break;

      case 5:
        findBookByTitle(library);
        pauseProcess();
        break;

      case 6:
        findWriterByLastName(library);
        pauseProcess();
        break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}
