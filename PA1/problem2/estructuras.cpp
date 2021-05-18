#include <iostream>

using namespace std;

// Estudiante

struct estudiante {
  string nombre;
  string apellidos;
  string direccion;
  unsigned short edad;
  float promFinal;
  int asistencia;
};

struct nodoE {
  estudiante info;
  nodoE *sgte;
};

struct listaEstudiantes {
  int cant;
  nodoE *cab;
};

// Curso

struct curso {
  string codigo;
  string nombre;
  int creditos;
  int ciclo;
  listaEstudiantes estudiantes;
};

struct nodoC {
  curso info;
  nodoC *sgte;
  nodoC *ant;
};

struct listaCursos {
  int cant;
  nodoC *cab;
};

// Universidad

struct universidadStruct {
  string nombre;
  listaCursos cursos;
};
