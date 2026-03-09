#ifndef FUNCIONESUSUARIO_H_INCLUDED
#define FUNCIONESUSUARIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// FUNCIONES DE LOGIN--

typedef struct stUsuario{
    char usuario[50]; //Sin espacios
    char contrasena[30];
    char mail[60];
    char direccion[30]; //Calle y altura
    char documento[9];
    char caracter[8]; //Admin o usuario
    int estado; // 0 inactivo, 1 activo;
} stUsuario;


stUsuario A;
int*usuariosValidos;
char usuario[50];
char contrasena[30];


//SWITCHES
int switchPanelInicio();
int switchPanelAdministrador();

stUsuario pantallaRegistrarUsuarioAdmin(stUsuario A);
void verificarOCrearArchivoUsuarios(char archivoUsuarios[]);
stUsuario pantallaRegistrarUsuario(stUsuario A);
int verificarRegistrarUsuario(char archivoUsuarios[], stUsuario A);
void erroresRegistrarUsuario(int error);
void registrarUsuarioMain(stUsuario A);
void pantallaIniciarSesion(char usuario[], char contrasena[]);
int verificarInicioSesion(char archivoUsuarios[], char usuario[], char contrasena[]);
void printErrorInicioSesion();
void registrarEnElArchivo(char archivoUsuarios[], stUsuario A);
void formatearArchivo(char archivoUsuarios[]);
void mostrarUnUsuario(stUsuario A);
void mostrarUsuariosActivos(char archivoUsuarios[]);
void mostrarTodosLosUsuarios (char archivoUsuarios[]);
int adminoUsuario(stUsuario aux);
void mostrarUsuariosActivosRecursiva(FILE*bufUs);
void mostrarUsuariosActivoss(char archivoUsuarios[]);
void pasarMayusculaNombre(char usuario[]);


#endif // FUNCIONESUSUARIO_H_INCLUDED
