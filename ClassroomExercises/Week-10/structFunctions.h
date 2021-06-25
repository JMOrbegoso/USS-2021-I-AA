#include "helpers.h"
#include "structs.h"

using namespace std;

// Factories

cityStruct buildCity(string name, unsigned long inhabitantsQuantity) {
  cityStruct city;

  city.name = name;
  city.inhabitantsQuantity = inhabitantsQuantity;

  return city;
}

void buildEdge(nodo* aux_1, nodo* aux_2, edge* newEdge) {
  edge* temp;
  if (aux_1->adyacente == NULL) {
    aux_1->adyacente = newEdge;
    newEdge->destiny = aux_2;
    cout << "Arista registrada";
  } else {
    newEdge->destiny = aux_2;
    temp->next = newEdge;
    cout << "Arista registrada";
  }
}

// Init

void collectionsInitialization(grafoStruct& grafo) {
  grafo.nogoG = NULL;
  grafo.edgeG = NULL;
}

void dataInitialization(grafoStruct& grafo) {}