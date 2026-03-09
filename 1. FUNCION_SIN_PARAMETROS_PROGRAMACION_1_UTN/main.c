#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int sumar();

int main()
{
int suma =sumar();
printf("El resultado es %d",suma);

    return 0;
}

int sumar()///funcion sin parametro.
{
int num1, num2, suma;

printf("Ingrese un Nro 1:\n");
fflush(stdin);
scanf("%d", &num1);
printf("Ingrese un Nro 2:\n");
fflush(stdin);
scanf("%d", &num2);
suma= num1+num2;
return suma;
}



