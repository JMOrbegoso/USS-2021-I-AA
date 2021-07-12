#include <conio.h>

#include <iostream>
#define dim 15

using namespace std;

struct Datos {
  int codigo;
  char nombre[dim];
  char apellido[dim];
  int dni;
  char email[dim];
  float promedio;
}

Registro[100];  // 100 alumnos maximo
int size = 0;

int menu_principal() {
  int opcion;
  cout << "\t\t\t\tMENU PRINCIPAL" << endl;
  cout << "\t\t\t\t==============" << endl;
  cout << "\t\t[1]: Ingreso de datos" << endl;
  cout << "\t\t[2]: Buscar estudiante por DNI" << endl;
  cout << "\t\t[3]: Mostrar lista ordenada para exposicion" << endl;
  cout << "\t\t[4]: Buscar un estudiante en la lista de exposicion" << endl;
  cout << "\t\t[5]: Mostrar a los estudiantes con todas sus notas" << endl;
  cout << "\t\t[0]: Salir" << endl;
  do {
    cout << "Ingrese una opcion: [ ]"
         << "\b\b";
    cin >> opcion;
  } while (opcion < 0 || opcion > 25);
  return opcion;
}

void registro() {
  do {
    cout << "Ingrese la cantidad de alumnos: ";
    cin >> size;
  } while (size < 0);

  cout << "---INGRESO DE DATOS---" << endl;
  for (int i = 0; i < size; i++) {
    cout << "Ingrese su codigo: ";
    cin >> Registro[i].codigo;

    cout << "Ingrese su nombre (maximo 15 caracteres): ";
    fflush(stdin);
    cin.getline(Registro[i].nombre, dim, '\n');

    cout << "Ingrese su apellido (maximo 15 caracteres): ";
    fflush(stdin);
    cin.getline(Registro[i].apellido, dim, '\n');

    cout << "Ingrese su DNI: ";
    cin >> Registro[i].dni;

    cout << "Ingrese su email (maximo 15 caracteres): ";
    fflush(stdin);
    cin.getline(Registro[i].email, dim, '\n');

    do {
      cout << "Ingrese su promedio: ";
      cin >> Registro[i].promedio;
    } while (!(Registro[i].promedio >= 0 && Registro[i].promedio <= 20));

    cout << endl;
  }

  cout << "Datos guardados" << endl;
}

void buscar_dni() {
  int dni;
  bool encontrado = false;

  cout << "Ingrese el DNI a buscar:";
  cin >> dni;
  for (int i = 0; i < size; i++)
    if (Registro[i].dni == dni) {
      cout << "DNI encontrado" << endl;
      cout << "Codigo: " << Registro[i].codigo << endl;
      cout << "Nombre: " << Registro[i].nombre << endl;
      cout << "Apellido: " << Registro[i].apellido << endl;
      cout << "Email: " << Registro[i].email << endl;
      cout << "Promedio: " << Registro[i].promedio << endl;
      encontrado = true;
    }

  if (encontrado == false) cout << "No se encontro el DNI solicitado" << endl;
}

void ordenar() {
  Datos aux;
  for (int i = 0; i < size; i++)
    for (int j = i + 1; j < size; j++)
      if (Registro[i].promedio < Registro[j].promedio) {
        aux = Registro[i];
        Registro[i] = Registro[j];
        Registro[j] = aux;
      }
}

void lista() {
  ordenar();
  cout << "DATOS:" << endl;
  for (int i = 0; i < size; i++) {
    cout << "Codigo: " << Registro[i].codigo << endl;
    cout << "Nombre: " << Registro[i].nombre << endl;
    cout << "Apellido: " << Registro[i].apellido << endl;
    cout << "DNI: " << Registro[i].dni << endl;
    cout << "Email: " << Registro[i].email << endl;
    cout << "Promedio: " << Registro[i].promedio << endl;
    cout << endl;
  }
}

void buscar_lista() {
  ordenar();
  int dni;
  bool encontrado = false;

  cout << "Buscar en lista ordenada" << endl;
  cout << "Ingrese el DNI a buscar:";
  cin >> dni;
  for (int i = 0; i < size; i++)
    if (Registro[i].dni == dni) {
      cout << "DNI encontrado" << endl;
      cout << "Codigo: " << Registro[i].codigo << endl;
      cout << "Nombre: " << Registro[i].nombre << endl;
      cout << "Apellido: " << Registro[i].apellido << endl;
      cout << "Posicion: " << (i + 1) << endl;
      cout << "Email: " << Registro[i].email << endl;
      cout << "Promedio: " << Registro[i].promedio << endl;
      encontrado = true;
    }

  if (encontrado == false) cout << "No se encontro el DNI solicitado" << endl;
}

void mostrar_notas() {
  ordenar();
  cout << "NOTAS DE ESTUDIANTES:" << endl;
  for (int i = 0; i < size; i++) {
    cout << "Codigo: " << Registro[i].codigo << endl;
    cout << "Nombre: " << Registro[i].nombre << endl;
    cout << "Promedio: " << Registro[i].promedio << endl;
    cout << endl;
  }
}

int main() {
  int opcion;
  do {
    system("cls");
    opcion = menu_principal();
    switch (opcion) {
      case 1:
        system("cls");
        registro();
        getche();
        break;
      case 2:
        system("cls");
        buscar_dni();
        getche();
        break;
      case 3:
        system("cls");
        lista();
        getche();
        break;
      case 4:
        system("cls");
        buscar_lista();
        getche();
        break;
      case 5:
        system("cls");
        mostrar_notas();
        getche();
        break;
      case 0:
        system("cls");
        cout << "Saliendo" << endl;
        getche();
        break;
    }
  } while (opcion != 0);
  return 0;
}
