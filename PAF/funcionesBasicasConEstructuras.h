#include "basicas.h"
#include "estructuras.h"

using namespace std;

// Fabricas

empleadoStruct construirEmpleado(string dni, string claveDeAcceso,
                                 string nombres, string apellidos, bool genero,
                                 float salario) {
  empleadoStruct empleado;

  empleado.dni = dni;
  empleado.claveDeAcceso = claveDeAcceso;
  empleado.nombres = nombres;
  empleado.apellidos = apellidos;
  empleado.genero = genero;
  empleado.salario = salario;

  return empleado;
}

clienteStruct construirCliente(string dni, string claveDeAcceso, string nombres,
                               string apellidos, bool genero) {
  clienteStruct cliente;

  cliente.dni = dni;
  cliente.claveDeAcceso = claveDeAcceso;
  cliente.nombres = nombres;
  cliente.apellidos = apellidos;
  cliente.genero = genero;

  cliente.productosEnCarritoDeCompra.cabecera = NULL;
  cliente.productosEnCarritoDeCompra.largo = 0;

  return cliente;
}

productoEnAlmacenStruct construirProductoEnAlmacen(string codigo, string nombre,
                                                   string marca, string tipo,
                                                   float precio,
                                                   unsigned long stock) {
  productoEnAlmacenStruct productoEnAlmacen;

  productoEnAlmacen.codigo = codigo;
  productoEnAlmacen.nombre = nombre;
  productoEnAlmacen.marca = marca;
  productoEnAlmacen.tipo = tipo;
  productoEnAlmacen.precio = precio;
  productoEnAlmacen.stock = stock;

  return productoEnAlmacen;
}

productoEnCarritoDeCompraStruct construirProductoEnCarritoDeCompra(
    string codigo, string nombre, string marca, string tipo, float precio,
    unsigned long cantidad) {
  productoEnCarritoDeCompraStruct productoEnCarritoDeCompra;

  productoEnCarritoDeCompra.codigo = codigo;
  productoEnCarritoDeCompra.nombre = nombre;
  productoEnCarritoDeCompra.marca = marca;
  productoEnCarritoDeCompra.tipo = tipo;
  productoEnCarritoDeCompra.precio = precio;
  productoEnCarritoDeCompra.cantidad = cantidad;

  return productoEnCarritoDeCompra;
}

productoVendidoStruct construirProductoVendido(string codigo, string nombre,
                                               string marca, string tipo,
                                               float precio,
                                               unsigned long cantidad) {
  productoVendidoStruct productoVendido;

  productoVendido.codigo = codigo;
  productoVendido.nombre = nombre;
  productoVendido.marca = marca;
  productoVendido.tipo = tipo;
  productoVendido.precio = precio;
  productoVendido.cantidad = cantidad;

  return productoVendido;
}

personaRecogiendoCompraStruct construirPersonaRecogiendoCompra(
    string nombres, string apellidos, string dni, string fechaDeLLegada) {
  personaRecogiendoCompraStruct personaRecogiendoCompra;

  personaRecogiendoCompra.nombres = nombres;
  personaRecogiendoCompra.apellidos = apellidos;
  personaRecogiendoCompra.dni = dni;
  personaRecogiendoCompra.fechaDeLLegada = fechaDeLLegada;

  return personaRecogiendoCompra;
}

ventaStruct construirVenta(string nombresCliente, string apellidosCliente,
                           string dniCliente, string fechaDeVenta,
                           string estadoDeVenta) {
  ventaStruct venta;

  venta.nombresCliente = nombresCliente;
  venta.apellidosCliente = apellidosCliente;
  venta.dniCliente = dniCliente;
  venta.fechaDeVenta = fechaDeVenta;
  venta.estadoDeVenta = estadoDeVenta;

  venta.productosVendidos.cabecera = NULL;
  venta.productosVendidos.largo = 0;

  return venta;
}

almacenStruct construirAlmacen(string codigoAlmacen, string departamentoDelPeru,
                               string direccion) {
  almacenStruct almacen;

  almacen.codigoAlmacen = codigoAlmacen;
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
                             almacenVertice *nuevoVertice) {
  almacenVertice *temp;

  if (aux1->adyacente == NULL) {
    aux1->adyacente = nuevoVertice;
    nuevoVertice->destino = aux2;
  } else {
    temp = aux1->adyacente;
    while (temp->siguiente != NULL) {
      temp = temp->siguiente;
    }
    nuevoVertice->destino = aux2;
    temp->siguiente = nuevoVertice;
  }
}

// Funciones para a??adiar a colecciones

void insertar(almacenesGrafo &almacenes, almacenStruct nuevoAlmacen) {
  almacenNodo *almacenNodoPuntero = new almacenNodo();

  almacenNodo *ultimoNodo = almacenes.nodo;

  almacenNodoPuntero->almacen = nuevoAlmacen;
  almacenNodoPuntero->siguiente = NULL;

  if (almacenes.nodo == NULL) {
    almacenes.nodo = almacenNodoPuntero;
  } else {
    while (ultimoNodo->siguiente != NULL) {
      ultimoNodo = ultimoNodo->siguiente;
    }

    ultimoNodo->siguiente = almacenNodoPuntero;
  }

  almacenes.largo++;
}

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

void insertar(productosVendidosLista &productosVendidos,
              productoVendidoStruct nuevoProductoVendido) {
  productoVendidoNodo *productoVendidoNodoPuntero = new productoVendidoNodo();

  productoVendidoNodo *ultimoNodo = productosVendidos.cabecera;

  productoVendidoNodoPuntero->productoVendido = nuevoProductoVendido;
  productoVendidoNodoPuntero->siguiente = NULL;

  if (productosVendidos.cabecera == NULL) {
    productosVendidos.cabecera = productoVendidoNodoPuntero;
  } else {
    while (ultimoNodo->siguiente != NULL) {
      ultimoNodo = ultimoNodo->siguiente;
    }

    ultimoNodo->siguiente = productoVendidoNodoPuntero;
  }

  productosVendidos.largo++;
}

void insertar(ventasLista &ventas, ventaStruct nuevaVenta) {
  ventaNodo *ventaNodoPuntero = new ventaNodo();

  ventaNodo *ultimoNodo = ventas.cabecera;

  ventaNodoPuntero->venta = nuevaVenta;
  ventaNodoPuntero->siguiente = NULL;

  if (ventas.cabecera == NULL) {
    ventas.cabecera = ventaNodoPuntero;
  } else {
    while (ultimoNodo->siguiente != NULL) {
      ultimoNodo = ultimoNodo->siguiente;
    }

    ultimoNodo->siguiente = ventaNodoPuntero;
  }

  ventas.largo++;
}

void encolar(personasRecogiendoComprasCola &personasRecogiendoCompras,
             personaRecogiendoCompraStruct nuevoPersonaRecogiendoCompra) {
  personaRecogiendoCompraNodo *personaRecogiendoCompraNodoPuntero =
      new personaRecogiendoCompraNodo;

  personaRecogiendoCompraNodoPuntero->personaRecogiendoCompra =
      nuevoPersonaRecogiendoCompra;
  personaRecogiendoCompraNodoPuntero->siguiente = NULL;

  if (personasRecogiendoCompras.inicio == NULL) {
    personasRecogiendoCompras.inicio = personaRecogiendoCompraNodoPuntero;
  } else {
    personasRecogiendoCompras.fin->siguiente =
        personaRecogiendoCompraNodoPuntero;
  }

  personasRecogiendoCompras.fin = personaRecogiendoCompraNodoPuntero;
  personasRecogiendoCompras.largo++;
}

personaRecogiendoCompraStruct desencolarPersonaRecogiendoCompra(
    personasRecogiendoComprasCola &personasRecogiendoCompras) {
  personaRecogiendoCompraNodo *personaRecogiendoCompraNodoPuntero;
  personaRecogiendoCompraStruct personaRecogiendoCompraBorrado;

  personaRecogiendoCompraNodoPuntero = personasRecogiendoCompras.inicio;
  personaRecogiendoCompraBorrado =
      personaRecogiendoCompraNodoPuntero->personaRecogiendoCompra;

  personasRecogiendoCompras.inicio =
      personasRecogiendoCompras.inicio->siguiente;
  personasRecogiendoCompras.largo--;

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

// Inicializadores

void inicializacionDeColecciones(deltronStruct &deltron) {
  deltron.empleados.cabecera = NULL;
  deltron.empleados.largo = 0;

  deltron.clientes.cabecera = NULL;
  deltron.clientes.largo = 0;

  deltron.ventas.cabecera = NULL;
  deltron.ventas.largo = 0;

  deltron.almacenes.nodo = NULL;
  deltron.almacenes.vertice = NULL;
  deltron.almacenes.largo = 0;
}

void inicializacionDeData(deltronStruct &deltron) {
  almacenStruct almacenLima, almacenTrujillo, almacenChiclayo;
  empleadoStruct empleado01, empleado02;
  clienteStruct cliente01, cliente02;
  productoEnAlmacenStruct productoEnAlmacen01, productoEnAlmacen02,
      productoEnAlmacen03;
  productoEnCarritoDeCompraStruct productoEnCarritoDeCompra01;
  ventaStruct venta01;
  productoVendidoStruct productoVendido01, productoVendido02;
  personaRecogiendoCompraStruct personaRecogiendoCompra01;

  deltron.razonSocial = "Deltron SAC";
  deltron.ruc = "12345678910";

  // Construir empleados
  empleado01 = construirEmpleado("11111111", "123456", "Jorge",
                                 "Gonzales Rojas", true, 2000);
  empleado02 = construirEmpleado("22222222", "123456", "Miguel", "Ramos Lopez",
                                 true, 2000);

  // Construir clientes
  cliente01 =
      construirCliente("12121212", "123456", "Tulio", "Ramos Lopez", true);
  cliente02 = construirCliente("13131313", "123456", "Valery",
                               "Marquez Gonzales", false);

  // Construir productos en almacen
  productoEnAlmacen01 = construirProductoEnAlmacen(
      "intel-i7-10700K", "i7 10700K", "Intel", "CPU", 1900, 10);
  productoEnAlmacen02 = construirProductoEnAlmacen(
      "amd-ryzen7-3700", "Ryzen 7 3700", "AMD", "CPU", 1700, 15);
  productoEnAlmacen03 = construirProductoEnAlmacen(
      "nvidia-geforce-1030", "GeForce 1030", "Nvidia", "GPU", 400, 20);

  // Construir producto en carrito de compra
  productoEnCarritoDeCompra01 = construirProductoEnCarritoDeCompra(
      "intel-i7-10700K", "i7 10700K", "Intel", "CPU", 1900, 1);

  // Construir personas recogiendo compra
  personaRecogiendoCompra01 = construirPersonaRecogiendoCompra(
      "Jorge", "Martinez", "15151515", "2021-06-30 10:00:00");

  // Construir productos comprados
  productoVendido01 = construirProductoVendido(
      "nvidia-geforce-1030", "GeForce 1030", "Nvidia", "GPU", 400, 1);
  productoVendido02 = construirProductoVendido("wd-black-sd400", "Black SD400",
                                               "WD", "Disco Duro", 380, 1);

  // Construir ventas realizadas
  venta01 = construirVenta("Tulio", "Ramos Lopez", "12121212",
                           "2021-06-20 10:00:00", "Recogida");

  // Construir almacenes
  almacenLima = construirAlmacen("lima1", "Lima", "Av. Lima 747");
  almacenTrujillo =
      construirAlmacen("trujillo1", "Trujillo", "Av. Trujillo 747");
  almacenChiclayo =
      construirAlmacen("chiclayo1", "Chiclayo", "Av. Chiclayo 747");

  // Insertar empleados
  insertar(deltron.empleados, empleado01);
  insertar(deltron.empleados, empleado02);

  // Insertar productos en almacen
  insertar(almacenLima.productosEnAlmacen, productoEnAlmacen01);
  insertar(almacenLima.productosEnAlmacen, productoEnAlmacen02);
  insertar(almacenLima.productosEnAlmacen, productoEnAlmacen03);

  // Insertar producto en carrito de compra
  apilar(cliente01.productosEnCarritoDeCompra, productoEnCarritoDeCompra01);

  // Insertar personas recogiendo compra
  encolar(almacenLima.personasRecogiendoCompras, personaRecogiendoCompra01);

  // Insertar clientes
  insertar(deltron.clientes, cliente01);
  insertar(deltron.clientes, cliente02);

  // Insertar productos comprados
  insertar(venta01.productosVendidos, productoVendido01);
  insertar(venta01.productosVendidos, productoVendido02);

  // Insertar ventas realizadas
  insertar(deltron.ventas, venta01);

  // Insertar almacenes
  insertar(deltron.almacenes, almacenLima);
  insertar(deltron.almacenes, almacenTrujillo);
  insertar(deltron.almacenes, almacenChiclayo);
}

// Buscadores/Iteradores

almacenNodo *iterarGrafoAlmacenes(almacenesGrafo almacenes, int index) {
  almacenNodo *almacenNodoPuntero;

  if (0 >= index) {
    return NULL;
  }

  if (index > almacenes.largo) {
    return NULL;
  }

  almacenNodoPuntero = almacenes.nodo;

  for (int i = 1; almacenNodoPuntero != NULL; i++) {
    if (i == index) {
      return almacenNodoPuntero;
    }
    almacenNodoPuntero = almacenNodoPuntero->siguiente;
  }

  return NULL;
}

almacenNodo *pedirAlmacen(almacenesGrafo almacenes, string mensaje) {
  int selectedOption;
  almacenNodo *almacenNodoPuntero;

  cout << endl
       << mensaje << "." << endl
       << "Escoja entre los " << almacenes.largo
       << " almacenes siguientes:" << endl
       << endl;

  almacenNodoPuntero = almacenes.nodo;

  for (int i = 1; almacenNodoPuntero != NULL; i++) {
    cout << "[" << i << "] - "
         << almacenNodoPuntero->almacen.departamentoDelPeru << " - "
         << almacenNodoPuntero->almacen.direccion << endl;
    almacenNodoPuntero = almacenNodoPuntero->siguiente;
  }

  cout << endl << "Introduzca la opci??n deseada:" << endl;
  cin >> selectedOption;

  while (!(1 <= selectedOption && selectedOption <= almacenes.largo)) {
    cout << "Por favor, introduzca un valor entre 1 y " << almacenes.largo
         << "." << endl;
    fflush(stdin);
    cin >> selectedOption;
  }

  return iterarGrafoAlmacenes(almacenes, selectedOption);
}

productoEnAlmacenNodo *iterarProductoEnAlmacen(
    productosEnAlmacenLista productosEnAlmacen, int index) {
  productoEnAlmacenNodo *productoEnAlmacenNodoPuntero;

  if (0 >= index) {
    return NULL;
  }

  if (index > productosEnAlmacen.largo) {
    return NULL;
  }

  productoEnAlmacenNodoPuntero = productosEnAlmacen.cabecera;

  for (int i = 1; productoEnAlmacenNodoPuntero != NULL; i++) {
    if (i == index) {
      return productoEnAlmacenNodoPuntero;
    }
    productoEnAlmacenNodoPuntero = productoEnAlmacenNodoPuntero->siguiente;
  }

  return NULL;
}

productoEnAlmacenNodo *pedirProductoEnAlmacen(
    productosEnAlmacenLista productosEnAlmacen, string mensaje) {
  int selectedOption;
  productoEnAlmacenNodo *productoEnAlmacenNodoPuntero;

  cout << endl
       << mensaje << "." << endl
       << "Escoja entre los " << productosEnAlmacen.largo
       << " productos en almacenes siguientes:" << endl
       << endl;

  productoEnAlmacenNodoPuntero = productosEnAlmacen.cabecera;

  for (int i = 1; productoEnAlmacenNodoPuntero != NULL; i++) {
    cout << "[" << i << "] - "
         << productoEnAlmacenNodoPuntero->productoEnAlmacen.marca << " - "
         << productoEnAlmacenNodoPuntero->productoEnAlmacen.nombre << " - "
         << productoEnAlmacenNodoPuntero->productoEnAlmacen.stock << endl;
    productoEnAlmacenNodoPuntero = productoEnAlmacenNodoPuntero->siguiente;
  }

  cout << endl << "Introduzca la opci??n deseada:" << endl;
  cin >> selectedOption;

  while (!(1 <= selectedOption && selectedOption <= productosEnAlmacen.largo)) {
    cout << "Por favor, introduzca un valor entre 1 y "
         << productosEnAlmacen.largo << "." << endl;
    fflush(stdin);
    cin >> selectedOption;
  }

  return iterarProductoEnAlmacen(productosEnAlmacen, selectedOption);
}

clienteNodo *iterarClientes(clientesLista clientes, int index) {
  clienteNodo *clienteNodoPuntero;

  if (0 >= index) {
    return NULL;
  }

  if (index > clientes.largo) {
    return NULL;
  }

  clienteNodoPuntero = clientes.cabecera;

  for (int i = 1; clienteNodoPuntero != NULL; i++) {
    if (i == index) {
      return clienteNodoPuntero;
    }
    clienteNodoPuntero = clienteNodoPuntero->siguiente;
  }

  return NULL;
}

clienteNodo *pedirCliente(clientesLista clientes, string mensaje) {
  int selectedOption;
  clienteNodo *clienteNodoPuntero;

  cout << endl
       << mensaje << "." << endl
       << "Escoja entre los " << clientes.largo
       << " productos en almacenes siguientes:" << endl
       << endl;

  clienteNodoPuntero = clientes.cabecera;

  for (int i = 1; clienteNodoPuntero != NULL; i++) {
    cout << "[" << i << "] - " << clienteNodoPuntero->cliente.apellidos << " "
         << clienteNodoPuntero->cliente.nombres << " - "
         << clienteNodoPuntero->cliente.dni << endl;
    clienteNodoPuntero = clienteNodoPuntero->siguiente;
  }

  cout << endl << "Introduzca la opci??n deseada:" << endl;
  cin >> selectedOption;

  while (!(1 <= selectedOption && selectedOption <= clientes.largo)) {
    cout << "Por favor, introduzca un valor entre 1 y " << clientes.largo << "."
         << endl;
    fflush(stdin);
    cin >> selectedOption;
  }

  return iterarClientes(clientes, selectedOption);
}

ventaNodo *iterarVentas(ventasLista ventas, int index) {
  ventaNodo *ventaNodoPuntero;

  if (0 >= index) {
    return NULL;
  }

  if (index > ventas.largo) {
    return NULL;
  }

  ventaNodoPuntero = ventas.cabecera;

  for (int i = 1; ventaNodoPuntero != NULL; i++) {
    if (i == index) {
      return ventaNodoPuntero;
    }
    ventaNodoPuntero = ventaNodoPuntero->siguiente;
  }

  return NULL;
}

ventaNodo *pedirVenta(ventasLista ventas, string mensaje) {
  int selectedOption;
  ventaNodo *ventaNodoPuntero;

  cout << endl
       << mensaje << "." << endl
       << "Escoja entre las " << ventas.largo << " ventas siguientes:" << endl
       << endl;

  ventaNodoPuntero = ventas.cabecera;

  for (int i = 1; ventaNodoPuntero != NULL; i++) {
    cout << "[" << i << "] - " << ventaNodoPuntero->venta.fechaDeVenta << " - "
         << ventaNodoPuntero->venta.apellidosCliente << " - "
         << ventaNodoPuntero->venta.nombresCliente << endl;
    ventaNodoPuntero = ventaNodoPuntero->siguiente;
  }

  cout << endl << "Introduzca la opci??n deseada:" << endl;
  cin >> selectedOption;

  while (!(1 <= selectedOption && selectedOption <= ventas.largo)) {
    cout << "Por favor, introduzca un valor entre 1 y " << ventas.largo << "."
         << endl;
    fflush(stdin);
    cin >> selectedOption;
  }

  return iterarVentas(ventas, selectedOption);
}

productoEnCarritoDeCompraNodo *iterarProductosEnCarritoDeCompra(
    productosEnCarritoDeCompraPila productosEnCarritoDeCompra, int index) {
  productoEnCarritoDeCompraNodo *productoEnCarritoDeCompraNodoPuntero;

  if (0 >= index) {
    return NULL;
  }

  if (index > productosEnCarritoDeCompra.largo) {
    return NULL;
  }

  productoEnCarritoDeCompraNodoPuntero = productosEnCarritoDeCompra.cabecera;

  for (int i = 1; productoEnCarritoDeCompraNodoPuntero != NULL; i++) {
    if (i == index) {
      return productoEnCarritoDeCompraNodoPuntero;
    }
    productoEnCarritoDeCompraNodoPuntero =
        productoEnCarritoDeCompraNodoPuntero->siguiente;
  }

  return NULL;
}

productoEnCarritoDeCompraNodo *pedirProductoEnCarritoDeCompra(
    productosEnCarritoDeCompraPila productosEnCarritoDeCompra, string mensaje) {
  int selectedOption;
  productoEnCarritoDeCompraNodo *productoEnCarritoDeCompraNodoPuntero;

  cout << endl
       << mensaje << "." << endl
       << "Escoja entre los " << productosEnCarritoDeCompra.largo
       << " productos en carrito de compra siguientes:" << endl
       << endl;

  productoEnCarritoDeCompraNodoPuntero = productosEnCarritoDeCompra.cabecera;

  for (int i = 1; productoEnCarritoDeCompraNodoPuntero != NULL; i++) {
    cout
        << "[" << i << "]"
        << " Marca: "
        << productoEnCarritoDeCompraNodoPuntero->productoEnCarritoDeCompra.marca
        << " - Nombre: "
        << productoEnCarritoDeCompraNodoPuntero->productoEnCarritoDeCompra
               .nombre
        << " - Precio: "
        << productoEnCarritoDeCompraNodoPuntero->productoEnCarritoDeCompra
               .precio
        << " - Cantidad: "
        << productoEnCarritoDeCompraNodoPuntero->productoEnCarritoDeCompra
               .cantidad
        << endl;
    productoEnCarritoDeCompraNodoPuntero =
        productoEnCarritoDeCompraNodoPuntero->siguiente;
  }

  cout << endl << "Introduzca la opci??n deseada:" << endl;
  cin >> selectedOption;

  while (!(1 <= selectedOption &&
           selectedOption <= productosEnCarritoDeCompra.largo)) {
    cout << "Por favor, introduzca un valor entre 1 y "
         << productosEnCarritoDeCompra.largo << "." << endl;
    fflush(stdin);
    cin >> selectedOption;
  }

  return iterarProductosEnCarritoDeCompra(productosEnCarritoDeCompra,
                                          selectedOption);
}

almacenNodo *buscarAlmacenPorCodigo(almacenesGrafo almacenes,
                                    string almacenCodigo) {
  almacenNodo *aux = almacenes.nodo;

  while (aux != NULL) {
    if (aux->almacen.codigoAlmacen == almacenCodigo) return aux;
    aux = aux->siguiente;
  }

  return NULL;
}

empleadoNodo *buscarEmpleadoPorDni(deltronStruct deltron, string dni) {
  empleadoNodo *aux = deltron.empleados.cabecera;

  while (aux != NULL) {
    if (aux->empleado.dni == dni) return aux;
    aux = aux->siguiente;
  }

  return NULL;
}

clienteNodo *buscarClientePorDni(deltronStruct deltron, string dni) {
  clienteNodo *aux = deltron.clientes.cabecera;

  while (aux != NULL) {
    if (aux->cliente.dni == dni) return aux;
    aux = aux->siguiente;
  }

  return NULL;
}

bool dniEstaRegistrado(deltronStruct deltron, string dni) {
  return buscarEmpleadoPorDni(deltron, dni) != NULL ||
         buscarClientePorDni(deltron, dni) != NULL;
}

productoEnAlmacenNodo *buscarProductoEnAlmacenPorCodigo(
    productosEnAlmacenLista productosEnAlmacen, string productoCodigo) {
  productoEnAlmacenNodo *aux = productosEnAlmacen.cabecera;

  while (aux != NULL) {
    if (aux->productoEnAlmacen.codigo == productoCodigo) return aux;
    aux = aux->siguiente;
  }

  return NULL;
}

// Impresores

void imprimirCabeceraAlmacenes(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Departamento";
  gotoxy(25, y);
  cout << "Direcci??n";
  gotoxy(50, y);
  cout << "Almacenes proximos";
}

void imprimirAlmacen(almacenNodo *nodo, int n, int y) {
  almacenVertice *vertice;
  string almacenDestino;
  int x = 0;

  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << nodo->almacen.departamentoDelPeru;
  gotoxy(25, y);
  cout << nodo->almacen.direccion;
  vertice = nodo->adyacente;

  if (vertice == NULL) {
    gotoxy(50, y);
    cout << "No hay destinos disponibles";
    return;
  }

  while (vertice != NULL) {
    gotoxy(50 + x, y);
    almacenDestino = vertice->destino->almacen.direccion + " [" +
                     vertice->destino->almacen.departamentoDelPeru + "]";
    cout << almacenDestino;

    if (vertice->siguiente != NULL) cout << ", ";

    x += (almacenDestino.length() + 2);
    vertice = vertice->siguiente;
  }
}

void imprimirCabeceraEmpleados(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Nombre completo";
  gotoxy(45, y);
  cout << "DNI";
  gotoxy(55, y);
  cout << "Genero";
  gotoxy(65, y);
  cout << "Salario";
}

void imprimirEmpleado(empleadoStruct empleado, int n, int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << empleado.apellidos << " " << empleado.nombres;
  gotoxy(45, y);
  cout << empleado.dni;
  gotoxy(55, y);
  cout << conseguirGenero(empleado.genero);
  gotoxy(65, y);
  cout << empleado.salario;
}

void imprimirCabeceraClientes(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Nombre completo";
  gotoxy(45, y);
  cout << "DNI";
  gotoxy(55, y);
  cout << "Genero";
}

void imprimirCliente(clienteStruct cliente, int n, int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << cliente.apellidos << " " << cliente.nombres;
  gotoxy(45, y);
  cout << cliente.dni;
  gotoxy(55, y);
  cout << conseguirGenero(cliente.genero);
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
  cout << "Nombre completo";
  gotoxy(45, y);
  cout << "DNI";
  gotoxy(55, y);
  cout << "Fecha de LLegada";
}

void imprimirPersonaRecogiendoCompra(
    personaRecogiendoCompraStruct personaRecogiendoCompra, int n, int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << personaRecogiendoCompra.nombres << " "
       << personaRecogiendoCompra.apellidos;
  gotoxy(45, y);
  cout << personaRecogiendoCompra.dni;
  gotoxy(55, y);
  cout << personaRecogiendoCompra.fechaDeLLegada;
}

void imprimirCabeceraCompra(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Cliente";
  gotoxy(45, y);
  cout << "DNI";
  gotoxy(55, y);
  cout << "Fecha";
  gotoxy(80, y);
  cout << "Estado";
}

void imprimirCompra(ventaStruct compra, int n, int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << compra.apellidosCliente << " " << compra.nombresCliente;
  gotoxy(45, y);
  cout << compra.dniCliente;
  gotoxy(55, y);
  cout << compra.fechaDeVenta;
  gotoxy(80, y);
  cout << compra.estadoDeVenta;
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

void imprimirProductoComprado(productoVendidoStruct productoComprado, int n,
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
