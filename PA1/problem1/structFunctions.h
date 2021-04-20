#include "helpers.h"
#include "structs.h"
#include <iostream>

using namespace std;

void collectionsInitialization(concessionaireStruct &concessionaire) {
  concessionaire.brands.firstNode = NULL;
  concessionaire.brands.length = 0;
}

brandStruct buildBrand(string code, string name, string country) {

  brandStruct brand;
  brand.code = code;
  brand.name = name;
  brand.country = country;
  brand.models.firstNode = NULL;
  brand.models.length = 0;
  return brand;
}

void addToCollection(concessionaireStruct &concessionaire,
                     brandStruct newBrand) {
  brandNode *newNode = new brandNode();

  brandNode *lastNode = concessionaire.brands.firstNode;

  newNode->brand = newBrand;
  newNode->next = NULL;

  if (concessionaire.brands.firstNode == NULL) {
    concessionaire.brands.firstNode = newNode;
    concessionaire.brands.firstNode->previous = NULL;
    return;
  }

  while (lastNode->next != NULL) {
    lastNode = lastNode->next;
  }

  lastNode->next = newNode;
  newNode->previous = lastNode;

  concessionaire.brands.length++;
}

void dataInitialization(concessionaireStruct &concessionaire) {
  brandStruct toyota;

  concessionaire.name = "Las Condes";
  concessionaire.address = "Las Condes #124";
  concessionaire.ruc = "12345678910";

  toyota = buildBrand("toy-1", "Toyota", "Japón");

  addToCollection(concessionaire, toyota);
}

void showBrand(brandStruct brand, int i) {
  gotoxy(0, 9 + i);
  cout << i;
  gotoxy(5, 9 + i);
  cout << brand.code;
  gotoxy(20, 9 + i);
  cout << brand.name;
  gotoxy(35, 9 + i);
  cout << brand.country;
  gotoxy(50, 9 + i);
  cout << brand.models.length;
}
