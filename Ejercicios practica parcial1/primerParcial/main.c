#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pila.h"
///prototipado
///eje1
int cargarArrayAyB(int dimC,int A[dimC],int B[dimC]);
///2
int sumatoria (int validos,int B[validos]);
float promedio(int validos,int B [validos]);
///3
void returnPyI(int validos,int B[validos],int *pares,int *impares);
///4
void cargarCparCimpar(int dimF,int dimC,int M[dimF][dimC]);
///5
void pasaraPfila(int dimF,int dimC,int M[dimF][dimC],int fila,Pila *pila);
///6
void mostrarM(int dimF,int dimC,int M[dimF][dimC]);
void mostrarArray(int validos,int B[validos]);
int main()
{
    int x,validos,fila;
    int pares=0;
    int impares=0;
    float prom;
    int dimC=100;
    int dimF=100;
    int A[dimC];
    int B[dimC];
    int M[dimF][dimC];
    Pila pila;
    inicpila(&pila);

    do{
    printf("\nEJERCICIOS\nPOINT 1\nPOINT 2\nPOINT 3\nPOINT 4\nPOINT 5\nPOINT 6\n");
    fflush(stdin);
    scanf("%d",&x);
    switch(x){

    case 1:

    validos=cargarArrayAyB(dimC,A,B);
    printf("validos%d",validos);

        break;

    case 2:
        validos=cargarArrayAyB(dimC,A,B);
        prom=promedio(validos,B);
        printf("el promedio es :%.2f",prom);

        break;

    case 3:
         validos=cargarArrayAyB(dimC,A,B);
         returnPyI(validos,B,&pares,&impares);
         printf("pares %d",pares);
         printf("impares %d",impares);
        break;

    case 4:
        printf("ingrese num de filas(3):");
        fflush(stdin);
        scanf("%d",&dimF);
        printf("ingrese num de columnas(3):");
        fflush(stdin);
        scanf("%d",&dimC);
        cargarCparCimpar(dimF,dimC,M);
        mostrarM(dimF,dimC,M);


        break;
    case 5:
        printf("ingrese num de filas(3):");
        fflush(stdin);
        scanf("%d",&dimF);
        printf("ingrese num de columnas(3):");
        fflush(stdin);
        scanf("%d",&dimC);
        printf("ingrese la fila que desea:");
        fflush(stdin);
        scanf("%d",&fila);
        cargarCparCimpar(dimF,dimC,M);
        mostrarM(dimF,dimC,M);
        pasaraPfila(dimF,dimC,M,fila,&pila);
        mostrar(&pila);


    break;
    case 6:

        mostrarM(dimF,dimC,M);
        validos=cargarArrayAyB(dimC,A,B);
        mostrarArray(validos,B);

        break;










}return 0;
}while (x!=0);
}



///1
int cargarArrayAyB(int dimC,int A[dimC],int B[dimC]){
int i=0;
int x=0;
int num=0;
int control=1;
while(i<dimC && control==1){
    printf("ingrese un num:");
    fflush(stdin);
    scanf("%d",&num);

    if((num)%3==0){
        A[i]=num;
    }
    else{
        B[i]=num;
        x++;
    }
    printf("desea seguir cargando?(1/0)");
    fflush(stdin);
    scanf("%d",&control);
i++;
}

return x;
}
///2
int sumatoria (int validos,int B[validos]){
int i=0;
int suma=0;
while(i<validos){

suma+=B[i];
i++;
}
return suma;
}

float promedio(int validos,int B [validos]){
int suma=sumatoria(validos,B);
int cant=validos;
float prom;

prom=(float)suma/(float)cant;

    return prom;
}
///3
void returnPyI(int validos,int B[validos],int *pares,int *impares){
int i=0;
while(i<validos){
    if (B[i]%2==0){
    pares++;
    i++;
    }
    else{
    impares++;
    i++;
    }
}
}

///4
void cargarCparCimpar(int dimF,int dimC,int M[dimF][dimC]){
int f;
int c;
int n1=1;
int n2=2;

for(f=0;f<dimF;f++){
    for(c=0;c<dimC;c++){
        M[f][c]=n2;

    }
}
for(f=1;f<dimF;f++){
    for(c=1;c<dimC;c++){
        M[f][c]=n1;
}
}
}
///4/6.B
void mostrarM(int dimF,int dimC,int M[dimF][dimC]){
int f;
int c;
for(f=0;f<dimF;f++){
    for(c=0;c<dimC;c++){
    printf("%d|",M[f][c]);
}
printf("\n");
}

}

///5
void pasaraPfila(int dimF,int dimC,int M[dimF][dimC],int fila,Pila *pila){
int f=fila;
int c=0;
while(c<dimC){
    apilar(pila,M[f][c]);
    c++;
}
}



///6.A
void mostrarArray(int validos,int B[validos]){
int i;
for(i=validos;i>0;i--){
    printf("%d|",B[i]);

}
}
