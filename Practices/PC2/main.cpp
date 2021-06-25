#include "menu.h"

using namespace std;

int main(int argc, char *argv[]) {
  libraryStruct library;

  collectionsInitialization(library);
  dataInitialization(library);

  mainMenu(library);

  return 0;
}
