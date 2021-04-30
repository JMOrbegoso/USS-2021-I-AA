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
};

struct writersPile {
  writerNode *top;
  int length;
};

struct libraryStruct {
  string name;
  string address;
  writersPile writers;
};
