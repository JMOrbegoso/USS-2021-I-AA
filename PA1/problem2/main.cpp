#include <basicas.cpp>
#include <estructuras.cpp>
#include <iostream>

using namespace std;

void inicializa(universidadStruct &universidad) {
  universidad.nombre = "USS";
  universidad.cursos.cant = 0;
  universidad.cursos.cab = NULL;
}

void inicializaCurso(curso &cur) {
  cur.estudiantes.cab = NULL;
  cur.estudiantes.cant = 0;
  cur.ciclo = 0;
}

void leerCurso(curso &cur) {
  gotoxy(20, 5);cur.nombre = leerTexto("Ingrese Nombre de Curso:");
  gotoxy(20, 6);cur.creditos = leerEntero("Ingrese numero de créditos :");
  gotoxy(20, 7);cur.codigo = leerEntero("Ingrese codigo:");
  gotoxy(20, 8);cur.ciclo = leerEntero("Ingrese ciclo:");
}

void insertarCurso(listaCursos &lC, curso cur) {
  nodoC *aux = new (struct nodoC);
  nodoC *temp = new (struct nodoC);
  temp->info = cur;
  temp->sgte = NULL;

  if (lC.cab == NULL) {
    lC.cab = temp;
    lC.cab->ant = NULL;
  } else {
    aux = lC.cab;
    while (aux->sgte != NULL) {
      aux = aux->sgte;
    }
    aux->sgte = temp;
    temp->ant = aux;
  }
  lC.cant++;
}

void insertarEstudiante(listaEstudiantes &lE, estudiante est) {
  nodoE *aux = new (struct nodoE);
  nodoE *temp = new (struct nodoE);
  temp->info = est;
  temp->sgte = NULL;
  if (lE.cab == NULL) {
    lE.cab = temp;
  } else {
    aux = lE.cab;
    while (aux->sgte != NULL) {
      aux = aux->sgte;
    }
    aux->sgte = temp;
  }
  lE.cant++;
}

void inicializarDatos(universidadStruct &universidad) {
  curso cur_1, cur_2;
  estudiante est_1, est_2;

  cur_1.codigo = "mat";
  cur_1.creditos = 3;
  cur_1.nombre = "matematica";
  cur_1.ciclo = 1;
  cur_1.estudiantes.cant = 0;
  cur_1.estudiantes.cab = NULL;

  cur_2.codigo = "fis";
  cur_2.creditos = 3;
  cur_2.nombre = "fisica";
  cur_2.ciclo = 1;
  cur_2.estudiantes.cant = 0;
  cur_2.estudiantes.cab = NULL;

  est_1.nombre = "Marcia";
  est_1.apellidos = "Garcia";
  est_1.direccion = "Av.";
  est_1.asistencia = 3;
  est_1.edad = 11;
  est_1.promFinal = 11;

  est_2.nombre = "Jose";
  est_2.apellidos = "Garcia";
  est_2.direccion = "Av.";
  est_2.asistencia = 3;
  est_2.edad = 11;
  est_2.promFinal = 11;

  insertarEstudiante(cur_1.estudiantes, est_1);
  insertarEstudiante(cur_2.estudiantes, est_2);

  insertarCurso(universidad.cursos, cur_1);
  insertarCurso(universidad.cursos, cur_2);
}

void registrarCurso(universidadStruct &universidad) {
  curso cur;
  inicializaCurso(cur);
  system("cls");
  leerCurso(cur);
  insertarCurso(universidad.cursos, cur);
}

nodoC *pedirCurso(listaCursos &cursos) {
  string codigoCurso;
  nodoC *aux;
  gotoxy(30, 11);cout << "Ingrese el codigo del curso:";
  cin >> codigoCurso;
  aux = cursos.cab;
  while (aux != NULL) {
    if (aux->info.codigo == codigoCurso) {
      cout << "Escogió " << aux->info.nombre << endl;
      return aux;
    }
    aux = aux->sgte;
  }
  gotoxy(20, 5);cout << "No se encontró el curso";
  return NULL;
}

void registrarEstudiante(universidadStruct &universidad) {
  estudiante est;
  nodoC *curso;
  system("cls");
  gotoxy(35, 3);cout << "NUEVO ESTUDIANTE";
  gotoxy(35, 4);cout << "==============";
  gotoxy(30, 5);est.apellidos = leerTexto("Ingrese apellidos:");
  gotoxy(30, 6);est.nombre = leerTexto("Ingrese nombre:");
  gotoxy(30, 7);est.direccion = leerTexto("Ingrese direccion:");
  gotoxy(30, 8);est.edad = leerEntero("Ingrese edad:");
  gotoxy(30, 9);est.promFinal = leerNota("Ingrese promedio:");
  gotoxy(30, 10);est.asistencia = leerEntero("Ingrese asistencia:");
  gotoxy(30, 11);curso = pedirCurso(universidad.cursos);
  if (curso == NULL) {
    cout << endl << "No se pudo registrar el estudiante" << endl << endl;
    return;
  }
  insertarEstudiante(curso->info.estudiantes, est);
  gotoxy(30, 11);cout << "El estudiante se registro correctamente en el curso"
       << curso->info.nombre << ", este curso ahora tiene "
       << curso->info.estudiantes.cant << " estudiantes." << endl
       << endl;
}

void mostrarCurso(curso cur, int x) {
  gotoxy(20, 8 + x);cout << x + 1;
  gotoxy(23, 8 + x);cout << cur.codigo;
  gotoxy(35, 8 + x);cout << cur.nombre;
  gotoxy(45, 8 + x);cout << cur.creditos;
}

void mostrarEstudiante(estudiante est, int x) {
  gotoxy(20, 8 + x);cout << x + 1;
  gotoxy(23, 8 + x);cout << est.apellidos;
  gotoxy(35, 8 + x);cout << est.nombre;
  gotoxy(45, 8 + x);cout << est.direccion;
  gotoxy(50, 8 + x);cout << est.edad;
  gotoxy(60, 8 + x);cout << est.promFinal;
}

void mostrarCursos(universidadStruct universidad) {
  nodoC *aux;
  gotoxy(30, 5);cout << "Cursos de la univerdidad";
  aux = universidad.cursos.cab;
  int i = 13;
  while (aux != NULL) {
    mostrarCurso(aux->info, i);
    aux = aux->sgte;
    i++;
  }
  cout << endl << endl;
}

void mostrarEstudiantes(universidadStruct universidad) {
  nodoC *auxC;
  nodoE *auxE;
  gotoxy(20, 5);cout << "Estudiantes de todos los cursos de la univerdidad";
  auxC = universidad.cursos.cab;
  int i = 13;
  while (auxC != NULL) {
    auxE = auxC->info.estudiantes.cab;
    while (auxE != NULL) {
      mostrarEstudiante(auxE->info, i);
      auxE = auxE->sgte;
      i++;
    }
    auxC = auxC->sgte;
  }
  cout << endl << endl;
}

void buscarEstudiante(universidadStruct universidad) {
  string apellidoPorBuscar;
  bool estudianteEncontrado = false;
  nodoC *auxC;
  nodoE *auxE;
  gotoxy(30, 16);cout << "Ingrese el apellido del estudiante:";
  cin >> apellidoPorBuscar;
  gotoxy(30, 17);cout << "Estudiantes de todos los cursos de la univerdidad con un apellido "
          "similar a "
       << apellidoPorBuscar;
  auxC = universidad.cursos.cab;
  int i = 13;
  while (auxC != NULL) {
    auxE = auxC->info.estudiantes.cab;
    while (auxE != NULL) {
      if (auxE->info.apellidos == apellidoPorBuscar) {
        mostrarEstudiante(auxE->info, i);
        estudianteEncontrado = true;
        i++;
      }
      auxE = auxE->sgte;
    }
    auxC = auxC->sgte;
  }
  if (!estudianteEncontrado)
    cout << "No se encontró ningun estudiante con el apellido "
         << apellidoPorBuscar;
  cout << endl << endl;
}

void listaAprobados(universidadStruct universidad) {
  nodoC *auxC;
  nodoE *auxE;
  gotoxy(20, 5);cout << "Estudiantes aprobados de la universidad ";
  auxC = universidad.cursos.cab;
  int i = 13;
  while (auxC != NULL) {
    auxE = auxC->info.estudiantes.cab;
    while (auxE != NULL) {
      if (auxE->info.promFinal >= 11) {
        mostrarEstudiante(auxE->info, i);
        i++;
      }
      auxE = auxE->sgte;
    }
    auxC = auxC->sgte;
  }
  cout << endl << endl;
}

void listaDesaprobados(universidadStruct universidad) {
  nodoC *auxC;
  nodoE *auxE;
  gotoxy(20, 5); cout << "Estudiantes desaprobados de la universidad ";
  auxC = universidad.cursos.cab;
  int i = 13;
  while (auxC != NULL) {
    auxE = auxC->info.estudiantes.cab;
    while (auxE != NULL) {
      if (!(auxE->info.promFinal >= 11)) {
        mostrarEstudiante(auxE->info, i);
        i++;
      }
      auxE = auxE->sgte;
    }
    auxC = auxC->sgte;
  }
  cout << endl << endl;
}

void listaInhabilitados(universidadStruct universidad) {
  nodoC *auxC;
  nodoE *auxE;
  gotoxy(20, 5); cout << "Estudiantes inhabilitados de la universidad ";
  auxC = universidad.cursos.cab;
  int i = 13;
  while (auxC != NULL) {
    auxE = auxC->info.estudiantes.cab;
    while (auxE != NULL) {
      if (auxE->info.asistencia < 5) {
        mostrarEstudiante(auxE->info, i);
        i++;
      }
      auxE = auxE->sgte;
    }
    auxC = auxC->sgte;
  }
  cout << endl << endl;
}

int main() {
  universidadStruct universidad;
  inicializa(universidad);
  inicializarDatos(universidad);
  int opc;
  do {
    opc = menu();
    switch (opc) {
    case 1:
      registrarCurso(universidad);
      break;
    case 2:
      registrarEstudiante(universidad);
      break;
    case 3:
      mostrarCursos(universidad);
      break;
    case 4:
      mostrarEstudiantes(universidad);
      break;
    case 5:
      buscarEstudiante(universidad);
      break;
    case 6:
      listaAprobados(universidad);
      break;
    case 7:
      listaDesaprobados(universidad);
      break;
    case 8:
      listaInhabilitados(universidad);
      break;
    }
  } while (!(opc == 9));
  return 0;
}
