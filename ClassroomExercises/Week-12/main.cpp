#include <ctime>
#include <iostream>

#define limit 100

using namespace std;

int main(int argc, char *argv[]) {
  unsigned startTime, endTime;

  startTime = clock();

  for (int x = 0; x <= limit; x++) {
    cout << " X: " << x << endl;
  }

  endTime = clock();

  double total = (double(endTime - startTime)) / CLOCKS_PER_SEC;

  cout << endl;
  cout << "Tiempo de ejecución: " << total << " ms";
  cout << endl;

  system("pause");

  return 0;
}
