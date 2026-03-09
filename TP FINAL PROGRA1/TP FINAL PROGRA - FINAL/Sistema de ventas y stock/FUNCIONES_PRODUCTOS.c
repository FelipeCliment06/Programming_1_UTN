#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FUNCIONES_PRODUCTOS.h"


Producto Cargar_1_Producto()///CARGA TODOS LOS CAMPOS DE UN PRODUCTO Y LO RETORNA
{
    Producto producto;

    printf("ingrese el nombre del producto: ");
    fflush(stdin);
    gets(producto.nombre);

    printf("ingrese el precio: ");
    fflush(stdin);
    scanf("%f",&producto.precio);

    printf("ingrese el codigo: ");
    fflush(stdin);
    scanf("%d",&producto.codigo);

    printf("ingrese el stock disponible: ");
    fflush(stdin);
    scanf("%d",&producto.stock);


    producto.estado=1;


    return producto;
}

void Cargar_Varios_Productos(char archivoProducto[])/// CARGA LOS PRODUCTOS EN EL ARCHIVO MEDIANTE LLAMADAS A LA FUNC ANTERIOR, TMB VERIFICA QUE NO SE REPITA NI EL NOMBRE NI EL CODIGO DE UN PRODUCTO
{
    Producto producto;
    char control='s';
    int i;

    FILE * buff=fopen(archivoProducto,"ab");

    if (buff)
    {

        while(control=='s')
        {


            fseek(buff,0,SEEK_END);
            int cant= Cant_Elementos_En_El_Arch(archivoProducto,sizeof(Producto));
            producto=Cargar_1_Producto();

            if(cant>=1)
            {
                i=Verificar_Productos(producto,archivoProducto);
                if(i==1)
                {
                    printf("\nEl producto no fue cargado por que el nombre o codigo ya esta usado.\n");
                }
                else
                {
                    fwrite(&producto,sizeof(Producto),1,buff);
                }
            }
            else
            {
                fwrite(&producto,sizeof(Producto),1,buff);
            }


            printf("\nDesea seguir ingresando?(s/n): ");
            fflush(stdin);
            scanf(" %c",&control);
            system("cls");


        }
        fclose(buff);
    }


    else
    {
        printf("No se pudo abrir el archivo! ");
    }
}

int Verificar_Productos(Producto UltProducto, char archivoProducto[])///LA LLAMO EN LA FUNCION DE CARGAR ARCHIVO,VERIFICO SI SE REPITE EL NOMBRE O EL CODIGO
{
    Producto producto;
    int i = 0;
    FILE * buff=fopen(archivoProducto,"rb");

    if(buff)
    {

        while(fread(&producto,sizeof(Producto),1,buff)>0 && i==0)
        {
            if((strcmpi(UltProducto.nombre,producto.nombre)==0) || (UltProducto.codigo==producto.codigo) )
            {
                i=1;
            }
        }
        fclose(buff);
    }

    else
    {
        printf("No se pudo abrir el archivo! ");
    }

    return i;

}

void Mostra_1_producto(Producto producto)///MUESTRA TODOS LOS CAMPOS DE U PRODUCTO
{

    printf("_______________________\n");
    printf("Nombre: ");
    puts(producto.nombre);
    printf("Precio: $%2.f",producto.precio);
    printf("\nCodigo: %d",producto.codigo);
    if(producto.stock==0)
    {
        printf("\nStock:  SIN STOCK!!!");
    }
    else
    {
        printf("\nStock:  %d",producto.stock);
    }
    if(producto.estado==1)
    {
        printf("\nEstado: Activo\n");
    }
    else
    {
        printf("\nEstado: Inactivo\n");
    }

}

void mostrar_Arreglo_Productos(Producto arreglo[],int validosProductos)///MUESTRA UN ARREGLO DE PRODUCTOS MEDIANTE LLAMADAS A LA FUNC ANTERIOR
{
    int i=0;

    while(i<validosProductos)
    {

        Mostra_1_producto(arreglo[i]);
        i++;
    }

}

int Cant_Elementos_En_El_Arch(char archivoProducto[],int TamanioStruct)///CUENTA LA CANT DE ELEMENTOS QUE HAY EN EL ARCHIVO Y LOS RETORNA.
{
    FILE * buff=fopen(archivoProducto,"rb");
    int validos;
    if(buff)
    {
        fseek(buff, 0, SEEK_END);
        validos = ftell(buff) / TamanioStruct;

        fclose(buff);
    }

    else
    {
        printf("No se pudo abrir el archivo! ");
    }

    return validos;
}

int Pasar_A_Arreglo_Dinamico(char archivoProducto[],Producto **arreglo)///RECIBE EL ARREGLO POR UNTERO, CREA EL ARREGLO DINAMICO CON EL TAMAÑO JUSTO, RETORNA VALIDOS PARA MOSTRAR O OTROS
{

    int validos= Cant_Elementos_En_El_Arch(archivoProducto,sizeof(Producto));
    int i=0;
    FILE * buff = fopen(archivoProducto,"rb");
    Producto aux;
    if(buff)
    {

        *arreglo = (Producto*)malloc(sizeof(Producto)* validos);

        while((fread(&aux, sizeof(Producto), 1, buff))>0)
        {
            (*arreglo)[i] = aux;

            i++;

        }

        fclose(buff);

    }

    else
    {
        printf("No se pudo abrir el archivo! ");
    }

    return validos;
}

int Encontrar_Menor(Producto arreglo[],int validosProductos,int pos)///ENCUENTRA EL MENOR ALFABETICAMENTE ENTRE LOS PRODUCTOS
{
    int i=pos+1;
    int posmenor=pos;



    while(i<validosProductos)
    {

        if(strcmpi(arreglo[posmenor].nombre,arreglo[i].nombre)>0)
        {

            posmenor=i;
            i++;
        }
        else
            i++;

    }
    return posmenor;
}

void Ordenar_Seleccion_ABC(Producto arreglo[],int validosProductos)/// ORDENA ALFABETICAMENTE EL ARREGLO
{
    int posmenor;
    Producto aux;
    int i=0;

    while(i<validosProductos)
    {

        posmenor=Encontrar_Menor(arreglo,validosProductos,i);
        aux=arreglo[i];
        arreglo[i]=arreglo[posmenor];
        arreglo[posmenor]=aux;
        i++;
    }
}

void Modificar_Productos(char archivoProducto[],char buscado[])/// ESTA FUNC ES LA QUE LLAMA A TODOS LOS ODIFICAR POR CAMPOS, LE PASA A CADA UNO LA POSICION QUE SE DESEE.
{
    char control='s';
    int swABCM;
    int pos=buscar_Producto(archivoProducto,buscado);
    if(pos!=-1)
    {
        do
        {

            printf("\n\n\nQue desea modificar?");
            printf("\n\n\n|NOMBRE(1)| |PRECIO(2)| |CODIGO(3)| |STOCK(4)| |ELIMINAR(5)|\n\n\n");
            fflush(stdin);
            scanf("%d",&swABCM);
            switch(swABCM)
            {

            case 1:
                Modificar_Nombre(archivoProducto,pos);

                break;

            case 2:
                Modificar_Precio(archivoProducto,pos);

                break;
            case 3:
                Modificar_Codigo(archivoProducto,pos);

                break;
            case 4:
                Modificar_Stock(archivoProducto,pos);
                break;
            case 5:
                Modificar_Estado(archivoProducto,pos);
                break;
            }
            printf("Desea segir modificando este producto?(s/n): ");
            fflush(stdin);
            scanf(" %c",&control);

        }
        while(control=='s');
    }
    else
    {
        printf("\n\n\t\tEl producto no fue encontrado!\n\n");
    }
}

void Modificar_Nombre(char archivoProducto[],int pos)///RECIB LA POSICION Y MODIFICA EL NOMBRE, ANTES VERIFICA Q NO SE REPITA
{
    int i;
    Producto aux;
    FILE * buff=fopen(archivoProducto,"r+b");



    if (buff)
    {
        fseek(buff,pos*sizeof(Producto),SEEK_SET);
        fread(&aux,sizeof(Producto),1,buff);
        printf("ingrese el nuevo nombre del producto: ");
        fflush(stdin);
        gets(aux.nombre);
        i=buscar_Producto(archivoProducto, aux.nombre);
        if(i==-1)
        {
            fseek(buff,pos*sizeof(Producto),SEEK_SET);
            fwrite(&aux,sizeof(Producto),1,buff);
        }
        else
        {
            printf("\n\n\tEl nombre de usuario ya esta ingresado!\n\n");
        }
        fclose(buff);

    }
    else
    {
        printf("No se pudo abrir el archivo! ");
    }
}

void Modificar_Precio(char archivoProducto[],int pos)///RECIBE LA POS Y MODIFICA EL PRECIO
{

    Producto aux;
    FILE * buff=fopen(archivoProducto,"r+b");



    if (buff)
    {
        fseek(buff,pos*sizeof(Producto),SEEK_SET);
        fread(&aux,sizeof(Producto),1,buff);
        printf("ingrese el nuevo precio del producto: ");
        fflush(stdin);
        scanf("%f",&aux.precio);
        fseek(buff,pos*sizeof(Producto),SEEK_SET);
        fwrite(&aux,sizeof(Producto),1,buff);

        fclose(buff);

    }
    else
    {
        printf("No se pudo abrir el archivo! ");
    }
}

void Modificar_Codigo(char archivoProducto[],int pos)///RECIBE LA POS Y MODIFICA EL CODIGO, ANTES VERIFICA QUE NO SE REPITA
{
    int i;
    Producto aux;
    FILE * buff=fopen(archivoProducto,"r+b");



    if (buff)
    {

        fseek(buff,pos*sizeof(Producto),SEEK_SET);
        fread(&aux,sizeof(Producto),1,buff);
        printf("ingrese el codigo del producto: ");
        fflush(stdin);
        scanf("%d",&aux.codigo);
        i=buscar_Producto_Codigo(archivoProducto, aux.codigo);
        if(i==-1)
        {
            fseek(buff,pos*sizeof(Producto),SEEK_SET);
            fwrite(&aux,sizeof(Producto),1,buff);
        }
        else
        {
            printf("\n\n\tEl codigo ingresado ya esta cargado!\n\n");
        }
        fclose(buff);
    }
    else
    {
        printf("No se pudo abrir el archivo! ");
    }
}

void Modificar_Stock(char archivoProducto[],int pos)///RECIBE LA POSCICION Y SE INGRESA LA CANT DEL PRODUCTO QUE INGRESO Y ESTO SE SUMA A LO QUE YA HABIA
{

    Producto aux;
    int ingreso;
    FILE * buff=fopen(archivoProducto,"r+b");



    if (buff)
    {

        fseek(buff,pos*sizeof(Producto),SEEK_SET);
        fread(&aux,sizeof(Producto),1,buff);
        printf("ingrese la cant que ingreso del producto: ");
        fflush(stdin);
        scanf("%d",&ingreso);
        aux.stock+=ingreso;
        fseek(buff,pos*sizeof(Producto),SEEK_SET);
        fwrite(&aux,sizeof(Producto),1,buff);

        fclose(buff);

    }
    else
    {
        printf("No se pudo abrir el archivo! ");
    }
}

void Modificar_Estado(char archivoProducto[],int pos)///MODIFICA EL ESTADO(BAJA LOGICA)
{

    Producto aux;
    FILE * buff=fopen(archivoProducto,"r+b");



    if (buff)
    {

        fseek(buff,pos*sizeof(Producto),SEEK_SET);
        fread(&aux,sizeof(Producto),1,buff);
        printf("ingrese el nuevo estado del producto |(Act(1)|Inact(0)|: ");
        fflush(stdin);
        scanf("%d",&aux.estado);
        fseek(buff,pos*sizeof(Producto),SEEK_SET);
        fwrite(&aux,sizeof(Producto),1,buff);

        fclose(buff);

    }
    else
    {
        printf("No se pudo abrir el archivo! ");
    }
}

int buscar_Producto(char archivoProducto[],char buscado[])///BUSCA UN PRODUCTO POR EL NOMBRE RETORNA EL LUGAR
{
    int pos=0;
    int flag=0;
    Producto producto;
    FILE * buff=fopen(archivoProducto,"rb");



    if (buff)
    {
        while(fread(&producto,sizeof(Producto),1,buff)>0 && flag==0)
        {

            if (strcmpi(producto.nombre,buscado)==0)
            {
                flag=1;

                pos=ftell(buff)/sizeof(Producto);
                pos = pos-1;
            }

        }
        if(flag!=1)
        {
            pos=-1;
        }
        fclose(buff);
    }
    else
    {
        printf("No se pudo abrir el archivo! ");
    }

    return pos;
}

int buscar_Producto_Codigo(char archivoProducto[],int codigo)///BUSCA UN PRODUCTO POR CDIGO Y RETORNA LA POS
{
    int pos=0;
    int flag=0;
    Producto producto;
    FILE * buff=fopen(archivoProducto,"rb");



    if (buff)
    {
        while(fread(&producto,sizeof(Producto),1,buff)>0 && flag==0)
        {

            if (producto.codigo == codigo)
            {
                flag=1;

                pos=ftell(buff)/sizeof(Producto);
                pos = pos-1;
            }

        }
        if(flag!=1)
        {
            pos=-1;
        }
        fclose(buff);
    }
    else
    {
        printf("No se pudo abrir el archivo! ");
    }

    return pos;
}

void Ordenar_Inser_Menor_Precio(Producto arreglo[], int validosProductos)///ORDENA DE MENOR A MAYOR PRECIO
{
    for (int i = 1; i < validosProductos; i++)
    {
        Insertar_En_Orden_Menor(arreglo,i);
    }
}
void Insertar_En_Orden_Menor(Producto arreglo[], int posicion)///BUSCA EL LUGAR Y LO INSERTA
{
    Producto aux = arreglo[posicion];
    int j = posicion;

    while (j > 0 && arreglo[j - 1].precio > aux.precio)
    {
        arreglo[j] = arreglo[j - 1];
        j--;
    }
    arreglo[j] = aux;
}

void Ordenar_Inser_Mayor_Precio(Producto arreglo[], int validosProductos)///ORDENA DE MAYOR A MENOR
{
    for (int i = 1; i < validosProductos; i++)
    {
        Insertar_En_Orden_Mayor(arreglo,i);
    }
}
void Insertar_En_Orden_Mayor(Producto arreglo[], int posicion)/// BUSCA EL LUGAR Y LO INSERTA
{
    Producto aux = arreglo[posicion];
    int j = posicion;

    while (j > 0 && arreglo[j - 1].precio < aux.precio)
    {
        arreglo[j] = arreglo[j - 1];
        j--;
    }
    arreglo[j] = aux;
}

void Mostrar_Buscado(char archivoProducto[],char buscado[])///MUESTRA UN PRODUCTO PEDIDO
{

    int pos=buscar_Producto(archivoProducto,buscado);
    Producto aux;
    FILE * buff=fopen(archivoProducto,"rb");



    if (buff)
    {
        if(pos!=-1)
        {
            fseek(buff,pos*sizeof(Producto),SEEK_SET);
            fread(&aux,sizeof(Producto),1,buff);
            Mostra_1_producto(aux);
        }
        else
        {
            printf("El producto no fue encontrado!");
        }

        fclose(buff);
    }
    else
    {
        printf("No se pudo abrir el archivo! ");
    }
}
