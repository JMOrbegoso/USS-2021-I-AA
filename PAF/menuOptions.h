#include "structFunctions.h"

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
  addDelay(1.5);
}

void registrarCliente(deltronStruct &deltron) {
  cout << endl << "SE ESTÁ REGISTRANDO" << endl;
  addDelay(1.5);
}

empleadoNodo *loginEmpleado(deltronStruct deltron) {
  empleadoNodo *empleadoNodoPuntero;
  string dni;
  string clave;
  bool empleadoEncontrado = false;
  string saludo;

  clearScreen();
  showAppTitle(deltron);

  gotoxy(20, 10);
  cout << "Inicio de sesión de empleado" << endl << endl;

  dni = requestText("Por favor ingrese su DNI", 8, 8);
  clave = requestText("Por favor ingrese su contraseña", 6, 8);

  empleadoNodoPuntero = deltron.empleados.cabecera;

  while (empleadoNodoPuntero != NULL) {
    if (empleadoNodoPuntero->empleado.dni == dni) {
      empleadoEncontrado = true;

      if (empleadoNodoPuntero->empleado.claveDeAcceso == clave) {
        clearScreen();

        gotoxy(5, 10);
        saludo = empleadoNodoPuntero->empleado.genero ? "Bienvenido "
                                                      : "Bienvenida ";
        cout << saludo;
        cout << empleadoNodoPuntero->empleado.nombres << " "
             << empleadoNodoPuntero->empleado.apellidos;
        cout << endl;

        gotoxy(10, 20);
        cout << "Ingresando...";
        addDelay(2);
        return empleadoNodoPuntero;
      } else {
        cout << "Contraseña incorrecta, por favor corrijala" << endl;
        addDelay(2);
        return NULL;
      }
    }

    empleadoNodoPuntero = empleadoNodoPuntero->siguiente;
  }

  if (!empleadoEncontrado) {
    cout << "No fue encontrado su DNI. Usuario no existe" << endl;
    addDelay(2);
  }

  return NULL;
}

clienteNodo *loginCliente(deltronStruct deltron) {
  clienteNodo *clienteNodoPuntero;
  string dni;
  string clave;
  bool clienteEncontrado = false;
  string saludo;

  clearScreen();
  showAppTitle(deltron);

  gotoxy(20, 10);
  cout << "Inicio de sesión de cliente" << endl << endl;

  dni = requestText("Por favor ingrese su DNI", 8, 8);
  clave = requestText("Por favor ingrese su contraseña", 6, 8);

  clienteNodoPuntero = deltron.clientes.cabecera;

  while (clienteNodoPuntero != NULL) {
    if (clienteNodoPuntero->cliente.dni == dni) {
      clienteEncontrado = true;

      if (clienteNodoPuntero->cliente.claveDeAcceso == clave) {
        clearScreen();

        gotoxy(5, 10);
        saludo =
            clienteNodoPuntero->cliente.genero ? "Bienvenido " : "Bienvenida ";
        cout << saludo;
        cout << clienteNodoPuntero->cliente.nombres << " "
             << clienteNodoPuntero->cliente.apellidos;
        cout << endl;

        gotoxy(10, 20);
        cout << "Ingresando...";
        addDelay(2);
        return clienteNodoPuntero;
      } else {
        cout << "Contraseña incorrecta, por favor corrijala" << endl;
        addDelay(2);
        return NULL;
      }
    }

    clienteNodoPuntero = clienteNodoPuntero->siguiente;
  }

  if (!clienteEncontrado) {
    cout << "No fue encontrado su DNI. Usuario no existe" << endl;
    addDelay(2);
  }

  return NULL;
}

void revisarVentas(deltronStruct deltron) {}

void registrarProductoEnAlmacen(deltronStruct &deltron) {}

void editarProductoEnAlmacen(deltronStruct &deltron) {}

void registrarPersonaEnCola(deltronStruct &deltron) {}

void despacharVenta(deltronStruct &deltron) {}

void revisarCatalogoDeAlmacen(deltronStruct deltron) {}

void buscarProductoEnAlmacenes(deltronStruct deltron) {}

void agregarProductoAlCarrito(deltronStruct &deltron) {}

void editarCantidadDeProductoEnCarrito(deltronStruct &deltron) {}

void quitarProductoDeCarrito(deltronStruct &deltron) {}

void realizarCompra(deltronStruct &deltron) {}