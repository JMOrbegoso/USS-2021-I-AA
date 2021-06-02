#include "structFunctions.hpp"

using namespace std;

void showAppTitle(libraryStruct library) {
  cout << endl
       << "-----------------------------------------------------------" << endl;
  cout << "\t Sistema de la biblioteca de la universidad "
       << library.universityName << endl
       << endl
       << endl;
  cout << "-----------------------------------------------------------" << endl;
}

int requestMenuOption(libraryStruct library) {
  int selectedOption;

  clearScreen();
  showAppTitle(library);

  cout << endl
       << "Esta aplicación tiene las siguientes opciones:" << endl
       << endl;

  cout << "[1] Listar todas las salas de la biblioteca" << endl;
  cout << "[2] Listar alumnos haciendo cola en TODAS las salas de la biblioteca"
       << endl;
  cout << "[3] Listar alumnos haciendo cola en una sala de la biblioteca"
       << endl;
  cout << "[4] Listar TODOS los libros por ser prestados a TODOS los "
          "estudiantes en las colas"
       << endl;
  cout << "[5] Listar libros por ser prestados a un estudiante" << endl;
  cout << endl;
  cout << "[6] Registrar nuevo alumno/a" << endl;
  cout << "[7] Añadir libro a pila de libros de alumno" << endl;
  cout << "[8] Prestar libros a alumno" << endl;
  cout << endl;
  cout << "[0] Cerrar" << endl;

  cout << endl << "Por favor ingrese una de las opciones:" << endl;
  cin >> selectedOption;
  while (!(0 <= selectedOption && selectedOption <= 8)) {
    cout << "La opcion seleccionada fue inválida, por favor seleccione una "
            "opcion válida:"
         << endl;
    cin >> selectedOption;
  }
  return selectedOption;
}

void showAllRooms(libraryStruct library) {
  roomNode *roomNodePointer;

  clearScreen();
  showAppTitle(library);

  gotoxy(20, 10);
  cout << "Todas las salas de la libreria de la universidad "
       << library.universityName << endl;

  roomNodePointer = library.rooms.head;

  showRoomsListHeader(12);

  for (int i = 1; roomNodePointer != NULL; i++) {
    showRoom(roomNodePointer->room, i, i + 13);
    roomNodePointer = roomNodePointer->next;
  }

  cout << endl << endl;
}

void showAllStudents(libraryStruct library) {
  roomNode *roomNodePointer;
  studentNode *studentNodePointer;

  clearScreen();
  showAppTitle(library);

  gotoxy(20, 10);
  cout << "Todos los estudiantes formando cola en las salas de la biblioteca "
          "de la universidad "
       << library.universityName << endl;

  roomNodePointer = library.rooms.head;

  showStudentsListHeader(12);

  int i = 1;
  while (roomNodePointer != NULL) {
    studentNodePointer = roomNodePointer->room.students.head;
    while (studentNodePointer != NULL) {
      showStudent(studentNodePointer->student, i, i + 13);
      studentNodePointer = studentNodePointer->next;
      i++;
    }
    roomNodePointer = roomNodePointer->next;
  }

  cout << endl << endl;
}

void showStudentsByRoom(libraryStruct library) {
  roomNode *roomNodePointer;
  studentNode *studentNodePointer;

  roomNodePointer = requestRoomWithSelector(
      library.rooms,
      "Ingrese la sala de la que desea ver los estudiantes en cola");

  clearScreen();
  showAppTitle(library);

  gotoxy(20, 10);
  cout << "Estudiantes haciendo cola en la sala de tematica "
       << roomNodePointer->room.thematic << ":" << endl;

  studentNodePointer = roomNodePointer->room.students.head;

  showStudentsListHeader(12);

  for (int i = 1; studentNodePointer != NULL; i++) {
    showStudent(studentNodePointer->student, i, i + 13);
    studentNodePointer = studentNodePointer->next;
  }

  cout << endl << endl;
}

void showAllBooksToBorrow(libraryStruct library) {
  roomNode *roomNodePointer;
  studentNode *studentNodePointer;
  bookNode *bookNodePointer;

  clearScreen();
  showAppTitle(library);

  gotoxy(20, 10);
  cout << "Todos los libros de los estudiantes haciendo cola en las salas de "
          "la universidad "
       << library.universityName << endl;

  roomNodePointer = library.rooms.head;

  showBooksListHeader(12);

  int i = 1;
  while (roomNodePointer != NULL) {
    studentNodePointer = roomNodePointer->room.students.head;
    while (studentNodePointer != NULL) {
      bookNodePointer = studentNodePointer->student.books.top;
      while (bookNodePointer != NULL) {
        showBook(bookNodePointer->book, i, i + 13);
        bookNodePointer = bookNodePointer->next;
        i++;
      }
      studentNodePointer = studentNodePointer->next;
    }
    roomNodePointer = roomNodePointer->next;
  }

  cout << endl << endl;
}

void showBooksToBorrowByStudent(libraryStruct library) {
  roomNode *roomNodePointer;
  studentNode *studentNodePointer;
  bookNode *bookNodePointer;

  roomNodePointer = requestRoomWithSelector(
      library.rooms,
      "Escoja la sala donde se encuentra el estudiante que desea revisar");
  studentNodePointer = requestStudentWithSelector(
      roomNodePointer->room.students,
      "Escoja el estudiante del que quiere revisar sus libros");

  clearScreen();
  showAppTitle(library);

  gotoxy(20, 10);
  cout << "Libros de " << studentNodePointer->student.lastName << " "
       << studentNodePointer->student.firstName << ":" << endl;

  bookNodePointer = studentNodePointer->student.books.top;

  showBooksListHeader(12);

  for (int i = 1; bookNodePointer != NULL; i++) {
    showBook(bookNodePointer->book, i, i + 13);
    bookNodePointer = bookNodePointer->next;
  }

  cout << endl << endl;
}

void mainMenu(libraryStruct &library) {
  int selectedOption;

  do {
    selectedOption = requestMenuOption(library);

    if (selectedOption != 0) {
      switch (selectedOption) {
        case 1:
          showAllRooms(library);
          pauseProcess();
          break;
        case 2:
          showAllStudents(library);
          pauseProcess();
          break;
        case 3:
          showStudentsByRoom(library);
          pauseProcess();
          break;
        case 4:
          showAllBooksToBorrow(library);
          pauseProcess();
          break;
        case 5:
          showBooksToBorrowByStudent(library);
          pauseProcess();
          break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}
