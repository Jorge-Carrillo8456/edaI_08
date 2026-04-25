#include "../include/listacircularligada.h"

CDlista *lista_crear(){
    CDlista *nuevo = (CDlista *)malloc(sizeof(CDlista));
    if(nuevo!=NULL){
        nuevo->head = NULL;
        nuevo->tail = NULL;
    }
    return nuevo;
}

bool lista_vacia(CDlista *l){
    if((l->head==NULL)&&(l->tail==NULL)) return true;
    return false;
}

int num_nodos(CDlista *l){
    if(lista_vacia(l)){
        return 0;
    } else {
        int i = 0;
        Nodo *con = l->head;
        do {
            i++;
            con = con->sig;
        } while (con != l->head);
        return i;
    }
}

bool lista_insertar_vacia(CDlista *l, void *dato, size_t size){
    if(lista_vacia(l)){
        Nodo *nuevo = nodo_crear(dato, size);
        if(nuevo!=NULL){
            l->head = nuevo;
            l->tail = nuevo;
            nuevo->sig = nuevo;
            nuevo->ant = nuevo;
            return true;
        }
    }
    return false;
}

bool lista_insertar_head(CDlista *l, void *dato, size_t size){
    if(lista_vacia(l)){
        return lista_insertar_vacia(l, dato, size);
    }
    Nodo *nuevo = nodo_crear(dato, size);
    if(nuevo!=NULL){
        nuevo->sig = l->head;
        nuevo->ant = l->tail;
        l->head->ant = nuevo;
        l->tail->sig = nuevo;
        l->head = nuevo;
        return true;
    }
    return false;
}

bool lista_insertar_tail(CDlista *l, void *dato, size_t size){
    if(lista_vacia(l)){
        return lista_insertar_vacia(l, dato, size);
    }
    Nodo *nuevo = nodo_crear(dato, size);
    if(nuevo!=NULL){
        nuevo->sig = l->head;
        nuevo->ant = l->tail;
        l->tail->sig = nuevo;
        l->head->ant = nuevo;
        l->tail = nuevo;
        return true;
    }
    return false;
}

bool lista_insertar_posicion(CDlista *l, int pos, void *dato, size_t size){
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
        nuevo->sig = tmp;
        nuevo->ant = tmp->ant;
        tmp->ant->sig = nuevo;
        tmp->ant = nuevo;
        return true;
    }
    return false;
}

bool lista_eliminar_head(CDlista *l){
    if(lista_vacia(l)){
        return false;
    } else {
        Nodo *tmp = l->head;
        if(l->head == l->tail){
            l->head = NULL;
            l->tail = NULL;
        } else {
            l->head = l->head->sig;
            l->head->ant = l->tail;
            l->tail->sig = l->head;
        }
        tmp->sig = NULL;
        tmp->ant = NULL;
        nodo_eliminar(tmp);
        return true;
    }
}

bool lista_eliminar_tail(CDlista *l){
    if(lista_vacia(l)){
        return false;
    } else {
        Nodo *tmp = l->tail;
        if(l->head == l->tail){
            l->head = NULL;
            l->tail = NULL;
        } else {
            l->tail = l->tail->ant;
            l->tail->sig = l->head;
            l->head->ant = l->tail;
        }
        tmp->sig = NULL;
        tmp->ant = NULL;
        nodo_eliminar(tmp);
        return true;
    }
}

bool lista_eliminar_posicion(CDlista *l, int pos){
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
        tmp->sig->ant = tmp->ant;
        tmp->ant->sig = tmp->sig;
        tmp->ant = NULL;
        tmp->sig = NULL;
        nodo_eliminar(tmp);
        return true;
    }
    return false;
}

void lista_eliminar_elemento(CDlista *l, void *dato) {
    if (lista_vacia(l)) return;
    int total = num_nodos(l);
    Nodo *tmp = l->head;
    
    for(int i=0; i<total; i++) {
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
                tmp->ant = NULL;
                tmp->sig = NULL;
                nodo_eliminar(tmp);
            }
            return; 
        }
        tmp = tmp->sig;
    }
}

void lista_eliminar_elementos_similares(CDlista *l, void *dato){
    if (lista_vacia(l)) return;
    int total = num_nodos(l);
    Nodo *tmp = l->head;
    Nodo *aux;
    
    for(int i=0; i<total; i++) {
        aux = tmp;   
        tmp = tmp->sig;
        
        if (cmp(aux->info, dato) == 0) {
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
    }
}

Nodo* buscar_posicion(CDlista *l, int *pos){
    if(lista_vacia(l) || *pos > num_nodos(l) || *pos < 1) return NULL;
    Nodo *tmp=l->head;
    for(int i=1; i<*pos; i++){
        tmp=tmp->sig;
    }
    return tmp;
}

int buscar_elemento(CDlista *l, void *dato){
    if (lista_vacia(l)) return -1;
    Nodo *tmp = l->head;
    int total = num_nodos(l);
    
    for(int i=1; i<=total; i++) {
        if(cmp(tmp->info, dato) == 0) return i;
        tmp = tmp->sig;
    }
    return -1; 
}

Nodo* primero(CDlista* l){
    return l->head;
}

Nodo* ultimo(CDlista* l){
    return l->tail;
}

Nodo* siguiente(Nodo* actual){
    if(actual != NULL) return actual->sig;
    return NULL;
}

bool modificar(CDlista* l, int pos, void* dato, size_t size){
    if(lista_vacia(l)){
        return false;
    } else {
        int con = num_nodos(l);
        if(pos>con || pos<1){
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

void imprimirLista(CDlista* l) {
    if (lista_vacia(l)) return;
    Nodo *tmp = l->head;
    do {
        tmp = tmp->sig;
    } while (tmp != l->head);
}

void vaciarLista(CDlista* l) {
    while (!lista_vacia(l)) {
        lista_eliminar_head(l);
    }
}

void borrarLista(CDlista* l) {
    if (l != NULL) {
        vaciarLista(l);
        free(l);
    }
}
