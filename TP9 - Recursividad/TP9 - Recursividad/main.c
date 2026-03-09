#include <stdio.h>
#include <stdlib.h>


char nombreArchivoInt[]= {"Archivero"};

///aux

int cantRegistrosArchivo(char nombreArchivo[],int divisor);

void mostrarArchivoEnteros(char nombreArchivo[]);

void mostrarArrayEnteros(int array[],int validos);

///1

int factorial(int numero);

///2

int potencia(int num, int exponente);

///3

void mostrarArrayRecursivo(int array[],int validos,int i);

///4

void mostrarArrayRecursivoInverso(int array[],int validos,int i);

///5

int capicuaRecursivo(int array[],int validos,int i);

///6

int sumatoriaArrayRecursiva(int array[],int validos,int i);

///7

int menorArrayRecursivo(int array[],int validos,int i);

///8

int menorArchivoRecursivo(FILE*buff);

///9

void invertirArchivoRecursivo(FILE*buff,int cantidadRegistros,int i);

///10

void mostrarArchivoInvertidoRecursivo(FILE*buff,int cantRegistros);

///11

void mostrarCaracteresInverso();

///12

int buscarElementoArregloRecursivo(int array[],int validos, int i,int busqueda);

int main()
{
    ///1

    int opcion,control=1;

    int num1,factorial1;

    ///2

    int potencia2,num2,exponente2;

    ///3

    int array3[]= {5,55,4,6,1,-2};

    ///5

    int rta5;

    ///6

    int rta6;

    ///7

    int rta7;

    ///8

    int rta8;

    ///9


    FILE*buff;

    int cantidadRegistros9;

    ///10

    int cantidadRegistros10;

    ///12

    int rta12;
    int busqueda12;

    printf("Bienvenido al TP de recursividad: ");
    while (control==1)
    {
        printf("\nIngrese el ejercicio a realizar: \n1_Factorial.\n2_Potencia.\n3_Mostrar array recursivamente.\n4_Mostrar array invertido recursivamente.\n5_Capicua recursivo.\n6_Sumatoria array.\n7_Menor recursivo.\n8_Menor de archivo recursivo.\n9_Invertir Archivo recursivamente.\n10_Mostrar archivo invertido recursivamente.\n11_Mostrar caracteres en  sentido inverso.\n12_Buscar elemento en array recursivamente.\nSu opcion: ");
        scanf("%d",&opcion);
        switch (opcion)
        {
        case 1:

            printf("\nIngrese el numero para calcular el factorial: ");
            scanf("%d",&num1);
            factorial1=factorial(num1);
            printf("\nEl factorial de %d es: %d.",num1,factorial1);
            break;

        case 2:

            printf("\nIngrese el numero a elevar: ");
            scanf("%d",&num2);
            printf("\nIngrese el exponente: ");
            scanf("%d",&exponente2);
            potencia2=potencia(num2,exponente2);
            printf("El numero %d elevado a %d da como resultado: %d",num2,exponente2,potencia2);
            break;

        case 3:
            mostrarArrayRecursivo(array3,6,0);
            break;

        case 4:

            mostrarArrayRecursivoInverso(array3,6,0);
            break;

        case 5:

            rta5=capicuaRecursivo(array3,6,0);
            if(rta5==1)
            {
                printf("El arreglo es capicua: \n");
                mostrarArrayEnteros(array3,6);

            }
            else
            {
                printf("El arreglo no es capicua: \n");
                mostrarArrayEnteros(array3,6);
            }
            break;

        case 6:

            rta6=sumatoriaArrayRecursiva(array3,6,0);
            printf("El resultado de la sumatoria es: %d \n",rta6);
            mostrarArrayEnteros(array3,6);
            break;
        case 7:

            rta7=menorArrayRecursivo(array3,6,0);
            printf("El menor del array es: %d.\n",rta7);
            mostrarArrayEnteros(array3,6);
            break;

        case 8:

            buff=fopen(nombreArchivoInt,"rb");
            if(buff)
            {
                rta8=menorArchivoRecursivo(buff);
                fclose(buff);
                printf("El menor  en el archivo de enteros es %d\n",rta8);
                mostrarArchivoEnteros(nombreArchivoInt);
            }
            else
            {
                printf("No se pudo abrir el archivo.");
            }
            break;

        case  9:

            printf("El archivo: \n");
            mostrarArchivoEnteros(nombreArchivoInt);
            system("pause");
            cantidadRegistros9=cantRegistrosArchivo(nombreArchivoInt,sizeof(int));
            buff=fopen(nombreArchivoInt,"r+b");
            if (buff)
            {
                invertirArchivoRecursivo(buff,cantidadRegistros9,0);
                fclose(buff);
                printf("El archivo invertido: \n");
                mostrarArchivoEnteros(nombreArchivoInt);
            }
            else
            {
                printf("No se pudo abrir el archivo.");
            }
            break;

        case 10:

            cantidadRegistros10=cantRegistrosArchivo(nombreArchivoInt,sizeof(int));
            buff=fopen(nombreArchivoInt,"rb");
            if(buff)
            {
                printf("El archivo invertido: \n");
                mostrarArchivoInvertidoRecursivo(buff,cantidadRegistros10);
                fclose(buff);
            }
            break;

        case 11:

            mostrarCaracteresInverso();
            break;
        case 12:

            mostrarArrayRecursivo(array3,6,0);
            printf("\n");
            system("pause");
            printf("\nIngrese el elemento a buscar: ");
            scanf("%d",&busqueda12);
            rta12=buscarElementoArregloRecursivo(array3,6,0,busqueda12);
            if(rta12==1)
            {
                printf("\nEl elemento se encuentra en el array.\n");
            }
            else
            {
                printf("\nEl elemento no se encuentra en el array.\n");
            }
            mostrarArrayRecursivo(array3,6,0);
            break;

        default:

            printf("\nIngreso una opcion no valida.");
            break;
        }
        printf("\nIngrese 1 para realizar otro ejercicio o 0 para salir.");
        scanf("%d",&control);
    }

    return 0;
}

///1.///////////////////////////////////////////////////////////////////////////////////////////////////

int factorial(int numero)
{
    if(numero==0)
    {
        numero=1;
    }
    else
    {
        numero=factorial(numero-1)*numero;
    }
    return numero;
}

///2.///////////////////////////////////////////////////////////////////////////////////////////////////

int potencia(int num,int exponente)
{
    if(exponente==0)
    {
        num=1;
    }
    else
    {
        num=potencia(num,exponente-1)*num;
    }
    return num;
}

///3.///////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarArrayRecursivo(int array[],int validos,int i)
{
    if(i==validos-1)
    {
        printf("|%*d|",4,array[i]);
    }
    else
    {
        printf("|%*d|",4,array[i]);
        mostrarArrayRecursivo(array,validos,i+1);
    }
}

///4.///////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarArrayRecursivoInverso(int array[],int validos,int i)
{
    if(i==validos-1)
    {
        printf("%d",array[i]);
    }
    else
    {
        mostrarArrayRecursivoInverso(array,validos,i+1);
        printf("%d",array[i]);
    }
}

///5.///////////////////////////////////////////////////////////////////////////////////////////////////


int capicuaRecursivo(int array[],int validos,int i)
{
    int rta=0;
    if(i<=validos)
    {
        rta=1;
    }
    else
    {
        if(array[i]==array[validos])
        {
            rta=capicuaRecursivo(array,validos-1,i+1);
        }

    }

    return rta;

}

///6.///////////////////////////////////////////////////////////////////////////////////////////////////

int sumatoriaArrayRecursiva(int array[],int validos,int i)
{
    int suma;
    if(i==validos-1)
    {
        suma=array[i];
    }
    else
    {
        suma=sumatoriaArrayRecursiva(array,validos,i+1);
        suma+=array[i];
    }
    return suma;
}

///7.///////////////////////////////////////////////////////////////////////////////////////////////////

int menorArrayRecursivo(int array[],int validos,int i)
{
    int menor;
    if(i==validos-1)
    {
        menor=array[i];
    }
    else
    {
        menor=menorArrayRecursivo(array,validos,i+1);
        if(menor>array[i])
        {
            menor=array[i];
        }
    }
    return menor;
}

///8.///////////////////////////////////////////////////////////////////////////////////////////////////

int menorArchivoRecursivo(FILE*buff)
{
    int num;
    int menor;
    if(fread(&num,sizeof(int),1,buff)==0)
    {
        fseek(buff,(long)sizeof(int)*-1,SEEK_CUR);
        fread(&menor,sizeof(int),1,buff);
    }
    else
    {
            menor=menorArchivoRecursivo(buff);
        if (menor>num)
        {
            menor=num;
        }
    }
    return menor;
}

///9.///////////////////////////////////////////////////////////////////////////////////////////////////

void invertirArchivoRecursivo(FILE*buff,int cantRegistros,int i)
{
    int a,b;
    long posA=i*sizeof(int);
    long posB=(cantRegistros-1-i)*sizeof(int);
    if(i>=cantRegistros/2)
    {
        return;
    }
    else
    {
        fseek(buff,posA,SEEK_SET);
        fread(&a,sizeof(int),1,buff);
        fseek(buff,posB,SEEK_SET);
        fread(&b,sizeof(int),1,buff);
        fseek(buff,posA,SEEK_SET);
        fwrite(&b,sizeof(int),1,buff);
        fseek(buff,posB,SEEK_SET);
        fwrite(&a,sizeof(int),1,buff);
        invertirArchivoRecursivo(buff,cantRegistros,i+1);
    }
}


///10.///////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarArchivoInvertidoRecursivo(FILE*buff,int cantRegistros)
{
    int a;
    if(cantRegistros==0)
    {
        return;
    }
    else
    {
        fseek(buff,(long)(cantRegistros-1)*sizeof(int),SEEK_SET);
        fread(&a,sizeof(int),1,buff);
        printf("|%*d|",4,a);
        mostrarArchivoInvertidoRecursivo(buff,cantRegistros-1);
    }
}

///11.///////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarCaracteresInverso()
{
    char dato;
    printf("Ingrese un caracter, si desea terminar ingrese '*': ");
    fflush(stdin);
    scanf("%c",&dato);
    if(dato=='*')
    {
        return;
    }
    else
    {
        mostrarCaracteresInverso();
        printf("%c",dato);
    }
}

///12.///////////////////////////////////////////////////////////////////////////////////////////////////

int buscarElementoArregloRecursivo(int array[],int validos, int i,int busqueda)
{
    int flag=0;
    if(i==validos && flag==0)
    {
        if(busqueda==array[i])
        {
            flag=1;
        }
    }
    else
    {
        if(busqueda==array[i])
        {
            flag=1;
        }
        else
        {
            flag=buscarElementoArregloRecursivo(array,validos,i+1,busqueda);
        }
    }
    return flag;
}

///aux

void mostrarArchivoEnteros(char nombreArchivo[])
{
    int aux;
    FILE* buf=fopen(nombreArchivo,"rb");
    if(buf!=NULL)
    {
        while((fread(&aux,sizeof(int),1,buf))>0)
        {
            printf("|%d| ",aux);
        }
        printf("\n");

        fclose(buf);
    }
    else
    {
        printf("No pude abrir el archivo.\n");
    }
}

void mostrarArrayEnteros(int array[],int validos)
{
    int i=0;
    while(i<validos)
    {
        printf("%*d|",4,array[i]);
        i++;
    }
    printf("\n");
}

int cantRegistrosArchivo(char nombreArchivo[],int divisor)
{
    int cant;
    FILE*buf=fopen(nombreArchivo,"rb");
    if(buf)
    {
        fseek(buf,0,2);
        cant=ftell(buf)/divisor;
        fclose(buf);
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
    }
    return cant;
}

//
