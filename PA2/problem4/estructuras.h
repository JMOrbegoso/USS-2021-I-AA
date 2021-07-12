#include <iostream>
using namespace std;
//Afiliados pertenecen a los partidos
struct afiliado{
	string apellidos;
	string nombres;
	int edad;
	string dni;
	string direccion;
	string profesion;
	string email;
	double sueldo;
};
struct nodoA{
	afiliado info;
	nodoA *sgte;
};
struct colaAfiliados{
	nodoA *adelante;
	nodoA *atras;
	unsigned short nAfiliados;
};
//Partido politico 
struct partidosPolitico{
	string nombre;
	string descripcion;
	string fechaCreacion;
	colaAfiliados cA;
};
struct nodoPP{
	partidosPolitico info;
	nodoPP *sgte;
};
struct colaPP{
	nodoPP *adelante;
	nodoPP *atras;
	unsigned short nPP;
};

