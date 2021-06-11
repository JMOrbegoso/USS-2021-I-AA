#include "helpers.hpp"
#include "structs.hpp"

using namespace std;

int getHeight(peopleThree people) {
  int rightHeight = 0, leftHeight = 0;
  if (people == NULL) {
    return -1;
  } else {
    leftHeight = getHeight(people->left);
    rightHeight = getHeight(people->right);
    if (leftHeight > rightHeight)
      return leftHeight + 1;
    else
      return rightHeight + 1;
  }
}

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
