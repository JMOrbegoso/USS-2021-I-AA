#include <iostream>

using namespace std;

// Producto
struct productoStruct {
  string marca;
  string nombre;
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

// Subcategoria
struct subcategoriaStruct {
  string marca;
  productosLista productos;
};

struct subcategoriaNodo {
  subcategoriaStruct subcategoria;
  subcategoriaNodo *siguiente;
};

struct subcategoriasLista {
  subcategoriaNodo *cabecera;
  int largo;
};

// Categoria
struct categoriaStruct {
  string nombre;
  subcategoriasLista subcategorias;
};

struct categoriaNodo {
  categoriaStruct categoria;
  categoriaNodo *siguiente;
};

struct categoriasLista {
  categoriaNodo *cabecera;
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

// Almacen
struct almacenStruct {
  productosEnAlmacenLista productosEnAlmacen;
  string direccion;
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

struct productosEnCarritosDeComprasLista {
  productoEnCarritoDeCompraNodo *cabecera;
  int largo;
};

// Carrito de compra
struct carritoDeCompraStruct {
  productosEnCarritosDeComprasLista productosEnCarritosDeCompras;
};

// Clientes
struct clienteStruct {
  string nombre;
  string apellidoPaterno;
  string apellidoMaterno;
  bool genero;
  string dni;
  carritoDeCompraStruct carritoDeCompra;
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

// Sucursal
struct sucursalStruct {
  string nombre;
  almacenStruct almacen;
  clientesRecogiendoComprasCola clientesRecogiendoCompras;
};

struct sucursalNodo {
  sucursalStruct sucursal;
  sucursalNodo *siguiente;
};

struct sucursalesLista {
  sucursalNodo *cabecera;
  int largo;
};

// Productos comprados
struct productoCompradoStruct {
  string marca;
  string nombre;
  float precio;
  int cantidad;
};

struct productoCompradoNodo {
  productoCompradoStruct producto;
  productoCompradoNodo *siguiente;
};

struct productosCompradosLista {
  productoCompradoNodo *cabecera;
  int largo;
};

// Compras
struct compraStruct {
  productosCompradosLista productosComprados;
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
  clientesLista clientes;
  sucursalesLista sucursales;
  categoriasLista categorias;
  comprasLista compras;
};
