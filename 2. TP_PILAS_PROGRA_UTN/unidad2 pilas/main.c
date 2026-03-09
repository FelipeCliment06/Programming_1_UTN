#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    /*  (EXPLICACION)
    Pila A;
   iniciapila (&A);
   apilar(&A,8);///donde guardo y que guardo(atraves del programador)
   apilar(&A,);
   leer(&A);///guardar atraves del cliente, preguntando al usuario)(hace el printf y el scanf)

   ///desapilar
  int topA= desapilar(&A);///lo q desapile se guarda en la variable "topA"

   ///cabiar de pila
   apilar(&B, topA);    ///para pasar a la pila B antes hay q crearla

   apilar(&B,desapilar(&A));

   ///tope(devuelve el valor del mas arriba de la pila pero no lo quita de la pila)

   int topeB=tobe(&B)




    Pila A;
    inicpila(&A);

    apilar(&A, 3);

    for(int i=0; i<3; i++){
        leer(&A);

    }

   char control='s';

   while(control=='s'){
        leer(&A);


    printf("quiere seguir cargando? presione 's' si quiere seguir cargando");

    fflush(stdin);
    scanf("%c",&control);
   }


    Pila B;
    inicpila(&B);
    while(!pilavacia(&A)){
        apilar(&B,desapilar(&A));

    }

    printf("pila A");
    mostrar(&A);
    printf("pila B");
    mostrar(&B);



 1.- Cargar desde el teclado una pila llamada DADA con 5 elementos.
 Pasar los tres primeros elementos que se encuentren en el tope a la
 pila AUX1 y los restantes a la pila AUX2, ambas pilas inicializadas.

    Pila DADA;

    inicpila (&DADA);
    for(int i=0; i<5;i++){
       leer(&DADA);
    }

    Pila AUXI;
    inicpila(&AUXI);
    for( int i=0; i<3;i++){
    apilar(&AUXI,desapilar(&DADA));
    }

    Pila AUX2;
    inicpila(&AUX2);
    while(!pilavacia(&DADA)){

    apilar(&AUX2,desapilar(&DADA));
    }
    printf("pila DADA");
    mostrar(&DADA);
    printf("pila AUXI");
    mostrar(&AUXI);
    printf("pila AUX2");
    mostrar(&AUX2);




2.- Cargar desde el teclado una pila llamada ORIGEN e inicializar en vacío la pila DESTINO.
Pasar todos los elementos de la pila ORIGEN a la pila DESTINO.

    Pila ORIGEN;
    inicpila(&ORIGEN);



    char control='s';

    while(control=='s'){
        leer(&ORIGEN);
        printf("quiere seguir cargando? presione 's' si quiere seguir cargando");
        fflush(stdin);
        scanf("%c",&control);
    }

    Pila DESTINO;
    inicpila(&DESTINO);


    while(!pilavacia(&ORIGEN)){
        apilar(&DESTINO ,desapilar(&ORIGEN));

    }
    printf("PILA ORIGEN");
    mostrar(&ORIGEN);
    printf("PILA DESTINO");
    mostrar(&DESTINO);




3.Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS
todos aquellos elementos distintos al valor 8.

    Pila DADA;
    Pila DISTINTOS;
    Pila AUX;

  char control='A';
inicpila(&DADA);
  while(control=='A'){

    leer(&DADA);
    printf("cargue otro y si desea cargar otro aprete 'a'");
    fflush(stdin);
    scanf("%c",&control);

  }
    inicpila(&DISTINTOS);
    inicpila(&AUX);
  while(!pilavacia(&DADA)){
    if(tope(&DADA)!=8){
     apilar(&DISTINTOS,desapilar(&DADA));
    }
    else{
        apilar(&AUX, desapilar(&DADA));
    }


  }
    while(!pilavacia(&AUX))  {
        apilar(&DADA,desapilar(&AUX));

    }




  printf("DADA");
  mostrar(&DADA);
  printf("DISTINTOS");
  mostrar(&DISTINTOS);



 4.Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO.
 Pasar los elementos de la pila ORIGEN a la pila DESTINO, pero dejándolos en el mismo orden.

 Pila ORIGEN;
 Pila DESTINO;
 Pila AUX;
 inicpila(&ORIGEN);
 inicpila(&DESTINO);
 inicpila(&AUX);
 char control = 'A';

while(control=='A'){

    leer(&ORIGEN);
    printf("cargue otro y si desea cargar otro aprete 'A'");
    fflush(stdin);
    scanf("%c",&control);
}

while(!pilavacia(&ORIGEN))  {
        apilar(&AUX,desapilar(&ORIGEN));

    }

while(!pilavacia(&AUX))  {
        apilar(&DESTINO,desapilar(&AUX));

    }


printf("origen");
mostrar(&ORIGEN);
printf("destino");
mostrar(&DESTINO);



5.cargar desde el teclado la pila DADA. invertir la pila de manera que dada contenga los elementos cargados
originalmente en ella, pero en orten inverso

    Pila DADA;
    Pila AUX1;
    Pila AUX2;
    inicpila(&DADA);
    inicpila(&AUX1);
    inicpila(&AUX2);
    char control = 'A';

    while(control=='A'){

        leer(&DADA);
        printf("cargue otro y si desea cargar otro aprete 'a'");
        fflush(stdin);
        scanf("%c",&control);
    }

    while(!pilavacia(&DADA))  {
        apilar(&AUX1,desapilar(&DADA));
    }

    while(!pilavacia(&AUX1))  {
        apilar(&AUX2,desapilar(&AUX1));
    }

    while(!pilavacia(&AUX2))  {
        apilar(&DADA,desapilar(&AUX2));
    }
    printf("DADA");
    mostrar (&DADA);
    printf("aux1");
    mostrar (&AUX1);
    printf("aux2");
    mostrar (&AUX2);




6.- Pasar el primer elemento (tope) de la pila DADA a su última posición (base),
dejando los restantes elementos en el mismo orden.

Pila DADA;
Pila AUX;
Pila AUX2;
inicpila(&DADA);
inicpila(&AUX);
inicpila(&AUX2);
char control='A';

while (control=='A'){
    leer (&DADA);
    printf("quiere seguir cargando? presione 'A' si quiere seguir cargando");
    fflush(stdin);
    scanf("%c",&control);
}
apilar(&AUX,desapilar(&DADA));

while(!pilavacia(&DADA)){
    apilar(&AUX2,desapilar(&DADA));

}
apilar(&DADA,desapilar(&AUX));
while(!pilavacia(&AUX2)){
    apilar(&DADA,desapilar(&AUX2));
}
printf("DADA");
mostrar(&DADA);




7.- Pasar el último elemento (base) de la pila DADA a su primera posición
tope), dejando los restantes elementos en el mismo orden

Pila DADA;
Pila AUX;
Pila AUX2;
inicpila(&DADA);
inicpila(&AUX);
inicpila (&AUX2);
char control='A';
while (control=='A'){
    leer (&DADA);
    printf("quiere seguir cargando? presione 'A' si quiere seguir cargando");
    fflush(stdin);
    scanf("%c",&control);

}
while(!pilavacia(&DADA)){
    apilar (&AUX,desapilar(&DADA));

}

apilar(&AUX2,desapilar (&AUX));


while(!pilavacia(&AUX)){
    apilar (&DADA,desapilar(&AUX));
}
while(!pilavacia(&AUX2)){
    apilar(&DADA,desapilar(&AUX2));
}
mostrar(&DADA);





8.Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa.


Pila MAZO;
Pila JUGADOR1;
Pila JUGADOR2;
inicpila (&MAZO);
inicpila(&JUGADOR1);
inicpila(&JUGADOR2);


apilar(&MAZO,1);
apilar(&MAZO,2);
apilar(&MAZO,3);
apilar(&MAZO,4);
apilar(&MAZO,5);
apilar(&MAZO,6);
apilar(&MAZO,7);
apilar(&MAZO,8);
apilar(&MAZO,9);
apilar(&MAZO,10);



while(!pilavacia(&MAZO)){
    apilar(&JUGADOR1,desapilar(&MAZO));
    if(!pilavacia(&MAZO)){
    apilar(&JUGADOR2,desapilar(&MAZO));
    }
}


printf("MAZO");
mostrar(&MAZO);
printf("PJ1");
mostrar(&JUGADOR1);
printf("PJ2");
mostrar(&JUGADOR2);





9.- Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado.
Recordar no utilizar para la resolución de los ejercicios variables que funcionen como contadores
o acumuladores. La problemática debe resolverse aplicando pensamiento lógico.


Pila A;
Pila B;
Pila AUXA;
Pila AUXB;
inicpila(&A);
inicpila(&B);
inicpila(&AUXA);
inicpila(&AUXB);
char control = 'A';
char control2 ='B';

    while(control=='A'){

        leer(&A);
        printf("cargue otro y si desea cargar otro aprete 'A'");
        fflush(stdin);
        scanf("%c",&control);
    }


    while(control2=='B'){

        leer(&B);
        printf("cargue otro y si desea cargar otro aprete 'B'");
        fflush(stdin);
        scanf("%c",&control2);
    }


    while(!pilavacia(&A) && !pilavacia(&B)){
        apilar(&AUXA,desapilar(&A));
        apilar(&AUXB, desapilar(&B));


    }
    if (pilavacia(&A)&& pilavacia(&B)){
        printf("las pilas son iguales");

    }

    else {
        if(!pilavacia(&A)){
            printf("la pila 'A' tiene mas elementos");
        }

    else{
        printf("a pila 'b' tiene mas elementos");
    }
    }
    mostrar(&A);
    mostrar(&B);
    mostrar(&AUXA);
    mostrar(&AUXB);




10.- Cargar las pilas A y B y luego compararlas, evaluando si son completamente iguales (en cantidad de elementos,
valores que contienen y posición de los mismos). Mostrar por pantalla el resultado. Recordar no utilizar para la
resolución de los ejercicios variables que funcionen como contadores o acumuladores. La problemática debe resolverse
aplicando pensamiento lógico.




    Pila A;
    Pila B;
    Pila AUXA;
    Pila AUXB;
    inicpila(&A);
    inicpila(&B);
    inicpila(&AUXA);
    inicpila(&AUXB);
    char control = 'A';
    char control2 ='B';

    while(control=='A'){

        leer(&A);
        printf("\ncargue otro y si desea cargar otro aprete 'A'\n");
        fflush(stdin);
        scanf("%c",&control);
    }


    while(control2=='B'){

        leer(&B);
        printf("\ncargue otro y si desea cargar otro aprete 'B'\n");
        fflush(stdin);
        scanf("%c",&control2);
    }


    while(!pilavacia(&A) && !pilavacia(&B)&& tope(&A)==tope(&B)){
       apilar(&AUXA,desapilar(&A));
       apilar(&AUXB,desapilar(&B));

    }
    if(pilavacia(&A)&& pilavacia(&B)){
        printf("\nlas pilas son iguales\n\n\n");
    }
    else
        printf("\nlas pilas no son iguales\n\n\n");


/// 11.- Suponiendo la existencia de una pila MODELO que no esté vacía, eliminar de la pila DADA
/// todos los elementos que sean iguales al TOPE de la pila MODELO.

    Pila DADA;
    Pila MODELO;
    Pila AUXA;
    Pila AUXB;
    inicpila(&DADA);
    inicpila(&MODELO);
    inicpila(&AUXA);
    inicpila (&AUXB);

    apilar(&MODELO,1);
    apilar(&MODELO,2);
    apilar(&MODELO,3);
    apilar(&MODELO,4);
    apilar(&MODELO,5);

    char control = 'A';

    while(control=='A'){

        leer(&DADA);
        printf("cargue otro y si desea cargar otro aprete 'A'");
        fflush(stdin);
        scanf("%c",&control);
    }

    while (!pilavacia(&DADA)){

    if (tope(&MODELO) == tope(&DADA)){
            apilar(&AUXB, desapilar(&DADA));
        }
        else{
            apilar(&AUXA, desapilar(&DADA));
        }
    }

    while(!pilavacia(&AUXA)){
        apilar(&DADA,desapilar(&AUXA));
    }
    printf("MODELO");
    mostrar (&MODELO);
    printf("DADA");
    mostrar (&DADA);

    mostrar (&AUXA);
    printf("IGUALES A TOP MODELO");
    mostrar (&AUXB);



 12.Suponiendo la existencia de una pila MODELO (vacía o no),
   eliminar de la pila DADA todos los elementos que existan en la pila MODELO.



    Pila DADA;
    Pila MODELO;
    Pila AUXA;
    Pila AUXB;
    Pila AUXC;
    inicpila(&DADA);
    inicpila(&MODELO);
    inicpila(&AUXA);
    inicpila (&AUXB);
    inicpila(&AUXC);

    apilar(&MODELO,1);
    apilar(&MODELO,2);
    apilar(&MODELO,3);
    apilar(&MODELO,4);
    apilar(&MODELO,5);

    char control = 'A';

    while(control=='A'){

        leer(&DADA);
        printf("cargue otro y si desea cargar otro aprete 'A'");
        fflush(stdin);
        scanf("%c",&control);
    }
    while (!pilavacia(&MODELO)){

        while (!pilavacia(&DADA)){

            if (tope(&MODELO) == tope(&DADA)){
            apilar(&AUXB, desapilar(&DADA));

        }
            else{
            apilar(&AUXA, desapilar(&DADA));
        }
        }

        apilar (&AUXC, desapilar(&MODELO));

        while (!pilavacia(&AUXA)){

            if (tope(&MODELO) == tope(&AUXA)){
            apilar(&AUXB, desapilar(&AUXA));

        }
            else{
            apilar(&DADA, desapilar(&AUXA));
        }
        }
    }

    printf("DADA");
        mostrar (&DADA);
    printf("MODELO");
        mostrar(&MODELO);
    printf("AUXA");
        mostrar(&AUXA);
    printf("AUXB");
        mostrar(&AUXB);
    printf("AUXC");
        mostrar(&AUXC);


    13.- Suponiendo la existencia de una pila LÍMITE, pasar los elementos de la pila DADA
     que sean mayores o iguales que el tope de LIMITE a la pila MAYORES, y los elementos que sean menores a la pila MENORES.


    Pila DADA;
    Pila LIMITE;
    Pila MAYORES;
    Pila MENORES;
    inicpila(&DADA);
    inicpila(&LIMITE);
    inicpila(&MAYORES);
    inicpila(&MENORES);

    apilar(&LIMITE,1);
    apilar(&LIMITE,2);
    apilar(&LIMITE,3);

    char control = 'A';

    while(control=='A'){

        leer(&DADA);
        printf("cargue otro y si desea cargar otro aprete 'A'");
        fflush(stdin);
        scanf("%c",&control);
    }

    while (!pilavacia(&DADA)){
        if (tope(&DADA)>= tope(&LIMITE)){
            apilar (&MAYORES, desapilar(&DADA));
        }
        else{
            apilar(&MENORES, desapilar(&DADA));
        }
    }
    printf("MAYORES");
    mostrar (&MAYORES);
    printf("MENORES");
    mostrar (&MENORES);


14.- Determinar si la cantidad de elementos de la pila DADA es par. Si es par, pasar el elemento del tope de la pila DADA
 a la pila PAR y si es impar pasar el tope a la pila IMPAR (el ejercicio debe ser realizado SIN contar los elementos)

*/


Pila DADA;
Pila PAR;
Pila IMPAR;
Pila AUX1;
Pila AUX2;
inicpila (&DADA);
inicpila(&PAR);
inicpila(&IMPAR);
inicpila(&AUX1);
inicpila(&AUX2);

apilar(&DADA,1);
apilar(&DADA,2);
apilar(&DADA,3);
apilar(&DADA,4);
apilar(&DADA,5);





while(!pilavacia(&DADA)){
    apilar(&AUX1,desapilar(&DADA));
    if(!pilavacia(&DADA)){
    apilar(&AUX2,desapilar(&DADA));
    }
}
    apilar(&DADA, desapilar(&AUX1));
    apilar(&DADA, desapilar(&AUX2));


if (pilavacia(&DADA)){
    apilar(&PAR, desapilar(&AUX2));
    }
    else {
        apilar(&IMPAR, desapilar(&DADA));
    }


printf("DADA");
mostrar(&DADA);
printf("PAR");
mostrar(&PAR);
printf("IMPAR");
mostrar(&IMPAR);





    return 0;






}
