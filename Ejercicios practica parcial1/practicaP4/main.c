#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pila.h"
////prototipado
//1
int cargarArreglo(int dimC,int arreglo[dimC] );
//2
int pasarDeAaP (int validos,int arreglo[validos], Pila *A);
//3
Pila cargarP(Pila A);
void cargarM(int dimF,int dimC,int M[dimF][dimC]);
int compararMyP(int validos,int dimC,int M[validos][dimC],Pila A);




int main()
{
    int x,validos,i;
    int dimC=100;
    int dimF=100;
    int M[dimF][dimC];
    int arreglo[dimC];
    Pila A;
    inicpila(&A);

    do{
        printf("\nEJERCICIO\nPOINT 1\nPOINT 2\nPOINT 3\nPOINT 4\nPOINT 5\n");
        fflush(stdin);
        scanf("%d",&x);
        switch(x){

    case 1:
        validos=cargarArreglo(dimC,arreglo);
            break;

    case 2:

         validos=cargarArreglo(dimC,arreglo);
        i=pasarDeAaP(validos,arreglo,&A);
        if (i==1){
            printf("se pasaron una cant par");
        }
        else{
            printf("se pasaron una cant impar");
        }
            break;

    case 3:
        printf("cargando pila:\n");
        A=cargarP(A);
        printf("cargando Matriz:\n");
        printf("ingrese cant de filas");
        fflush(stdin);
        scanf("%d",&dimF);
        printf("ingrese cant de columnas");
        fflush(stdin);
        scanf("%d",&dimC);
        cargarM(dimF,dimC,M);
        i=compararMyP(dimF,dimC,M,A);
        printf("hay %d coincidencias",i);



            break;

    case 4:



            break;

    case 5:



            break;


}return 0;
}while (x!=0);
}


int cargarArreglo(int dimC,int arreglo[dimC]){
int i=0;
int control=1;
while(i<dimC && control==1){
    printf("ingrese un num:");
    fflush(stdin);
    scanf("%d",&arreglo[i]);

    printf("desea seguir ingresando?(1/0)");
    fflush(stdin);
    scanf("%d",&control);
i++;
}
return i;
}

int pasarDeAaP (int validos,int arreglo[validos],Pila *A){
int i=0;
int x=0;

while(i<validos){
    if(arreglo[i]>96 && arreglo[i]<123){
        apilar(A,arreglo[i]);
        i++;
        x++;
    }
    else
        i++;
}

if(x%2==0){
    return 1;
}
else{
    return 0;
}

}


Pila cargarP(Pila A){
int control=1;
while (control==1){

    leer(&A);
    printf("desea seguir ingresando?(1/0)");
    fflush(stdin);
    scanf("%d",&control);

}
return A;
}

void cargarM(int dimF,int dimC,int M[dimF][dimC]){
int f;
int c;
for(f=0;f<dimF;f++){
    for(c=0;c<dimC;c++){
        printf("ingrese un num:");
        fflush(stdin);
        scanf("%d",&M[f][c]);
    }
}
}

int compararMyP(int dimF,int dimC,int M[dimF][dimC],Pila A){
int i;
int f;
int c;
Pila AUX;
inicpila(&AUX);
while(!pilavacia(&A)){
for(f=0;f<dimF;f++){
    for(c=0;c<dimC;c++){
        if (M[f][c]==tope(&A)){
            i++;
        }
apilar(&AUX,desapilar(&A));
}
}
}
return i;
}
