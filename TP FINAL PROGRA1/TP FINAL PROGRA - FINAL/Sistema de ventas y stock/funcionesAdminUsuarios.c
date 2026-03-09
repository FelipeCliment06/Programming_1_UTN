#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesUsuario.h"
#include "funcionesAdminUsuarios.h"


/// FUNCIONES ADMIN MANEJO USUARIOS--


//FUNCIONES DE SWITCH

int menuUsuariosAdmin()
{
    int swUsuariosAdmin;
        printf("\n\n\t\t\t BUSCAR UN USUARIO |  REGISTRAR UN USUARIO  |  ELIMINAR UN USUARIO  |  EDITAR UN USUARIO  |  VOLVER");
        printf("\n\t\t\t        (1)                    (2)                      (3)                    (4)              (0)\n\n");
        fflush(stdin);
        scanf("%i", &swUsuariosAdmin);
            system("cls");
        return swUsuariosAdmin;
}

//FUNIONES DE BUSCAR USUARIOS

void buscarPorInicial(char archivoUsuarios[], char inicial) //BUSCA Y MUESTRA TODOS LOS USUARIOS QUE EMPIECEN POR LA INICIAL QUE EL USUARIO INGRESA
{
    int flag=0;
    stUsuario aux;
    FILE*bufUs;
    bufUs=fopen(archivoUsuarios, "rb");
    fseek(bufUs, 0, SEEK_SET);
    if(bufUs)
    {
        while(fread(&aux, sizeof(stUsuario), 1, bufUs)>0)
        {
            if(aux.usuario[0] == inicial)
            {
                mostrarUnUsuario(aux);
                flag=1;
            }

        }
        if(flag==0)
        {
            printf("\n\n\t\t\t\tNo se encontro un usuario con esa inicial");
        }
        fclose(bufUs);
    }
    else
    {
        printf("ERROR: Intenta nuevamente!");
    }

}

void buscarUnUsuario(char archivoUsuarios[], stUsuario A)
{
    stUsuario aux;
    FILE*bufUs;
    bufUs=fopen(archivoUsuarios, "rb");
    if(bufUs)
    {
        while(fread(&aux, sizeof(stUsuario), 1, bufUs)>0)
        {
            if(strcmp(A.usuario, aux.usuario)==0)
            {
                mostrarUnUsuario(aux);
            }
        }

        fclose(bufUs);
    }
    else
    {
        printf("No se pudo abrir el archivo, intenta nuevamente!");
    }
}

stUsuario darDeBajaUsuario(stUsuario A) //BAJA LOGICA
{
    stUsuario aux;
    aux=A;
    aux.estado=0;
    return aux;
}

void eliminarUsuario (char archivoUsuarios[], char usuario[]) //BAJA LOGICA
{
    char confirmar;
    stUsuario aux;
    FILE*bufUs;
    bufUs=fopen(archivoUsuarios, "r+b");
    if(bufUs)
    {
        while(fread(&aux, sizeof(stUsuario), 1, bufUs)>0)
        {
            if(strcmp(usuario, aux.usuario)==0)
            {
                mostrarUnUsuario(aux);
                printf("\n\t\tEsta seguro que desea eliminar el usuario? s/n: ");
                scanf("%c", &confirmar);
                if(confirmar=='s' || confirmar ||'s')
                {
                    aux = darDeBajaUsuario(aux);
                    fseek(bufUs, (sizeof(stUsuario)*-1), SEEK_CUR);
                    fwrite(&aux, sizeof(stUsuario), 1, bufUs);
                    break;
                }
            }
        }

        fclose(bufUs);
    }
    else
    {
        printf("No se pudo abrir el archivo, intenta nuevamente!");
    }
}


// FUNCIONES EDITAR UN USUARIO


void editarUsuario (char archivoUsuarios[], char usuario[], char campo[]) //BUSCA EL CAMPO QUE INGRESO EL USUARIO Y LLAMA A LA FUNCION QUE CORRESPONDE QUE DESEA EDITAR EL USUARIO
{
    int flag=0;
    stUsuario aux;
    FILE*bufUs;
    bufUs=fopen(archivoUsuarios, "r+b");
    if(bufUs)
    {
        while((fread(&aux, sizeof(stUsuario),1 , bufUs)>0) && flag==0)
        {
            if(strcmp(aux.usuario, usuario)==0)
            {
                flag=1;
                fseek(bufUs, (sizeof(stUsuario)*-1), SEEK_CUR);

                    if(strcmpi(campo, "usuario")== 0)
                    {
                        aux = modificarUsuario(aux);
                    }
                    else if(strcmpi(campo,"mail")==0)
                    {
                        aux = modificarMail(aux);
                    }
                    else if(strcmpi(campo, "documento")==0)
                    {
                        aux = modificarDocumento(aux);
                    }
                    else if(strcmpi(campo, "direccion")==0)
                    {
                        aux = modificarDireccion(aux);
                    }
                    else if(strcmpi(campo, "estado")==0)
                    {
                        aux = modificarEstado(aux);
                    }
                    else if(strcmpi(campo,"caracter")==0)
                    {
                        aux=modificarCaracter(aux);
                    }
                    else if(strcmpi(campo, "contrasena")==0)
                    {
                        aux=modificarContrasena(aux);
                    }

                    fwrite(&aux, sizeof(stUsuario),1 , bufUs);
                    break;
            }
        }

        if(flag==0)
        {
            printf("No se encontro el usuario!");
        }

        fclose(bufUs);
    }
    else
    {
        printf("Error al abrir el archivo!");
    }

}

stUsuario modificarUsuario(stUsuario A)
{
    stUsuario aux;
    aux=A;
    printf("Ingrese el nuevo nombre de usuario: ");
    gets(aux.usuario);
    printf("\nUsuario modificado!\n");
    return aux;
}

stUsuario modificarMail(stUsuario A)
{
    stUsuario aux;
    aux=A;
    printf("Ingrese el nuevo mail: ");
    gets(aux.mail);
    printf("\nMail modificado!\n");
    return aux;
}

stUsuario modificarDocumento(stUsuario A)
{
    stUsuario aux;
    aux=A;
    printf("Ingrese el nuevo documento: ");
    gets(aux.documento);
    printf("\nDocumento modificado!\n");
    return aux;
}

stUsuario modificarDireccion(stUsuario A)
{
    stUsuario aux;
    aux=A;
    printf("Ingrese la nueva direccion: ");
    gets(aux.direccion);
    printf("\nDireccion modificada!\n");
    return aux;
}

stUsuario modificarEstado(stUsuario A)
{
    stUsuario aux;
    aux=A;
    if(aux.estado==1)
    {
        printf("El estado del usuario es: Activo");
        aux.estado=0;
        printf("\nEstado modificado!\n");
    }
    else
    {
        printf("El estado del usuario es: Inactivo");
        aux.estado=1;
        printf("\nEstado modificado!\n");
    }

    return aux;
}

stUsuario modificarContrasena(stUsuario A)
{
    stUsuario aux;
    aux=A;
    printf("Ingrese la nueva contrasena: ");
    gets(aux.contrasena);
    printf("\nContrasena modificado!\n");
    return aux;
}

stUsuario modificarCaracter(stUsuario A)
{
    stUsuario aux;
    aux=A;
    if(strcmpi(aux.caracter, "Admin")==0)
    {
        printf("El caracter del usuario es: Admin");
        strcpy(aux.caracter, "Usuario");
        printf("\nEl usuario ahora es: Usuario\n");
    }
    else if(strcmpi(aux.caracter, "Usuario")==0)
    {
        printf("El caracter del usuario es: Usuario");
        strcpy(aux.caracter, "Admin");
        printf("\nEl usuario ahora es: Admin\n");
    }
    return aux;
}
