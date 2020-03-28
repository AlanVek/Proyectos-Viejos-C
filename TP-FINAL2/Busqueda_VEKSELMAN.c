#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define maximo 99999
#define n 4800
int buscar_en_vector (int vector[],int numero, int posic[], int *h);
void mostrar_vector (int vector[], int largo);
int i,j;
int main()
{
    int *h, posiciones[maximo],vector_busqueda[maximo];
    FILE *txt;
    txt=fopen ("numeros_a_ordenar.txt","rt");
    for (i=0;i<maximo;i++)
    {
        fscanf (txt,"%d",&vector_busqueda[i]);
    }
    if (buscar_en_vector(vector_busqueda,n,posiciones,&h)==-1)
        printf ("\n\nEl numero %d no esta en el vector.\n\n",n);
    else
    {
        printf ("\n\nEl numero %d esta en las posiciones: ",n);
        printf ("\n");
        mostrar_vector(posiciones,h);
        printf ("\n\nAparece %d veces",h);
        printf ("\n\n");
    }
    fclose (txt);
    return 0;
}
int buscar_en_vector (int vector[],int numero, int posic[], int *h)
{
    int inicio=0,a;
    double prom;
    *h=0;
    int finish=maximo-1;

    while (inicio<finish-1)
    {
        prom=(double) (vector[inicio]+vector[finish]+numero)/3;

        a= prom*finish/vector[finish];

        if (vector[a]>numero)
            finish=a;

        else
            inicio=a;

        if (vector[a]==numero)
        {
            posic[*h]=a;
            *h+=1;
            i=a+1;
            while (vector[i]==numero && i<maximo)
            {
                posic[*h]=i;
                *h+=1;
                i+=1;
            }
            i=a-1;
            while (vector[i]==numero && i>-1)
            {
                posic[*h]=i;
                *h+=1;
                i-=1;
            }
            return 1;
        }
    }
    return -1;
}
void mostrar_vector (int vector[], int largo)
{
    for (i=0;i<largo;i++)
    {
        printf ("%d ",vector[i]);
    }
}
