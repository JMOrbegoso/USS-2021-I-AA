#include <iostream>

using namespace std;

// Producto
struct productoStruct {
  string nombre;
  string marca;
  string tipo;
  float precio;
};

struct productoNodo {
  productoStruct producto;
  productoNodo *siguiente;
};

struct productosLista {
  productoNodo *cabecera;
  int largo;
};

// Productos en almacen
struct productoEnAlmacenStruct {
  productoNodo *producto;
  int cantidad;
};

struct productoEnAlmacenNodo {
  productoEnAlmacenStruct productoEnAlmacen;
  productoEnAlmacenNodo *siguiente;
};

struct productosEnAlmacenLista {
  productoEnAlmacenNodo *cabecera;
  int largo;
};

// Productos en carrito de compras
struct productoEnCarritoDeCompraStruct {
  productoEnAlmacenNodo *productoEnAlmacen;
  int cantidad;
};

struct productoEnCarritoDeCompraNodo {
  productoEnCarritoDeCompraStruct productoEnCarritoDeCompra;
  productoEnCarritoDeCompraNodo *siguiente;
};

struct productosEnCarritosDeComprasPila {
  productoEnCarritoDeCompraNodo *cabecera;
  int largo;
};

// Clientes
struct clienteStruct {
  string nombre;
  string apellidoPaterno;
  string apellidoMaterno;
  bool genero;
  string dni;
  productosEnCarritosDeComprasPila productosEnCarritosDeCompras;
};

struct clienteNodo {
  clienteStruct cliente;
  clienteNodo *siguiente;
};

struct clientesLista {
  clienteNodo *cabecera;
  int largo;
};

// Cola de clientes
struct clienteRecogiendoCompraStruct {
  clienteNodo *cliente;
  string fechaDeLLegada;
};

struct clienteRecogiendoCompraNodo {
  clienteRecogiendoCompraStruct clienteRecogiendoCompra;
  clienteRecogiendoCompraNodo *siguiente;
};

struct clientesRecogiendoComprasCola {
  clienteRecogiendoCompraNodo *inicio;
  clienteRecogiendoCompraNodo *fin;
  int largo;
};

// Almacen
struct almacenStruct {
  string nombre;
  string direccion;
  productosEnAlmacenLista productosEnAlmacen;
  clientesRecogiendoComprasCola clientesRecogiendoCompras;
};

struct almacenNodo {
  almacenStruct almacen;
  almacenNodo *siguiente;
};

struct almacenesGrafo {
  almacenNodo *chiclayo;
  almacenNodo *trujillo;
  almacenNodo *lima;
};

// Productos comprados
struct productoCompradoStruct : productoStruct {};

struct productoCompradoNodo {
  productoCompradoStruct productoComprado;
  productoCompradoNodo *siguiente;
};

struct productosCompradosLista {
  productoCompradoNodo *cabecera;
  int largo;
};

// Compras
struct compraStruct {
  productosCompradosLista productosComprados;
  clienteNodo *cliente;
  string fecha;
  string estado;
};

struct compraNodo {
  compraStruct compra;
  compraNodo *siguiente;
};

struct comprasLista {
  compraNodo *cabecera;
  int largo;
};

// Deltron
struct deltronStruct {
  string razonSocial;
  string ruc;
  productosLista productos;
  almacenesGrafo almacenes;
  clientesLista clientes;
  comprasLista compras;
};
