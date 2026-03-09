#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pila.h"

///prototipado
///1
int cargarPilayArreglo(Pila *A,int dimC,int arreglo[dimC]);
///2
void capicua(int validos,int arreglo[validos]);
int cargarArreglo(int dimC,int arreglo[dimC]);
///3
Pila cargarPila(Pila B);
int copiarPenA(Pila B,int dimC,int arreglo[dimC]);
///4
void cargamatriz(int dimF,int dimC,int M[dimF][dimC]);
int sumadeParesMatriz(int dimF,int dimC,int M[dimF][dimC]);
///5
int cargarString(int dimF,int dimC,char string[dimF][dimC]);
void mostrarString(int validos,int dimC,char string[validos][dimC]);
int encontrarPalabra(int validos,int dimC,char string[validos][dimC],char palabra);






int main()
{
int x,validos;
int i=0;
int dimC=100;
int dimF=100;
int arreglo[dimC];
Pila A;
Pila B;
inicpila(&A);
inicpila(&B);
int M[dimF][dimC];
char string[dimF][dimC];
char palabra;
do{
    printf("\nEJERCICIOS\nPOINT 1\nPOINT 2\nPOINT 3\nPOINT 4\nPOINT 5\nPOINT 6\n");
    scanf("%d",&x);
    switch(x){

case 1:
    validos=cargarPilayArreglo(&A,dimC,arreglo);
    printf("%d",validos);
    mostrar(&A);
    break;

case 2:
    validos= cargarArreglo(dimC,arreglo);
    capicua(validos,arreglo);
    break;

case 3:

    B = cargarPila(B);
    i= copiarPenA(B,dimC,arreglo);

    if(i==1)
    printf("habia mas de 10 elementos");

    else
    printf("habia menos de 10 elementos");

    break;

case 4:
    printf("ingrese el num de filas:");
    fflush(stdin);
    scanf("%d",&dimF);
    printf("ingrese el num de columnas:");
    fflush(stdin);
    scanf("%d",&dimC);
    cargamatriz(dimF,dimC,M);
    i=sumadeParesMatriz(dimF,dimC,M);
    printf("la suma es: %d",i);




    break;

case 5:

    validos=cargarString(dimF,dimC,string);
    mostrarString(validos,dimC,string);
    printf("ingrese una palabra:");
    fflush(stdin);
    scanf("%c",&palabra);
    i=encontrarPalabra(validos,dimC,string,palabra);
    printf("la palabra esta %d veces",i);


    break;

}return 0;
}while(x!=0);
}


int cargarPilayArreglo(Pila *A,int dimC,int arreglo[dimC]){
int i=0;
int x=0;
int num;
int control=1;
while(i<dimC&& x<dimC && control==1){
    printf("ingrese un num:");
    fflush(stdin);
    scanf("%d",&num);
    if (num %2==0){
        apilar(A,num);
    }
    else{
        arreglo[i]=num;
        x++;
    }

    printf("desea seguir ingresando?(1/0)");
    fflush(stdin);
    scanf("%d",&control);
}
return x;
}


int cargarArreglo(int dimC,int arreglo[dimC]){
int i=0;
int num;
int control=1;
while(i<dimC&&control==1){
    printf("ingrese un num:");
    fflush(stdin);
    scanf("%d",&num);
    arreglo[i]=num;

    printf("desea seguir ingresando?(1/0)");
    fflush(stdin);
    scanf("%d",&control);

    i++;
}
return i;
}



void capicua(int validos,int arreglo[validos]){
int i;
Pila A;
Pila B;
Pila C;
Pila D;
inicpila(&A);
inicpila(&B);
inicpila(&C);
inicpila(&D);

for(i=0;i<validos;i++){
    apilar(&A,arreglo[i]);
}
while(!pilavacia(&A)){
    apilar(&B,desapilar(&A));
    apilar(&C,desapilar(&A));
}
while(!pilavacia(&C)){
    apilar(&A,desapilar(&C));
}

while(!pilavacia(&B) && tope(&A)==tope(&B)){
    apilar(&C,desapilar(&B));
    apilar(&D,desapilar(&A));
}
if (pilavacia(&A))
    printf("la pila es capicua");

else
    printf("la pila no es capicua");

}


Pila cargarPila(Pila B){
int control = 1;
while (control==1){

    leer(&B);

    printf("desea seguir ingresando?(1/0)");
    fflush(stdin);
    scanf("%d",&control);
    }
    return B;
}

int copiarPenA(Pila B,int dimC,int arreglo[dimC]){
int i=0;
Pila aux;
inicpila(&aux);

while(!pilavacia(&B)&& i<10){

    arreglo[i]=tope(&B);
    apilar(&aux,desapilar(&B));
    i++;
}


if (!pilavacia(&B)){
    return 1 ;
    }
else{
    return 0 ;
    }
}




///4
void cargamatriz (int dimF,int dimC,int M[dimF][dimC]){
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
int sumadeParesMatriz(int dimF,int dimC,int M[dimF][dimC]){
int f;
int c;
int suma=0;
for(f=0;f<dimF;f++){
    for(c=0;c<dimC;c++){

    if(M[f][c]%2==0){
    suma+= M[f][c];
    }
    }
}
return suma;
}



int cargarString(int dimF,int dimC,char string[dimF][dimC]){
int i=0;
int control=1;
while(i<dimF && control==1){

    printf("ingrese una palabra:");
    fflush(stdin);
    gets(string[i]);

    printf("desea seguir ingresando?(1/0)");
    fflush(stdin);
    scanf("%d",&control);
    i++;

}
return i;
}


void mostrarString(int validos,int dimC,char string[validos][dimC]){
int i=0;
while(i<validos){
    printf("palabra %d",i+1);
        puts(string[i]);
        i++;
}
}
int encontrarPalabra(int validos,int dimC,char string[validos][dimC],char palabra){
int i=-1;
int x;
while(i<validos){

    if(palabra == string[i][dimC]){
        x++;
        i++;

    }
    else
        i++;
}
return x;
}

