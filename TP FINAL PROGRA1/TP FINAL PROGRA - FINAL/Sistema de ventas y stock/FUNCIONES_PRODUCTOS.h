#ifndef FUNCIONES_PRODUCTOS_H_INCLUDED
#define FUNCIONES_PRODUCTOS_H_INCLUDED

typedef struct
{
    char nombre[90];
    float precio;
    int codigo;
    int stock;
    int estado;

} Producto ;

Producto Cargar_1_Producto();

int controlarSalirDeCargar();

void Cargar_Varios_Productos(char archivoProducto[]);

int Verificar_Productos(Producto UltProducto, char archivoProducto[]);

void Mostra_1_producto(Producto producto);

void mostrar_Arreglo_Productos(Producto arreglo[],int validosProductos);

int  Pasar_A_Arreglo_Dinamico(char archivoProducto[],Producto **arreglo);

int Cant_Elementos_En_El_Arch(char archivoProducto[],int TamanioStruct);

void Ordenar_Seleccion_ABC(Producto arreglo[],int validosProductos);

int Encontrar_Menor(Producto arreglo[],int validosProductos,int pos);

void Pasar_A_Archivo_El_Arreglo(Producto arreglo[],int validosProductos,char archivoProducto[]);

int buscar_Producto(char archivoProducto[],char buscado[]);

int buscar_Producto_Codigo(char archivoProducto[], int codigo);

void Modificar_Productos(char archivoProducto[],char buscado[]);

void Modificar_Nombre(char archivoProducto[],int pos);

void Modificar_Precio(char archivoProducto[],int pos);

void Modificar_Codigo(char archivoProducto[],int pos);

void Modificar_Stock(char archivoProducto[],int pos);

void Modificar_Estado(char archivoProducto[],int pos);

void Ordenar_Inser_Menor_Precio(Producto arreglo[],int validosProductos);

void Insertar_En_Orden_Menor(Producto arreglo[], int posicion);

void Ordenar_Inser_Mayor_Precio(Producto arreglo[],int validosProductos);

void Insertar_En_Orden_Mayor(Producto arreglo[], int posicion);

void Mostrar_Buscado(char archivoProducto[],char buscado[]);

#endif // FUNCIONES_PRODUCTOS_H_INCLUDED
