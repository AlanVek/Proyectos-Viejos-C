#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int codigo;
    char nombre[50];
    char categoria;
    float sueldo;
} empleado;
int main()
{
    FILE *nomina,*nomina_ordenado;
    nomina=fopen ("nomina.txt","rt");
    int i,j;
    char a=00;
    empleado vector[100],aux;
    for (i=0;i<100;i++)
    {
        fscanf (nomina,"%d ",&vector[i].codigo);
        fgets (vector[i].nombre,50,nomina);
        fgetc(nomina);
        vector[i].categoria=fgetc(nomina);
        fscanf (nomina,"%f",&vector[i].sueldo);
    }

    for (i=0;i<100;i++)
    {
       for (j=i+1;j<100;j++)
       {
           if (vector[i].sueldo<vector[j].sueldo)
           {
               aux=vector[i];
               vector[i]=vector[j];
               vector[j]=aux;
           }
       }
    }
    nomina_ordenado=fopen("nomina_orden.txt","wt");
    for (i=0;i<100;i++)
    {
        fprintf (nomina_ordenado,"%d %s %c %f\n",vector[i].codigo,vector[i].nombre,vector[i].categoria,vector[i].sueldo);
    }
    fclose (nomina);
    fclose (nomina_ordenado);

    return 0;
}
