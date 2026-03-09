#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <conio.h>
#define CLEAR_SCREEN system("cls")
#else
#include <unistd.h>
#define CLEAR_SCREEN system("clear")
#endif

const int MaxCP = 30;

///7
int CargarArregloDePalabras(int DimF, int MaxCP, char string[DimF][MaxCP]);
///8
void MostrarArregloDePalabras(int validos, int MaxCP, char string[validos][MaxCP]);
///9
int EncontrarStrings(int validos, int MaxCP, char string[validos][MaxCP], char buscar[]);
///10 (pendiente)
///11
void OrdenarAlfabeticamente(int validos, int MaxCP, char string[validos][MaxCP]);
void ordenamientoseleccion(int validos, int MaxCP, char string[validos][MaxCP]);
int EncontrarMenorStrings(int validos, int MaxCP, char string[validos][MaxCP], int pos);

int main()
{
    int DimF;
    printf("Ingrese la cantidad de filas (maximo 100): ");
    scanf("%d", &DimF);
    while(getchar() != '\n'); // Limpiar buffer

    if (DimF <= 0 || DimF > 100) {
        printf("Cantidad invalida. Usando valor por defecto 10.\n");
        DimF = 10;
    }

    char string[DimF][MaxCP];
    char buscar[MaxCP];
    int cantCargados, validos, posEncontrado;

    int x;

    do {
        printf("\n\nMENU EJERCICIOS:\n");
        printf("1.- Cargar arreglo de palabras y devolver cantidad\n");
        printf("2.- Mostrar arreglo de palabras\n");
        printf("3.- Buscar palabra en arreglo\n");
        printf("4.- Buscar palabra en arreglo ordenado (pendiente)\n");
        printf("5.- Ordenar alfabeticamente (metodo burbuja)\n");
        printf("6.- Ordenar alfabeticamente (seleccion)\n");
        printf("0.- Salir\n");
        printf("Ingrese opcion: ");
        scanf("%d", &x);
        while(getchar() != '\n'); // limpiar buffer

        switch (x) {
            case 1:
                // 7. Cargar arreglo de palabras, retornar cantidad cargada
                cantCargados = CargarArregloDePalabras(DimF, MaxCP, string);
                printf("Se cargaron %d palabras.\n", cantCargados);
                break;

            case 2:
                // 8. Mostrar arreglo de palabras
                validos = CargarArregloDePalabras(DimF, MaxCP, string);
                MostrarArregloDePalabras(validos, MaxCP, string);
                break;

            case 3:
                // 9. Buscar palabra en arreglo
                validos = CargarArregloDePalabras(DimF, MaxCP, string);
                MostrarArregloDePalabras(validos, MaxCP, string);
                printf("Ingrese la palabra a buscar: ");
                fgets(buscar, MaxCP, stdin);
                buscar[strcspn(buscar, "\n")] = 0; // quitar \n

                posEncontrado = EncontrarStrings(validos, MaxCP, string, buscar);
                if (posEncontrado == -1)
                    printf("La palabra '%s' no fue encontrada.\n", buscar);
                else
                    printf("La palabra '%s' fue encontrada en la posicion %d.\n", buscar, posEncontrado + 1);
                break;

            case 4:
                printf("Ejercicio 4 pendiente.\n");
                break;

            case 5:
                // 11. Ordenar alfabeticamente (burbuja)
                validos = CargarArregloDePalabras(DimF, MaxCP, string);
                MostrarArregloDePalabras(validos, MaxCP, string);
                OrdenarAlfabeticamente(validos, MaxCP, string);
                printf("Arreglo ordenado alfabeticamente (burbuja):\n");
                MostrarArregloDePalabras(validos, MaxCP, string);
                break;

            case 6:
                // 11. Ordenar alfabeticamente (seleccion)
                validos = CargarArregloDePalabras(DimF, MaxCP, string);
                MostrarArregloDePalabras(validos, MaxCP, string);
                ordenamientoseleccion(validos, MaxCP, string);
                printf("Arreglo ordenado alfabeticamente (seleccion):\n");
                MostrarArregloDePalabras(validos, MaxCP, string);
                break;

            case 0:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion invalida.\n");
                break;
        }

    } while (x != 0);

    return 0;
}

int CargarArregloDePalabras(int DimF, int MaxCP, char string[DimF][MaxCP]) {
    int f = 0;
    char control = 's';
    while (f < DimF && (control == 's' || control == 'S')) {
        printf("Ingrese una palabra: ");
        fgets(string[f], MaxCP, stdin);
        string[f][strcspn(string[f], "\n")] = 0; // quita salto de linea
        f++;
        if (f < DimF) {
            printf("Desea seguir cargando? (s/n): ");
            scanf(" %c", &control);
            while(getchar() != '\n'); // limpiar buffer
        }
    }
    return f;
}

void MostrarArregloDePalabras(int validos, int MaxCP, char string[validos][MaxCP]) {
    for (int f = 0; f < validos; f++) {
        printf("Palabra %d: %s\n", f + 1, string[f]);
    }
}

int EncontrarStrings(int validos, int MaxCP, char string[validos][MaxCP], char buscar[]) {
    for (int f = 0; f < validos; f++) {
#ifdef _WIN32
        if (_stricmp(buscar, string[f]) == 0) // Windows case-insensitive compare
#else
        if (strcasecmp(buscar, string[f]) == 0) // Linux/macOS case-insensitive compare
#endif
            return f;
    }
    return -1;
}

void OrdenarAlfabeticamente(int validos, int MaxCP, char string[validos][MaxCP]) {
    int f, x;
    char aux[MaxCP];
    for (f = 0; f < validos - 1; f++) {
        for (x = f + 1; x < validos; x++) {
#ifdef _WIN32
            if (_stricmp(string[x], string[f]) < 0)
#else
            if (strcasecmp(string[x], string[f]) < 0)
#endif
            {
                strcpy(aux, string[f]);
                strcpy(string[f], string[x]);
                strcpy(string[x], aux);
            }
        }
    }
}

void ordenamientoseleccion(int validos, int MaxCP, char string[validos][MaxCP]) {
    int f;
    char aux[MaxCP];
    for (f = 0; f < validos - 1; f++) {
        int posmenor = EncontrarMenorStrings(validos, MaxCP, string, f);
        strcpy(aux, string[posmenor]);
        strcpy(string[posmenor], string[f]);
        strcpy(string[f], aux);
    }
}

int EncontrarMenorStrings(int validos, int MaxCP, char string[validos][MaxCP], int pos) {
    int posmenor = pos;
    for (int i = pos + 1; i < validos; i++) {
#ifdef _WIN32
        if (_stricmp(string[i], string[posmenor]) < 0)
#else
        if (strcasecmp(string[i], string[posmenor]) < 0)
#endif
        {
            posmenor = i;
        }
    }
    return posmenor;
}





