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

string convertirAString(int number) { return to_string(number); }
string convertirAString(float number) { return to_string(number); }

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

float leerDinero(string mensaje, float min) {
  string requestMessage, errorMessage;

  requestMessage = mensaje + " (Mínimo S/" + convertirAString(min) + ")";
  errorMessage = "Por favor, ingrese una cantidad mínima de S/" +
                 convertirAString(min) + ".";

  return leerNumeroDecimal(requestMessage, errorMessage, min);
}

float leerDinero(string mensaje, float min, float max) {
  string requestMessage, errorMessage;

  requestMessage = mensaje + " (Mínimo S/" + convertirAString(min) +
                   " y máximo de S/" + convertirAString(max) + ")";
  errorMessage = "Por favor, ingrese una cantidad mínima de S/" +
                 convertirAString(min) + " y máxima de S/" +
                 convertirAString(max) + ".";

  return leerNumeroDecimal(requestMessage, errorMessage, min);
}

string leerFecha(string mensaje) {
  string date;

  // Year
  int year = leerNumeroEntero(
      "Año:", "Por favor ingrese un valor entre 1900 y 2050", 1900, 2050);

  // Month
  int selectedMonth;
  string months[12];
  months[0] = "Enero";
  months[1] = "Febrero";
  months[2] = "Marzo";
  months[3] = "Abril";
  months[4] = "Mayo";
  months[5] = "Junio";
  months[6] = "Julio";
  months[7] = "Agosto";
  months[8] = "Septiembre";
  months[9] = "Octubre";
  months[10] = "Noviembre";
  months[11] = "Diciembre";

  cout << endl << "Mes:" << endl << endl;

  for (int i = 0; i < 12; i++) {
    cout << "[" << (i + 1) << "] " << months[i] << endl;
  }

  cout << endl << "Introduzca la opción deseada:" << endl;
  cin >> selectedMonth;
  while (!(1 <= selectedMonth && selectedMonth <= 12)) {
    cout << "Introdujo una opción inválida, por favor seleccione una opción "
            "válida:"
         << endl;
    cin >> selectedMonth;
  }
  selectedMonth--;

  int maxDays;
  if (selectedMonth == 0 || selectedMonth == 2 || selectedMonth == 4 ||
      selectedMonth == 6 || selectedMonth == 7 || selectedMonth == 9 ||
      selectedMonth == 11) {
    maxDays = 31;
  } else if (selectedMonth == 3 || selectedMonth == 5 || selectedMonth == 8 ||
             selectedMonth == 10) {
    maxDays = 30;
  } else if (selectedMonth == 1 && year % 4 == 0) {
    maxDays = 29;
  } else {
    maxDays = 28;
  }

  // Day
  int day = leerNumeroEntero(
      "Día del mes:",
      "Por favor ingrese un valor entre 1 y " + convertirAString(maxDays), 1,
      maxDays);

  return convertirAString(year) + "/" + months[selectedMonth] + "/" +
         convertirAString(day);
}

void esperarMostrandoTexto(string mensaje, bool esperaLarga = false) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, 2);

  cout << mensaje;

  for (int i = 0; i < 6; i++) {
    if (esperaLarga)
      Sleep(450);
    else
      Sleep(150);

    cout << ".";
  }

  SetConsoleTextAttribute(hConsole, 15);
}
