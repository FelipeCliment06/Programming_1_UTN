#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int valorrandom();
void punto2();
int sumaN(int N);
void tabla(int N);
void cambiasigno(int *num);
void carga2valores(int *A, int *B);
void calculadora();

int main() {
    int opcion;
    srand(time(NULL)); // Inicializar semilla del random

    do {
        printf("\n------------------\n");
        printf("MENU DE OPCIONES\n");
        printf("------------------\n");
        printf("1. Valor RANDOM de 0 a 100\n");
        printf("2. Mayor y menor de 3 numeros\n");
        printf("3. Suma de enteros positivos menores que N\n");
        printf("4. Mostrar tabla de multiplicar\n");
        printf("5. Calculadora\n");
        printf("6. Cambiar signo de un numero\n");
        printf("7. Cargar 2 valores por referencia\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                int valor = valorrandom();
                printf("Valor random: %d\n", valor);
                break;
            }
            case 2:
                punto2();
                break;
            case 3: {
                int N, resultado;
                printf("Ingrese un numero: ");
                scanf("%d", &N);
                resultado = sumaN(N);
                printf("La suma es: %d\n", resultado);
                break;
            }
            case 4: {
                int num;
                printf("Ingrese un numero para la tabla: ");
                scanf("%d", &num);
                tabla(num);
                break;
            }
            case 5:
                calculadora();
                break;
            case 6: {
                int num;
                printf("Ingrese un numero: ");
                scanf("%d", &num);
                cambiasigno(&num);
                printf("Con signo cambiado: %d\n", num);
                break;
            }
            case 7: {
                int num1, num2;
                carga2valores(&num1, &num2);
                printf("Los valores cargados son: %d y %d\n", num1, num2);
                break;
            }
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }

    } while (opcion != 0);

    return 0;
}

// 1. Valor random
int valorrandom() {
    return rand() % 101;
}

// 2. Mayor y menor de tres numeros
void punto2() {
    int num1, num2, num3, mayor, menor;

    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);
    printf("Ingrese el tercer numero: ");
    scanf("%d", &num3);

    mayor = num1;
    if (num2 > mayor) mayor = num2;
    if (num3 > mayor) mayor = num3;

    menor = num1;
    if (num2 < menor) menor = num2;
    if (num3 < menor) menor = num3;

    printf("Mayor: %d, Menor: %d\n", mayor, menor);
}

// 3. Suma de enteros menores a N
int sumaN(int N) {
    int suma = 0;
    for (int i = 0; i < N; i++) {
        suma += i;
    }
    return suma;
}

// 4. Tabla de multiplicar
void tabla(int N) {
    printf("Tabla del %d:\n", N);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", N, i, N * i);
    }
}

// 5. Calculadora
void calculadora() {
    int n1, n2, opcion;
    float res;

    printf("Calculadora\n");
    printf("1. Sumar\n2. Restar\n3. Multiplicar\n4. Dividir\n");
    printf("Seleccione una operacion: ");
    scanf("%d", &opcion);

    printf("Ingrese el primer numero: ");
    scanf("%d", &n1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &n2);

    switch (opcion) {
        case 1:
            res = n1 + n2;
            printf("Resultado: %.2f\n", res);
            break;
        case 2:
            res = n1 - n2;
            printf("Resultado: %.2f\n", res);
            break;
        case 3:
            res = n1 * n2;
            printf("Resultado: %.2f\n", res);
            break;
        case 4:
            if (n2 != 0) {
                res = (float)n1 / n2;
                printf("Resultado: %.2f\n", res);
            } else {
                printf("Error: division por cero\n");
            }
            break;
        default:
            printf("Opcion invalida.\n");
    }
}

// 6. Cambiar signo
void cambiasigno(int *num) {
    *num = -(*num);
}

// 7. Cargar 2 valores por referencia
void carga2valores(int *A, int *B) {
    printf("Cargar primer valor: ");
    scanf("%d", A);
    printf("Cargar segundo valor: ");
    scanf("%d", B);
}














