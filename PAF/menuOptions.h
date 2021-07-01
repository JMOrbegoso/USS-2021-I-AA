#include "structFunctions.h"

void showAppTitle(deltronStruct deltron) {
  cout << endl;
  cout << "-----------------------------------------------------------";
  cout << endl << endl;
  cout << "\t Sistema virtual de la empresa " << deltron.razonSocial;
  cout << endl << endl;
  cout << "RUC: " << deltron.ruc;
  cout << endl << endl;
  cout << "-----------------------------------------------------------";
  cout << endl;
}

void registrarEmpleado(deltronStruct& deltron) {
  cout << endl << "SE ESTÁ REGISTRANDO" << endl;
  addDelay(1.5);
}

void registrarCliente(deltronStruct& deltron) {
  cout << endl << "SE ESTÁ REGISTRANDO" << endl;
  addDelay(1.5);
}

empleadoNodo* loginEmpleado(deltronStruct deltron) {
  cout << endl << "ESTÁ HACIENDO LOGIN" << endl;
  addDelay(1.5);
  return NULL;
}

clienteNodo* loginCliente(deltronStruct deltron) {
  cout << endl << "ESTÁ HACIENDO LOGIN" << endl;
  addDelay(1.5);
  return NULL;
}