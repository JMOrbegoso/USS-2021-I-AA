#include "structFunctions.h"

void showAppTitle() {
  cout << endl;
  cout << "-----------------------------------------------------------";
  cout << endl << endl;
  cout << "\t Nombre: Problema de clase - 10 & 11 ";
  cout << endl << endl;
  cout << "-----------------------------------------------------------";
  cout << endl;
}

void registerCity(citiesGraph &cities) {
  cityStruct newCity;
  string cityName;

  clearScreen();
  showAppTitle();

  gotoxy(20, 8);
  cout << "Registrar nueva ciudad:" << endl;

  // Build the city struct
  cityName = requestText("Ingrese el nombre de la nueva ciudad", 1);
  newCity = buildCity(cityName);

  insert(cities, newCity);

  cout << "La nueva ciudad fue registrada de forma exitosa.";
  cout << endl << endl;
}

void addCitiesLink(citiesGraph &cities) {
  cityNode *originCityNodePointer, *destinationCityNodePointer;
  cityEdge *newCityEdge = new struct cityEdge;

  clearScreen();
  showAppTitle();

  gotoxy(20, 8);
  cout << "Registrar nuevo enlace entre ciudades:" << endl;

  if (cities.node == NULL || cities.node->next == NULL) {
    cout << "Primero debe de añadir almenos 2 ciudades al grafo.";
    cout << endl << endl;
    return;
  }

  newCityEdge->next = NULL;

  originCityNodePointer = requestCity(cities, "Escoja la ciudad de origen");

  if (originCityNodePointer == NULL) {
    cout << "Introdujo una ciudad no valida";
    cout << endl << endl;
    return;
  }

  destinationCityNodePointer =
      requestCity(cities, "Escoja la ciudad de destino");

  if (destinationCityNodePointer == NULL) {
    cout << "Introdujo una ciudad no valida";
    cout << endl << endl;
    return;
  }

  buildCityEdge(originCityNodePointer, destinationCityNodePointer, newCityEdge);
}

void registerHouse(citiesGraph &cities) {
  houseStruct newHouse;
  string address, owner;
  unsigned short floorsQuantity;
  cityNode *cityNodePointer;

  clearScreen();
  showAppTitle();

  gotoxy(20, 8);
  cout << "Registrar nueva casa:" << endl;

  address = requestText("Ingrese la dirección de la nueva vivienda", 5);
  owner = requestText(
      "Ingrese el nombre completo del dueño de la nueva vivienda", 5);
  floorsQuantity =
      requestIntegerNumber("Ingrese el numero de pisos de la nueva vivienda",
                           "Por favor ingrese un numero mayor o igual a 1", 1);

  newHouse = buildHouse(address, owner, floorsQuantity);

  cityNodePointer = requestCity(
      cities, "Escoja la ciudad en la que se encuentra la vivienda");

  if (cityNodePointer == NULL) {
    cout << "No seleccionó una ciudad valida para la nueva vivienda.";
    cout << endl << endl;
    return;
  }

  insert(cityNodePointer->city.houses, newHouse);

  cout << "La vivienda fue registrada de forma exitosa.";
  cout << endl << endl;
}

void registerPerson(citiesGraph &cities) {
  personStruct newPerson;
  string dni, firstName, lastName;
  float salary;
  cityNode *cityNodePointer;
  houseNode *houseNodePointer;

  clearScreen();
  showAppTitle();

  gotoxy(20, 8);
  cout << "Registrar nuevo habitante:" << endl;

  dni = requestText("Ingrese el DNI del nuevo habitante", 8, 8);
  firstName = requestText("Ingrese el nombre del nuevo habitante", 3);
  lastName = requestText("Ingrese el apellido del nuevo habitante", 3);
  salary = requestMoney("Ingrese el salario del nuevo habitante", 1);

  newPerson = buildPerson(dni, firstName, lastName, salary);

  cityNodePointer = requestCity(
      cities, "Escoja la ciudad en la que se encuentra la vivienda");

  if (cityNodePointer == NULL) {
    cout << "No seleccionó una ciudad valida para la nueva vivienda.";
    cout << endl << endl;
    return;
  }

  houseNodePointer = requestHouseWithSelector(
      cityNodePointer->city.houses,
      "Escoja la casa en la que vive el nuevo habitante");

  if (houseNodePointer == NULL) {
    cout << "No seleccionó una vivienda valida para el nuevo habitante.";
    cout << endl << endl;
    return;
  }

  insert(houseNodePointer->house.people, newPerson);

  cout << "El habitante fue registrado de forma exitosa.";
  cout << endl << endl;
}

void showAllCities(citiesGraph cities) {
  int i;
  cityNode *cityNodePointer;

  clearScreen();
  showAppTitle();

  gotoxy(20, 8);
  cout << "Lista de todas las ciudades:" << endl;

  cityNodePointer = cities.node;

  showCitiesListHeader(10);

  for (int i = 0; cityNodePointer != NULL; i++) {
    showCity(cityNodePointer->city, i, i + 12);
    cityNodePointer = cityNodePointer->next;
  }

  cout << endl << endl;
}

void showCitiesWithDestinations(citiesGraph cities) {
  cityNode *auxCityNode;
  cityEdge *tempCityEdge;

  clearScreen();
  showAppTitle();

  gotoxy(20, 8);
  cout << "Lista de todas las ciudades con sus destinos:" << endl;

  showCitiesWithDestinationsListHeader(10);

  auxCityNode = cities.node;

  for (int i = 0; auxCityNode != NULL; i++) {
    showCityWithDestinations(auxCityNode, i, 12 + i);
    auxCityNode = auxCityNode->next;
  }

  cout << endl << endl;
}

void showAllHouses(citiesGraph cities) {
  cityNode *cityNodePointer;
  houseNode *houseNodePointer;

  clearScreen();
  showAppTitle();

  gotoxy(20, 10);
  cout << "Todas las viviendas de todas las ciudades registradas:" << endl;

  cityNodePointer = cities.node;

  showHousesListHeader(12);

  int i = 1;
  while (cityNodePointer != NULL) {
    houseNodePointer = cityNodePointer->city.houses.head;
    while (houseNodePointer != NULL) {
      showHouse(houseNodePointer->house, i, i + 13);
      houseNodePointer = houseNodePointer->next;
      i++;
    }
    cityNodePointer = cityNodePointer->next;
  }

  cout << endl << endl;
}

void showHousesByCity(citiesGraph cities) {
  cityNode *cityNodePointer;
  houseNode *houseNodePointer;

  cityNodePointer =
      requestCity(cities, "Ingrese la ciudad que desea revisar sus viviendas");

  clearScreen();
  showAppTitle();

  gotoxy(20, 10);
  cout << "Estudiantes haciendo cola en la sala de tematica "
       << cityNodePointer->city.name << ":" << endl;

  houseNodePointer = cityNodePointer->city.houses.head;

  showHousesListHeader(12);

  for (int i = 1; houseNodePointer != NULL; i++) {
    showHouse(houseNodePointer->house, i, i + 13);
    houseNodePointer = houseNodePointer->next;
  }

  cout << endl << endl;
}

void showAllPeople(citiesGraph cities) {
  cityNode *cityNodePointer;
  houseNode *houseNodePointer;
  personNode *personNodePointer;

  clearScreen();
  showAppTitle();

  gotoxy(20, 10);
  cout << "Todos los habitantes de todas las viviendas de todas las ciudades"
       << endl;

  cityNodePointer = cities.node;

  showPeopleListHeader(12);

  int i = 1;
  while (cityNodePointer != NULL) {
    houseNodePointer = cityNodePointer->city.houses.head;
    while (houseNodePointer != NULL) {
      personNodePointer = houseNodePointer->house.people.head;
      while (personNodePointer != NULL) {
        showPerson(personNodePointer->person, i, i + 13);
        personNodePointer = personNodePointer->next;
        i++;
      }
      houseNodePointer = houseNodePointer->next;
    }
    cityNodePointer = cityNodePointer->next;
  }

  cout << endl << endl;
}

void showPeopleByCity(citiesGraph cities) {
  cityNode *cityNodePointer;
  houseNode *houseNodePointer;
  personNode *personNodePointer;

  cityNodePointer = requestCity(
      cities, "Seleccione la ciudad de la que desea ver sus habitantes");

  if (cityNodePointer == NULL) {
    cout << "No seleccionó una ciudad valida.";
    cout << endl << endl;
    return;
  }

  clearScreen();
  showAppTitle();

  gotoxy(20, 10);
  cout << "Todos los habitantes de todas las viviendas de la ciudad de "
       << cityNodePointer->city.name << endl;

  showPeopleListHeader(12);

  int i = 1;
  houseNodePointer = cityNodePointer->city.houses.head;
  while (houseNodePointer != NULL) {
    personNodePointer = houseNodePointer->house.people.head;
    while (personNodePointer != NULL) {
      showPerson(personNodePointer->person, i, i + 13);
      personNodePointer = personNodePointer->next;
      i++;
    }
    houseNodePointer = houseNodePointer->next;
  }

  cout << endl << endl;
}

void showPeopleByHouse(citiesGraph cities) {
  cityNode *cityNodePointer;
  houseNode *houseNodePointer;
  personNode *personNodePointer;

  cityNodePointer =
      requestCity(cities,
                  "Seleccione la ciudad en la que se encuentra la vivienda de "
                  "la que desea ver sus habitantes");

  if (cityNodePointer == NULL) {
    cout << "No seleccionó una ciudad valida.";
    cout << endl << endl;
    return;
  }

  houseNodePointer = requestHouseWithSelector(
      cityNodePointer->city.houses,
      "Seleccione la vivienda de la que desea ver sus habitantes");

  if (houseNodePointer == NULL) {
    cout << "No seleccionó una vivienda valida.";
    cout << endl << endl;
    return;
  }

  clearScreen();
  showAppTitle();

  gotoxy(20, 10);
  cout << "Todos los habitantes la vivienda propiedad de "
       << houseNodePointer->house.owner << " ubicada en "
       << houseNodePointer->house.address << endl;

  showPeopleListHeader(12);

  int i = 1;
  personNodePointer = houseNodePointer->house.people.head;
  while (personNodePointer != NULL) {
    showPerson(personNodePointer->person, i, i + 13);
    personNodePointer = personNodePointer->next;
    i++;
  }

  cout << endl << endl;
}
