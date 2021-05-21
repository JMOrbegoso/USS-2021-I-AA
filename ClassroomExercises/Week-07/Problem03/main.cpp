//
// Hallar la suma de los terminos de la serie siguiente:
// suma = 1/1 + 1/2 + 1/3 + 1/4 + ......
//

#include <iostream>

using namespace std;

int sumFractions(int num) {
  float fraction = 1 / num;

  return fraction + sumFractions(num);
}

int main(int argc, char *argv[]) {
  cout << "La suma es " << sumFractions(1) << endl;

  return 0;
}
