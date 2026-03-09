#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>

// Prototipos

/// 1
int cargarY_DevolverCantidad(int a[]);
/// 2
void MostrarArrayEntero(int a[], int cantidad);
/// 3
int SumaElementosEnteros(int a[], int cantidad);
/// 4
void CopiarArrayEnLaPila(int a[], int cantidad, Pila *pila);
/// 5
void CargarArrayFlotante(float a[]);
float SumatoriaArrayFlotante(float a[]);
/// 6
int cargarY_DevolverCantidadChar(char a[]);
int EncontrarChar(char a[], int cantidad, char elemento);
void MostrarArrayChar(char a[], int cantidad);
/// 7
int InsertarOrdenado(char a[], int cantidad, char elemento);
/// 8
int MaximoCaracter(int a[], int cantidad);
/// 9
void Capicua(int a[], int cantidad);
/// 10
void invertirArregloEnteros(int a[], int cantidad);
/// 11
void OrdenamientoPorSeleccion(int a[], int cantidad);
int encontrarMenorEntero(int a[], int cantidad, int pos);
/// 12
void OrdenamientoPorInsercion(int a[], int cantidad);
void Insertar(int a[], int u, int elemento);
/// 13
void Juntar2Arreglos(char a[], char b[], int cantidad, int cantidad2, char c[]);
void OrdenamientoPorSeleccionChar(char a[], int cantidad);
int encontrarMenorChar(char a[], int cantidad, int pos);
/// 14
void sumatoria13(int a[], int cantidad);

int main()
{
    int arreglo[100];
    int cantidad;
    int cantidad2;
    int suma;
    Pila pila;
    inicpila(&pila);
    char array[100];
    char array2[100];
    char array3[200]; // para juntar dos arreglos char
    int flag;
    char elemento;
    float Suma;
    int mayor;
    int x;

    int arreglo13[5] = {1, 5, 6, 7, 8};

    do {
        printf("\n\n//////////////////////////// MENU DE EJERCICIOS ////////////////////////////\n");
        printf("Ingrese el numero del ejercicio (0 para salir):\n");
        printf("1.- Cargar arreglo entero y devolver cantidad.\n");
        printf("2.- Mostrar arreglo entero.\n");
        printf("3.- Sumar elementos de arreglo entero.\n");
        printf("4.- Copiar arreglo a pila.\n");
        printf("5.- Sumar arreglo float de 100 elementos.\n");
        printf("6.- Buscar caracter en arreglo char.\n");
        printf("7.- Insertar caracter en arreglo char ordenado.\n");
        printf("8.- Obtener maximo caracter de arreglo entero.\n");
        printf("9.- Determinar si arreglo entero es capicua.\n");
        printf("10.- Invertir arreglo entero.\n");
        printf("11.- Ordenamiento por seleccion (enteros).\n");
        printf("12.- Ordenamiento por insercion (enteros).\n");
        printf("13.- Juntar dos arreglos char ordenados y ordenarlos.\n");
        printf("14.- Generar arreglo sumatoria acumulada.\n");
        printf("0.- Salir.\n");
        printf("Ingrese opcion: ");
        scanf("%d", &x);

        // Limpieza buffer para evitar problemas con scanf y fgets/char
        while(getchar() != '\n');

        switch (x) {

            case 1:
                // 1. Cargar arreglo entero y devolver cantidad
                cantidad = cargarY_DevolverCantidad(arreglo);
                printf("Cantidad cargada: %d\n", cantidad);
                printf("Arreglo cargado:\n");
                MostrarArrayEntero(arreglo, cantidad);
                printf("\n");
                break;

            case 2:
                // 2. Mostrar arreglo entero (carga y luego muestra)
                cantidad = cargarY_DevolverCantidad(arreglo);
                MostrarArrayEntero(arreglo, cantidad);
                printf("\n");
                break;

            case 3:
                // 3. Sumar elementos arreglo entero
                cantidad = cargarY_DevolverCantidad(arreglo);
                MostrarArrayEntero(arreglo, cantidad);
                suma = SumaElementosEnteros(arreglo, cantidad);
                printf("\nSuma total: %d\n", suma);
                break;

            case 4:
                // 4. Copiar arreglo a pila
                cantidad = cargarY_DevolverCantidad(arreglo);
                MostrarArrayEntero(arreglo, cantidad);
                inicpila(&pila); // vaciar pila antes de copiar
                CopiarArrayEnLaPila(arreglo, cantidad, &pila);
                printf("Contenido de la pila:\n");
                mostrar(&pila);
                break;

            case 5:
                // 5. Sumar arreglo float 100 elementos (se cargan aleatorios)
                {
                    float arregloFloat[100];
                    CargarArrayFlotante(arregloFloat);
                    Suma = SumatoriaArrayFlotante(arregloFloat);
                    printf("Sumatoria arreglo float de 100 elementos: %.2f\n", Suma);
                }
                break;

            case 6:
                // 6. Buscar caracter en arreglo char
                cantidad = cargarY_DevolverCantidadChar(array);
                printf("Ingrese el caracter a buscar: ");
                scanf(" %c", &elemento);
                flag = EncontrarChar(array, cantidad, elemento);
                if (flag)
                    printf("El caracter '%c' se encuentra en el arreglo.\n", elemento);
                else
                    printf("El caracter '%c' NO se encuentra en el arreglo.\n", elemento);
                break;

            case 7:
                // 7. Insertar caracter en arreglo char ordenado
                cantidad = cargarY_DevolverCantidadChar(array);
                printf("Ingrese el caracter a insertar: ");
                scanf(" %c", &elemento);
                cantidad = InsertarOrdenado(array, cantidad, elemento);
                printf("Arreglo con caracter insertado:\n");
                MostrarArrayChar(array, cantidad);
                printf("\n");
                break;

            case 8:
                // 8. Obtener maximo caracter en arreglo entero
                cantidad = cargarY_DevolverCantidad(arreglo);
                mayor = MaximoCaracter(arreglo, cantidad);
                printf("El mayor caracter es (valor ASCII): %d\n", mayor);
                break;

            case 9:
                // 9. Determinar si arreglo entero es capicua
                cantidad = cargarY_DevolverCantidad(arreglo);
                Capicua(arreglo, cantidad);
                break;

            case 10:
                // 10. Invertir arreglo entero
                cantidad = cargarY_DevolverCantidad(arreglo);
                printf("Arreglo original:\n");
                MostrarArrayEntero(arreglo, cantidad);
                invertirArregloEnteros(arreglo, cantidad);
                printf("\nArreglo invertido:\n");
                MostrarArrayEntero(arreglo, cantidad);
                printf("\n");
                break;

            case 11:
                // 11. Ordenamiento por seleccion (enteros)
                cantidad = cargarY_DevolverCantidad(arreglo);
                OrdenamientoPorSeleccion(arreglo, cantidad);
                printf("Arreglo ordenado por seleccion:\n");
                MostrarArrayEntero(arreglo, cantidad);
                printf("\n");
                break;

            case 12:
                // 12. Ordenamiento por insercion (enteros)
                cantidad = cargarY_DevolverCantidad(arreglo);
                OrdenamientoPorInsercion(arreglo, cantidad);
                printf("Arreglo ordenado por insercion:\n");
                MostrarArrayEntero(arreglo, cantidad);
                printf("\n");
                break;

            case 13:
                // 13. Juntar dos arreglos char ordenados y ordenarlos
                printf("Carga primer arreglo char ordenado:\n");
                cantidad = cargarY_DevolverCantidadChar(array);
                printf("Carga segundo arreglo char ordenado:\n");
                cantidad2 = cargarY_DevolverCantidadChar(array2);
                Juntar2Arreglos(array, array2, cantidad, cantidad2, array3);
                OrdenamientoPorSeleccionChar(array3, cantidad + cantidad2);
                printf("Arreglo combinado y ordenado:\n");
                MostrarArrayChar(array3, cantidad + cantidad2);
                printf("\n");
                break;

            case 14:
                // 14. Generar arreglo sumatoria acumulada
                printf("Arreglo inicial:\n");
                MostrarArrayEntero(arreglo13, 5);
                sumatoria13(arreglo13, 5);
                printf("\nArreglo con sumatoria acumulada:\n");
                MostrarArrayEntero(arreglo13, 5);
                printf("\n");
                break;

            case 0:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }

    } while (x != 0);

    return 0;
}


/// FUNCIONES ///

/// 1
int cargarY_DevolverCantidad(int a[]) {
    int posicion = 0;
    char control;
    do {
        printf("Cargue un elemento entero: ");
        scanf("%d", &a[posicion]);
        posicion++;
        printf("Si quiere seguir ingresando (s/n): ");
        scanf(" %c", &control);
    } while (control == 's' || control == 'S');
    return posicion;
}

/// 2
void MostrarArrayEntero(int a[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("|%d| ", a[i]);
    }
}

/// 3
int SumaElementosEnteros(int a[], int cantidad) {
    int acumulador = 0;
    for (int i = 0; i < cantidad; i++) {
        acumulador += a[i];
    }
    return acumulador;
}

/// 4
void CopiarArrayEnLaPila(int a[], int cantidad, Pila *pila) {
    for (int i = 0; i < cantidad; i++) {
        apilar(pila, a[i]);
    }
}

/// 5
void CargarArrayFlotante(float a[]) {
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        a[i] = (float)(rand() % 1000) / 10.0f;  // valores de 0.0 a 99.9
    }
}
float SumatoriaArrayFlotante(float a[]) {
    float sumatoria = 0;
    for (int i = 0; i < 100; i++) {
        sumatoria += a[i];
    }
    return sumatoria;
}

/// 6
int cargarY_DevolverCantidadChar(char a[]) {
    int posicion = 0;
    char control;
    do {
        printf("Cargue un caracter: ");
        scanf(" %c", &a[posicion]);
        posicion++;
        printf("Si quiere seguir ingresando (s/n): ");
        scanf(" %c", &control);
    } while (control == 's' || control == 'S');
    return posicion;
}
int EncontrarChar(char a[], int cantidad, char elemento) {
    int i = 0;
    int flag = 0;
    while ((i < cantidad) && (flag == 0)) {
        if (elemento == a[i]) {
            flag = 1;
        } else {
            i++;
        }
    }
    return flag;
}
void MostrarArrayChar(char a[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("|%c| ", a[i]);
    }
}

/// 7
int InsertarOrdenado(char a[], int cantidad, char elemento) {
    int i = cantidad - 1;
    while (i >= 0 && elemento < a[i]) {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = elemento;
    return cantidad + 1;
}

/// 8
int MaximoCaracter(int a[], int cantidad) {
    int mayor = a[0];
    for (int i = 1; i < cantidad; i++) {
        if (mayor < a[i]) {
            mayor = a[i];
        }
    }
    return mayor;
}

/// 9
void Capicua(int a[], int cantidad) {
    Pila pila, AUX, AUX2, AUX3;
    inicpila(&pila);
    inicpila(&AUX);
    inicpila(&AUX2);
    inicpila(&AUX3);

    for (int i = 0; i < cantidad; i++) {
        apilar(&pila, a[i]);
    }

    while (!pilavacia(&pila)) {
        apilar(&AUX, desapilar(&pila));
        if (!pilavacia(&pila)) {
            apilar(&AUX2, desapilar(&pila));
        }
    }

    while (!pilavacia(&AUX2)) {
        apilar(&pila, desapilar(&AUX2));
    }

    while (!pilavacia(&AUX) && tope(&pila) == tope(&AUX)) {
        apilar(&AUX2, desapilar(&AUX));
        apilar(&AUX3, desapilar(&pila));
    }

    if (pilavacia(&pila))
        printf("La pila es capicua.\n");
    else
        printf("La pila no es capicua.\n");
}

/// 10
void invertirArregloEnteros(int a[], int cantidad) {
    int aux, j = cantidad - 1;
    for (int i = 0; i < cantidad / 2; i++) {
        aux = a[i];
        a[i] = a[j];
        a[j] = aux;
        j--;
    }
}

/// 11
void OrdenamientoPorSeleccion(int a[], int cantidad) {
    int posmenor;
    int aux;
    int i = 0;

    while (i < cantidad - 1) {
        posmenor = encontrarMenorEntero(a, cantidad, i);
        aux = a[posmenor];
        a[posmenor] = a[i];
        a[i] = aux;
        i++;
    }
}
int encontrarMenorEntero(int a[], int cantidad, int pos) {
    int menor = a[pos];
    int posmenor = pos;
    for (int i = pos + 1; i < cantidad; i++) {
        if (menor > a[i]) {
            menor = a[i];
            posmenor = i;
        }
    }
    return posmenor;
}

/// 12
void OrdenamientoPorInsercion(int a[], int cantidad) {
    for (int i = 1; i < cantidad; i++) {
        int elemento = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > elemento) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = elemento;
    }
}

/// 13
void Juntar2Arreglos(char a[], char b[], int cantidad, int cantidad2, char c[]) {
    for (int i = 0; i < cantidad; i++) {
        c[i] = a[i];
    }
    for (int i = 0; i < cantidad2; i++) {
        c[cantidad + i] = b[i];
    }
}
void OrdenamientoPorSeleccionChar(char a[], int cantidad) {
    int posmenor;
    char aux;
    int i = 0;
    while (i < cantidad) {
        posmenor = encontrarMenorChar(a, cantidad, i);
        aux = a[posmenor];
        a[posmenor] = a[i];
        a[i] = aux;
        i++;
    }
}
int encontrarMenorChar(char a[], int cantidad, int pos) {
    char menor = a[pos];
    int posmenor = pos;
    for (int i = pos + 1; i < cantidad; i++) {
        if (menor > a[i]) {
            menor = a[i];
            posmenor = i;
        }
    }
    return posmenor;
}

/// 14
void sumatoria13(int a[], int cantidad) {
    for (int i = 1; i < cantidad; i++) {
        a[i] = a[i] + a[i - 1];
    }
}









