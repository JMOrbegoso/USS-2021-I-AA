#include "structFunctions.h"

using namespace std;

void showAppTitle(concessionaireStruct concessionaire) {
  cout << endl
       << "-----------------------------------------------------------" << endl;
  cout << "\t\t Sistema virtual de " << concessionaire.name << endl;
  cout << endl
       << "-----------------------------------------------------------" << endl;
  cout << "Dirección: " << concessionaire.address << endl;
  cout << "RUC: " << concessionaire.ruc << endl;
  cout << endl
       << "-----------------------------------------------------------" << endl;
}

int requestMenuOption(concessionaireStruct concessionaire) {
  int selectedOption;

  clearScreen();
  showAppTitle(concessionaire);

  cout << endl
       << "Esta aplicación tiene las siguientes opciones:" << endl
       << endl;

  cout << "[1] Registrar nueva marca de automóviles" << endl;
  cout << "[2] Registrar nuevo modelo de automóviles" << endl;
  cout << "[3] Registrar nuevo automóvil" << endl;
  cout << "[4] Listar todas las marcas de automóviles" << endl;
  cout << "[5] Listar todos los modelos de automóviles" << endl;
  cout << "[6] Listar todos los automóviles" << endl;
  cout << "[7] Listar automóviles por modelo" << endl;
  cout << "[8] Buscar un automóvil por licencia" << endl;
  cout << "[0] Cerrar" << endl;

  cout << endl << "Por favor ingrese una de las opciones:" << endl;
  cin >> selectedOption;
  while (!(0 <= selectedOption && selectedOption <= 8)) {
    cout << "La opcion seleccionada fue inválida, por favor seleccione una "
            "opcion válida:"
         << endl;
    cin >> selectedOption;
  }
  return selectedOption;
}

void registerNewBrand(concessionaireStruct &concessionaire) {
  brandStruct newBrand;
  string code, name, country;

  cout << "Va a registrar una nueva marca de automóviles" << endl << endl;

  code = requestText("Ingrese el código de la nueva marca", 1);
  name = requestText("Ingrese el nombre de la nueva marca", 1);
  country = requestText("Ingrese el país de procedencia de la nueva marca", 1);

  newBrand = buildBrand(code, name, country);

  addToCollection(concessionaire.brands, newBrand);

  cout << "La marca de automóviles ha sido registrada correctamente";
}

void registerNewModel(concessionaireStruct &concessionaire) {
  modelStruct newModel;
  brandStruct *brandPointer;
  string code, name, type;

  cout << "Va a registrar un nuevo modelo de automóviles" << endl << endl;

  code = requestText("Ingrese el código del nuevo modelo", 1);
  name = requestText("Ingrese el nombre del nuevo modelo", 1);
  type = requestText("Ingrese el tipo del nuevo modelo", 1);
  brandPointer = requestBrand(concessionaire);

  newModel = buildModel(code, name, type);
  addToCollection(brandPointer->models, newModel);

  cout << "El modelo de automóviles ha sido registrado correctamente";
}

void registerNewCar(concessionaireStruct &concessionaire) {
  carStruct newCar;
  brandStruct *brandPointer;
  modelStruct *modelPointer;
  string code, license, color;
  float cylinderCapacity, performance;

  cout << "Va a registrar un nuevo automóvil" << endl << endl;

  code = requestText("Ingrese el código del nuevo automóvil", 1);
  license = requestText("Ingrese la matricula del nuevo automóvil", 1, 10);
  cylinderCapacity =
      requestFloatNumber("Ingrese el cilindraje del nuevo automóvil (cc)", 1);
  color = requestText("Ingrese el color del nuevo automóvil", 1);
  performance =
      requestFloatNumber("Ingrese el performance del nuevo automóvil (CV)", 1);
  brandPointer = requestBrand(concessionaire);
  modelPointer = requestModel(*brandPointer);

  newCar = buildCar(code, license, cylinderCapacity, color, performance);
  addToCollection(modelPointer->cars, newCar);

  cout << "El automóvil ha sido registrado correctamente";
}

void showBrands(concessionaireStruct concessionaire) {
  clearScreen();
  showAppTitle(concessionaire);

  gotoxy(20, 10);
  cout << "Marcas de automóviles" << endl;

  showBrandsListHeaders(12);

  brandNode *node = concessionaire.brands.firstNode;

  for (int i = 1; node != NULL; i++) {
    showBrand(node->brand, i);
    node = node->next;
  }

  cout << endl << endl;
}

void showModels(concessionaireStruct concessionaire) {
  brandNode *brand_node;
  modelNode *model_node;
  int i = 1;
  clearScreen();
  showAppTitle(concessionaire);

  gotoxy(20, 10);
  cout << "Modelos de automóviles" << endl;

  showModelsListHeaders(12);

  brand_node = concessionaire.brands.firstNode;

  while (brand_node != NULL) {
    model_node = brand_node->brand.models.firstNode;
    while (model_node != NULL) {
      showModel(model_node->model, brand_node->brand.name, i);
      model_node = model_node->next;
      i++;
    }

    brand_node = brand_node->next;
  }

  cout << endl << endl;
}

void showCars(concessionaireStruct concessionaire) {
  brandNode *brand_node;
  modelNode *model_node;
  carNode *car_node;
  int i = 1;

  clearScreen();
  showAppTitle(concessionaire);

  showCarsListHeaders(12);

  brand_node = concessionaire.brands.firstNode;

  while (brand_node != NULL) {
    model_node = brand_node->brand.models.firstNode;
    while (model_node != NULL) {
      car_node = model_node->model.cars.firstNode;
      while (car_node != NULL) {
        showCar(car_node->car, brand_node->brand.name, model_node->model.name,
                i);
        car_node = car_node->next;
        i++;
      }

      model_node = model_node->next;
    }

    brand_node = brand_node->next;
  }

  cout << endl << endl;
}

void showCars(concessionaireStruct concessionaire, modelStruct model,
              string brandName) {
  carNode *car_node;
  int i = 1;

  clearScreen();
  showAppTitle(concessionaire);

  gotoxy(20, 10);
  cout << "Automóviles" << endl;

  showCarsListHeaders(12);

  car_node = model.cars.firstNode;
  while (car_node != NULL) {
    showCar(car_node->car, brandName, model.name, i);
    car_node = car_node->next;
    i++;
  }

  cout << endl << endl;
}

void findCarByLicense(concessionaireStruct concessionaire) {
  brandNode *brand_node;
  modelNode *model_node;
  carNode *car_node;
  string licenseToFind;
  int i = 1;

  licenseToFind = requestText("Ingrese la licencia a buscar:", 1);

  clearScreen();
  showAppTitle(concessionaire);

  gotoxy(20, 10);
  cout << "Automóviles con la licencia: " << licenseToFind << endl;

  brand_node = concessionaire.brands.firstNode;

  while (brand_node != NULL) {
    model_node = brand_node->brand.models.firstNode;
    while (model_node != NULL) {
      car_node = model_node->model.cars.firstNode;
      while (car_node != NULL) {
        showCarsListHeaders(12);
        if (containsText(car_node->car.license, licenseToFind)) {
          showCar(car_node->car, brand_node->brand.name, model_node->model.name,
                  i);
        }

        car_node = car_node->next;
        i++;
      }

      model_node = model_node->next;
    }

    brand_node = brand_node->next;
  }

  cout << endl << endl;
}

void mainMenu(concessionaireStruct &concessionaire) {
  int selectedOption;
  brandStruct brand;
  modelStruct model;

  do {
    selectedOption = requestMenuOption(concessionaire);

    if (selectedOption != 0) {
      switch (selectedOption) {
      case 1:
        registerNewBrand(concessionaire);
        addDelay(2);
        break;

      case 2:
        registerNewModel(concessionaire);
        addDelay(2);
        break;

      case 3:
        registerNewCar(concessionaire);
        addDelay(2);
        break;

      case 4:
        showBrands(concessionaire);
        pauseProcess();
        break;

      case 5:
        showModels(concessionaire);
        pauseProcess();
        break;

      case 6:
        showCars(concessionaire);
        pauseProcess();
        break;

      case 7:
        brand = *requestBrand(concessionaire);
        model = *requestModel(brand);
        showCars(concessionaire, model, brand.name);
        pauseProcess();
        break;

      case 8:
        findCarByLicense(concessionaire);
        pauseProcess();
        break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}
