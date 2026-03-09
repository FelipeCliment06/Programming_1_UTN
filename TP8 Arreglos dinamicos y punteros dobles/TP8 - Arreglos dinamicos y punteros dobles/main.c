#include <stdio.h>
#include <stdlib.h>

char nombreArchivoAlumnos[]= {"Archiveiro"};

typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;
} Alumno;


///2.a
void mostrarArregloEnteros(int validos,int arreglo[]);

int cargarY_DevolverCantidadEnteros(int dim,int a[]);

int contarElementosPares(int validos,int arreglo[validos]);

void pasarElementosParesAarrayDinamico(int validos,int a[],int validos2,int ad[]);
///2.b
int * crearYpasarElementosParesAarrayDinamico(int validos,int a[],int validos2);
///2.c
void crearYpasarElementosParesAarrayDinamicoPtroDoble(int validos,int a[],int validos2,int ** a2);

///3.a
int cantRegistrosArchivo(char nombreArchivo[],int divisor);

void pasarAlumnosDeArchivoAarreglo(char nombreArchivoAlumnos[],Alumno arregloAlumno[],int validos);

void mostrar1alumno(Alumno A);

void mostrarArregloAlumnos(int validos,Alumno arregloAlumnos[]);

///3.b

Alumno * arregloDinamicoAlumnosDesdeArchivoCretorno(int validos,char nombreArchivoAlumnos[]);

///3.c

void arregloDinamicoAlumnosDesdeArchivoPtroDoble(char nombreArchivoAlumnos[],int validos,Alumno**alumnos);

///4

int * redimensionarArregloDinamico(int * arregloDinamico,int validosNuevo);

int main()
{
    int valor=0;
    int*pint=&valor;
    int**ppint=&pint;

    char opcion2;
    int opcion,control=1;
    int * a2;
    int arreglo2[20];
    int validos2,cantPares;

    char opcion3;
    Alumno * a3;
    int validos3;

    while(control==1)
    {
        printf("Ingrese el ejercicio que quiere realizar: ");
        scanf("%i",&opcion);

        switch(opcion)
        {
        case 1:

            printf("Ingrese el primer valor: \n");
            scanf("%i",&*pint);
            printf("El primer valor: %i\n",*pint);

            printf("Ingrese el segundo valor: \n");
            scanf("%i",&**ppint);
            printf("El segundo valor %i\n",*pint);

            printf("La direccion de memoria de la variable comun: %p\n",&valor);
            printf("La direccion de memoria del puntero: %p\n",&pint);
            printf("La direccion de memoria del puntero doble: %p",&ppint);
            break;

        case 2:
            printf("Ingrese a para trabajar con array estatico,b para trabajar con array dinamico o c para trabajar con array dinamico y puntero doble: ");
            fflush(stdin);
            scanf("%c",&opcion2);
            switch (opcion2)
            {
            case 'a':

                validos2=cargarY_DevolverCantidadEnteros(20,arreglo2);
                printf("El arreglo estatico cargado: \n");
                mostrarArregloEnteros(validos2,arreglo2);
                cantPares=contarElementosPares(validos2,arreglo2);
                a2=(int*)malloc(cantPares*(sizeof(int)));
                pasarElementosParesAarrayDinamico(validos2,arreglo2,cantPares,a2);
                printf("El arreglo dinamico cargado con pares: \n");
                mostrarArregloEnteros(cantPares,a2);
                break;

            case 'b':

                validos2=cargarY_DevolverCantidadEnteros(20,arreglo2);
                printf("El arreglo estatico cargado: \n");
                mostrarArregloEnteros(validos2,arreglo2);
                cantPares=contarElementosPares(validos2,arreglo2);
                a2=crearYpasarElementosParesAarrayDinamico(validos2,arreglo2,cantPares);
                printf("El arreglo dinamico cargado con pares: \n");
                mostrarArregloEnteros(cantPares,a2);
                break;

            case 'c':

                validos2=cargarY_DevolverCantidadEnteros(20,arreglo2);
                printf("El arreglo estatico cargado: \n");
                mostrarArregloEnteros(validos2,arreglo2);
                cantPares=contarElementosPares(validos2,arreglo2);
                crearYpasarElementosParesAarrayDinamicoPtroDoble(validos2,arreglo2,cantPares,&a2);
                printf("El arreglo dinamico cargado con pares: \n");
                mostrarArregloEnteros(cantPares,a2);
                break;

            default:

                printf("Ingreso una opcion incorrecta.");
                break;
            }
        case 3: ///Hacer una función que copie los registros de todos los alumnos existentes en el archivo en un arreglo del tamaño justo,
                ///creando el arreglo dinámico en el Main antes de la invocación de la función.

            printf("Ingrese a para trabajar con malloc en main,b para trabajar con malloc en funcion o c para trabajar con ptro doble: ");
            fflush(stdin);
            scanf("%c",&opcion3);
            switch (opcion3)
            {
            case 'a':

                validos3=cantRegistrosArchivo(nombreArchivoAlumnos,sizeof(Alumno));
                a3=(Alumno *)malloc(validos3*(sizeof(Alumno)));
                pasarAlumnosDeArchivoAarreglo(nombreArchivoAlumnos,a3,validos3);
                mostrarArregloAlumnos(validos3,a3);
                break;

            case 'b':

                validos3=cantRegistrosArchivo(nombreArchivoAlumnos,sizeof(Alumno));
                a3=arregloDinamicoAlumnosDesdeArchivoCretorno(validos3,nombreArchivoAlumnos);
                mostrarArregloAlumnos(validos3,a3);
                break;

            case 'c':
                validos3=cantRegistrosArchivo(nombreArchivoAlumnos,sizeof(Alumno));
                arregloDinamicoAlumnosDesdeArchivoPtroDoble(nombreArchivoAlumnos,validos3,&a3);
                mostrarArregloAlumnos(validos3,a3);
                break;

            default:

                printf("Ingreso una opcion incorrecta.");
                break;
            }
            break;

        case 4:///Hacer una función que reciba un arreglo dinámico por parámetro, la cantidad de
               ///elementos válidos del mismo, y un valor que indique el nuevo tamaño que se le quiere
               ///dar a dicho arreglo. La función debe redimensionar el arreglo (usar la función realloc) y
               ///retornar el puntero a dicho espacio de memoria.


            break;




        default:
            printf("Ingreso una opcion incorrecta.");
            break;
        }
        printf("Si desea continuar con otro ejercicio ingrese 1, para salir ingrese 0: ");
        scanf("%i",&control);
        printf("\n");
    }

    return 0;
}

///2.///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarArregloEnteros(int validos,int arreglo[])
{
    int i=0;
    while(i<validos)
    {
        printf("|%d",arreglo[i]);
        i++;
    }
    printf("\n");
}

int cargarY_DevolverCantidadEnteros(int dim,int a[])

{

    int cantidad=0;
    char control='s';
    while (control=='s' && cantidad<dim)
    {
        printf("Cargue un elemento: \n\n");
        fflush(stdin);
        scanf("%d",&a[cantidad]);
        cantidad++;
        printf("Si quiere seguir ingresando marque s, sino n: \n\n");
        fflush(stdin);
        scanf("%c",&control);
    }


    return cantidad;
}

int contarElementosPares(int validos,int arreglo[])
{
    int cant=0, i=0;
    while(i<validos)
    {
        if(arreglo[i]%2==0)
        {
            cant++;
        }
        i++;
    }

    return cant;
}

void pasarElementosParesAarrayDinamico(int validos,int a[],int validos2,int ad[])
{
    int i=0, j=0;
    while(i<validos && j<=validos2)
    {
        if(a[i]%2==0)
        {
            ad[j]=a[i];
            j++;
        }
        i++;
    }
}

///2.b///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int * crearYpasarElementosParesAarrayDinamico(int validos,int a[],int validos2)
{
    int* a2;

    a2=(int*)malloc(validos2*(sizeof(int)));


    int i=0, j=0;
    while(i<validos && j<=validos2)
    {
        if(a[i]%2==0)
        {
            a2[j]=a[i];
            j++;
        }
        i++;
    }

    return a2;
}

///2.c///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void crearYpasarElementosParesAarrayDinamicoPtroDoble(int validos,int a[],int validos2,int ** a2)
{


    *a2=(int*)malloc(validos2*(sizeof(int)));


    int i=0, j=0;
    while(i<validos && j<validos2)
    {
        if(a[i]%2==0)
        {
            (*a2)[j]=a[i];
            j++;
        }
        i++;
    }
}

///3.a////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cantRegistrosArchivo(char nombreArchivo[],int divisor)
{
    int cant;
    FILE*buf=fopen(nombreArchivo,"rb");
    if(buf)
    {
        fseek(buf,0,SEEK_END);
        cant=ftell(buf)/divisor;
        fclose(buf);
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
    }
    return cant;
}

void pasarAlumnosDeArchivoAarreglo(char nombreArchivoAlumnos[],Alumno arregloAlumno[],int validos)
{
    Alumno A;
    int i=0;
    FILE*buff=fopen(nombreArchivoAlumnos,"rb");
    if(buff)
    {
        while((fread(&A,sizeof(Alumno),1,buff))>0 && i<validos)
        {
            arregloAlumno[i]=A;
            i++;
        }
        fclose(buff);
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
    }
}

void mostrar1alumno(Alumno A)
{
    printf("Legajo: %d",A.legajo);
    printf("\nNombre y Apellido: ");
    puts(A.nombreYapellido);
    printf("Edad: %d",A.edad);
    printf("\nAnio que cursa: %d",A.anio);
    printf("\n");
}

void mostrarArregloAlumnos(int validos,Alumno arregloAlumnos[])
{
    int i=0;
    while(i<validos)
    {
        mostrar1alumno(arregloAlumnos[i]);
        i++;
        printf("\n");
    }
}

///3.b////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Alumno * arregloDinamicoAlumnosDesdeArchivoCretorno(int validos,char nombreArchivoAlumnos[])
{
    int i=0;
    Alumno * aD=(Alumno*)malloc(validos*(sizeof(Alumno)));
    Alumno A;
    FILE*buff=fopen(nombreArchivoAlumnos,"rb");
    if (buff)
    {
        while((fread(&A,sizeof(Alumno),1,buff))>0 && i<validos)
        {
            aD[i]=A;
            i++;
        }
        fclose(buff);
    }
    else
    {
        printf("El archivo no se pudo abrir");
    }
    return aD;
}

///3.c////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void arregloDinamicoAlumnosDesdeArchivoPtroDoble(char nombreArchivoAlumnos[],int validos,Alumno**alumnos)
{
    int i=0;
    Alumno A;
    *alumnos=(Alumno*)malloc(validos*(sizeof(Alumno)));
    FILE*buff=fopen(nombreArchivoAlumnos,"rb");
    if (buff)
    {
        while((fread(&A,sizeof(Alumno),1,buff))>0 && i<validos)
        {
            (*alumnos)[i]=A;
            i++;
        }
        fclose(buff);
    }
    else
    {
        printf("El archivo no se pudo abrir");
    }
}

///4.////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int * redimensionarArregloDinamico(int * arregloDinamico,int validosNuevo)
{
    arregloDinamico=(int*)realloc(arregloDinamico,validosNuevo*sizeof(int));
    return arregloDinamico;
}

//
