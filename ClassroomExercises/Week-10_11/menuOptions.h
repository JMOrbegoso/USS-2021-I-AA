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
  cout << endl;
  cout << "Not implemented";
  cout << endl;
}

void registerPerson(citiesGraph &cities) {
  cout << endl;
  cout << "Not implemented";
  cout << endl;
}

void showCities(citiesGraph cities) {
  int i;
  cityNode *cityNodePointer;

  clearScreen();
  showAppTitle();

  gotoxy(20, 8);
  cout << "Lista de todas las ciudades:" << endl;

  cityNodePointer = cities.node;

  for (int i = 1; cityNodePointer != NULL; i++) {
    cout << "[" << i << "] - " << cityNodePointer->city.name << " - Con "
         << cityNodePointer->city.houses.length << " viviendas." << endl;
    cityNodePointer = cityNodePointer->next;
  }

  cout << endl << endl;
}

void showCitiesWithDestinations(citiesGraph cities) {
  cityNode *auxCityNode;
  cityEdge *tempCityEdge;
  int x = 0;
  int y = 0;

  clearScreen();
  showAppTitle();

  gotoxy(20, 8);
  cout << "Lista de todas las ciudades con sus destinos:" << endl;

  gotoxy(10, 10);
  cout << "Ciudad Origen";
  gotoxy(40, 10);
  cout << "Ciudad Destino";

  auxCityNode = cities.node;

  while (auxCityNode != NULL) {
    gotoxy(10, 12 + y);
    cout << auxCityNode->city.name;

    tempCityEdge = auxCityNode->adjacent;

    x = 0;
    while (tempCityEdge != NULL) {
      gotoxy(40 + x, 12 + y);
      cout << tempCityEdge->destiny->city.name;
      x += (tempCityEdge->destiny->city.name.length() + 2);
      tempCityEdge = tempCityEdge->next;
    }

    auxCityNode = auxCityNode->next;
    y++;
  }

  cout << endl << endl;
}

void showHouses(citiesGraph cities) {
  cout << endl;
  cout << "Not implemented";
  cout << endl;
}

void showPeople(citiesGraph cities) {
  cout << endl;
  cout << "Not implemented";
  cout << endl;
}
