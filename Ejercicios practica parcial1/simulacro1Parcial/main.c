#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "pila.h"
///prototipado///
//1
void CargarPila( Pila *A);
///2
int PasarPilaImparesAArray(Pila A,int arreglo[]);
void mostrarArray(int arreglo[],int validos);
///3
int CargarArrayEntero(int dimC,int arreglo[]);
int EncontrarMenor (int validos,int dimC,int arreglo[]);
///4
int CargarMatrizEnteros(int dimF,int dimC,int M[dimF][dimC]);
void mostrarMatrizEntero(int dimF,int dimC,int M[dimF][dimC]);
///5
void mostrarPosDeterminado(int dimC,int arreglo[]);
int PedirPos(int dimC,int arreglo[]);
///6
void MostrarPilaSinFunc(Pila *A);
///7
float promedioDeMatrizE(int dimF,int dimC,int M[dimF][dimC]);
int sumatoriaMatrizEntero(int dimF,int dimC,int M[dimF][dimC]);
///8
int cargarMarizChar(int dimF,int dimC,char MatrizC[dimF][dimC]);
void mostraMC(int dimF,int dimC,char MatrizC[dimF][dimC]);

int main()
{
Pila A;
inicpila(&A);
int x,dimC,menor,dimF;
float prom;
int arreglo[20];
int validos;
int M[dimF][dimC];
char MatrizC[dimF][dimC];



    do{
        printf("\n\nMENU\nIngrese un ejercicio o 0 para salir\nEJERCICIO 1\nEJERCICIO 2\nEJERCICIO 3\nEJERCICIO 4\nEJERCICIO 5\nEJERCICIO 6\nEJERCICIO 7\nEJERCICIO 8\nEJERCICIO 9\nEJERCICIO 10\n");
    scanf("%d",&x);
    switch(x){


case 1:
    CargarPila(&A);
    mostrar(&A);
    break;

case 2:
    CargarPila(&A);
    mostrar(&A);
    validos= PasarPilaImparesAArray(A,arreglo);
    mostrarArray(arreglo,validos);

    break;

case 3:
    printf("ingrese cant max de columnas:");
    scanf("%d",&dimC);
    validos=CargarArrayEntero(dimC,arreglo);
    mostrarArray(arreglo,validos);
    menor = EncontrarMenor(validos,dimC,arreglo);
    printf("\nel menor es :%d",menor);
    break;

case 4:
    printf("ingrese cant max de filas:");
    scanf("%d",&dimF);
    printf("ingrese cant max de columnas:");
    scanf("%d",&dimC);
    CargarMatrizEnteros(dimF,dimC,M);
    mostrarMatrizEntero(dimF,dimC,M);
    break;

case 5:
    printf("ingrese cant max de columnas:");
    scanf("%d",&dimC);
    validos=CargarArrayEntero(dimC,arreglo);
    mostrarArray(arreglo,validos);
    mostrarPosDeterminado(dimC,arreglo);

    break;

case 6:
    CargarPila(&A);
    MostrarPilaSinFunc(&A);

    break;

case 7:
    printf("ingrese cant max de filas:");
    scanf("%d",&dimF);
    printf("ingrese cant max de columnas:");
    scanf("%d",&dimC);
    CargarMatrizEnteros(dimF,dimC,M);
    mostrarMatrizEntero(dimF,dimC,M);
    prom=promedioDeMatrizE(dimF,dimF,M);
    printf("el promedio de la matriz es %.2f",prom);

    break;

case 8:
    printf("ingrese cant max de filas:");
    scanf("%d",&dimF);
    printf("ingrese cant max de columnas:");
    scanf("%d",&dimC);
    validos=cargarMarizChar(dimF,dimC,MatrizC);
    mostraMC(dimF,dimC,MatrizC);


    break;

case 9:


    break;

case 10:

    break;

  return 0;
    }
}while(x!=0);
}
//1
void CargarPila(Pila *A){

int i=1;
while(i==1){

    leer(A);
    printf("si desea cargar otro aprete 1");
    fflush(stdin);
    scanf("%d",&i);
}
}
//2
int PasarPilaImparesAArray(Pila A,int arreglo[]){
int validos=0;
int i;
Pila aux;
inicpila(&aux);
while((i<20)&&(!pilavacia(&A))){
    if(tope(&A)%2!=0){
    arreglo[i]= tope(&A);
    apilar(&aux,desapilar(&A));
    i++;
    validos++;
    }
    else
        apilar(&aux,desapilar(&A));
}
return validos;
}

void mostrarArray(int arreglo[],int validos){

for(int i=0;i<validos;i++){

    printf("|%d|",arreglo[i]);
}
}

///3
int CargarArrayEntero(int dimC,int arreglo[]){
int i;

for(i=0;i<dimC;i++){
    printf("ingrese un valor");
    scanf("%d",&arreglo[i]);
}
return i;
}

int EncontrarMenor(int validos,int dimC,int arreglo[]){
int i=0;
int pos=i;
int menor=arreglo[pos];

for(i=1;i<validos;i++){
   if( arreglo[i]<= menor){
    menor=arreglo[i];
   }

}
return menor;
}

int CargarMatrizEnteros(int dimF,int dimC,int M[dimF][dimC]){
int f,c;
for(f=0;f<dimF;f++){
    for(c=0;c<dimC;c++){
        printf("ingrese un dato:");
        scanf("%d",&M[f][c]);
    }
}
return f+c;
}

void mostrarMatrizEntero(int dimF,int dimC,int M[dimF][dimC]){
int f,c;
for(f=0;f<dimF;f++){
    for(c=0;c<dimC;c++){
        printf("%d|", M[f][c]);
    }
    printf("\n");
}
}


void mostrarPosDeterminado(int dimC,int arreglo[]){
int pos;
pos= PedirPos(dimC,arreglo);
printf("el valor en la poscicion %d es %d",pos,arreglo[pos-1]);
}

int PedirPos(int dimC,int arreglo[]){
int pos;

printf("\ningrese la pos que desea ver entre 1 y %d: ",dimC);
fflush(stdin);
scanf("%d",&pos);
while(pos<1||pos>dimC){
    printf("la pos que usted ingreso no es valida, debe ingresar un num del 1 hasta %d",dimC);
    scanf("%d",&pos);
}

return pos;
}


void MostrarPilaSinFunc(Pila *A){
int aux;
Pila B;
inicpila(&B);
while(!pilavacia(A)){
   apilar(&B,desapilar(A));
}
printf("BASE----------------------------------------------------------TOPE\n\n");
while(!pilavacia(&B)){
aux=tope(&B);
printf("%d|",aux);
apilar(A,desapilar(&B));
}
printf("\n\nBASE----------------------------------------------------------TOPE");
}

float promedioDeMatrizE(int dimF,int dimC,int M[dimF][dimC]){
int suma,cant;
float prom;
suma=sumatoriaMatrizEntero(dimF,dimC,M);
cant=dimF*dimC;
prom=(float)suma/(float)cant;

return prom;
}


int sumatoriaMatrizEntero(int dimF,int dimC,int M[dimF][dimC]){
int f,c;
int suma=0;
for(f=0;f<dimF;f++){
    for(c=0;c<dimC;c++){
    suma+=M[f][c];
    }
   }
return suma;
}


int cargarMarizChar(int dimF,int dimC,char MatrizC [dimF][dimC]){
int f;
for(f=0;f<dimF;f++){
    printf("ingrese una palabra:");
    gets(MatrizC[f]);

}
return f;
}

void mostraMC(int dimF ,int dimC,char Matriz[dimF][dimC]){
int f;
for(f=0;f<dimF;f++){
   puts(Matriz[f]);
   printf("\n");
}
}








