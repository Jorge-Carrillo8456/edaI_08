#include "listaligada.h"

DlLista *lista_crear(){
    DlLista *nuevo = (DlLista *)malloc(sizeof(DlLista));
    if(nuevo!=NULL){
        nuevo->head = NULL;
        nuevo->tail = NULL;
    }
    return nuevo;
}
bool lista_vacia(DlLista *l){
    if((l->head==NULL)&&(l->tail==NULL)) return true;
    return false;
}
bool lista_insertar_vacia(DlLista *l, void *info, size_t size){
    if(lista_vacia(l)){
        Nodo *nuevo = nodo_crear(info, size);
        if(nuevo!=NULL){
            l->head = nuevo;
            l->tail = nuevo;
            return true;
        }
    }
    return false;
}
bool lista_insertar_head(DlLista *l, void *info, size_t size){
    Nodo *nuevo = nodo_crear(info, size);
    if(nuevo!=NULL){
        nuevo->sig=l->head;
        l->head->ant=nuevo;
        l->head=nuevo;
    }
}
bool lista_insertar_tail(DlLista *l, void *info, size_t size){
    Nodo *nuevo = nodo_crear(info, size);
    if(nuevo!=NULL){
        nuevo->ant=l->tail;
        l->tail->sig=nuevo;     
        l->tail=nuevo;
    }
}
bool lista_insertar_posicion(DlLista *l, int pos, void *info, size_t size){
}
void lista_eliminar_head(DlLista *l){
    
}
void lista_eliminar_tail(DlLista *l){
    
}
bool lista_eliminar_posicion(DlLista *l, int pos){
}    