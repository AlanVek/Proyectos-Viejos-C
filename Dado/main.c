﻿#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define cant_min 1
#define cant_max 6
#define tot_max 100000

typedef struct
{
    int numero;
    int cantidad;
} Dado;

void max_vector(Dado vector[],Dado vector2[]);
void actualizar_cant (int vector_cant[], Dado vector[],int *h);
void cargar_datos (FILE *csv,int vectorx[], int cantidad_dados);
void cargar_ronda (FILE *txt, Dado vector[],int cant_tiradas);

int i;
int main()
{
    int a,t,h=0,maximo,cant_dados,vector_cantidades[tot_max];
    FILE *txt,*csv;
    srand(time(NULL));
    Dado vector[cant_max],vector_mayores[cant_max];

    txt=fopen ("Dado.txt","w+t");
    csv=fopen ("Dado.csv","w+t");

    printf ("Ingrese cantidad de dados: ");
    scanf("%d",&cant_dados);
    while (cant_dados<1)
    {
        printf ("Error. Debe ser mayor a 0. Intente de nuevo: ");
        scanf ("%d",&cant_dados);
    }
    while (cant_dados*cant_max>tot_max)
    {
        printf ("La cantidad de dados no puede superar %d. Intente de nuevo: ",tot_max/cant_max);
        scanf ("%d",&cant_dados);
    }
    printf ("\nIngrese cantidad de tiros por dado: ");
    scanf("%d",&maximo);
    while (maximo<1)
    {
        printf ("Error. Debe ser mayor a 0. Intente de nuevo: ");
        scanf ("%d",&maximo);
    }

    printf ("\n");
    fprintf (csv, "Número,");

    for (i=0;i<cant_dados;i++)
        fprintf (csv,"Dado %d,",i+1);

    fprintf (csv,"Total\n");

    for (t=0;t<cant_dados;t++)
    {
        cargar_ronda(txt,vector,maximo);

        printf ("Dado %d de %d:\n",t+1,cant_dados);
        for (i=0;i<cant_max-cant_min+1;i++)
            printf ("%d: %d\n",vector[i].numero,vector[i].cantidad);

        max_vector(vector,vector_mayores);
        for (i=0;i<cant_max-cant_min+1;i++)
        {
            if (vector_mayores[i].cantidad==0)
                break;
        }

        printf ("\nMas veces: ");
        for (a=0;a<i;a++)
        {
            printf ("%d  ",vector_mayores[a].numero);
        }
        printf ("\nCantidad de veces: %d\n\n",vector_mayores[0].cantidad);

        actualizar_cant(vector_cantidades,vector,&h);
    }
    cargar_datos(csv,vector_cantidades,cant_dados);

    fclose(txt);
    fclose(csv);

    return 0;
}

void max_vector(Dado vector[],Dado vector2[])
{
    int k=1;
    Dado j=vector[0];
    for (i=1;i<cant_max-cant_min+1;i++)
    {
        if (vector[i].cantidad>j.cantidad)
            j=vector[i];
    }
    for (i=0;i<cant_max-cant_min+1;i++)
    {
        vector2[i].cantidad=0;
    }
    vector2[0]=j;
    for (i=0;i<cant_max-cant_min+1;i++)
    {
        if (vector[i].cantidad==j.cantidad && vector[i].numero!=j.numero)
        {
            vector2[k]=vector[i];
            k++;
        }
    }
}
void actualizar_cant (int vector_can[], Dado vector[],int *h)
{
    for (i=*h;i<cant_max+*h-cant_min+1;i++)
    {
        vector_can[i]=vector[i-*h].cantidad;
    }
    *h+=cant_max-cant_min+1;
}
void cargar_datos (FILE *csv,int vectorx[], int cantidad_dados)
{
    int l,s,total;
    for (l=cant_min-1;l<cant_max;l++)
    {
        total=0;
        fprintf (csv,"%d,",l+1);
        for (s=l-cant_min+1;s<cantidad_dados*(cant_max-cant_min+1);s+=(cant_max-cant_min+1))
        {
            fprintf (csv,"%d,",vectorx[s]);
            total+=vectorx[s];
        }
        fprintf (csv,"%d\n",total);
    }
}
void cargar_ronda (FILE *txt, Dado vector[],int cant_tiradas)
{
    int a;
    for (i=cant_min-1;i<cant_max;i++)
    {
        vector[i-cant_min+1].cantidad=0;
        vector[i-cant_min+1].numero=i+1;
    }
    for (i=0;i<cant_tiradas;i++)
    {
        a=cant_min+rand()%(cant_max-cant_min+1);
        fprintf (txt,"%d\n",a);
        vector[a-cant_min].cantidad++;
    }
    fprintf (txt,"-----------------------------------------\n");
}
 
