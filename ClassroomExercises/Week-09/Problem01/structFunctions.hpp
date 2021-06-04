#include "helpers.hpp"
#include "structs.hpp"

using namespace std;

void showPeopleListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Apellidos";
  gotoxy(25, y);
  cout << "Nombres";
  gotoxy(45, y);
  cout << "Edad";
}

void showPerson(personStruct person, int i, int y) {
  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << person.lastName;
  gotoxy(25, y);
  cout << person.firstName;
  gotoxy(45, y);
  cout << person.age;
}
