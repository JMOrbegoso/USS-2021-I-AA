#include "menu.h"

using namespace std;

int main() {
  personsQueue persons;

  collectionsInitialization(persons);
  dataInitialization(persons);

  mainMenu(persons);

  return 0;
}
