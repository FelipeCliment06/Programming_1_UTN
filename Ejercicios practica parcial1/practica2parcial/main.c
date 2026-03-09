#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "string.h"
#include "pila.h"

const int dimF=100;
const int dimC=100;
///1
int apilarIyPenPilas(Pila *A,Pila *B);
///2
int buscarDatoEnP(Pila *B,int dato);
///3
int PasarPaUnArreglo(Pila *A,Pila *B,int dimC,int arreglo[dimC]);
void mostrarArreglo(int validos,int arreglo[validos]);
///4
float promedioArreglo(int validos,int arreglo[validos]);
int sumatoria(int validos,int arreglo[validos]);
///5
int cargarString(int dimF,int dimC,char string[dimF][dimC]);
void mostrarString(int validos,int dimF,int dimC,char string[dimF][dimC]);
///6
int buscarPalabra(int validos,int dimC,char string[validos][dimC],int dato);



int main()
{
    int x,validos,dato,flag,prom,len;
    Pila A;
    Pila B;
    inicpila(&A);
    inicpila(&B);
    int arreglo[dimC];
    char string[dimF][dimC];

    do{
        printf("\nEJERCICIOS\nEJERCICIO 1\nEJERCICIO 2\nEJERCICIO 3\nEJERCICIO 4\nEJERCICIO 5\nEJERCICIO 6\n");
        scanf("%d",&x);
        switch(x){

    case 1:
            apilarIyPenPilas(&A,&B);
            mostrar(&A);
            mostrar(&B);
        break;
    case 2:
        apilarIyPenPilas(&A,&B);
        mostrar(&B);
        printf("ingrese el dato buscado:");
        fflush(stdin);
        scanf("%d",&dato);
        flag=buscarDatoEnP(&B,dato);
        if (flag==1){
            printf("el dato fue encontrado");
        }
        else{
            printf("el dato no fue encontrado");
        }
        break;
    case 3:
        apilarIyPenPilas(&A,&B);
        validos=PasarPaUnArreglo(&A,&B,dimC,arreglo);
        mostrarArreglo(validos,arreglo);

        break;

    case 4:
        apilarIyPenPilas(&A,&B);
        validos=PasarPaUnArreglo(&A,&B,dimC,arreglo);
        mostrarArreglo(validos,arreglo);
        prom=promedioArreglo(validos,arreglo);
        printf("\nel promedio es %d.2",prom);


        break;
    case 5:
        validos=cargarString(dimF,dimC,string);
        mostrarString(validos,dimF,dimC,string);

        break;
    case 6:
         validos=cargarString(dimF,dimC,string);
        mostrarString(validos,dimF,dimC,string);
        printf("ingrese la pos que desea ver del 0 al %d:",validos-1);
        fflush(stdin);
        scanf("%d",&dato);
        len=buscarPalabra(validos,dimC,string,dato);
        printf("la longitud de la palabra es de %d letras",len);



        break;



    return 0;
}}
    while(x!=0);
}


///1
int apilarIyPenPilas(Pila *A,Pila*B){
srand(time(NULL));
int i;
int dato;
while(i<30){
dato=rand()%101;
    if(dato%2==0){
        apilar(A,dato);
    }
    else{
        apilar(B,dato);
    }
    i++;
}
return i;
}

///2
int buscarDatoEnP(Pila *B,int dato){
int flag;
Pila aux;
inicpila(&aux);
while(!pilavacia(B)&& flag==0){
        if (dato==tope(B)){
            flag=1;
        }
else{
    apilar(&aux,desapilar(B));
}
}
return flag;
}

///3
int PasarPaUnArreglo(Pila *A, Pila *B,int dimC,int arreglo[dimC]){
int i;
Pila aux;
inicpila(&aux);
while(i<dimC &&!pilavacia(A)){
        if(tope(A)>5){
        arreglo[i]=tope(A);
        i++;
        }

    apilar(&aux,desapilar(A));

}
while(i<dimC&&!pilavacia(B)){
        if(tope(B)>5){
        arreglo[i]=tope(B);
        i++;
        }

    apilar(&aux,desapilar(B));

}
return i;
}



void mostrarArreglo(int validos,int arreglo[validos]){
int i;
while(i<validos){
    printf("%d|",arreglo[i]);
    i++;
}
}

///4
float promedioArreglo(int validos,int arreglo[validos]){
int prom;
int suma=sumatoria(validos,arreglo);
prom=(float)suma/(float)validos;


return prom;
}

int sumatoria(int validos,int arreglo[validos]){
int i;
int suma=0;
for(i=validos-1;i--;){
    suma+=arreglo[i];
}
return suma;
}


int cargarString(int dimF,int dimC,char string[dimF][dimC]){
int i;
int control=1;
while(control==1 && i<dimF){
   printf("ingrese una palabra:");
   fflush(stdin);
   gets(string[i]);

   printf("desea seguir cargando(1/0)");
   fflush(stdin);
   scanf("%d",&control);
i++;
}
return i;
}

void mostrarString(int validos,int dimF,int dimC,char string[dimF][dimC]){
int i=0;
while(i<validos){
    printf("palabra %d:",i+1);
    puts(string[i]);
    i++;
}
}

int buscarPalabra(int validos,int dimC,char string[validos][dimC],int dato){
int i;
i=(strlen(string[dato]));
return i;
}
