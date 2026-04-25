#ifndef __LISTALIGADA_H__
#define __LISTALIGADA_H__

#include "nodo.h"

typedef struct Dlista Dlista;
struct Dlista{
    Nodo *head;
    Nodo *tail;
};  

Dlista *lista_crear();
bool lista_vacia(Dlista *l);
int num_nodos(Dlista *l);
bool lista_insertar_vacia(Dlista *l, void *dato, size_t size);
bool lista_insertar_head(Dlista *l, void *dato, size_t size);
bool lista_insertar_tail(Dlista *l, void *dato, size_t size);
bool lista_insertar_posicion(Dlista *l, int pos, void *dato, size_t size);
bool lista_eliminar_head(Dlista *l);
bool lista_eliminar_tail(Dlista *l);
bool lista_eliminar_posicion(Dlista *l, int pos);     
void lista_eliminar_elemento(Dlista *l, void *dato);
void lista_eliminar_elementos_similares(Dlista *l, void *dato);
Nodo* buscar_posicion(Dlista *l, int *pos);
int buscar_elemento(Dlista *l, void *dato);
Nodo* primero(Dlista* l);
Nodo* ultimo(Dlista* l);
Nodo* siguiente(Nodo* actual);
bool modificar(Dlista* l, int pos, void* dato, size_t size);
void imprimirLista(Dlista* l); 
void vaciarLista(Dlista* l);
void borrarLista(Dlista* l);

// Declaramos que existirá una función cmp en algún lugar del programa
extern int cmp(void*, void*);

#endif
