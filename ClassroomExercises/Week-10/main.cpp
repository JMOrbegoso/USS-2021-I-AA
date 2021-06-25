#include "menu.h"

using namespace std;

int main(int argc, char *argv[]) {
  grafoStruct grafo;

  collectionsInitialization(grafo);
  dataInitialization(grafo);

  mainMenu(grafo);

  return 0;
}
