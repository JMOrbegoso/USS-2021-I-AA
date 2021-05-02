#include "menu.h"

using namespace std;

int main() {
  departmentStruct department;

  collectionsInitialization(department);
  dataInitialization(department);

  mainMenu(department);

  return 0;
}
