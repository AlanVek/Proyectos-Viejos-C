#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int codigo,comuna;
    char nombre[50];
} Barrio;
int main()
{
    FILE *txt;
    int i,j;
    Barrio vector_barrios[48],aux;

    txt=fopen("barriosycomunas.txt","rt");
    for (i=0;i<48;i++)
    {
        fscanf (txt,"%d,%s ,%d",&vector_barrios[i].codigo,&vector_barrios[i].nombre,&vector_barrios[i].comuna);
    }

    for (i=0;i<47;i++)
    {
        for (j=i+1;j<48;j++)
        {
            if ((vector_barrios[i].comuna)<(vector_barrios[j].comuna))
            {
                aux=vector_barrios[i];
                vector_barrios[i]=vector_barrios[j];
                vector_barrios[j]=aux;
            }
        }
    }
    for (i=0;i<48;i++)
    {
        printf ("%d,%s ,%d\n",vector_barrios[i].codigo,vector_barrios[i].nombre,vector_barrios[i].comuna);
    }

    fclose(txt);
    return 0;
}
