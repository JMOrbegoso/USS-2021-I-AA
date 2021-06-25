#include <iostream>

using namespace std;

struct cityStruct {
  string name;
  unsigned long inhabitantsQuantity;
};

struct nodo {
  cityStruct city;
  struct nodo *next;
  struct edge *adyacente;
};

struct edge {
  struct nodo *destiny;
  struct edge *next;
};

struct grafoStruct {
  nodo *nogoG;
  edge *edgeG;
};
