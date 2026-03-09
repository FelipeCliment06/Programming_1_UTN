#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ArchivoAsteroides[]={"asteroides"};


typedef struct{
    char designador[10];
    float volumen;
    float velocidad;
    int radioactivo;///0=si; 1=no.
}Asteroide;

///prototipado
Asteroide cargar1asteroide();
int cargarArregloAsteroides(Asteroide arreglo[19]);
///2
void cargaEnArchivo(char ArchivoAsteroides[],int validos,Asteroide arreglo[validos]);
void MostrarListameteoritos(char ArchivoAsteroides[]);


void mostrarRecursivo(int validos,Asteroide arreglo[validos],int i);

void mostar1Asteroide(Asteroide meteorito);

int pasarAArregloDin(char ArchivoAsteroides[],Asteroide **Arrdin);

void mostrarArreloDin(Asteroide Arrdin[],int validosArrdinam);







int main()
{

int sw_menu;
Asteroide arreglo[19];
int validos;
int i=0;
Asteroide * Arrdin;
int validosArrdinam;


do{
    printf("\nPOINT 1\nPOINT 2\nPOINT 3\nPOINT 4\n");
    fflush(stdin);
    scanf("%d",&sw_menu);
    switch(sw_menu){

    case 1:

        validos=cargarArregloAsteroides(arreglo);


        break;

    case 2:
        validos=cargarArregloAsteroides(arreglo);
        cargaEnArchivo(ArchivoAsteroides,validos,arreglo);
        MostrarListameteoritos(ArchivoAsteroides);

        break;

    case 3:
        validos=cargarArregloAsteroides(arreglo);
        mostrarRecursivo(validos,arreglo,i);

        break;

    case 4:

        validosArrdinam=pasarAArregloDin(ArchivoAsteroides,&Arrdin);
        mostrarArreloDin(Arrdin,validosArrdinam);



        break;

    }


}

while(sw_menu!=0);
return 0;
}









///1
Asteroide cargar1asteroide()
{
    Asteroide metiorito;

    printf("ingrese el designador:");
    fflush(stdin);
    gets(metiorito.designador);

    printf("ingrese el volumen del metiorito:");
    fflush(stdin);
    scanf("%f",&metiorito.volumen);

    printf("ingrese la velocidad del metiorito:");
    fflush(stdin);
    scanf("%f",&metiorito.velocidad);

    printf("el metiorito esta en estado radiactivo?(0=si|1=no)");
    fflush(stdin);
    scanf("%d",&metiorito.radioactivo);


return metiorito;
}

int cargarArregloAsteroides(Asteroide arreglo[19])
{
    int i=0;
    char control='s';
    while(i<19 && control=='s'){

    arreglo[i] = cargar1asteroide();
        i++;

    printf("desea seguir ingresando?(s/n)");
    fflush(stdin);
    scanf("%c",&control);

    }
return i;
}

void cargaEnArchivo(char ArchivoAsteroides[],int validos,Asteroide arreglo[validos])
{

    FILE * buff = fopen(ArchivoAsteroides,"ab");
    int i=0;
    Asteroide metiorito;

    if (buff){
    while(i<validos){

        metiorito=arreglo[i];
        i++;
        fwrite(&metiorito,sizeof(Asteroide),1,buff);

    }

    fclose(buff);
    }

}

void mostrarRecursivo(int validos,Asteroide arreglo[validos],int i)
{
    if(i<validos){

    if(arreglo[i].radioactivo==0){
    mostar1Asteroide(arreglo[i]);
    }
    mostrarRecursivo(validos,arreglo,i+1);
        }
}

void mostar1Asteroide(Asteroide meteorito)
{
    printf("\n------------------");
    printf("\ndesignador:");
    puts(meteorito.designador);
    printf("volumen: %.2f",meteorito.volumen);
    printf("\nvelocidad: %.2f",meteorito.velocidad);
    if(meteorito.radioactivo==0){
        printf("\nestado: radioactivo");
    }
    else{
        printf("\nestado: no radiactivo");
    }
    printf("\n------------------");
}



void MostrarListameteoritos(char ArchivoAsteroides[])
{
    Asteroide meteorito;
    FILE * buff=fopen(ArchivoAsteroides,"rb");

    if (buff)
    {
        while(fread(&meteorito,sizeof(Asteroide),1,buff)>0)
        {
            mostar1Asteroide(meteorito);
        }
        fclose(buff);
    }
}


int pasarAArregloDin(char ArchivoAsteroides[],Asteroide **Arrdin)
{
    FILE * buff=fopen(ArchivoAsteroides,"rb");
    int cant;
    int i=0;
    Asteroide meteorito;
    if(buff){

        fseek(buff,0,SEEK_END);
        cant=ftell(buff)/sizeof(Asteroide);
        fseek(buff,0,SEEK_SET);

        *Arrdin = (Asteroide*)malloc(sizeof(Asteroide)*cant);

        while((fread(&meteorito,sizeof(Asteroide),1,buff)>0)){

            (*Arrdin) [i] = meteorito;
            i++;


        }
fclose(buff);
    }
return i;
}

void mostrarArreloDin(Asteroide Arrdin[],int validosArrdinam){
int i=0;

while(i<validosArrdinam){

mostar1Asteroide(Arrdin[i]);

i++;

}
}





