#include <iostream>
#include "basicas.h"
#include "estructuras.h"

using namespace std;

void inicializa(listaEquipos &lE){
	lE.cab=NULL;
	lE.nEquipos=0;
}
void inicializaJug(jugador &jug){
	jug.edad=0;
}
void inicializaEquipo(equipo &eq){
	eq.cantidad=0;
}
void leerEquipo(equipo &eq){
	system("cls");
    gotoxy(35,5 ); eq.codigo = leerTexto("Ingrese codigo: ");
    gotoxy(35,6 ); eq.nombre = leerTexto("Ingrese nombre: ");
    gotoxy(35,7 ); eq.ciudad = leerTexto("Ingrese ciudad: ");
    gotoxy(35,8 ); eq.estadio = leerTexto("Ingrese estadio: ");
    gotoxy(35,9 ); eq.entrenador= leerTexto("Ingrese entrenador: ");
}
void insertarEquipo(listaEquipos &lE, equipo eq){
	nodoEquipo *aux = new (struct nodoEquipo);
    nodoEquipo *temp = new (struct nodoEquipo);
    temp->info = eq;
    temp->sgte = NULL;
    if ( lE.cab == NULL ){
        lE.cab = temp;
    }
    else{
        aux = lE.cab;
        while( aux->sgte != NULL) {
            aux = aux->sgte;
        }
        aux->sgte = temp;
    }
    lE.nEquipos++;
}
void registrarEquipo(listaEquipos &lE){
	equipo eq;
    inicializaEquipo(eq);
    leerEquipo(eq);
    insertarEquipo(lE,eq);
}
void leerDatosJugador( equipo &eq){
    system("cls");
    if (eq.cantidad < nJug){
        gotoxy(30,5);eq.listaJugadores[eq.cantidad].apellidos = leerTexto("Ingrese apellidos: ");
        gotoxy(30,6);eq.listaJugadores[eq.cantidad].nombres= leerTexto("Ingrese nombres: ");
        gotoxy(30,7);eq.listaJugadores[eq.cantidad].edad= leerEntero("Ingrese edad: ", 15, 100);
        gotoxy(30,8);eq.listaJugadores[eq.cantidad].peso= leerReal ("Ingrese peso: ", 30, 90);
        gotoxy(30,9);eq.listaJugadores[eq.cantidad].posicion= leerTexto("Ingrese posicion: ");
        gotoxy(30,10);eq.listaJugadores[eq.cantidad].talla= leerReal ("Ingrese talla:", 1.5, 2.5);
        eq.cantidad++;
    }
    else{
        cout << "Equipo completo " << endl;
        Sleep(2000);
    }
}
void mostrarLista(listaEquipos lE){
    nodoEquipo *aux = lE.cab;
    int x =0;
    system("cls");
    cabecera();
    while (aux != NULL){
        gotoxy(1, 4+x); cout << x+1 << ". " <<  aux->info.codigo;
        gotoxy(10, 4+x); cout << aux->info.nombre;
        gotoxy(30, 4+x); cout << aux->info.ciudad;
        gotoxy(50, 4+x); cout << aux->info.estadio;
        gotoxy(70, 4+x); cout << aux->info.entrenador;
        aux = aux->sgte;
        x++;
    }
    cout << endl << endl;
    system("pause");
}
void registrarJug(listaEquipos &lE){
	 if (lE.nEquipos > 0 ){
        int num;
        nodoEquipo *newNodo = new (struct nodoEquipo);
        mostrarLista(lE);
        newNodo = lE.cab;
        num = leerEntero("Ingrese Numero de Equipo: ", 1, lE.nEquipos );
        for ( int x = 0 ; x < num-1; x++ ){
            newNodo = newNodo->sgte;
        }
        leerDatosJugador ( newNodo->info );
    }
}
void mostrarEquipo(nodoEquipo *aux){
    system("cls");
    gotoxy(5, 4); cout << "Codigo: " << aux->info.codigo;
    gotoxy(5, 5); cout << "Nombre: " << aux->info.nombre;
    gotoxy(5, 6); cout << "Ciudad: " << aux->info.ciudad;
    gotoxy(5, 7); cout << "Estadio: " << aux->info.estadio;
    gotoxy(5, 8); cout << "Entrenador: " << aux->info.entrenador << endl;
    gotoxy(50, 4); cout << "LISTA DE JUGADORES";
    if (aux->info.cantidad > 0){
        for (int x=0; x < aux->info.cantidad; x++ ){
			gotoxy(50, 5+x ); cout << x+1 << " - " << aux->info.listaJugadores[x].apellidos << ", " << aux->info.listaJugadores[x].nombres;
        }
    }
    system("pause");
}
void buscarEq(listaEquipos lE){
    if (lE.nEquipos > 0){
        system("cls");
        gotoxy(30,5);string nombreBuscar = leerTexto("Ingrese equipo a buscar: ");
        nodoEquipo *aux = lE.cab;
        while(aux != NULL){
            if (nombreBuscar == aux->info.nombre ){
                mostrarEquipo(aux);
                break;
            }
            aux = aux->sgte;
        }        
    }
}
void mostrarTodo(listaEquipos lE){
	mostrarLista(lE);
	nodoEquipo *aux = lE.cab;
	mostrarEquipo(aux);
}
int main(int argc, char** argv) {
	listaEquipos lE;
	inicializa(lE);
	int opc;
    do{
       opc = menu();
       switch(opc){
        case 1: registrarEquipo(lE); break;
        case 2: registrarJug(lE); break;
        case 3: buscarEq(lE); break;
        case 4: mostrarLista(lE); break;
        case 5: mostrarTodo(lE); break;

       }
    }while(!(opc == 8));
	return 0;
}

