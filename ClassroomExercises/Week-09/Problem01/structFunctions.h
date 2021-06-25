#include "helpers.h"
#include "structs.h"

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

peopleThree joinThree(peopleThree leftPeopleThree,
                      peopleThree rightPeopleThree) {
  if (leftPeopleThree == NULL) return rightPeopleThree;

  if (rightPeopleThree == NULL) return leftPeopleThree;

  peopleThree joinedThrees =
      joinThree(leftPeopleThree->right, rightPeopleThree->left);

  leftPeopleThree->right = joinedThrees;
  rightPeopleThree->left = leftPeopleThree;

  return rightPeopleThree;
}

void deletePerson(peopleThree people, string lastNameToFind) {
  if (people == NULL) return;

  if (people->person.lastName > lastNameToFind)
    deletePerson(people->left, lastNameToFind);
  else if (people->person.lastName < lastNameToFind)
    deletePerson(people->right, lastNameToFind);
  else {
    peopleThree aux = people;
    people = joinThree(people->left, people->right);
    delete aux;
  }
}

void showPerson(personStruct person) {
  cout << endl;
  cout << "Apellidos: " << person.lastName << endl;
  cout << "Nombres: " << person.firstName << endl;
  cout << "Edad: " << person.age << endl;
  cout << endl;
}
