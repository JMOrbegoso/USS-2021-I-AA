#include "menu.h"

using namespace std;

int main(int argc, char *argv[]) {
  deltronStruct deltron;

  inicializacionDeColecciones(deltron);
  inicializacionDeData(deltron);

  menuPrincipal(deltron);

  return 0;
}
