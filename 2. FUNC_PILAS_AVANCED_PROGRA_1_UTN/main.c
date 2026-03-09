#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

// Prototipos de funciones
void sumarElementos();
void contarElementos();
void promedioElementos();
void buscarElemento();
void eliminarElemento();
void esCapicua();
void unionDePilas();
void intercalarOrdenadas();

int main() {
    int opcion;

    do {
        printf("\n\n=== MENU DE EJERCICIOS CON PILAS ===\n");
        printf("1. Sumar elementos\n");
        printf("2. Contar elementos\n");
        printf("3. Calcular promedio\n");
        printf("4. Buscar elemento\n");
        printf("5. Eliminar elemento\n");
        printf("6. Verificar si es capicua\n");
        printf("7. Union de dos pilas\n");
        printf("8. Intercalar pilas ordenadas\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: sumarElementos(); break;
            case 2: contarElementos(); break;
            case 3: promedioElementos(); break;
            case 4: buscarElemento(); break;
            case 5: eliminarElemento(); break;
            case 6: esCapicua(); break;
            case 7: unionDePilas(); break;
            case 8: intercalarOrdenadas(); break;
            case 0: printf("Saliendo...\n"); break;
            default: printf("Opcion invalida.\n");
        }
    } while (opcion != 0);

    return 0;
}

// 1. Sumar los elementos de una pila
void sumarElementos() {
    Pila A;
    inicpila(&A);
    int suma = 0, num;

    printf("Ingrese valores a la pila (0 para terminar):\n");
    do {
        scanf("%d", &num);
        if (num != 0) {
            apilar(&A, num);
            suma += num;
        }
    } while (num != 0);

    printf("La suma de los elementos es: %d\n", suma);
}

// 2. Contar los elementos de una pila
void contarElementos() {
    Pila A;
    inicpila(&A);
    int contador = 0, num;

    printf("Ingrese valores a la pila (0 para terminar):\n");
    do {
        scanf("%d", &num);
        if (num != 0) {
            apilar(&A, num);
            contador++;
        }
    } while (num != 0);

    printf("La cantidad de elementos es: %d\n", contador);
}

// 3. Calcular el promedio de los valores de una pila
void promedioElementos() {
    Pila A;
    inicpila(&A);
    int suma = 0, contador = 0, num;
    float promedio;

    printf("Ingrese valores a la pila (0 para terminar):\n");
    do {
        scanf("%d", &num);
        if (num != 0) {
            apilar(&A, num);
            suma += num;
            contador++;
        }
    } while (num != 0);

    if (contador > 0) {
        promedio = (float)suma / contador;
        printf("El promedio es: %.2f\n", promedio);
    } else {
        printf("La pila esta vacia.\n");
    }
}

// 4. Determinar si un elemento buscado esta en la pila
void buscarElemento() {
    Pila A;
    inicpila(&A);
    int num, buscado, encontrado = 0;

    printf("Ingrese valores a la pila (0 para terminar):\n");
    do {
        scanf("%d", &num);
        if (num != 0)
            apilar(&A, num);
    } while (num != 0);

    printf("Ingrese el valor a buscar: ");
    scanf("%d", &buscado);

    while (!pilavacia(&A)) {
        if (tope(&A) == buscado) {
            encontrado = 1;
            break;
        }
        desapilar(&A);
    }

    if (encontrado)
        printf("El elemento esta en la pila.\n");
    else
        printf("El elemento NO esta en la pila.\n");
}

// 5. Eliminar un elemento especifico de la pila
void eliminarElemento() {
    Pila A, AUX;
    inicpila(&A);
    inicpila(&AUX);
    int num, eliminar;

    printf("Ingrese valores a la pila (0 para terminar):\n");
    do {
        scanf("%d", &num);
        if (num != 0)
            apilar(&A, num);
    } while (num != 0);

    printf("Ingrese el valor a eliminar: ");
    scanf("%d", &eliminar);

    int eliminado = 0;
    while (!pilavacia(&A)) {
        if (!eliminado && tope(&A) == eliminar) {
            desapilar(&A);
            eliminado = 1;
        } else {
            apilar(&AUX, desapilar(&A));
        }
    }

    while (!pilavacia(&AUX))
        apilar(&A, desapilar(&AUX));

    if (eliminado)
        printf("Elemento eliminado.\n");
    else
        printf("Elemento no encontrado.\n");
}

// 6. Verificar si una pila es capicua
void esCapicua() {
    Pila A, AUX1, AUX2;
    inicpila(&A);
    inicpila(&AUX1);
    inicpila(&AUX2);
    int num;

    printf("Ingrese valores a la pila (0 para terminar):\n");
    do {
        scanf("%d", &num);
        if (num != 0)
            apilar(&A, num);
    } while (num != 0);

    Pila temp;
    inicpila(&temp);

    while (!pilavacia(&A)) {
        int val = tope(&A);
        apilar(&AUX1, val);
        apilar(&AUX2, desapilar(&A));
    }

    while (!pilavacia(&AUX2))
        apilar(&A, desapilar(&AUX2));

    int capicua = 1;
    while (!pilavacia(&AUX1)) {
        if (tope(&AUX1) != tope(&A)) {
            capicua = 0;
            break;
        }
        desapilar(&AUX1);
        desapilar(&A);
    }

    printf(capicua ? "La pila es capicua.\n" : "La pila NO es capicua.\n");
}

// 7. Union de dos pilas sin elementos repetidos
void unionDePilas() {
    Pila A, B, C, TEMP;
    inicpila(&A);
    inicpila(&B);
    inicpila(&C);
    inicpila(&TEMP);
    int num;

    printf("Cargar pila A (0 para terminar):\n");
    do {
        scanf("%d", &num);
        if (num != 0) apilar(&A, num);
    } while (num != 0);

    printf("Cargar pila B (0 para terminar):\n");
    do {
        scanf("%d", &num);
        if (num != 0) apilar(&B, num);
    } while (num != 0);

    while (!pilavacia(&A)) {
        apilar(&C, tope(&A));
        desapilar(&A);
    }

    while (!pilavacia(&B)) {
        int val = tope(&B);
        desapilar(&B);
        int repetido = 0;

        while (!pilavacia(&C)) {
            if (tope(&C) == val) repetido = 1;
            apilar(&TEMP, desapilar(&C));
        }
        while (!pilavacia(&TEMP))
            apilar(&C, desapilar(&TEMP));

        if (!repetido)
            apilar(&C, val);
    }

    printf("Union de pilas sin repetidos:\n");
    mostrar(&C);
}

// 8. Intercalar dos pilas ordenadas en una final ordenada
void intercalarOrdenadas() {
    Pila A, B, C;
    inicpila(&A);
    inicpila(&B);
    inicpila(&C);
    int num;

    printf("Cargar pila A ORDENADA (0 para terminar):\n");
    do {
        scanf("%d", &num);
        if (num != 0) apilar(&A, num);
    } while (num != 0);

    printf("Cargar pila B ORDENADA (0 para terminar):\n");
    do {
        scanf("%d", &num);
        if (num != 0) apilar(&B, num);
    } while (num != 0);

    Pila tempA, tempB;
    inicpila(&tempA);
    inicpila(&tempB);

    while (!pilavacia(&A)) apilar(&tempA, desapilar(&A));
    while (!pilavacia(&B)) apilar(&tempB, desapilar(&B));

    while (!pilavacia(&tempA) && !pilavacia(&tempB)) {
        if (tope(&tempA) < tope(&tempB)) {
            apilar(&C, desapilar(&tempA));
        } else {
            apilar(&C, desapilar(&tempB));
        }
    }

    while (!pilavacia(&tempA)) apilar(&C, desapilar(&tempA));
    while (!pilavacia(&tempB)) apilar(&C, desapilar(&tempB));

    printf("Resultado de la intercalacion ordenada:\n");
    mostrar(&C);
}


