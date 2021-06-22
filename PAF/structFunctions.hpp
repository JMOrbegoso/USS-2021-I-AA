#include "helpers.hpp"
#include "structs.hpp"

using namespace std;

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
                               string apellidoMaterno, char genero,
                               string dni) {
  clienteStruct cliente;

  cliente.nombre = nombre;
  cliente.apellidoPaterno = apellidoPaterno;
  cliente.apellidoMaterno = apellidoMaterno;
  cliente.genero = genero;
  cliente.dni = dni;

  cliente.productosEnCarritoDeCompra.cabecera = NULL;
  cliente.productosEnCarritoDeCompra.largo = 0;

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

productoEnAlmacenStruct construirProductoEnAlmacen(
    productoNodo *productoPuntero, unsigned long cantidad) {
  productoEnAlmacenStruct productoEnAlmacen;

  if (productoPuntero == NULL) throw exception();

  productoEnAlmacen.producto = productoPuntero;
  productoEnAlmacen.cantidad = cantidad;

  return productoEnAlmacen;
}

productoEnCarritoDeCompraStruct construirProductoEnCarritoDeCompra(
    productoEnAlmacenNodo *productoEnAlmacenPuntero, unsigned long cantidad) {
  productoEnCarritoDeCompraStruct productoEnCarritoDeCompra;

  if (productoEnAlmacenPuntero == NULL) throw exception();

  productoEnCarritoDeCompra.productoEnAlmacen = productoEnAlmacenPuntero;
  productoEnCarritoDeCompra.cantidad = cantidad;

  return productoEnCarritoDeCompra;
}

clienteRecogiendoCompraStruct construirClienteRecogiendoCompra(
    clienteNodo *clientePuntero, string fechaDeLLegada) {
  clienteRecogiendoCompraStruct clienteRecogiendoCompra;

  if (clientePuntero == NULL) throw exception();

  clienteRecogiendoCompra.cliente = clientePuntero;
  clienteRecogiendoCompra.fechaDeLLegada = fechaDeLLegada;

  return clienteRecogiendoCompra;
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

void encolar(clientesRecogiendoComprasCola &clientesRecogiendoCompras,
             clienteRecogiendoCompraStruct nuevoClienteRecogiendoCompra) {
  clienteRecogiendoCompraNodo *clienteRecogiendoCompraNodoPuntero =
      new clienteRecogiendoCompraNodo;

  clienteRecogiendoCompraNodoPuntero->clienteRecogiendoCompra =
      nuevoClienteRecogiendoCompra;
  clienteRecogiendoCompraNodoPuntero->siguiente = NULL;

  if (clientesRecogiendoCompras.inicio == NULL) {
    clientesRecogiendoCompras.inicio = clienteRecogiendoCompraNodoPuntero;
  } else {
    clientesRecogiendoCompras.fin->siguiente =
        clienteRecogiendoCompraNodoPuntero;
  }

  clientesRecogiendoCompras.fin = clienteRecogiendoCompraNodoPuntero;
  clientesRecogiendoCompras.largo++;
}

clienteRecogiendoCompraStruct desencolarClienteRecogiendoCompra(
    clientesRecogiendoComprasCola &clientesRecogiendoCompras) {
  clienteRecogiendoCompraNodo *clienteRecogiendoCompraNodoPuntero;
  clienteRecogiendoCompraStruct clienteRecogiendoCompraBorrado;

  clienteRecogiendoCompraNodoPuntero = clientesRecogiendoCompras.inicio;
  clienteRecogiendoCompraBorrado =
      clienteRecogiendoCompraNodoPuntero->clienteRecogiendoCompra;

  clientesRecogiendoCompras.inicio =
      clientesRecogiendoCompras.inicio->siguiente;
  clientesRecogiendoCompras.largo--;

  delete clienteRecogiendoCompraNodoPuntero;

  return clienteRecogiendoCompraBorrado;
}

void apilar(productosEnCarritoDeCompraPila &productosEnCarritoDeCompra,
            productoEnCarritoDeCompraStruct nuevoProductoEnCarritoDeCompra) {
  productoEnCarritoDeCompraNodo *productoEnCarritoDeCompraNodoPuntero =
      new productoEnCarritoDeCompraNodo();

  productoEnCarritoDeCompraNodoPuntero->productoEnCarritoDeCompra =
      nuevoProductoEnCarritoDeCompra;
  productoEnCarritoDeCompraNodoPuntero->siguiente =
      productosEnCarritoDeCompra.cabecera;

  productosEnCarritoDeCompra.cabecera = productoEnCarritoDeCompraNodoPuntero;
  productosEnCarritoDeCompra.largo++;
}

void desapilar(productosEnCarritoDeCompraPila &productosEnCarritoDeCompra) {
  productoEnCarritoDeCompraNodo *productoEnCarritoDeCompraNodoPuntero;
  productoEnCarritoDeCompraStruct productoEnCarritoDeCompraBorrado;

  productoEnCarritoDeCompraNodoPuntero = productosEnCarritoDeCompra.cabecera;
  productoEnCarritoDeCompraBorrado =
      productoEnCarritoDeCompraNodoPuntero->productoEnCarritoDeCompra;

  productosEnCarritoDeCompra.cabecera =
      productosEnCarritoDeCompra.cabecera->siguiente;
  productosEnCarritoDeCompra.largo--;

  delete productoEnCarritoDeCompraNodoPuntero;
}

// iteradores

clienteNodo *buscarClientePorDni(clientesLista clientes, string dni) {
  clienteNodo *punteroIterador = clientes.cabecera;

  while (punteroIterador != NULL) {
    if (punteroIterador->cliente.dni == dni)
      return punteroIterador;
    else
      punteroIterador = punteroIterador->siguiente;
  }
  return NULL;
}

productoNodo *buscarProductoPorNombre(productosLista productos, string nombre) {
  productoNodo *punteroIterador = productos.cabecera;

  while (punteroIterador != NULL) {
    if (punteroIterador->producto.nombre == nombre)
      return punteroIterador;
    else
      punteroIterador = punteroIterador->siguiente;
  }
  return NULL;
}

productoEnAlmacenNodo *buscarProductoEnAlmacenPorNombre(
    productosEnAlmacenLista productos, string nombre) {
  productoEnAlmacenNodo *punteroIterador = productos.cabecera;

  while (punteroIterador != NULL) {
    if (punteroIterador->productoEnAlmacen.producto->producto.nombre == nombre)
      return punteroIterador;
    else
      punteroIterador = punteroIterador->siguiente;
  }
  return NULL;
}

// Inicializadores

void inicializacionDeColecciones(deltronStruct &deltron) {
  deltron.clientes.cabecera = NULL;
  deltron.clientes.largo = 0;

  deltron.compras.cabecera = NULL;
  deltron.compras.largo = 0;

  deltron.productos.cabecera = NULL;
  deltron.productos.largo = 0;

  deltron.almacenes.chiclayo = NULL;
  deltron.almacenes.trujillo = NULL;
  deltron.almacenes.lima = NULL;
}

void inicializacionDeData(deltronStruct &deltron) {}

// Impresores

void imprimirCabeceraProductos(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Tipo";
  gotoxy(25, y);
  cout << "Marca";
  gotoxy(45, y);
  cout << "Nombre";
  gotoxy(70, y);
  cout << "Precio";
}

void imprimirProducto(productoStruct producto, int n, int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << producto.tipo;
  gotoxy(25, y);
  cout << producto.marca;
  gotoxy(45, y);
  cout << producto.nombre;
  gotoxy(70, y);
  cout << producto.precio;
}

void imprimirCabeceraClientes(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Apellidos";
  gotoxy(25, y);
  cout << "Nombres";
  gotoxy(50, y);
  cout << "DNI";
  gotoxy(70, y);
  cout << "Genero";
}

void imprimirCliente(clienteStruct cliente, int n, int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << cliente.apellidoPaterno << " " << cliente.apellidoMaterno;
  gotoxy(25, y);
  cout << cliente.nombre;
  gotoxy(50, y);
  cout << cliente.dni;
  gotoxy(70, y);
  cout << getGenre(cliente.genero);
}

void imprimirCabeceraAlmacenes(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Nombre";
  gotoxy(25, y);
  cout << "Dirección";
}

void imprimirAlmacen(almacenStruct almacen, int n, int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << almacen.nombre;
  gotoxy(25, y);
  cout << almacen.direccion;
}

void imprimirCabeceraProductoEnAlmacen(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Tipo";
  gotoxy(25, y);
  cout << "Marca";
  gotoxy(45, y);
  cout << "Nombre";
  gotoxy(70, y);
  cout << "Precio";
  gotoxy(80, y);
  cout << "Cantidad";
}

void imprimirProductoEnAlmacen(productoEnAlmacenStruct productoEnAlmacen, int n,
                               int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << productoEnAlmacen.producto->producto.tipo;
  gotoxy(25, y);
  cout << productoEnAlmacen.producto->producto.marca;
  gotoxy(45, y);
  cout << productoEnAlmacen.producto->producto.nombre;
  gotoxy(70, y);
  cout << productoEnAlmacen.producto->producto.precio;
  gotoxy(80, y);
  cout << productoEnAlmacen.cantidad;
}

void imprimirCabeceraProductosEnCarritoDeCompra(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Tipo";
  gotoxy(25, y);
  cout << "Marca";
  gotoxy(45, y);
  cout << "Nombre";
  gotoxy(70, y);
  cout << "Precio";
  gotoxy(80, y);
  cout << "Cantidad";
}

void imprimirProductoEnCarritoDeCompra(
    productoEnCarritoDeCompraStruct productoEnCarritoDeCompra, int n, int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << productoEnCarritoDeCompra.productoEnAlmacen->productoEnAlmacen
              .producto->producto.tipo;
  gotoxy(25, y);
  cout << productoEnCarritoDeCompra.productoEnAlmacen->productoEnAlmacen
              .producto->producto.marca;
  gotoxy(45, y);
  cout << productoEnCarritoDeCompra.productoEnAlmacen->productoEnAlmacen
              .producto->producto.nombre;
  gotoxy(70, y);
  cout << productoEnCarritoDeCompra.productoEnAlmacen->productoEnAlmacen
              .producto->producto.precio;
  gotoxy(80, y);
  cout << productoEnCarritoDeCompra.cantidad;
}

void imprimirCabeceraClientesRecogiendoCompra(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Nombres";
  gotoxy(30, y);
  cout << "Apellidos";
  gotoxy(55, y);
  cout << "DNI";
  gotoxy(65, y);
  cout << "Genero";
  gotoxy(85, y);
  cout << "Fecha de LLegada";
}

void imprimirClienteRecogiendoCompra(
    clienteRecogiendoCompraStruct clienteRecogiendoCompra, int n, int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << clienteRecogiendoCompra.cliente->cliente.nombre;
  gotoxy(30, y);
  cout << clienteRecogiendoCompra.cliente->cliente.apellidoPaterno << " "
       << clienteRecogiendoCompra.cliente->cliente.apellidoMaterno;
  gotoxy(55, y);
  cout << clienteRecogiendoCompra.cliente->cliente.dni;
  gotoxy(65, y);
  cout << getGenre(clienteRecogiendoCompra.cliente->cliente.genero);
  gotoxy(85, y);
  cout << clienteRecogiendoCompra.fechaDeLLegada;
}

void imprimirCabeceraCompra(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Estado";
  gotoxy(25, y);
  cout << "Fecha";
  gotoxy(40, y);
  cout << "Cliente";
}

void imprimirCompra(compraStruct compra, int n, int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << compra.estado;
  gotoxy(25, y);
  cout << compra.fecha;
  gotoxy(40, y);
  cout << compra.cliente->cliente.apellidoPaterno << " "
       << compra.cliente->cliente.apellidoPaterno
       << compra.cliente->cliente.nombre;
}

void imprimirCabeceraProductoComprado(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Tipo";
  gotoxy(25, y);
  cout << "Marca";
  gotoxy(45, y);
  cout << "Nombre";
  gotoxy(70, y);
  cout << "Precio";
  gotoxy(80, y);
  cout << "Cantidad";
}

void imprimirProductoComprado(productoCompradoStruct productoComprado, int n,
                              int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << productoComprado.tipo;
  gotoxy(25, y);
  cout << productoComprado.marca;
  gotoxy(45, y);
  cout << productoComprado.precio;
  gotoxy(70, y);
  cout << productoComprado.precio;
  gotoxy(80, y);
  cout << productoComprado.cantidad;
}
