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
  cout << "[3] Actualizar datos de un autor" << endl;
  cout << "[4] Buscar autor por apellidos" << endl;

  cout << "[0] Cerrar" << endl;

  cout << endl << "Por favor ingrese una de las opciones:" << endl;
  cin >> selectedOption;
  while (!(0 <= selectedOption && selectedOption <= 4)) {
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

  gotoxy(20, 6);
  cout << "Va a registrar un nuevo autor:" << endl << endl;

  firstName = requestText("Ingrese los nombres del nuevo autor", 3);
  lastName = requestText("Ingrese los apellidos del nuevo autor", 3);
  age = requestIntegerNumber("Ingrese la edad del nuevo autor", 5);

  newAuthor = buildAuthor(firstName, lastName, age);

  addToCollection(authors, newAuthor);

  cout << "El autor ha sido registrado correctamente";
}

void showAuthors(authorsList authors) {
  clearScreen();
  showAppTitle();

  gotoxy(20, 6);
  cout << "Autores" << endl;

  authorNode *node = authors.firstNode;

  showAuthorsListHeader(9);

  int i = 1;
  while (node != NULL) {
    showAuthor(node->author, i);
    node = node->next;
    i++;
  }

  cout << endl << endl;
}

void updateAuthor(authorsList &authors) {
  string authorLastNameToFind, firstName, lastName;
  unsigned short age;
  bool authorFound = false;

  clearScreen();
  showAppTitle();

  gotoxy(20, 6);
  cout << "Va a actualizar los datos de un autor" << endl;

  authorNode *node = authors.firstNode;

  authorLastNameToFind =
      requestText("Ingrese el apellido del autor a editar", 1);

  while (node != NULL) {
    if (containsText(node->author.lastName, authorLastNameToFind)) {
      authorFound = true;

      firstName = requestText("Ingrese el nombre actualizado del autor", 3);
      lastName = requestText("Ingrese el apellido actualizado del autor", 3);
      age = requestIntegerNumber("Ingrese la edad actualizada del autor", 5);

      node->author.firstName = firstName;
      node->author.lastName = lastName;
      node->author.age = age;

      cout << "Los datos del autor se han actualizado correctamente";
      break;
    }

    node = node->next;
  }

  if (!authorFound)
    cout << "El apellido del autor no fue encontrado";

  cout << endl << endl;
}

void findAuthorByLastName(authorsList &authors) {
  string authorLastNameToFind;
  bool authorFound = false;

  clearScreen();
  showAppTitle();

  gotoxy(20, 6);
  cout << "Va a buscar un autor por apellidos" << endl;

  authorNode *node = authors.firstNode;

  authorLastNameToFind =
      requestText("Ingrese el apellido del autor a buscar", 1);

  showAuthorsListHeader(10);

  int i = 1;
  while (node != NULL) {
    if (containsText(node->author.lastName, authorLastNameToFind)) {
      authorFound = true;
      showAuthor(node->author, i);
      i++;
    }

    node = node->next;
  }

  if (!authorFound)
    cout << "No se encontró ningún autor con los apellidos buscados";

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

      case 3:
        updateAuthor(authors);
        addDelay(3);
        break;

      case 4:
        findAuthorByLastName(authors);
        pauseProcess();
        break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}
