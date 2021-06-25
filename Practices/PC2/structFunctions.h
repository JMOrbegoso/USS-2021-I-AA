#include "helpers.h"
#include "structs.h"

using namespace std;

void collectionsInitialization(libraryStruct &library) {
  library.rooms.head = NULL;
  library.rooms.length = 0;
}

roomStruct buildRoom(string thematic) {
  roomStruct room;

  room.thematic = thematic;
  room.students.head = NULL;
  room.students.tail = NULL;
  room.students.length = 0;

  return room;
}

studentStruct buildStudent(string code, string lastName, string firstName,
                           string email, string birthDate, string career) {
  studentStruct student;

  student.code = code;
  student.lastName = lastName;
  student.firstName = firstName;
  student.email = email;
  student.birthDate = birthDate;
  student.career = career;

  student.books.top = NULL;
  student.books.length = 0;

  return student;
}

bookStruct buildBook(string code, string title, unsigned short publicationDate,
                     string authorFirstName, string authorLastName,
                     string type) {
  bookStruct book;

  book.code = code;
  book.title = title;
  book.publicationDate = publicationDate;
  book.authorFirstName = authorFirstName;
  book.authorLastName = authorLastName;
  book.type = type;

  return book;
}

// Añadir a lista
void addToList(roomsList &rooms, roomStruct newRoom) {
  roomNode *roomNodePointer = new roomNode();

  roomNode *lastNode = rooms.head;

  roomNodePointer->room = newRoom;
  roomNodePointer->next = NULL;

  if (rooms.head == NULL) {
    rooms.head = roomNodePointer;
  } else {
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }

    lastNode->next = roomNodePointer;
  }

  rooms.length++;
}

// Encolar
void enqueue(studentsQueue &students, studentStruct newStudent) {
  studentNode *studentNodePointer = new studentNode;

  studentNodePointer->student = newStudent;
  studentNodePointer->next = NULL;

  if (students.head == NULL) {
    students.head = studentNodePointer;
  } else {
    students.tail->next = studentNodePointer;
  }

  students.tail = studentNodePointer;
  students.length++;
}

// Desencolar
studentStruct dequeue(studentsQueue &students) {
  studentNode *studentNodePointer;
  studentStruct deletedStudent;

  studentNodePointer = students.head;
  deletedStudent = studentNodePointer->student;

  students.head = students.head->next;
  students.length--;

  delete studentNodePointer;

  return deletedStudent;
}

// Apilar
void push(booksStack &books, bookStruct newBook) {
  bookNode *bookNodePointer = new bookNode();

  bookNodePointer->book = newBook;
  bookNodePointer->next = books.top;

  books.top = bookNodePointer;
  books.length++;
}

void dataInitialization(libraryStruct &library) {
  roomStruct room_1, room_2, room_3;
  studentStruct student_1, student_2, student_3, student_4, student_5,
      student_6;
  bookStruct book_01, book_02, book_03, book_04, book_05, book_06, book_07,
      book_08, book_09, book_10, book_11, book_12;

  library.universityName = "Universidad Señor de Sipán";

  room_1 = buildRoom("Programacion");
  room_2 = buildRoom("Ing. Civil");
  room_3 = buildRoom("Medicina");

  student_1 =
      buildStudent("2020A-55", "Flores", "Ricardo", "ricardoflores@gmail.com",
                   "2000-11-10", "Ing. Sistemas");
  student_2 = buildStudent("2019A-34", "Diaz", "Susana", "susanadiaz@gmail.com",
                           "2005-10-09", "Ing. Sistemas");

  student_3 =
      buildStudent("2021A-11", "Rioja", "Roberto", "robertorioja@gmail.com",
                   "1999-08-07", "Ing. Civil");
  student_4 =
      buildStudent("2020A-98", "Garcia", "Marcos", "marcosgarcia@gmail.com",
                   "2001-01-09", "Ing. Civil");

  student_5 =
      buildStudent("2010A-24", "Gonzales", "Maria", "mariagonzales@gmail.com",
                   "2000-03-01", "Medicina Humana");
  student_6 =
      buildStudent("2017A-30", "Lopez", "Guillermo", "guillermolopez@gmail.com",
                   "2000-11-10", "Medicina Humana");

  book_01 =
      buildBook("aa-11", "Algoritmos", 1988, "Jim", "Shawn", "Instructivo");
  book_02 =
      buildBook("aa-12", "Backend en Go", 2020, "Joe", "Roland", "Informativo");
  book_03 = buildBook("aa-13", "Bases de datos", 1980, "Elena", "Hadwin",
                      "Instructivo");
  book_04 =
      buildBook("aa-14", "Xamarin", 2010, "Gustavo", "Goodwin", "Informativo");
  book_05 =
      buildBook("bb-11", "Zapatas", 1960, "Mark", "Pierce", "Instructivo");
  book_06 =
      buildBook("bb-12", "Puentes", 1955, "Robert", "Erickson", "Informativo");
  book_07 =
      buildBook("bb-13", "Vigas", 1978, "Fernanda", "Fabijan", "Instructivo");
  book_08 = buildBook("bb-14", "Naves industriales", 1954, "Christobal",
                      "Martin", "Informativo");
  book_09 =
      buildBook("cc-11", "Pulmones", 1998, "Joe", "Roland", "Instructivo");
  book_10 =
      buildBook("cc-12", "Corazon", 1981, "Yoshi", "Matsumoto", "Informativo");
  book_11 =
      buildBook("cc-13", "Estomago", 1984, "Terence", "Hollie", "Instructivo");
  book_12 =
      buildBook("cc-14", "Cerebro", 1986, "Mirta", "Charles", "Informativo");

  push(student_1.books, book_01);
  push(student_1.books, book_02);
  push(student_2.books, book_03);
  push(student_2.books, book_04);
  push(student_3.books, book_05);
  push(student_3.books, book_06);
  push(student_4.books, book_07);
  push(student_4.books, book_08);
  push(student_5.books, book_09);
  push(student_5.books, book_10);
  push(student_6.books, book_11);
  push(student_6.books, book_12);

  enqueue(room_1.students, student_1);
  enqueue(room_1.students, student_2);
  enqueue(room_2.students, student_3);
  enqueue(room_2.students, student_4);
  enqueue(room_3.students, student_5);
  enqueue(room_3.students, student_6);

  addToList(library.rooms, room_1);
  addToList(library.rooms, room_2);
  addToList(library.rooms, room_3);
}

roomNode *iterateRoomsList(roomsList rooms, int index) {
  roomNode *roomNodePointer;

  if (0 >= index) {
    return NULL;
  }

  if (index > rooms.length) {
    return NULL;
  }

  roomNodePointer = rooms.head;

  for (int i = 1; roomNodePointer != NULL; i++) {
    if (i == index) {
      return roomNodePointer;
    }
    roomNodePointer = roomNodePointer->next;
  }

  return NULL;
}

studentNode *iterateStudentsQueue(studentsQueue students, int index) {
  studentNode *studentNodePointer;

  if (0 >= index) {
    return NULL;
  }

  if (index > students.length) {
    return NULL;
  }

  studentNodePointer = students.head;

  for (int i = 1; studentNodePointer != NULL; i++) {
    if (i == index) {
      return studentNodePointer;
    }
    studentNodePointer = studentNodePointer->next;
  }

  return NULL;
}

roomNode *requestRoomWithSelector(roomsList &rooms, string message) {
  int selectedOption;
  roomNode *roomNodePointer;

  cout << endl
       << message << "." << endl
       << "Escoja entre las " << rooms.length << " salas siguientes:" << endl
       << endl;

  roomNodePointer = rooms.head;

  for (int i = 1; roomNodePointer != NULL; i++) {
    cout << "[" << i << "] - " << roomNodePointer->room.thematic << " - "
         << roomNodePointer->room.students.length
         << " estudiantes en cola para esta sala" << endl;
    roomNodePointer = roomNodePointer->next;
  }

  cout << endl << "Introduzca la opción deseada:" << endl;
  cin >> selectedOption;

  while (!(1 <= selectedOption && selectedOption <= rooms.length)) {
    cout << "Por favor, introduzca un valor entre 1 y " << rooms.length << "."
         << endl;
    fflush(stdin);
    cin >> selectedOption;
  }

  return iterateRoomsList(rooms, selectedOption);
}

studentNode *requestStudentWithSelector(studentsQueue &students,
                                        string message) {
  int selectedOption;
  studentNode *studentNodePointer;

  studentNodePointer = students.head;

  cout << endl
       << message << "." << endl
       << "Escoja entre los " << students.length
       << " estudiantes siguientes:" << endl
       << endl;

  for (int i = 1; studentNodePointer != NULL; i++) {
    cout << "[" << i << "] - " << studentNodePointer->student.firstName << " "
         << studentNodePointer->student.lastName << " - Con "
         << studentNodePointer->student.books.length << " libros." << endl;
    studentNodePointer = studentNodePointer->next;
  }

  cout << endl << "Introduzca la opción deseada:" << endl;
  cin >> selectedOption;

  while (!(1 <= selectedOption && selectedOption <= students.length)) {
    cout << "Por favor, introduzca un valor entre 1 y " << students.length
         << "." << endl;
    fflush(stdin);
    cin >> selectedOption;
  }

  return iterateStudentsQueue(students, selectedOption);
}

void showRoomsListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Tematica";
  gotoxy(25, y);
  cout << "# de estudiantes en cola";
}

void showRoom(roomStruct room, int i, int y) {
  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << room.thematic;
  gotoxy(25, y);
  cout << room.students.length;
}

void showStudentsListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Apellidos";
  gotoxy(20, y);
  cout << "Nombres";
  gotoxy(30, y);
  cout << "Email";
  gotoxy(60, y);
  cout << "Fecha Nacimiento";
  gotoxy(75, y);
  cout << "Carrera";
  gotoxy(95, y);
  cout << "# Libros";
}

void showStudent(studentStruct student, int i, int y) {
  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << student.lastName;
  gotoxy(20, y);
  cout << student.firstName;
  gotoxy(30, y);
  cout << student.email;
  gotoxy(60, y);
  cout << student.birthDate;
  gotoxy(75, y);
  cout << student.career;
  gotoxy(95, y);
  cout << student.books.length;
}

void showBooksListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Codigo";
  gotoxy(15, y);
  cout << "Title";
  gotoxy(40, y);
  cout << "Publication";
  gotoxy(65, y);
  cout << "Autor";
}

void showBook(bookStruct book, int i, int y) {
  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << book.code;
  gotoxy(15, y);
  cout << book.title;
  gotoxy(40, y);
  cout << book.publicationDate;
  gotoxy(65, y);
  cout << book.authorLastName + " " + book.authorFirstName;
}
