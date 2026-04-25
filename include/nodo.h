#ifndef __NODO_H__
#define __NODO_H__

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


typedef struct Nodo Nodo;
struct Nodo{
    void *info;
    Nodo *sig;
    Nodo *ant;
};

Nodo *nodo_crear(void *dato, size_t size);
void nodo_eliminar(Nodo *nodo);
bool nodo_actualizar(Nodo *nodo, void *dato, size_t size);

#endif
