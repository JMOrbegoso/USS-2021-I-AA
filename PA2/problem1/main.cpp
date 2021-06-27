// 1. Una empresa lleva el control de sus almacenes que registran sus productos
// (código, nombre, descripción, precio, descuento, stock, presentación y
// estado) que vende.
//
// Cada producto pertenece a una categoría que tiene:
// un nombre, un código y lleva un control de la cantidad de productos
// registrados.
//
// Se pide que se lleve el control del registro de los productos que se apilan
// en el almacén.
// De las categorías se debe llevar el control de los productos
// que venden, la fecha de venta y el monto total de las ventas.
//
// Para los cual se deben presentar las opciones de:
//
// - Registrar un almacén
// - Registrar un producto
// - Abastecer (incrementar el stock de un producto)
// - Proveer (incrementar el producto)
// - Listar productos por almacén elegido
// - Buscar un producto en los almacenes y ver stock

#include "menu.h"

using namespace std;

int main(int argc, char *argv[]) {
  companyStruct company;

  collectionsInitialization(company);
  dataInitialization(company);

  mainMenu(company);
  return 0;
}
