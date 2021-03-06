#include "opcionesMenu.h"

using namespace std;

void mostrarPresentacion() {
  cout << "\t\t\t\t"
       << "Bienvenido al PAF del curso de Análisis de algoritmos [2021-I]"
       << endl
       << endl;
  cout << "\t"
       << "Desarrollado por el Grupo #08:" << endl
       << endl;
  cout << "->\tOrbegoso Rosas Juan Manuel" << endl;
  cout << "->\tGutiérrez Chávez Sebastián Andree" << endl;
  cout << "->\tSantamaria Flores Luzmila" << endl;
  cout << "->\tVílchez Ruiz Juan Ismael" << endl;
  cout << "->\tSánchez Sánchez Joselyn" << endl;
}

void mostrarInstrucciones() {
  cout << "\t"
       << "Instrucciones:" << endl
       << endl;
  cout << "->\tPara iniciar sesión como empleado puede registrarse o usar la "
          "cuentas ya registrada:"
       << endl;
  cout << "\tDNI: '11111111'." << endl;
  cout << endl;
  cout << "->\tPara iniciar sesión como cliente puede registrarse o usar una "
          "de las cuentas ya registradas:"
       << endl;
  cout << "\tDNI: '12121212'." << endl;
  cout << endl;
  cout << "->\tLa clave de estas cuentas de usuario ya creadas es '123456'."
       << endl;
}

void mostrarPresentacionEInstrucciones() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, 3);

  mostrarPresentacion();
  cout << endl << endl;
  mostrarInstrucciones();

  SetConsoleTextAttribute(hConsole, 15);
  system("pause");
  esperarMostrandoTexto("Abriendo sistema virtual de la empresa Deltron SAC");
  system("cls");
}

int pedirOpcionDelMenuRol(deltronStruct deltron) {
  int opcionSeleccionada;

  system("cls");
  mostrarDatosEmpresa(deltron);

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

  system("cls");
  mostrarDatosEmpresa(deltron);

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

  system("cls");
  mostrarDatosEmpresa(deltron);

  cout << endl;

  cout << "\t\t\tBienvenido " << nombreEmpleado;
  cout << endl;

  cout << endl << "¿Que desea hacer?" << endl;
  cout << endl;
  cout << "[1] Mostrar todas las ventas" << endl;
  cout << "[2] Registrar nuevo producto en almacén" << endl;
  cout << "[3] Editar producto en almacén" << endl;
  cout << "[4] Registrar persona formando cola para recoger producto" << endl;
  cout << "[5] Entregar compra a persona formando cola (despachar)" << endl;
  cout << "[6] Listar almacénes" << endl;
  cout << "[7] Registrar nuevo almacén" << endl;
  cout << "[8] Registrar relación entre almacenes" << endl;
  cout << endl;
  cout << "[0] Cerrar Sesión" << endl;

  cout << endl << "Introduzca la opción deseada:" << endl;
  cin >> opcionSeleccionada;
  while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 8)) {
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

  system("cls");
  mostrarDatosEmpresa(deltron);

  cout << endl;

  cout << "\t\t\tBienvenid@ " << razonSocialCliente;
  cout << endl;

  cout << endl << "¿Que desea hacer?" << endl;
  cout << endl;
  cout << "[1] Revisar catalogo de productos de un almacen" << endl;
  cout << "[2] Buscar producto en todos los almacenes" << endl;
  cout << "[3] Añadir producto al carrito de compras" << endl;
  cout << "[4] Editar cantidad de un producto en el carrito de compras" << endl;
  cout << "[5] Quitar producto del carrito de compras" << endl;
  cout << "[6] Realizar compra" << endl;
  cout << endl;
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

void menuEmpleado(deltronStruct& deltron, empleadoNodo* empleadoLogeado) {
  int opcionSeleccionada;
  string empleadoNombreCompleto;

  empleadoNombreCompleto = empleadoLogeado->empleado.nombres + " " +
                           empleadoLogeado->empleado.apellidos;

  do {
    opcionSeleccionada =
        pedirOpcionDelMenuEmpleado(deltron, empleadoNombreCompleto);

    if (opcionSeleccionada != 0) {
      switch (opcionSeleccionada) {
        case 1:
          revisarVentas(deltron, empleadoLogeado);
          system("pause");
          break;
        case 2:
          registrarProductoEnAlmacen(deltron, empleadoLogeado);
          Sleep(1500);
          break;
        case 3:
          editarProductoEnAlmacen(deltron, empleadoLogeado);
          Sleep(1500);
          break;
        case 4:
          registrarPersonaEnCola(deltron, empleadoLogeado);
          Sleep(1500);
          break;
        case 5:
          despacharVenta(deltron, empleadoLogeado);
          Sleep(1500);
          break;
        case 6:
          revisarAlmacenes(deltron, empleadoLogeado);
          system("pause");
          break;
        case 7:
          registrarNuevoAlmacen(deltron, empleadoLogeado);
          Sleep(1500);
          break;
        case 8:
          registrarRelacionEntreAlmacenes(deltron, empleadoLogeado);
          Sleep(1500);
          break;

        default:
          break;
      }
    }

  } while (!(opcionSeleccionada == 0));

  cout << endl << "Cerrando Sesión" << endl;
}

void menuCliente(deltronStruct& deltron, clienteNodo* clienteLogeado) {
  int opcionSeleccionada;
  string clienteNombreCompleto;

  clienteNombreCompleto =
      clienteLogeado->cliente.nombres + " " + clienteLogeado->cliente.apellidos;

  do {
    opcionSeleccionada =
        pedirOpcionDelMenuCliente(deltron, clienteNombreCompleto);

    if (opcionSeleccionada != 0) {
      switch (opcionSeleccionada) {
        case 1:
          revisarCatalogoDeAlmacen(deltron, clienteLogeado);
          system("pause");
          break;
        case 2:
          buscarProductoEnAlmacenes(deltron, clienteLogeado);
          system("pause");
          break;
        case 3:
          agregarProductoAlCarrito(deltron, clienteLogeado);
          Sleep(1500);
          break;
        case 4:
          editarCantidadDeProductoEnCarrito(deltron, clienteLogeado);
          Sleep(1500);
          break;
        case 5:
          quitarProductoDeCarrito(deltron, clienteLogeado);
          Sleep(1500);
          break;
        case 6:
          realizarCompra(deltron, clienteLogeado);
          Sleep(1500);
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
