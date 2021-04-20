#include "menu.h"

using namespace std;

int main() {
  concessionaireStruct concessionaire;

  collectionsInitialization(concessionaire);
  dataInitialization(concessionaire);

  mainMenu(concessionaire);

  return 0;
}
