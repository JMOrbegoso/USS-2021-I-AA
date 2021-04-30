#include "menu.h"

using namespace std;

int main() {
  libraryStruct library;

  collectionsInitialization(library);
  dataInitialization(library);

  mainMenu(library);

  return 0;
}
