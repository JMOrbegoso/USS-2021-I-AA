#include <iostream>

using namespace std;

// Person
struct personStruct {
  string dni;
  string firstName;
  string lastName;
  float salary;
};

struct personNode {
  personStruct person;
  personNode *prev;
  personNode *next;
};

struct peopleList {
  personNode *head;
  int length;
};

// House
struct houseStruct {
  string address;
  string owner;
  unsigned short floorsQuantity;
  peopleList people;
};

struct houseNode {
  houseStruct house;
  houseNode *prev;
  houseNode *next;
};

struct housesList {
  houseNode *head;
  int length;
};

// City
struct cityStruct {
  string name;
  housesList houses;
};

struct cityNode {
  cityStruct city;
  struct cityNode *next;
  struct cityEdge *adjacent;
};

struct cityEdge {
  struct cityNode *destiny;
  struct cityEdge *next;
};

struct citiesGraph {
  cityNode *node;
  cityEdge *edge;
};
