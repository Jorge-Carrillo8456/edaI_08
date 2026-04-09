#include "nodo.h"

Nodo *nodo_crear(void *info, size_t size){
    Nodo *nuevo =(Nodo *)malloc(sizeof(Nodo));
    if(nuevo!=NULL){
        nuevo->sig = NULL;
        nuevo->ant = NULL;
        nuevo->info = malloc(size);
        memcpy(nuevo->info, info, size);
    }
    return nuevo;
}

void nodo_eliminar(Nodo *nodo){
    if(nodo!=NULL){
        if((nodo->sig==NULL)&&(nodo->ant==NULL)){
            free(nodo->info);
            free(nodo);
        }
    }
}

bool nodo_actualizar(Nodo *nodo, void *info, size_t size){
    if(nodo!=NULL){
        nodo->info = realloc(nodo->info, size);
        if(!nodo->info) return false;
        memcpy(nodo->info, info, size);
    }
    return true;
}