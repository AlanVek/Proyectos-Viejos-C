#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define maximo 100
#define liminf 1
#define limsup 10
void mostrar_matriz(float vector[maximo][maximo],int fil, int col);
void cargar_matriz(float vector[maximo][maximo],int fil, int col);
void ordenar_vector (float n[maximo],int largo);
void fila_a_vector (float vector[maximo][maximo],float vector_copia[],int nrofila,int cols);
void mostrar_vector (float vector_c[],int largo);
int i,j;
int main()
{
    int filas,columnas,h;
    float matriz[maximo][maximo],vector_ayuda[maximo];
    srand(time(NULL));
    printf ("Ingresar filas: ");
    scanf ("%d",&filas);
    printf ("\nIngresar columnas: ");
    scanf ("%d",&columnas);
    cargar_matriz(matriz,filas,columnas);
    printf ("\n\nMatriz generada:\n ");
    mostrar_matriz(matriz,filas,columnas);

    printf ("\n\nMatriz con filas de menor a mayor:\n");
    for (h=0;h<filas;h++)
    {
        fila_a_vector(matriz,vector_ayuda,h,columnas);
        ordenar_vector(vector_ayuda,columnas);
        mostrar_vector(vector_ayuda,columnas);
    }


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
void ordenar_vector (float n[maximo],int largo)
{
    float aux;
    int t;
    for (t=0;t<largo-1;t++)
    {
        for (j=t+1;j<largo;j++)
        {
            if (n[j]<n[t])
            {
                aux=n[t];
                n[t]=n[j];
                n[j]=aux;
            }
        }
    }
}
void fila_a_vector (float vector[maximo][maximo],float vector_copia[],int nrofila,int cols)
{
    for (i=0;i<cols;i++)
    {
        vector_copia[i]=vector[nrofila][i];
    }
}
void mostrar_vector (float vector_c[],int largo)
{
    for (i=0;i<largo;i++)
    {
        printf ("%.2f  ",vector_c[i]);
    }
    printf ("\n");
}
