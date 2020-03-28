#include <stdio.h>
#include <stdlib.h>
int comparar_strcmp(char vector1[],char vector2[]);
typedef struct
{
    int codigo;
    char nombre[50];
    char categoria;
    float sueldo;
} empleado;

int main()
{
    int i,j;
    FILE *nomina,*nomina_alfabetico;
    nomina=fopen ("nomina.txt","rt");
    empleado vector[100];
    empleado aux;
    for (i=0;i<100;i++)
    {
        fscanf (nomina,"%d ",&vector[i].codigo);
        fgets (vector[i].nombre,50,nomina);
        fgetc(nomina);
        vector[i].categoria=fgetc(nomina);
        fscanf (nomina,"%f",&vector[i].sueldo);
    }
    fclose (nomina);

    for (i=0;i<99;i++)
    {
        for (j=i+1;j<100;j++)
        {
            if (comparar_strcmp(vector[i].nombre,vector[j].nombre)>0)
            {
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
        }
    }
    nomina_alfabetico=fopen ("nomina_orden_alfab.txt","wt");
    for (i=0;i<100;i++)
    {
        fprintf(nomina_alfabetico,"%04d %s %c  %f\n", vector[i].codigo,vector[i].nombre,vector[i].categoria,vector[i].sueldo);
    }
    fclose (nomina_alfabetico);
}
int comparar_strcmp(char vector1[],char vector2[])
{
    int t=0;
    while (vector1[t]==vector2[t])
    {
        t+=1;
    }
     return vector1[t]-vector2[t];
}
