#include "structFunctions.h"

using namespace std;

void showAppTitle() {
  cout << endl
       << "-----------------------------------------------------------" << endl;
  cout << "\t Semana 09 - Problema 01 - Arboles " << endl << endl << endl;
  cout << "-----------------------------------------------------------" << endl;
}

void registerPerson(peopleThree &people) {
  string firstName, lastName;
  unsigned short age;

  personStruct newPerson;

  clearScreen();
  showAppTitle();

  gotoxy(20, 10);
  cout << "Registrar nuevo estudiante:" << endl;

  firstName = requestText("Ingrese los nombres del nuevo estudiante", 2);
  lastName = requestText("Ingrese los apellidos del nuevo estudiante", 2);
  age =
      requestIntegerNumber("Ingrese la edad del la persona",
                           "Por favor ingrese una edad entre 0 y 120", 0, 120);

  newPerson = buildPerson(lastName, firstName, age);

  insertPerson(people, newPerson);

  cout << "La persona fue añadida de forma exitosa." << endl;
}

void showPeopleByPreOrder(peopleThree people, void (*func)(personStruct)) {
  func(people->person);
  if (people->left) showPeopleByPreOrder(people->left, func);
  if (people->right) showPeopleByPreOrder(people->right, func);
}

void showPeopleByInOrder(peopleThree people, void (*func)(personStruct)) {
  func(people->person);
  if (people->left) showPeopleByInOrder(people->left, func);
  if (people->right) showPeopleByInOrder(people->right, func);
}

void showPeopleByPostOrder(peopleThree people, void (*func)(personStruct)) {
  func(people->person);
  if (people->left) showPeopleByPostOrder(people->left, func);
  if (people->right) showPeopleByPostOrder(people->right, func);
}

void findPerson(peopleThree people, string lastNameToFind) {
  if (people != NULL) {
    if (containsText(people->person.lastName, lastNameToFind)) {
      showPerson(people->person);
      return;
    }
  }
}

void findPeople(peopleThree people) {
  string lastNameToFind;
  lastNameToFind = requestText("Ingrese el apellido a buscar", 1);

  findPerson(people, lastNameToFind);
}

void calculateHeight(peopleThree people) {
  int height;
  height = getHeight(people);
  cout << "La altura del árbol de personas es de " << height;
}

void deletePeopleByLastName(peopleThree people) {
  clearScreen();

  if (people != NULL) {
    string lastNameToFind;
    lastNameToFind =
        requestText("Ingrese el apellido de la persona a borrar:", 2);
    deletePerson(people, lastNameToFind);
  } else {
    cout << "No hay personas registradas.";
  }
}

int requestMenuOption(peopleThree people) {
  int selectedOption;

  clearScreen();
  showAppTitle();

  cout << endl
       << "Esta aplicación tiene las siguientes opciones:" << endl
       << endl;

  cout << "[1] Registrar persona" << endl;
  cout << "[2] Mostrar personas en pre-orden" << endl;
  cout << "[3] Mostrar personas en in-orden" << endl;
  cout << "[4] Mostrar personas en post-orden" << endl;
  cout << "[5] Buscar persona" << endl;
  cout << "[6] Eliminar persona" << endl;
  cout << "[7] Calcular altura" << endl;
  cout << endl;
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

void mainMenu(peopleThree &people) {
  int selectedOption;

  do {
    selectedOption = requestMenuOption(people);

    if (selectedOption != 0) {
      switch (selectedOption) {
        case 1:
          registerPerson(people);
          addDelay(2);
          break;
        case 2:
          showPeopleByPreOrder(people, showPerson);
          pauseProcess();
          break;
        case 3:
          showPeopleByInOrder(people, showPerson);
          pauseProcess();
          break;
        case 4:
          showPeopleByPostOrder(people, showPerson);
          pauseProcess();
          break;
        case 5:
          findPeople(people);
          pauseProcess();
          break;
        case 6:
          deletePeopleByLastName(people);
          pauseProcess();
          break;
        case 7:
          calculateHeight(people);
          pauseProcess();
          break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}
