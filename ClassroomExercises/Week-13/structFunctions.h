#include "helpers.h"
#include "structs.h"

using namespace std;

// Factories

studentStruct buildStudent(string dni, string firstName, string lastName) {
  studentStruct student;

  student.dni = dni;
  student.firstName = firstName;
  student.lastName = lastName;

  return student;
}

// Insert to collection

void insert(studentsList &students, studentStruct newStudent) {
  studentNode *studentNodePointer = new studentNode();

  studentNode *lastNode = students.head;

  studentNodePointer->student = newStudent;
  studentNodePointer->next = NULL;

  if (students.head == NULL) {
    students.head = studentNodePointer;
  } else {
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }

    lastNode->next = studentNodePointer;
  }

  students.length++;
}

// Init

void collectionsInitialization(studentsList &students) {
  students.head = NULL;
  students.length = 0;
}

void dataInitialization(studentsList &students) {
  studentStruct student1, student2;

  student1 = buildStudent("10101010", "Julio", "Gonzales");
  student2 = buildStudent("10101010", "Marcos", "Rojas");

  insert(students, student1);
  insert(students, student2);
}

// Printers

void showStudentsListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Nombres";
  gotoxy(25, y);
  cout << "Apellidos";
  gotoxy(50, y);
  cout << "DNI";
}

void showStudent(studentStruct student, int i, int y) {
  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << student.firstName;
  gotoxy(25, y);
  cout << student.lastName;
  gotoxy(50, y);
  cout << student.dni;
}
