#include "funcionesBasicasConEstructuras.h"

void showAppTitle(deltronStruct deltron) {
  cout << endl;
  cout << "-----------------------------------------------------------";
  cout << endl << endl;
  cout << "\t Sistema virtual de la empresa " << deltron.razonSocial;
  cout << endl << endl;
  cout << "RUC: " << deltron.ruc;
  cout << endl << endl;
  cout << "-----------------------------------------------------------";
  cout << endl;
}

void registrarEmpleado(deltronStruct &deltron) {
  cout << endl << "SE ESTÁ REGISTRANDO" << endl;
  Sleep(1500);
}

void registrarCliente(deltronStruct &deltron) {
  cout << endl << "SE ESTÁ REGISTRANDO" << endl;
  Sleep(1500);
}

empleadoNodo *loginEmpleado(deltronStruct deltron) {
  empleadoNodo *empleadoNodoPuntero;
  string dni;
  string clave;
  bool empleadoEncontrado = false;
  string saludo;

  system("cls");
  showAppTitle(deltron);

  gotoxy(20, 10);
  cout << "Inicio de sesión de empleado" << endl << endl;

  dni = leerTexto("Por favor ingrese su DNI", 8, 8);
  clave = leerTexto("Por favor ingrese su contraseña", 6, 8);

  empleadoNodoPuntero = deltron.empleados.cabecera;

  while (empleadoNodoPuntero != NULL) {
    if (empleadoNodoPuntero->empleado.dni == dni) {
      empleadoEncontrado = true;

      if (empleadoNodoPuntero->empleado.claveDeAcceso == clave) {
        system("cls");

        gotoxy(5, 10);
        saludo = empleadoNodoPuntero->empleado.genero ? "Bienvenido "
                                                      : "Bienvenida ";
        cout << saludo;
        cout << empleadoNodoPuntero->empleado.nombres << " "
             << empleadoNodoPuntero->empleado.apellidos;
        cout << endl;

        gotoxy(10, 20);
        esperarMostrandoTexto("Ingresando...");
        return empleadoNodoPuntero;
      } else {
        esperarMostrandoTexto("Contraseña incorrecta, por favor corrijala");
        return NULL;
      }
    }

    empleadoNodoPuntero = empleadoNodoPuntero->siguiente;
  }

  if (!empleadoEncontrado) {
    esperarMostrandoTexto("No fue encontrado su DNI. Usuario no existe");
  }

  return NULL;
}

clienteNodo *loginCliente(deltronStruct deltron) {
  clienteNodo *clienteNodoPuntero;
  string dni;
  string clave;
  bool clienteEncontrado = false;
  string saludo;

  system("cls");
  showAppTitle(deltron);

  gotoxy(20, 10);
  cout << "Inicio de sesión de cliente" << endl << endl;

  dni = leerTexto("Por favor ingrese su DNI", 8, 8);
  clave = leerTexto("Por favor ingrese su contraseña", 6, 8);

  clienteNodoPuntero = deltron.clientes.cabecera;

  while (clienteNodoPuntero != NULL) {
    if (clienteNodoPuntero->cliente.dni == dni) {
      clienteEncontrado = true;

      if (clienteNodoPuntero->cliente.claveDeAcceso == clave) {
        system("cls");

        gotoxy(5, 10);
        saludo =
            clienteNodoPuntero->cliente.genero ? "Bienvenido " : "Bienvenida ";
        cout << saludo;
        cout << clienteNodoPuntero->cliente.nombres << " "
             << clienteNodoPuntero->cliente.apellidos;
        cout << endl;

        gotoxy(10, 20);
        esperarMostrandoTexto("Ingresando...");
        return clienteNodoPuntero;
      } else {
        esperarMostrandoTexto("Contraseña incorrecta, por favor corrijala");
        return NULL;
      }
    }

    clienteNodoPuntero = clienteNodoPuntero->siguiente;
  }

  if (!clienteEncontrado) {
    esperarMostrandoTexto("No fue encontrado su DNI. Usuario no existe");
  }

  return NULL;
}

void revisarVentas(deltronStruct deltron, empleadoNodo *empleadoLogeado) {}

void registrarProductoEnAlmacen(deltronStruct &deltron,
                                empleadoNodo *empleadoLogeado) {}

void editarProductoEnAlmacen(deltronStruct &deltron,
                             empleadoNodo *empleadoLogeado) {
  almacenNodo *almacenNodoPuntero;
  productoEnAlmacenNodo *productoEnAlmacenNodoPuntero;

  almacenNodoPuntero = pedirAlmacen(
      deltron.almacenes, "Seleccione el almacen para editar el producto");

  if (almacenNodoPuntero == NULL) {
    cout << "Selecciono un almacen no valido";
    return;
  }

  productoEnAlmacenNodoPuntero =
      pedirProductoEnAlmacen(almacenNodoPuntero->almacen.productosEnAlmacen,
                             "Seleccione el producto que desee editar");

  if (productoEnAlmacenNodoPuntero == NULL) {
    cout << "Selecciono un producto no valido";
    return;
  }

  int stock = leerNumeroEntero("Ingrese stock para el producto",
                               "Porfavor que el stock sea mayor a 0", 0);
  productoEnAlmacenNodoPuntero->productoEnAlmacen.stock = stock;
}

void registrarPersonaEnCola(deltronStruct &deltron,
                            empleadoNodo *empleadoLogeado) {
  string apellidos, nombres, dni, fechaDeLLegada;
  personaRecogiendoCompraStruct nuevaPersonaRecogiendoCompra;
  almacenNodo *almacenNodoPuntero;

  system("cls");
  showAppTitle(deltron);

  gotoxy(20, 8);
  cout << "Registrará una persona formando cola para recoger una venta:"
       << endl;

  apellidos = leerTexto("Ingrese Apellidos :", 2);
  nombres = leerTexto("Ingrese Nombres :", 2);
  dni = leerTexto("Ingrese Edad :", 8, 8);
  fechaDeLLegada = leerTexto("Ingrese Fecha de Llegada :", 2);

  almacenNodoPuntero = pedirAlmacen(
      deltron.almacenes, "Ingrese el almacen en donde está formando cola");

  nuevaPersonaRecogiendoCompra =
      construirPersonaRecogiendoCompra(nombres, apellidos, dni, fechaDeLLegada);

  encolar(almacenNodoPuntero->almacen.personasRecogiendoCompras,
          nuevaPersonaRecogiendoCompra);

  cout << "La persona fue registrada correctamente";
  cout << endl;
}

void despacharVenta(deltronStruct &deltron, empleadoNodo *empleadoLogeado) {
  almacenNodo *almacenNodoPuntero;
  personaRecogiendoCompraStruct personaRecogiendoCompraAtendida;
  ventaNodo *ventaDespachada;

  system("cls");
  showAppTitle(deltron);

  gotoxy(20, 8);
  cout << "Va a despachar una venta a una persona formando cola para recoger "
          "una venta:"
       << endl;

  almacenNodoPuntero = pedirAlmacen(
      deltron.almacenes, "Ingrese el almacen donde quiere despachar:");

  ventaDespachada = pedirVenta(deltron.ventas, "Ingrese la venta a despachar");

  ventaDespachada->venta.estadoDeVenta = "Entregada";

  desencolarPersonaRecogiendoCompra(
      almacenNodoPuntero->almacen.personasRecogiendoCompras);
}

void revisarAlmacenes(deltronStruct deltron, empleadoNodo *empleadoLogeado) {
  almacenNodo *auxCityNode;
  almacenVertice *tempCityEdge;

  system("cls");
  showAppTitle(deltron);

  gotoxy(20, 8);
  cout << "Lista de todas las ciudades con sus destinos:" << endl;

  imprimirCabeceraAlmacenes(10);

  auxCityNode = deltron.almacenes.nodo;

  for (int i = 0; auxCityNode != NULL; i++) {
    imprimirAlmacen(auxCityNode, i, 12 + i);
    auxCityNode = auxCityNode->siguiente;
  }

  cout << endl << endl;
}

void registrarNuevoAlmacen(deltronStruct &deltron,
                           empleadoNodo *empleadoLogeado) {}

void registrarRelacionEntreAlmacenes(deltronStruct &deltron,
                                     empleadoNodo *empleadoLogeado) {
  almacenNodo *almacenOrigenNodoPuntero, *almacenDestinoNodoPuntero;
  almacenVertice *newCityEdge = new struct almacenVertice;

  system("cls");
  showAppTitle(deltron);

  gotoxy(20, 8);
  cout << "Registrar nuevo enlace entre almacenes:" << endl;

  if (deltron.almacenes.nodo == NULL ||
      deltron.almacenes.nodo->siguiente == NULL) {
    cout << "Primero debe de añadir almenos 2 almacenes.";
    cout << endl << endl;
    return;
  }

  newCityEdge->siguiente = NULL;

  almacenOrigenNodoPuntero =
      pedirAlmacen(deltron.almacenes, "Escoja el almacén de origen");

  if (almacenOrigenNodoPuntero == NULL) {
    cout << "Introdujo un almacén no valido";
    cout << endl << endl;
    return;
  }

  almacenDestinoNodoPuntero =
      pedirAlmacen(deltron.almacenes, "Escoja el almacén de destino");

  if (almacenDestinoNodoPuntero == NULL) {
    cout << "Introdujo un almacén no valida";
    cout << endl << endl;
    return;
  }

  construirAlmacenVertice(almacenOrigenNodoPuntero, almacenDestinoNodoPuntero,
                          newCityEdge);
}

void revisarCatalogoDeAlmacen(deltronStruct deltron,
                              clienteNodo *clienteLogeado) {
  almacenNodo *almacenNodoPuntero;
  productoEnAlmacenNodo *productoEnAlmacenNodoPuntero;

  // almacenNodoPuntero = deltron.almacenes.nodo;
  almacenNodoPuntero = pedirAlmacen(deltron.almacenes, "Seleccione el almacen");

  if (almacenNodoPuntero == NULL) {
    cout << "Selecciono un almacen no valido";
    return;
  }

  productoEnAlmacenNodoPuntero =
      almacenNodoPuntero->almacen.productosEnAlmacen.cabecera;

  int i = 0;
  while (productoEnAlmacenNodoPuntero != NULL) {
    imprimirProductoEnAlmacen(productoEnAlmacenNodoPuntero->productoEnAlmacen,
                              i, i + 12);
    i++;
    productoEnAlmacenNodoPuntero = productoEnAlmacenNodoPuntero->siguiente;
  }
}

void buscarProductoEnAlmacenes(deltronStruct deltron,
                               clienteNodo *clienteLogeado) {
  almacenNodo *almacenNodoPuntero;
  productoEnAlmacenNodo *productoEnAlmacenNodoPuntero;

  string productoBuscar = leerTexto("Ingrese nombre a buscar: ", 3);
  almacenNodoPuntero = deltron.almacenes.nodo;

  while (almacenNodoPuntero != NULL) {
    productoEnAlmacenNodoPuntero =
        almacenNodoPuntero->almacen.productosEnAlmacen.cabecera;

    while (productoEnAlmacenNodoPuntero != NULL) {
      if (contieneTexto(productoEnAlmacenNodoPuntero->productoEnAlmacen.nombre,
                        productoBuscar)) {
        cout << "Se encontro su producto en el almacen de: "
             << almacenNodoPuntero->almacen.departamentoDelPeru;
        productoEnAlmacenNodoPuntero = productoEnAlmacenNodoPuntero->siguiente;
      }
    }
    almacenNodoPuntero = almacenNodoPuntero->siguiente;
  }
}

void agregarProductoAlCarrito(deltronStruct &deltron,
                              clienteNodo *clienteLogeado) {}

void editarCantidadDeProductoEnCarrito(deltronStruct &deltron,
                                       clienteNodo *clienteLogeado) {}

void quitarProductoDeCarrito(deltronStruct &deltron,
                             clienteNodo *clienteLogeado) {}

void realizarCompra(deltronStruct &deltron, clienteNodo *clienteLogeado) {
  string nombresCliente, apellidosCliente, dniCliente, fechaDeVenta,
      estadoDeVenta;
  ventaStruct venta;
  clienteNodo *clienteNodoPuntero;
  almacenNodo *almacenNodoPuntero;
  productoEnCarritoDeCompraNodo *productoEnCarritoDeCompraNodoPuntero;
  productoEnAlmacenNodo *productoEnAlmacenNodoPuntero;
  productoVendidoStruct productoVendido;
  int cantidadComprada;

  fechaDeVenta = leerTexto("Ingrese la fecha y hora actuales", 2, 2);

  clienteNodoPuntero = pedirCliente(
      deltron.clientes, "Ingrese el cliente que a realizado la compra");

  nombresCliente = clienteNodoPuntero->cliente.nombres;
  apellidosCliente = clienteNodoPuntero->cliente.apellidos;
  dniCliente = clienteNodoPuntero->cliente.apellidos;
  estadoDeVenta = "Creada";

  venta = construirVenta(nombresCliente, apellidosCliente, dniCliente,
                         fechaDeVenta, estadoDeVenta);

  almacenNodoPuntero = buscarAlmacenPorCodigo(
      deltron.almacenes,
      clienteNodoPuntero->cliente.productosEnCarritoDeCompra.codigoAlmacen);

  productoEnCarritoDeCompraNodoPuntero =
      clienteNodoPuntero->cliente.productosEnCarritoDeCompra.cabecera;
  while (productoEnCarritoDeCompraNodoPuntero != NULL) {
    productoEnAlmacenNodoPuntero = buscarProductoEnAlmacenPorCodigo(
        almacenNodoPuntero->almacen.productosEnAlmacen,
        productoEnCarritoDeCompraNodoPuntero->productoEnCarritoDeCompra.codigo);

    if (productoEnAlmacenNodoPuntero->productoEnAlmacen.stock >=
        productoEnCarritoDeCompraNodoPuntero->productoEnCarritoDeCompra
            .cantidad) {
      cantidadComprada = productoEnCarritoDeCompraNodoPuntero
                             ->productoEnCarritoDeCompra.cantidad;
    } else {
      cantidadComprada = productoEnAlmacenNodoPuntero->productoEnAlmacen.stock;
    }

    productoVendido = construirProductoVendido(
        productoEnAlmacenNodoPuntero->productoEnAlmacen.codigo,
        productoEnAlmacenNodoPuntero->productoEnAlmacen.nombre,
        productoEnAlmacenNodoPuntero->productoEnAlmacen.marca,
        productoEnAlmacenNodoPuntero->productoEnAlmacen.tipo,
        productoEnAlmacenNodoPuntero->productoEnAlmacen.precio,
        cantidadComprada);

    insertar(venta.productosVendidos, productoVendido);

    productoEnAlmacenNodoPuntero->productoEnAlmacen.stock =
        productoEnAlmacenNodoPuntero->productoEnAlmacen.stock -
        cantidadComprada;

    productoEnCarritoDeCompraNodoPuntero =
        productoEnCarritoDeCompraNodoPuntero->siguiente;

    desapilar(clienteNodoPuntero->cliente.productosEnCarritoDeCompra);
  }
}
