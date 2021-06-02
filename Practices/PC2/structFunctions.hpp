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
