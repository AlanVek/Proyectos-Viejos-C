#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define cant 10

void cargar_numeros_archivo (FILE *txt);
void cargar_vector_de_archivo (FILE *txt, int numeros[]);
void ordenar_vector (int numeros[]);
void vector_a_archivo (int numeros[],FILE *txt_ord);
int i;
int main()
{
    FILE *txt,*txt_ord;
    int vector[cant];

    srand(time(NULL));

    txt=fopen ("archivo-escribir.txt","wt");

    cargar_numeros_archivo (txt);

    fclose(txt);

    fopen ("archivo-escribir.txt","rt");

    cargar_vector_de_archivo (txt,vector);
    ordenar_vector (vector);

    txt_ord=fopen ("archivo-escribir-ordenado.txt","wt");

    vector_a_archivo (vector,txt_ord);

    fclose (txt);
    fclose (txt_ord);

    return 0;
}
void cargar_numeros_archivo (FILE *txt)
{
    int a;
    for (i=0;i<cant;i++)
    {
        a=rand()%101;
        fprintf (txt,"%d\n",a);
    }
}
void cargar_vector_de_archivo (FILE *txt, int numeros[])
{
    for (i=0;i<cant;i++)
    {
        fscanf(txt,"%d",&numeros[i]);
    }
}
void ordenar_vector (int numeros[])
{
    int aux,j;
    for (i=0;i<cant-1;i++)
    {
        for (j=i+1;j<cant;j++)
        {
            if (numeros[i]>numeros[j])
            {
                aux=numeros[i];
                numeros[i]=numeros[j];
                numeros[j]=aux;
            }
        }
    }
}
void vector_a_archivo (int numeros[],FILE *txt_ord)
{
    for (i=0;i<cant;i++)
    {
        fprintf (txt_ord,"%d\n",numeros[i]);
    }
}
