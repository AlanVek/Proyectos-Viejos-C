#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char tiempo[10],potencial[10],corriente[10];
} Medicion;

int main()
{
    FILE *txt,*txt2,*txt3;
    int i,cantidad=1;
    int p=0;
    Medicion vector[200];
    float vector_potencial[200];
    float vector_corriente [200];
    float a;

    txt=fopen ("Datos.txt","rt");
    txt2=fopen ("Datos - Resumen.txt","wt");
    txt3=fopen ("Datos.csv","wt");

    fscanf (txt,"%s\t%s\t%s",&vector[cantidad-1].tiempo,&vector[cantidad-1].potencial,&vector[cantidad-1].corriente);

    while (!(feof(txt)))
    {
        cantidad++;
        fscanf (txt,"%s\t%s\t%s",&vector[cantidad-1].tiempo,&vector[cantidad-1].potencial,&vector[cantidad-1].corriente);
    }
    fprintf (txt2,"Tiempo\t\tPotencial\tCorriente\n");
    fprintf (txt3,"Tiempo\tPotencial\tCorriente\n");

    for (i=0;i<cantidad;i+=5)
    {
        fprintf (txt2,"%s\t\t%s\t\t%s\n",vector[i].tiempo,vector[i].potencial,vector[i].corriente);
        fprintf (txt3,"%s\t%s\t%s\n",vector[i].tiempo,vector[i].potencial,vector[i].corriente);
    }

    fclose (txt);
    fclose (txt2);
    fclose (txt3);
    return 0;
}

