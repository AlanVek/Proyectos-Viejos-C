#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define maximo 100
int buscar_en_vector (int vector[],int numero, int largo, int posic[], int *h);
void ordenar_vector (int vector[],int largo);
void mostrar_vector (int vector[],int largo);

int i,j;
int main()
{
    srand (time(NULL));
    FILE *txt;
    txt=fopen ("numeros_a_ordenar.txt","wt+");
    int *h, posiciones[maximo],vector_busqueda[maximo];
    for (i=0;i<maximo;i++)
    {
        vector_busqueda[i]=rand()%20;
    }
    ordenar_vector(vector_busqueda,maximo);
    mostrar_vector(vector_busqueda,maximo);
    for (i=0;i<maximo;i++)
    {
        fprintf (txt,"%d\n",vector_busqueda[i]);
    }
    if (buscar_en_vector(vector_busqueda,13,maximo,posiciones,&h)==-1)
        printf ("\n\nEl numero 13 no esta en el vector.\n\n");
    else
    {
        printf ("\n\nEl numero 13 esta en las posiciones: ");
        printf ("\n");
        ordenar_vector(posiciones,h);
        mostrar_vector(posiciones,h);
        printf ("\n\n");
    }
}
int buscar_en_vector (int vector[],int numero,int largo, int posic[], int *h)
{
    int inicio=0,inicioant,prom;
    *h=0;
    int finish=largo-1;
    i=inicio;
    while (vector[i]==numero)
    {
        posic[*h]=i;
        i+=1,
        *h+=1;
    }
    i=finish;
    while (vector[i]==numero)
    {
        posic[*h]=i;
        i-=1;
        *h+=1;
    }
    while (numero>=vector[inicio] && numero<=vector[finish] && inicio>=0 && inicio<=finish)
    {
        prom=(vector[inicio]+vector[finish]+numero)/3;
        if (prom>numero)
        {
            inicioant=inicio;
            for (i=0;i<largo;i++)
            {
                if (vector[i]!=0)
                {
                    inicio+=(prom/vector[i])-1;
                    if (inicio==inicioant)
                        return -1;
                    if (inicio>=finish)
                    {
                        finish=finish-1;
                        inicio=inicioant;
                        largo-=1;
                    }
                    break;
                }
            }
        }
        else
        {
            inicioant=inicio;
            inicio=inicio+(numero*largo/vector[finish])-1;
        }
        largo=largo-(inicio-inicioant);
        if (vector[inicio]==numero)
        {
            posic[*h]=inicio;
            *h+=1;
        }
        if (inicio!=finish)
            i=inicio+1;
        while (vector[i]==numero && i<finish)
        {
            posic[*h]=i;
            *h+=1;
            i+=1;
        }
        if (inicio!=0)
            i=inicio-1;
        while (vector[i]==numero && i>-1)
        {
            posic[*h]=i;
            *h+=1;
            i-=1;
        }
        if (inicio>=finish-1)
            return -1;
    }
    if (*h==0)
        return -1;
}
void ordenar_vector (int vector[],int largo)
{
    int aux;
    for (i=0;i<largo-1;i++)
    {
        for (j=i+1;j<largo;j++)
        {
            if (vector[i]>vector[j])
            {
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
        }
    }
}
void mostrar_vector (int vector[],int largo)
{
    for (i=0;i<largo;i++)
    {
        printf ("%d ",vector[i]);
    }
}
