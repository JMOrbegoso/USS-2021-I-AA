#include <iostream>

using namespace std;

// Book
struct bookStruct {
  string code;
  string title;
  unsigned short publicationDate;
  string authorLastName;
  string authorFirstName;
  string type;
};

struct bookNode {
  bookStruct book;
  bookNode *next;
};

struct booksStack {
  bookNode *top;
  int length;
};

// Student
struct studentStruct {
  string code;
  string lastName;
  string firstName;
  string email;
  string birthDate;
  string career;
  booksStack books;
};

struct studentNode {
  studentStruct student;
  studentNode *next;
};

struct studentsQueue {
  studentNode *head;
  studentNode *tail;
  int length;
};

// Room
struct roomStruct {
  string thematic;
  studentsQueue students;
};

struct roomNode {
  roomStruct room;
  roomNode *next;
};

struct roomsList {
  roomNode *head;
  int length;
};

// Library
struct libraryStruct {
  string universityName;
  roomsList rooms;
};
