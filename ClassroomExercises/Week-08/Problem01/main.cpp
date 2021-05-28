#include <math.h>

#include <iostream>
#include <string>
#if defined(WIN32) || defined(_WIN32) || \
    defined(__WIN32) && !defined(__CYGWIN__)

#include <windows.h>

#else

#endif

using namespace std;

#define max 8

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

void init(int board[max]) {
  for (int x = 0; x < max; x++) {
    board[x] = -1;
  }
}

bool check(int row, int board[max]) {
  for (int x = 0; x < row; x++) {
    if ((board[x] == board[row]) ||
        (abs(row - x) == abs(board[row] - board[x])))
      return false;
  }
  return true;
}

void showBoard(int board[max]) {
  for (int x = 0; x < max; x++) {
    for (int y = 0; y < max; y++) {
      if (board[x] == y)
        cout << "R";
      else
        cout << "0";
    }
    cout << endl << endl;
  }
}

int ubicateQueen(int row, int board[max], int &solutionNumber) {
  if (row < max) {
    for (board[row] = 0; board[row] < max; board[row]++) {
      if (check(row, board)) {
        ubicateQueen(row + 1, board, solutionNumber);
      }
    }
  } else {
    solutionNumber++;
    cout << "Solución # " << solutionNumber << endl;
    cout << "------------------------------" << endl;
    showBoard(board);
  }

  return 0;
}

int main() {
  int board[max];
  int row = 0;
  int solutionNumber = 0;

  init(board);

  ubicateQueen(row, board, solutionNumber);

  return 0;
}