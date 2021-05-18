#include <iostream>
#include <windows.h>


#define nJug 10


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
    int opc;
    system("cls");
    gotoxy(45,4); cout << "Menu";
    gotoxy(45,5); cout << "====";
    gotoxy(35,6); cout << "1.Registrar equipo";
    gotoxy(35,7); cout << "2.Registrar jugador ";
    gotoxy(35,8); cout << "3.Buscar equipo de futbol";
    gotoxy(35,9); cout << "4.Lista de equipos";
    gotoxy(35,10);cout << "5.Mostrar equipos con sus jugadores";
    do{
        gotoxy(35,12);cout << "Elija opcion:";
        cin >> opc;
    }while(!(opc > 0 && opc < 6));
    return opc;
}

string leerTexto(string mensaje){
    string texto;
    do{
        cout << mensaje;
        fflush(stdin);
        getline(cin, texto);
    }while(!(texto.length()>0));
    return texto;
}


float leerNota(string mensaje){
    float nota;
    do{
        cout << mensaje;
        cin >> nota;
    }while(!(nota >=0 && nota <=20));
    return nota;
}

float leerReal(string mensaje, float limiteInf, float limiteSup){
    float nota;
    do{
        cout << mensaje;
        cin >> nota;
    }while(!(nota >=limiteInf && nota <= limiteSup));
    return nota;
}

unsigned short leerEntero(string mensaje, int limiteInf, int limiteSup){
    int num;
    do{
        cout << mensaje;
        cin >> num;
    }while(!(num >=limiteInf && num <= limiteSup));
    return num;
}

void cabecera(){
    gotoxy( 3,3); cout << "CODIGO";
    gotoxy(10,3); cout << "NOMBRE";
    gotoxy(30,3); cout << "CIUDAD";
    gotoxy(50,3); cout << "ESTADIO";
    gotoxy(70,3); cout << "ENTRENADOR";
}

