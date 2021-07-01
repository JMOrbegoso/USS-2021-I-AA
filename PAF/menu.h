#include "menuOptions.h"

using namespace std;

int pedirOpcionDelMenuRol(deltronStruct deltron) {
  int opcionSeleccionada;

  clearScreen();
  showAppTitle(deltron);

  cout << endl << "¿Cúal es su rol?" << endl << endl;

  cout << "[1] Empleado" << endl;
  cout << "[2] Cliente" << endl;
  cout << "[0] Cerrar sistema" << endl;

  cout << endl << "Introduzca la opción deseada:" << endl;
  cin >> opcionSeleccionada;
  while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 2)) {
    cout << "Introdujo una opción inválida, por favor seleccione una opción "
            "válida:"
         << endl;
    cin >> opcionSeleccionada;
  }

  return opcionSeleccionada;
}

int pedirOpcionDelMenuLogin(deltronStruct deltron, string rol) {
  int opcionSeleccionada;

  clearScreen();
  showAppTitle(deltron);

  cout << endl;

  cout << "\t\t\tInicio de sesión como " << rol;
  cout << endl;

  cout << endl << "¿Desea iniciar sesión o registrarse?" << endl << endl;

  cout << "[1] Iniciar sesión" << endl;
  cout << "[2] Registrarse" << endl;
  cout << "[0] Volver" << endl;

  cout << endl << "Introduzca la opción deseada:" << endl;
  cin >> opcionSeleccionada;
  while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 2)) {
    cout << "Introdujo una opción inválida, por favor seleccione una opción "
            "válida:"
         << endl;
    cin >> opcionSeleccionada;
  }

  return opcionSeleccionada;
}

int pedirOpcionDelMenuEmpleado(deltronStruct deltron, string nombreEmpleado) {
  int opcionSeleccionada;

  clearScreen();
  showAppTitle(deltron);

  cout << endl;

  cout << "\t\t\tBienvenido " << nombreEmpleado;
  cout << endl;

  cout << endl << "¿Que desea hacer?" << endl << endl;

  cout << "[1] Mostrar todas las ordenes" << endl;
  cout << "[2] Revisar Almacenes" << endl;
  cout << "[3] Registrar nuevo producto" << endl;
  cout << "[4] Editar datos de producto existente" << endl;
  cout << "[5] Cambiar stock de producto en almacén" << endl;
  cout << "[6] Retirar producto" << endl;
  cout << "[0] Cerrar Sesión" << endl;

  cout << endl << "Introduzca la opción deseada:" << endl;
  cin >> opcionSeleccionada;
  while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 6)) {
    cout << "Introdujo una opción inválida, por favor seleccione una opción "
            "válida:"
         << endl;
    cin >> opcionSeleccionada;
  }

  return opcionSeleccionada;
}

int pedirOpcionDelMenuCliente(deltronStruct deltron,
                              string razonSocialCliente) {
  int opcionSeleccionada;

  clearScreen();
  showAppTitle(deltron);

  cout << endl;

  cout << "\t\t\tBienvenid@ " << razonSocialCliente;
  cout << endl;

  cout << endl << "¿Que desea hacer?" << endl << endl;

  cout << "[1] Revisar catalogo de productos" << endl;
  cout << "[2] Buscar producto por nombre" << endl;
  cout << "[3] Buscar producto por marca" << endl;
  cout << "[4] Crear orden de compra" << endl;
  cout << "[5] Ver historial de ordenes realizadas" << endl;
  cout << "[0] Cerrar Sesión" << endl;

  cout << endl << "Introduzca la opción deseada:" << endl;
  cin >> opcionSeleccionada;
  while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 5)) {
    cout << "Introdujo una opción inválida, por favor seleccione una opción "
            "válida:"
         << endl;
    cin >> opcionSeleccionada;
  }

  return opcionSeleccionada;
}

void menuEmpleado(deltronStruct& deltron, empleadoNodo* empleadoNodoPuntero) {
  int opcionSeleccionada;
  string empleadoNombreCompleto;

  empleadoNombreCompleto = empleadoNodoPuntero->empleado.nombres + " " +
                           empleadoNodoPuntero->empleado.apellidos;

  do {
    opcionSeleccionada =
        pedirOpcionDelMenuEmpleado(deltron, empleadoNombreCompleto);

    if (opcionSeleccionada != 0) {
      switch (opcionSeleccionada) {
        case 1:
          pauseProcess();
          break;

        default:
          break;
      }
    }

  } while (!(opcionSeleccionada == 0));

  cout << endl << "Cerrando Sesión" << endl;
}

void menuCliente(deltronStruct& deltron, clienteNodo* clienteNodoPuntero) {
  int opcionSeleccionada;
  string clienteNombreCompleto;

  clienteNombreCompleto = clienteNodoPuntero->cliente.nombres + " " +
                          clienteNodoPuntero->cliente.apellidos;

  do {
    opcionSeleccionada =
        pedirOpcionDelMenuCliente(deltron, clienteNombreCompleto);

    if (opcionSeleccionada != 0) {
      switch (opcionSeleccionada) {
        case 1:
          pauseProcess();
          break;

        default:
          break;
      }
    }

  } while (!(opcionSeleccionada == 0));

  cout << endl << "Cerrando Sesión" << endl;
}

void menuLoginEmpleado(deltronStruct& deltron) {
  empleadoNodo* empleadoLogeado;
  int opcionSeleccionadaDelMenuLogin;

  do {
    opcionSeleccionadaDelMenuLogin =
        pedirOpcionDelMenuLogin(deltron, "Empleado");

    if (opcionSeleccionadaDelMenuLogin != 0) {
      switch (opcionSeleccionadaDelMenuLogin) {
        case 2:
          registrarEmpleado(deltron);
        case 1:
          empleadoLogeado = loginEmpleado(deltron);

          if (empleadoLogeado != NULL) {
            menuEmpleado(deltron, empleadoLogeado);
          } else {
            cout << endl;
            cout << endl << "Intente nuevamente o registrese" << endl;
          }

          break;

        default:
          break;
      }
    }

  } while (!(opcionSeleccionadaDelMenuLogin == 0));

  cout << endl << "Volviendo" << endl;
}

void menuLoginCliente(deltronStruct& deltron) {
  clienteNodo* clienteLogeado;
  int opcionSeleccionadaDelMenuLogin;

  do {
    opcionSeleccionadaDelMenuLogin =
        pedirOpcionDelMenuLogin(deltron, "Cliente");

    if (opcionSeleccionadaDelMenuLogin != 0) {
      switch (opcionSeleccionadaDelMenuLogin) {
        case 2:
          registrarCliente(deltron);
        case 1:
          clienteLogeado = loginCliente(deltron);

          if (clienteLogeado != NULL) {
            menuCliente(deltron, clienteLogeado);
          } else {
            cout << endl;
            cout << endl << "Intente nuevamente o registrese" << endl;
          }

          break;

        default:
          break;
      }
    }

  } while (!(opcionSeleccionadaDelMenuLogin == 0));

  cout << endl << "Volviendo" << endl;
}

void menuPrincipal(deltronStruct& deltron) {
  int opcionSeleccionadaDelMenuRol;
  bool debeCerrar;

  do {
    opcionSeleccionadaDelMenuRol = pedirOpcionDelMenuRol(deltron);

    if (opcionSeleccionadaDelMenuRol != 0) {
      switch (opcionSeleccionadaDelMenuRol) {
        case 1:
          menuLoginEmpleado(deltron);
          debeCerrar = false;
          break;

        case 2:
          menuLoginCliente(deltron);
          debeCerrar = false;
          break;

        default:
          debeCerrar = true;
          break;
      }
    }

  } while (!(opcionSeleccionadaDelMenuRol == 0) && !debeCerrar);
}
