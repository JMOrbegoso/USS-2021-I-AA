#include "structFunctions.h"

using namespace std;

// Main menu function

void showAppTitle(libraryStruct library) {
  cout << endl
       << "--------------------------------------------------------------------"
          "------------------"
       << endl;
  cout << "\t\t\t\t Bienvenido a la biblioteca " << library.name << endl;
  cout << "\t-> Dirección: " << library.address;
  cout << endl
       << "--------------------------------------------------------------------"
          "------------------"
       << endl;
}

int requestMenuOption(libraryStruct library) {
  int selectedOption;

  clearScreen();
  showAppTitle(library);

  cout << endl << "Por favor seleccione la opción deseada:" << endl << endl;

  cout << "[1] Registrar nuevo autor" << endl;
  cout << "[2] Mostrar autor en la cima" << endl;
  cout << "[3] Listar autores" << endl;
  cout << "[4] Buscar autor por apellidos" << endl;
  cout << "[5] Borrar autor" << endl;

  cout << "[0] Cerrar" << endl;

  cout << endl << "Por favor ingrese una de las opciones:" << endl;
  cin >> selectedOption;
  while (!(0 <= selectedOption && selectedOption <= 5)) {
    cout << "La opcion seleccionada fue inválida, por favor seleccione una "
            "opcion válida:"
         << endl;
    cin >> selectedOption;
  }
  return selectedOption;
}

void registerWriter(libraryStruct &library) {
  string firstName, lastName;
  unsigned short age;
  char genre;
  writerStruct newWriter;

  clearScreen();
  showAppTitle(library);

  gotoxy(40, 6);
  cout << "Va a registrar un nuevo escritor:" << endl;

  firstName = requestText("Ingrese los nombres del nuevo autor", 1);
  lastName = requestText("Ingrese los apellidos del nuevo autor", 1);
  age = requestIntegerNumber("Ingrese la edad del nuevo autor", 18);
  genre = requestGenre("Ingrese el genero del nuevo autor");

  newWriter = buildWriter(firstName, lastName, age, genre);

  push(library.writers, newWriter);

  cout << "El escritor del libro fue añadido de forma exitosa" << endl;
}

void showTopWriter(libraryStruct library) {
  clearScreen();
  showAppTitle(library);

  gotoxy(40, 6);

  writerNode *top_writer_node = library.writers.top;

  if (top_writer_node != NULL) {
    cout << "El ultimo autor registrado es:" << endl;

    showWritersListHeader(8);

    showWriter(top_writer_node->writer, 1, 10);
  } else
    cout << "No hay autores registrados";

  cout << endl << endl;
}

void showWriters(libraryStruct library) {
  clearScreen();
  showAppTitle(library);

  gotoxy(40, 6);
  cout << "Autores registrados:" << endl;

  writerNode *writer_node = library.writers.top;

  showWritersListHeader(8);

  int i = 1;
  while (writer_node != NULL) {
    showWriter(writer_node->writer, i, i + 9);
    writer_node = writer_node->next;
    i++;
  }

  cout << endl << endl;
}

void findWritersByLastName(libraryStruct library) {
  string textToFind;
  bool writerFound = false;

  clearScreen();
  showAppTitle(library);

  textToFind = requestText("Ingrese el apellido del escritor a buscar", 3);

  gotoxy(40, 6);
  cout << "Escritores con un apellido similar a " << textToFind << endl;

  writerNode *node = library.writers.top;

  showWritersListHeader(8);

  int i = 1;
  while (node != NULL) {
    if (containsText(node->writer.lastName, textToFind)) {
      writerFound = true;
      showWriter(node->writer, i, i + 9);
      i++;
    }
    node = node->next;
  }

  if (!writerFound)
    cout << endl
         << endl
         << "No se encontró ningun autor con un apellido similar";

  cout << endl << endl;
}

void deleteWriter(libraryStruct &library) {}

void mainMenu(libraryStruct &library) {

  int selectedOption;

  do {
    selectedOption = requestMenuOption(library);

    if (selectedOption != 0) {
      switch (selectedOption) {
      case 1:
        registerWriter(library);
        addDelay(2);
        break;

      case 2:
        showTopWriter(library);
        pauseProcess();
        break;

      case 3:
        showWriters(library);
        pauseProcess();
        break;

      case 4:
        findWritersByLastName(library);
        pauseProcess();
        break;

      case 5:
        deleteWriter(library);
        addDelay(2);
        break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}
