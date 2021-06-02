#include "helpers.hpp"
#include "structs.hpp"

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

  room_1 = buildRoom("Algoritmos");
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
                   "2001-01-02", "Ing. Civil");

  student_5 =
      buildStudent("2010A-24", "Gonzales", "Maria", "mariagonzales@gmail.com",
                   "2000", "Medicina Humana");
  student_6 =
      buildStudent("2017A-30", "Lopez", "Guillermo", "guillermolopez@gmail.com",
                   "2000-11-10", "Medicina Humana");

  book_01 =
      buildBook("aa-11", "Algoritmos", 1978, "Jim", "Shawn", "Instructivo");
  book_02 =
      buildBook("aa-12", "Backend en Go", 1978, "Joe", "Roland", "Informativo");
  book_03 = buildBook("aa-13", "Bases de datos", 1978, "Elena", "Hadwin",
                      "Instructivo");
  book_04 =
      buildBook("aa-14", "Xamarin", 1978, "Gustavo", "Goodwin", "Informativo");
  book_05 =
      buildBook("bb-11", "Zapatas", 1978, "Mark", "Pierce", "Instructivo");
  book_06 =
      buildBook("bb-12", "Puentes", 1978, "Robert", "Erickson", "Informativo");
  book_07 =
      buildBook("bb-13", "Vigas", 1978, "Fernanda", "Fabijan", "Instructivo");
  book_08 = buildBook("bb-14", "Naves industriales", 1978, "Christobal",
                      "Martin", "Informativo");
  book_09 =
      buildBook("cc-11", "Pulmones", 1978, "Joe", "Roland", "Instructivo");
  book_10 =
      buildBook("cc-12", "Corazon", 1978, "Yoshi", "Matsumoto", "Informativo");
  book_11 =
      buildBook("cc-13", "Estomago", 1978, "Terence", "Hollie", "Instructivo");
  book_12 =
      buildBook("cc-14", "Cerebro", 1978, "Mirta", "Charles", "Informativo");

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
