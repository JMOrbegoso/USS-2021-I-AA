#include <iostream>
#include <string>
#if defined(WIN32) || defined(_WIN32) ||                                       \
    defined(__WIN32) && !defined(__CYGWIN__)

#include <windows.h>

#else

#endif

using namespace std;

string toLowerCase(string text) {
  /*for_each(text.begin(), text.end(), [](char& c) {
      c = ::tolower(c);
  });*/
  return text;
}

bool containsText(string textBase, string textToFind) {
  if (toLowerCase(textBase).find(toLowerCase(textToFind), 0) != string::npos) {
    return true;
  }
  return false;
}

string toString(int number) { return std::to_string(number); }
string toString(float number) { return std::to_string(number); }

char *toCharArray(string text) {
  char *charArray;
  string str_obj(text);
  charArray = &str_obj[0];
  return charArray;
}

void clearScreen() {
#if defined(WIN32) || defined(_WIN32) ||                                       \
    defined(__WIN32) && !defined(__CYGWIN__)
  system("cls");
#else
  system("clear");
#endif
}

void pauseProcess() {
#if defined(WIN32) || defined(_WIN32) ||                                       \
    defined(__WIN32) && !defined(__CYGWIN__)
  system("pause");
#else
  string text;

  cout << endl
       << "Ingrese cualquier valor y presione ENTER para continuar" << endl;

  do {
    fflush(stdin);
    getline(cin, text);
  } while (text.length() == 0);

#endif
}

void addDelay(int sec) {
#if defined(WIN32) || defined(_WIN32) ||                                       \
    defined(__WIN32) && !defined(__CYGWIN__)
  Sleep(sec * 1000);
#else
  system(toCharArray("sleep " + toString(sec)));
#endif
}

void gotoxy(int x, int y) {
#if defined(WIN32) || defined(_WIN32) ||                                       \
    defined(__WIN32) && !defined(__CYGWIN__)
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y = y;
  SetConsoleCursorPosition(hcon, dwPos);
#else

#endif
}

string requestText(string message, long unsigned int minLength) {
  string text;

  cout << message << " (Mínimo " << minLength << " caracteres)" << endl;

  do {
    fflush(stdin);
    getline(cin, text);
  } while (!(minLength <= text.length()));

  return text;
}

string requestText(string message, long unsigned int minLength,
                   long unsigned int maxLength) {
  string text;

  cout << message << " (Mínimo " << minLength << " y máximo " << maxLength
       << " caracteres)" << endl;

  do {
    fflush(stdin);
    getline(cin, text);
  } while (!(minLength <= text.length() && text.length() <= maxLength));

  return text;
}

char requestGenre() {
  char genre;

  cout << "¿Es de genero masculino (m) o femenino (f)?" << endl;
  cin >> genre;

  while (!(genre == 'm' || genre == 'f')) {
    cout << "Por favor, solo ingrese 'm' o 'f':" << endl;
    fflush(stdin);
    cin >> genre;
  }

  return genre;
}

int requestIntegerNumber(string message, int min) {
  int integer;

  cout << message << " (Mínimo " << min << ")" << endl;
  cin >> integer;

  while (!(min <= integer)) {
    cout << "Por favor, introduzca un valor mínimo de " << min << "." << endl;
    fflush(stdin);
    cin >> integer;
  }

  return integer;
}

int requestIntegerNumber(string message, int min, int max) {
  int integer;

  cout << message << "(Mínimo " << min << " y máximo " << max << ")" << endl;
  cin >> integer;

  while (!(min <= integer && integer <= max)) {
    cout << "Por favor, introduzca un valor mínimo de " << min
         << " o máximo de " << max << "." << endl;
    fflush(stdin);
    cin >> integer;
  }

  return integer;
}

int requestAge(int minAge) {
  return requestIntegerNumber("¿Cúal es su edad?", 18);
}

string requestDNI() {
  string dni;

  dni = requestText("¿Cúal es su DNI?", 8, 8);

  return dni;
}

string requestRUC() {
  string dni;

  dni = requestText("¿Cúal es el RUC?", 11, 11);

  return dni;
}

string requestPassword() {
  string clave;

  clave = requestText("¿Cúal es su clave?", 6);

  return clave;
}

float requestMoney(string message, int min) {
  float amount;

  cout << message << "(Mínimo S/" << min << ")" << endl;
  cin >> amount;

  while (!(min <= amount)) {
    cout << "Por favor, ingrese una cantidad mínima de S/" << min << "."
         << endl;
    fflush(stdin);
    cin >> amount;
  }

  return amount;
}

float requestMoney(string message, int min, int max) {
  float amount;

  cout << message << "(Mínimo S/" << min << " y máximo S/" << max << ")"
       << endl;
  cin >> amount;

  while (!(min <= amount && amount <= max)) {
    cout << "Por favor, ingrese una cantidad mínima de S/" << min
         << " y máxima de S/" << max << "." << endl;
    fflush(stdin);
    cin >> amount;
  }

  return amount;
}

string requestSearchTerm() {
  return requestText("Ingrese el termino de busqueda", 2);
}

string requestDate() {
  string date;

  // Year
  int year = requestIntegerNumber("¿Cúal es el año actual?", 2000, 2050);

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

  cout << endl << "¿Hoy en que mes no encontramos?" << endl << endl;

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
  int day = requestIntegerNumber("¿Hoy que día del mes es?", 1, maxDays);

  return toString(year) + "/" + months[selectedMonth] + "/" + toString(day);
}
