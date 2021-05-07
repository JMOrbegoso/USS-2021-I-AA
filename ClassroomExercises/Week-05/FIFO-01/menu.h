#include "structFunctions.h"

using namespace std;

void showAppTitle() {
  cout << endl
       << "-----------------------------------------------------------" << endl;
  cout << "\t\t Problema 01 de semana 05" << endl;
  cout << "-----------------------------------------------------------" << endl;
  cout << "\t\t\tJuan Manuel" << endl;
  cout << "\t\t\tOrbegoso Rosas" << endl;
  cout << "-----------------------------------------------------------" << endl;
}

int requestMenuOption() {
  int selectedOption;

  clearScreen();
  showAppTitle();

  cout << endl
       << "Esta aplicación tiene las siguientes opciones:" << endl
       << endl;

  cout << "[1] Registrar persona - Encolar" << endl;
  cout << "[2] Atender persona - Desencolar" << endl;
  cout << "[3] Buscar persona" << endl;
  cout << "[4] Mostrar cola" << endl;
  cout << "[5] Vaciar cola " << endl;

  cout << "[0] Cerrar" << endl;

  cout << endl << "Por favor ingrese una de las opciones:" << endl;
  cin >> selectedOption;
  while (!(0 <= selectedOption && selectedOption <= 5)) {
    cout << "La opcion seleccionada fue inválida, por favor seleccione una "
            "opcion válida:"
         << endl;
    cin >> selectedOption;
  }
  return selectedOption;
}

void registerNewPerson(personsQueue &persons) {
  string firstName, lastName, address;
  char genre;
  unsigned short age;

  personStruct newPerson;

  clearScreen();
  showAppTitle();

  gotoxy(40, 10);
  cout << "Registrar nueva persona:" << endl;

  firstName = requestText("Ingrese los nombres de la nueva persona", 2);
  lastName = requestText("Ingrese los apellidos de la nueva persona", 2);
  address = requestText("Ingrese la direccion de la nueva persona", 2);
  genre = requestGenre("Ingrese el genero de la nueva persona");
  age = requestIntegerNumber(
      "Ingrese la edad de la nueva persona",
      "Por favor ingrese una edad mayor a 0 y menor a 110", 0, 110);

  newPerson = buildPerson(firstName, lastName, address, genre, age);

  enqueue(persons, newPerson);

  cout << "La persona fue añadida de forma exitosa" << endl;
}

void findPerson(personsQueue persons) {
  personNode *person_node;
  string lastNameToFind;
  bool personFound = false;

  lastNameToFind = requestText("Ingrese el apellido a buscar:", 2);

  clearScreen();
  showAppTitle();

  gotoxy(40, 10);
  cout << "Todas las personas con un apellido similar a  " << lastNameToFind
       << endl;

  showPersonsListHeader(12);

  person_node = persons.head;

  int i = 1;
  while (person_node != NULL) {
    if (containsText(person_node->person.lastName, lastNameToFind)) {
      personFound = true;
      showPerson(person_node->person, i, i + 12);
      i++;
    }

    person_node = person_node->next;
  }

  if (!personFound)
    cout << endl
         << "No se encontró ninguna persona con un apellido similar a "
         << lastNameToFind << endl;

  cout << endl << endl;
}

void showPersons(personsQueue persons) {
  personNode *person_node;

  clearScreen();
  showAppTitle();

  gotoxy(40, 10);
  cout << "Todas las personas registradas " << endl;

  showPersonsListHeader(12);

  person_node = persons.head;

  int i = 1;
  while (person_node != NULL) {
    showPerson(person_node->person, i, i + 12);
    person_node = person_node->next;
    i++;
  }

  cout << endl << endl;
}

void mainMenu(personsQueue &persons) {
  int selectedOption;

  do {
    selectedOption = requestMenuOption();

    if (selectedOption != 0) {
      switch (selectedOption) {
      case 1:
        registerNewPerson(persons);
        addDelay(2);
        break;

      case 2:
        // registerNewDistrict(department);
        addDelay(2);
        break;

      case 3:
        findPerson(persons);
        pauseProcess();
        break;

      case 4:
        showPersons(persons);
        pauseProcess();
        break;

      case 5:
        // findPersonByDistrict(department);
        pauseProcess();
        break;

      case 6:
        // showAllPersonsData(department);
        pauseProcess();
        break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}
