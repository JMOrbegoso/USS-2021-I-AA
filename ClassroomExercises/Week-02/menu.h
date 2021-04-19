#include "structFunctions.h"

using namespace std;

// Main menu function

void showAppTitle() {
  cout << endl
       << "-----------------------------------------------------------" << endl;
  cout << "\t\t Problema de autores" << endl;
  cout << endl
       << "-----------------------------------------------------------" << endl;
}

int requestMenuOption(authorsList authors) {
  int selectedOption;

  clearScreen();
  showAppTitle();

  cout << endl << "Por favor seleccione la opción deseada:" << endl << endl;

  cout << "[1] Mostrar autores" << endl;
  cout << "[2] Registrar nuevo autor" << endl;

  cout << "[0] Cerrar" << endl;

  cout << endl << "Por favor ingrese una de las opciones:" << endl;
  cin >> selectedOption;
  while (!(0 <= selectedOption && selectedOption <= 2)) {
    cout << "La opcion seleccionada fue inválida, por favor seleccione una "
            "opcion válida:"
         << endl;
    cin >> selectedOption;
  }
  return selectedOption;
}

void registerNewAuthor(authorsList &authors) {
  authorStruct newAuthor;
  string firstName;
  string lastName;
  unsigned short age;

  cout << "Va a registrar un nuevo autor:" << endl << endl;

  firstName = requestText("Ingrese el nombre del nuevo autor", 3);
  lastName = requestText("Ingrese el nombre del nuevo autor", 3);
  age = requestIntegerNumber("Ingrese la edad del nuevo autor", 5);

  newAuthor = buildAuthor(firstName, lastName, age);

  addToCollection(authors, newAuthor);

  cout << "El autor ha sido registrado correctamente";
}

void showAuthors(authorsList authors) {
  clearScreen();
  showAppTitle();

  gotoxy(10, 10);
  cout << "Autores" << endl;

  authorNode *node = authors.firstNode;

  gotoxy(0, 12);
  cout << "#";
  gotoxy(5, 12);
  cout << "Nombre";
  gotoxy(20, 12);
  cout << "Apellido";
  gotoxy(40, 12);
  cout << "Edad";

  int i = 1;
  while (node != NULL) {
    showAuthor(node->author, i);
    node = node->next;
    i++;
  }

  cout << endl << endl;
}

void mainMenu(authorsList &authors) {

  int selectedOption;

  do {
    selectedOption = requestMenuOption(authors);

    if (selectedOption != 0) {
      switch (selectedOption) {
      case 1:
        showAuthors(authors);
        pauseProcess();
        break;

      case 2:
        registerNewAuthor(authors);
        addDelay(3);
        break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}
