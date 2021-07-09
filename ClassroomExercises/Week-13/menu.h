#include "menuOptions.h"

using namespace std;

int requestMenuOption() {
  int selectedOption;

  clearScreen();
  showAppTitle();

  cout << endl
       << "Esta aplicación tiene las siguientes opciones:" << endl
       << endl;

  cout << "[1] Registrar estudiante" << endl;
  cout << "[2] Mostrar estudiantes" << endl;
  cout << "[3] Ordenar estudiantes" << endl;
  cout << endl;
  cout << "[0] Cerrar" << endl;

  cout << endl << "Por favor ingrese una de las opciones:" << endl;
  cin >> selectedOption;
  while (!(0 <= selectedOption && selectedOption <= 11)) {
    cout << "La opcion seleccionada fue inválida, por favor seleccione una "
            "opcion válida:"
         << endl;
    cin >> selectedOption;
  }
  return selectedOption;
}

void mainMenu(studentsList &students) {
  int selectedOption;

  do {
    selectedOption = requestMenuOption();

    if (selectedOption != 0) {
      switch (selectedOption) {
        case 1:
          registerStudent(students);
          addDelay(1.5);
          break;

        case 2:
          showStudents(students);
          pauseProcess();
          break;

        case 3:
          orderStudentsWithBubbleSort(students);
          addDelay(1.5);
          break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}
