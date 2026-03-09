#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Prototipos

/// 1. Cargar alumnos (nombre, legajo, años), hasta que el usuario quiera o se complete el arreglo.
/// Retorna cantidad de alumnos cargados.
int cargarAlumnos(int dimF, int dimC, char arregloNombre[dimF][dimC], int arregloLegajo[], int arregloAnios[]);

/// 2. Buscar un legajo y devolver la posición. Si no está devuelve -1.
int buscarLegajo(int validos, int arregloLegajo[], int buscar);

/// 3. Mostrar un alumno dado la posición.
void mostrar1alumno(int dimC, char arregloNombre[][dimC], int arregloLegajo[], int arregloAnios[], int posicion);

/// 4. Intercambiar enteros y palabras.
void intercambiarEnterosDeArreglos(int arreglo[], int pos1, int pos2);
void intercambiarPalabras(int dimC, char palabra1[dimC], char palabra2[dimC]);

/// 4.1 Buscar posición del menor nombre en orden alfabético (para ordenación).
int posicionMenor(int validos, int dimC, char arregloNombre[validos][dimC], int pos);

/// 4.2 Ordenar por nombre (método selección).
void ordenarPorNombre(int validos, int dimC, char arregloNombre[validos][dimC], int arregloLegajo[], int arregloAnios[]);

/// 5. Mostrar todos los alumnos con sus datos (registros completos).
void mostrarArregloParaleloAlumnos(int validos, int dimC, char arregloNombre[validos][dimC], int arregloLegajo[], int arregloAnios[]);


int main()
{
    int legajos[20];
    char nombres[20][30];
    int anios[20];

    printf("=== Carga de alumnos ===\n");
    int validos = cargarAlumnos(20, 30, nombres, legajos, anios);

    // Buscar un legajo
    int buscar, resultado;
    printf("\nIngrese el legajo que quiere buscar: ");
    scanf("%d", &buscar);

    resultado = buscarLegajo(validos, legajos, buscar);
    if (resultado != -1)
    {
        printf("\nAlumno encontrado:\n");
        mostrar1alumno(30, nombres, legajos, anios, resultado);
    }
    else
    {
        printf("El legajo %d no esta en el listado.\n", buscar);
    }

    // Ordenar por nombre
    ordenarPorNombre(validos, 30, nombres, legajos, anios);

    printf("\nListado ordenado por nombre:\n");
    mostrarArregloParaleloAlumnos(validos, 30, nombres, legajos, anios);

    return 0;
}

/// 1. Cargar alumnos
int cargarAlumnos(int dimF, int dimC, char arregloNombre[dimF][dimC], int arregloLegajo[], int arregloAnios[])
{
    int i = 0;
    int control = 1;
    while (i < dimF && control == 1)
    {
        printf("\nAlumno %d\n", i + 1);

        printf("Ingrese nombre y apellido: ");
        fflush(stdin);
        fgets(arregloNombre[i], dimC, stdin);
        arregloNombre[i][strcspn(arregloNombre[i], "\n")] = 0; // quitar salto de línea

        printf("Ingrese años: ");
        scanf("%d", &arregloAnios[i]);

        printf("Ingrese numero de legajo: ");
        scanf("%d", &arregloLegajo[i]);

        while(getchar() != '\n'); // limpiar buffer

        printf("Presione 1 para seguir cargando o 0 para terminar: ");
        scanf("%d", &control);
        while(getchar() != '\n'); // limpiar buffer
        i++;
    }
    return i;
}

/// 2. Buscar legajo
int buscarLegajo(int validos, int arregloLegajo[], int buscar)
{
    for (int i = 0; i < validos; i++)
    {
        if (arregloLegajo[i] == buscar)
            return i;  // Retorna posición válida
    }
    return -1; // No encontrado
}

/// 3. Mostrar un alumno (por posición)
void mostrar1alumno(int dimC, char arregloNombre[][dimC], int arregloLegajo[], int arregloAnios[], int posicion)
{
    printf("Legajo: %d\n", arregloLegajo[posicion]);
    printf("Nombre: %s\n", arregloNombre[posicion]);
    printf("Anios: %d\n", arregloAnios[posicion]);
}

/// 4. Intercambiar palabras
void intercambiarPalabras(int dimC, char palabra1[dimC], char palabra2[dimC])
{
    char aux[dimC];
    strcpy(aux, palabra1);
    strcpy(palabra1, palabra2);
    strcpy(palabra2, aux);
}

/// 4. Intercambiar enteros en arreglo
void intercambiarEnterosDeArreglos(int arreglo[], int pos1, int pos2)
{
    int aux = arreglo[pos1];
    arreglo[pos1] = arreglo[pos2];
    arreglo[pos2] = aux;
}

/// 4.1 Encontrar posición de la palabra menor alfabeticamente desde pos (para selección)
int posicionMenor(int validos, int dimC, char arregloNombre[validos][dimC], int pos)
{
    int posMenor = pos;
    for (int i = pos + 1; i < validos; i++)
    {
        // strcmp normal, orden alfabético sensible a mayúsculas
        if (strcmp(arregloNombre[i], arregloNombre[posMenor]) < 0)
        {
            posMenor = i;
        }
    }
    return posMenor;
}

/// 4.2 Ordenar por nombre (selección)
void ordenarPorNombre(int validos, int dimC, char arregloNombre[validos][dimC], int arregloLegajo[], int arregloAnios[])
{
    for (int i = 0; i < validos - 1; i++)
    {
        int menor = posicionMenor(validos, dimC, arregloNombre, i);
        if (menor != i)
        {
            intercambiarPalabras(dimC, arregloNombre[i], arregloNombre[menor]);
            intercambiarEnterosDeArreglos(arregloLegajo, i, menor);
            intercambiarEnterosDeArreglos(arregloAnios, i, menor);
        }
    }
}

/// 5. Mostrar todos los alumnos uno por uno
void mostrarArregloParaleloAlumnos(int validos, int dimC, char arregloNombre[validos][dimC], int arregloLegajo[], int arregloAnios[])
{
    for (int i = 0; i < validos; i++)
    {
        printf("------------------------------\n");
        mostrar1alumno(dimC, arregloNombre, arregloLegajo, arregloAnios, i);
    }
}


