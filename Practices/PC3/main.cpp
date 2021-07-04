/*
En una ciudad existen varias sucursales del banco Bravs.
Las sucursales se ubican en distintas calles,
pero se lleva un registro de que bancos se comunican entre ellos.

Dentro de las sucursales del banco existen trabajadores que,
si bien pertenecen al banco,
se lleva un registro de ellos en la sucursal.

Los clientes si pertenecen al banco y se pueden registrar en cualquier sucursal.

Se debe guardar en que sucursal se registró.

En base a ello:
-	Registrar sucursales
-	Registrar clientes
-	Registrar trabajadores
-	Elegir una sucursal y mostrar la cola de atenciones
-	Elegir una sucursal y mostrar la lista de trabajadores
-	Buscar un cliente
*/

#include "menu.h"

using namespace std;

int main(int argc, char *argv[]) {
  bankStruct bank;

  collectionsInitialization(bank);
  dataInitialization(bank);

  mainMenu(bank);

  return 0;
}
