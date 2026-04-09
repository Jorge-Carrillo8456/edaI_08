#ifndef __LISTALIGADA_H__
#define __LISTALIGADA_H__
#include "nodo.h"

typedef struct DLista DlLista;
struct DlLista{
    Nodo *head;
    Nodo *tail;
};  

DlLista *lista_crear();
bool lista_vacia(DlLista *l);
bool lista_insertar_vacia(DlLista *l, void *info, size_t size);
bool lista_insertar_head(DlLista *l, void *info, size_t size);
bool lista_insertar_tail(DlLista *l, void *info, size_t size);
bool lista_insertar_posicion(DlLista *l, int pos, void *info, size_t size);
void lista_eliminar_head(DlLista *l);
void lista_eliminar_tail(DlLista *l);
bool lista_eliminar_posicion(DlLista *l, int pos);        

#endif