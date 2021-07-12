#include <iostream>
#include "basicas.h"

using namespace std; 

struct libros{
	string titulo;
	string fPublicacion;
	string autor;
	unsigned short nPaginas;
	string editorial;
};

struct nodoL{
    libros info;
    nodoL *sgte;
    nodoL *ant;
};

struct listaLibros{
    int nLib;
    nodoL *cab;
};

struct estante{
	unsigned short numero;
	string capacidad;
	string tematica;
	listaLibros lL; 
};

struct nodoE{
    estante stan;
    nodoE *sgte;
    nodoE *ant;
};

struct listaEstantes{
    int nEstan;
    nodoE *cab;
};

struct salas{
	string nombre;
	string horaInicio;
	string horaFin;
	string carrera;
	string capacidad;
	listaEstantes lE;
};

struct nodoS{
    salas sala;
    nodoS *sgte;
    nodoS *ant;
};

struct listaSalas{
    int nSalas;
    nodoS *cab;
};

