#include "helpers.h"
#include "structs.h"
#include <iostream>

using namespace std;

void collectionsInitialization(departmentStruct &department) {
  department.provinces.head = NULL;
  department.provinces.length = 0;
}

provinceStruct buildProvince(string name, unsigned long population, float area,
                             unsigned short creationYear) {
  provinceStruct province;
  province.name = name;
  province.population = population;
  province.area = area;
  province.creationYear = creationYear;

  province.districts.head = NULL;
  province.districts.length = 0;

  return province;
}

districtStruct buildDistrict(string name, unsigned long population, float area,
                             unsigned short creationYear) {
  districtStruct district;
  district.name = name;
  district.population = population;
  district.area = area;
  district.creationYear = creationYear;

  district.persons.head = NULL;
  district.persons.length = 0;

  return district;
}

personStruct buildPerson(string firstName, string lastName, char genre,
                         unsigned short age) {
  personStruct person;
  person.firstName = firstName;
  person.lastName = lastName;
  person.genre = genre;
  person.age = age;

  return person;
}

void addToCollection(provincesList &provinces, provinceStruct newProvince) {
  provinceNode *newNode = new provinceNode();

  provinceNode *lastNode = provinces.head;

  newNode->province = newProvince;
  newNode->next = NULL;

  if (provinces.head == NULL) {
    provinces.head = newNode;
  } else {
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }

    lastNode->next = newNode;
  }

  provinces.length++;
}

void addToCollection(districtsList &districts, districtStruct newDistrict) {
  districtNode *newNode = new districtNode();

  districtNode *lastNode = districts.head;

  newNode->district = newDistrict;
  newNode->next = NULL;

  if (districts.head == NULL) {
    districts.head = newNode;
  } else {
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }

    lastNode->next = newNode;
  }

  districts.length++;
}

void addToCollection(personsList &persons, personStruct newPerson) {
  personNode *newNode = new personNode();

  personNode *lastNode = persons.head;

  newNode->person = newPerson;
  newNode->next = NULL;

  if (persons.head == NULL) {
    persons.head = newNode;
    persons.head->previous = NULL;
  } else {
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }

    lastNode->next = newNode;
    newNode->previous = lastNode;
  }

  persons.length++;
}

void dataInitialization(departmentStruct &department) {
  provinceStruct chiclayo;
  provinceStruct ferrenafe;
  provinceStruct lambayeque;

  districtStruct eten;
  districtStruct pitipo;
  districtStruct olmos;

  personStruct person_1;
  personStruct person_2;
  personStruct person_3;

  department.name = "Lambayeque";
  department.motto = "Cuna de la cultura Moche";
  department.creationYear = 1872;

  chiclayo = buildProvince("Chiclayo", 799675, 3288.07, 1835);
  ferrenafe = buildProvince("Ferreñafe", 97415, 1578.6, 1951);
  lambayeque = buildProvince("Lambayeque", 300170, 9364.63, 1872);

  eten = buildDistrict("Eten", 15200, 84.78, 1835);
  pitipo = buildDistrict("Pitipo", 20080, 558.18, 1851);
  olmos = buildDistrict("Olmos", 50251, 5335.25, 1835);

  person_1 = buildPerson("Julio", "Gomez", 'm', 47);
  person_2 = buildPerson("Rosa", "Jimenez", 'f', 32);
  person_3 = buildPerson("Ramon", "Martinez", 'm', 28);

  addToCollection(eten.persons, person_1);
  addToCollection(pitipo.persons, person_2);
  addToCollection(olmos.persons, person_3);

  addToCollection(chiclayo.districts, eten);
  addToCollection(ferrenafe.districts, pitipo);
  addToCollection(lambayeque.districts, olmos);

  addToCollection(department.provinces, chiclayo);
  addToCollection(department.provinces, ferrenafe);
  addToCollection(department.provinces, lambayeque);
}

void showProvincesListHeaders(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Name";
  gotoxy(25, y);
  cout << "Poblacion (hab)";
  gotoxy(50, y);
  cout << "Area (km2)";
  gotoxy(60, y);
  cout << "Año de fundacion";
}

void showProvince(provinceStruct province, int i, int y) {
  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << province.name;
  gotoxy(25, y);
  cout << province.population;
  gotoxy(50, y);
  cout << province.area;
  gotoxy(60, y);
  cout << province.creationYear;
}

void showDistrictsListHeaders(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Name";
  gotoxy(25, y);
  cout << "Poblacion (hab)";
  gotoxy(50, y);
  cout << "Area (km2)";
  gotoxy(60, y);
  cout << "Año de fundacion";
}

void showDistrict(districtStruct district, int i, int y) {
  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << district.name;
  gotoxy(25, y);
  cout << district.population;
  gotoxy(50, y);
  cout << district.area;
  gotoxy(60, y);
  cout << district.creationYear;
}

void showPersonsListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Nombres";
  gotoxy(20, y);
  cout << "Apellidos";
  gotoxy(40, y);
  cout << "Genero";
  gotoxy(55, y);
  cout << "Edad";
}

void showPerson(personStruct person, int i, int y) {
  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << person.firstName;
  gotoxy(20, y);
  cout << person.lastName;
  gotoxy(40, y);
  cout << getGenre(person.genre);
  gotoxy(55, y);
  cout << person.age;
}
