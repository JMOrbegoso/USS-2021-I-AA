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
  cout << "[4] Buscar un automóvil por por placa" << endl;
  cout << "[5] Listar todos los automóviles" << endl;
  cout << "[6] Listar automóviles por modelo" << endl;
  cout << "[0] Cerrar" << endl;

  cout << endl << "Por favor ingrese una de las opciones:" << endl;
  cin >> selectedOption;
  while (!(0 <= selectedOption && selectedOption <= 6)) {
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
  modelStruct *modelPointer;
  string code, license, color;
  float cylinderCapacity, performance;

  cout << "Va a registrar un nuevo automóvil" << endl << endl;

  code = requestText("Ingrese el código del nuevo automóvil", 1);
  license = requestText("Ingrese el nombre del nuevo modelo", 1);
  cylinderCapacity =
      requestFloatNumber("Ingrese el cilindraje del nuevo automóvil (cc)", 1);
  color = requestText("Ingrese el tipo del nuevo modelo", 1);
  performance =
      requestFloatNumber("Ingrese el performance del nuevo automóvil (CV)", 1);
  modelPointer = requestModel(concessionaire);

  newCar = buildCar(code, license, cylinderCapacity, color, performance);
  addToCollection(modelPointer->cars, newCar);

  cout << "El modelo de automóviles ha sido registrado correctamente";
}

void showBrands(concessionaireStruct concessionaire) {
  clearScreen();
  showAppTitle(concessionaire);

  gotoxy(10, 6);
  cout << "Marcas de automóviles" << endl;

  brandNode *node = concessionaire.brands.firstNode;

  gotoxy(0, 8);
  cout << "#";
  gotoxy(5, 8);
  cout << "Código";
  gotoxy(20, 8);
  cout << "Nombre";
  gotoxy(35, 8);
  cout << "País";
  gotoxy(50, 8);
  cout << "# de Modelos";

  int i = 1;
  while (node != NULL) {
    showBrand(node->brand, i);
    node = node->next;
    i++;
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
        // registerNewCar(concessionaire);
        addDelay(2);
        break;
        ;

      case 4:
        // findCarByLicense(concessionaire);
        pauseProcess();
        break;

      case 5:
        //  showAllCars(concessionaire);
        pauseProcess();
        break;

      case 6:
        //  showCarsByModel(concessionaire);
        pauseProcess();
        break;
      }
    }

  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}
