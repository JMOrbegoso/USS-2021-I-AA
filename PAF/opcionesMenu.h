#include "funcionesBasicasConEstructuras.h"

void mostrarDatosEmpresa(deltronStruct deltron) {
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
  empleadoStruct nuevoEmpleado;
  string nombres, apellidos, dni, clave;
  bool genero;
  float salario;

  system("cls");
  mostrarDatosEmpresa(deltron);

  gotoxy(20, 10);
  cout << "Registro de empleado" << endl << endl;

  nombres = leerTexto("Por favor ingrese sus nombres", 2);
  apellidos = leerTexto("Por favor ingrese sus apellidos", 2);
  dni = leerTexto("Por favor ingrese su DNI", 8, 8);
  clave = leerTexto("Por favor ingrese su contraseña", 6, 8);
  genero = leerGenero("Por favor ingrese su genero");
  salario = leerNumeroDecimal("Por favor ingrese su salario",
                              "Por favor ingrese un numero superior a 0", 1);

  if (dniEstaRegistrado(deltron, dni)) {
    cout << "El DNI usado ya está registrado, por favor use otro.";
    cout << endl;
    return;
  }

  nuevoEmpleado =
      construirEmpleado(dni, clave, nombres, apellidos, genero, salario);

  insertar(deltron.empleados, nuevoEmpleado);

  cout << "El empleado fue registrado de forma correcta.";
  cout << endl;
}

void registrarCliente(deltronStruct &deltron) {
  clienteStruct nuevoCliente;
  string nombres, apellidos, dni, clave;
  bool genero;

  system("cls");
  mostrarDatosEmpresa(deltron);

  gotoxy(20, 10);
  cout << "Registro de cliente" << endl << endl;

  nombres = leerTexto("Por favor ingrese sus nombres", 2);
  apellidos = leerTexto("Por favor ingrese sus apellidos", 2);
  dni = leerTexto("Por favor ingrese su DNI", 8, 8);
  clave = leerTexto("Por favor ingrese su contraseña", 6, 8);
  genero = leerGenero("Por favor ingrese su genero");

  if (dniEstaRegistrado(deltron, dni)) {
    cout << "El DNI usado ya está registrado, por favor use otro.";
    cout << endl;
    return;
  }

  nuevoCliente = construirCliente(dni, clave, nombres, apellidos, genero);

  insertar(deltron.clientes, nuevoCliente);

  cout << "El cliente fue registrado de forma correcta.";
  cout << endl;
}

empleadoNodo *loginEmpleado(deltronStruct deltron) {
  empleadoNodo *empleadoNodoPuntero;
  string dni;
  string clave;
  bool empleadoEncontrado = false;
  string saludo;

  system("cls");
  mostrarDatosEmpresa(deltron);

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
  mostrarDatosEmpresa(deltron);

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

void revisarVentas(deltronStruct deltron, empleadoNodo *empleadoLogeado) {
  ventaNodo *ventaNodoPuntero;

  system("cls");
  mostrarDatosEmpresa(deltron);

  gotoxy(20, 10);
  cout << "Ventas realizadas" << endl << endl;

  imprimirCabeceraCompra(10);

  int i = 0;
  ventaNodoPuntero = deltron.ventas.cabecera;
  while (ventaNodoPuntero != NULL) {
    imprimirCompra(ventaNodoPuntero->venta, i, i + 12);
    i++;
    ventaNodoPuntero = ventaNodoPuntero->siguiente;
  }

  cout << endl;
}

void registrarProductoEnAlmacen(deltronStruct &deltron,
                                empleadoNodo *empleadoLogeado) {}

void editarProductoEnAlmacen(deltronStruct &deltron,
                             empleadoNodo *empleadoLogeado) {
  almacenNodo *almacenNodoPuntero;
  productoEnAlmacenNodo *productoEnAlmacenNodoPuntero;

  system("cls");
  mostrarDatosEmpresa(deltron);

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
  mostrarDatosEmpresa(deltron);

  gotoxy(20, 8);
  cout << "Registrará una persona formando cola para recoger una venta:"
       << endl;

  apellidos = leerTexto("Ingrese Apellidos:", 2);
  nombres = leerTexto("Ingrese Nombres:", 2);
  dni = leerTexto("Ingrese DNI:", 8, 8);
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
  mostrarDatosEmpresa(deltron);

  gotoxy(20, 8);
  cout << "Va a despachar una venta a una persona formando cola:" << endl;

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
  mostrarDatosEmpresa(deltron);

  gotoxy(20, 8);
  cout << "Lista de todos los almacenes con sus relaciones:" << endl;

  imprimirCabeceraAlmacenes(10);

  auxCityNode = deltron.almacenes.nodo;

  for (int i = 0; auxCityNode != NULL; i++) {
    imprimirAlmacen(auxCityNode, i, 12 + i);
    auxCityNode = auxCityNode->siguiente;
  }

  cout << endl << endl;
}

void registrarNuevoAlmacen(deltronStruct &deltron,
                           empleadoNodo *empleadoLogeado) {
  string codigoAlmacen, departamentoDelPeru, direccion;
  almacenStruct nuevoAlmacen;

  system("cls");
  mostrarDatosEmpresa(deltron);

  gotoxy(20, 8);
  cout << "Registrará un nuevo almacén:" << endl;

  codigoAlmacen = leerTexto("Ingrese el codigo del almacen:", 2);
  departamentoDelPeru = leerTexto("Ingrese el departamento del Perú:", 2);
  direccion = leerTexto("Ingrese la dirección del almacén:", 2);

  nuevoAlmacen =
      construirAlmacen(codigoAlmacen, departamentoDelPeru, direccion);

  insertar(deltron.almacenes, nuevoAlmacen);

  cout << "El almacén fue registrada correctamente";
  cout << endl;
}

void registrarRelacionEntreAlmacenes(deltronStruct &deltron,
                                     empleadoNodo *empleadoLogeado) {
  almacenNodo *almacenOrigenNodoPuntero, *almacenDestinoNodoPuntero;
  almacenVertice *newCityEdge = new struct almacenVertice;

  system("cls");
  mostrarDatosEmpresa(deltron);

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

  system("cls");
  mostrarDatosEmpresa(deltron);

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

  system("cls");
  mostrarDatosEmpresa(deltron);

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
  ventaStruct nuevaVenta;
  clienteNodo *clienteNodoPuntero;
  almacenNodo *almacenNodoPuntero;
  productoEnCarritoDeCompraNodo *productoEnCarritoDeCompraNodoPuntero;
  productoEnAlmacenNodo *productoEnAlmacenNodoPuntero;
  productoVendidoStruct productoVendido;
  int cantidadComprada;

  system("cls");
  mostrarDatosEmpresa(deltron);

  fechaDeVenta = leerTexto("Ingrese la fecha y hora actuales", 2, 2);

  clienteNodoPuntero = pedirCliente(
      deltron.clientes, "Ingrese el cliente que a realizado la compra");

  nombresCliente = clienteNodoPuntero->cliente.nombres;
  apellidosCliente = clienteNodoPuntero->cliente.apellidos;
  dniCliente = clienteNodoPuntero->cliente.apellidos;
  estadoDeVenta = "Creada";

  nuevaVenta = construirVenta(nombresCliente, apellidosCliente, dniCliente,
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

    insertar(nuevaVenta.productosVendidos, productoVendido);

    productoEnAlmacenNodoPuntero->productoEnAlmacen.stock =
        productoEnAlmacenNodoPuntero->productoEnAlmacen.stock -
        cantidadComprada;

    productoEnCarritoDeCompraNodoPuntero =
        productoEnCarritoDeCompraNodoPuntero->siguiente;

    desapilar(clienteNodoPuntero->cliente.productosEnCarritoDeCompra);
  }

  insertar(deltron.ventas, nuevaVenta);
}
