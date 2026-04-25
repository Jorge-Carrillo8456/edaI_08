#include "../include/listaligada.h"

Dlista *lista_crear(){
    Dlista *nuevo = (Dlista *)malloc(sizeof(Dlista));
    if(nuevo!=NULL){
        nuevo->head = NULL;
        nuevo->tail = NULL;
    }
    return nuevo;
}

bool lista_vacia(Dlista *l){
    if((l->head==NULL)&&(l->tail==NULL)) return true;
    return false;
}

int num_nodos(Dlista *l){
    if(lista_vacia(l)){
        return 0;
    } else {
        int i = 0;
        for (Nodo *con = l->head; con != NULL; con = con->sig) {
            i++;
        }
        return i;
    }
}

bool lista_insertar_vacia(Dlista *l, void *dato, size_t size){
    if(lista_vacia(l)){
        Nodo *nuevo = nodo_crear(dato, size);
        if(nuevo!=NULL){
            l->head = nuevo;
            l->tail = nuevo;
            return true;
        }
    }
    return false;
}

bool lista_insertar_head(Dlista *l, void *dato, size_t size){
    if(lista_vacia(l)) return lista_insertar_vacia(l, dato, size);
    
    Nodo *nuevo = nodo_crear(dato, size);
    if(nuevo!=NULL){
        nuevo->sig=l->head;
        l->head->ant=nuevo;
        l->head=nuevo;
        return true; 
    }
    return false;
}

bool lista_insertar_tail(Dlista *l, void *dato, size_t size){
    if(lista_vacia(l)) return lista_insertar_vacia(l, dato, size);
    
    Nodo *nuevo = nodo_crear(dato, size);
    if(nuevo!=NULL){
        nuevo->ant=l->tail;
        l->tail->sig=nuevo;     
        l->tail=nuevo;
        return true; 
    }
    return false;
}

bool lista_insertar_posicion(Dlista *l, int pos, void *dato, size_t size){
    int con = num_nodos(l);
    if(pos>con){
        return false;
    } else if (lista_vacia(l)){
        lista_insertar_vacia(l, dato, size);
        return true;
    } else if (pos==1){
        lista_insertar_head(l, dato, size);
        return true;
    } else if (pos==con){
        lista_insertar_tail(l, dato, size);
        return true;
    } else if ((pos<con)&&(pos>1)){
        int i=1;
        Nodo *tmp=l->head;
        for(; i<pos; i++){
            tmp=tmp->sig;
        }
        Nodo *nuevo = nodo_crear(dato, size);
        nuevo->sig=tmp;
        nuevo->ant=tmp->ant;
        tmp->ant->sig=nuevo;
        tmp->ant=nuevo;
        return true;
    }
    return false;
}

bool lista_eliminar_head(Dlista *l){
    if(lista_vacia(l)){
        return false;
    } else {
        Nodo *tmp=l->head;
        l->head=l->head->sig;
        
        if(l->head != NULL) {
            l->head->ant=NULL;
        } else {
            l->tail = NULL; 
        }
        
        tmp->sig=NULL;
        tmp->ant=NULL;
        nodo_eliminar(tmp);
        return true;
    }
}

bool lista_eliminar_tail(Dlista *l){
    if(lista_vacia(l)){
        return false;
    } else {
        Nodo *tmp=l->tail;
        l->tail=l->tail->ant;
        
        if(l->tail != NULL) {
            l->tail->sig=NULL;
        } else {
            l->head = NULL;
        }
        
        tmp->ant=NULL;
        tmp->sig=NULL; 
        nodo_eliminar(tmp);
        return true;
    }
}

bool lista_eliminar_posicion(Dlista *l, int pos){
    int con = num_nodos(l);
    if(pos>con){
        return false;
    } else if (pos==1){
        lista_eliminar_head(l);
        return true;
    } else if (pos==con){
        lista_eliminar_tail(l);
        return true;
    } else if ((pos<con)&&(pos>1)){
        int i=1;
        Nodo *tmp=l->head;
        for(; i<pos; i++){
            tmp=tmp->sig;
        }
        tmp->sig->ant=tmp->ant;
        tmp->ant->sig=tmp->sig;
        tmp->ant=NULL;
        tmp->sig=NULL;
        nodo_eliminar(tmp);
        return true;
    }
    return false;
}     

void lista_eliminar_elemento(Dlista *l, void *dato) {
    if (lista_vacia(l)) return;
    Nodo *tmp = l->head;
    while (tmp != NULL) {
        if (cmp(tmp->info, dato) == 0) {
            if (tmp == l->head) {
                lista_eliminar_head(l);
            } 
            else if (tmp == l->tail) {
                lista_eliminar_tail(l);
            } 
            else {
                tmp->ant->sig = tmp->sig;
                tmp->sig->ant = tmp->ant;
                tmp->ant=NULL;
                tmp->sig=NULL;
                nodo_eliminar(tmp);
            }
            return; 
        }
        tmp = tmp->sig;
    }
}

void lista_eliminar_elementos_similares(Dlista *l, void *dato){
    if (lista_vacia(l)) return;
    Nodo *tmp = l->head;
    Nodo *aux;
    while (tmp != NULL) {
        if (cmp(tmp->info, dato) == 0) {
            aux = tmp;   
            tmp = tmp->sig;

            if (aux == l->head) {
                lista_eliminar_head(l);
            } 
            else if (aux == l->tail) {
                lista_eliminar_tail(l);
            } 
            else {
                aux->ant->sig = aux->sig;
                aux->sig->ant = aux->ant;
                aux->ant = NULL;
                aux->sig = NULL;
                nodo_eliminar(aux);
            }
        } 
        else {
            tmp = tmp->sig;
        }
    }
}

Nodo* buscar_posicion(Dlista *l, int *pos){
    if(lista_vacia(l) || *pos > num_nodos(l) || *pos < 1) return NULL;
    
    Nodo *tmp=l->head;
    for(int i=1; i<*pos; i++){
        tmp=tmp->sig;
    }
    return tmp;
}

int buscar_elemento(Dlista *l, void *dato){
    if (lista_vacia(l)) return -1;
    
    Nodo *tmp=l->head;
    int i=1;
    while(tmp != NULL){
        if(cmp(tmp->info, dato) == 0) return i;
        i++;
        tmp=tmp->sig;
    }
    return -1; 
}

Nodo* primero(Dlista* l){
    return l->head;
}

Nodo* ultimo(Dlista* l){
    return l->tail;
}

Nodo* siguiente(Nodo* actual){
    if(actual != NULL) return actual->sig;
    return NULL;
}

bool modificar(Dlista* l, int pos, void* dato, size_t size){
    if(lista_vacia(l)){
        return false;
    } else {
        int con = num_nodos(l);
        if(pos>con || pos < 1){
            return false;
        } else if (pos==1){
            nodo_actualizar(l->head, dato, size);
            return true;
        } else if (pos==con){
            nodo_actualizar(l->tail, dato, size);
            return true;
        } else {
            int i=1;
            Nodo *tmp=l->head;
            for(; i<pos; i++){
                tmp=tmp->sig;
            }
            nodo_actualizar(tmp, dato, size);
            return true;
        }
    }
}

void vaciarLista(Dlista* l) {
    while (!lista_vacia(l)) {
        lista_eliminar_head(l); 
    }
}

void borrarLista(Dlista* l) {
    if (l != NULL) {
        vaciarLista(l);
        free(l);
    }
}
