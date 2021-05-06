#include "structFunctions.h"

using namespace std;

void showAppTitle(departmentStruct department) {
  cout << endl
       << "-----------------------------------------------------------" << endl;
  cout << "\t\t Sistema Virtual del Departamento de " << department.name
       << endl;
  cout << "-----------------------------------------------------------" << endl;
  cout << "\t\t\t" << department.motto << endl;
  cout << "\t\t\tCreado en el año: " << department.creationYear << endl;
  cout << "-----------------------------------------------------------" << endl;
}

int requestMenuOption(departmentStruct department) {
  int selectedOption;

  clearScreen();
  showAppTitle(department);

  cout << endl
       << "Esta aplicación tiene las siguientes opciones:" << endl
       << endl;

  cout << "[1] Agregar provincia" << endl;
  cout << "[2] Agregar distrito" << endl;
  cout << "[3] Agregar persona" << endl;

  cout << "[4] Listar personas de un distrito" << endl;
  cout << "[5] Buscar persona" << endl;
  cout << "[6] Mostrar provincias con sus distritos y sus personas" << endl;

  cout << "[0] Cerrar" << endl;

  cout << endl << "Por favor ingrese una de las opciones:" << endl;
  cin >> selectedOption;
  while (!(0 <= selectedOption && selectedOption <= 6)) {
    cout << "La opcion seleccionada fue inválida, por favor seleccione una "
            "opcion válida:"
         << endl;
    cin >> selectedOption;
  }
  return selectedOption;
}

void registerNewProvince(departmentStruct &department) {
  string name;
  unsigned long population;
  float area;
  unsigned short creationYear;

  provinceStruct newProvince;

  clearScreen();
  showAppTitle(department);

  gotoxy(40, 10);
  cout << "Registrar nueva provincia:" << endl;

  name = requestText("Ingrese el nombre de la nueva provincia", 2);
  population = requestIntegerNumber(
      "Ingrese la cantidad de habitantes de la nueva provincia",
      "Por favor ingrese un numero de habitantes mayor a 0", 0);
  area = requestFloatNumber("Ingrese el área total de la nueva provincia",
                            "Por favor ingrese un area mayor a 0 Km2", 0);
  creationYear =
      requestIntegerNumber("Ingrese el año de creacion de la nueva provincia",
                           "Por favor ingrese un año mayor a 1800", 1800);

  newProvince = buildProvince(name, population, area, creationYear);

  addToCollection(department.provinces, newProvince);

  cout << "La provincia fue añadida de forma exitosa" << endl;
}

void registerNewDistrict(departmentStruct &department) {
  string name;
  unsigned long population;
  float area;
  unsigned short creationYear;
  provinceStruct province;

  districtStruct newDistrict;

  clearScreen();
  showAppTitle(department);

  gotoxy(40, 10);
  cout << "Registrar nuevo distrito:" << endl;

  name = requestText("Ingrese el nombre del nuevo distrito", 2);
  population = requestIntegerNumber(
      "Ingrese la cantidad de habitantes del nuevo distrito",
      "Por favor ingrese un numero de habitantes mayor a 0", 0);
  area = requestFloatNumber("Ingrese el área total del nuevo distrito",
                            "Por favor ingrese un area mayor a 0 Km2", 0);
  creationYear =
      requestIntegerNumber("Ingrese el año de creacion del nuevo distrito",
                           "Por favor ingrese un año mayor a 1800", 1800);

  newDistrict = buildDistrict(name, population, area, creationYear);

  province = *requestProvinceWithSelector(
      department, "Ingrese la provincia a la que este distrito pertenece:");

  addToCollection(province.districts, newDistrict);

  cout << "El distrito fue añadido de forma exitosa" << endl;
}

void registerNewPerson(departmentStruct &department) {
  string firstName;
  string lastName;
  char genre;
  unsigned short age;
  provinceStruct province;
  districtStruct district;

  personStruct newPerson;

  clearScreen();
  showAppTitle(department);

  gotoxy(40, 10);
  cout << "Registrar nueva persona:" << endl;

  firstName = requestText("Ingrese los nombres de la nueva persona", 2);
  lastName = requestText("Ingrese los apellidos de la nueva persona", 2);
  genre = requestGenre("Ingrese el genero de la nueva persona");
  age = requestIntegerNumber(
      "Ingrese la edad de la nueva persona",
      "Por favor ingrese una edad mayor a 0 y menor a 110", 0, 110);

  newPerson = buildPerson(firstName, lastName, genre, age);

  province = *requestProvinceWithSelector(
      department, "Ingrese la provincia de la persona:");

  while (!(province.districts.head != NULL)) {
    cout << endl
         << "La provincia elegida no tiene distritos, por favor elija una "
            "provincia con distritos."
         << endl;

    province = *requestProvinceWithSelector(
        department, "Ingrese la provincia de la persona:");
  }

  district = *requestDistrictWithSelector(province,
                                          "Ingrese el distrito de la persona:");

  addToCollection(district.persons, newPerson);

  cout << "La persona fue añadida de forma exitosa" << endl;
}

void showPersonsByDistrict(departmentStruct department) {
  provinceStruct province;
  districtStruct district;

  province = *requestProvinceWithSelector(
      department, "Ingrese la provincia de las personas que desea listar:");
  district = *requestDistrictWithSelector(
      province, "Ingrese el distrito de las personas que desea listar:");

  clearScreen();
  showAppTitle(department);

  gotoxy(40, 10);
  cout << "Personas del distrito de " << district.name << endl;

  personNode *person_node = district.persons.head;

  showPersonsListHeader(12);

  int i = 1;
  while (person_node != NULL) {
    showPerson(person_node->person, i, i + 13);
    person_node = person_node->next;
    i++;
  }

  cout << endl << endl;
}

void findPersonByDistrict(departmentStruct department) {
  provinceStruct province;
  districtStruct district;
  string lastNameToFind;
  bool personFound = false;
  province = *requestProvinceWithSelector(
      department, "Ingrese la provincia de las personas que desea listar:");
  district = *requestDistrictWithSelector(
      province, "Ingrese el distrito de las personas que desea listar:");
  lastNameToFind = requestText("Ingrese el apellido a buscar", 2);

  clearScreen();
  showAppTitle(department);

  gotoxy(40, 10);
  cout << "Personas del distrito de " << district.name
       << " con un apellido similar a " << lastNameToFind << ":" << endl;

  personNode *person_node = district.persons.head;

  showPersonsListHeader(12);

  int i = 1;
  while (person_node != NULL) {
    if (containsText(person_node->person.lastName, lastNameToFind)) {
      personFound = true;
      showPerson(person_node->person, i, i + 13);
      i++;
    }
    person_node = person_node->next;
    i++;
  }

  if (!personFound)
    cout << endl << endl << "No se encontro ninguna persona con ese apellido";

  cout << endl << endl;
}

void showAllPersonsData(departmentStruct department) {
  provinceNode *province_node;
  districtNode *district_node;
  personNode *person_node;

  clearScreen();
  showAppTitle(department);

  gotoxy(40, 10);
  cout << "Personas de todo el departamento de " << department.name << endl;

  province_node = department.provinces.head;

  showPersonsListWithUbicationDataHeader(12);

  int i = 1;
  while (province_node != NULL) {
    district_node = province_node->province.districts.head;
    while (district_node != NULL) {
      person_node = district_node->district.persons.head;
      while (person_node != NULL) {
        showPersonWithUbicationData(person_node->person,
                                    province_node->province,
                                    district_node->district, i, i + 12);
        person_node = person_node->next;
        i++;
      }
      district_node = district_node->next;
    }
    province_node = province_node->next;
  }

  cout << endl << endl;
}

void mainMenu(departmentStruct &department) {
  int selectedOption;

  do {
    selectedOption = requestMenuOption(department);

    if (selectedOption != 0) {
      switch (selectedOption) {
      case 1:
        registerNewProvince(department);
        addDelay(2);
        break;

      case 2:
        registerNewDistrict(department);
        addDelay(2);
        break;

      case 3:
        registerNewPerson(department);
        addDelay(2);
        break;

      case 4:
        showPersonsByDistrict(department);
        pauseProcess();
        break;

      case 5:
        findPersonByDistrict(department);
        pauseProcess();
        break;

      case 6:
        showAllPersonsData(department);
        pauseProcess();
        break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}
