#include "helpers.hpp"
#include "structs.hpp"

using namespace std;

void inicializacionDeColecciones(deltronStruct &deltron) {}

void inicializacionDeData(deltronStruct &deltron) {}

// Fabricas

productoStruct construirProducto(string nombre, string marca, string tipo,
                                 float precio) {
  productoStruct producto;

  producto.nombre = nombre;
  producto.marca = marca;
  producto.tipo = tipo;
  producto.precio = precio;

  return producto;
}

clienteStruct construirCliente(string nombre, string apellidoPaterno,
                               string apellidoMaterno, bool genero,
                               string dni) {
  clienteStruct cliente;

  cliente.nombre = nombre;
  cliente.apellidoPaterno = apellidoPaterno;
  cliente.apellidoMaterno = apellidoMaterno;
  cliente.genero = genero;
  cliente.dni = dni;

  cliente.productosEnCarritosDeCompras.cabecera = NULL;
  cliente.productosEnCarritosDeCompras.largo = 0;

  return cliente;
}

almacenStruct construirAlmacen(string nombre, string direccion) {
  almacenStruct almacen;

  almacen.nombre = nombre;
  almacen.direccion = direccion;

  almacen.productosEnAlmacen.cabecera = NULL;
  almacen.productosEnAlmacen.largo = 0;

  almacen.clientesRecogiendoCompras.inicio = NULL;
  almacen.clientesRecogiendoCompras.fin = NULL;
  almacen.clientesRecogiendoCompras.largo = 0;

  return almacen;
}

compraStruct construirCompra(string fecha, string estado) {
  compraStruct compra;

  compra.fecha = fecha;
  compra.estado = estado;

  compra.cliente = NULL;

  compra.productosComprados.cabecera = NULL;
  compra.productosComprados.largo = 0;

  return compra;
}

productoEnAlmacenStruct construirProductoEnAlmacen() {
  productoEnAlmacenStruct productoEnAlmacen;

  productoEnAlmacen.producto = NULL;

  productoEnAlmacen.cantidad = 0;

  return productoEnAlmacen;
}

productoEnCarritoDeCompraStruct construirProductoEnCarritoDeCompra() {
  productoEnCarritoDeCompraStruct productoEnCarritoDeCompra;

  productoEnCarritoDeCompra.productoEnAlmacen = NULL;

  productoEnCarritoDeCompra.cantidad = 0;

  return productoEnCarritoDeCompra;
}

clienteRecogiendoCompraStruct construirClienteRecogiendoCompra() {
  clienteRecogiendoCompraStruct clienteRecogiendoCompra;

  clienteRecogiendoCompra.cliente = NULL;

  clienteRecogiendoCompra.fechaDeLLegada = "";

  return clienteRecogiendoCompra;
}

productoCompradoStruct construirproductoComprado(string nombre, string marca,
                                                 string tipo, float precio) {
  productoCompradoStruct productoComprado;

  productoComprado.nombre = nombre;
  productoComprado.marca = marca;
  productoComprado.tipo = tipo;
  productoComprado.precio = precio;

  return productoComprado;
}
