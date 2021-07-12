#include <windows.h>

#include <iostream>

#define nN 5

using namespace std;

void gotoxy(int x, int y) {
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y = y;
  SetConsoleCursorPosition(hcon, dwPos);
}

int menu() {
  int op;
  system("cls");
  gotoxy(35, 5);
  cout << "MENU DE OPCIONES" << endl;
  gotoxy(35, 6);
  cout << "================" << endl;
  gotoxy(32, 7);
  cout << "1.Registrar salas" << endl;
  gotoxy(32, 8);
  cout << "2.Registrar el registro de cada película" << endl;
  gotoxy(32, 9);
  cout << "3.Registrar atención de clientes" << endl;
  gotoxy(32, 10);
  cout << "4.Mostrar lista clientes con sus datos" << endl;
  gotoxy(32, 11);
  cout << "5.Buscar cliente" << endl;
  gotoxy(32, 12);
  cout << "6.Salir" << endl;
  do {
    gotoxy(32, 13);
    cout << "Ingrese opcion:";
    cin >> op;
  } while (!(op >= 0 && op <= 6));
  return op;
}

string leerTexto(string mensaje) {
  string valor;
  cout << mensaje;
  fflush(stdin);
  getline(cin, valor);
  return valor;
}

int leerEdad(string mensaje) {
  int x;
  do {
    cout << mensaje;
    cin >> x;
  } while (!(x >= 16 && x <= 80));
  return x;
}

int leerEntero(string mensaje) {
  int x;
  do {
    cout << mensaje;
    cin >> x;
  } while (!(x > 0));
  return x;
}

float leerReal(string mensaje) {
  float x;
  do {
    cout << mensaje;
    cin >> x;
  } while (!(x >= 0));
  return x;
}
