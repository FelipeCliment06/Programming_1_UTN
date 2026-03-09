#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "string.h"
#include "pila.h"
const int dimC=100;
const int dimF=50;
///prototipado///
///1
void cargarPilaPyPilaI(Pila *A,Pila *B);
///2
int buscarDato(Pila *B,int dato);
///3
int pasar2PilasAArray(Pila *A,Pila *B,int arreglo[]);
void mostrarArray(int validos,int arreglo[]);
///4
int cargarArreglo(int arreglo[]);
int sumatoria(int validos,int arreglo[]);
float promedioArray(int validos,int arreglo[]);
///5
int cargarUnString(int dimF,int dimC,char string[dimF][dimC]);
void mostrarString(int validos,int dimC,char string[validos][dimC]);
///6
int buscarPalabra(int pos,int validos,int dimC,char string[validos][dimC]);






int main()
{
    int x,dato,flag,validos,pos, palabra;
    float prom;
    Pila A;
    Pila B;
    inicpila(&A);
    inicpila(&B);
    int arreglo[dimC];
    char string[dimF][dimC];


    do{
        printf("\nMENU\nEJERCICIO 1\nEJERCICIO 2\nEJERCICIO 3\nEJERCICIO 4\nEJERCICIO 5\nEJERCICIO 6\nEJERCICIO 7\nEJERCICIO 8\n");
        scanf("%d",&x);
        switch(x){


case 1:
    cargarPilaPyPilaI(&A,&B);
    mostrar(&A);
    mostrar(&B);

    break;

case 2:
    cargarPilaPyPilaI(&A,&B);
    mostrar(&B);
    printf("ingrese el numero que desea buscar:");
    fflush(stdin);
    scanf("%d",&dato);
    flag=buscarDato(&B,dato);
    if(flag==1){
        printf("el dato buscado esta en la pila\n");
    }
    else if (flag ==0){
        printf("el dato buscado no esta en la pila\n");
    }
    break;

case 3:
    cargarPilaPyPilaI(&A,&B);
    mostrar(&A);
    mostrar(&B);
    validos=pasar2PilasAArray(&A,&B,arreglo);
    mostrarArray(validos,arreglo);


    break;

case 4:

    validos = cargarArreglo(arreglo);
    mostrarArray(validos,arreglo);
    prom=promedioArray(validos,arreglo);
    printf("\n el promedio del arreglo es:%.2f",prom);


    break;

case 5:
    validos=cargarUnString(dimF,dimC,string);
    mostrarString(validos,dimC,string);

    break;

case 6:
    validos=cargarUnString(dimF,dimC,string);
    printf("ingrese que pos desea buscar, entre 0 y %d",validos-1);
    scanf("%d",&pos);
    palabra = buscarPalabra(pos,validos,dimC,string);
    printf("la palabra tiene %d letras",palabra);

    break;





    return 0;
}}
    while(x!=0);

}




void cargarPilaPyPilaI(Pila *A,Pila *B){
srand(time(NULL));
int i;
int dato;
for(i=0;i<30;i++){
dato = rand()%101;
if((dato)%2==0){
    apilar(A,dato);
}
else
    apilar(B,dato);
}
}

int buscarDato(Pila *B,int dato){
Pila aux;
inicpila(&aux);
int flag;
while(!pilavacia(B)&& flag==0){
    if (dato == tope(B)){
        flag = 1;
    }
    apilar(&aux,desapilar(B));
}
return flag;
}



int pasar2PilasAArray(Pila *A,Pila *B,int arreglo[]){
Pila aux;
Pila aux2;
inicpila(&aux2);
inicpila(&aux);
int i;
while(i<70 &&!pilavacia(A)){
        if(tope(A)>5){
            arreglo[i]=tope(A);
            i++;
        }
        apilar(&aux,desapilar(A));

    }
while(i<70&&!pilavacia(B)){
        if(tope(B)>5){
            arreglo[i]=tope(B);
            i++;
        }
        apilar(&aux2,desapilar(B));

    }

return i;
}


void mostrarArray(int validos,int arreglo[]){
int i;

for(i=0;i<validos;i++){
    printf("%d|",arreglo[i]);
}
}

int cargarArreglo(int arreglo[]){
int i=0;
int control=1;
 while(control==1){

    printf("cargue un dato:");
    fflush(stdin);
    scanf("%d",&arreglo[i]);
    i++;

    printf("si quiere ingresar otro(1/0)");
    fflush(stdin);
    scanf("%d",&control);
}

return i;
}

int sumatoria(int validos,int arreglo[]){
int i;
int suma=0;
for(i=validos-1;i--;){
        suma+=arreglo[i];

}
return suma;
}

float promedioArray(int validos,int arreglo[]){
int suma;
suma=sumatoria(validos,arreglo);
float prom;
prom=(float)suma/(float)validos;

return prom;
}

int cargarUnString(int dimF,int dimC,char string[dimF][dimC]){
int i;
int control=1;
while(i<dimF && control==1){
    printf("ingrese una palabra:");
    fflush(stdin);
    gets(string[i]);

    printf("desea seguir ingresando(1/0)");
    fflush(stdin);
    scanf("%d",&control);

i++;
}
return i;
}
void mostrarString(int validos,int dimC,char string[validos][dimC]){
int i;
for(i=0;i<validos;i++){
    printf("palabra %d:",i+1);
    puts(string[i]);
}
}

int buscarPalabra(int pos,int validos,int dimC,char string[validos][dimC]){
int cant;

cant=strlen(string[pos]);
printf("la palabra es:");
puts(string[pos]);


return cant;
}

