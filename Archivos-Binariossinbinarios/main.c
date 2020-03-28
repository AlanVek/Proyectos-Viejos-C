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
    FILE *nomina,*catA,*catB,*catC,*catD,*nominabin;
    nomina=fopen ("nomina.txt","rt");
    nominabin=fopen ("nomina.bin","w+b");
    int i;
    char a=00;
    empleado vector[100];
    for (i=0;i<100;i++)
    {
        fscanf (nomina,"%d ",&vector[i].codigo);
        fgets (vector[i].nombre,50,nomina);
        fgetc(nomina);
        vector[i].categoria=fgetc(nomina);
        fscanf (nomina,"%f",&vector[i].sueldo);
        fwrite(&vector[i],sizeof(empleado),1,nominabin);
    }
    catA=fopen ("categoriaA.bin","wb");
    catB=fopen ("categoriaB.bin","wb");
    catC=fopen ("categoriaC.bin","wb");
    catD=fopen ("categoriaD.bin","wb");

    for (i=0;i<100;i++)
    {
        if (vector[i].categoria=='A')
        {
            fwrite(&vector[i],sizeof(empleado),1,catA);
        }
        if (vector[i].categoria=='B')
        {
            fwrite(&vector[i],sizeof(empleado),1,catB);
        }
        if (vector[i].categoria=='C')
        {
           fwrite(&vector[i],sizeof(empleado),1,catC);
        }
        if (vector[i].categoria=='D')
        {
            fwrite(&vector[i],sizeof(empleado),1,catD);
        }
    }
    fclose (catA);
    fclose (catB);
    fclose (catC);
    fclose (catD);
    fclose (nomina);
    fclose(nominabin);
}
