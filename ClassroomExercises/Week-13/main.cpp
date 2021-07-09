#include "menu.h"

using namespace std;

int main(int argc, char *argv[]) {
  studentsList students;

  collectionsInitialization(students);
  dataInitialization(students);

  mainMenu(students);

  return 0;
}
