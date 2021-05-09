#include "helpers.h"
#include "structs.h"
#include <iostream>

using namespace std;

concessionaireStruct buildConcessionaireStruct() {
  concessionaireStruct concessionaire;

  concessionaire.brands.head = NULL;
  concessionaire.brands.length = 0;

  return concessionaire;
}

brandStruct buildBrand(string code, string name, string country) {
  brandStruct brand;

  brand.code = code;
  brand.name = name;
  brand.country = country;

  brand.models.head = NULL;
  brand.models.length = 0;

  return brand;
}

modelStruct buildModel(string code, string name, string type) {
  modelStruct model;

  model.code = code;
  model.name = name;
  model.type = type;

  model.cars.head = NULL;
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

  brandNode *lastNode = brands.head;

  newNode->brand = newBrand;
  newNode->next = NULL;

  if (brands.head == NULL) {
    brands.head = newNode;
    brands.head->previous = NULL;
  } else {
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }

    lastNode->next = newNode;
    newNode->previous = lastNode;
  }

  brands.length++;
}

void addToCollection(modelsList &models, modelStruct newModel) {
  modelNode *newNode = new modelNode();

  modelNode *lastNode = models.head;

  newNode->model = newModel;
  newNode->next = NULL;

  if (models.head == NULL) {
    models.head = newNode;
  } else {
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }

    lastNode->next = newNode;
  }

  models.length++;
}

void addToCollection(carsList &cars, carStruct newCar) {
  carNode *newNode = new carNode();

  carNode *lastNode = cars.head;

  newNode->car = newCar;
  newNode->next = NULL;

  if (cars.head == NULL) {
    cars.head = newNode;
  } else {
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }

    lastNode->next = newNode;
  }

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

brandNode *iterateBrandsList(brandsList brands, int index) {
  brandNode *brandNodePointer;

  if (0 >= index) {
    return NULL;
  }

  if (index > brands.length) {
    return NULL;
  }

  brandNodePointer = brands.head;

  for (int i = 1; brandNodePointer != NULL; i++) {
    if (i == index) {
      return brandNodePointer;
    }
    brandNodePointer = brandNodePointer->next;
  }

  return NULL;
}

modelNode *iterateModelsList(modelsList models, int index) {
  modelNode *modelNodePointer;

  if (0 >= index) {
    return NULL;
  }

  if (index > models.length) {
    return NULL;
  }

  modelNodePointer = models.head;

  for (int i = 1; modelNodePointer != NULL; i++) {
    if (i == index) {
      return modelNodePointer;
    }
    modelNodePointer = modelNodePointer->next;
  }

  return NULL;
}

brandNode *requestBrandWithSelector(brandsList &brands, string message) {
  int selectedOption;
  brandNode *brandNodePointer;

  cout << endl
       << message << ". Escoja entre las " << brands.length
       << " marcas de automóviles siguientes:" << endl
       << endl;

  brandNodePointer = brands.head;

  for (int i = 1; brandNodePointer != NULL; i++) {
    cout << "[" << i << "] - " << brandNodePointer->brand.name << " - "
         << brandNodePointer->brand.models.length
         << " modelos en esta marca de automóviles" << endl;
    brandNodePointer = brandNodePointer->next;
  }

  cout << endl << "Introduzca la opción deseada:" << endl;

  while (!(1 <= selectedOption && selectedOption <= brands.length)) {
    cout << "Por favor, introduzca un valor entre 1 y " << brands.length << "."
         << endl;
    fflush(stdin);
    cin >> selectedOption;
  }

  return iterateBrandsList(brands, selectedOption);
}

modelNode *requestModelWithSelector(modelsList &models, string message) {
  int selectedOption;
  modelNode *modelNodePointer;

  modelNodePointer = models.head;

  cout << endl
       << message << ". Escoja entre los " << models.length
       << " modelos de automóviles siguientes:" << endl
       << endl;

  for (int i = 1; modelNodePointer != NULL; i++) {
    cout << "[" << i << "] - " << modelNodePointer->model.name << " - "
         << modelNodePointer->model.cars.length << " automóviles de este modelo"
         << endl;
    modelNodePointer = modelNodePointer->next;
  }

  cout << endl << "Introduzca la opción deseada:" << endl;

  while (!(1 <= selectedOption && selectedOption <= models.length)) {
    cout << "Por favor, introduzca un valor entre 1 y " << models.length << "."
         << endl;
    fflush(stdin);
    cin >> selectedOption;
  }

  return iterateModelsList(models, selectedOption);
}

void showBrandsListHeaders(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Código";
  gotoxy(20, y);
  cout << "Nombre";
  gotoxy(35, y);
  cout << "País";
  gotoxy(50, y);
  cout << "# de Modelos";
}

void showModelsListHeaders(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Código";
  gotoxy(20, y);
  cout << "Nombre";
  gotoxy(35, y);
  cout << "Tipo";
  gotoxy(50, y);
  cout << "# de automóviles";
  gotoxy(70, y);
  cout << "Marca";
}

void showCarsListHeaders(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Código";
  gotoxy(20, y);
  cout << "Licencia";
  gotoxy(35, y);
  cout << "Cilindraje";
  gotoxy(50, y);
  cout << "Color";
  gotoxy(60, y);
  cout << "Potencia";
  gotoxy(70, y);
  cout << "Modelo";
  gotoxy(80, y);
  cout << "Marca";
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
