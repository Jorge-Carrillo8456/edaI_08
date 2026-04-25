#ifndef __LISTACIRCULARDOBLE_H__
#define __LISTACIRCULARDOBLE_H__

#include "nodo.h"

typedef struct CDlista CDlista;
struct CDlista{
    Nodo *head;
    Nodo *tail;
};  

CDlista *lista_crear();
bool lista_vacia(CDlista *l);
int num_nodos(CDlista *l);
bool lista_insertar_vacia(CDlista *l, void *dato, size_t size);
bool lista_insertar_head(CDlista *l, void *dato, size_t size);
bool lista_insertar_tail(CDlista *l, void *dato, size_t size);
bool lista_insertar_posicion(CDlista *l, int pos, void *dato, size_t size);
bool lista_eliminar_head(CDlista *l);
bool lista_eliminar_tail(CDlista *l);
bool lista_eliminar_posicion(CDlista *l, int pos);     
void lista_eliminar_elemento(CDlista *l, void *dato);
void lista_eliminar_elementos_similares(CDlista *l, void *dato);
Nodo* buscar_posicion(CDlista *l, int *pos);
int buscar_elemento(CDlista *l, void *dato);
Nodo* primero(CDlista* l);
Nodo* ultimo(CDlista* l);
Nodo* siguiente(Nodo* actual);
bool modificar(CDlista* l, int pos, void* dato, size_t size);
void imprimirLista(CDlista* l);
void vaciarLista(CDlista* l);
void borrarLista(CDlista* l);

extern int cmp(void*, void*);

#endif
