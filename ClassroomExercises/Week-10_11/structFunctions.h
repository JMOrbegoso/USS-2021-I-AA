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

cityStruct buildCity(string name, unsigned long inhabitantsQuantity) {
  cityStruct city;

  city.name = name;

  city.houses.head = NULL;
  city.houses.length = 0;

  return city;
}

// Init

void collectionsInitialization(citiesGraph& cities) {
  cities.node = NULL;
  cities.edge = NULL;
}

void dataInitialization(citiesGraph& cities) {}
