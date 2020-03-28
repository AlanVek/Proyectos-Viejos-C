#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define cantidad 10
#define limite 10

void cargar_lista(int lista[],int largo, int maximo);
int esta_en_ambos(int lista_1[],int lista_2[], int lista_en_ambos[],int largo);
void mostrar_lista(int lista[],int largo);
void ordenar_vector(int vector[],int largo);
int i,j;
int main()
{
    srand(time(NULL));
    int lista1[cantidad],lista2[cantidad],en_ambos[cantidad],cuantos_comparten;

    cargar_lista(lista1,cantidad,limite);
    cargar_lista(lista2,cantidad,limite);

    printf ("Lista 1: ");
    mostrar_lista(lista1,cantidad);
    printf ("\n\n");

    printf ("Lista 2: ");
    mostrar_lista(lista2,cantidad);
    printf ("\n\n");

    cuantos_comparten= esta_en_ambos(lista1,lista2,en_ambos,cantidad);
    ordenar_vector(en_ambos,cuantos_comparten);

    printf ("Lo que comparten: ");
    mostrar_lista(en_ambos,cuantos_comparten);

    printf ("\n");

    return 0;
}
void cargar_lista(int lista[],int largo,int maximo)
{
    for (i=0;i<largo;i++)
    {
        lista[i]=rand()%(maximo+1);
    }
}
void mostrar_lista(int lista[],int largo)
{
    for (i=0;i<largo;i++)
    {
        if (i==largo-1)
            printf ("%d",lista[i]);
        else
        printf ("%d/",lista[i]);
    }
}
int esta_en_ambos(int lista_1[],int lista_2[],int lista_en_ambos[],int largo)
{
    int contador_en_ambos,flag,k=0;
    for (i=0;i<largo;i++)
    {
        for (j=0;j<largo;j++)
        {
            if (lista_1[i]==lista_2[j])
            {
                flag=0;
                for (contador_en_ambos=0;contador_en_ambos<k;contador_en_ambos++)
                {
                    if (lista_en_ambos[contador_en_ambos]==lista_1[i])
                    {
                        flag=1;
                        break;
                    }
                }
                if (flag==0)
                {
                    lista_en_ambos[k]=lista_1[i];
                    k+=1;
                }
            }

        }
    }
    return k;
}
void ordenar_vector(int vector[],int largo)
{
    int aux;
    for (i=0;i<largo-1;i++)
    {
        for (j=i+1;j<largo;j++)
        {
            if (vector[j]<vector[i])
            {
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
        }
    }
}
