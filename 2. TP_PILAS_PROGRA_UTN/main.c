#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
void ejercicio7();
void ejercicio8();
void ejercicio9();
void ejercicio10();
void ejercicio11();
void ejercicio12();
void ejercicio13();
void ejercicio14();

int main() {
    int opcion;

    do {
        printf("\n====== MENU DE EJERCICIOS DE PILAS ======\n");
        printf("1.- Repartir pila DADA (5 elem) en AUX1 (3 elem) y AUX2 (resto)\n");
        printf("2.- Pasar todos los elementos de ORIGEN a DESTINO\n");
        printf("3.- Pasar a DISTINTOS los elementos distintos a 8 de DADA\n");
        printf("4.- Pasar elementos de ORIGEN a DESTINO manteniendo orden\n");
        printf("5.- Invertir la pila DADA\n");
        printf("6.- Pasar el tope de DADA a la base\n");
        printf("7.- Pasar el último elemento (base) de DADA al tope\n");
        printf("8.- Repartir los elementos de MAZO en JUGADOR1 y JUGADOR2 alternados\n");
        printf("9.- Comparar cantidad de elementos de pilas A y B\n");
        printf("10.- Comparar pilas A y B para ver si son iguales en todo\n");
        printf("11.- Eliminar de DADA todos los elementos iguales al tope de MODELO\n");
        printf("12.- Eliminar de DADA todos los elementos que estén en MODELO\n");
        printf("13.- Pasar a MAYORES los >= tope LIMITE y a MENORES los demás\n");
        printf("14.- Determinar si la cantidad de elementos en DADA es par o impar y pasar el tope a PAR o IMPAR\n");
        printf("0.- Salir\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch(opcion){
            case 1: ejercicio1(); break;
            case 2: ejercicio2(); break;
            case 3: ejercicio3(); break;
            case 4: ejercicio4(); break;
            case 5: ejercicio5(); break;
            case 6: ejercicio6(); break;
            case 7: ejercicio7(); break;
            case 8: ejercicio8(); break;
            case 9: ejercicio9(); break;
            case 10: ejercicio10(); break;
            case 11: ejercicio11(); break;
            case 12: ejercicio12(); break;
            case 13: ejercicio13(); break;
            case 14: ejercicio14(); break;
            case 0: printf("Saliendo...\n"); break;
            default: printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 0);

    return 0;
}

// 1.- Repartir pila DADA en AUX1 y AUX2
void ejercicio1() {
    Pila DADA, AUX1, AUX2;
    inicpila(&DADA);
    inicpila(&AUX1);
    inicpila(&AUX2);

    printf("\nEjercicio 1: Cargar pila DADA con 5 elementos\n");
    for(int i=0; i<5; i++) {
        printf("Ingrese elemento %d: ", i+1);
        leer(&DADA);
    }

    for(int i=0; i<3; i++) {
        if(!pilavacia(&DADA)) apilar(&AUX1, desapilar(&DADA));
    }
    while(!pilavacia(&DADA)) apilar(&AUX2, desapilar(&DADA));

    printf("Pila AUX1 (3 primeros elementos del tope de DADA):\n"); mostrar(&AUX1);
    printf("Pila AUX2 (resto de elementos de DADA):\n"); mostrar(&AUX2);
}

// 2.- Pasar todos los elementos de ORIGEN a DESTINO
void ejercicio2() {
    Pila ORIGEN, DESTINO;
    inicpila(&ORIGEN);
    inicpila(&DESTINO);
    int valor;

    printf("\nEjercicio 2: Cargar pila ORIGEN (0 para terminar)\n");
    while(1) {
        printf("Ingrese valor: ");
        scanf("%d", &valor);
        if(valor == 0) break;
        apilar(&ORIGEN, valor);
    }

    while(!pilavacia(&ORIGEN)) apilar(&DESTINO, desapilar(&ORIGEN));

    printf("Pila ORIGEN (vacía):\n"); mostrar(&ORIGEN);
    printf("Pila DESTINO (elementos transferidos):\n"); mostrar(&DESTINO);
}

// 3.- Pasar a DISTINTOS los elementos distintos a 8 de DADA
void ejercicio3() {
    Pila DADA, DISTINTOS, AUX;
    char control = 'a';
    inicpila(&DADA);
    inicpila(&DISTINTOS);
    inicpila(&AUX);

    printf("\nEjercicio 3: Cargar pila DADA (presione otra tecla para terminar)\n");
    while(control == 'a' || control == 'A') {
        leer(&DADA);
        printf("Presione 'a' para seguir cargando: ");
        fflush(stdin);
        scanf("%c", &control);
    }

    while(!pilavacia(&DADA)) {
        if(tope(&DADA) != 8) apilar(&DISTINTOS, desapilar(&DADA));
        else apilar(&AUX, desapilar(&DADA));
    }

    while(!pilavacia(&AUX)) apilar(&DADA, desapilar(&AUX));

    printf("Pila DADA:\n"); mostrar(&DADA);
    printf("Pila DISTINTOS (elementos != 8):\n"); mostrar(&DISTINTOS);
}

// 4.- Pasar elementos de ORIGEN a DESTINO manteniendo orden
void ejercicio4() {
    Pila ORIGEN, DESTINO, AUX;
    char control = 'a';
    inicpila(&ORIGEN);
    inicpila(&DESTINO);
    inicpila(&AUX);

    printf("\nEjercicio 4: Cargar pila ORIGEN (presione otra tecla para terminar)\n");
    while(control == 'a' || control == 'A') {
        leer(&ORIGEN);
        printf("Presione 'a' para seguir cargando: ");
        fflush(stdin);
        scanf("%c", &control);
    }

    while(!pilavacia(&ORIGEN)) apilar(&AUX, desapilar(&ORIGEN));
    while(!pilavacia(&AUX)) apilar(&DESTINO, desapilar(&AUX));

    printf("Pila ORIGEN (vacía):\n"); mostrar(&ORIGEN);
    printf("Pila DESTINO (mismo orden que ORIGEN):\n"); mostrar(&DESTINO);
}

// 5.- Invertir pila DADA
void ejercicio5() {
    Pila DADA, AUX1, AUX2;
    char control = 'a';
    inicpila(&DADA);
    inicpila(&AUX1);
    inicpila(&AUX2);

    printf("\nEjercicio 5: Cargar pila DADA (presione otra tecla para terminar)\n");
    while(control == 'a' || control == 'A') {
        leer(&DADA);
        printf("Presione 'a' para seguir cargando: ");
        fflush(stdin);
        scanf("%c", &control);
    }

    while(!pilavacia(&DADA)) apilar(&AUX1, desapilar(&DADA));
    while(!pilavacia(&AUX1)) apilar(&AUX2, desapilar(&AUX1));
    while(!pilavacia(&AUX2)) apilar(&DADA, desapilar(&AUX2));

    printf("Pila DADA invertida:\n"); mostrar(&DADA);
}

// 6.- Pasar el tope de DADA a la base
void ejercicio6() {
    Pila DADA, AUX, AUX2;
    char control = 'a';
    inicpila(&DADA);
    inicpila(&AUX);
    inicpila(&AUX2);

    printf("\nEjercicio 6: Cargar pila DADA (presione otra tecla para terminar)\n");
    while(control == 'a' || control == 'A') {
        leer(&DADA);
        printf("Presione 'a' para seguir cargando: ");
        fflush(stdin);
        scanf("%c", &control);
    }

    if(!pilavacia(&DADA)) apilar(&AUX, desapilar(&DADA)); // guardar tope
    while(!pilavacia(&DADA)) apilar(&AUX2, desapilar(&DADA)); // resto
    apilar(&DADA, desapilar(&AUX)); // tope ahora base
    while(!pilavacia(&AUX2)) apilar(&DADA, desapilar(&AUX2));

    printf("Pila DADA con tope pasado a base:\n"); mostrar(&DADA);
}

// 7.- Pasar último elemento (base) de DADA al tope
void ejercicio7() {
    Pila DADA, AUX, AUX2;
    char control = 'a';
    inicpila(&DADA);
    inicpila(&AUX);
    inicpila(&AUX2);

    printf("\nEjercicio 7: Cargar pila DADA (presione otra tecla para terminar)\n");
    while(control == 'a' || control == 'A') {
        leer(&DADA);
        printf("Presione 'a' para seguir cargando: ");
        fflush(stdin);
        scanf("%c", &control);
    }

    while(!pilavacia(&DADA)) apilar(&AUX, desapilar(&DADA)); // invertir pila
    if(!pilavacia(&AUX)) apilar(&AUX2, desapilar(&AUX)); // sacar el último (base)
    while(!pilavacia(&AUX)) apilar(&DADA, desapilar(&AUX)); // devolver resto

    while(!pilavacia(&AUX2)) apilar(&DADA, desapilar(&AUX2)); // poner el último arriba

    printf("Pila DADA con base pasada a tope:\n"); mostrar(&DADA);
}

// 8.- Repartir MAZO en JUGADOR1 y JUGADOR2 alternados
void ejercicio8() {
    Pila MAZO, JUGADOR1, JUGADOR2;
    inicpila(&MAZO);
    inicpila(&JUGADOR1);
    inicpila(&JUGADOR2);

    // Cargo MAZO fijo para demo
    for(int i=1; i<=10; i++) {
        apilar(&MAZO, i);
    }

    while(!pilavacia(&MAZO)) {
        apilar(&JUGADOR1, desapilar(&MAZO));
        if(!pilavacia(&MAZO)) apilar(&JUGADOR2, desapilar(&MAZO));
    }

    printf("Pila MAZO (vacía):\n"); mostrar(&MAZO);
    printf("Pila JUGADOR1 (elementos alternados):\n"); mostrar(&JUGADOR1);
    printf("Pila JUGADOR2 (elementos alternados):\n"); mostrar(&JUGADOR2);
}

// 9.- Comparar cantidad elementos pilas A y B (sin usar contadores)
void ejercicio9() {
    Pila A, B, AUXA, AUXB;
    char controlA='a', controlB='a';
    inicpila(&A);
    inicpila(&B);
    inicpila(&AUXA);
    inicpila(&AUXB);

    printf("\nEjercicio 9: Cargar pila A\n");
    while(controlA=='a' || controlA=='A') {
        leer(&A);
        printf("Presione 'a' para seguir cargando A: ");
        fflush(stdin);
        scanf("%c", &controlA);
    }

    printf("\nEjercicio 9: Cargar pila B\n");
    while(controlB=='a' || controlB=='A') {
        leer(&B);
        printf("Presione 'a' para seguir cargando B: ");
        fflush(stdin);
        scanf("%c", &controlB);
    }

    while(!pilavacia(&A) && !pilavacia(&B)) {
        apilar(&AUXA, desapilar(&A));
        apilar(&AUXB, desapilar(&B));
    }

    if(pilavacia(&A) && pilavacia(&B)) {
        printf("Las pilas tienen la misma cantidad de elementos.\n");
    } else if(!pilavacia(&A)) {
        printf("La pila A tiene más elementos.\n");
    } else {
        printf("La pila B tiene más elementos.\n");
    }
}

// 10.- Comparar pilas A y B (cantidad, valores, posición)
void ejercicio10() {
    Pila A, B, AUXA, AUXB;
    char controlA='a', controlB='a';
    inicpila(&A);
    inicpila(&B);
    inicpila(&AUXA);
    inicpila(&AUXB);

    printf("\nEjercicio 10: Cargar pila A\n");
    while(controlA=='a' || controlA=='A') {
        leer(&A);
        printf("Presione 'a' para seguir cargando A: ");
        fflush(stdin);
        scanf("%c", &controlA);
    }

    printf("\nEjercicio 10: Cargar pila B\n");
    while(controlB=='a' || controlB=='A') {
        leer(&B);
        printf("Presione 'a' para seguir cargando B: ");
        fflush(stdin);
        scanf("%c", &controlB);
    }

    int iguales = 1;

    while(!pilavacia(&A) && !pilavacia(&B)) {
        if(tope(&A) != tope(&B)) {
            iguales = 0;
            break;
        }
        apilar(&AUXA, desapilar(&A));
        apilar(&AUXB, desapilar(&B));
    }

    if(!pilavacia(&A) || !pilavacia(&B)) iguales = 0;

    if(iguales) {
        printf("Las pilas son iguales.\n");
    } else {
        printf("Las pilas NO son iguales.\n");
    }
}

// 11.- Eliminar de DADA todos los elementos iguales al tope de MODELO
void ejercicio11() {
    Pila DADA, MODELO, AUXA, AUXB;
    char control='a';
    inicpila(&DADA);
    inicpila(&MODELO);
    inicpila(&AUXA);
    inicpila(&AUXB);

    // Cargo MODELO fijo para demo (puedes modificar)
    apilar(&MODELO, 5);

    printf("\nEjercicio 11: Cargar pila DADA\n");
    while(control == 'a' || control == 'A') {
        leer(&DADA);
        printf("Presione 'a' para seguir cargando: ");
        fflush(stdin);
        scanf("%c", &control);
    }

    while(!pilavacia(&DADA)) {
        if(tope(&DADA) == tope(&MODELO)) {
            apilar(&AUXB, desapilar(&DADA));
        } else {
            apilar(&AUXA, desapilar(&DADA));
        }
    }
    while(!pilavacia(&AUXA)) apilar(&DADA, desapilar(&AUXA));

    printf("Pila MODELO:\n"); mostrar(&MODELO);
    printf("Pila DADA (elementos sin eliminar):\n"); mostrar(&DADA);
    printf("Elementos eliminados (iguales a tope MODELO):\n"); mostrar(&AUXB);
}

// 12.- Eliminar de DADA todos los elementos que estén en MODELO
void ejercicio12() {
    Pila DADA, MODELO, AUXA, AUXB, AUXC;
    char control='a';
    inicpila(&DADA);
    inicpila(&MODELO);
    inicpila(&AUXA);
    inicpila(&AUXB);
    inicpila(&AUXC);

    // Cargo MODELO fijo para demo (puedes modificar)
    apilar(&MODELO, 5);
    apilar(&MODELO, 3);

    printf("\nEjercicio 12: Cargar pila DADA\n");
    while(control == 'a' || control == 'A') {
        leer(&DADA);
        printf("Presione 'a' para seguir cargando: ");
        fflush(stdin);
        scanf("%c", &control);
    }

    while(!pilavacia(&MODELO)) {
        while(!pilavacia(&DADA)) {
            if(tope(&MODELO) == tope(&DADA)) {
                apilar(&AUXB, desapilar(&DADA));
            } else {
                apilar(&AUXA, desapilar(&DADA));
            }
        }
        apilar(&AUXC, desapilar(&MODELO));

        while(!pilavacia(&AUXA)) {
            if(!pilavacia(&MODELO) && tope(&MODELO) == tope(&AUXA)) {
                apilar(&AUXB, desapilar(&AUXA));
            } else {
                apilar(&DADA, desapilar(&AUXA));
            }
        }
    }

    printf("Pila DADA (sin elementos eliminados):\n"); mostrar(&DADA);
    printf("Pila MODELO (elementos a eliminar):\n"); mostrar(&MODELO);
    printf("Elementos eliminados:\n"); mostrar(&AUXB);
}

// 13.- Pasar a MAYORES los >= tope LIMITE, a MENORES los demás
void ejercicio13() {
    Pila DADA, LIMITE, MAYORES, MENORES;
    char control='a';
    inicpila(&DADA);
    inicpila(&LIMITE);
    inicpila(&MAYORES);
    inicpila(&MENORES);

    // Cargo LIMITE fijo para demo
    apilar(&LIMITE, 5);

    printf("\nEjercicio 13: Cargar pila DADA\n");
    while(control=='a' || control=='A') {
        leer(&DADA);
        printf("Presione 'a' para seguir cargando: ");
        fflush(stdin);
        scanf("%c", &control);
    }

    while(!pilavacia(&DADA)) {
        if(tope(&DADA) >= tope(&LIMITE)) apilar(&MAYORES, desapilar(&DADA));
        else apilar(&MENORES, desapilar(&DADA));
    }

    printf("Pila LIMITE:\n"); mostrar(&LIMITE);
    printf("Pila MAYORES (>= limite):\n"); mostrar(&MAYORES);
    printf("Pila MENORES (< limite):\n"); mostrar(&MENORES);
}

// 14.- Ver si cantidad de elementos DADA es par o impar y pasar tope a PAR o IMPAR
void ejercicio14() {
    Pila DADA, AUX, PAR, IMPAR;
    char control='a';
    int cont=0;
    inicpila(&DADA);
    inicpila(&AUX);
    inicpila(&PAR);
    inicpila(&IMPAR);

    printf("\nEjercicio 14: Cargar pila DADA\n");
    while(control=='a' || control=='A') {
        leer(&DADA);
        printf("Presione 'a' para seguir cargando: ");
        fflush(stdin);
        scanf("%c", &control);
    }

    while(!pilavacia(&DADA)) {
        cont++;
        apilar(&AUX, desapilar(&DADA));
    }
    while(!pilavacia(&AUX)) apilar(&DADA, desapilar(&AUX));

    if(cont % 2 == 0) {
        printf("Cantidad de elementos: %d (Par)\n", cont);
        if(!pilavacia(&DADA)) apilar(&PAR, desapilar(&DADA));
        printf("Pila PAR:\n"); mostrar(&PAR);
    } else {
        printf("Cantidad de elementos: %d (Impar)\n", cont);
        if(!pilavacia(&DADA)) apilar(&IMPAR, desapilar(&DADA));
        printf("Pila IMPAR:\n"); mostrar(&IMPAR);
    }
}
