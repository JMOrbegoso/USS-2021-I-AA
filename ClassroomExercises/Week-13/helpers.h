#include <iostream>
#include <string>
#if defined(WIN32) || defined(_WIN32) || \
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

char *toCharArray(string text) {
  char *charArray;
  string str_obj(text);
  charArray = &str_obj[0];
  return charArray;
}

void clearScreen() {
#if defined(WIN32) || defined(_WIN32) || \
    defined(__WIN32) && !defined(__CYGWIN__)
  system("cls");
#else
  system("clear");
#endif
}

void pauseProcess() {
#if defined(WIN32) || defined(_WIN32) || \
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
#if defined(WIN32) || defined(_WIN32) || \
    defined(__WIN32) && !defined(__CYGWIN__)
  Sleep(sec * 1000);
#else
  system(toCharArray("sleep " + toString(sec)));
#endif
}

void gotoxy(int x, int y) {
#if defined(WIN32) || defined(_WIN32) || \
    defined(__WIN32) && !defined(__CYGWIN__)
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y = y;
  SetConsoleCursorPosition(hcon, dwPos);
#else
  printf("%c[%d;%df", 0x1B, y, x);
#endif
}

string concatenateStrings(string acumulator, string toAdd, string separator) {
  if (acumulator.length() > 0)
    return acumulator + separator + toAdd;
  else
    return toAdd;
}

bool containsText(string textBase, string textToFind) {
  if (toLowerCase(textBase).find(toLowerCase(textToFind), 0) != string::npos) {
    return true;
  }
  return false;
}

string getGenre(char genre) {
  if (genre == 'm')
    return "Masculino";
  else if (genre == 'f')
    return "Femenino";
  else
    return "Genero no valido";
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

char requestGenre(string message) {
  char genre;

  cout << message
       << ". Ingrese 'm' para genero masculino o 'f' para genero femenino."
       << endl;
  cin >> genre;

  while (!(genre == 'm' || genre == 'f')) {
    cout << "Por favor, ingrese solo 'm' o 'f':" << endl;
    fflush(stdin);
    cin >> genre;
  }

  return genre;
}

int requestIntegerNumber(string requestMessage, string errorMessage, int min) {
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

int requestIntegerNumber(string requestMessage, string errorMessage, int min,
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

float requestFloatNumber(string requestMessage, string errorMessage,
                         float min) {
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

float requestFloatNumber(string requestMessage, string errorMessage, float min,
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
