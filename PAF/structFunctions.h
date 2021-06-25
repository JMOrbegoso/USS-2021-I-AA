#include "helpers.h"
#include "structs.h"

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

compraStruct construirCompra(clienteNodo *clientePuntero, string fecha,
                             string estado) {
  compraStruct compra;

  if (clientePuntero == NULL) throw exception();

  compra.cliente = clientePuntero;

  compra.fecha = fecha;
  compra.estado = estado;

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

void inicializacionDeData(deltronStruct &deltron) {
  productoStruct producto_01, producto_02, producto_03;
  clienteStruct cliente_01, cliente_02;
  almacenStruct almacen_01, almacen_02, almacen_03;
  almacenNodo *almacenNodoPuntero_1 = new almacenNodo();
  almacenNodo *almacenNodoPuntero_2 = new almacenNodo();
  almacenNodo *almacenNodoPuntero_3 = new almacenNodo();
  productoEnAlmacenStruct productoEnAlmacen_01, productoEnAlmacen_02,
      productoEnAlmacen_03;
  productoEnCarritoDeCompraStruct productoEnCarritoDeCompra_01;
  clienteRecogiendoCompraStruct clienteRecogiendoCompra_01;
  compraStruct compra_01;

  deltron.razonSocial = "Deltron SAC";
  deltron.ruc = "12345678910";

  // Init productos
  producto_01 = construirProducto("i7 10700K", "Intel", "CPU", 1900);
  producto_02 = construirProducto("Ryzen 7 3700", "AMD", "CPU", 1700);
  producto_03 = construirProducto("GeForce 1030", "Nvidia", "GPU", 400);

  insertar(deltron.productos, producto_01);
  insertar(deltron.productos, producto_02);
  insertar(deltron.productos, producto_03);

  // Init clientes
  cliente_01 = construirCliente("Tulio", "Rioja", "Ramos", 'm', "11111111");
  cliente_02 =
      construirCliente("Valery", "Marquez", "Gonzales", 'f', "22222222");

  insertar(deltron.clientes, cliente_01);
  insertar(deltron.clientes, cliente_02);

  // Init almacenes
  almacen_01 = construirAlmacen("Almacen Chiclayo", "Av. Chiclayo 747");
  almacen_02 = construirAlmacen("Almacen Trujillo", "Av. Trujillo 747");
  almacen_03 = construirAlmacen("Almacen Lima", "Av. Lima 747");

  productoEnAlmacen_01 = construirProductoEnAlmacen(
      buscarProductoPorNombre(deltron.productos, "i7 10700K"), 10);
  productoEnAlmacen_02 = construirProductoEnAlmacen(
      buscarProductoPorNombre(deltron.productos, "Ryzen 7 3700"), 15);
  productoEnAlmacen_03 = construirProductoEnAlmacen(
      buscarProductoPorNombre(deltron.productos, "GeForce 1030"), 20);

  insertar(almacen_01.productosEnAlmacen, productoEnAlmacen_01);
  insertar(almacen_01.productosEnAlmacen, productoEnAlmacen_02);
  insertar(almacen_01.productosEnAlmacen, productoEnAlmacen_03);

  almacenNodoPuntero_1->almacen = almacen_01;
  almacenNodoPuntero_2->almacen = almacen_02;
  almacenNodoPuntero_3->almacen = almacen_03;

  deltron.almacenes.chiclayo = almacenNodoPuntero_1;
  deltron.almacenes.trujillo = almacenNodoPuntero_2;
  deltron.almacenes.lima = almacenNodoPuntero_3;

  // Inicializar carritos de compra
  productoEnCarritoDeCompra_01 = construirProductoEnCarritoDeCompra(
      buscarProductoEnAlmacenPorNombre(
          deltron.almacenes.chiclayo->almacen.productosEnAlmacen, "i7 10700K"),
      2);
  apilar(buscarClientePorDni(deltron.clientes, "11111111")
             ->cliente.productosEnCarritoDeCompra,
         productoEnCarritoDeCompra_01);

  // Inicializar clientes recogiendo compras
  clienteRecogiendoCompra_01 = construirClienteRecogiendoCompra(
      buscarClientePorDni(deltron.clientes, "11111111"), "2021-06-22 10:30:00");
  encolar(deltron.almacenes.chiclayo->almacen.clientesRecogiendoCompras,
          clienteRecogiendoCompra_01);

  // Inicializar Compras realizadas
  compra_01 = construirCompra(buscarClientePorDni(deltron.clientes, "11111111"),
                              "2021-06-20 10:00:00", "Recogida");

  insertar(deltron.compras, compra_01);
}

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
  cout << "Cliente nombre completo";
  gotoxy(75, y);
  cout << "Cliente DNI";
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
       << compra.cliente->cliente.apellidoPaterno << " "
       << compra.cliente->cliente.nombre;
  gotoxy(75, y);
  cout << compra.cliente->cliente.dni;
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
