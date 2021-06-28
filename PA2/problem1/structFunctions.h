#include "helpers.h"
#include "structs.h"

using namespace std;

productStruct buildProduct(string code, string description, string name,
                           string presentation, string status, float price,
                           float discount, unsigned short stock) {
  productStruct product;

  product.code = code;
  product.description = description;
  product.discount = discount;
  product.name = name;
  product.presentation = presentation;
  product.price = price;
  product.status = status;
  product.stock = stock;

  return product;
}

categoryStruct buildCategory(string code, string name) {
  categoryStruct category;

  category.code = code;
  category.name = name;

  category.products.top = NULL;
  category.products.length = 0;

  return category;
}

warehouseStruct buildWarehouse(string address) {
  warehouseStruct warehouse;

  warehouse.address = address;

  warehouse.categories.head = NULL;
  warehouse.categories.length = 0;

  return warehouse;
}

soldProductStruct buildSoldProduct(string code, string name, float price,
                                   float discount, unsigned short quantity) {
  soldProductStruct soldProduct;

  soldProduct.code = code;
  soldProduct.discount = discount;
  soldProduct.name = name;
  soldProduct.price = price;
  soldProduct.quantity = quantity;

  return soldProduct;
}

saleStruct buildSale(string saleDate) {
  saleStruct sale;

  sale.saleDate = saleDate;

  sale.soldProducts.head = NULL;
  sale.soldProducts.length = 0;

  return sale;
}

void insert(categoriesList &categories, categoryStruct newCategory) {
  categoryNode *categoryNodePointer = new categoryNode();

  categoryNode *lastNode = categories.head;

  categoryNodePointer->category = newCategory;
  categoryNodePointer->next = NULL;

  if (categories.head == NULL) {
    categories.head = categoryNodePointer;
  } else {
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }

    lastNode->next = categoryNodePointer;
  }

  categories.length++;
}

void insert(warehousesList &warehouses, warehouseStruct newWarehouse) {
  warehouseNode *warehouseNodePointer = new warehouseNode();

  warehouseNode *lastNode = warehouses.head;

  warehouseNodePointer->warehouse = newWarehouse;
  warehouseNodePointer->next = NULL;

  if (warehouses.head == NULL) {
    warehouses.head = warehouseNodePointer;
  } else {
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }

    lastNode->next = warehouseNodePointer;
  }

  warehouses.length++;
}

void insert(soldProductsList &soldProducts, soldProductStruct newSoldProduct) {
  soldProductNode *soldProductNodePointer = new soldProductNode();

  soldProductNode *lastNode = soldProducts.head;

  soldProductNodePointer->soldProduct = newSoldProduct;
  soldProductNodePointer->next = NULL;

  if (soldProducts.head == NULL) {
    soldProducts.head = soldProductNodePointer;
  } else {
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }

    lastNode->next = soldProductNodePointer;
  }

  soldProducts.length++;
}

void insert(salesList &sales, saleStruct newSale) {
  saleNode *saleNodePointer = new saleNode();

  saleNode *lastNode = sales.head;

  saleNodePointer->sale = newSale;
  saleNodePointer->next = NULL;

  if (sales.head == NULL) {
    sales.head = saleNodePointer;
  } else {
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }

    lastNode->next = saleNodePointer;
  }

  sales.length++;
}

void push(productsStack &products, productStruct newProduct) {
  productNode *productNodePointer = new productNode();

  productNodePointer->product = newProduct;
  productNodePointer->next = products.top;

  products.top = productNodePointer;
  products.length++;
}

void collectionsInitialization(companyStruct &company) {
  company.warehouses.head = NULL;
  company.warehouses.length = 0;

  company.sales.head = NULL;
  company.sales.length = 0;
}

void dataInitialization(companyStruct &company) {
  warehouseStruct warehouse_1, warehouse_2;
  categoryStruct category_aseo_1, category_aseo_2, category_tv, category_aio;
  productStruct product_aseo_1, product_aseo_2, product_aseo_3, product_aseo_4,
      product_tv_1, product_tv_2, product_aio_1, product_aio_2;
  saleStruct sale_1;
  soldProductStruct soldProduct_1, soldProduct_2;

  company.businessName = "Almacenes SAC";
  company.ruc = "12345678910";

  warehouse_1 = buildWarehouse("Av. Bolognesi");
  warehouse_2 = buildWarehouse("Av. Javier Prado");

  category_aseo_1 = buildCategory("aseo-pers", "Aseo personal");
  category_aseo_2 = buildCategory("elec-tv", "Aseo personal");
  category_tv = buildCategory("aseo-pers", "Televisores");
  category_aio = buildCategory("pc-aio", "PC All-In-One");

  product_aseo_1 = buildProduct("pr-1", "Pasta dental", "Colgate Herbal",
                                "caja", "disponible", 5, 0.20, 120);
  product_aseo_2 = buildProduct("pr-1", "Pasta dental", "Colgate Herbal",
                                "caja", "disponible", 4.20, 0.20, 120);
  product_aseo_3 = buildProduct("pr-2", "Jabon liquido", "Jabón de marca",
                                "caja", "disponible", 5.80, 0.30, 90);
  product_aseo_4 = buildProduct("pr-4", "Shampoo", "Shampoo Head and Shoulders",
                                "botella", "disponible", 9.70, 0.60, 40);
  product_tv_1 = buildProduct("pr-5", "Tv Oled 49\"", "Tv Lg", "caja",
                              "disponible", 3100, 120, 10);
  product_tv_2 = buildProduct("pr-6", "Tv Oled 65\"", "Tv Samsung", "caja",
                              "disponible", 5900, 220, 10);
  product_aio_1 = buildProduct("pr-7", "Con Windows 10", "HP Pavilion", "caja",
                               "disponible", 4200, 0.20, 120);
  product_aio_2 = buildProduct("pr-8", "Con MacOsX", "iMac 27\"", "caja",
                               "disponible", 5, 6900, 10);

  sale_1 = buildSale("2019-12-11 11:45:00");
  soldProduct_1 = buildSoldProduct("game", "Xbox One", 1200, 10, 1);
  soldProduct_2 = buildSoldProduct("appl", "MacBook Air", 3200, 100, 1);

  insert(sale_1.soldProducts, soldProduct_1);
  insert(sale_1.soldProducts, soldProduct_2);

  push(category_aseo_1.products, product_aseo_1);
  push(category_aseo_2.products, product_aseo_2);
  push(category_aseo_1.products, product_aseo_3);
  push(category_aseo_2.products, product_aseo_4);
  push(category_tv.products, product_tv_1);
  push(category_tv.products, product_tv_2);
  push(category_aio.products, product_aio_1);
  push(category_aio.products, product_aio_2);

  insert(warehouse_1.categories, category_aseo_1);
  insert(warehouse_1.categories, category_tv);
  insert(warehouse_2.categories, category_aseo_2);
  insert(warehouse_2.categories, category_aio);

  insert(company.warehouses, warehouse_1);
  insert(company.warehouses, warehouse_2);

  insert(company.sales, sale_1);
}

warehouseNode *iterateWarehousesList(warehousesList warehouses, int index) {
  warehouseNode *warehouseNodePointer;

  if (0 >= index) {
    return NULL;
  }

  if (index > warehouses.length) {
    return NULL;
  }

  warehouseNodePointer = warehouses.head;

  for (int i = 1; warehouseNodePointer != NULL; i++) {
    if (i == index) {
      return warehouseNodePointer;
    }
    warehouseNodePointer = warehouseNodePointer->next;
  }

  return NULL;
}

warehouseNode *requestWarehouseWithSelector(warehousesList &warehouses,
                                            string message) {
  int selectedOption;
  warehouseNode *warehouseNodePointer;

  warehouseNodePointer = warehouses.head;

  cout << endl
       << message << "." << endl
       << "Escoja entre los " << warehouses.length
       << " almacenes siguientes:" << endl
       << endl;

  for (int i = 1; warehouseNodePointer != NULL; i++) {
    cout << "[" << i << "] - " << warehouseNodePointer->warehouse.address
         << endl;
    warehouseNodePointer = warehouseNodePointer->next;
  }

  cout << endl << "Introduzca la opción deseada:" << endl;
  cin >> selectedOption;

  while (!(1 <= selectedOption && selectedOption <= warehouses.length)) {
    cout << "Por favor, introduzca un valor entre 1 y " << warehouses.length
         << "." << endl;
    fflush(stdin);
    cin >> selectedOption;
  }

  return iterateWarehousesList(warehouses, selectedOption);
}

categoryNode *iterateCategoriesList(categoriesList categories, int index) {
  categoryNode *categoryNodePointer;

  if (0 >= index) {
    return NULL;
  }

  if (index > categories.length) {
    return NULL;
  }

  categoryNodePointer = categories.head;

  for (int i = 1; categoryNodePointer != NULL; i++) {
    if (i == index) {
      return categoryNodePointer;
    }
    categoryNodePointer = categoryNodePointer->next;
  }

  return NULL;
}

categoryNode *requestCategoryWithSelector(categoriesList &categories,
                                          string message) {
  int selectedOption;
  categoryNode *categoryNodePointer;

  categoryNodePointer = categories.head;

  cout << endl
       << message << "." << endl
       << "Escoja entre las " << categories.length
       << " categorias siguientes:" << endl
       << endl;

  for (int i = 1; categoryNodePointer != NULL; i++) {
    cout << "[" << i << "] - " << categoryNodePointer->category.name << endl;
    categoryNodePointer = categoryNodePointer->next;
  }

  cout << endl << "Introduzca la opción deseada:" << endl;
  cin >> selectedOption;

  while (!(1 <= selectedOption && selectedOption <= categories.length)) {
    cout << "Por favor, introduzca un valor entre 1 y " << categories.length
         << "." << endl;
    fflush(stdin);
    cin >> selectedOption;
  }

  return iterateCategoriesList(categories, selectedOption);
}

productNode *iterateProductsStack(productsStack products, int index) {
  productNode *productNodePointer;

  if (0 >= index) {
    return NULL;
  }

  if (index > products.length) {
    return NULL;
  }

  productNodePointer = products.top;

  for (int i = 1; productNodePointer != NULL; i++) {
    if (i == index) {
      return productNodePointer;
    }
    productNodePointer = productNodePointer->next;
  }

  return NULL;
}

productNode *requestProductWithSelector(productsStack &products,
                                        string message) {
  int selectedOption;
  productNode *productNodePointer;

  productNodePointer = products.top;

  cout << endl
       << message << "." << endl
       << "Escoja entre los " << products.length
       << " productos siguientes:" << endl
       << endl;

  for (int i = 1; productNodePointer != NULL; i++) {
    cout << "[" << i << "] - " << productNodePointer->product.name << endl;
    productNodePointer = productNodePointer->next;
  }

  cout << endl << "Introduzca la opción deseada:" << endl;
  cin >> selectedOption;

  while (!(1 <= selectedOption && selectedOption <= products.length)) {
    cout << "Por favor, introduzca un valor entre 1 y " << products.length
         << "." << endl;
    fflush(stdin);
    cin >> selectedOption;
  }

  return iterateProductsStack(products, selectedOption);
}

saleNode *iterateSalesList(salesList sales, int index) {
  saleNode *saleNodePointer;

  if (0 >= index) {
    return NULL;
  }

  if (index > sales.length) {
    return NULL;
  }

  saleNodePointer = sales.head;

  for (int i = 1; saleNodePointer != NULL; i++) {
    if (i == index) {
      return saleNodePointer;
    }
    saleNodePointer = saleNodePointer->next;
  }

  return NULL;
}

saleNode *requestSaleWithSelector(salesList &sales, string message) {
  int selectedOption;
  saleNode *saleNodePointer;

  saleNodePointer = sales.head;

  cout << endl
       << message << "." << endl
       << "Escoja entre las " << sales.length << " ventas siguientes:" << endl
       << endl;

  for (int i = 1; saleNodePointer != NULL; i++) {
    cout << "[" << i << "] - " << saleNodePointer->sale.saleDate << endl;
    saleNodePointer = saleNodePointer->next;
  }

  cout << endl << "Introduzca la opción deseada:" << endl;
  cin >> selectedOption;

  while (!(1 <= selectedOption && selectedOption <= sales.length)) {
    cout << "Por favor, introduzca un valor entre 1 y " << sales.length << "."
         << endl;
    fflush(stdin);
    cin >> selectedOption;
  }

  return iterateSalesList(sales, selectedOption);
}

unsigned short getTotalPrice(soldProductsList soldProducts) {
  soldProductNode *aux = soldProducts.head;
  unsigned short totalPrice = 0;

  while (aux != NULL) {
    totalPrice += aux->soldProduct.price * aux->soldProduct.quantity -
                  aux->soldProduct.discount;
    aux = aux->next;
  }

  return totalPrice;
}

void showProductsStackHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Código";
  gotoxy(10, y);
  cout << "Nombre";
  gotoxy(25, y);
  cout << "Descripción";
  gotoxy(50, y);
  cout << "Precio";
  gotoxy(56, y);
  cout << "Descuento";
  gotoxy(62, y);
  cout << "Stock";
  gotoxy(68, y);
  cout << "Presentación";
  gotoxy(74, y);
  cout << "Status";
}

void showProduct(productStruct product, int n, int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << product.code;
  gotoxy(10, y);
  cout << product.name;
  gotoxy(25, y);
  cout << product.description;
  gotoxy(50, y);
  cout << product.price;
  gotoxy(56, y);
  cout << product.discount;
  gotoxy(62, y);
  cout << product.stock;
  gotoxy(68, y);
  cout << product.presentation;
  gotoxy(74, y);
  cout << product.status;
}

void showCategoriesListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Codigo";
  gotoxy(20, y);
  cout << "Nombre";
  gotoxy(40, y);
  cout << "Cantidad de productos";
}

void showCategory(categoryStruct category, int n, int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << category.code;
  gotoxy(20, y);
  cout << category.name;
  gotoxy(40, y);
  cout << category.products.length;
}

void showWarehousesListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Dirección";
  gotoxy(25, y);
  cout << "Categorias de productos en venta";
}

void showWarehouse(warehouseStruct warehouse, int n, int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << warehouse.address;
  gotoxy(25, y);
  cout << warehouse.categories.length << " categorias";
}

void showSoldProductsListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Código";
  gotoxy(15, y);
  cout << "Nombre";
  gotoxy(40, y);
  cout << "Precio Unitario";
  gotoxy(50, y);
  cout << "Descuento";
  gotoxy(60, y);
  cout << "Cantidad";
  gotoxy(70, y);
  cout << "Parcial";
}

void showSoldProduct(soldProductStruct soldProduct, int n, int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << soldProduct.code;
  gotoxy(15, y);
  cout << soldProduct.name;
  gotoxy(40, y);
  cout << soldProduct.price;
  gotoxy(50, y);
  cout << soldProduct.discount;
  gotoxy(60, y);
  cout << soldProduct.quantity;
  gotoxy(70, y);
  cout << soldProduct.price * soldProduct.quantity - soldProduct.discount;
}

void showSalesListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Fecha de Compra";
  gotoxy(30, y);
  cout << "Monto total";
}

void showSale(saleStruct sale, int n, int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << sale.saleDate;
  gotoxy(30, y);
  cout << getTotalPrice(sale.soldProducts);
}

void showProductInWarehouseStackHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Código";
  gotoxy(15, y);
  cout << "Nombre";
  gotoxy(40, y);
  cout << "Precio";
  gotoxy(50, y);
  cout << "Descuento";
  gotoxy(60, y);
  cout << "Stock";
  gotoxy(70, y);
  cout << "Almacén";
}

void showProductInWarehouse(productStruct product, string warehouseAddress,
                            int n, int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << product.code;
  gotoxy(15, y);
  cout << product.name;
  gotoxy(40, y);
  cout << product.price;
  gotoxy(50, y);
  cout << product.discount;
  gotoxy(60, y);
  cout << product.stock;
  gotoxy(70, y);
  cout << warehouseAddress;
}