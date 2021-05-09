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
  provinceStruct chiclayo, ferrenafe, lambayeque;

  districtStruct eten, pitipo, olmos;

  personStruct person_1, person_2, person_3, person_4, person_5, person_6;

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
  person_2 = buildPerson("Maria", "Izquierdo", 'f', 15);
  person_3 = buildPerson("Luis", "Lopez", 'm', 27);
  person_4 = buildPerson("Tulio", "Rojas", 'm', 11);
  person_5 = buildPerson("Rosa", "Jimenez", 'f', 72);
  person_6 = buildPerson("Alex", "Rodrigez", 'm', 28);

  addToCollection(eten.persons, person_1);
  addToCollection(eten.persons, person_2);
  addToCollection(pitipo.persons, person_3);
  addToCollection(pitipo.persons, person_4);
  addToCollection(olmos.persons, person_5);
  addToCollection(olmos.persons, person_6);

  addToCollection(chiclayo.districts, eten);
  addToCollection(ferrenafe.districts, pitipo);
  addToCollection(lambayeque.districts, olmos);

  addToCollection(department.provinces, chiclayo);
  addToCollection(department.provinces, ferrenafe);
  addToCollection(department.provinces, lambayeque);
}

provinceNode *iterateProvincesList(provincesList provinces, int index) {
  provinceNode *provinceNodePointer;

  if (0 >= index) {
    return NULL;
  }

  if (index > provinces.length) {
    return NULL;
  }

  provinceNodePointer = provinces.head;

  for (int i = 1; provinceNodePointer != NULL; i++) {
    if (i == index) {
      return provinceNodePointer;
    }
    provinceNodePointer = provinceNodePointer->next;
  }

  return NULL;
}

districtNode *iterateDistrictsList(districtsList districts, int index) {
  districtNode *districtNodePointer;

  if (0 >= index) {
    return NULL;
  }

  if (index > districts.length) {
    return NULL;
  }

  districtNodePointer = districts.head;

  for (int i = 1; districtNodePointer != NULL; i++) {
    if (i == index) {
      return districtNodePointer;
    }
    districtNodePointer = districtNodePointer->next;
  }

  return NULL;
}

provinceNode *requestProvinceWithSelector(provincesList &provinces,
                                          string message) {
  int selectedOption, provincesQuantity;
  provinceNode *node;

  provincesQuantity = provinces.length;
  node = provinces.head;

  cout << endl
       << message << ". Escoja entre las " << provincesQuantity
       << " provincias siguientes:" << endl
       << endl;

  provincesQuantity = 0;
  while (node != NULL) {
    provincesQuantity++;
    cout << "[" << provincesQuantity << "] - " << node->province.name << " - "
         << node->province.districts.length << " distritos en esta provincia"
         << endl;
    node = node->next;
  }

  cout << endl << "Introduzca la opción deseada:" << endl;

  while (!(1 <= selectedOption && selectedOption <= provincesQuantity)) {
    cout << "Por favor, introduzca un valor entre 1 y " << provincesQuantity
         << "." << endl;
    fflush(stdin);
    cin >> selectedOption;
  }

  return iterateProvincesList(provinces, selectedOption);
}

districtNode *requestDistrictWithSelector(districtsList &districts,
                                          string message) {
  int selectedOption, districtsQuantity;
  districtNode *node;

  districtsQuantity = districts.length;
  node = districts.head;

  cout << endl
       << message << ". Escoja entre los " << districtsQuantity
       << " distritos siguientes:" << endl
       << endl;

  districtsQuantity = 0;
  while (node != NULL) {
    districtsQuantity++;
    cout << "[" << districtsQuantity << "] - " << node->district.name << " - "
         << node->district.persons.length << " personas en este distrito"
         << endl;
    node = node->next;
  }

  cout << endl << "Introduzca la opción deseada:" << endl;

  while (!(1 <= selectedOption && selectedOption <= districtsQuantity)) {
    cout << "Por favor, introduzca un valor entre 1 y " << districtsQuantity
         << "." << endl;
    fflush(stdin);
    cin >> selectedOption;
  }

  return iterateDistrictsList(districts, selectedOption);
}

void showProvincesListHeaders(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Name";
  gotoxy(25, y);
  cout << "Poblacion";
  gotoxy(40, y);
  cout << "Area (km2)";
  gotoxy(55, y);
  cout << "Fundado (Año)";
  gotoxy(75, y);
  cout << "Distritos";
}

void showProvince(provinceStruct province, int i, int y) {
  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << province.name;
  gotoxy(25, y);
  cout << province.population;
  gotoxy(40, y);
  cout << province.area;
  gotoxy(55, y);
  cout << province.creationYear;
  gotoxy(75, y);
  cout << province.districts.length;
}

void showDistrictsListHeaders(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Name";
  gotoxy(25, y);
  cout << "Poblacion";
  gotoxy(40, y);
  cout << "Area (km2)";
  gotoxy(55, y);
  cout << "Fundado (Año)";
  gotoxy(75, y);
  cout << "Personas";
}

void showDistrict(districtStruct district, int i, int y) {
  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << district.name;
  gotoxy(25, y);
  cout << district.population;
  gotoxy(40, y);
  cout << district.area;
  gotoxy(55, y);
  cout << district.creationYear;
  gotoxy(75, y);
  cout << district.persons.length;
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

void showPersonsListWithUbicationDataHeader(int y) {
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
  gotoxy(65, y);
  cout << "Provincia";
  gotoxy(80, y);
  cout << "Distrito";
}

void showPersonWithUbicationData(personStruct person, provinceStruct province,
                                 districtStruct district, int i, int y) {
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
  gotoxy(65, y);
  cout << province.name;
  gotoxy(80, y);
  cout << district.name;
}
