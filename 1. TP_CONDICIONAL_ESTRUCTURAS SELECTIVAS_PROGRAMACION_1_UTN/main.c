#include <stdio.h>
#include <stdlib.h>

// Prototipos de funciones
void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();

int main() {
    int opcion;

    do {
        printf("\n========= MENU =========\n");
        printf("1. Verificar nota (selectiva simple)\n");
        printf("2. Verificar nota (selectiva compuesta)\n");
        printf("3. Descuento por compra (mayor a $5000)\n");
        printf("4. Calculo de sueldo semanal\n");
        printf("5. Orden ascendente de dos numeros\n");
        printf("6. Descuento por cantidad de camisas\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: ejercicio1(); break;
            case 2: ejercicio2(); break;
            case 3: ejercicio3(); break;
            case 4: ejercicio4(); break;
            case 5: ejercicio5(); break;
            case 6: ejercicio6(); break;
            case 0: printf("Saliendo del programa...\n"); break;
            default: printf("Opcion invalida. Intente de nuevo.\n");
        }

    } while (opcion != 0);

    return 0;
}

// 1. Selectiva simple: verificar si una nota aprueba
// Una persona ingresa su nota y se debe informar si aprobo (nota >= 6)
void ejercicio1() {
    float nota;
    printf("\nIngrese la nota: ");
    scanf("%f", &nota);

    if (nota >= 6) {
        printf("Aprobo\n");
    } else {
        printf("Desaprobo\n");
    }
}

// 2. Selectiva compuesta: verificar si aprobo o promociono
// Si nota >= 8 promociona. Si nota >= 6 y < 8, aprueba. Si < 6, desaprueba.
void ejercicio2() {
    float nota;
    printf("\nIngrese la nota: ");
    scanf("%f", &nota);

    if (nota >= 8) {
        printf("Promociono\n");
    } else if (nota >= 6) {
        printf("Aprobo pero no promociono\n");
    } else {
        printf("Desaprobo\n");
    }
}

// 3. Descuento si la compra supera los $5000
// En un almacen se hace un 20%% de descuento a los clientes cuya compra supere los $5.000.
void ejercicio3() {
    float compraTotal;
    printf("\nIngrese el total de la compra: ");
    scanf("%f", &compraTotal);

    if (compraTotal >= 5000) {
        compraTotal *= 0.8;
    }

    printf("El total a pagar con el descuento alplicado es: $%.2f\n", compraTotal);
}

// 4. Calculo de sueldo semanal
// Si trabaja 40 horas o menos se paga $300/hora
// Si trabaja mas de 40 horas: $300/h hasta 40 y $400/h extras
void ejercicio4() {
    float horas, pago;
    printf("\nIngrese horas trabajadas esta semana: ");
    scanf("%f", &horas);

    if (horas <= 40) {
        pago = horas * 300;
    } else {
        pago = 40 * 300 + (horas - 40) * 400;
    }

    printf("Su pago semanal es: $%.2f\n", pago);
}

// 5. Leer dos numeros e imprimirlos en forma ascendente
void ejercicio5() {
    int num1, num2;
    printf("\nIngrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);

    if (num1 < num2) {
        printf("Orden ascendente: %d, %d\n", num1, num2);
    } else {
        printf("Orden ascendente: %d, %d\n", num2, num1);
    }
}

// 6. Descuento por compra de camisas
// Si se compran 3 o mas camisas: 20%% de descuento
// Si se compran menos de 3 camisas: 10%% de descuento
void ejercicio6() {
    int camisas;
    float monto;
    printf("\nIngrese la cantidad de camisas: ");
    scanf("%d", &camisas);
    printf("Ingrese el total sin descuento: ");
    scanf("%f", &monto);

    if (camisas >= 3) {
        monto *= 0.8;
    } else {
        monto *= 0.9;
    }

    printf("El total a pagar con descuento es: $%.2f\n", monto);
}





















