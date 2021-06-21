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

// Funciones para añadiar a colecciones

void insertar(clientesLista &clientes, clienteStruct nuevoCliente) {
  clienteNodo *clienteNodoPuntero = new clienteNodo();

  clienteNodo *ultimoNodo = clientes.cabecera;

  clienteNodoPuntero->cliente = nuevoCliente;
  clienteNodoPuntero->siguiente = NULL;

  if (clientes.cabecera == NULL) {
    clientes.cabecera = clienteNodoPuntero;
  } else {
    while (ultimoNodo->siguiente != NULL) {
      ultimoNodo = ultimoNodo->siguiente;
    }

    ultimoNodo->siguiente = clienteNodoPuntero;
  }

  clientes.largo++;
}

void insertar(productosLista &productos, productoStruct nuevoProducto) {
  productoNodo *productoNodoPuntero = new productoNodo();

  productoNodo *ultimoNodo = productos.cabecera;

  productoNodoPuntero->producto = nuevoProducto;
  productoNodoPuntero->siguiente = NULL;

  if (productos.cabecera == NULL) {
    productos.cabecera = productoNodoPuntero;
  } else {
    while (ultimoNodo->siguiente != NULL) {
      ultimoNodo = ultimoNodo->siguiente;
    }

    ultimoNodo->siguiente = productoNodoPuntero;
  }

  productos.largo++;
}

void insertar(productosCompradosLista &productosComprados,
              productoCompradoStruct nuevoProductoComprado) {
  productoCompradoNodo *productoCompradoNodoPuntero =
      new productoCompradoNodo();

  productoCompradoNodo *ultimoNodo = productosComprados.cabecera;

  productoCompradoNodoPuntero->productoComprado = nuevoProductoComprado;
  productoCompradoNodoPuntero->siguiente = NULL;

  if (productosComprados.cabecera == NULL) {
    productosComprados.cabecera = productoCompradoNodoPuntero;
  } else {
    while (ultimoNodo->siguiente != NULL) {
      ultimoNodo = ultimoNodo->siguiente;
    }

    ultimoNodo->siguiente = productoCompradoNodoPuntero;
  }

  productosComprados.largo++;
}

void insertar(productosEnAlmacenLista &productosEnAlmacen,
              productoEnAlmacenStruct nuevoProductoEnAlmacen) {
  productoEnAlmacenNodo *productoEnAlmacenNodoPuntero =
      new productoEnAlmacenNodo();

  productoEnAlmacenNodo *ultimoNodo = productosEnAlmacen.cabecera;

  productoEnAlmacenNodoPuntero->productoEnAlmacen = nuevoProductoEnAlmacen;
  productoEnAlmacenNodoPuntero->siguiente = NULL;

  if (productosEnAlmacen.cabecera == NULL) {
    productosEnAlmacen.cabecera = productoEnAlmacenNodoPuntero;
  } else {
    while (ultimoNodo->siguiente != NULL) {
      ultimoNodo = ultimoNodo->siguiente;
    }

    ultimoNodo->siguiente = productoEnAlmacenNodoPuntero;
  }

  productosEnAlmacen.largo++;
}

void insertar(comprasLista &compras, compraStruct nuevaCompra) {
  compraNodo *compraNodoPuntero = new compraNodo();

  compraNodo *ultimoNodo = compras.cabecera;

  compraNodoPuntero->compra = nuevaCompra;
  compraNodoPuntero->siguiente = NULL;

  if (compras.cabecera == NULL) {
    compras.cabecera = compraNodoPuntero;
  } else {
    while (ultimoNodo->siguiente != NULL) {
      ultimoNodo = ultimoNodo->siguiente;
    }

    ultimoNodo->siguiente = compraNodoPuntero;
  }

  compras.largo++;
}