#include "helpers.h"
#include "structs.h"
#include <iostream>

using namespace std;

writerStruct buildWriter(string firstName, string lastName, unsigned short age,
                         char genre) {
  writerStruct writer;
  writer.firstName = firstName;
  writer.lastName = lastName;
  writer.age = age;
  writer.genre = genre;

  return writer;
}

void push(writersPile &writers, writerStruct newWriter) {
  writerNode *newWriterNode = new writerNode();

  newWriterNode->writer = newWriter;
  newWriterNode->next = writers.top;

  writers.top = newWriterNode;
  writers.length++;
}

void collectionsInitialization(libraryStruct &library) {
  library.name = "Las Condes";
  library.address = "Las Condes #444";

  library.writers.top = NULL;
  library.writers.length = 0;
}

void dataInitialization(libraryStruct &library) {
  writerStruct jimenez, lovecraft, lobsang, cervantes, orwell, dante, virgilio;

  jimenez = buildWriter("Julio Ramon", "Jimenez", 70, 'm');
  lovecraft = buildWriter("H.P.", "Lovecraft", 70, 'm');
  lobsang = buildWriter("Lobsang", "Rampa", 70, 'm');
  cervantes = buildWriter("Miguel", "De Cervantes", 70, 'm');
  orwell = buildWriter("George", "Orwell", 70, 'm');
  dante = buildWriter("Dante", "Alighieri", 70, 'm');
  virgilio = buildWriter("-", "Virgilio", 70, 'm');

  push(library.writers, jimenez);
  push(library.writers, lovecraft);
  push(library.writers, lobsang);
  push(library.writers, cervantes);
  push(library.writers, orwell);
  push(library.writers, dante);
  push(library.writers, virgilio);
}

void showWritersListHeader(int y) {
  gotoxy(0, y);
  cout << "#";
  gotoxy(5, y);
  cout << "Nombres";
  gotoxy(20, y);
  cout << "Apellidos";
  gotoxy(40, y);
  cout << "Edad";
  gotoxy(45, y);
  cout << "Genero";
}

void showWriter(writerStruct writer, int i, int y) {
  gotoxy(0, y);
  cout << i;
  gotoxy(5, y);
  cout << writer.firstName;
  gotoxy(20, y);
  cout << writer.lastName;
  gotoxy(40, y);
  cout << writer.age;
  gotoxy(45, y);
  cout << getGenre(writer.genre);
}
