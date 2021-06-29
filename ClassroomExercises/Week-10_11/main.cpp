#include "menu.h"

using namespace std;

int main(int argc, char *argv[]) {
  citiesGraph cities;

  collectionsInitialization(cities);
  dataInitialization(cities);

  mainMenu(cities);

  return 0;
}
