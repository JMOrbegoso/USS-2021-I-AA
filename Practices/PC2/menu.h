#include "structFunctions.h"

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

void registerNewStudent(libraryStruct &library) {
  string firstName, lastName, code, birthDate, email, career;

  roomNode *roomNodePointer;
  studentStruct newStudent;

  clearScreen();
  showAppTitle(library);

  gotoxy(20, 10);
  cout << "Registrar nuevo estudiante:" << endl;

  code = requestText("Ingrese el codigo del nuevo estudiante", 2);
  firstName = requestText("Ingrese los nombres del nuevo estudiante", 2);
  lastName = requestText("Ingrese los apellidos del nuevo estudiante", 2);
  email = requestText("Ingrese el email del nuevo estudiante", 2);
  birthDate =
      requestText("Ingrese la fecha de nacimiento del nuevo estudiante", 2);
  career = requestText(
      "Ingrese la carrera profesional de nacimiento del nuevo estudiante", 2);

  newStudent =
      buildStudent(code, lastName, firstName, email, birthDate, career);

  roomNodePointer = requestRoomWithSelector(
      library.rooms, "Ingrese la sala en la que se encuentra el estudiante");

  enqueue(roomNodePointer->room.students, newStudent);

  cout << "El estudiante fue añadido de forma exitosa" << endl;
}

void AddBookToStudentBookStack(libraryStruct &library) {
  roomNode *roomNodePointer;
  studentNode *studentNodePointer;
  bookStruct newBook;
  string code, title, authorLastName, authorFirstName, type;
  unsigned short publicationDate;

  cout << "Va a añadir un libro a la pila de libros de un estudiante" << endl
       << endl;

  code = requestText("Ingrese el código del libro a añadir", 1);
  title = requestText("Ingrese el titulo del libro a añadir", 2);
  authorFirstName =
      requestText("Ingrese el nombre del autor del libro a añadir", 2);
  authorLastName =
      requestText("Ingrese el apellido del autor del libro a añadir", 2);
  type = requestText("Ingrese el tipo del libro a añadir", 2);
  publicationDate =
      requestIntegerNumber("Ingrese el año de publicación del libro",
                           "Por favor ingrese un año valido", 1000, 2021);

  roomNodePointer = requestRoomWithSelector(
      library.rooms,
      "Ingrese la sala donde se encuentra el estudiante que prestará el libro");

  while (!(roomNodePointer->room.students.head != NULL)) {
    cout << endl
         << "La sala elegida no tiene estudiantes, por favor elija una "
            "sala con estudiantes."
         << endl;

    addDelay(1);

    roomNodePointer =
        requestRoomWithSelector(library.rooms,
                                "Ingrese la sala donde se encuentra el "
                                "estudiante que prestará el libro");
  }

  studentNodePointer =
      requestStudentWithSelector(roomNodePointer->room.students,
                                 "Ingrese el estudiante que prestará el libro");

  newBook = buildBook(code, title, publicationDate, authorFirstName,
                      authorLastName, type);
  push(studentNodePointer->student.books, newBook);

  cout << "El libro ha sido registrado correctamente en la pila de libros del "
          "estudiante.";
}

void BorrowBooksToStudent(libraryStruct &library) {
  roomNode *roomNodePointer;
  studentStruct studentToBorrow;

  cout << "Va a prestar los libros a un estudiante" << endl << endl;

  roomNodePointer =
      requestRoomWithSelector(library.rooms,
                              "Ingrese la sala donde se encuentra el "
                              "estudiante al que se le prestarán los libro");

  while (!(roomNodePointer->room.students.head != NULL)) {
    cout << endl
         << "La sala elegida no tiene estudiantes, por favor elija una "
            "sala con estudiantes."
         << endl;

    addDelay(1);

    roomNodePointer =
        requestRoomWithSelector(library.rooms,
                                "Ingrese la sala donde se encuentra el "
                                "estudiante al que se le prestarán los libro");
  }

  studentToBorrow = dequeue(roomNodePointer->room.students);

  cout << "Se le prestaron correctamente los libros al estudiante "
       << studentToBorrow.firstName << " " << studentToBorrow.lastName << "."
       << endl
       << endl;
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
        case 6:
          registerNewStudent(library);
          addDelay(2);
          break;
        case 7:
          AddBookToStudentBookStack(library);
          addDelay(2);
          break;
        case 8:
          BorrowBooksToStudent(library);
          addDelay(3);
          break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}
