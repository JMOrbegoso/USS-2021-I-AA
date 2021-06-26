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

soldProductStruct buildSoldProduct(string code, string description, string name,
                                   string presentation, string status,
                                   float price, float discount,
                                   unsigned short stock,
                                   unsigned short quantity) {
  soldProductStruct soldProduct;

  soldProduct.code = code;
  soldProduct.description = description;
  soldProduct.discount = discount;
  soldProduct.name = name;
  soldProduct.presentation = presentation;
  soldProduct.price = price;
  soldProduct.status = status;
  soldProduct.stock = stock;

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

  productNodePointer->book = newProduct;
  productNodePointer->next = products.top;

  products.top = productNodePointer;
  products.length++;
}
