#include <stdio.h>
#include <stdlib.h>

int main()
{
    ///uso del switch


    int operador;
    printf("ingrese su eleccion, del 1 al 4\n");
    scanf("%d",&operador);


    switch(operador){

    case 1:
        printf("el operador es uno\n");
        break;


    case 2:
        printf("el operador es dos\n");
        printf("el operador ya te dijo q es 2\n");
        break;

    case 3:
        printf("el operador es tres\n");
        break;


    case 4:
        printf("el operador es 4\n");
        break;

    default:
        printf("la opcion es incorrecta\n");

    }

    printf("salio del switch");
















    return 0;
}
