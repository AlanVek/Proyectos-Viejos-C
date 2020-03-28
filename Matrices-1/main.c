#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <time.h>
#define maximo 100
void cargar_matriz(float vector[maximo][maximo],int fil, int col);
float promedio_todos (float vector[maximo][maximo],int fil,int col);
float suma_valores_fila (float vector[maximo][maximo],int fila, int col);
float prod_diag_princ (float vector[maximo][maximo],int fila, int col);
float prod_diag_sec (float vector[maximo][maximo],int fila, int col);
int posit_y_neg_en_col(float vector[maximo][maximo],int fila, int col,int *positivos);
void mostrar_matriz(float vector[maximo][maximo],int fil, int col);
void trasponer_matriz(float vector[maximo][maximo],float vector_copia[maximo][maximo],int fil, int col);
int i,j;

int main()
{

    float matriz[maximo][maximo],matriz_copia[maximo][maximo];
    int filas,columnas,fila_suma,columna_busqueda,neg_en_col,*positivos;
    srand(time(NULL));
    printf ("Ingrese cantidad de filas: ");
    scanf ("%d",&filas);
    printf ("\nIngrese cantidad de columnas: ");
    scanf ("%d",&columnas);
    cargar_matriz (matriz,filas,columnas);
    printf ("\nMatriz:\n");
    mostrar_matriz (matriz,filas,columnas);
    printf ("\nPromedio de todos los valores: %.2f",promedio_todos(matriz,filas,columnas));
    printf ("\nIngrese fila a sumar: ");
    scanf ("%d",&fila_suma);
    while (fila_suma>filas)
    {
        printf ("\nLa fila seleccionada no puede ser mayor a %d. Intente de nuevo: ",filas);
        scanf ("%d",&fila_suma);
    }
    fila_suma-=1;
    printf ("\nSuma fila %d: %.2f",fila_suma+1,suma_valores_fila(matriz,fila_suma,columnas));
    printf ("\nProducto diagonal principal: %.2f",prod_diag_princ(matriz,filas,columnas));
    printf ("\nProducto diagonal secundaria: %.2f",prod_diag_sec(matriz,filas,columnas));
    printf ("\nIngresar columna a buscar negativos y positivos: ");
    scanf ("%d",&columna_busqueda);
    while (columna_busqueda>columnas)
    {
        printf ("\nLa columna seleccionada no puede ser mayor a %d. Intente de nuevo: ",columnas);
        scanf ("%d",&columna_busqueda);
    }
    columna_busqueda-=1;
    neg_en_col=posit_y_neg_en_col(matriz,filas,columna_busqueda,&positivos);
    printf ("\nCantidad de positivos en columna %d: %d",columna_busqueda+1,positivos);
    printf ("\nCantidad de negativos en columna %d: %d",columna_busqueda+1,neg_en_col);
    trasponer_matriz(matriz,matriz_copia,filas,columnas);
    printf ("\n\nMatriz traspuesta: ");
    printf ("\n");
    mostrar_matriz(matriz_copia,columnas,filas);


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
            a=1+(rand()%110)*0.1;
            b=rand()%2;
            a*=pow(-1,b);
            vector[i][j]=a;
        }
    }
}
float promedio_todos (float vector[maximo][maximo],int fil,int col)
{
    float suma=0.0;
    for (i=0;i<fil;i++)
    {
        for (j=0;j<col;j++)
        {
            suma+=vector[i][j];
        }
    }
    return (float) suma/(fil*col);
}
float suma_valores_fila (float vector[maximo][maximo],int fila, int col)
{
    float suma=0;
    for (i=0;i<col;i++)
    {
        suma+=vector[fila][i];
    }
    return suma;
}
float prod_diag_princ (float vector[maximo][maximo],int fila, int col)
{
    int minimo=fila;
    float producto=1;
    if (fila<col)
        minimo=fila;
    else
        minimo=col;
    for (i=0;i<minimo;i++)
        producto*=vector[i][i];
    return producto;
}
float prod_diag_sec (float vector[maximo][maximo],int fila, int col)
{
    int minimo=fila;
    float producto=1;
    if (fila<col)
        minimo=fila;
    else
        minimo=col;

    for (i=minimo-1;i>-1;i--)
    {
        producto*=vector[i][fila-i-1];
    }
    return producto;
}
int posit_y_neg_en_col(float vector[maximo][maximo],int fila, int col,int *positivos)
{
    int suma=0;
    *positivos=0;
    for (i=0;i<fila;i++)
    {
        if (vector[i][col]<0)
            suma+=1;
        else
            *positivos+=1;
    }
    return suma;
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
void trasponer_matriz(float vector[maximo][maximo],float vector_copia[maximo][maximo],int fil, int col)
{
    float aux;
    for (i=0;i<fil;i++)
    {
        for (j=0;j<col;j++)
        {
            vector_copia[j][i]=vector[i][j];
        }
    }
}
