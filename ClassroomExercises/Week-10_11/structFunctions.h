#include "helpers.h"
#include "structs.h"

using namespace std;

// Factories

personStruct buildPerson(string dni, string firstName, string lastName,
                         float salary) {
  personStruct person;

  person.dni = dni;
  person.firstName = firstName;
  person.lastName = lastName;
  person.salary = salary;

  return person;
}

houseStruct buildHouse(string address, string owner,
                       unsigned short floorsQuantity) {
  houseStruct house;

  house.address = address;
  house.owner = owner;
  house.floorsQuantity = floorsQuantity;

  house.people.head = NULL;
  house.people.length = 0;

  return house;
}

cityStruct buildCity(string name) {
  cityStruct city;

  city.name = name;

  city.houses.head = NULL;
  city.houses.length = 0;

  return city;
}

void buildCityEdge(cityNode *aux1, cityNode *aux2, cityEdge *newCityEdge) {
  cityEdge *temp;

  if (aux1->adjacent == NULL) {
    aux1->adjacent = newCityEdge;
    newCityEdge->destiny = aux2;
  } else {
    temp = aux1->adjacent;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    newCityEdge->destiny = aux2;
    temp->next = newCityEdge;
  }
}

// Insert to collection

void insert(citiesGraph &cities, cityStruct newCity) {
  cityNode *auxCityNode;

  // Build the city node
  cityNode *newCityNode = new struct cityNode;
  newCityNode->next = NULL;
  newCityNode->adjacent = NULL;
  newCityNode->city = newCity;

  // Add the city node to the graph
  if (cities.node == NULL) {
    cities.node = newCityNode;
  } else {
    auxCityNode = cities.node;
    while (auxCityNode->next != NULL) {
      auxCityNode = auxCityNode->next;
    }
    auxCityNode->next = newCityNode;
  }

  cities.length++;
}

void insert(housesList &houses, houseStruct newHouse) {
  houseNode *roomNodePointer = new houseNode();

  houseNode *lastNode = houses.head;

  roomNodePointer->house = newHouse;
  roomNodePointer->next = NULL;

  if (houses.head == NULL) {
    houses.head = roomNodePointer;
  } else {
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }

    lastNode->next = roomNodePointer;
  }

  houses.length++;
}

void insert(peopleList &people, personStruct newPerson) {
  personNode *roomNodePointer = new personNode();

  personNode *lastNode = people.head;

  roomNodePointer->person = newPerson;
  roomNodePointer->next = NULL;

  if (people.head == NULL) {
    people.head = roomNodePointer;
  } else {
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }

    lastNode->next = roomNodePointer;
  }

  people.length++;
}

// Init

void collectionsInitialization(citiesGraph &cities) {
  cities.node = NULL;
  cities.edge = NULL;
  cities.length = 0;
}

void dataInitialization(citiesGraph &cities) {
  cityStruct ica, lima, trujillo, chiclayo, piura, tumbes;
  houseStruct house1, house2, house3, house4;
  personStruct person1, person2, person3, person4, person5, person6, person7,
      person8, person9, person10;

  ica = buildCity("Ica");
  lima = buildCity("Lima");
  trujillo = buildCity("Trujillo");
  chiclayo = buildCity("Chiclayo");
  piura = buildCity("Piura");
  tumbes = buildCity("Tumbes");

  house1 = buildHouse("Av. Bolognesi 111", "Jose Martinez", 1);
  house2 = buildHouse("Av. Heroes 211", "Justin Rojas", 1);
  house3 = buildHouse("Av. Javier Prado 391", "Jhon Doe", 1);
  house4 = buildHouse("Av. Manzanos 61", "Marco Gonzales", 1);

  person1 = buildPerson("12411284", "Isabela", "Apolinario", 1200);
  person2 = buildPerson("12411284", "Joel", "Rojas", 1200);
  person3 = buildPerson("12411284", "Felipe", "Gonzales", 1200);
  person4 = buildPerson("12411284", "Marcelo", "Marquez", 1200);
  person5 = buildPerson("12411284", "Josefina", "Fernandez", 1200);
  person6 = buildPerson("12411284", "Nico", "Lopez", 1200);
  person7 = buildPerson("12411284", "Lucia", "Castañeda", 1200);
  person8 = buildPerson("12411284", "Jose", "Perez", 1200);
  person9 = buildPerson("12411284", "Micaela", "Espinoza", 1200);
  person10 = buildPerson("12411284", "Eusebia", "Mendez", 1200);

  insert(house1.people, person1);
  insert(house1.people, person2);
  insert(house1.people, person3);
  insert(house2.people, person4);
  insert(house2.people, person5);
  insert(house3.people, person6);
  insert(house4.people, person7);
  insert(house4.people, person8);
  insert(house4.people, person9);
  insert(house4.people, person10);

  insert(lima.houses, house1);
  insert(trujillo.houses, house2);
  insert(chiclayo.houses, house3);
  insert(tumbes.houses, house4);

  insert(cities, ica);
  insert(cities, lima);
  insert(cities, trujillo);
  insert(cities, chiclayo);
  insert(cities, piura);
  insert(cities, tumbes);
}

// Selectors/Pickers

cityNode *iterateCitiesGraph(citiesGraph cities, int index) {
  cityNode *cityNodePointer;

  if (0 >= index) {
    return NULL;
  }

  if (index > cities.length) {
    return NULL;
  }

  cityNodePointer = cities.node;

  for (int i = 1; cityNodePointer != NULL; i++) {
    if (i == index) {
      return cityNodePointer;
    }
    cityNodePointer = cityNodePointer->next;
  }

  return NULL;
}

cityNode *requestCity(citiesGraph cities, string message) {
  int selectedOption;
  cityNode *cityNodePointer;

  cout << endl
       << message << "." << endl
       << "Escoja entre las " << cities.length
       << " ciudades siguientes:" << endl
       << endl;

  cityNodePointer = cities.node;

  for (int i = 1; cityNodePointer != NULL; i++) {
    cout << "[" << i << "] - " << cityNodePointer->city.name << " - Con "
         << cityNodePointer->city.houses.length << " viviendas." << endl;
    cityNodePointer = cityNodePointer->next;
  }

  cout << endl << "Introduzca la opción deseada:" << endl;
  cin >> selectedOption;

  while (!(1 <= selectedOption && selectedOption <= cities.length)) {
    cout << "Por favor, introduzca un valor entre 1 y " << cities.length << "."
         << endl;
    fflush(stdin);
    cin >> selectedOption;
  }

  return iterateCitiesGraph(cities, selectedOption);
}

houseNode *iterateHousesList(housesList houses, int index) {
  houseNode *houseNodePointer;

  if (0 >= index) {
    return NULL;
  }

  if (index > houses.length) {
    return NULL;
  }

  houseNodePointer = houses.head;

  for (int i = 1; houseNodePointer != NULL; i++) {
    if (i == index) {
      return houseNodePointer;
    }
    houseNodePointer = houseNodePointer->next;
  }

  return NULL;
}

houseNode *requestHouseWithSelector(housesList &houses, string message) {
  int selectedOption;
  houseNode *houseNodePointer;

  cout << endl
       << message << "." << endl
       << "Escoja entre las " << houses.length
       << " viviendas siguientes:" << endl
       << endl;

  houseNodePointer = houses.head;

  for (int i = 1; houseNodePointer != NULL; i++) {
    cout << "[" << i << "] - " << houseNodePointer->house.address << endl;
    houseNodePointer = houseNodePointer->next;
  }

  cout << endl << "Introduzca la opción deseada:" << endl;
  cin >> selectedOption;

  while (!(1 <= selectedOption && selectedOption <= houses.length)) {
    cout << "Por favor, introduzca un valor entre 1 y " << houses.length << "."
         << endl;
    fflush(stdin);
    cin >> selectedOption;
  }

  return iterateHousesList(houses, selectedOption);
}

// Printers

void showCitiesListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Nombre";
  gotoxy(40, y);
  cout << "# Viviendas";
}

void showCity(cityStruct city, int i, int y) {
  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << city.name;
  gotoxy(40, y);
  cout << " Con " << city.houses.length << " Viviendas";
}

void showCitiesWithDestinationsListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Nombre";
  gotoxy(40, y);
  cout << "Destinos";
}

void showCityWithDestinations(cityNode *node, int i, int y) {
  cityEdge *edge;
  int x = 0;

  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << node->city.name;

  edge = node->adjacent;

  if (edge == NULL) {
    gotoxy(40, y);
    cout << "No hay destinos disponibles";
    return;
  }

  while (edge != NULL) {
    gotoxy(40 + x, y);
    cout << edge->destiny->city.name;

    if (edge->next != NULL) cout << ", ";

    x += (edge->destiny->city.name.length() + 2);
    edge = edge->next;
  }
}

void showHousesListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Direccion";
  gotoxy(30, y);
  cout << "Dueño";
  gotoxy(45, y);
  cout << "# de pisos";
  gotoxy(52, y);
  cout << "Habitantes";
}

void showHouse(houseStruct house, int i, int y) {
  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << house.address;
  gotoxy(30, y);
  cout << house.owner;
  gotoxy(45, y);
  cout << house.floorsQuantity;
  gotoxy(52, y);
  cout << house.people.length;
}

void showPeopleListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Nombres";
  gotoxy(25, y);
  cout << "Apellidos";
  gotoxy(50, y);
  cout << "DNI";
  gotoxy(60, y);
  cout << "Salario";
}

void showPerson(personStruct person, int i, int y) {
  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << person.firstName;
  gotoxy(25, y);
  cout << person.lastName;
  gotoxy(50, y);
  cout << person.dni;
  gotoxy(60, y);
  cout << person.salary;
}
