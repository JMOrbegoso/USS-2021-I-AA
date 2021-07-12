#include <iostream>
#include <windows.h>
#include "basicas.h"
using namespace std;
/*. Registrar los datos de las elecciones. En ellas se registran los partidos políticos (nombre,
descripción, fecha de creación, cantidad de afiliados) y sus afiliados (apellidos, nombres,
edad, DNI, dirección, profesión, email y sueldo).
Se pide elaborar un programa que:
- Registre un partido
- Registre un afiliado a un partido
- Busque un afiliado
- Elimine un afiliado
- Elimine un partido
- Mostrar la lista de partidos
- Mostrar la lista de afiliados a un partido
*/
void inicializa(colaPP &cPP){
	cPP.adelante = NULL;
	cPP.atras = NULL;
	cPP.nPP = 0;
}
void inicializaAf(afiliado &af){
	af.edad = 0;
	af.sueldo = 0;
}
partidosPolitico leerPartido(){
	partidosPolitico pP;
	afiliado af;
	inicializaAf(af);
	system("cls");
	gotoxy(35,5); cout<<"Registrar partido politico";
	gotoxy(30,6); pP.nombre= leerTexto("Ingrese nombre: ");
	gotoxy(30,7); pP.descripcion= leerTexto("Ingrese descripcion: ");
	gotoxy(30,8); pP.fechaCreacion= leerTexto("Ingrese fechaCreacion: ");
	return pP;
}
void encolarPartido(colaPP &cPP, partidosPolitico pP){
	nodoPP *aux;
	aux = new (struct nodoPP);
	aux->info = pP;
	aux->sgte = NULL;
	if (cPP.adelante == NULL){
		cPP.adelante = aux;
	}else{
		cPP.atras->sgte = aux;
	}
	cPP.atras = aux;
	cPP.nPP++;
}
nodoPP *iterarGrafoAlmacenes(colaPP almacenes, int index) {
  nodoPP *nodoPpPuntero;
  if (0 >= index) {
    return NULL;
  }
  if (index > almacenes.nPP) {
    return NULL;
  }
  nodoPpPuntero = almacenes.adelante;
  for (int i = 1; nodoPpPuntero != NULL; i++) {
    if (i == index) {
      return nodoPpPuntero;
    }
    nodoPpPuntero = nodoPpPuntero->sgte;
  }
  return NULL;
}
nodoPP *pedirPartidoPolitico(colaPP partidosPoliticos, string mensaje) {
  int selectedOption;
  nodoPP *nodoPpPuntero;
  cout << endl
       << mensaje << "." << endl
       << "Escoja entre los " << partidosPoliticos.nPP
       << " partidos politicos siguientes:" << endl
       << endl;
  nodoPpPuntero = partidosPoliticos.adelante;
  for (int i = 1; nodoPpPuntero != NULL; i++) {
    cout << "[" << i << "] - " << nodoPpPuntero->info.nombre << endl;
    nodoPpPuntero = nodoPpPuntero->sgte;
  }
  cout << endl << "Introduzca la opción deseada:" << endl;
  cin >> selectedOption;
  while (!(1 <= selectedOption && selectedOption <= partidosPoliticos.nPP)) {
    cout << "Por favor, introduzca un valor entre 1 y " << partidosPoliticos.nPP
         << "." << endl;
    fflush(stdin);
    cin >> selectedOption;
  }
  return iterarGrafoAlmacenes(partidosPoliticos, selectedOption);
}
void registrarPartido(colaPP &cPP){
	partidosPolitico pP;
	pP = leerPartido();
	encolarPartido(cPP, pP);
}
afiliado leerAfiliado(){
	afiliado af;
	system("cls");
	gotoxy(35,5); cout<<"Registrar afiliado";
	gotoxy(30,6); af.apellidos= leerTexto("Ingrese apellidos: ");
	gotoxy(30,7); af.nombres= leerTexto("Ingrese nombres: ");
	gotoxy(30,8); af.edad= leerEdad("Ingrese edad: ");
	gotoxy(30,9); af.dni= leerTexto("Ingrese dni: ");
	gotoxy(30,10); af.direccion= leerTexto("Ingrese direccion: ");
	gotoxy(30,11); af.profesion= leerTexto("Ingrese profesion: ");
	gotoxy(30,12); af.email= leerTexto("Ingrese email: ");
	gotoxy(30,13); af.sueldo= leerReal("Ingrese sueldo: ");
	return af;
}
void encolarAfiliado(colaAfiliados &cA, afiliado af){
	nodoA *aux;
	aux = new (struct nodoA);
	aux->info = af;
	aux->sgte = NULL;
	if (cA.adelante == NULL){
		cA.adelante = aux;
	}else{
		cA.atras->sgte = aux;
	}
	cA.atras = aux;
	cA.nAfiliados++;
}
void registrarAfiliado(colaPP &cPP){
	afiliado af;
	af = leerAfiliado();
	encolarAfiliado(cPP.adelante->info.cA, af);
}
void mostrarPersona(afiliado af){
    system("cls");
    gotoxy(5, 30 ); cout << "Datos de la persona";
    gotoxy(5, 31 ); cout << "NOMBRES Y APELLIDOS  : " << af.nombres << ", " << af.apellidos;
    gotoxy(5, 32 ); cout << "DIRECCION            : " << af.direccion;
    gotoxy(5, 33 ); cout << "EDAD                 : " << af.edad;
    gotoxy(5, 34 ); cout << "EMAIL                : " << af.email;
}
bool colaVacia(colaPP cPP){
    if (cPP.adelante == NULL)
        return TRUE;        // Esta vacia
    else
        return FALSE;       // Tiene elementos
}
void buscarAfiliado(colaPP &cPP){
    nodoA *aux;
    string buscar;
    system("cls");
    if ( colaVacia(cPP) == FALSE ){
        fflush(stdin);
        buscar = leerTexto("Ingrese nombre a buscar:");
        aux = cPP.adelante->info.cA.adelante;
        while(aux != NULL){
            if (buscar == aux->info.nombres){
                mostrarPersona(aux->info);
                break;
            }
            aux = aux->sgte;
        }
    }
    else{
        gotoxy(35,5 );cout <<"No hay nadie en la cola";
    }
    Sleep(2000);
}
afiliado desencolar( colaPP &cPP ){
    afiliado af;
    nodoA *aux;
    aux = cPP.adelante->info.cA.adelante;
    af = aux->info;
    cPP.adelante->info.cA.adelante = cPP.adelante->info.cA.adelante->sgte;
    cPP.adelante->info.cA.nAfiliados--;
    delete aux;
    return af;
}
void eliminarAfiliado(colaPP &cPP){
    afiliado af;
    if ( colaVacia(cPP) == TRUE ){
        system("cls");
        gotoxy(35,5 );cout << "No hay personas en la cola";
    }
    else{
        af = desencolar(cPP);
        mostrarPersona(af);
    }
   Sleep(2000);
}
void mostrarPartido(partidosPolitico pP){
    system("cls");
    gotoxy(5, 30 ); cout << "Datos de la persona";
    gotoxy(5, 31 ); cout << "NOMBRE		: " << pP.nombre;
    gotoxy(5, 32 ); cout << "DESCRIPCION		: " << pP.descripcion;
    gotoxy(5, 33 ); cout << "FECHA DE CREACION		: " << pP.fechaCreacion;
}
partidosPolitico desencolarPartido( colaPP &cPP ){
    partidosPolitico pP;
    nodoPP *aux;
    aux = cPP.adelante;
    pP = aux->info;
    cPP.adelante = cPP.adelante->sgte;
    cPP.nPP--;
    delete aux;
    return pP;
}
void eliminarPartido(colaPP &cPP){
    partidosPolitico pP;
    if ( colaVacia(cPP) == TRUE ){
        system("cls");
        gotoxy(35,5 );cout << "No hay personas en la cola";
    }
    else{
        pP = desencolarPartido(cPP);
        mostrarPartido(pP);
    }
   Sleep(2000);
}
void encabezado(){
	gotoxy(35,5); cout<<"Partido";
	gotoxy(20,7); cout<<"N	NOMBRE	DESCRIPCION		FECHA DE CREACION";
}
void mostrar(partidosPolitico pP, int x){
	gotoxy(20,8+x); cout<<x+1;
	gotoxy(23,8+x); cout<<pP.nombre;
	gotoxy(35,8+x); cout<<pP.descripcion;
	gotoxy(45,8+x); cout<<pP.fechaCreacion;
}
void mostrarListaPartido(colaPP &cPP){
	nodoPP *aux;
	int x = 0;
	system("cls");
	encabezado();
	
	while(aux != NULL){
		mostrar(aux->info, x);
		aux = aux->sgte;
		x++;
		Sleep(2000);
	}
	system("pause");
}
void encabezadoAf(){
	gotoxy(35,5); cout<<"Afiliado";
	gotoxy(20,7); cout<<"N	NOMBRES	APELLIDOS	DNI	";
}
void mostrarAf(afiliado af, int x){
	gotoxy(20,8+x); cout<<x+1;
	gotoxy(23,8+x); cout<<af.nombres;
	gotoxy(35,8+x); cout<<af.apellidos;
	gotoxy(45,8+x); cout<<af.dni;
}
void mostrarListaAfiliado(colaPP &cPP){
	nodoA *aux;
	int x = 0;
	system("cls");
	encabezadoAf();
	
	while(aux != NULL){
		mostrarAf(aux->info, x);
		aux = aux->sgte;
		x++;
		Sleep(2000);
	}
	system("pause");
}
int main(int argc, char** argv) {
	colaPP cPP;
	inicializa(cPP);
	int opc;
    do{
       opc = menu();
       switch(opc){
        case 1: registrarPartido(cPP); break;
        case 2: registrarAfiliado(cPP); break;
        case 3: buscarAfiliado(cPP); break;
        case 4: eliminarAfiliado(cPP); break;
        case 5: eliminarPartido(cPP); break;
        case 6: mostrarListaPartido(cPP); break;
        case 7: mostrarListaAfiliado(cPP); break;
       }
    }while(!(opc == 8));
	return 0;
}
