#include "helpers.h"
#include "structs.h"

using namespace std;

// Fabricas

empleadoStruct construirEmpleado(string nombres, string apellidos, bool genero,
                                 string dni, float salario) {
  empleadoStruct empleado;

  empleado.nombres = nombres;
  empleado.apellidos = apellidos;
  empleado.genero = genero;
  empleado.dni = dni;
  empleado.salario = salario;

  return empleado;
}

clienteStruct construirCliente(string nombres, string apellidos, bool genero,
                               string dni) {
  clienteStruct cliente;

  cliente.nombres = nombres;
  cliente.apellidos = apellidos;
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
  almacenStruct almacenLima, almacenTrujillo, almacenChiclayo;
  empleadoStruct empleado01, empleado02;
  clienteStruct cliente01, cliente02;

  productoEnAlmacenStruct productoEnAlmacen01, productoEnAlmacen02,
      productoEnAlmacen03;
  productoEnCarritoDeCompraStruct productoEnCarritoDeCompra01;
  personaRecogiendoCompraStruct personaRecogiendoCompra01;
  compraStruct compra01;

  deltron.razonSocial = "Deltron SAC";
  deltron.ruc = "12345678910";

  // Init empleados
  empleado01 =
      construirEmpleado("Jorge", "Gonzales Rojas", true, "11111111", 2000);
  empleado02 =
      construirEmpleado("Miguel", "Ramos Lopez", true, "22222222", 2000);

  insertar(deltron.empleados, empleado01);
  insertar(deltron.empleados, empleado02);

  // Init clientes
  cliente01 = construirCliente("Tulio", "Ramos Lopez", true, "12121212");
  cliente02 = construirCliente("Valery", "Marquez Gonzales", false, "13131313");

  insertar(deltron.clientes, cliente01);
  insertar(deltron.clientes, cliente02);

  // Productos en Almacen

  productoEnAlmacen01 =
      construirProductoEnAlmacen("i7 10700K", "Intel", "CPU", 1900, 10);
  productoEnAlmacen02 =
      construirProductoEnAlmacen("Ryzen 7 3700", "AMD", "CPU", 1700, 15);
  productoEnAlmacen03 =
      construirProductoEnAlmacen("GeForce 1030", "Nvidia", "GPU", 400, 20);

  insertar(almacenLima.productosEnAlmacen, productoEnAlmacen01);
  insertar(almacenLima.productosEnAlmacen, productoEnAlmacen02);
  insertar(almacenLima.productosEnAlmacen, productoEnAlmacen03);

  // Init almacenes
  almacenLima = construirAlmacen("Almacen Lima", "Av. Lima 747");
  almacenTrujillo = construirAlmacen("Almacen Trujillo", "Av. Trujillo 747");
  almacenChiclayo = construirAlmacen("Almacen Chiclayo", "Av. Chiclayo 747");

  insertar(deltron.almacenes, almacenLima);
  insertar(deltron.almacenes, almacenTrujillo);
  insertar(deltron.almacenes, almacenChiclayo);

  // Inicializar carritos de compra

  // Inicializar clientes recogiendo compras

  // Inicializar Compras realizadas
  compra01 = construirCompra("Tulio", "Ramos", "Lopez", "12121212",
                             "2021-06-20 10:00:00", "Recogida");

  insertar(deltron.compras, compra01);
}

// Impresores

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

void imprimirCabeceraEmpleados(int y) {
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
  gotoxy(80, y);
  cout << "Salario";
}

void imprimirEmpleado(empleadoStruct empleado, int n, int y) {
  gotoxy(0, y);
  cout << n;
  gotoxy(5, y);
  cout << empleado.apellidos;
  gotoxy(25, y);
  cout << empleado.nombres;
  gotoxy(50, y);
  cout << empleado.dni;
  gotoxy(70, y);
  cout << getGenre(empleado.genero);
  gotoxy(80, y);
  cout << empleado.salario;
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
  cout << cliente.apellidos;
  gotoxy(25, y);
  cout << cliente.nombres;
  gotoxy(50, y);
  cout << cliente.dni;
  gotoxy(70, y);
  cout << getGenre(cliente.genero);
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
