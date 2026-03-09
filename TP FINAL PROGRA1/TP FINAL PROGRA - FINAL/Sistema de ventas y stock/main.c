#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesUsuario.h"
#include "funcionesAdminUsuarios.h"
#include "FUNCIONES_PRODUCTOS.h"
#include "productos.h"

///SRUCTS



int main()
{
    system("color 0a");

    char archivoUsuarios[]="archivoUsuarios";
    char archivoProducto [] = {"productos"};
    char archivoDeVentas[] = "archivoTotales.bin";


//FUNCION PRIMER USO DEL PROGRAMA
    verificarOCrearArchivoUsuarios(archivoUsuarios);




//DECLARACIONES Y VARIABLES DE LOS SWITCH FUNCIONES DEL ADMIN
//USUARIOS
    int swLogin;
    int swCaracter;
    int swAdmin;
    int swUsuariosAdmin;
    char confirmar;


//PRODUCTOS
    int sw_menuProductos;
    char control_ABM='s';
    char control_Orden='s';
    char control_Busc='s';
    int sw_Orden;

//VENTAS
    int swPanelUsuario;


//DECLARACIONES DE VARIABLES y ESTRUCTURAS
    //USUARIO
    stUsuario A;
    char inicial;
    char campo[10];

    //PRODUCTOS
    char buscado[30];
    Producto * arreglo;
    int validosProductos=0;


    //VENTAS
    float total=0;
    char control='s';
    int codigos[30];
    int validos;



    // MAIN /////////

    do
    {
        swLogin = switchPanelInicio();
        switch(swLogin)
        {

        case 1:  // INICIAR SESION

            pantallaIniciarSesion(usuario, contrasena);
            swCaracter = verificarInicioSesion(archivoUsuarios, usuario, contrasena);

            system("pause");
            system("cls");

                switch(swCaracter)
                {

                case 1: //PANEL ADMINISTRADOR
                        do
                        {
                            swAdmin = switchPanelAdministrador();
                            switch(swAdmin)
                            {

                            case 1: // PRODUCTOS
                                do
                                    {
                                        printf("\n\n\t\t\t  CARGAR PRODUCTOS  |  MODIFICAR LISTA  |  VER LISTA  |  BUSCAR  |  VOLVER  ");
                                        printf("\n\t\t\t       (1)                 (2)                (3)          (4)        (0)\n\n");
                                        scanf("%d",&sw_menuProductos);
                                        switch(sw_menuProductos)
                                        {
                                            case 1: //CARGAR PRODUCTOS
                                                system("cls");
                                                printf("\n\n\t\t\t\t\t  CARGAR PRODUCTOS               \n\n\n");
                                                printf("Comenzar Carga? s/n: ");
                                                scanf(" %c",&confirmar);
                                                if(confirmar=='s'|| confirmar=='S')
                                                {
                                                    Cargar_Varios_Productos(archivoProducto);
                                                }
                                                system("cls");
                                                    break;

                                            case 2: // MODIFICAR LISTA

                                                system("cls");
                                                printf("\n\n\t\t\t\t\t  MODIFICAR LISTA               \n\n\n");
                                                printf("Comenzar Modificacion? s/n: ");
                                                scanf(" %c",&confirmar);
                                                if(confirmar=='s'|| confirmar=='S'){
                                                control_ABM='s';
                                                while(control_ABM=='s')
                                                {
                                                    validosProductos=Pasar_A_Arreglo_Dinamico(archivoProducto, &arreglo);
                                                    Ordenar_Seleccion_ABC(arreglo,validosProductos);
                                                    printf("LISTA:");
                                                    mostrar_Arreglo_Productos(arreglo,validosProductos);
                                                    printf("\n\nIngrese el nombre del producto que desee modificar: ");
                                                    fflush(stdin);
                                                    gets(buscado);
                                                    system("cls");
                                                    printf("\nProducto seleccionado:\n\n");
                                                    Mostrar_Buscado(archivoProducto,buscado);
                                                    Modificar_Productos(archivoProducto,buscado);
                                                    printf("Desea modificar otro producto?(s/n): ");
                                                    fflush(stdin);
                                                    scanf(" %c",&control_ABM);


                                                        system("cls");
                                                }
                                                }
                                                system("cls");
                                                    break;

                                            case 3: // VER LISTA


                                                do
                                                {
                                                    system("cls");
                                                    printf("\n\n\t\t\t\t\t\t\tVER LISTA \n\n");

                                                    printf("\n\t\t\t   MENOR PRECIO(1)  |  MAYOR PRECIO(2)  |  ALFABETICO(3)  |  VOLVER(0) \n\n\n");
                                                    printf("Elija la opcion que desee: ");
                                                    fflush(stdin);
                                                    scanf("%d", &sw_Orden);
                                                    validosProductos=Pasar_A_Arreglo_Dinamico(archivoProducto, &arreglo);
                                                    if(sw_Orden!=0)
                                                    {

                                                    switch(sw_Orden)
                                                    {

                                                            case 1:
                                                                Ordenar_Inser_Menor_Precio(arreglo,validosProductos);
                                                                mostrar_Arreglo_Productos(arreglo,validosProductos);

                                                                    break;

                                                            case 2:
                                                                Ordenar_Inser_Mayor_Precio(arreglo,validosProductos);
                                                                mostrar_Arreglo_Productos(arreglo,validosProductos);

                                                                    break;

                                                            case 3:
                                                                Ordenar_Seleccion_ABC(arreglo,validosProductos);
                                                                mostrar_Arreglo_Productos(arreglo,validosProductos);
                                                                    break;

                                                    }

                                                            printf("\n\nDesea ordenar la lista nuevamente?(s/n): ");
                                                            fflush(stdin);
                                                            scanf(" %c",&control_Orden);

                                                        }
                                                        else
                                                        {
                                                            break;
                                                        }
                                                    }while(control_Orden=='s');

                                                system("cls");

                                                break;

                                            case 4: // BUSCAR

                                                do{
                                                    system("cls");
                                                    printf("\n\n\t\t\t\t\t\tBUSCAR PRODUCTO\n\n");
                                                    printf("\nDesea comenzar a buscar producto? s/n: ");
                                                    fflush(stdin);
                                                    scanf(" %c", &confirmar);
                                                    if(confirmar=='s'|| confirmar=='S')
                                                    {
                                                        system("cls");
                                                        printf("\n\n\t\t\t\t\t\tBUSCAR PRODUCTO\n\n");
                                                        validosProductos=Pasar_A_Arreglo_Dinamico(archivoProducto, &arreglo);
                                                        printf("\nIngrese el nombre del producto buscado: ");
                                                        fflush(stdin);
                                                        gets(buscado);

                                                        Mostrar_Buscado(archivoProducto,buscado);

                                                        printf("\n\nDesea ver otro producto?(s/n): ");
                                                        fflush(stdin);
                                                        scanf("%c",&control_Busc);

                                                        system("cls");
                                                    }
                                                    else
                                                    {
                                                        break;
                                                    }
                                                  }while(control_Busc=='s');
                                                  system("cls");

                                                    break;


                                        }
                                        }while(sw_menuProductos!=0);
                                        system("cls");



                                    break; //break case 1 (productos)

                            case 2: // USUARIOS

                                do{
                                        mostrarUsuariosActivoss(archivoUsuarios);
                                        swUsuariosAdmin= menuUsuariosAdmin();
                                        switch(swUsuariosAdmin)
                                        {

                                        case 1: //BUSCAR UN USUARIO
                                            printf("\n\n\t\t\t\tIngrese la inicial a buscar: ");
                                            fflush(stdin);
                                            scanf(" %c", &inicial);

                                            buscarPorInicial(archivoUsuarios, inicial);
                                            printf("\n\n");
                                            system("pause");
                                            system("cls");
                                                break; //break case 1 (buscar usuario)


                                        case 2: //REGISTRAR UN USUARIO
                                            registrarUsuarioMain(A);
                                            system("pause");
                                            system("cls");
                                                break; //break case 2 (registrar usuario)

                                        case 3: // ELIMINAR UN USUARIO
                                            system("cls");
                                            mostrarUsuariosActivos(archivoUsuarios);

                                            printf("\n\n\t\t\t\tIngrese el nombre del usuario que desea eliminar: ");
                                            fflush(stdin);
                                            gets(usuario);
                                            eliminarUsuario(archivoUsuarios, usuario);
                                            system("pause");
                                            system("cls");

                                                break; //break case 3 (eliminar usuario)

                                        case 4: //EDITAR UN USUARIO
                                            system("cls");
                                            mostrarTodosLosUsuarios(archivoUsuarios);

                                            printf("\n\n\t\t\t\tIngrese el nombre de usuario que desea editar (n): ");
                                            fflush(stdin);
                                            gets(usuario);
                                            if(strcmpi(usuario, "n")==0)
                                            {
                                                system("cls");
                                                break;
                                            }
                                            printf("\n\n\t\t\t\tIgrese el campo que desea modificar: ");
                                            gets(campo);
                                            editarUsuario(archivoUsuarios, usuario, campo);
                                            system("pause");
                                            system("cls");

                                                break; //break case 4 editar usuario)




                                            }
                                        } while(swUsuariosAdmin!=0);
                                        break;// break case 2 (panel usuarios)

                            case 3: // CAJA
                                printf("\n\n\t\t\t\t\t\t\tCAJA \n\n");
                                mostrarArchivoTotal(archivoDeVentas);
                                printf("\n\n");
                                system("pause");
                                system("cls");

                                    break; // break case 3 (caja)


                                case 4:  //CERRAR SESION
                                    system("cls");
                                    printf("\n\n");
                                    printf("\n\n\t\t\t\tSeguro desea cerrar sesion? s/n: ");
                                    scanf(" %c", &confirmar);
                                    if(confirmar=='s' || confirmar=='S')
                                    {
                                        system("cls");
                                        swAdmin=0;
                                    }
                                        system("cls");
                                            break;
                                    }

                            }while(swAdmin!=0);
                        break;

                // PANEL DE USUARIO


                case 2: //PANEL USUARIO
                    do{
                        pasarMayusculaNombre(usuario);
                        printf("\n\n\t\t\t\t\t\tBIENVENIDO: %s !\n\n", usuario);
                        printf("\n\n\t\t\t\t\t NUEVA VENTA(1) |  CERRAR SESION(2)\n\n");
                        fflush(stdin);
                        scanf(" %i", &swPanelUsuario);
                        switch(swPanelUsuario)
                        {
                        case 1:
                            mostrarLista(archivoProducto);

                            total=pedirCodigoYRetornarTotal(archivoProducto, codigos, &validos);
                            printf("\n---------------------------\n");
                            printf("|TOTAL...........$%.2f|", total);
                            printf("\n---------------------------\n");

                            printf("\n\tVENDER? s/n: ");
                            fflush(stdin);
                            scanf("%c", &control);

                            if (control=='s')
                            {
                                printf ("\n\tVENDIDO!\n\n");
                                cargarTotalEnArchivo(archivoDeVentas, total);
                                mostrarArchivoTotal(archivoDeVentas);
                                restarArregloAlArhivo(archivoProducto, codigos, validos);
                            }

                            printf("\n\n");

                            break;
                        case 2: // CERRAR SESION
                            break;


                        }
                        system("pause");
                        system("cls");
                    }while(swPanelUsuario!=2);
                break; // break case 2 (PANEL USUARUI)

            }
            break;

                case 2: // REGISTRAR USUARIO

                    registrarUsuarioMain(A);

                    break;

        }
    }
    while((swLogin!=0)&&(swCaracter!=0));
    return 0;
}
