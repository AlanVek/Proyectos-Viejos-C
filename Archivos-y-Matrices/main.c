#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define limsup 10
#define liminf 0
#define maximo 100
#include <math.h>
void cargar_matriz_en_archivo (FILE *bin, int dim);
void leer_matriz_de_archivo (FILE *bin, int vector[maximo][maximo],int dim);
void mostrar_matriz(int vector[maximo][maximo],int dim);
void cambiar_valor_matriz (FILE *bin,int vector[maximo][maximo],int dim);
void matriz_a_texto (FILE *txt, int vector[maximo][maximo],int dim);
int i,j;
int main()
{
    FILE *bin,*txt;
    int n,matriz[maximo][maximo];

    bin=fopen ("matriz.bin","w+b");
    txt=fopen("matriz.txt","wt");
    srand (time(NULL));

    printf ("Ingrese dimension matriz: ");
    scanf ("%d",&n),

    cargar_matriz_en_archivo (bin, n);
    fseek(bin,0,SEEK_SET);

    leer_matriz_de_archivo(bin,matriz,n);
    mostrar_matriz(matriz,n);
    cambiar_valor_matriz(bin,matriz,n);
    leer_matriz_de_archivo(bin,matriz,n);
    matriz_a_texto(txt,matriz,n);

    mostrar_matriz(matriz,n);
    printf ("\n");

    fclose (bin);
    fclose(txt);
    return 0;
}
void cargar_matriz_en_archivo (FILE *bin, int dim)
{
    int a;
    int b;
    for (i=0;i<dim*dim;i++)
    {
        a=liminf+(rand()%(limsup-liminf+1));
        b=rand()%2;
        a*=pow(-1,b);
        fwrite (&a, sizeof(int),1,bin);
    }
}
void leer_matriz_de_archivo (FILE *bin, int vector[maximo][maximo],int dim)
{
    for (i=0;i<dim;i++)
    {
        for (j=0;j<dim;j++)
        {
            fread (&vector[i][j],sizeof(int),1,bin);
        }
    }
}
void mostrar_matriz(int vector[maximo][maximo],int dim)
{
    for (i=0;i<dim;i++)
    {
        for (j=0;j<dim;j++)
        {
            printf ("%d   ",vector[i][j]);
        }
        printf ("\n");
    }
}
void cambiar_valor_matriz (FILE *bin,int vector[maximo][maximo],int dim)
{
    int fila,columna,valor;
    printf ("\nSeleccione fila: ");
    scanf ("%d",&fila);
    while (fila>dim)
    {
        printf ("No es fila correcta. Intente de nuevo: ");
        scanf ("%d",&fila);
    }
    fila-=1;
    printf ("\nSeleccione columna: ");
    scanf ("%d",&columna);
    while (columna>dim)
    {
        printf ("No es columna correcta. Intente de nuevo: ");
        scanf ("%d",&columna);
    }
    columna-=1;
    printf ("\nIngrese valor nuevo: ");
    scanf ("%d",&valor);
    vector[fila][columna]=valor;
    for (i=0;i<dim;i++)
    {
        for (j=0;j<dim;j++)
        {
            fwrite (&vector[i][j],sizeof(int),1,bin);
        }
    }

}
void matriz_a_texto (FILE *txt, int vector[maximo][maximo],int dim)
{
    for (i=0;i<dim;i++)
    {
        for (j=0;j<dim;j++)
        {
            fprintf (txt,"%d  ",vector[i][j]);
        }
        fprintf (txt,"\n");
    }
}
