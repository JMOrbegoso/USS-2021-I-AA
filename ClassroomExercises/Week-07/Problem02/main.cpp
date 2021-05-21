//
// Realizar un algoritmo que calcule el factorial de un numero
//

#include <iostream>

using namespace std;

int requestIntegerNumber(string requestMessage, string errorMessage, int min) {
  int integer;

  cout << requestMessage << endl;
  cin >> integer;

  while (!(min <= integer)) {
    cout << errorMessage << endl;
    fflush(stdin);
    cin >> integer;
  }

  return integer;
}

int requestIntegerNumber(string requestMessage, string errorMessage, int min,
                         int max) {
  int integer;

  cout << requestMessage << endl;
  cin >> integer;

  while (!(min <= integer && integer <= max)) {
    cout << errorMessage << endl;
    fflush(stdin);
    cin >> integer;
  }

  return integer;
}

int getFactorial(int num) {
  if (num <= 1) // caso base
    return 1;

  return num * getFactorial(num - 1);
}

int getFactorialWithLoop(int num) {
  int factorial = 1;

  for (int i = num; i >= 1; i--) {
    factorial *= i;
  }

  return factorial;
}

int main(int argc, char *argv[]) {
  int num = requestIntegerNumber(
      "Ingrese el numero del que quiere calcular el factorial",
      "corrija el numero", 0, 10);

  cout << "El factorial es " << getFactorial(num) << endl;
  cout << "El factorial es " << getFactorialWithLoop(num) << endl;

  return 0;
}
