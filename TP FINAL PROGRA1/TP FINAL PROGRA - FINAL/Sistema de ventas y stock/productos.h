#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED
#include "FUNCIONES_PRODUCTOS.h"

////////////////////////////////////////////////////
///estructura//////////////////////////////////////
//////////////////////////////////////////////////

typedef struct {
    char nombre[90];
    float precio;
    int codigo;
    int stock;
    int estado;
} producto;

////////////////////////////////////////////////////
///prototipado/////////////////////////////////////
//////////////////////////////////////////////////

void mostrarUnProducto(producto unProducto);
void mostrarLista(char archivoProducto[]);
void cargarArchivo(char archivoProducto[]);
void formatearArchivoJ(char archivoProducto[]);
int buscarProductoPorCodigo(char archivoProducto[], producto* prod, int codigo);
float pedirCodigoYRetornarTotal(char archivoProducto[], int codigos[], int* validos);
void cargarTotalEnArchivo(char archivoProducto[], float total);
void mostrarArreglo (int A[], int validos);
void mostrarArchivoTotal(char archivoProducto[]);
producto restarStock(producto P);
void restarStockDeArchivo(char archivoProducto[], int codigo);
void restarArregloAlArhivo(char archivoProducto[], int arreglo[], int validos);

#endif // PRODUCTOS_H_INCLUDED
