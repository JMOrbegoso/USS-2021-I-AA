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

struct productosEnCarritoDeCompraPila {
  productoEnCarritoDeCompraNodo *cabecera;
  int largo;
};

// Personas
struct personaStruct {
  string nombre;
  string apellidoPaterno;
  string apellidoMaterno;
  char genero;
  string dni;
  string claveDeAcceso;
};

// Empleados
struct empleadoStruct : personaStruct {
  float salario;
};

struct empleadoNodo {
  empleadoStruct empleado;
  empleadoNodo *siguiente;
};

struct empleadosLista {
  empleadoNodo *cabecera;
  int largo;
};

// Clientes
struct clienteStruct : personaStruct {
  productosEnCarritoDeCompraPila productosEnCarritoDeCompra;
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
  almacenVertice *adyacente;
};

struct almacenVertice {
  almacenNodo *destino;
  almacenVertice *siguiente;
};

struct almacenesGrafo {
  almacenNodo *nodo;
  almacenVertice *vertice;
  int largo;
};

// Productos comprados
struct productoCompradoStruct : productoStruct {
  int cantidad;
};

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
  empleadosLista empleados;
  clientesLista clientes;  
  comprasLista compras;
};
