#include <iostream>

using namespace std;

struct almacenVertice;

// Producto
struct productoBaseStruct {
  string codigo;
  string nombre;
  string marca;
  string tipo;
  float precio;
};

// Usuario
struct usuarioBaseStruct {
  string nombres;
  string apellidos;
  bool genero;  // True para hombre, False para mujer
  string dni;
  string claveDeAcceso;
};

// Productos en almacen
struct productoEnAlmacenStruct : productoBaseStruct {
  int stock;
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
struct productoEnCarritoDeCompraStruct : productoBaseStruct {
  int cantidad;
};

struct productoEnCarritoDeCompraNodo {
  productoEnCarritoDeCompraStruct productoEnCarritoDeCompra;
  productoEnCarritoDeCompraNodo *siguiente;
};

struct productosEnCarritoDeCompraPila {
  string codigoAlmacen;
  productoEnCarritoDeCompraNodo *cabecera;
  int largo;
};

// Empleados
struct empleadoStruct : usuarioBaseStruct {
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
struct clienteStruct : usuarioBaseStruct {
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

// Cola para recoger compra
struct personaRecogiendoCompraStruct {
  string nombres;
  string apellidos;
  string dni;
  string fechaDeLLegada;
};

struct personaRecogiendoCompraNodo {
  personaRecogiendoCompraStruct personaRecogiendoCompra;
  personaRecogiendoCompraNodo *siguiente;
};

struct personasRecogiendoComprasCola {
  personaRecogiendoCompraNodo *inicio;
  personaRecogiendoCompraNodo *fin;
  int largo;
};

// Almacen
struct almacenStruct {
  string codigoAlmacen;
  string departamentoDelPeru;
  string direccion;
  productosEnAlmacenLista productosEnAlmacen;
  personasRecogiendoComprasCola personasRecogiendoCompras;
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

// Productos vendidos
struct productoVendidoStruct : productoBaseStruct {
  int cantidad;
};

struct productoVendidoNodo {
  productoVendidoStruct productoVendido;
  productoVendidoNodo *siguiente;
};

struct productosVendidosLista {
  productoVendidoNodo *cabecera;
  int largo;
};

// Ventas
struct ventaStruct {
  string nombresCliente;
  string apellidosCliente;
  string dniCliente;
  string fechaDeVenta;
  string estadoDeVenta;
  productosVendidosLista productosVendidos;
};

struct ventaNodo {
  ventaStruct venta;
  ventaNodo *siguiente;
};

struct ventasLista {
  ventaNodo *cabecera;
  int largo;
};

// Deltron
struct deltronStruct {
  string razonSocial;
  string ruc;

  almacenesGrafo almacenes;
  empleadosLista empleados;
  clientesLista clientes;
  ventasLista ventas;
};
