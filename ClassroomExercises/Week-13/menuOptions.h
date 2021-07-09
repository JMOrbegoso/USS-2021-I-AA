#include "structFunctions.h"

void showAppTitle() {
  cout << endl;
  cout << "-----------------------------------------------------------";
  cout << endl << endl;
  cout << "\t Nombre: Problema de clase - Semana 13 ";
  cout << endl << endl;
  cout << "-----------------------------------------------------------";
  cout << endl;
}

void registerStudent(studentsList &students) {
  studentStruct newStudent;
  string dni, firstName, lastName;

  clearScreen();
  showAppTitle();

  gotoxy(20, 8);
  cout << "Registrar nuevo estudiante:" << endl;

  dni = requestText("Ingrese el DNI del nuevo estudiante", 8, 8);
  firstName = requestText("Ingrese el nombre del nuevo estudiante", 3);
  lastName = requestText("Ingrese el apellido del nuevo estudiante", 3);

  newStudent = buildStudent(dni, firstName, lastName);

  insert(students, newStudent);

  cout << "El estudiante fue registrado de forma exitosa.";
  cout << endl << endl;
}

void showStudents(studentsList students) {
  studentNode *studentNodePointer;

  clearScreen();
  showAppTitle();

  gotoxy(20, 10);
  cout << "Todos los estudiantes registrados" << endl;

  studentNodePointer = students.head;

  showStudentsListHeader(12);

  for (int i = 0; studentNodePointer != NULL; i++) {
    showStudent(studentNodePointer->student, i, i + 13);
    studentNodePointer = studentNodePointer->next;
  }

  cout << endl << endl;
}

void orderStudentsWithBubbleSort(studentsList &students) {
  studentNode *current;
  studentNode *next;
  studentStruct student;

  current = students.head;

  if (!(students.length > 0)) {
    cout << "No hay estudiantes registrados";
    cout << endl << endl;
    return;
  }

  while (current->next != NULL) {
    next = current->next;

    while (next != NULL) {
      if (current->student.lastName > next->student.lastName) {
        student = next->student;
        next->student = current->student;
        current->student = student;
      }
      next = next->next;
    }
    current = current->next;
    next = current->next;
  }

  cout << "Los estudiantes fueron ordenados correctamente";
  cout << endl << endl;
}