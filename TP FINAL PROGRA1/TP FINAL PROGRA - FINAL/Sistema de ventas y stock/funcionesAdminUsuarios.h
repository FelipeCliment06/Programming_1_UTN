#ifndef FUNCIONESADMINUSUARIOS_H_INCLUDED
#define FUNCIONESADMINUSUARIOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// FUNCIONES ADMINISTRADOR PARA MANEJO USUARIOS--


void buscarPorInicial(char archivoUsuarios[], char inicial);
int menuUsuariosAdmin();
void buscarUnUsuario(char archivoUsuarios[], stUsuario A);
void eliminarUsuario(char archivoUsuarios[], char usuario[]);
stUsuario darDeBajaUsuario(stUsuario A);
void editarUsuario (char archivoUsuarios[], char usuario[], char campo[]);
stUsuario modificarUsuario(stUsuario A);
stUsuario modificarMail(stUsuario A);
stUsuario modificarDocumento(stUsuario A);
stUsuario modificarDireccion(stUsuario A);
stUsuario modificarEstado(stUsuario A);
stUsuario modificarCaracter(stUsuario A);
stUsuario modificarContrasena(stUsuario A);


#endif // FUNCIONESADMINUSUARIOS_H_INCLUDED
