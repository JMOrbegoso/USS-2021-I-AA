//
// Realizar un algoritmo recursivo que muestre
// los 20 primeros numeros naturales
//

#include <iostream>

using namespace std;

int showNumber(int num) {
  if (num >= 1) // caso base
    cout << showNumber(num - 1) << endl;

  return num;
}

int main(int argc, char *argv[]) {
  int num = 6;
  showNumber(num);

  return 0;
}
