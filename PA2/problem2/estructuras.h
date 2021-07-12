#include <iostream>

#include "basicas.h"

using namespace std;

struct persona {
  string nombre, apellidos, dni;
  string sala;
  string cantidad;
  string pelicula;
  unsigned short edad;
};

struct nodoP {
  persona per;
  nodoP *sgte;
};

struct colaPersonas {
  nodoP *adelante;
  nodoP *atras;
  unsigned short nPersonas;
};

struct pelicula {
  string nombre;
  unsigned short duración;
  unsigned short sala;
  unsigned short cantidad;
};

struct nodoPe {
  pelicula peli;
  nodoPe *sgte;
};

struct pilaPelicula {
  nodoPe *cima;
  unsigned short nPeliculas;
};

struct sala {
  string numero;
  pilaPelicula pelicula;
  colaPersonas persona;
};

struct nodoS {
  sala info;
  nodoS *sgte;
  nodoS *ant;
};

struct pilaSalas {
  int nSalas;
  nodoS *cab;
};
