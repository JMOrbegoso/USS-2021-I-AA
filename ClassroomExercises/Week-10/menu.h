#include "structFunctions.h"

using namespace std;

void showAppTitle() {
  cout << endl
       << "-----------------------------------------------------------" << endl;
  cout << "\t Nombre: Problema de clase - 10 " << endl << endl << endl;
  cout << "-----------------------------------------------------------" << endl;
}

void registerNewNode(nodo *&cabezaG) {
  cityStruct city;
  string name;
  unsigned long inhabitantsQuantity;
  nodo *aux;
  nodo *newNode = new struct nodo;

  name = requestText("Ingrese el nombre de la ciudad", 1);
  inhabitantsQuantity =
      requestIntegerNumber("Ingrese la cantidad de habitantes de la ciudad",
                           "Por favor ingrese una cantidad mayor a 0", 0);

  city = buildCity(name, inhabitantsQuantity);

  if (cabezaG == NULL) {
    cabezaG = newNode;
    cout << "Ciudad registrada exitosamente.";
  } else {
    aux = cabezaG;
    while (aux != NULL) {
      aux = aux->next;
    }
    aux->next = newNode;
    cout << "Ciudad registrada exitosamente.";
  }
}

void registerNewEdge(nodo *cabezaG) {
  string cityName_1, cityName_2;
  edge *newEdge = new struct edge;
  nodo *aux_1, *aux_2;

  if (cabezaG == NULL) {
    cout << "El grafo está vacío";
    return;
  }

  newEdge->next = NULL;

  cityName_1 = requestText("Ingrese la ciudad de origen", 1);
  cityName_2 = requestText("Ingrese la ciudad de destino", 1);

  aux_1 = aux_2 = cabezaG;

  while (aux_2 != NULL) {
    if (aux_2->city.name == cityName_2) {
      break;
    }
    aux_2 = aux_2->next;
  }

  if (aux_2 != NULL) {
    while (aux_1 != NULL) {
      if (aux_1->city.name == cityName_1) {
        buildEdge(aux_1, aux_2, newEdge);
      }
      aux_1 = aux_1->next;
    }
  }
}

void showCities(nodo *cabezaG) {
  clearScreen();
  nodo *aux;
  edge *temp;
  aux = cabezaG;

  cout << "Ciudad origen";
  cout << "Ciudad destino";

  while (aux != NULL) {
    cout << aux->city.name;
    if (aux->adyacente != NULL) {
      temp = aux->adyacente;
      while (temp != NULL) {
        cout << temp->destiny->city.name;
        temp = temp->next;
      }
    }
    aux = aux->next;
  }
  pauseProcess();
}

int requestMenuOption() {
  int selectedOption;

  clearScreen();
  showAppTitle();

  cout << endl
       << "Esta aplicación tiene las siguientes opciones:" << endl
       << endl;

  cout << "[1] Registrar Ciudad (nodo)" << endl;
  cout << "[2] Registrar arista" << endl;
  cout << "[3] Mostrar el grafo" << endl;
  cout << endl;
  cout << "[0] Cerrar" << endl;

  cout << endl << "Por favor ingrese una de las opciones:" << endl;
  cin >> selectedOption;
  while (!(0 <= selectedOption && selectedOption <= 3)) {
    cout << "La opcion seleccionada fue inválida, por favor seleccione una "
            "opcion válida:"
         << endl;
    cin >> selectedOption;
  }
  return selectedOption;
}

void mainMenu(grafoStruct &grafo) {
  int selectedOption;

  do {
    selectedOption = requestMenuOption();

    if (selectedOption != 0) {
      switch (selectedOption) {
        case 1:
          registerNewNode(grafo.nogoG);
          addDelay(1.5);
          break;

        case 2:
          registerNewEdge(grafo.nogoG);
          addDelay(1.5);
          break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}
