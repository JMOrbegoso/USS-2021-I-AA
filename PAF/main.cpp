#include "menu.h"

using namespace std;

int main(int argc, char *argv[]) {
  deltronStruct deltron;

  inicializacionDeColecciones(deltron);
  inicializacionDeData(deltron);

  mostrarPresentacionEInstrucciones();
  menuPrincipal(deltron);

  return 0;
}
