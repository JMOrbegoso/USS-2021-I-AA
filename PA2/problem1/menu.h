#include "structFunctions.h"

using namespace std;

void showAppTitle(companyStruct company) {
  cout << endl
       << "-----------------------------------------------------------" << endl;
  cout << "\t Sistema Virtual de la empresa " << company.businessName << endl;
  cout << "RUC: " << company.ruc << endl;
  cout << "Almacenes: " << company.warehouses.length << endl;
  cout << "Ventas realizadas en total: " << company.sales.length << endl;
  cout << "-----------------------------------------------------------" << endl;
}

void registerNewWarehouse(companyStruct &company) {
  string address;
  warehouseStruct newWarehouse;

  clearScreen();
  showAppTitle(company);

  gotoxy(20, 10);
  cout << "Registrar nuevo almacén:" << endl;

  address = requestText("Ingrese la dirección del nuevo almacén", 2);

  newWarehouse = buildWarehouse(address);

  insert(company.warehouses, newWarehouse);

  cout << "El nuevo almacén fue añadido de forma exitosa" << endl;
}

void showAllWarehouses(companyStruct company) {
  warehouseNode *warehouseNodePointer;

  clearScreen();
  showAppTitle(company);

  gotoxy(20, 10);
  cout << "Todos los almacenes de la empresa " << company.businessName << endl;

  warehouseNodePointer = company.warehouses.head;

  showWarehousesListHeader(12);

  for (int i = 1; warehouseNodePointer != NULL; i++) {
    showWarehouse(warehouseNodePointer->warehouse, i, i + 13);
    warehouseNodePointer = warehouseNodePointer->next;
  }

  cout << endl << endl;
}

void showCategoriesByWarehouse(companyStruct company) {
  warehouseNode *warehouseNodePointer;
  categoryNode *categoryNodePointer;

  warehouseNodePointer = requestWarehouseWithSelector(
      company.warehouses,
      "Ingrese el almacén del que quiere revisar las categorias de productos");

  clearScreen();
  showAppTitle(company);

  gotoxy(20, 10);
  cout << "Categorias de productos del almacén ubicado en "
       << warehouseNodePointer->warehouse.address << ":" << endl;

  categoryNodePointer = warehouseNodePointer->warehouse.categories.head;

  showCategoriesListHeader(12);

  for (int i = 1; categoryNodePointer != NULL; i++) {
    showCategory(categoryNodePointer->category, i, i + 13);
    categoryNodePointer = categoryNodePointer->next;
  }

  cout << endl << endl;
}

void showProductsByWarehouse(companyStruct company) {
  warehouseNode *warehouseNodePointer;
  categoryNode *categoryNodePointer;
  productNode *productNodePointer;

  warehouseNodePointer = requestWarehouseWithSelector(
      company.warehouses,
      "Ingrese el almacén del que quiere revisar las categorias de productos");

  clearScreen();
  showAppTitle(company);

  gotoxy(20, 10);
  cout << "Categorias de productos del almacén ubicado en "
       << warehouseNodePointer->warehouse.address << ":" << endl;

  categoryNodePointer = warehouseNodePointer->warehouse.categories.head;

  showProductsStackHeader(12);

  int i = 1;
  while (categoryNodePointer != NULL) {
    productNodePointer = categoryNodePointer->category.products.top;

    while (productNodePointer != NULL) {
      showProduct(productNodePointer->product, i, i + 13);
      productNodePointer = productNodePointer->next;
      i++;
    }

    categoryNodePointer = categoryNodePointer->next;
  }

  cout << endl << endl;
}

void findProductInWarehouses(companyStruct company) {
  string productToFind;
  warehouseNode *warehouseNodePointer;
  categoryNode *categoryNodePointer;
  productNode *productNodePointer;

  productToFind = requestText(
      "Ingrese el nombre del producto que desea buscar en todos los almacenes",
      1);

  clearScreen();
  showAppTitle(company);

  gotoxy(20, 8);
  cout << "Productos con nombre similar a " << productToFind
       << " en todos los almacenes:" << endl;

  showProductInWarehouseStackHeader(10);

  warehouseNodePointer = company.warehouses.head;

  int i = 1;
  while (warehouseNodePointer != NULL) {
    categoryNodePointer = warehouseNodePointer->warehouse.categories.head;
    while (categoryNodePointer != NULL) {
      productNodePointer = categoryNodePointer->category.products.top;

      while (productNodePointer != NULL) {
        if (containsText(productNodePointer->product.name, productToFind)) {
          showProductInWarehouse(productNodePointer->product,
                                 warehouseNodePointer->warehouse.address, i,
                                 i + 11);
          i++;
        }

        productNodePointer = productNodePointer->next;
      }

      categoryNodePointer = categoryNodePointer->next;
    }

    warehouseNodePointer = warehouseNodePointer->next;
  }

  cout << endl << endl;
}

int requestMenuOption(companyStruct company) {
  int selectedOption;

  clearScreen();
  showAppTitle(company);

  cout << endl << "Este sistema tiene las siguientes opciones:" << endl << endl;

  cout << "[1] Registrar un almacén" << endl;
  cout << "[2] Registrar un producto" << endl;
  cout << endl;
  cout << "[3] Abastecer un producto" << endl;
  cout << "[4] Proveer un producto" << endl;
  cout << endl;
  cout << "[5] Listar almacenes" << endl;
  cout << "[6] Listar categorias de productos en un almacén" << endl;
  cout << "[7] Listar productos un almacén" << endl;
  cout << "[8] Listar ventas realizadas" << endl;
  cout << "[9] Listar productos vendidos en una ventas especifica" << endl;
  cout << endl;
  cout << "[10] Buscar un producto en todos los almacenes" << endl;
  cout << endl;
  cout << "[0] Cerrar" << endl;

  cout << endl << "Por favor ingrese una de las opciones:" << endl;
  cin >> selectedOption;
  while (!(0 <= selectedOption && selectedOption <= 10)) {
    cout << "La opcion seleccionada fue inválida, por favor seleccione una "
            "opcion válida:"
         << endl;
    cin >> selectedOption;
  }
  return selectedOption;
}

void mainMenu(companyStruct &company) {
  int selectedOption;

  do {
    selectedOption = requestMenuOption(company);

    if (selectedOption != 0) {
      switch (selectedOption) {
        case 1:
          registerNewWarehouse(company);
          addDelay(2);
          break;
        case 5:
          showAllWarehouses(company);
          pauseProcess();
          break;
        case 6:
          showCategoriesByWarehouse(company);
          pauseProcess();
          break;
        case 7:
          showProductsByWarehouse(company);
          pauseProcess();
          break;
        case 10:
          findProductInWarehouses(company);
          pauseProcess();
          break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}
