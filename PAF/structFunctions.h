#include "helpers.h"
#include "structs.h"

using namespace std;

// Fabricas

empleadoStruct construirEmpleado(string nombre, string apellidoPaterno,
                                 string apellidoMaterno, bool genero,
                                 string dni, float salario) {
  empleadoStruct empleado;

  empleado.nombre = nombre;
  empleado.apellidoPaterno = apellidoPaterno;
  empleado.apellidoMaterno = apellidoMaterno;
  empleado.genero = genero;
  empleado.dni = dni;
  empleado.salario = salario;

  return empleado;
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

  cliente.productosEnCarritoDeCompra.cabecera = NULL;
  cliente.productosEnCarritoDeCompra.largo = 0;

  return cliente;
}

productoEnAlmacenStruct construirProductoEnAlmacen(string nombre, string marca,
                                                   string tipo, float precio,
                                                   unsigned long stock) {
  productoEnAlmacenStruct productoEnAlmacen;

  productoEnAlmacen.nombre = nombre;
  productoEnAlmacen.marca = marca;
  productoEnAlmacen.tipo = tipo;
  productoEnAlmacen.precio = precio;
  productoEnAlmacen.stock = stock;

  return productoEnAlmacen;
}

productoEnCarritoDeCompraStruct construirProductoEnCarritoDeCompra(
    string nombre, string marca, string tipo, float precio,
    unsigned long cantidad) {
  productoEnCarritoDeCompraStruct productoEnCarritoDeCompra;

  productoEnCarritoDeCompra.nombre = nombre;
  productoEnCarritoDeCompra.marca = marca;
  productoEnCarritoDeCompra.tipo = tipo;
  productoEnCarritoDeCompra.precio = precio;
  productoEnCarritoDeCompra.cantidad = cantidad;

  return productoEnCarritoDeCompra;
}

productoCompradoStruct construirproductoComprado(string nombre, string marca,
                                                 string tipo, float precio,
                                                 unsigned long cantidad) {
  productoCompradoStruct productoComprado;

  productoComprado.nombre = nombre;
  productoComprado.marca = marca;
  productoComprado.tipo = tipo;
  productoComprado.precio = precio;
  productoComprado.cantidad = cantidad;

  return productoComprado;
}

personaRecogiendoCompraStruct construirPersonaRecogiendoCompra(
    string nombre, string apellidoMaterno, string apellidoPaterno, string dni,
    string fechaDeLLegada) {
  personaRecogiendoCompraStruct personaRecogiendoCompra;

  personaRecogiendoCompra.nombre = nombre;
  personaRecogiendoCompra.apellidoMaterno = apellidoMaterno;
  personaRecogiendoCompra.apellidoPaterno = apellidoPaterno;
  personaRecogiendoCompra.dni = dni;
  personaRecogiendoCompra.fechaDeLLegada = fechaDeLLegada;

  return personaRecogiendoCompra;
}

compraStruct construirCompra(string nombreCliente,
                             string apellidoPaternoCliente,
                             string apellidoMaternoCliente, string dniCliente,
                             string fechaDeCompra, string estadoDeCompra) {
  compraStruct compra;

  compra.nombreCliente = nombreCliente;
  compra.apellidoPaternoCliente = apellidoPaternoCliente;
  compra.apellidoMaternoCliente = apellidoMaternoCliente;
  compra.dniCliente = dniCliente;
  compra.fechaDeCompra = fechaDeCompra;
  compra.estadoDeCompra = estadoDeCompra;

  compra.productosComprados.cabecera = NULL;
  compra.productosComprados.largo = 0;

  return compra;
}

almacenStruct construirAlmacen(string departamentoDelPeru, string direccion) {
  almacenStruct almacen;

  almacen.departamentoDelPeru = departamentoDelPeru;
  almacen.direccion = direccion;

  almacen.productosEnAlmacen.cabecera = NULL;
  almacen.productosEnAlmacen.largo = 0;

  almacen.personasRecogiendoCompras.inicio = NULL;
  almacen.personasRecogiendoCompras.fin = NULL;
  almacen.personasRecogiendoCompras.largo = 0;

  return almacen;
}

void construirAlmacenVertice(almacenNodo *aux1, almacenNodo *aux2,
                             almacenVertice *newCityEdge) {
  almacenVertice *temp;

  if (aux1->adyacente == NULL) {
    aux1->adyacente = newCityEdge;
    newCityEdge->destino = aux2;
  } else {
    temp = aux1->adyacente;
    while (temp->siguiente != NULL) {
      temp = temp->siguiente;
    }
    newCityEdge->destino = aux2;
    temp->siguiente = newCityEdge;
  }
}

// Funciones para añadiar a colecciones

void insertar(empleadosLista &empleados, empleadoStruct nuevoEmpleado) {
  empleadoNodo *empleadoNodoPuntero = new empleadoNodo();

  empleadoNodo *ultimoNodo = empleados.cabecera;

  empleadoNodoPuntero->empleado = nuevoEmpleado;
  empleadoNodoPuntero->siguiente = NULL;

  if (empleados.cabecera == NULL) {
    empleados.cabecera = empleadoNodoPuntero;
  } else {
    while (ultimoNodo->siguiente != NULL) {
      ultimoNodo = ultimoNodo->siguiente;
    }

    ultimoNodo->siguiente = empleadoNodoPuntero;
  }

  empleados.largo++;
}

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

void encolar(personasRecogiendoComprasCola &personasRecogiendoCompras,
             personaRecogiendoCompraStruct nuevoPersonaRecogiendoCompra) {
  personaRecogiendoCompraNodo *clienteRecogiendoCompraNodoPuntero =
      new personaRecogiendoCompraNodo;

  clienteRecogiendoCompraNodoPuntero->personaRecogiendoCompra =
      nuevoPersonaRecogiendoCompra;
  clienteRecogiendoCompraNodoPuntero->siguiente = NULL;

  if (personasRecogiendoCompras.inicio == NULL) {
    personasRecogiendoCompras.inicio = clienteRecogiendoCompraNodoPuntero;
  } else {
    personasRecogiendoCompras.fin->siguiente =
        clienteRecogiendoCompraNodoPuntero;
  }

  personasRecogiendoCompras.fin = clienteRecogiendoCompraNodoPuntero;
  personasRecogiendoCompras.largo++;
}

personaRecogiendoCompraStruct desencolarClienteRecogiendoCompra(
    personasRecogiendoComprasCola &clientesRecogiendoCompras) {
  personaRecogiendoCompraNodo *personaRecogiendoCompraNodoPuntero;
  personaRecogiendoCompraStruct personaRecogiendoCompraBorrado;

  personaRecogiendoCompraNodoPuntero = clientesRecogiendoCompras.inicio;
  personaRecogiendoCompraBorrado =
      personaRecogiendoCompraNodoPuntero->personaRecogiendoCompra;

  clientesRecogiendoCompras.inicio =
      clientesRecogiendoCompras.inicio->siguiente;
  clientesRecogiendoCompras.largo--;

  delete personaRecogiendoCompraNodoPuntero;

  return personaRecogiendoCompraBorrado;
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
  deltron.empleados.cabecera = NULL;
  deltron.empleados.largo = 0;

  deltron.clientes.cabecera = NULL;
  deltron.clientes.largo = 0;

  deltron.compras.cabecera = NULL;
  deltron.compras.largo = 0;

  deltron.almacenes.nodo = NULL;
  deltron.almacenes.vertice = NULL;
  deltron.almacenes.largo = 0;
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
  cout << "Departamento";
  gotoxy(25, y);
  cout << "Dirección";
}

void imprimirAlmacen(almacenStruct almacen, int n, int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << almacen.departamentoDelPeru;
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
  cout << "Stock";
}

void imprimirProductoEnAlmacen(productoEnAlmacenStruct productoEnAlmacen, int n,
                               int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << productoEnAlmacen.tipo;
  gotoxy(25, y);
  cout << productoEnAlmacen.marca;
  gotoxy(45, y);
  cout << productoEnAlmacen.nombre;
  gotoxy(70, y);
  cout << productoEnAlmacen.precio;
  gotoxy(80, y);
  cout << productoEnAlmacen.stock;
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
  cout << productoEnCarritoDeCompra.tipo;
  gotoxy(25, y);
  cout << productoEnCarritoDeCompra.marca;
  gotoxy(45, y);
  cout << productoEnCarritoDeCompra.nombre;
  gotoxy(70, y);
  cout << productoEnCarritoDeCompra.precio;
  gotoxy(80, y);
  cout << productoEnCarritoDeCompra.cantidad;
}

void imprimirCabeceraPersonasRecogiendoCompras(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Nombres";
  gotoxy(30, y);
  cout << "Apellidos";
  gotoxy(55, y);
  cout << "DNI";
  gotoxy(65, y);
  cout << "Fecha de LLegada";
}

void imprimirPersonaRecogiendoCompra(
    personaRecogiendoCompraStruct personaRecogiendoCompra, int n, int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << personaRecogiendoCompra.nombre;
  gotoxy(30, y);
  cout << personaRecogiendoCompra.apellidoPaterno << " "
       << personaRecogiendoCompra.apellidoMaterno;
  gotoxy(55, y);
  cout << personaRecogiendoCompra.dni;
  gotoxy(65, y);
  cout << personaRecogiendoCompra.fechaDeLLegada;
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
  gotoxy(80, y);
  cout << "Cliente DNI";
}

void imprimirCompra(compraStruct compra, int n, int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << compra.estadoDeCompra;
  gotoxy(25, y);
  cout << compra.fechaDeCompra;
  gotoxy(40, y);
  cout << compra.apellidoPaternoCliente << " " << compra.apellidoMaternoCliente
       << " " << compra.nombreCliente;
  gotoxy(80, y);
  cout << compra.dniCliente;
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
