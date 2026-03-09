#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "productos.h"


void mostrarUnProducto(producto unProducto){

    printf("\n---------------------------\n");
    printf("|%s", unProducto.nombre);
    printf("...........$%.2f|", unProducto.precio);
    printf("\ncodigo: %d", unProducto.codigo);
    printf("\nstock: %d", unProducto.stock);
    printf("\n---------------------------\n");

}

void mostrarLista(char archivoProducto[]){
    FILE *buffer = fopen(archivoProducto, "rb");

    if (buffer!=NULL){

            producto unProducto;
            int i=1;

            while (fread(&unProducto, sizeof(producto), 1, buffer)>0){
                printf("\nproducto %d: ", i);
                mostrarUnProducto(unProducto);
                i++;
            }
            fclose(buffer);
    }
    else
        printf("el archivo no existe");
}

void formatearArchivoJ(char archivoProducto[]){
    FILE *buffer = fopen(archivoProducto, "wb");
    fclose(buffer);
}

int buscarProductoPorCodigo(char archivoProducto[], producto* prod, int codigo){
    //recorre el archivo y si lo encuentra modifica el producto que ingresa por parametro
    //si lo encuentra retorna 1, sino 0

    FILE *buffer = fopen(archivoProducto, "rb");
    int res=0;

    if (buffer!=NULL){

    producto unProducto;

        while (fread(&unProducto, sizeof(producto), 1, buffer)>0){

            if (unProducto.codigo==codigo){

                *prod=unProducto;
                res = 1;
                fclose(buffer);
            }
        }

        fclose(buffer);
    }
    else{
        printf("el archivo no existe");
        }

        return res;
}

float pedirCodigoYRetornarTotal(char archivoProducto[], int codigos[], int* validos){
     //pide codigo, lo carga en un arreglo y modifica validos a medida q carga el arreglo
    //el arreglo se sobreescribe y reutiliza por cada venta que se haga
    int i=0;
    producto prod;
    int codigo;
    int res=0;
    float total=0;
    char control='s';

    while (control=='s'){

        do{
            printf("\ningrese un codigo: ");
            fflush(stdin);
            scanf("%d", &codigo);

            res=buscarProductoPorCodigo(archivoProducto, &prod, codigo);

            if (res==0){
                printf("\nCODIGO INCORRECTO\n");
            }
        }
        while (res==0);

        total+=prod.precio;
        printf("\nprecio........$%.2f", total);

        codigos[i]=codigo;
        i++;

        printf("\n\nAgregar? s/n: ");
        fflush(stdin);
        scanf("%c", &control);
    }

    *validos=i;
    return total;
}

void cargarTotalEnArchivo(char archivoProducto[], float total){
    FILE* buff=fopen(archivoProducto, "ab");

    if (buff){
        fwrite(&total, sizeof(float), 1, buff);
        fclose(buff);
    }
}

void mostrarArchivoTotal(char archivoProducto[]){
    FILE *buffer = fopen(archivoProducto, "rb");

    if (buffer!=NULL){

            int i=1;
            float num;

            while (fread(&num, sizeof(float), 1, buffer)>0){
                printf("\nVENTA %d: ", i);
                printf("TOTAL: %.2f", num);
                i++;
            }
            fclose(buffer);
    }
    else
        printf("el archivo no existe");
}

producto restarStock(producto P){
    P.stock--;
    return P;
}

void restarStockDeArchivo(char archivoProducto[], int codigo){

    FILE *buffer = fopen(archivoProducto, "r+b");
    producto unProducto;

    if (buffer!=NULL){
            while (fread(&unProducto, sizeof(producto), 1, buffer)>0){
                if (unProducto.codigo==codigo){
                    unProducto=restarStock(unProducto);
                    fseek(buffer,(sizeof(producto)*-1), SEEK_CUR);
                    fwrite(&unProducto, sizeof(producto), 1, buffer);
                    break;
                }
            }
    fclose(buffer);
    }
}

void restarArregloAlArhivo(char archivoProducto[], int arreglo[], int validos){
    int i=0;
    for (i=0;i<validos;i++){
        restarStockDeArchivo(archivoProducto, arreglo[i]);
    }
}
