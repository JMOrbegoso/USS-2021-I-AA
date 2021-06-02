#include <iostream>

using namespace std;

// Book
struct bookStruct {
  string code;
  string title;
  unsigned short publicationDate;
  string authorFullName;
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
  unsigned short birthDate;
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
  roomNode *top;
  int length;
};

// Library
struct libraryStruct {
  string universityName;
  roomsList rooms;
};
