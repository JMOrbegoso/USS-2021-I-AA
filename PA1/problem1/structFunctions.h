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

modelStruct buildModel(string code, string name, string type) {
  modelStruct model;
  model.code = code;
  model.name = name;
  model.type = type;
  model.cars.firstNode = NULL;
  model.cars.length = 0;
  return model;
}

carStruct buildCar(string code, string license, float cylinderCapacity,
                   string color, float performance) {
  carStruct car;
  car.code = code;
  car.license = license;
  car.cylinderCapacity = cylinderCapacity;
  car.color = color;
  car.performance = performance;
  return car;
}

void addToCollection(brandsList &brands, brandStruct newBrand) {
  brandNode *newNode = new brandNode();

  brandNode *lastNode = brands.firstNode;

  newNode->brand = newBrand;
  newNode->next = NULL;

  if (brands.firstNode == NULL) {
    brands.firstNode = newNode;
    brands.firstNode->previous = NULL;
    brands.length = 1;
    return;
  }

  while (lastNode->next != NULL) {
    lastNode = lastNode->next;
  }

  lastNode->next = newNode;
  newNode->previous = lastNode;

  brands.length++;
}

void addToCollection(modelsList &models, modelStruct newModel) {
  modelNode *newNode = new modelNode();

  modelNode *lastNode = models.firstNode;

  newNode->model = newModel;
  newNode->next = NULL;

  if (models.firstNode == NULL) {
    models.firstNode = newNode;
    models.length = 1;
    return;
  }

  while (lastNode->next != NULL) {
    lastNode = lastNode->next;
  }

  lastNode->next = newNode;

  models.length++;
}

void addToCollection(carsList &cars, carStruct newCar) {
  carNode *newNode = new carNode();

  carNode *lastNode = cars.firstNode;

  newNode->car = newCar;
  newNode->next = NULL;

  if (cars.firstNode == NULL) {
    cars.firstNode = newNode;
    cars.length = 1;
    return;
  }

  while (lastNode->next != NULL) {
    lastNode = lastNode->next;
  }

  lastNode->next = newNode;

  cars.length++;
}

void dataInitialization(concessionaireStruct &concessionaire) {
  brandStruct toyota;
  modelStruct corolla;
  carStruct toy_cor_1;

  concessionaire.name = "Las Condes";
  concessionaire.address = "Las Condes #124";
  concessionaire.ruc = "12345678910";

  toy_cor_1 = buildCar("toy-cor-1", "CD-3720", 2000, "azul", 120);
  corolla = buildModel("cor-1", "Corolla", "auto");
  toyota = buildBrand("toy-1", "Toyota", "Japón");

  addToCollection(corolla.cars, toy_cor_1);
  addToCollection(toyota.models, corolla);
  addToCollection(concessionaire.brands, toyota);
}

brandStruct *requestBrand(concessionaireStruct concessionaire) {
  int selectedOption;
  brandStruct *validOptions[100];

  cout << endl << "Escoja una marca de automóviles:" << endl << endl;

  brandNode *node = concessionaire.brands.firstNode;

  for (int i = 1; node != NULL; i++) {
    cout << "[" << i << "] - " << node->brand.name << endl;
    validOptions[i] = &node->brand;
    node = node->next;
  }

  cout << endl << "Introduzca la opción deseada:" << endl;

  do {
    cin >> selectedOption;
  } while (
      !(0 < selectedOption && selectedOption <= concessionaire.brands.length));

  return validOptions[selectedOption];
}

modelStruct *requestModel(brandStruct brand) {
  int selectedOption;
  modelStruct *validOptions[100];

  cout << endl
       << "Escoja un modelo automóviles de la marca " << brand.name << ":"
       << endl
       << endl;

  modelNode *node = brand.models.firstNode;

  for (int i = 1; node != NULL; i++) {
    cout << "[" << i << "] - " << node->model.name << endl;
    validOptions[i] = &node->model;
    node = node->next;
  }

  cout << endl << "Introduzca la opción deseada:" << endl;

  do {
    cin >> selectedOption;
  } while (!(0 < selectedOption && selectedOption <= brand.models.length));

  return validOptions[selectedOption];
}

void showBrand(brandStruct brand, int i) {
  gotoxy(0, 13 + i);
  cout << i;
  gotoxy(5, 13 + i);
  cout << brand.code;
  gotoxy(20, 13 + i);
  cout << brand.name;
  gotoxy(35, 13 + i);
  cout << brand.country;
  gotoxy(50, 13 + i);
  cout << brand.models.length;
}

void showModel(modelStruct model, string brandName, int i) {
  gotoxy(0, 13 + i);
  cout << i;
  gotoxy(5, 13 + i);
  cout << model.code;
  gotoxy(20, 13 + i);
  cout << model.name;
  gotoxy(35, 13 + i);
  cout << model.type;
  gotoxy(50, 13 + i);
  cout << model.cars.length;
  gotoxy(70, 13 + i);
  cout << brandName;
}

void showCar(carStruct car, string brandName, string modelName, int i) {
  gotoxy(0, 13 + i);
  cout << i;
  gotoxy(5, 13 + i);
  cout << car.code;
  gotoxy(20, 13 + i);
  cout << car.license;
  gotoxy(35, 13 + i);
  cout << car.cylinderCapacity;
  gotoxy(50, 13 + i);
  cout << car.color;
  gotoxy(60, 13 + i);
  cout << car.performance;
  gotoxy(70, 13 + i);
  cout << modelName;
  gotoxy(80, 13 + i);
  cout << brandName;
}
