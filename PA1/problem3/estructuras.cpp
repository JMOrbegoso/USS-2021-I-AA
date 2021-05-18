#include <iostream>

using namespace std;

struct postulante{
    string apellidos;
    string nombres;
    string DNI;
    string Email;
    string direccion;
    string Nombre_Escuela;
    float puntaje;
};
struct nodo_Postulante{
    postulante info;
    nodo_Postulante * sgt;
};
struct lista_Postulante{
    nodo_Postulante * cab;
    int N_Postulante;
};

struct escuelas{
    string nombre;
    string codigo;
    int ciclos;
    string titulo;
    lista_Postulante LP;
};

struct nodo_Escuelas{
    escuelas info;
    nodo_Escuelas * sgt;
    nodo_Escuelas * ant;
};
struct lista_Escuela{
    nodo_Escuelas * cab;
    int N_Escuelas;
};
