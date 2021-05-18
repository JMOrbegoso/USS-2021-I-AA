#include <iostream>
#include <windows.h>

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
    gotoxy(35,4); cout << "REGISTRO DEPOSTULANTES A UN EXAMEN DE ADMISION";
    gotoxy(35,5); cout << "==============================================";
    gotoxy(35,6); cout << "1. Registrar las escuelas";
    gotoxy(35,7); cout << "2. Registrar postulantes ";
    gotoxy(35,8); cout << "3. Buscar un postulante ";
    gotoxy(35,9);cout << "4. Generar Reportes";
    gotoxy(35,10);cout << "5. SALIR";
    do{
        gotoxy(35,11);cout << "Elija opcion: ";
        cin >> opc;
    }while(!(opc > 0 && opc < 6));
    return opc;
}

int menu_Reportes(){
    int opc;
    system("cls");
    gotoxy(35,4); cout << " REPORTES";
    gotoxy(35,5); cout << "===========";
    gotoxy(35,6); cout << "1. Listado general de postulantes";
    gotoxy(35,7); cout << "2. Listado de postulante por escuela ";
    gotoxy(35,8); cout << "3. Ingresar puntaje para indicar quienene lo superaron ";
    gotoxy(35,9);cout << "4. SALIR";
    do{
        gotoxy(35,11);cout << "Elija opcion: ";
        cin >> opc;
    }while(!(opc > 0 && opc < 7));
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

float leerFloat(string mensaje, float limiteInf, float limiteSup){
    float num;
    do{
        cout << mensaje;
        cin >> num;
    }while(!(num >=limiteInf && num <= limiteSup));
    return num;
}

int leerEntero(string mensaje, int limiteInf, int limiteSup){
    int num;
    do{
        cout << mensaje;
        cin >> num;
    }while(!(num >=limiteInf && num <= limiteSup));
    return num;
}
string leerDNI(string msj){
    string valor;
    do{
       cout<<msj;
       fflush(stdin);
       getline(cin,valor);
}while(valor.size()!=8);
    return valor;
}

void Cabecera_Escuela(){
    gotoxy(5,2); cout << "NUMERO";
    gotoxy(23,2); cout << "ESCUELA";
    gotoxy(40,2); cout << "CICLO";
    gotoxy(50,2); cout << "CODIGO";
    gotoxy(60,2); cout << "TITULO";
}

void cabecera_Postulantes(){
     gotoxy(30,2); cout << "----------------LISTA DE POSTULANTES---------------------";
    gotoxy(1,4); cout << "NUM";
    gotoxy(9,4); cout << "APELLIDOS";
    gotoxy(25,4); cout << "NOMBRES";
    gotoxy(43,4); cout << "DNI";
    gotoxy(56,4); cout << "DIRECCION";
    gotoxy(72,4); cout << "EMAIL";
    gotoxy(92,4); cout << "ESCUELA";
    gotoxy(105,4); cout << "PUNTAJE";
}

