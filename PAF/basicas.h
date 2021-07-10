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

string leerTexto(string mensaje, long unsigned int minLength) {
  string text;

  cout << mensaje << " (Mínimo " << minLength << " caracteres)" << endl;

  do {
    fflush(stdin);
    getline(cin, text);
  } while (!(minLength <= text.length()));

  return text;
}

string leerTexto(string mensaje, long unsigned int minLength,
                 long unsigned int maxLength) {
  string text;

  cout << mensaje << " (Mínimo " << minLength << " y máximo " << maxLength
       << " caracteres)" << endl;

  do {
    fflush(stdin);
    getline(cin, text);
  } while (!(minLength <= text.length() && text.length() <= maxLength));

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

int leerNumeroEntero(string requestMessage, string errorMessage, int min) {
  int integer;

  cout << requestMessage << endl;
  cin >> integer;

  while (!(min <= integer)) {
    cout << errorMessage << endl;
    fflush(stdin);
    cin >> integer;
  }

  return integer;
}

int leerNumeroEntero(string requestMessage, string errorMessage, int min,
                     int max) {
  int integer;

  cout << requestMessage << endl;
  cin >> integer;

  while (!(min <= integer && integer <= max)) {
    cout << errorMessage << endl;
    fflush(stdin);
    cin >> integer;
  }

  return integer;
}

float leerNumeroDecimal(string requestMessage, string errorMessage, float min) {
  float amount;

  cout << requestMessage << endl;
  cin >> amount;

  while (!(min <= amount)) {
    cout << errorMessage << endl;
    fflush(stdin);
    cin >> amount;
  }

  return amount;
}

float leerNumeroDecimal(string requestMessage, string errorMessage, float min,
                        float max) {
  float amount;

  cout << requestMessage << endl;
  cin >> amount;

  while (!(min <= amount && amount <= max)) {
    cout << errorMessage << endl;
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
