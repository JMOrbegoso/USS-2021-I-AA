#include "structFunctions.h"

void showAppTitle(deltronStruct deltron) {
  cout << endl;
  cout << "-----------------------------------------------------------";
  cout << endl << endl;
  cout << "\t Sistema virtual de la empresa " << deltron.razonSocial;
  cout << "RUC: " << deltron.ruc;
  cout << endl << endl;
  cout << "-----------------------------------------------------------";
  cout << endl;
}
