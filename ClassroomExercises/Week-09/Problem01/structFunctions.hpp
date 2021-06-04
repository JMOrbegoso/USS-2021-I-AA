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

personNode *createPersonNode(personStruct person) {
  personNode *newPersonNode = new (struct personNode);
  newPersonNode->person = person;
  newPersonNode->left = NULL;
  newPersonNode->right = NULL;
  return newPersonNode;
}

void insertPerson(peopleThree &people, personStruct person) {
  if (people == NULL) {
    people = createPersonNode(person);
  } else if (person.age < people->person.age) {
    insertPerson(people->left, person);
  } else if (person.age > people->person.age) {
    insertPerson(people->right, person);
  } else {
  }
}

void showPerson(personStruct person) {
  cout << endl;
  cout << "Apellidos: " << person.lastName << endl;
  cout << "Nombres: " << person.firstName << endl;
  cout << "Edad: " << person.age << endl;
  cout << endl;
}