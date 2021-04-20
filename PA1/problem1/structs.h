#include <iostream>

using namespace std;

struct carStruct {
  string code;
  string license;
  float cylinderCapacity;
  string color;
  float perfomance;
};

struct carNode {
  carStruct car;
  carNode *next;
};

struct carsList {
  carNode *firstNode;
  int length;
};

struct modelStruct {
  string code;
  string name;
  string type;
  carsList cars;
};

struct modelNode {
  modelStruct model;
  modelNode *next;
};

struct modelsList {
  modelNode *firstNode;
  int length;
};

struct brandStruct {
  string code;
  string name;
  string country;
  modelsList models;
};

struct brandNode {
  brandStruct brand;
  brandNode *previous;
  brandNode *next;
};

struct brandsList {
  brandNode *firstNode;
  int length;
};

struct concessionaireStruct {
  string name;
  brandsList brands;
  string address;
  string ruc;
};
