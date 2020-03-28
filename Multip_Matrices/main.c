#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define maximo 100
#define liminf 1
#define limsup 10
void mostrar_matriz(float vector[maximo][maximo],int fil, int col);
void cargar_matriz(float vector[maximo][maximo],int fil, int col);
void multiplicar_matrices (float vector1[maximo][maximo],float vector2[maximo][maximo],float matriz_multip[maximo][maximo],int fil1, int col1fil2,int col2);
int i,j;
int main()
{
    int filas1,columnas1,columnas2;
    float matriz1[maximo][maximo],matriz2[maximo][maximo],multip[maximo][maximo];
    srand(time(NULL));
    printf("Ingrese cantidad filas 1: ");
    scanf ("%d",&filas1);
    printf("\nIngrese cantidad columnas 1: ");
    scanf ("%d",&columnas1);
    printf("\nIngrese cantidad columnas 2: ");
    scanf ("%d",&columnas2);
    cargar_matriz(matriz1,filas1,columnas1);
    cargar_matriz(matriz2,columnas1,columnas2);
    printf ("\n\nMatriz 1:\n");
    mostrar_matriz(matriz1,filas1,columnas1);
    printf ("\n\nMatriz 2:\n");
    mostrar_matriz(matriz2,columnas1,columnas2);
    multiplicar_matrices(matriz1,matriz2,multip,filas1,columnas1,columnas2);
    printf ("\n\nMatriz multiplicacion:\n");
    mostrar_matriz(multip,filas1,columnas2);


    return 0;
}
void cargar_matriz(float vector[maximo][maximo],int fil, int col)
{
    float a;
    int b;
    for (i=0;i<fil;i++)
    {
        for (j=0;j<col;j++)
        {
            a=liminf+(rand()%((limsup-liminf+1)*10))*0.1;
            b=rand()%2;
            a*=pow(-1,b);
            vector[i][j]=a;
        }
    }
}
void mostrar_matriz(float vector[maximo][maximo],int fil, int col)
{
    for (i=0;i<fil;i++)
    {
        for (j=0;j<col;j++)
        {
            printf ("%.2f   ",vector[i][j]);
        }
        printf ("\n");
    }
}
void multiplicar_matrices (float vector1[maximo][maximo],float vector2[maximo][maximo],float matriz_multip[maximo][maximo],int fil1, int col1fil2,int col2)
{
    float suma;
    int t;
    for (i=0;i<fil1;i++)
    {
        for (j=0;j<col2;j++)
        {
            suma=0;
            for (t=0;t<col1fil2;t++)
            {
                suma+=(vector1[i][t]*vector2[t][j]);
            }
            matriz_multip[i][j]=suma;
        }
    }
}
