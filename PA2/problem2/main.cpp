#include <windows.h>

#include <iostream>

#include "estructuras.h"

using namespace std;

void inicializar(pilaSalas &listado) {
  listado.cab = NULL;
  listado.nSalas = 0;
}

void inicializaSalas(pelicula &peli) {
  peli.duración = 0;
  peli.sala = 0;
}

void leerSala(pelicula &peli) {
  system("cls");
  gotoxy(35, 3);
  cout << "==PELICULA==";
  gotoxy(35, 4);
  cout << "============";
  gotoxy(30, 5);
  peli.sala = leerEntero("Ingrese numero de sala:");
  gotoxy(30, 6);
  peli.nombre = leerTexto("Ingrese nombre:");
  gotoxy(30, 8);
  peli.duración = leerReal("Ingrese duración::");
  gotoxy(30, 9);
  peli.cantidad = leerReal("Ingrese cantidad de personas:");
}

void push(pilaSalas &listado, pelicula peli) {
  nodoS *aux;
  aux = new (struct nodoS);
  aux->info = peli;
  aux->sgte = listado.cab;
  listado.cab = aux;
  listado.nSalas++;
}

void apilar(pilaSalas &listado) {
  pelicula peli;
  inicializaSalas(peli);
  leerSala(peli);
  push(listado, peli);
}

void mostrarPelicula(pelicula peli) {
  // system("cls");
  gotoxy(30, 5);
  cout << "PELICULA";
  gotoxy(30, 6);
  cout << "=======";
  gotoxy(30, 7);
  cout << "NOMBRE         :" << peli.nombre;
  gotoxy(30, 8);
  cout << "N° SALA        :" << peli.sala;
  gotoxy(30, 9);
  cout << "DURACION       :" << peli.duración;
  gotoxy(30, 10);
  cout << "CANTIDAD      :" << peli.cantidad;
  Sleep(2000);
}

void inicializar(colaPersonas &cP) {
  cP.adelante = NULL;
  cP.atras = NULL;
  cP.nPersonas = 0;
}

persona leerPersona() {
  persona per;
  system("cls");
  gotoxy(35, 3);
  cout << "REGISTRAR PERSONA";
  gotoxy(35, 4);
  per.apellidos = leerTexto("Ingrese Apellidos :");
  gotoxy(35, 5);
  per.nombre = leerTexto("Ingrese Nombres :");
  gotoxy(35, 6);
  per.edad = leerEntero("Ingrese Edad :");
  gotoxy(35, 7);
  per.dni = leerTexto("Ingrese DNI :");
  gotoxy(35, 8);
  per.pelicula = leerTexto("Ingrese Pelicula :");
  gotoxy(35, 7);
  per.cantidad = leerEntero("Ingrese cantidad de entradas :");
  gotoxy(35, 8);
  per.sala = leerEntero("Ingrese N° de sala :");
  return per;
}

void encolar(colaPersonas &cP, persona per) {
  nodoP *aux;
  aux = new (struct nodoP);
  aux->per = per;
  aux->sgte = NULL;
  if (cP.adelante == NULL) {
    cP.adelante = aux;
  } else {
    cP.atras->sgte = aux;
  }
  cP.atras = aux;
  cP.nPersonas++;
}

void registrarPersona(colaPersonas &cP) {
  persona per;
  per = leerPersona();
  encolar(cP, per);
}

void mostrarPersona(persona per) {
  system("cls");
  gotoxy(5, 30);
  cout << "Datos de la persona";
  gotoxy(5, 31);
  cout << "NOMBRES Y APELLIDOS  : " << per.nombre << ", " << per.apellidos;
  gotoxy(5, 32);
  cout << "EDAD                 : " << per.edad;
  gotoxy(5, 33);
  cout << "DNI                  : " << per.dni;
  gotoxy(5, 34);
  cout << "PELICULA             : " << per.pelicula;
  gotoxy(5, 34);
  cout << "CANTIDAD             : " << per.cantidad;
  gotoxy(5, 34);
  cout << "SALA                 : " << per.sala;
}

void buscarPersona(colaPersonas cP) {
  nodoP *aux;
  string apellidos, nombres;
  system("cls");
  if (colaVacia(cP) == FALSE) {
    fflush(stdin);
    apellidos = leerTexto("Ingrese apellidos persona a buscar:");
    nombres = leerTexto("Ingrese nombre persona a buscar:");
    aux = cP.adelante;
    while (aux != NULL) {
      if (apellidos == aux->per.apellidos && nombres == aux->per.nombre) {
        mostrarPersona(aux->per);
        break;
      }
      aux = aux->sgte;
    }
  } else {
    gotoxy(35, 5);
    cout << "No hay nadie en la cola";
  }
  Sleep(2000);
}

int main() {
  salas listado;
  inicializar(listado);
  int opc;
  do {
    opc = menu();
    switch (opc) {
      case 1:
        leerSalas(listado);
        break;
      case 2:
        mostrarPelicula(listado);
        break;
      case 3:
        leerPersona();
        break;
      case 4:
        mostrarPersona(cP);
        break;
      case 5:
        buscarPersona(cP);
        break;
    }
  } while (!(opc == 6));
  return 0;
}
