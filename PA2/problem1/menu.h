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

void registerNewCategory(companyStruct &company) {
  string name, code;
  warehouseNode *warehouseNodePointer;
  categoryStruct newCategory;

  clearScreen();
  showAppTitle(company);

  gotoxy(20, 10);
  cout << "Registrar nueva categoria de productos:" << endl;

  code = requestText("Ingrese el codigo de la nueva categoria de productos", 2);
  name = requestText("Ingrese el nombre de la nueva categoria de productos", 2);

  newCategory = buildCategory(code, name);

  warehouseNodePointer = requestWarehouseWithSelector(
      company.warehouses,
      "Ingrese el almacén de la nueva categoria de productos");

  insert(warehouseNodePointer->warehouse.categories, newCategory);

  cout << "La categoria de productos fue añadida correctamente al almacén"
       << endl;
}

void registerNewProduct(companyStruct &company) {
  warehouseNode *warehouseNodePointer;
  categoryNode *categoryNodePointer;
  productStruct newProduct;
  string code, description, name, presentation, status;
  float price, discount;
  unsigned short stock;

  cout << "Va a añadir un nuevo producto a un almacén" << endl << endl;

  code = requestText("Ingrese el código del nuevo producto", 1);
  description = requestText("Ingrese la descripción del nuevo producto", 1);
  name = requestText("Ingrese el nombre del nuevo producto", 1);
  presentation = requestText("Ingrese la presentacion del nuevo producto", 1);
  status = requestText("Ingrese el status del nuevo producto", 1);
  price = requestMoney("Ingrese el precio del nuevo producto", 0.10);
  discount = requestMoney("Ingrese el descuento del nuevo producto", 0.10);
  stock = requestIntegerNumber("Ingrese el stock del producto",
                               "Por favor ingrese un valor superior a 1", 1);

  warehouseNodePointer = requestWarehouseWithSelector(
      company.warehouses, "Ingrese el almacén del nuevo producto");

  while (!(warehouseNodePointer->warehouse.categories.head != NULL)) {
    cout << endl
         << "El almacén seleccionado no tiene categorias de productos, por "
            "favor seleccione un almacén con categorias de productos."
         << endl;

    warehouseNodePointer = requestWarehouseWithSelector(
        company.warehouses, "Ingrese el almacén del nuevo producto");
  }

  categoryNodePointer = requestCategoryWithSelector(
      warehouseNodePointer->warehouse.categories,
      "Ingrese la categoria de productos del nuevo producto");

  newProduct = buildProduct(code, description, name, presentation, status,
                            price, discount, stock);

  push(categoryNodePointer->category.products, newProduct);

  cout << "El producto ha sido registrado correctamente.";
}

void increaseProductStock(companyStruct company) {
  warehouseNode *warehouseNodePointer;
  categoryNode *categoryNodePointer;
  productNode *productNodePointer;
  unsigned short stock;

  cout << "Va a editar el stock de un producto en almacén" << endl << endl;

  warehouseNodePointer = requestWarehouseWithSelector(
      company.warehouses, "Ingrese el almacén del producto");

  while (!(warehouseNodePointer->warehouse.categories.head != NULL)) {
    cout << endl;
    cout << "El almacén seleccionado no tiene categorias de productos, por "
            "favor seleccione un almacén con categorias de productos.";
    cout << endl;

    warehouseNodePointer = requestWarehouseWithSelector(
        company.warehouses, "Ingrese el almacén del producto");
  }

  categoryNodePointer =
      requestCategoryWithSelector(warehouseNodePointer->warehouse.categories,
                                  "Seleccione la categoria del producto");

  while (!(categoryNodePointer->category.products.top != NULL)) {
    cout << endl;
    cout << "La categoria seleccionada no tiene productos, por favor "
            "seleccione una categoria con productos.";
    cout << endl;

    categoryNodePointer =
        requestCategoryWithSelector(warehouseNodePointer->warehouse.categories,
                                    "Seleccione la categoria del producto");
  }

  productNodePointer = requestProductWithSelector(
      categoryNodePointer->category.products,
      "Escoja el producto al que le gustaria cambiar el stock");

  stock = requestIntegerNumber(
      "Ingrese el nuevo stock del producto (mayor de 0)",
      "Por favor ingrese un valor entre 0 y 10000", 0, 10000);

  productNodePointer->product.stock = stock;

  cout << "El stock del producto ha cambiado correctamente.";
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

void showSales(companyStruct company) {
  saleNode *saleNodePointer;

  clearScreen();
  showAppTitle(company);

  gotoxy(20, 10);
  cout << "Todos las ventas de la empresa " << company.businessName << endl;

  saleNodePointer = company.sales.head;

  showSalesListHeader(12);

  for (int i = 1; saleNodePointer != NULL; i++) {
    showSale(saleNodePointer->sale, i, i + 13);
    saleNodePointer = saleNodePointer->next;
  }

  cout << endl << endl;
}

void showProductsSoldBySale(companyStruct company) {
  saleNode *saleNodePointer;
  soldProductNode *soldProductPointer;

  saleNodePointer = requestSaleWithSelector(
      company.sales, "Escoja la venta que desea revisar");

  clearScreen();
  showAppTitle(company);

  gotoxy(20, 10);
  cout << "Todos los productos vendidos en la venta "
       << saleNodePointer->sale.saleDate << endl;

  showSoldProductsListHeader(12);

  soldProductPointer = saleNodePointer->sale.soldProducts.head;

  for (int i = 1; soldProductPointer != NULL; i++) {
    showSoldProduct(soldProductPointer->soldProduct, i, i + 13);
    soldProductPointer = soldProductPointer->next;
  }

  cout << endl << endl;
}

int requestMenuOption(companyStruct company) {
  int selectedOption;

  clearScreen();
  showAppTitle(company);

  cout << endl << "Este sistema tiene las siguientes opciones:" << endl << endl;

  cout << "[1] Registrar un almacén" << endl;
  cout << "[2] Registrar categoria de productos" << endl;
  cout << "[3] Registrar un producto" << endl;
  cout << endl;
  cout << "[4] Abastecer un producto" << endl;
  cout << "[5] Proveer un producto" << endl;
  cout << endl;
  cout << "[6] Listar almacenes" << endl;
  cout << "[7] Listar categorias de productos en un almacén" << endl;
  cout << "[8] Listar productos un almacén" << endl;
  cout << "[9] Listar ventas realizadas" << endl;
  cout << "[10] Listar productos vendidos en una ventas especifica" << endl;
  cout << endl;
  cout << "[11] Buscar un producto en todos los almacenes" << endl;
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
        case 2:
          registerNewCategory(company);
          addDelay(2);
          break;
        case 3:
          registerNewProduct(company);
          addDelay(2);
          break;
        case 4:
          increaseProductStock(company);
          addDelay(2);
          break;
        case 6:
          showAllWarehouses(company);
          pauseProcess();
          break;
        case 7:
          showCategoriesByWarehouse(company);
          pauseProcess();
          break;
        case 8:
          showProductsByWarehouse(company);
          pauseProcess();
          break;
        case 9:
          showSales(company);
          pauseProcess();
          break;
        case 10:
          showProductsSoldBySale(company);
          pauseProcess();
          break;
        case 11:
          findProductInWarehouses(company);
          pauseProcess();
          break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}
