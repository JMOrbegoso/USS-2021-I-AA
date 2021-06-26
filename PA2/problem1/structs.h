#include <iostream>

using namespace std;

// Product
struct productStruct {
  string code;
  string name;
  string description;
  float price;
  float discount;
  unsigned short stock;
  string presentation;
  string status;
};

struct productNode {
  productStruct product;
  productNode *next;
};

struct productsStack {
  productNode *top;
  int length;
};

// Product Category
struct categoryStruct {
  string name;
  string code;
  productsStack products;
};

struct categoryNode {
  categoryStruct category;
  categoryNode *next;
};

struct categoriesList {
  categoryNode *head;
  int length;
};

// Warehouse
struct warehouseStruct {
  string address;
  categoriesList categories;
};

struct warehouseNode {
  warehouseStruct warehouse;
  warehouseNode *next;
};

struct warehousesList {
  warehouseNode *head;
  int length;
};

// Sold products
struct soldProductStruct : productStruct {
  unsigned short quantity;
};

struct soldProductNode {
  soldProductStruct soldProduct;
  soldProductNode *next;
};

struct soldProductsList {
  soldProductNode *head;
  int length;
};

// Sales
struct saleStruct {
  string saleDate;
  soldProductsList soldProducts;
};

struct saleNode {
  saleStruct sale;
  saleNode *next;
};

struct salesList {
  saleNode *head;
  int length;
};

// Company
struct companyStruct {
  string ruc;
  string businessName;
  warehousesList warehouses;
  salesList sales;
};