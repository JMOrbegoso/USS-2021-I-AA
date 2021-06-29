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

// Init

void collectionsInitialization(citiesGraph &cities) {
  cities.node = NULL;
  cities.edge = NULL;
  cities.length = 0;
}

void dataInitialization(citiesGraph &cities) {
  cityStruct ica, lima, trujillo, chiclayo, piura, tumbes;

  ica = buildCity("Ica");
  lima = buildCity("Lima");
  trujillo = buildCity("Trujillo");
  chiclayo = buildCity("Chiclayo");
  piura = buildCity("Piura");
  tumbes = buildCity("Tumbes");

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