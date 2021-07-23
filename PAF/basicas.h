#include <windows.h>

#include <iostream>
#include <string>

using namespace std;

string aMinuscula(string text) {
  /*for_each(text.begin(), text.end(), [](char& c) {
      c = ::tolower(c);
  });*/
  return text;
}

char *toCharArray(string text) {
  char *charArray;
  string str_obj(text);
  charArray = &str_obj[0];
  return charArray;
}

void gotoxy(int x, int y) {
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y = y;
  SetConsoleCursorPosition(hcon, dwPos);
}

string concatenarStrings(string acumulator, string toAdd, string separator) {
  if (acumulator.length() > 0)
    return acumulator + separator + toAdd;
  else
    return toAdd;
}

bool contieneTexto(string textBase, string textToFind) {
  if (aMinuscula(textBase).find(aMinuscula(textToFind), 0) != string::npos) {
    return true;
  }
  return false;
}

string conseguirGenero(bool genre) { return genre ? "Masculino" : "Femenino"; }

string leerTexto(string mensaje, long unsigned int minCaracteres) {
  string text;

  cout << mensaje << " (Mínimo " << minCaracteres << " caracteres)" << endl;

  do {
    fflush(stdin);
    getline(cin, text);
  } while (!(minCaracteres <= text.length()));

  return text;
}

string leerTexto(string mensaje, long unsigned int minCaracteres,
                 long unsigned int maxCaracteres) {
  string text;

  cout << mensaje << " (Mínimo " << minCaracteres << " y máximo "
       << maxCaracteres << " caracteres)" << endl;

  do {
    fflush(stdin);
    getline(cin, text);
  } while (!(minCaracteres <= text.length() && text.length() <= maxCaracteres));

  return text;
}

bool leerGenero(string mensaje) {
  char genre;

  cout << mensaje
       << ". Ingrese 'm' para genero masculino o 'f' para genero femenino."
       << endl;
  cin >> genre;

  while (!(genre == 'm' || genre == 'f')) {
    cout << "Por favor, ingrese solo 'm' o 'f':" << endl;
    fflush(stdin);
    cin >> genre;
  }

  return genre == 'm';
}

int leerNumeroEntero(string mensajeDePeticion, string mensajeDeValidacion,
                     int min) {
  int integer;

  cout << mensajeDePeticion << endl;
  cin >> integer;

  while (!(min <= integer)) {
    cout << mensajeDeValidacion << endl;
    fflush(stdin);
    cin >> integer;
  }

  return integer;
}

int leerNumeroEntero(string mensajeDePeticion, string mensajeDeValidacion,
                     int min, int max) {
  int integer;

  cout << mensajeDePeticion << endl;
  cin >> integer;

  while (!(min <= integer && integer <= max)) {
    cout << mensajeDeValidacion << endl;
    fflush(stdin);
    cin >> integer;
  }

  return integer;
}

float leerNumeroDecimal(string mensajeDePeticion, string mensajeDeValidacion,
                        float min) {
  float amount;

  cout << mensajeDePeticion << endl;
  cin >> amount;

  while (!(min <= amount)) {
    cout << mensajeDeValidacion << endl;
    fflush(stdin);
    cin >> amount;
  }

  return amount;
}

float leerNumeroDecimal(string mensajeDePeticion, string mensajeDeValidacion,
                        float min, float max) {
  float amount;

  cout << mensajeDePeticion << endl;
  cin >> amount;

  while (!(min <= amount && amount <= max)) {
    cout << mensajeDeValidacion << endl;
    fflush(stdin);
    cin >> amount;
  }

  return amount;
}

void esperarMostrandoTexto(string mensaje) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, 2);

  cout << mensaje;

  for (int i = 0; i < 10; i++) {
    cout << ".";
    Sleep(180);
  }

  SetConsoleTextAttribute(hConsole, 15);
}
