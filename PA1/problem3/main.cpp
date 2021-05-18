#include <iostream>
#include <estructuras.cpp>
#include <basicas.cpp>

using namespace std;

void inicializar_Postulante(lista_Postulante & LP){
    LP.cab = NULL;
    LP.N_Postulante = 0;
}

void inicializar_Escuelas(lista_Escuela & LE){
    LE.cab = NULL;
    LE.N_Escuelas= 0;
}

void llenar_Postulante(postulante & P, string escuela){
     system("cls");
     gotoxy(35,4); P.apellidos = leerTexto("APELLIDO  :  ");
     gotoxy(35,5); P.nombres = leerTexto("NOMBRE    :  ");
     gotoxy(35,6); P.DNI = leerDNI("DNI       :  ");
     gotoxy(35,7); P.Email = leerTexto("EMAIL     :  ");
     gotoxy(35,8); P.direccion = leerTexto("DIRECCION :  ");
     gotoxy(35,9); P.puntaje = leerFloat("PUNTAJE   :  ",0,100);
     P.Nombre_Escuela = escuela;
}

void mostrar_Postulante(postulante  P){
    gotoxy(35,6); cout << "APELLIDO  :  " << P.apellidos;
    gotoxy(35,7); cout << "NOMBRE    :  " << P.nombres;
    gotoxy(35,8); cout << "DNI       :  " << P.DNI;
    gotoxy(35,9); cout << "EMAIL     :  " << P.Email;
    gotoxy(35,10); cout << "DIRECCION :  " << P.direccion;
    gotoxy(35,11); cout << "PUNTAJE   :  " << P.puntaje;
    gotoxy(35,12); cout << "ESCUELA  :  " << P.Nombre_Escuela;

}
/**/
void mostrar_P(postulante P,int i){
    int x=0;
       gotoxy(3,5+x+i); cout << x+i+1;
       gotoxy(9,5+x+i); cout << P.apellidos;
       gotoxy(24,5+x+i); cout << P.nombres;
       gotoxy(40,5+x+i); cout << P.DNI;
       gotoxy(55,5+x+i); cout << P.direccion;
       gotoxy(70,5+x+i); cout << P.Email;
       gotoxy(91,5+x+i); cout << P.Nombre_Escuela;
       gotoxy(108,5+x+i); cout << P.puntaje;
       x++;
    cout << endl<< endl;
}

void mostrar_lista_Postulantes(lista_Postulante LP,int i){
    nodo_Postulante * aux = LP.cab;
    int x =0;
    while (aux != NULL) {
       gotoxy(3,5+x+i); cout << x+i+1;
       gotoxy(9,5+x+i); cout << aux->info.apellidos;
       gotoxy(24,5+x+i); cout << aux->info.nombres;
       gotoxy(40,5+x+i); cout << aux->info.DNI;
       gotoxy(55,5+x+i); cout << aux->info.direccion;
       gotoxy(70,5+x+i); cout << aux->info.Email;
       gotoxy(91,5+x+i); cout << aux->info.Nombre_Escuela;
       gotoxy(108,5+x+i); cout << aux->info.puntaje;
       x++;
       aux = aux->sgt;
    }
    cout << endl<< endl;
}
/**/
void llenar_Escuelas(escuelas &E){
     system("cls");
     gotoxy(35,4); E.nombre = leerTexto(" NOMBRE DE ESCUELA : ");
     gotoxy(35,5); E.ciclos = leerEntero(" NUMERO DE CICLOS  : ",1,15);
     gotoxy(35,6); E.codigo = leerTexto(" CODIGO DE ESCUELA : ");
     gotoxy(35,7); E.titulo = leerTexto(" TITULO            : ");
     inicializar_Postulante(E.LP);
}
void mostrarEscuelas(lista_Escuela  LE){
    nodo_Escuelas * aux = LE.cab;
    int x =0;
    system("cls");
    Cabecera_Escuela();
    while (aux != NULL) {
       gotoxy(5,4+x); cout << x+1;
       gotoxy(20,4+x); cout << aux->info.nombre;
       gotoxy(40,4+x); cout << aux->info.ciclos;
       gotoxy(50,4+x); cout << aux->info.codigo;
       gotoxy(60,4+x); cout << aux->info.titulo;
       aux = aux->sgt;
        x++;
    }
    cout << endl<< endl;
    system("pause");
}

void Agregar_Postulante(lista_Postulante & LP, postulante P){
        nodo_Postulante * aux = new nodo_Postulante;
        nodo_Postulante * nuevo = new nodo_Postulante;
        nuevo->info = P;
        nuevo->sgt = NULL;
        if (LP.cab == NULL) {
            LP.cab = nuevo;
        }
        else{
            aux = LP.cab;
            while (aux->sgt != NULL) {
                aux = aux->sgt;
            }
            aux->sgt = nuevo;
        }
    LP.N_Postulante ++ ;
}

void Agregar_Escuelas(lista_Escuela &LE, escuelas E){
        nodo_Escuelas * nuevoNodo = new nodo_Escuelas;
        nodo_Escuelas * nodoActual = new nodo_Escuelas;
        nuevoNodo->info = E;
        nodoActual = LE.cab;

        if (nodoActual) {
            while (nodoActual->sgt) {
                nodoActual = nodoActual->sgt;
            }
            nuevoNodo->sgt = nodoActual->sgt;
            nodoActual->sgt = nuevoNodo;
            nuevoNodo->ant = nodoActual;
        }
        else{
            nuevoNodo->sgt = nodoActual;
            nuevoNodo->ant = NULL;
            LE.cab = nuevoNodo;
        }

    LE.N_Escuelas++;
}

void Registro_Postulante(lista_Postulante &LP, string escuela){
    postulante nuevo;
    llenar_Postulante(nuevo, escuela);
    Agregar_Postulante(LP,nuevo);
}
/**/

nodo_Escuelas *Buscar(lista_Escuela LE, string seleccionado){
    system("cls");
    cout << endl<< endl<<endl;
    string escuela_B = seleccionado;
     nodo_Escuelas*aux = LE.cab;
     while (aux != NULL) {
         if (aux->info.nombre == escuela_B) {
             return aux; break;
         }
         aux= aux->sgt;
     }
 }
void R_lista_Postulantes_Escuela(lista_Escuela LE){
    system("cls");
    if (LE.N_Escuelas> 0) {
        nodo_Escuelas * aux = LE.cab;  
        string seleccionado;
        gotoxy(28,5); seleccionado =leerTexto("ESCUELA A MOSTRAR:    ");
        aux = Buscar(LE,seleccionado);
        if (aux != NULL) {
            system("cls");
            cout << "\t\t\t\tESCUELA:   "<< aux->info.nombre;
            cabecera_Postulantes();
            mostrar_lista_Postulantes(aux->info.LP, 0);
        }
        system("pause");
    }
    else{
        gotoxy(30,3);cout << "--- FALTA DE DATOS ---"<<endl;
    }
}
/**/
void R_Lista_General_Postulante(lista_Escuela LE){
    if (LE.N_Escuelas> 0) {
        nodo_Escuelas * aux = LE.cab;
        system("cls");
        cout<< endl;
        int i =0;
        cabecera_Postulantes();
        while (aux != NULL) {
            mostrar_lista_Postulantes(aux->info.LP, i);
            aux = aux->sgt;
            i++;
        }
        system("pause");
    }
    else{
        system("cls");
        gotoxy(30,3);cout << "--- FALTA DE DATOS ---"<<endl;
    }
}

void R_Supera_Puntaje(lista_Escuela LE){
    system("cls");
    cout << endl<< endl<<endl;
    int i=0;
    float Puntaje_postulante_B = leerFloat("        PUNTAJE A COMPARAR  :  ",1,100);
     nodo_Escuelas*aux = LE.cab;
     system("cls");
     cout  <<"          CON PUNTAJE MAYOR AL INGRESADO "<< endl;
     cabecera_Postulantes();
     while (aux != NULL) {
         nodo_Postulante*temp = aux->info.LP.cab;
         while (temp != NULL) {
             if (temp->info.puntaje > Puntaje_postulante_B) {
                 mostrar_P(temp->info,i);
                 i++;
                 //system("pause");
             }
             temp= temp->sgt;
         }
         aux= aux->sgt;
     }
     if (i<1) {
         system("cls");
         gotoxy(30,3);cout << "--- NO SE ENCONTRARON POSTULANTES QUE EXCEDAN EL VALOR INGRESADO ---"<<endl;
     }
     cout << endl<<endl;
     system("pause");
 }

void OP_Buscar_Postulante(lista_Escuela LE){
    system("cls");
    cout << endl<< endl<<endl;
    int i=0;
    string DNI_postulante_B = leerTexto("           DNI DE POSTULANTE A BUSCAR:  ");
     nodo_Escuelas*aux = LE.cab;
     system("cls");
     while (aux != NULL) {
         nodo_Postulante*temp = aux->info.LP.cab;
         while (temp != NULL) {
             if (temp->info.DNI == DNI_postulante_B) {
                 cout <<endl <<"               POSTULANTE ENCONTRADO"<< endl;
                 mostrar_Postulante(temp->info);
                 i++;
                 //system("pause");
             }
             temp= temp->sgt;
         }
         aux= aux->sgt;
     }
     if (i<1) {
         system("cls");
         gotoxy(30,3);cout << "--- NO SE ENCONTRO AL POSTULANTE ---"<<endl;
     }
     cout << endl<<endl;
     system("pause");
 }

void OP_Registrar_Postulante(lista_Escuela & LE){
    if (LE.N_Escuelas >0 ) {
        int num_E;
        string escuela;
        nodo_Escuelas * nuevo = new nodo_Escuelas;
        mostrarEscuelas(LE);
        nuevo = LE.cab;
        num_E = leerEntero("SELECCION DE ESCUELA: ", 1, LE.N_Escuelas);
        for (int x=0;x<num_E-1 ; x++) {
            nuevo = nuevo->sgt;
        }
        escuela = nuevo->info.nombre;
        Registro_Postulante(nuevo->info.LP, escuela);
    }
    else {
        system("cls");
        gotoxy(30,3);cout << "---DEBE REGISTRAR ESCUELAS ---"<<endl<<endl<<endl;

    }
     system("pause");
}

void OP_Registrar_Escuelas(lista_Escuela &LE){
    escuelas nuevo;
    llenar_Escuelas(nuevo);
    Agregar_Escuelas(LE,nuevo);
}

int OP_Reportes(lista_Escuela LE)
{
    int op;
    do{
        op = menu_Reportes();
        switch (op) {
           case 1: R_Lista_General_Postulante(LE); break;
           case 2: R_lista_Postulantes_Escuela(LE); break;
           case 3: R_Supera_Puntaje(LE); break;
        }
    }while(!(op == 4));
}


int main()
{
    lista_Escuela LE;
    inicializar_Escuelas(LE);
    int op;
    do{
        op = menu();
        switch (op) {
           case 1: OP_Registrar_Escuelas(LE); break;
           case 2: OP_Registrar_Postulante(LE); break;
           case 3: OP_Buscar_Postulante(LE); break;
           case 4: OP_Reportes(LE);break;
        }
    }while(!(op == 5));
}
