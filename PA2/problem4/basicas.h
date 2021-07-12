#include <iostream>
#include "estructuras.h"
#define nN 5

using namespace std;

void gotoxy(int x,int y){
     HANDLE hcon;
     hcon = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD dwPos;
     dwPos.X = x;
     dwPos.Y= y;
     SetConsoleCursorPosition(hcon,dwPos);
}

int menu(){
    int op;
    system("cls");
    gotoxy(35,5); cout << "MENU DE OPCIONES" << endl;
    gotoxy(35,6); cout << "================" << endl;
    gotoxy(32,7); cout << "1.Registrar partido" << endl;
    gotoxy(32,8); cout << "2.Registrar afiliado en el partido" << endl;
    gotoxy(32,9); cout << "3.Buscar un afiliado " << endl;
    gotoxy(32,10); cout << "4.Eliminar un afiliado " << endl;
    gotoxy(32,11); cout << "5.Eliminar un partido " << endl;
    gotoxy(32,12); cout << "6.Mostrar lista de partidos " << endl;
    gotoxy(32,13); cout << "7.Mostrar lista de afiliado en un partido " << endl;
    gotoxy(32,14); cout << "8.Salir" << endl;
    do{
        gotoxy(32,16);
        cout << "Ingrese opcion:";
        cin >> op;
    }while(!(op >= 0 && op <= 8));
    return op;
}

int menuTienda(){
    int op;
    system("cls");
    gotoxy(35,5); cout << "MENU DE OPCIONES" << endl;
    gotoxy(35,6); cout << "================" << endl;
    gotoxy(32,7); cout << "1.Registrar ciudad" << endl;
    gotoxy(32,8); cout << "2.Listar ciudad" << endl;
    gotoxy(32,9); cout << "3.Modificar ciudad" << endl;
    gotoxy(32,10); cout << "4.Salir" << endl;
    do{
        gotoxy(32,11);
        cout << "Ingrese opcion:";
        cin >> op;
    }while(!(op >= 0 && op <= 4));
    return op;
}

string leerTexto(string mensaje){
    string valor;
    cout << mensaje;
    fflush(stdin);
    getline(cin, valor);
    return valor;
}


int leerEdad( string mensaje){
    int x;
    do{
        cout << mensaje ;
        cin >> x;
    }while(!(x >=16 && x<= 80));
    return x;
}

int leerEntero( string mensaje){
    int x;
    do{
        cout << mensaje ;
        cin >> x;
    }while(!(x > 0 ));
    return x;
}


float leerNota( string mensaje){
    float x;
    do{
        cout << mensaje ;
        cin >> x;
    }while(!(x >=0 && x<= 20));
    return x;
}

float leerReal( string mensaje){
    float x;
    do{
        cout << mensaje ;
        cin >> x;
    }while(!(x >=0 ));
    return x;
}

