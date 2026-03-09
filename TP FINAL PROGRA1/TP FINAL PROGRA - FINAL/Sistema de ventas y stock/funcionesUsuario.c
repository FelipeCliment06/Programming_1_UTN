#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesUsuario.h"

/// FUNCIONES DE LOGIN--

char archivoUsuarios[]="archivoUsuarios";


//SWITCHS PANELES

int switchPanelInicio()
{
        int swLogin;
            printf("\n\n");
            printf("\t\t\t\t\tINICIAR      |    REGISTRARSE\n");
            printf("\t\t\t\t\tSESION (1)   |       (2)     \n");
            printf("\t\t\t\t\t");
            scanf("%i", &swLogin);
                system("cls");

    return swLogin;
}

int switchPanelAdministrador()
{
        int swAdmin;
            printf("\n\t\t\t\t\t\t ADMINISTRADOR");
            printf("\n\n\t\t\t\t PRODUCTOS  |  USUARIOS  |  CAJA  |  CERRAR SESION");
            printf("\n\t\t\t\t    (1)           (2)        (3)           (4)    \n\n\t\t\t");
            fflush(stdin);
            scanf("%i", &swAdmin);
                system("cls");

     return swAdmin;
}



//Funciones para PRIMER USO DEL PROGRAMA


stUsuario pantallaRegistrarUsuarioAdmin(stUsuario A) // CREA UN USUARIO ADMINISTRADOR
{
        printf("\t\tCREANDO UN USUARIO ADMIN...\n");
        printf("--------------------------------------------------------------------------------------------");
        printf("\n\t\tNombre de usuario: ");
            fflush(stdin);
        gets(A.usuario);
        printf("\n\t\t       Contrasena: ");
            fflush(stdin);
        gets(A.contrasena);
        printf("\n\t\t             Mail: ");
            fflush(stdin);
        gets(A.mail);
        printf("\n\t\t        Direccion: ");
            fflush(stdin);
        gets(A.direccion);
        printf("\n\t\t        Documento: ");
            fflush(stdin);
        gets(A.documento);
        strcpy(A.caracter, "Admin");
        A.estado=1;

        return A;
}

void verificarOCrearArchivoUsuarios(char archivoUsuarios[]) // VERIFICA SI YA EXISTE UN ARCHIVO, SI NO EXISTE, CREA UNO Y EL PRIMER USUARIO ES UN ADMINISTRADOR
{
    stUsuario aux;
    FILE*bufUs;
    bufUs=fopen(archivoUsuarios, "rb");
    if(bufUs)
    {
        fclose(bufUs);
    }
    else
    {
        aux=pantallaRegistrarUsuarioAdmin(aux);
        bufUs=fopen(archivoUsuarios, "wb");
        fwrite(&aux, sizeof(stUsuario),1 , bufUs);

        fclose(bufUs);
    }

}


//FUNCIONES DE REGISTRO


stUsuario pantallaRegistrarUsuario(stUsuario A)
{

        printf("\n\t\tNombre de usuario: ");
            fflush(stdin);
        gets(A.usuario);
        printf("\n\t\t       Contrasena: ");
            fflush(stdin);
        gets(A.contrasena);
        printf("\n\t\t             Mail: ");
            fflush(stdin);
        gets(A.mail);
        printf("\n\t\t        Direccion: ");
            fflush(stdin);
        gets(A.direccion);
        printf("\n\t\t        Documento: ");
            fflush(stdin);
        gets(A.documento);
        strcpy(A.caracter, "Usuario");
        A.estado=1;

        return A;
}

void registrarEnElArchivo(char archivoUsuarios[], stUsuario A)
{
    FILE*bufUs;
    bufUs=fopen(archivoUsuarios, "ab");
    if(bufUs)
    {
        fwrite(&A, sizeof(stUsuario), 1, bufUs);
        fclose(bufUs);
    }
    else
    {
        printf("\n\n\t\t\t\t\tNo se registro el usuario\n\n");
    }

}

int buscarSiExisteUsuario(stUsuario A, stUsuario aux) // BUSCA SI YA EXISTE ALGUN USUARIO CON EL MISMO NOMBRE, DOCUMENTO O MAIL.
{
    int usuarioExistente=0;

        if(strcmp(A.usuario, aux.usuario) == 0)
        {
            usuarioExistente = 1;
        }
        else if(strcmp(A.documento, aux.documento) == 0)
        {
            usuarioExistente = 2;
        }
        else if(strcmp(A.mail, aux.mail) == 0)
        {
            usuarioExistente = 3;
        }

        return usuarioExistente;
}


int verificarRegistrarUsuario(char archivoUsuarios[], stUsuario A)
{
    FILE*bufUs;
    stUsuario aux;
    bufUs=fopen(archivoUsuarios, "rb");
    int usuarioExistente=0;
    if(bufUs)
    {
        while((fread(&aux, sizeof(stUsuario), 1, bufUs) > 0)&& usuarioExistente==0)
        {
            usuarioExistente=buscarSiExisteUsuario(A, aux);
        }

        if (usuarioExistente==0)
        {
            return 0; // Nuevo usuario registrado
        }
        else
        {
            return usuarioExistente;
        }

        fclose(bufUs);
    }
    else
    {
        printf("Error al registrar, intenta nuevamente!");
        return -1; // Error al abrir el archivo
    }
}

void erroresRegistrarUsuario(int error) // IMPRIME LAS ALERTAS SI ALGUNO DE LOS CAMPOS QUE INGRESO EL USUARIO YA ESTA REGISTRADO
{

        if(error==1)
        {
            printf("\n\n\t\t\t\tEl usuario ya existe!\n\n");
        }
        else if(error==2)
        {
            printf("\n\n\t\t\t\tEl documento ya pertenece a un usuario registrado!\n\n");
        }
        else if(error==3)
        {
            printf("\n\n\t\t\t\tYa existe un usuario con ese correo!\n\n");
        }
        else if(error==-1)
        {
            printf("\n\n\t\t\t\tError al registrar, intenta nuevamente!\n\n");
        }

}

void registrarUsuarioMain(stUsuario A) // LLAMA A LAS ANTERIORES FUNCIONES
{

        A = pantallaRegistrarUsuario(A);

        int verificar = verificarRegistrarUsuario(archivoUsuarios, A);

        if(verificar==0)
        {
            registrarEnElArchivo(archivoUsuarios, A);
            printf("\n\n\t\t\t\t\tRegistro exitoso\n\n");
        }
        else
        {
            erroresRegistrarUsuario(verificar);
        }

}


//FUNCIONES INICIAR SESION


void pantallaIniciarSesion(char usuario[], char contrasena[])
{
             printf("\n\n");
             printf("\t\t\t\t\t\tPANCHITO's            \n");
             printf("\t\t   Usuario: ");
             fflush(stdin);
             gets(usuario);
             printf("\n\t\tContraseña: ");
             fflush(stdin);
             gets(contrasena);
}

int verificarInicioSesion(char archivoUsuarios[], char usuario[], char contrasena[]) // VERIFICA SI EL USUARIO ESTA REGISTRADO ANTES DE INICIAR SESION Y DETERMINA SI LO MANDA AL PANEL DE ADMINISTRADOR O DE USUARIO
{
    stUsuario aux;
    FILE*bufUs;
    bufUs=fopen(archivoUsuarios, "rb");
    if(bufUs)
    {
        while(fread(&aux, sizeof(stUsuario), 1, bufUs) > 0)
        {

            if((strcmp(usuario, aux.usuario) == 0) && aux.estado==1)
            {
                if(strcmp(contrasena, aux.contrasena) == 0)
                {

                    printf("\n\n\t\t\t\t\t     Inicio exitoso!\n\n");
                    int caracter = adminoUsuario(aux);
                    return caracter; // Usuario y contraseña coinciden
                }
                else
                {

                    printf("\n\n\t\t\t\t\tContraseña incorrecta!\n\n");
                    return -1; // Contraseña incorrecta
                }
            }

        }
        fclose(bufUs);
        printf("\n\n\t\t\t\t\tUsuario inexistente!\n\n");
        return -1; // Usuario no encontrado
    }
    else
    {
        printf("\n\n\t\t\t\t\tError al iniciar sesion\n\n");
        return -1;
    }
}

int adminoUsuario(stUsuario aux) // RETORNA 1 SI EL USUARIO ES ADMIN Y 2 SI ES USUARIO
{
    if(strcmp(aux.caracter, "Admin")==0)
    {
        return 1;
    }
    else
    {
        return 2;
    }

}

//

void formatearArchivo(char archivoUsuarios[])
{
    FILE*bufUs;
    bufUs=fopen(archivoUsuarios, "wb");
    if(bufUs)
    {
        fclose(bufUs);
    }
    else
    {
     printf("Error");
    }
}


// FUNCIONES MOSTRAR USUARIOS


void mostrarUnUsuario(stUsuario A)
{
    if(strlen(A.usuario)>0)
    {
        printf("\n\t============================================");
        printf("\n\t\t    Usuario: %s", A.usuario);
        printf("\n\t\t Contrasena: %s", A.contrasena);
        printf("\n\t\t       Mail: %s", A.mail);
        printf("\n\t\t  Documento: %s", A.documento);
        printf("\n\t\t   Caracter: %s", A.caracter);
        printf("\n\t\t  Direccion: %s", A.direccion);

    }
    else
    {
        printf("Error: usuario invalido!");
    }
}

void mostrarUsuariosActivos(char archivoUsuarios[]) //MUESTRA SOLO LOS USUARIOS QUE ESTAN ACTIVOS
{
    stUsuario aux;
    FILE*bufUs;
    bufUs=fopen(archivoUsuarios, "rb");
    if(bufUs)
    {
        while(fread(&aux, sizeof(stUsuario), 1, bufUs)>0)
        {
            if(aux.estado==1)
            {
                mostrarUnUsuario(aux);
            }
        }
        fclose(bufUs);
    }
    else
    {
        printf("ERROR");
    }
}


void mostrarUsuariosActivosRecursiva(FILE* bufUs) // MUESTRA SOLO LOS USUARIOS QUE ESTAN ACTIVOS EN FORMA RECURSIVA
{
    stUsuario aux;


    if (fread(&aux, sizeof(stUsuario), 1, bufUs) == 1)
    {
        if (aux.estado == 1)
        {
            mostrarUnUsuario(aux);
        }

        mostrarUsuariosActivosRecursiva(bufUs);
    }
    else
    {
        if (!feof(bufUs)) {

            printf("ERROR: Error de lectura del archivo\n");
        }

        return;
    }
}

void mostrarUsuariosActivoss(char archivoUsuarios[])
{
    FILE* bufUs;
    bufUs = fopen(archivoUsuarios, "rb");
    if (bufUs)
    {

        mostrarUsuariosActivosRecursiva(bufUs);
        fclose(bufUs);
    }
    else
    {
        printf("ERROR: No se pudo abrir el archivo");
    }
}


void mostrarTodosLosUsuarios (char archivoUsuarios[]) //MUESTRA TODOS LOS USUARIOS (se usa en la opcion de editar usuario para mostrar tambien los usuarios inactivos y asi poder activarlos si lo desea el usuaio
{
    stUsuario aux;
    FILE*bufUs;
    bufUs=fopen(archivoUsuarios, "rb");
    if(bufUs)
    {
        while(fread(&aux, sizeof(stUsuario), 1, bufUs)>0)
        {
            mostrarUnUsuario(aux);
            if(aux.estado==0)
            {
                printf("\n\t\t        Inactivo");
            }
        }

        fclose(bufUs);
    }
    else
    {
        printf("ERROR");
    }
}

void pasarMayusculaNombre(char usuario[]) //DECORACION
{
    for(int i = 0; usuario[i]; i++) {
    usuario[i] = toupper(usuario[i]);
}


}
