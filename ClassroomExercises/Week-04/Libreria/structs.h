#include <iostream>

using namespace std;

struct writerStruct {
  string firstName;
  string lastName;
  unsigned short age;
  char genre;
};

struct writerNode {
  writerStruct writer;
  writerNode *next;
  writerNode *previous;
};

struct writersList {
  writerNode *head;
  int length;
};

struct bookStruct {
  string code;
  string title;
  float price;
  unsigned short pagesQuantity;
  writersList writers;
};

struct bookNode {
  bookStruct book;
  bookNode *next;
  bookNode *previous;
};

struct booksList {
  bookNode *head;
  int length;
};

struct libraryStruct {
  string name;
  string address;
  booksList books;
};
