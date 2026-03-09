#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int matricula;
    char nombre[30];
    char genero; // m, f, x
} Alumno;

/// Prototipos
Alumno cargar1Alumno();
int cargarAlumnos(int dim, Alumno alum1[dim]);

void mostrar1alumno(Alumno alum1);
void mostrarAlumnos(int validos, Alumno alum1[validos]);

int buscarMatricula(int validos, Alumno alum1[validos], int buscado);
void mostrarXMatricula(int validos, Alumno alum1[validos], int buscado);

void ordenarXseleccion(int validos, Alumno alum1[validos]);
int encontrarMenor(int validos, Alumno alum1[validos], int pos);

void mostrarXgenero(int validos, Alumno alum1[validos], char genero);

int insertarXmatricula(int validos, Alumno alum1[validos + 1], Alumno alum2);
void intercambiarAlumnosEnArreglo(Alumno alum1[], int pos1, int pos2);

void ordenarXinsercionNombre(int validos, Alumno alum1[validos]);
void insertarEnOrden(int validos, Alumno alum1[validos], Alumno alum2, int pos);

int cantXgenero(int validos, Alumno alum1[validos], char genero);

int main() {
    int x, dim = 30, validos = 0, buscado, cant = 0;
    char genero;
    Alumno alum1[dim];
    Alumno alum2;

    do {
        printf("\n--- MENU DE OPCIONES ---\n");
        printf("1 - Cargar alumnos\n");
        printf("2 - Mostrar todos los alumnos\n");
        printf("3 - Mostrar alumno por matricula\n");
        printf("4 - Ordenar alumnos por matricula (seleccion)\n");
        printf("5 - Mostrar alumnos por género\n");
        printf("6 - Insertar alumno ordenado por matricula\n");
        printf("7 - Ordenar alumnos por nombre (insercion)\n");
        printf("8 - Contar alumnos por genero\n");
        printf("0 - Salir\n");
        printf("Ingrese opcion: ");
        scanf("%d", &x);
        getchar(); // limpia buffer

        switch (x) {
        case 1:
            validos = cargarAlumnos(dim, alum1);
            break;

        case 2:
            if (validos == 0) {
                printf("Primero debe cargar alumnos (opcion 1).\n");
            } else {
                mostrarAlumnos(validos, alum1);
            }
            break;

        case 3:
            if (validos == 0) {
                printf("Primero debe cargar alumnos (opcion 1).\n");
            } else {
                printf("Ingrese la matricula a buscar: ");
                scanf("%d", &buscado);
                getchar();
                mostrarXMatricula(validos, alum1, buscado);
            }
            break;

        case 4:
            if (validos == 0) {
                printf("Primero debe cargar alumnos (opcion 1).\n");
            } else {
                ordenarXseleccion(validos, alum1);
                printf("Alumnos ordenados por matricula:\n");
                mostrarAlumnos(validos, alum1);
            }
            break;

        case 5:
            if (validos == 0) {
                printf("Primero debe cargar alumnos (opcion 1).\n");
            } else {
                printf("Ingrese el genero a mostrar (M/F/X): ");
                scanf("%c", &genero);
                getchar();
                mostrarXgenero(validos, alum1, genero);
            }
            break;

        case 6:
            if (validos == 0) {
                printf("Primero debe cargar alumnos (opcion 1).\n");
            } else if (validos == dim) {
                printf("Arreglo lleno, no se puede insertar.\n");
            } else {
                printf("Ingrese datos del alumno a insertar:\n");
                alum2 = cargar1Alumno();
                validos = insertarXmatricula(validos, alum1, alum2);
                printf("Alumno insertado.\n");
                mostrarAlumnos(validos, alum1);
            }
            break;

        case 7:
            if (validos == 0) {
                printf("Primero debe cargar alumnos (opcion 1).\n");
            } else {
                ordenarXinsercionNombre(validos, alum1);
                printf("Alumnos ordenados por nombre:\n");
                mostrarAlumnos(validos, alum1);
            }
            break;

        case 8:
            if (validos == 0) {
                printf("Primero debe cargar alumnos (opcion 1).\n");
            } else {
                printf("Ingrese genero para contar (M/F/X): ");
                scanf("%c", &genero);
                getchar();
                cant = cantXgenero(validos, alum1, genero);
                printf("Cantidad de alumnos de genero %c: %d\n", genero, cant);
            }
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

/// 1. Cargar un alumno
Alumno cargar1Alumno() {
    Alumno alum1;
    printf("Ingrese la matricula del alumno: ");
    scanf("%d", &alum1.matricula);
    getchar();
    printf("Ingrese el nombre del alumno: ");
    fgets(alum1.nombre, 30, stdin);
    alum1.nombre[strcspn(alum1.nombre, "\n")] = 0; // quita salto de linea
    printf("Ingrese el genero del alumno | M | F | X |: ");
    scanf("%c", &alum1.genero);
    getchar();
    return alum1;
}

/// 1. Cargar varios alumnos
int cargarAlumnos(int dim, Alumno alum1[dim]) {
    int control = 1;
    int i = 0;
    while (i < dim && control == 1) {
        printf("\nAlumno %d:\n", i + 1);
        alum1[i] = cargar1Alumno();

        printf("Desea seguir ingresando? (1=si / 0=no): ");
        scanf("%d", &control);
        getchar();
        i++;
    }
    return i;
}

/// 2. Mostrar un alumno
void mostrar1alumno(Alumno alum1) {
    printf("MATRICULA: %d\n", alum1.matricula);
    printf("NOMBRE: %s\n", alum1.nombre);
    printf("GENERO: %c\n", alum1.genero);
}

/// 2. Mostrar todos los alumnos
void mostrarAlumnos(int validos, Alumno alum1[validos]) {
    for (int i = 0; i < validos; i++) {
        printf("Alumno %d:\n", i + 1);
        mostrar1alumno(alum1[i]);
        printf("\n");
    }
}

/// 3. Buscar matrícula
int buscarMatricula(int validos, Alumno alum1[validos], int buscado) {
    for (int i = 0; i < validos; i++) {
        if (alum1[i].matricula == buscado)
            return i;
    }
    return -1;
}

/// 3. Mostrar alumno por matrícula
void mostrarXMatricula(int validos, Alumno alum1[validos], int buscado) {
    int pos = buscarMatricula(validos, alum1, buscado);
    if (pos != -1) {
        mostrar1alumno(alum1[pos]);
    } else {
        printf("Alumno con matricula %d no encontrado.\n", buscado);
    }
}

/// 4. Ordenar por matrícula (selección)
void ordenarXseleccion(int validos, Alumno alum1[validos]) {
    for (int i = 0; i < validos - 1; i++) {
        int posmenor = encontrarMenor(validos, alum1, i);
        if (posmenor != i) {
            Alumno aux = alum1[i];
            alum1[i] = alum1[posmenor];
            alum1[posmenor] = aux;
        }
    }
}

/// 4. Encontrar menor matrícula desde pos
int encontrarMenor(int validos, Alumno alum1[validos], int pos) {
    int posmenor = pos;
    for (int i = pos + 1; i < validos; i++) {
        if (alum1[i].matricula < alum1[posmenor].matricula) {
            posmenor = i;
        }
    }
    return posmenor;
}

/// 5. Mostrar alumnos por género
void mostrarXgenero(int validos, Alumno alum1[validos], char genero) {
    int found = 0;
    for (int i = 0; i < validos; i++) {
        if (alum1[i].genero == genero) {
            mostrar1alumno(alum1[i]);
            printf("\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No hay alumnos con genero %c.\n", genero);
    }
}

/// 6. Insertar alumno ordenado por matrícula
int insertarXmatricula(int validos, Alumno alum1[validos + 1], Alumno alum2) {
    alum1[validos] = alum2; // inserto al final

    int i = validos - 1;
    while (i >= 0 && alum1[i].matricula > alum2.matricula) {
        alum1[i + 1] = alum1[i]; // corro uno a la derecha
        i--;
    }
    alum1[i + 1] = alum2;
    return validos + 1;
}

/// 7. Ordenar por nombre (inserción)
void ordenarXinsercionNombre(int validos, Alumno alum1[validos]) {
    for (int i = 1; i < validos; i++) {
        Alumno aux = alum1[i];
        int j = i - 1;
        while (j >= 0 && strcasecmp(alum1[j].nombre, aux.nombre) > 0) {
            alum1[j + 1] = alum1[j];
            j--;
        }
        alum1[j + 1] = aux;
    }
}

/// 8. Contar alumnos por género
int cantXgenero(int validos, Alumno alum1[validos], char genero) {
    int cant = 0;
    for (int i = 0; i < validos; i++) {
        if (alum1[i].genero == genero) {
            cant++;
        }
    }
    return cant;
}










