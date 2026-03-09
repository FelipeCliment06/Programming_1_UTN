#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int factorial_n(int num); /// punto 1
int potencia_n(int base,int exponente); /// punto 2
void mostrar_arreglo_r(int A[],int validos,int i); /// punto 3
void mostrar_arreglo_invertido_r(int A[],int validos,int i); /// punto 4
void mostrar_arreglo_r2(int A[],int validos);
int capicua_o_no(int A[],int i,int j); ///punto 5
int suma_re(int A[],int validos,int i); /// punto 6
int suma_re2(int A[],int validos); // en el parametro iria validos-1
int buscar_men(int A[],int validos,int i); /// punto 7
int buscar_men_archivo(char archivo[],int i); /// punto 8
int buscar_men_archivo_2(FILE *buffarraca,int i);
int buscar_men_archivo_main(char archivo[]);
void invertir_archivo(char archivo[],int i,int j); /// punto 9
void invertir_archivo_2(FILE *buffarraca,int i,int j); // punto 9 rediseñada para q solo abra el archivo una vez en el main
void invertir_archivo_main(char archivo[]);
void invertir_arreglo(int A[],int i,int j); // en el main se pasa validos-1 como j
void mostrar_archivo(char archivo[],int i); /// punto 10
void mostrar_archivo_2(FILE *buffarraca,int i);
void mostrar_archivo_main(char archivo[]);
void punto_11(); /// punto 11
int busqueda_arreglo(int A[],int validos,int i,int dato); /// punto 12
int cant_registros(char archivo[],int size);

int main()
{
    int tp_rec;
    do
    {
        system("cls");
        printf("punto n1(factorial de un numero)\n");
        printf("punto n2(potencia de un numero)\n");
        printf("punto n3(mostrar un arreglo)\n");
        printf("punto n4(mostrar arreglo invertido)\n");
        printf("punto n5(capicua si o no)\n");
        printf("punto n6(suma de un arreglo)\n");
        printf("punto n7(buscar el menor elemento de un arreglo)\n");
        printf("punto n8(buscar el menor elemento de un archivo)\n");
        printf("punto n9(invertir un archivo)\n");
        printf("punto n11(ingreso de char mostrado al reves)\n");
        printf("punto n12(busqueda en un arreglo)\n");
        printf("aprete 0 para cerrar\n");
        fflush(stdin);
        scanf("%i",&tp_rec);
        switch(tp_rec)
        {
        case 1:
            system("cls");
            printf("punto 1\n");
            printf("que numero queres saber :v?\n");
            fflush(stdin);
            int factoreo;
            scanf("%i",&factoreo);
            factoreo=factorial_n(factoreo);
            printf("%i\n",factoreo);
            system("pause");
            break;
        case 2:
            system("cls");
            printf("punto 2\n");
            printf("que numero quiere elevar y a que exponente\n");
            int bas,exp;
            scanf("%i",&bas);
            scanf("%i",&exp);
            int pot=potencia_n(bas,exp);
            printf("%i\n",pot);
            system("pause");
            break;
        case 3:
            system("cls");
            printf("punto 3\n");
            int A3[]= {1,2,3,4,5,6,7,8,9,10};
            mostrar_arreglo_r(A3,10,0);
            printf("|\n");
            system("pause");
            break;
        case 4:
            system("cls");
            printf("punto 4\n");
            int A4[]= {1,2,3,4,5,6,7,8,9,10};
//            mostrar_arreglo_invertido_r(A4,10,10);
            mostrar_arreglo_r2(A4,9);
            printf("\n"); // hace falta xq sino queda feo
//            printf("|\n");
            system("pause");
            break;
        case 5:
            system("cls");
            printf("punto 5\n");
            int A5[]= {2,1,0,1,2};
            if(capicua_o_no(A5,0,4)){
                printf("es cap\n");
            }
            else{
                printf("no es cap\n");
            }
            system("pause");
            break;
        case 6:
            system("cls");
            printf("punto 6\n");
            int A6[]= {1,2,3,4,5,6,7,8,9,10};
            int sumAr0=suma_re(A6,10,0);
            printf("%i\n",sumAr0);
            int sumar1=suma_re2(A6,9);
            printf("%i\n",sumar1);
            system("pause");
            break;
        case 7:
            system("cls");
            printf("punto 7\n");
            int A7[]= {9,2,3,8,5,1,7,8,9,10};
            int me=buscar_men(A7,10,0);
            printf("%i\n",me);
            system("pause");
            break;
        case 8:
            system("cls");
            printf("punto 8\n");
//            int A8[]= {9,2,3,8,5,1,7,8,9,10};
////            FILE *buffaraca;
////            buffaraca=fopen("A8","ab");
////            if(buffaraca){
////                fwrite(&A8,sizeof(int)*10,1,buffaraca);
////                fclose(buffaraca);
////            }
            char archivo8[]={"A9"};
            int men=buscar_men_archivo_main(archivo8);
            printf("%i\n",men);
            system("pause");
            break;
        case 9:
            system("cls");
            printf("punto 9\n");
//            int A9[]= {1,2,3,4,5,6,7,8,9,10};
//            mostrar_arreglo_r(A9,10,0);
//            invertir_arreglo(A9,0,9); //j como validos-1
//            mostrar_arreglo_r(A9,10,0);
//            FILE *buffaraca;
//            buffaraca=fopen("A9","wb");
//            if(buffaraca){
//                fwrite(&A9,sizeof(int)*10,1,buffaraca);
//                fclose(buffaraca);
//            }
            char archivo9[]={"A9"};
            mostrar_archivo(archivo9,0);
            invertir_archivo_main(archivo9);
            mostrar_archivo(archivo9,0);
            system("pause");
            break;
            case 10:
                system("cls");
                printf("punto 10\n");
                char archivo10[]={"A9"};
                mostrar_archivo_main(archivo10);
                system("pause");
                break;
        case 11:
            system("cls");
            printf("punto 11\n");
            punto_11();
            system("pause");
            break;
        case 12:
            system("cls");
            printf("punto 12\n");
            int A12[]= {1,2,3,4,5,6,7,8,9,10};
            mostrar_arreglo_r(A12,10,0);
            printf("que numero quiere buscar?\n");
            fflush(stdin);
            int dato;
            scanf("%i",&dato);
            if(busqueda_arreglo(A12,10,0,dato)){
                printf("el numero %i se encuentra en el arreglo\n",dato);
            }
            else{
                printf("el numero %i no se encuentra en el arreglo\n",dato);
            }
            system("pause");
            break;



        }
    }
    while(tp_rec!=0);
    return 0;
}

int factorial_n(int num) /// punto 1
{
    int fact;
    if(!num)
    {
        fact=1;
    }
    else
    {
        fact=(num)*factorial_n(num-1);
    }
    return fact;
}

int potencia_n(int base,int exponente) /// punto 2
{
    int pot;
    if(exponente==0)
    {
        pot=1;
    }
    else
    {
        pot=(base)*potencia_n(base,exponente-1);
    }
    return pot;
}

void mostrar_arreglo_r(int A[],int validos,int i) /// punto 3
{
    if(i!=validos){
        printf("|%i",A[i]);
        mostrar_arreglo_r(A,validos,i+1);
    }
    else{
    printf("\n\n");
    }
}

void mostrar_arreglo_r2(int A[],int validos)
{
    if(validos>-1)
    {
        mostrar_arreglo_r2(A,validos-1);
        printf("%i|",A[validos]);
    }
}

void mostrar_arreglo_invertido_r(int A[],int validos,int i) /// punto 4
{
//    i=validos;
    if(i!=0){
        printf("|%i",A[i-1]);
        mostrar_arreglo_invertido_r(A,validos,i-1);
    }
}

void mostrar_arreglo_invertido2(int A[],int validos)
{
    if(validos>-1)
    {
        printf("%i|",A[validos]);
        mostrar_arreglo_r2(A,validos-1);
    }
    else{
//        printf("%i|",A[validos]);
        printf("\n");
    }
}

int capicua_o_no(int A[],int i,int j) ///punto 5
{
    int cap;
//    printf("%i\n%i\n",A[i],A[j]);
    if(i<j){
        if(A[i]!=A[j]){
            return cap=0;
        }
        else{
            cap=capicua_o_no(A,i+1,j-1);
        }
    }
    else{
        cap=1;
    }

    return cap;
}

int suma_re(int A[],int validos,int i) /// punto 6
{
    int suma_a;
    if(i==validos-1)
    {
        suma_a=A[i];
    }
    else
    {
        suma_a=A[i]+suma_re(A,validos,i+1);
    }
    return suma_a;
}

int suma_re2(int A[],int validos) // en el parametro iria validos-1
{
    int suma_a=A[validos];
    if(validos>0){
        suma_a=A[validos]+suma_re2(A,validos-1);
    }
    return suma_a;
}

int buscar_men(int A[],int validos,int i) /// punto 7
{
    int men;
    if(i==validos-1)
    {
        men=A[i];
    }
    else{
        men=buscar_men(A,validos,i+1);
        if(A[i]<men){
            men=A[i];
        }
    }

    return men;
}

int buscar_men_archivo(char archivo[],int i) /// punto 8
{
    FILE *buffarraca=fopen(archivo,"rb");  // descubrimiento || es mucho mas eficiente abrir el archivo desde el main

    if(!buffarraca){
        printf("no se pudo abrir el archivo\n");
        return INT_MAX;
    }

    fseek(buffarraca,i*sizeof(int),SEEK_SET);
    int aux;
    int men;
    if(fread(&aux,sizeof(int),1,buffarraca)>0){
        fclose(buffarraca);
        men=buscar_men_archivo(archivo,i+1);
        if(aux<men){
            men=aux;
        }
    }
    else{
        fclose(buffarraca);
        men=INT_MAX;
    }
    return men;
}

int buscar_men_archivo_2(FILE *buffarraca,int i) // punto 8 repensado para que abra el archivo 1 sola vez en el main
{
    fseek(buffarraca,i*sizeof(int),SEEK_SET);
    int aux;
    int men;
    if(fread(&aux,sizeof(int),1,buffarraca)>0){
        men=buscar_men_archivo_2(buffarraca,i+1);
        if(aux<men){
            men=aux;
        }
    }
    else{
        men=INT_MAX;
    }
    return men;
}

int buscar_men_archivo_main(char archivo[])
{
    FILE *buffarraca=fopen(archivo,"rb");
    if(!buffarraca){
        exit(0);
    }

    int men=buscar_men_archivo_2(buffarraca,0);
    fclose(buffarraca);
    return men;
}

void invertir_arreglo(int A[],int i,int j) // en el main se pasa validos-1 como j
{
    int aux;
    if(i<j){
        aux=A[i];
        A[i]=A[j];
        A[j]=aux;
        invertir_arreglo(A,i+1,j-1);
    }
}

void invertir_archivo(char archivo[],int i,int j) /// punto 9
{
    FILE *buffarraca=fopen(archivo,"r+b");
    if(!buffarraca){
        exit(0);
    }


    int aux,aux2;
    if(i<j){
        fseek(buffarraca,i*sizeof(int),SEEK_SET);
        fread(&aux,sizeof(int),1,buffarraca);
        fseek(buffarraca,(j)*sizeof(int),SEEK_SET);
        fread(&aux2,sizeof(int),1,buffarraca);
        fseek(buffarraca,(i)*sizeof(int),SEEK_SET);
        fwrite(&aux2,sizeof(int),1,buffarraca);
        fseek(buffarraca,(j)*sizeof(int),SEEK_SET);
        fwrite(&aux,sizeof(int),1,buffarraca);
        fclose(buffarraca);
        invertir_archivo(archivo,i+1,j-1);
    }
    else{
        fclose(buffarraca);
    }

}

void invertir_archivo_2(FILE *buffarraca,int i,int j) // punto 9 rediseñada para q solo abra el archivo una vez en el main
{
    int aux,aux2;
    if(i<j){
        fseek(buffarraca,i*sizeof(int),SEEK_SET);
        fread(&aux,sizeof(int),1,buffarraca);
        fseek(buffarraca,(j)*sizeof(int),SEEK_SET);
        fread(&aux2,sizeof(int),1,buffarraca);
        fseek(buffarraca,(i)*sizeof(int),SEEK_SET);
        fwrite(&aux2,sizeof(int),1,buffarraca);
        fseek(buffarraca,(j)*sizeof(int),SEEK_SET);
        fwrite(&aux,sizeof(int),1,buffarraca);
        invertir_archivo_2(buffarraca,i+1,j-1);
    }
}

void invertir_archivo_main(char archivo[])
{
    int cant=cant_registros(archivo,sizeof(int));
    FILE *buffarraca=fopen(archivo,"r+b");
    if(!buffarraca){
        exit(0);
    }

    invertir_archivo_2(buffarraca,0,cant-1);
    fclose(buffarraca);
}

void mostrar_archivo(char archivo[],int i) /// punto 10
{
    FILE *buffarraca=fopen(archivo,"rb");
    if(!buffarraca){
        exit(0);
    }

    fseek(buffarraca,sizeof(int)*i,SEEK_SET);
    int aux;
    if(fread(&aux,sizeof(int),1,buffarraca)>0){
        printf("|%i",aux);
        mostrar_archivo(archivo,i+1);
    }
    else{
        printf("|\n");
    }
}

void mostrar_archivo_2(FILE *buffarraca,int i)
{
     fseek(buffarraca,sizeof(int)*i,SEEK_SET);
    int aux;
    if(fread(&aux,sizeof(int),1,buffarraca)>0){
        printf("|%i",aux);
        mostrar_archivo_2(buffarraca,i+1);
    }
    else{
        printf("|\n");
    }
}

void mostrar_archivo_main(char archivo[])
{
    FILE *buffarraca=fopen(archivo,"rb");
    if(!buffarraca){
        exit(0);
    }
    mostrar_archivo_2(buffarraca,0);
    fclose(buffarraca);
}

void punto_11() /// punto 11
{
    char tecla;
    printf("presione una tecla(presione * para salir)\n");
    fflush(stdin);
    scanf("%c",&tecla);
    if(tecla!='*'){
        punto_11();
        printf("%c\n",tecla);
    }
}

int busqueda_arreglo(int A[],int validos,int i,int dato) /// punto 12
{
    int flag=0;
    if(i<validos-1 && flag==0){
        if(dato==A[i]){
            flag=1;
        }
        else{
            flag=busqueda_arreglo(A,validos,i+1,dato);
        }
    }
    else{
        flag=0;
    }
    return flag;
}

int cant_registros(char archivo[],int size)
{
    FILE *buffarraca=fopen(archivo,"rb");
    fseek(buffarraca,0,SEEK_END);
    int x=ftell(buffarraca);
    fclose(buffarraca);
    int cant=x/size;
    return cant;
}
