#include <iostream>

using namespace std;

struct personStruct {
  string firstName;
  string lastName;
  char genre;
  unsigned short age;
};

struct personNode {
  personStruct person;
  personNode *next;
  personNode *previous;
};

struct personsList {
  personNode *head;
  int length;
};

struct districtStruct {
  string name;
  unsigned short population;
  float area;
  unsigned short creationYear;
  personsList persons;
};

struct districtNode {
  districtStruct district;
  districtNode *next;
};

struct districtsList {
  districtNode *head;
  int length;
};

struct provinceStruct {
  string name;
  unsigned short population;
  float area;
  unsigned short creationYear;
  districtsList districts;
};

struct provinceNode {
  provinceStruct province;
  provinceNode *next;
};

struct provincesList {
  provinceNode *head;
  int length;
};

struct departmentStruct {
  string name;
  string motto;
  string creationYear;
  provincesList provinces;
};
