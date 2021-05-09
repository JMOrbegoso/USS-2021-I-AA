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
  brandNode *brandNodePointer;
  string code, name, type;

  cout << "Va a registrar un nuevo modelo de automóviles" << endl << endl;

  code = requestText("Ingrese el código del nuevo modelo", 1);
  name = requestText("Ingrese el nombre del nuevo modelo", 1);
  type = requestText("Ingrese el tipo del nuevo modelo", 1);
  brandNodePointer = requestBrandWithSelector(
      concessionaire.brands,
      "Ingrese la marca del nuevo modelo de automóviles:");

  newModel = buildModel(code, name, type);
  addToCollection(brandNodePointer->brand.models, newModel);

  cout << "El modelo de automóviles ha sido registrado correctamente";
}

void registerNewCar(concessionaireStruct &concessionaire) {
  carStruct newCar;
  brandNode *brandNodePointer;
  modelNode *modelNodePointer;
  string code, license, color;
  float cylinderCapacity, performance;

  cout << "Va a registrar un nuevo automóvil" << endl << endl;

  code = requestText("Ingrese el código del nuevo automóvil", 1);
  license = requestText("Ingrese la matricula del nuevo automóvil", 1, 10);
  cylinderCapacity =
      requestFloatNumber("Ingrese el cilindraje del nuevo automóvil (cc)",
                         "Por favor ingrese un cilindraje mayor de 1 cc", 1);
  color = requestText("Ingrese el color del nuevo automóvil", 1);
  performance =
      requestFloatNumber("Ingrese el performance del nuevo automóvil (CV)",
                         "Por favor ingrese un permormance mayor de 1 CV", 1);
  brandNodePointer = requestBrandWithSelector(
      concessionaire.brands, "Ingrese la marca del automóvil:");

  while (!(brandNodePointer->brand.models.head != NULL)) {
    cout << endl
         << "La marca elegida no tiene modelos, por favor elija una "
            "marca con modelos."
         << endl;

    addDelay(1);

    brandNodePointer = requestBrandWithSelector(
        concessionaire.brands, "Ingrese la marca del automóvil:");
  }

  modelNodePointer = requestModelWithSelector(
      brandNodePointer->brand.models, "Ahora ingrese el modelo del automóvil:");

  newCar = buildCar(code, license, cylinderCapacity, color, performance);
  addToCollection(modelNodePointer->model.cars, newCar);

  cout << "El automóvil ha sido registrado correctamente";
}

void showBrands(concessionaireStruct concessionaire) {
  brandNode *brandNodePointer;

  clearScreen();
  showAppTitle(concessionaire);

  gotoxy(20, 10);
  cout << "Marcas de automóviles" << endl;

  showBrandsListHeaders(12);

  brandNodePointer = concessionaire.brands.head;

  for (int i = 1; brandNodePointer != NULL; i++) {
    showBrand(brandNodePointer->brand, i);
    brandNodePointer = brandNodePointer->next;
  }

  cout << endl << endl;
}

void showModels(concessionaireStruct concessionaire) {
  brandNode *brandNodePointer;
  modelNode *modelNodePointer;
  int i = 1;

  clearScreen();
  showAppTitle(concessionaire);

  gotoxy(20, 10);
  cout << "Modelos de automóviles" << endl;

  showModelsListHeaders(12);

  brandNodePointer = concessionaire.brands.head;

  while (brandNodePointer != NULL) {
    modelNodePointer = brandNodePointer->brand.models.head;
    while (modelNodePointer != NULL) {
      showModel(modelNodePointer->model, brandNodePointer->brand.name, i);
      modelNodePointer = modelNodePointer->next;
      i++;
    }

    brandNodePointer = brandNodePointer->next;
  }

  cout << endl << endl;
}

void showCars(concessionaireStruct concessionaire) {
  brandNode *brandNodePointer;
  modelNode *modelNodePointer;
  carNode *carNodePointer;
  int i = 1;

  clearScreen();
  showAppTitle(concessionaire);

  showCarsListHeaders(12);

  brandNodePointer = concessionaire.brands.head;

  while (brandNodePointer != NULL) {
    modelNodePointer = brandNodePointer->brand.models.head;
    while (modelNodePointer != NULL) {
      carNodePointer = modelNodePointer->model.cars.head;
      while (carNodePointer != NULL) {
        showCar(carNodePointer->car, brandNodePointer->brand.name,
                modelNodePointer->model.name, i);
        carNodePointer = carNodePointer->next;
        i++;
      }

      modelNodePointer = modelNodePointer->next;
    }

    brandNodePointer = brandNodePointer->next;
  }

  cout << endl << endl;
}

void showCarsByModel(concessionaireStruct concessionaire) {
  brandNode *brandNodePointer;
  modelNode *modelNodePointer;
  carNode *carNodePointer;

  brandNodePointer = requestBrandWithSelector(
      concessionaire.brands, "Ingrese la marca del automóvil:");

  while (!(brandNodePointer->brand.models.head != NULL)) {
    cout << endl
         << "La marca elegida no tiene modelos, por favor elija una "
            "marca con modelos."
         << endl;

    addDelay(1);

    brandNodePointer = requestBrandWithSelector(
        concessionaire.brands, "Ingrese la marca del automóvil:");
  }

  modelNodePointer = requestModelWithSelector(
      brandNodePointer->brand.models, "Ahora ingrese el modelo del automóvil:");

  clearScreen();
  showAppTitle(concessionaire);

  gotoxy(20, 10);
  cout << "Automóviles" << endl;

  showCarsListHeaders(12);

  carNodePointer = modelNodePointer->model.cars.head;

  for (int i = 1; carNodePointer != NULL; i++) {
    showCar(carNodePointer->car, brandNodePointer->brand.name,
            modelNodePointer->model.name, i);
    carNodePointer = carNodePointer->next;
  }

  cout << endl << endl;
}

void findCarByLicense(concessionaireStruct concessionaire) {
  brandNode *brandNodePointer;
  modelNode *modelNodePointer;
  carNode *carNodePointer;
  string licenseToFind;
  int i = 1;

  licenseToFind = requestText("Ingrese la licencia a buscar:", 1);

  clearScreen();
  showAppTitle(concessionaire);

  gotoxy(20, 10);
  cout << "Automóviles con la licencia: " << licenseToFind << endl;

  brandNodePointer = concessionaire.brands.head;

  while (brandNodePointer != NULL) {
    modelNodePointer = brandNodePointer->brand.models.head;
    while (modelNodePointer != NULL) {
      carNodePointer = modelNodePointer->model.cars.head;
      while (carNodePointer != NULL) {
        showCarsListHeaders(12);
        if (containsText(carNodePointer->car.license, licenseToFind)) {
          showCar(carNodePointer->car, brandNodePointer->brand.name,
                  modelNodePointer->model.name, i);
        }

        carNodePointer = carNodePointer->next;
        i++;
      }

      modelNodePointer = modelNodePointer->next;
    }

    brandNodePointer = brandNodePointer->next;
  }

  cout << endl << endl;
}

void mainMenu(concessionaireStruct &concessionaire) {
  int selectedOption;

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
        showCarsByModel(concessionaire);
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
