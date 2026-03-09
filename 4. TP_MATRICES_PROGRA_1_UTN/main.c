#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

///1
void CargarMatrizEnteros(int DimF,int DimC,int M[DimF][DimC]);
///2
void MostrarMatrizEnteros(int DimF,int DimC,int M[DimF][DimC]);
///3
void CargarMatrizRandom(int DimF,int DimC, int M[DimF][DimC]);
///4
int SumaMatrizEnteros(int DimF,int DimC,int M[DimF][DimC]);
///5
float PromedioMatrizEnteros(int DimF,int DimC,int M[DimF][DimC]);
///6
int BuacarDatoEnMatrizEnteros(int DimF,int DimC,int M[DimF][DimC],int dato);
///7
void CargarPalabraString(char S[30]);

int main()
{
int DimF,DimC,suma,dato,flag;
float promedio;
    printf("ingrese el numero de Filas:");
    scanf("%d",&DimF);
    printf("ingrese el numero de Columnas:");
    scanf("%d",&DimC);

int M[DimF][DimC];
char S[30];




    int x;
do{
    printf("\n\n/////////////////////////////////////////////////////////////////////////\n\n");
    printf("\nEJERCICIOS\nEJERCICIO 1\nEJERCICIO 2\nEJERCICIO 3\nEJERCICIO 4\nEJERCICIO 5\nEJERCICIO 6\nEJERCICIO 7\nEJERCICIO\n");
    scanf("%d",&x);
    switch(x){

    case 1:
        ///Hacer una función que reciba como parámetro una matriz de números enteros y permita que el usuario ingrese
        ///valores al mismo por teclado. La función debe cargar la matriz por completo.

    CargarMatrizEnteros(DimF,DimC,M);
    break;

    case 2:
        ///Hacer una función que reciba como parámetro una matriz de números enteros y la muestre por pantalla (en formato matricial).

    CargarMatrizEnteros(DimF,DimC,M);
    MostrarMatrizEnteros(DimF,DimC,M);
    break;

    case 3:
        ///Hacer una función que reciba como parámetro una matriz de números enteros y que cargue la misma con números aleatorios
        ///(sin intervención del usuario). La función debe cargar la matriz por completo.

        CargarMatrizRandom(DimF,DimC,M);
        MostrarMatrizEnteros(DimF,DimC,M);
        break;

    case 4:
        ///Hacer una función tipo int que sume el contenido total de una matriz de números enteros.
        CargarMatrizEnteros(DimF,DimC,M);
        printf("la Matiz:\n");
        MostrarMatrizEnteros(DimF,DimF,M);
        suma= SumaMatrizEnteros(DimF,DimC,M);
        printf("la suma es:%d",suma);

        break;

    case 5:
        ///Hacer una función tipo float que calcule el promedio de una matriz de números enteros.
        CargarMatrizEnteros(DimF,DimC,M);
        printf("la matriz:");
        MostrarMatrizEnteros(DimF,DimC,M);
        promedio=PromedioMatrizEnteros(DimF,DimC,M);
        printf("El promedio es:%.2f",promedio);

        break;

    case 6:
        ///Hacer una función que determine si un elemento se encuentra dentro de una matriz de números enteros.
        ///La función recibe la matriz y el dato a buscar.
        printf("ingrese el dato que desea buscar:");
        fflush(stdin);
        scanf("%d",&dato);
        CargarMatrizEnteros(DimF,DimC,M);
        flag =BuacarDatoEnMatrizEnteros(DimF,DimC,M,dato);
        if (flag==0){
            printf("el dato no esta en la matriz");}
        else{
            printf("el dato buscado si esta en la matriz");
        }

        break;

    case 7:
        ///Hacer una función que cargue un arreglo de palabras (strings). La función debe retornar cuantas palabras se cargaron.
        ///(puede ser a través del parámetro como puntero)
    CargarPalabraString(S);


        break;

    return 0;
        }
}while(x!=0);
}

///1///////////////////////////////////////////////////////////////////////////////////////////////////////////
void CargarMatrizEnteros(int DimF,int DimC,int M[DimF][DimC]){
int f,c;

for(f=0;f<DimF;f++){
    for(c=0;c<DimC;c++){
        printf("ingrese un num:");
        fflush(stdin);
        scanf("%d",&M[f][c]);
    }
}
}
///2/////////////////////////////////////////////////////////////////
void MostrarMatrizEnteros(int DimF,int DimC,int M[DimF][DimC]){
int f,c;

for(f=0;f<DimF;f++){
    for(c=0;c<DimC;c++){
        printf("%d|",M[f][c]);
    }
    printf("\n");
}
}
///3////////////////////////////////////////////////////////////////////////////
void CargarMatrizRandom(int DimF,int DimC,int M[DimF][DimC]){
    srand(time(NULL));
    int f;
    int c;

for(f=0;f<DimF;f++){
    for(c=0;c<DimC;c++){
        M[f][c]= rand()%100;
    }
}
}

///4////////////////////////////////////////////////////////////////////////////////
int SumaMatrizEnteros(int DimF,int DimC,int M[DimF][DimC]){
int f;
int c;
int suma;
for(f=0;f<DimF;f++){
    for(c=0;c<DimC;c++){
        suma = suma + M[f][c];
    }
}
return suma;
}

///5////////////////////////////////////////////////////////////////////////////////////
float PromedioMatrizEnteros(int DimF,int DimC,int M[DimF][DimC]){
int cant= DimF*DimC;
int suma= SumaMatrizEnteros(DimF,DimC,M);
float prom=(float)suma/(float)cant;

return prom;
}

///6///////////////////////////////////////////////////////////////////////////////////////
int BuacarDatoEnMatrizEnteros(int DimF,int DimC,int M[DimF][DimC],int dato){
int f,c;
int flag;

for(f=0;f<DimF && flag==0;f++){
    for(c=0;c<DimC && flag==0;c++ ){
        if (M[f][c]==dato){
            flag=1;
        }
    }
}
return flag;
}
///7/////////////////////////////////////////////////////////////////////////////////////////////
void CargarPalabraString(char S[30]){
char control='z';
while(control=='z'){
gets(S);
printf("ingrese una palabra y si no quiere ingresar mas aprete z:\n");
fflush(stdin);
scanf("%c",control);
}
}






