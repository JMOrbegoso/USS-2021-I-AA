#include <iostream>

#include "estructuras.h"

/*Una biblioteca tiene salas con sus datos (nombre de la sala, hora inicio de
atenci�n, hora fin de atenci�n, carrera profesional y capacidad). Cada sala
contiene estantes (n�mero de estante, capacidad y tem�tica). Cada estante tiene
libros (t�tulo, a�o de publicaci�n, autor, n�mero de p�ginas y editorial)
Elaborar un programa que use estructuras din�micas y permita:
- Registrar una sala
- Registrar un estante que pertenecen a salas
- Registrar libros que se ubican en estantes
- Buscar un libro
- Listar los libros de un estante
- Listar las salas
*/

using namespace std;

void inicializaSalas(pilaSalas &lS) {
  lS.cab = NULL;
  lS.nSalas = 0;
}

void inicializaEstante(pilaEstantes &lE) {
  lE.cab = NULL;
  lE.nEstan = 0;
}

void inicializaLibros(pilaLibros &lL) {
  lL.cab = NULL;
  lL.nLib = 0;
}

void leerLibros(libros &lib) {
  system("cls");
  gotoxy(25, 4);
  cout << "DATOS DEL LIBRO";
  gotoxy(25, 5);
  cout << "================";
  gotoxy(20, 6);
  lib.titulo = leerTexto("Ingrese Titulo:");
  gotoxy(20, 7);
  lib.fPublicacion = leerTexto("Ingrese A;o de Publicacion :");
  gotoxy(20, 8);
  lib.autor = leerTexto("Ingrese Autor :");
  gotoxy(20, 9);
  lib.nPaginas = leerEntero("Ingrese N? de Paginas :");
  gotoxy(20, 10);
  lib.editorial = leerTexto("Ingrese Editorial :");
}

void insertarLibros(pilaLibros &lL, libros lib) {
  nodoL *aux = new (struct nodoL);
  nodoL *temp = new (struct nodoL);
  temp->info = lib;
  temp->sgte = NULL;
  if (lL.cab == NULL) {
    lL.cab = temp;
    lL.cab->ant = NULL;
  } else {
    aux = lL.cab;
    while (aux->sgte != NULL) {
      aux = aux->sgte;
    }
    aux->sgte = temp;
    temp->ant = aux;
  }
  lL.nLib++;
}

nodoE *iterarEstantes(pilaEstantes estan, int index) {
  nodoE *nodoEPuntero;

  if (0 >= index) {
    return NULL;
  }

  if (index > estan.nEstan) {
    return NULL;
  }

  nodoEPuntero = estan.cab;

  for (int i = 1; nodoEPuntero != NULL; i++) {
    if (i == index) {
      return nodoEPuntero;
    }
    nodoEPuntero = nodoEPuntero->sgte;
  }
  return NULL;
}

nodoE *pedirEstante(pilaEstantes estan, string mensaje) {
  int selectedOption;
  nodoE *nodoEPuntero;

  cout << endl
       << mensaje << "." << endl
       << "Escoja entre los " << estan.nEstan << " estantes siguientes:" << endl
       << endl;

  nodoEPuntero = estan.cab;

  for (int i = 1; nodoEPuntero != NULL; i++) {
    cout << "[" << i << "] - " << nodoEPuntero->stan.tematica << endl;
    nodoEPuntero = nodoEPuntero->sgte;
  }

  cout << endl << "Introduzca la opci�n deseada:" << endl;
  cin >> selectedOption;

  while (!(1 <= selectedOption && selectedOption <= estan.nEstan)) {
    cout << "Por favor, introduzca un valor entre 1 y " << estan.nEstan << "."
         << endl;
    fflush(stdin);
    cin >> selectedOption;
  }
  return iterarEstantes(estan, selectedOption);
}

void registrarLibros(pilaEstantes &le) {
  nodoE *auxE;
  libros lib;
  leerLibros(lib);

  // Preguntar al usuario en que estante quiere guardarlo
  auxE = pedirEstante(le, "Ingrese El estante del nuevo libro");
  if (auxE == NULL) {
    cout << "El estante seleccionado no es valido" << endl;
    return;
  }
  insertarLibros(auxE->stan.lL, lib);
}

void leerEstante(estante &estan) {
  system("cls");
  gotoxy(25, 4);
  cout << "DATOS DEL ESTANTE";
  gotoxy(25, 5);
  cout << "================";
  gotoxy(20, 6);
  estan.numero = leerEntero("Ingrese N?:");
  gotoxy(20, 7);
  estan.capacidad = leerTexto("Ingrese Nombre :");
  gotoxy(20, 8);
  estan.tematica = leerTexto("Ingrese Posicion :");
}

void insertarEstante(pilaEstantes &lE, estante estan) {
  nodoE *aux = new (struct nodoE);
  nodoE *temp = new (struct nodoE);
  temp->stan = estan;
  temp->sgte = NULL;
  if (lE.cab == NULL) {
    lE.cab = temp;
    lE.cab->ant = NULL;
  } else {
    aux = lE.cab;
    while (aux->sgte != NULL) {
      aux = aux->sgte;
    }
    aux->sgte = temp;
    temp->ant = aux;
  }
  lE.nEstan++;
}

nodoS *iterarSalas(pilaSalas salas, int index) {
  nodoS *nodoSPuntero;

  if (0 >= index) {
    return NULL;
  }

  if (index > salas.nSalas) {
    return NULL;
  }

  nodoSPuntero = salas.cab;

  for (int i = 1; nodoSPuntero != NULL; i++) {
    if (i == index) {
      return nodoSPuntero;
    }
    nodoSPuntero = nodoSPuntero->sgte;
  }

  return NULL;
}

nodoS *pedirSala(pilaSalas salas, string mensaje) {
  int selectedOption;
  nodoS *nodoSPuntero;

  cout << endl
       << mensaje << "." << endl
       << "Escoja entre las " << salas.nSalas << " salas siguientes:" << endl
       << endl;

  nodoSPuntero = salas.cab;

  for (int i = 1; nodoSPuntero != NULL; i++) {
    cout << "[" << i << "] - " << nodoSPuntero->sala.nombre << endl;
    nodoSPuntero = nodoSPuntero->sgte;
  }

  cout << endl << "Introduzca la opci�n deseada:" << endl;
  cin >> selectedOption;

  while (!(1 <= selectedOption && selectedOption <= salas.nSalas)) {
    cout << "Por favor, introduzca un valor entre 1 y " << salas.nSalas << "."
         << endl;
    fflush(stdin);
    cin >> selectedOption;
  }

  return iterarSalas(salas, selectedOption);
}

void registrarEstante(pilaSalas &ls) {
  nodoS *aux;
  estante estan;
  leerEstante(estan);

  // Preguntar al usuario a que sala quiere guardarlo
  aux = pedirSala(ls, "Ingrese la sala del nuevo estante");
  if (aux == NULL) {
    cout << "La sala seleccionada no es valida" << endl;
    return;
  }
  insertarEstante(aux->sala.lE, estan);
}

void leerSalas(salas &salas) {
  system("cls");
  gotoxy(25, 4);
  cout << "****** INFORMACION DE LA SALA ****** ";
  gotoxy(20, 5);
  salas.nombre = leerTexto("Nombre :");
  gotoxy(20, 6);
  salas.horaInicio = leerTexto("Hora de Atencion :");
  gotoxy(20, 7);
  salas.horaFin = leerTexto("Hora de Cierre :");
  gotoxy(20, 8);
  salas.carrera = leerTexto("Carrera:");
  gotoxy(20, 9);
  salas.capacidad = leerTexto("Capacidad :");
}

void insertarSalas(pilaSalas &lS, salas salas) {
  nodoS *aux = new (struct nodoS);
  nodoS *temp = new (struct nodoS);
  temp->sala = salas;
  temp->sgte = NULL;
  if (lS.cab == NULL) {
    lS.cab = temp;
    lS.cab->ant = NULL;
  } else {
    aux = lS.cab;
    while (aux->sgte != NULL) {
      aux = aux->sgte;
    }
    aux->sgte = temp;
    temp->ant = aux;
  }
  lS.nSalas++;
}

void registrarSalas(pilaSalas &lS) {
  salas salas;
  leerSalas(salas);
  insertarSalas(lS, salas);
}

void listarSalas(pilaSalas lS) {
  nodoS *aux;
  aux = lS.cab;
  for (int i = 0; aux != NULL; i++) {
    gotoxy(1, i + 10);
    cout << "Nombre de la sala: " << aux->sala.nombre;
    aux = aux->sgte;
  }
}

void listarEstantes(pilaSalas lS) {
  int i = 0;
  nodoS *auxSala;
  nodoE *auxEstante;
  auxSala = lS.cab;

  while (auxSala != NULL) {
    auxEstante = auxSala->sala.lE.cab;

    while (auxEstante != NULL) {
      gotoxy(1, i + 10);
      cout << "Nombre: " << auxEstante->stan.tematica;
      auxEstante = auxEstante->sgte;
    }
    auxSala = auxSala->sgte;
  }
}

void buscarLibro(pilaSalas lS) {
  nodoS *auxSala;
  nodoE *auxEstante;
  nodoL *auxLibro;
  string libroABuscar;

  cout << "Cual el es el nombre del libro";
  cin >> libroABuscar;

  auxSala = lS.cab;

  while (auxSala != NULL) {
    auxEstante = auxSala->sala.lE.cab;

    while (auxEstante != NULL) {
      auxLibro = auxEstante->stan.lL.cab;

      while (auxLibro != NULL) {
        if (auxLibro->info.titulo == libroABuscar) {
          cout << auxLibro->info.titulo;
        }

        auxLibro = auxLibro->sgte;
      }

      auxEstante = auxEstante->sgte;
    }

    auxSala = auxSala->sgte;
  }
}

int main() {
  pilaSalas lS;
  pilaEstantes lE;
  inicializaSalas(lS);
  inicializaEstante(lE);
  int opc;
  do {
    opc = menu();
    switch (opc) {
      case 1:
        registrarSalas(lS);
        break;
      case 2:
        registrarEstante(lS);
        break;
      case 3:
        registrarLibros(lE);
        break;
      case 4:
        buscarLibro(lS);
        break;
      case 5:
        listarEstantes(lS);
        break;
      case 6:
        listarSalas(lS);
        break;
    }
  } while (!(opc == 7));
  return 0;
}
