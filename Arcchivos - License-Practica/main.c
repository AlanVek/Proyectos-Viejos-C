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
    FILE *txt,*nomina;
    char palabra[1500];
    int i,h;
    empleado vector[1000];
    txt=fopen("LICENSE.txt","rt+");
    fgets (palabra,1500,txt);
    while (!feof(txt))
    {
        printf ("%s\n",palabra);
        fgets(palabra,1500,txt);
    }
    nomina=fopen ("nomina.txt","rt");
    i=0;
    fscanf (nomina,"%d ",&vector[0].codigo);
    while (!feof(nomina))
    {
        fscanf (nomina,"%d ",&vector[i].codigo);
        fgets (vector[i].nombre,50,nomina);
        fgetc(nomina);
        vector[i].categoria=fgetc(nomina);
        fscanf (nomina,"%f",&vector[i].sueldo);
        i+=1;
        fscanf (nomina,"%d ",&vector[i].codigo);
    }
    fprintf (txt,"\n\n\n");
    for (h=0;h<i;h++)
    {
        fprintf (txt,"%04d %s %c  %f\n", vector[h].codigo,vector[h].nombre,vector[h].categoria,vector[h].sueldo);
    }
    for (h=0;h<i;h++)
    {
        printf ("%04d %s %c  %f\n", vector[h].codigo,vector[h].nombre,vector[h].categoria,vector[h].sueldo);
    }

    fclose (txt);
    fclose (nomina);
    return 0;

}
