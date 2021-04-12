#include "menu.h"

using namespace std;

int main() {
  clinicStruct clinic;

  collectionsInitialization(clinic);
  dataInitialization(clinic);

  mainMenu(clinic);

  return 0;
}
