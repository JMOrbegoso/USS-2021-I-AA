#include <iostream>

#include "basicas.h"

using namespace std;

struct libros {
  string titulo;
  string fPublicacion;
  string autor;
  unsigned short nPaginas;
  string editorial;
};

struct nodoL {
  libros info;
  nodoL *sgte;
  nodoL *ant;
};

struct pilaLibros {
  int nLib;
  nodoL *cab;
};

struct estante {
  unsigned short numero;
  string capacidad;
  string tematica;
  pilaLibros lL;
};

struct nodoE {
  estante stan;
  nodoE *sgte;
  nodoE *ant;
};

struct pilaEstantes {
  int nEstan;
  nodoE *cab;
};

struct salas {
  string nombre;
  string horaInicio;
  string horaFin;
  string carrera;
  string capacidad;
  pilaEstantes lE;
};

struct nodoS {
  salas sala;
  nodoS *sgte;
  nodoS *ant;
};

struct pilaSalas {
  int nSalas;
  nodoS *cab;
};
