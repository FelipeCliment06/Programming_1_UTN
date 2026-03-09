#include <stdio.h>
#include <stdlib.h>

void ejercicio1();
void ejercicio2();
void ejercicio3();

int main()
{
    printf("Ej: 1\n");
        ejercicio1();
    printf("\n\nEj: 2\n");
        ejercicio2();
    printf("Ej: 3\n");
        ejercicio3();
    return 0;
}

void ejercicio1()

{

   //Una persona va a invertir su capital en un banco y desea saber cuánto
   //dinero ganará después de un mes si el banco paga el 2% mensual.

   float tna = 0.02;
   float capitalInicial;
   float gananciaNeta;
   float totalACobrar;

   printf("ingrese el monto que desea invertir\n$:");
   fflush(stdin);
   scanf("%f",&capitalInicial);

   gananciaNeta = capitalInicial * tna;
   totalACobrar = gananciaNeta + capitalInicial;

   printf("\n su ganancia neta va a ser de: $%.2f y el total a cobrar es de: $ %.2f",gananciaNeta,totalACobrar);
}

void ejercicio2()
{


    ///Una tienda ofrece un descuento del 15% sobre el total de la compra y
    ///un cliente desea saber cuánto deberá pagar finalmente por su compra.
    fflush(stdin);
    float porcentajeDescuento = 0.15;
    float descuento;
    float subtotal;
    float totalAPagar;

    printf("ingrese el monto de su compra \n");

    fflush(stdin);
    scanf("%f", &subtotal);

    descuento = subtotal * porcentajeDescuento;
    totalAPagar = subtotal - descuento;

    printf("\n Subtotal------------ $ %.2f", subtotal);
    printf("\nDescuento------------ $ %.2f", descuento);
    printf("\nTotal a pagar-------- $ %.2f\n\n\n", totalAPagar);

}

 void ejercicio3()
{

/// Un maestro desea saber qué porcentaje de hombres y de mujeres hay en un grupo de estudiantes.

int hombres;
int mujeres;
float porcentajeDeHombres;
float porcentjeDeMujeres;
int totalDeAlumnos;

printf("ingrese cantidad de alumnos hombres: \n");

fflush(stdin);
scanf("%i", &hombres);

printf("ingrese cantidad de alumnos mujeres: \n");

fflush(stdin);
scanf("%i", &mujeres);

totalDeAlumnos = hombres + mujeres;
porcentajeDeHombres = (float) hombres *100/ totalDeAlumnos;
porcentjeDeMujeres = (float)mujeres *100/ totalDeAlumnos;

printf("hombres: %% %.1f\n", porcentajeDeHombres);
printf("mujeres: %% %.1f\n\n", porcentjeDeMujeres);
printf("total de alumnos: %i\n\n",totalDeAlumnos);

}











