#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/// PROTOTIPOS
Pila apilarpila(Pila A);
Pila pasarpila(Pila A, Pila B);
Pila pasarenorden(Pila A, Pila B);
int encontrarmenor(Pila *A);
int topeyanterior(Pila *A);
int sumaElementos(Pila A);
int cantidadElementos(Pila A);
float divisionElementos(int suma, int cantidad);
float promedio(Pila A);
int numeroDecimal(Pila A);
void meterunN(Pila *A, int anadir);
Pila ordenadaPorInsercion(Pila A);

int main() {
    int opcion;
    Pila A, B;
    int resultado;
    float resultadoF;

    do {
        printf("\n======= MENU PILAS =======\n");
        printf("1. Ingresar varios elementos a una pila (consigna 1)\n");
        printf("2. Pasar elementos de una pila a otra (consigna 2)\n");
        printf("3. Pasar elementos conservando el orden (consigna 3)\n");
        printf("4. Encontrar y eliminar el menor elemento (consigna 4)\n");
        printf("5. Ordenar pila con insercion (consigna 7)\n");
        printf("6. Sumar tope y anterior sin alterar la pila (consigna 8)\n");
        printf("7. Calcular promedio (consigna 9)\n");
        printf("8. Transformar pila a numero decimal (consigna 10)\n");
        printf("9. Insertar un numero conservando el orden (consigna 6)\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: /// 1. Ingresar varios elementos a una pila
                inicpila(&A);
                A = apilarpila(A);
                mostrar(&A);
                break;
            case 2: /// 2. Pasar todos los elementos de una pila a otra
                inicpila(&A);
                inicpila(&B);
                A = apilarpila(A);
                B = pasarpila(A, B);
                mostrar(&A);
                mostrar(&B);
                break;
            case 3: /// 3. Pasar elementos conservando el orden
                inicpila(&A);
                inicpila(&B);
                A = apilarpila(A);
                B = pasarenorden(A, B);
                mostrar(&B);
                break;
            case 4: /// 4. Encontrar el menor elemento y eliminarlo
                inicpila(&A);
                A = apilarpila(A);
                resultado = encontrarmenor(&A);
                printf("El menor elemento era: %d\n", resultado);
                mostrar(&A);
                break;
            case 5: /// 7. Ordenar usando funcion del ejercicio 6 (ordenamiento por insercion)
                inicpila(&A);
                A = apilarpila(A);
                B = ordenadaPorInsercion(A);
                mostrar(&B);
                break;
            case 6: /// 8. Sumar tope y anterior sin alterar pila
                inicpila(&A);
                A = apilarpila(A);
                resultado = topeyanterior(&A);
                printf("Suma del tope y anterior: %d\n", resultado);
                mostrar(&A);
                break;
            case 7: /// 9. Calcular promedio (usa 4 funciones)
                inicpila(&A);
                A = apilarpila(A);
                resultadoF = promedio(A);
                printf("Promedio de los elementos: %.2f\n", resultadoF);
                mostrar(&A);
                break;
            case 8: /// 10. Transformar pila a numero decimal
                inicpila(&A);
                A = apilarpila(A);
                resultado = numeroDecimal(A);
                printf("Numero decimal resultante: %d\n", resultado);
                mostrar(&A);
                break;
            case 9: /// 6. Insertar elemento conservando el orden
                inicpila(&A);
                A = apilarpila(A);
                printf("Ingrese numero a insertar: ");
                scanf("%d", &resultado);
                meterunN(&A, resultado);
                mostrar(&A);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }

    } while(opcion != 0);

    return 0;
}

/// FUNCIONES

/// 1. Apilar varios elementos
Pila apilarpila(Pila A) {
    char control = 'a';
    while(control == 'a' || control == 'A') {
        leer(&A);
        printf("Cargar otro? (A para continuar): ");
        fflush(stdin);
        scanf("%c", &control);
    }
    return A;
}

/// 2. Pasar elementos de una pila a otra
Pila pasarpila(Pila A, Pila B) {
    while(!pilavacia(&A)) {
        apilar(&B, desapilar(&A));
    }
    return B;
}

/// 3. Pasar conservando orden
Pila pasarenorden(Pila A, Pila B) {
    Pila AUX;
    inicpila(&AUX);
    while(!pilavacia(&A)) {
        apilar(&AUX, desapilar(&A));
    }
    while(!pilavacia(&AUX)) {
        apilar(&B, desapilar(&AUX));
    }
    return B;
}

/// 4. Encontrar menor y eliminarlo
int encontrarmenor(Pila *A) {
    Pila aux, aux2;
    inicpila(&aux);
    inicpila(&aux2);

    if(!pilavacia(A))
        apilar(&aux, desapilar(A));

    while(!pilavacia(A)) {
        if(tope(A) >= tope(&aux))
            apilar(&aux2, desapilar(A));
        else
            apilar(&aux, desapilar(A));
    }

    while(!pilavacia(&aux2)) apilar(A, desapilar(&aux2));
    apilar(&aux2, desapilar(&aux));
    while(!pilavacia(&aux)) apilar(A, desapilar(&aux));
    return tope(&aux2);
}

/// 8. Sumar tope y anterior
int topeyanterior(Pila *A) {
    Pila AUX;
    inicpila(&AUX);
    int n1, n2, resultado;

    apilar(&AUX, desapilar(A));
    n1 = tope(&AUX);
    apilar(&AUX, desapilar(A));
    n2 = tope(&AUX);
    resultado = n1 + n2;
    while(!pilavacia(&AUX)) apilar(A, desapilar(&AUX));
    return resultado;
}

/// 9.1. Sumar todos los elementos
int sumaElementos(Pila A) {
    int suma = 0;
    Pila AUX;
    inicpila(&AUX);
    while(!pilavacia(&A)) {
        apilar(&AUX, desapilar(&A));
        suma += tope(&AUX);
    }
    return suma;
}

/// 9.2. Contar elementos
int cantidadElementos(Pila A) {
    int contador = 0;
    Pila AUX;
    inicpila(&AUX);
    while(!pilavacia(&A)) {
        apilar(&AUX, desapilar(&A));
        contador++;
    }
    return contador;
}

/// 9.3. Dividir suma / cantidad
float divisionElementos(int suma, int cantidad) {
    return (float)suma / cantidad;
}

/// 9. Calcular promedio (usa las 3 anteriores)
float promedio(Pila A) {
    int suma = sumaElementos(A);
    int cant = cantidadElementos(A);
    return divisionElementos(suma, cant);
}

/// 10. Convertir a número decimal
int numeroDecimal(Pila A) {
    Pila AUX2;
    inicpila(&AUX2);
    int num = 0;
    int decimal = 1;

    while(!pilavacia(&A)) apilar(&AUX2, desapilar(&A));
    while(!pilavacia(&AUX2)) {
        apilar(&A, desapilar(&AUX2));
        num = tope(&A) * decimal + num;
        decimal *= 10;
    }
    return num;
}

/// 6. Insertar conservando orden
void meterunN(Pila *A, int anadir) {
    Pila AUX;
    inicpila(&AUX);
    while((!pilavacia(A)) && tope(A) > anadir)
        apilar(&AUX, desapilar(A));
    apilar(A, anadir);
    while(!pilavacia(&AUX)) apilar(A, desapilar(&AUX));
}

/// 7. Ordenar usando insercion
Pila ordenadaPorInsercion(Pila A) {
    Pila B;
    inicpila(&B);
    while(!pilavacia(&A))
        meterunN(&B, desapilar(&A));
    return B;
}



