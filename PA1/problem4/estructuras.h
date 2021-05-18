#include <iostream>
#include <windows.h>

using namespace std;

struct jugador{
    string apellidos;
    string nombres;
    string posicion;
    unsigned short edad;
    float peso;
    float talla;
};

struct equipo{
    string codigo;
    string nombre;
    string ciudad;
    string estadio;
    string entrenador;
    jugador listaJugadores[nJug];
    unsigned short cantidad;
};

struct nodoEquipo{
    equipo info;
    nodoEquipo *sgte;
};

struct listaEquipos{
    nodoEquipo *cab;
    unsigned short nEquipos;
};
