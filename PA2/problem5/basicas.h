#include <windows.h>

#include <iostream>

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
  gotoxy(32, 8);
  cout << "1.Registrar Sala " << endl;
  gotoxy(32, 9);
  cout << "2.RegistrarEstante " << endl;
  gotoxy(32, 10);
  cout << "3.Registrar Libro" << endl;
  gotoxy(32, 11);
  cout << "4.Buscar Libro" << endl;
  gotoxy(32, 12);
  cout << "5.Listar los libros de un estante" << endl;
  gotoxy(32, 13);
  cout << "6.Listar las salas" << endl;
  gotoxy(32, 14);
  cout << "7. Salir" << endl;
  do {
    gotoxy(32, 16);
    cout << "Ingrese opcion:";
    cin >> op;
  } while (!(op >= 0 && op <= 8));
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

float leerNota(string mensaje) {
  float x;
  do {
    cout << mensaje;
    cin >> x;
  } while (!(x >= 0 && x <= 20));
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
