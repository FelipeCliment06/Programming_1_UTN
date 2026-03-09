#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

char nombreArchivo [] = {"archivo"};
char archivoAlumno [] = {"alumnos"};

typedef struct
{
    int legajo;
    char nombreYapellido[30];
    int edad;
    int anio;
} Alumno;

///prototipado
///1
void cargarAlFinal(char nombreArchivo[], int num);
void cargarVarios(char nombreArchivo[]);
///2
void formatearArchivo(char nombreArchivo[]);
void mostrarArchivoInt(char nombreArchivo[]);
///3
int retornarCantDeRegistro(char nombreArchivo[]);
///4
Alumno cargar1Alumno();
void cargarAlumnos(char archivoAlumno[]);
///5
void mostrarAlumnos(char archivoAlumno[]);
void mostra1Alumno(Alumno a);
///6
void cargar1AlumnoAlFinal(char archivoAlumno[]);
///7
void pasarLegajosAP(char archivoAlumno[], Pila *A);
///8
int cantMayoresDeEdadEspecific(char archivoAlumno[], int edadEspe);
///9
void mostrarNombre(Alumno a);
void mostrarNombresAlumnosRangoEdad(char archivoAlumno[], int edadMenor, int edadMayor);
///10
Alumno encontrarMayor(char archivoAlumno[]);
///11
int cantXAnioSpecific(char archivoAlumno[], int anio);
///12
int cargarArrAlumno(int dim, Alumno alum[dim]);
void mostraArrAlumno(int validos, Alumno alum[validos]);
void copiarArrEnArch(int validos, Alumno alum[validos], char archivoAlumno[]);
int pasarDeArchAArrAnioEspe(int dim, Alumno alumAnio[dim], char archivoAlumno[], int anio);
///13
int cantidadDeRegistros(char archivoAlumno[], int tamanio);
///14
void mostrarRegistroPedido(char archivoAlumno[], int ubicacion);
///15 (comentado)
/*void modificarCamposDe1Alumno(Alumno a);
void modificar1registro(char archivoAlumno[], int ubicacio);
void modificarTodosLosRegistros(char archivoAlumno[]);*/
///16
void invertirArchivo(char archivoAlumno[]);

int main()
{
    int x;
    int num = 10;
    int cant;
    int dim = 100;
    int validos1;
    int ubicacion;
    Pila A;
    inicpila(&A);
    int edadEspe;
    int mayores;
    int edadMayor, edadMenor;
    Alumno alumnito;
    Alumno alumanio[dim];
    int anio;
    int validos;
    Alumno alum[dim];

    do
    {
        printf("\nEJERCICIOS\nPOINT 1_Agregar al final.\nPOINT 2_Mostrar Archivo\nPOINT 3_Cantidad total de registros.\nPOINT 4_Cargar Alumnos.\nPOINT 5_Mostrar Archivo Alumnos.\nPOINT 6_Cargar 1 Alumno en Archivo.\nPOINT 7_Pasar Legajos a Pila Mayores de edad.\nPOINT 8_Cantidad de Alumnos mayores a edad especifica.\nPOINT 9_Mostrar Nombres por rango de edad.\nPOINT 10\nPOINT 11\nPOINT 12\nPOINT 13\nPOINT 14\nPOINT 15\nPOINT 16\nPOINT 17\n");
        scanf("%d", &x);

        switch(x)
        {
            case 1: ///Hacer una función que agregue un elemento al final de un archivo.
                formatearArchivo(nombreArchivo);
                cargarAlFinal(nombreArchivo, num);
                mostrarArchivoInt(nombreArchivo);
                break;

            case 2: ///Hacer una función que muestre por pantalla el contenido de un archivo.
                formatearArchivo(nombreArchivo);
                cargarVarios(nombreArchivo);
                mostrarArchivoInt(nombreArchivo);
                break;

            case 3: ///Hacer una función que retorne la cantidad de registros que contiene un archivo.
                formatearArchivo(nombreArchivo);
                cargarVarios(nombreArchivo);
                cant = retornarCantDeRegistro(nombreArchivo);
                printf("\nLa cantidad de registros es %d\n", cant);
                break;

            case 4: ///Crear una función que cargue un archivo de alumnos.
                formatearArchivo(archivoAlumno);
                cargarAlumnos(archivoAlumno);
                break;

            case 5: ///Crear una función que muestre por pantalla los registros de un archivo de alumnos.
                mostrarAlumnos(archivoAlumno);
                break;

            case 6: ///Agregar de a un elemento al final del archivo.
                cargar1AlumnoAlFinal(archivoAlumno);
                mostrarAlumnos(archivoAlumno);
                break;

            case 7: ///Pasar a una pila los legajos de alumnos mayores de edad.
                pasarLegajosAP(archivoAlumno, &A);
                mostrar(&A);
                break;

            case 8: ///Contar alumnos mayores a edad específica.
                printf("Ingrese la edad que desea: ");
                scanf("%d", &edadEspe);
                mayores = cantMayoresDeEdadEspecific(archivoAlumno, edadEspe);
                printf("La cantidad de mayores a la edad %d son %d\n", edadEspe, mayores);
                break;

            case 9: ///Mostrar nombres de alumnos en rango de edad.
                printf("Ingrese edades desde: ");
                scanf("%d", &edadMenor);
                printf("Hasta: ");
                scanf("%d", &edadMayor);
                printf("Los nombres de los alumnos dentro de ese rango:\n");
                mostrarNombresAlumnosRangoEdad(archivoAlumno, edadMenor, edadMayor);
                break;

            case 10: ///Mostrar datos del alumno de mayor edad.
                alumnito = encontrarMayor(archivoAlumno);
                printf("El alumno de mayor edad es:\n");
                mostra1Alumno(alumnito);
                break;

            case 11: ///Contar cantidad de alumnos que cursan un determinado año.
                printf("Ingrese el año que desea: ");
                scanf("%d", &anio);
                cant = cantXAnioSpecific(archivoAlumno, anio);
                printf("Hay %d alumnos que cursan %d\n", cant, anio);
                break;

            case 12: ///Copiar arreglo en archivo y filtrar por año.
                printf("Cargando arreglo de alumnos\n\n");
                validos = cargarArrAlumno(dim, alum);
                printf("Mostrando arreglo cargado:\n");
                mostraArrAlumno(validos, alum);
                printf("\nCopiando arreglo en archivo alumnos:\n");
                copiarArrEnArch(validos, alum, archivoAlumno);
                printf("Mostrando archivo alumnos:\n");
                mostrarAlumnos(archivoAlumno);
                printf("\nPasar a arreglo por año:\n");
                printf("Ingrese el año que desea: ");
                scanf("%d", &anio);
                validos1 = pasarDeArchAArrAnioEspe(dim, alumanio, archivoAlumno, anio);
                mostraArrAlumno(validos1, alumanio);
                break;

            case 13: ///Cantidad de registros usando fseek y ftell.
                cant = cantidadDeRegistros(archivoAlumno, sizeof(Alumno));
                printf("La cantidad de registros es %d\n", cant);
                break;

            case 14: ///Mostrar registro pedido por número.
                printf("Ingrese la ubicación que quiere visualizar (0-based): ");
                scanf("%d", &ubicacion);
                mostrarRegistroPedido(archivoAlumno, ubicacion);
                break;

            case 16: ///Invertir archivo de alumnos.
                invertirArchivo(archivoAlumno);
                printf("Archivo invertido:\n");
                mostrarAlumnos(archivoAlumno);
                break;

            case 0:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opción inválida\n");
                break;
        }

    } while(x != 0);

    return 0;
}

///1
void cargarAlFinal(char nombreArchivo[], int num)
{
    FILE * buff = fopen(nombreArchivo, "ab");
    if(buff != NULL)
    {
        fwrite(&num, sizeof(int), 1, buff);
        fclose(buff);
    }
    else
    {
        printf("No se pudo abrir el archivo para escribir\n");
    }
}

void cargarVarios(char nombreArchivo[])
{
    int control = 1;
    int num;

    while(control == 1)
    {
        printf("Ingrese un número: ");
        scanf("%d", &num);
        cargarAlFinal(nombreArchivo, num);

        printf("Desea ingresar otro número? (1/0): ");
        int aux;
        scanf("%d", &aux);
        control = aux;
    }
}

///2
void formatearArchivo(char nombreArchivo[])
{
    char controlFormat;
    printf("Quiere formatear el archivo? s o n: ");
    getchar(); // limpiar buffer
    scanf("%c", &controlFormat);
    if(controlFormat == 's' || controlFormat == 'S')
    {
        FILE* buff = fopen(nombreArchivo, "wb");
        if(buff != NULL)
        {
            fclose(buff);
            printf("Archivo formateado correctamente\n");
        }
        else
        {
            printf("No se pudo abrir el archivo para formatear\n");
        }
    }
}

void mostrarArchivoInt(char nombreArchivo[])
{
    FILE * buff = fopen(nombreArchivo, "rb");
    int num;
    if(buff != NULL)
    {
        while(fread(&num, sizeof(int), 1, buff) > 0)
        {
            printf("%d \n", num);
        }
        fclose(buff);
    }
    else
    {
        printf("No se pudo abrir el archivo para leer\n");
    }
}

///3
int retornarCantDeRegistro(char nombreArchivo[])
{
    int i = 0;
    FILE *buff = fopen(nombreArchivo, "rb");
    int num;
    if(buff != NULL)
    {
        while(fread(&num, sizeof(int), 1, buff) > 0)
        {
            i++;
        }
        fclose(buff);
    }
    return i;
}

///4
Alumno cargar1Alumno()
{
    Alumno a;

    printf("Ingrese el legajo: ");
    scanf("%d", &a.legajo);
    getchar(); // limpiar buffer

    printf("Ingrese nombre y apellido: ");
    fgets(a.nombreYapellido, sizeof(a.nombreYapellido), stdin);
    a.nombreYapellido[strcspn(a.nombreYapellido, "\n")] = 0; // quita salto de línea

    printf("Ingrese la edad: ");
    scanf("%d", &a.edad);

    printf("Ingrese el año que cursa: ");
    scanf("%d", &a.anio);
    getchar();

    return a;
}

void cargarAlumnos(char archivoAlumno[])
{
    int control = 1;
    Alumno a;
    int i = 0;
    FILE * buff = fopen(archivoAlumno, "ab");
    if(buff != NULL)
    {
        while(control == 1 && i < 5)
        {
            a = cargar1Alumno();
            fwrite(&a, sizeof(Alumno), 1, buff);
            i++;

            if(i < 5)
            {
                printf("Desea seguir ingresando? (1/0): ");
                int aux;
                scanf("%d", &aux);
                control = aux;
                getchar();
            }
            else
            {
                printf("Ya ingresaste 5, bobo\n");
            }
        }
        fclose(buff);
    }
    else
    {
        printf("No se pudo abrir el archivo para escribir\n");
    }
}

///5
void mostrarAlumnos(char archivoAlumno[])
{
    Alumno a;
    FILE * buff = fopen(archivoAlumno, "rb");
    if (buff != NULL)
    {
        while(fread(&a, sizeof(Alumno), 1, buff) > 0)
        {
            mostra1Alumno(a);
        }
        fclose(buff);
    }
    else
    {
        printf("No se pudo abrir el archivo para leer\n");
    }
}

void mostra1Alumno(Alumno a)
{
    printf("----------------------------------------\n");
    printf("Legajo: %d\n", a.legajo);
    printf("Nombre y apellido: %s\n", a.nombreYapellido);
    printf("Edad: %d\n", a.edad);
    printf("Año que cursa: %d\n", a.anio);
}

///6
void cargar1AlumnoAlFinal(char archivoAlumno[])
{
    Alumno a;
    int control = 1;
    FILE * buff = fopen(archivoAlumno, "ab");
    if(buff != NULL)
    {
        while(control == 1)
        {
            a = cargar1Alumno();
            fwrite(&a, sizeof(Alumno), 1, buff);

            printf("Desea seguir ingresando? (1/0): ");
            int aux;
            scanf("%d", &aux);
            control = aux;
            getchar();
        }
        fclose(buff);
    }
    else
    {
        printf("No se pudo abrir el archivo para escribir\n");
    }
}

///7
void pasarLegajosAP(char archivoAlumno[], Pila *A)
{
    Alumno a;
    FILE * buff = fopen(archivoAlumno, "rb");
    if(buff != NULL)
    {
        while(fread(&a, sizeof(Alumno), 1, buff) > 0)
        {
            if(a.edad >= 18)
            {
                apilar(A, a.legajo);
            }
        }
        fclose(buff);
    }
    else
    {
        printf("No se pudo abrir el archivo para leer\n");
    }
}

///8
int cantMayoresDeEdadEspecific(char archivoAlumno[], int edadEspe)
{
    Alumno a;
    int mayores = 0;
    FILE * buff = fopen(archivoAlumno, "rb");
    if(buff != NULL)
    {
        while(fread(&a, sizeof(Alumno), 1, buff) > 0)
        {
            if(a.edad >= edadEspe)
            {
                mayores++;
            }
        }
        fclose(buff);
    }
    else
    {
        printf("No se pudo abrir el archivo para leer\n");
    }
    return mayores;
}

///9
void mostrarNombre(Alumno a)
{
    printf("%s\n", a.nombreYapellido);
}

void mostrarNombresAlumnosRangoEdad(char archivoAlumno[], int edadMenor, int edadMayor)
{
    Alumno A;
    FILE * buff = fopen(archivoAlumno, "rb");
    if(buff != NULL)
    {
        while(fread(&A, sizeof(Alumno), 1, buff) > 0)
        {
            if(A.edad >= edadMenor && A.edad <= edadMayor)
            {
                mostrarNombre(A);
            }
        }
        fclose(buff);
    }
    else
    {
        printf("No se pudo abrir el archivo para leer\n");
    }
}

///10
Alumno encontrarMayor(char archivoAlumno[])
{
    Alumno a, mayor;
    FILE * buff = fopen(archivoAlumno, "rb");
    if (buff != NULL)
    {
        if(fread(&a, sizeof(Alumno), 1, buff) > 0)
        {
            mayor = a;
            while(fread(&a, sizeof(Alumno), 1, buff) > 0)
            {
                if(a.edad > mayor.edad)
                {
                    mayor = a;
                }
            }
        }
        fclose(buff);
    }
    else
    {
        printf("No se pudo abrir el archivo para leer\n");
    }
    return mayor;
}

///11
int cantXAnioSpecific(char archivoAlumno[], int anio)
{
    Alumno a;
    int count = 0;
    FILE * buff = fopen(archivoAlumno, "rb");
    if(buff != NULL)
    {
        while(fread(&a, sizeof(Alumno), 1, buff) > 0)
        {
            if(a.anio == anio)
            {
                count++;
            }
        }
        fclose(buff);
    }
    else
    {
        printf("No se pudo abrir el archivo para leer\n");
    }
    return count;
}

///12
int cargarArrAlumno(int dim, Alumno alum[dim])
{
    int i = 0;
    int control = 1;
    while(i < dim && control == 1)
    {
        alum[i] = cargar1Alumno();
        i++;

        printf("Desea seguir ingresando? (1/0): ");
        int aux;
        scanf("%d", &aux);
        control = aux;
        getchar();
    }
    return i;
}

void mostraArrAlumno(int validos, Alumno alum[validos])
{
    for(int i = 0; i < validos; i++)
    {
        mostra1Alumno(alum[i]);
    }
}

void copiarArrEnArch(int validos, Alumno alum[validos], char archivoAlumno[])
{
    FILE * buff = fopen(archivoAlumno, "wb");
    if (buff != NULL)
    {
        for(int i = 0; i < validos; i++)
        {
            fwrite(&alum[i], sizeof(Alumno), 1, buff);
        }
        fclose(buff);
    }
    else
    {
        printf("No se pudo abrir el archivo para escribir\n");
    }
}

int pasarDeArchAArrAnioEspe(int dim, Alumno alumAnio[dim], char archivoAlumno[], int anio)
{
    int i = 0;
    Alumno a;
    FILE * buff = fopen(archivoAlumno, "rb");
    if (buff != NULL)
    {
        while(fread(&a, sizeof(Alumno), 1, buff) > 0 && i < dim)
        {
            if(a.anio == anio)
            {
                alumAnio[i] = a;
                i++;
            }
        }
        fclose(buff);
    }
    else
    {
        printf("No se pudo abrir el archivo para leer\n");
    }
    return i;
}

///13
int cantidadDeRegistros(char archivoAlumno[], int tamanio)
{
    int cant = 0;
    FILE * buff = fopen(archivoAlumno, "rb");
    if (buff != NULL)
    {
        fseek(buff, 0, SEEK_END);
        cant = ftell(buff) / tamanio;
        fclose(buff);
    }
    else
    {
        printf("No se pudo abrir el archivo para leer\n");
    }
    return cant;
}

///14
void mostrarRegistroPedido(char archivoAlumno[], int ubicacion)
{
    Alumno a;
    int cant;
    FILE * buff = fopen(archivoAlumno, "rb");
    if(buff != NULL)
    {
        cant = cantidadDeRegistros(archivoAlumno, sizeof(Alumno));
        if(ubicacion >= 0 && ubicacion < cant)
        {
            fseek(buff, sizeof(Alumno) * ubicacion, SEEK_SET);
            fread(&a, sizeof(Alumno), 1, buff);
            mostra1Alumno(a);
        }
        else
        {
            printf("Ubicación fuera de rango\n");
        }
        fclose(buff);
    }
    else
    {
        printf("No se pudo abrir el archivo para leer\n");
    }
}

///16
void invertirArchivo(char archivoAlumno[])
{
    Alumno a;
    FILE * buff = fopen(archivoAlumno, "rb+");
    if(buff != NULL)
    {
        int cant = cantidadDeRegistros(archivoAlumno, sizeof(Alumno));
        int i = 0;
        int j = cant - 1;
        while(i < j)
        {
            fseek(buff, sizeof(Alumno) * i, SEEK_SET);
            fread(&a, sizeof(Alumno), 1, buff);

            Alumno a2;
            fseek(buff, sizeof(Alumno) * j, SEEK_SET);
            fread(&a2, sizeof(Alumno), 1, buff);

            fseek(buff, sizeof(Alumno) * i, SEEK_SET);
            fwrite(&a2, sizeof(Alumno), 1, buff);

            fseek(buff, sizeof(Alumno) * j, SEEK_SET);
            fwrite(&a, sizeof(Alumno), 1, buff);

            i++;
            j--;
        }
        fclose(buff);
    }
    else
    {
        printf("No se pudo abrir el archivo para invertir\n");
    }
}





