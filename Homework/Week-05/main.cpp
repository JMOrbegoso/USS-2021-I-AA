//
//                                EJERCICIOS DE COLAS
// En un banco se tiene colas de clientes que llegan a presentar sus expedientes
// los cuales están ordenados por número y serán atendidos en ese orden.
// Realizar un programa que permita registrar la cola de clientes y de cada
// cliente registrar los expedientes que llevará al banco. Registrar persona
// Registrar expedientes
// Buscar persona
// Buscar expediente
// Listar personas
// Mostrar expedientes de una persona
//

#include "menu.h"

using namespace std;

int main(int argc, char *argv[]) {
  bankStruct bank;

  collectionsInitialization(bank);
  dataInitialization(bank);

  mainMenu(bank);

  return 0;
}
