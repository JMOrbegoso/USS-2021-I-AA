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
        cout << "Ingresando...";
        Sleep(2000);
        return empleadoNodoPuntero;
      } else {
        cout << "Contraseña incorrecta, por favor corrijala" << endl;
        Sleep(2000);
        return NULL;
      }
    }

    empleadoNodoPuntero = empleadoNodoPuntero->siguiente;
  }

  if (!empleadoEncontrado) {
    cout << "No fue encontrado su DNI. Usuario no existe" << endl;
    Sleep(2000);
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
        cout << "Ingresando...";
        Sleep(2000);
        return clienteNodoPuntero;
      } else {
        cout << "Contraseña incorrecta, por favor corrijala" << endl;
        Sleep(2000);
        return NULL;
      }
    }

    clienteNodoPuntero = clienteNodoPuntero->siguiente;
  }

  if (!clienteEncontrado) {
    cout << "No fue encontrado su DNI. Usuario no existe" << endl;
    Sleep(2000);
  }

  return NULL;
}

void revisarVentas(deltronStruct deltron, empleadoNodo *empleadoLogeado) {}

void registrarProductoEnAlmacen(deltronStruct &deltron,
                                empleadoNodo *empleadoLogeado) {}

void editarProductoEnAlmacen(deltronStruct &deltron,
                             empleadoNodo *empleadoLogeado) {}

void registrarPersonaEnCola(deltronStruct &deltron,
                            empleadoNodo *empleadoLogeado) {}

void despacharVenta(deltronStruct &deltron, empleadoNodo *empleadoLogeado) {}

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
                              clienteNodo *clienteLogeado) {}

void buscarProductoEnAlmacenes(deltronStruct deltron,
                               clienteNodo *clienteLogeado) {}

void agregarProductoAlCarrito(deltronStruct &deltron,
                              clienteNodo *clienteLogeado) {}

void editarCantidadDeProductoEnCarrito(deltronStruct &deltron,
                                       clienteNodo *clienteLogeado) {}

void quitarProductoDeCarrito(deltronStruct &deltron,
                             clienteNodo *clienteLogeado) {}

void realizarCompra(deltronStruct &deltron, clienteNodo *clienteLogeado) {}