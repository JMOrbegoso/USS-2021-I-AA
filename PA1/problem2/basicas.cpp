#include <iostream>
#include <windows.h>

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
    gotoxy(32,7); cout << "1.Registrar cursos" << endl;
    gotoxy(32,8); cout << "2.Registrar estudiantes" << endl;
    gotoxy(32,9); cout << "3.Mostrar curso" << endl;
    gotoxy(32,10); cout << "4.Mostrar estudiante" << endl;
    gotoxy(32,11); cout << "5.Buscar estudiante" << endl;
    gotoxy(32,12); cout << "6.Lista aprobados" << endl;
    gotoxy(32,13); cout << "7.Lista desaprobados" << endl;
    gotoxy(32,14); cout << "8.Lista inhabilitados" << endl;
    gotoxy(32,15); cout << "9.Salir" << endl;
    do{
        gotoxy(32,16);
        cout << "Ingrese opcion:";
        cin >> op;
    }while(!(op >= 0 && op <= 10));
    return op;
}

string leerTexto(string mensaje){
    string valor;
    cout << mensaje;
    fflush(stdin);
    getline(cin, valor);
    return valor;
}

int leerEntero( string mensaje){
    int x;
    do{
        cout << mensaje ;
        cin >> x;
    }while(!(x > 0 ));
    return x;
}

int leerEdad( string mensaje){
    int x;
    do{
        cout << mensaje ;
        cin >> x;
    }while(!(x >=16 && x<= 30));
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


