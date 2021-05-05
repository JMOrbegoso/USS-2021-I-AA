#include "menu.h"

using namespace std;

int main() {
  concessionaireStruct concessionaire;

  concessionaire = buildConcessionaireStruct();

  dataInitialization(concessionaire);

  mainMenu(concessionaire);

  return 0;
}
