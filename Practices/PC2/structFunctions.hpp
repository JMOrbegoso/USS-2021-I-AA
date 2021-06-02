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
                           string email, unsigned short birthDate,
                           string career) {
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
