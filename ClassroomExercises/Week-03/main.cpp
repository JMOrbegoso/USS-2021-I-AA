#include "menu.h"

using namespace std;

int main() {
  authorsList authors;

  collectionsInitialization(authors);
  dataInitialization(authors);

  mainMenu(authors);

  return 0;
}
