#include "helpers.hpp"
#include "structs.hpp"

using namespace std;

personStruct buildPerson(string lastName, string firstName,
                         unsigned short age) {
  personStruct person;

  person.lastName = lastName;
  person.firstName = firstName;
  person.age = age;

  return person;
}

void insertPerson(peopleThree &people, personStruct person) {
  if (people == NULL) {
    people->person = person;
    people->left = NULL;
    people->right = NULL;
  } else if (person.age < people->person.age) {
    insertPerson(people->left, person);
  } else if (person.age > people->person.age) {
    insertPerson(people->right, person);
  } else {
  }
}

void showPerson(personStruct person) {
  cout << "Apellidos: " << person.lastName << endl;
  cout << "Nombres: " << person.firstName << endl;
  cout << "Edad: " << person.age << endl;
}
