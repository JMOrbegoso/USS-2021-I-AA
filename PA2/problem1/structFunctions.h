#include "helpers.h"
#include "structs.h"

using namespace std;

void collectionsInitialization(companyStruct &company) {
  company.warehouses.head = NULL;
  company.warehouses.length = 0;

  company.sales.head = NULL;
  company.sales.length = 0;
}

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

saleStruct buildSaleStruct(string saleDate) {
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

unsigned short getTotalPrice(soldProductsList soldProducts) {
  soldProductNode *aux = soldProducts.head;
  unsigned short totalPrice = 0;

  while (aux != NULL) {
    totalPrice += aux->soldProduct.price * aux->soldProduct.quantity -
                  aux->soldProduct.discount;
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
}

void showWarehouse(warehouseStruct warehouse, int n, int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << warehouse.address;
}

void showSoldProductsListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Código";
  gotoxy(10, y);
  cout << "Nombre";
  gotoxy(25, y);
  cout << "Precio Unitario";
  gotoxy(56, y);
  cout << "Descuento";
  gotoxy(80, y);
  cout << "Cantidad";
  gotoxy(80, y);
  cout << "Parcial";
}

void showSoldProduct(soldProductStruct soldProduct, int n, int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << soldProduct.code;
  gotoxy(10, y);
  cout << soldProduct.name;
  gotoxy(25, y);
  cout << soldProduct.price;
  gotoxy(56, y);
  cout << soldProduct.discount;
  gotoxy(80, y);
  cout << soldProduct.quantity;
  gotoxy(80, y);
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