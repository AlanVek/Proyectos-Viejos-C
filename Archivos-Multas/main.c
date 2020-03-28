#include <stdio.h>
#include <stdlib.h>
#define maximo 10000
typedef struct
{
    int tipo,anio,mes,dia;
    char patente[6];
} infraccion;
typedef struct
{
    char patente[6];
    int monto;
    int cantidad;
} Auto;

void minamay (char cadena[]);
int monto_multas_porauto (infraccion vect[],char pat[], int *cant, int cuantos);
void cargar_archivo (FILE *total,FILE *txt,infraccion vect[maximo],Auto UnAuto,int *diez,int *once,int *doce,int cant_reg);
float tipoacosto (int tipo);

int i,j=0;
int main()
{
    FILE *infrac,*total,*txt;
    int cant_reg,ani;
    int diez=0,once=0,doce=0;
    infraccion vector[maximo];
    Auto UnAuto;

    infrac=fopen ("infracciones.bnr","r+b");
    fseek (infrac,0,SEEK_END);
    cant_reg=ftell(infrac);
    cant_reg=cant_reg/sizeof(infraccion);
    fseek (infrac,0,SEEK_SET);

    fread (&vector[j],sizeof(infraccion),1,infrac);
    while (!(feof(infrac)))
    {
        j+=1;
        fread (&vector[j],sizeof(infraccion),1,infrac);
    }

    total=fopen ("totalporauto.bin","w+b");
    txt=fopen("totalporauto.txt","w+t");
    for (j=0;j<cant_reg;j++)
    {
        minamay(vector[j].patente);
    }

    cargar_archivo(total,txt,vector,UnAuto,&diez,&once,&doce,cant_reg);

    for (ani=2010;ani<2013;ani++)
    {
        printf ("\n%d",ani);
        fprintf (txt,"\n%d",ani);
        if (ani==2010)
        {
            printf ("  Autos con mas de una multa: %d",diez);
            fprintf (txt,"  Autos con mas de una multa: %d",diez);
        }
        if (ani==2011){
            printf ("  Autos con mas de una multa: %d",once);
            fprintf (txt,"  Autos con mas de una multa: %d",once);
        }
        if (ani==2012){
            printf ("  Autos con mas de una multa: %d",doce);
            fprintf (txt,"  Autos con mas de una multa: %d",doce);
        }
    }

    printf ("\n");
    fclose (infrac);
    fclose (total);
    fclose(txt);
    return 0;
}
void minamay (char cadena[])
{
    i=0;
    while (cadena[i]!=0)
    {
        if (cadena[i]>96 && cadena[i]<123)
        {
            cadena[i]-=32;
        }
        i+=1;
    }
}
int monto_multas_porauto (infraccion vect[],char pat[], int *cant, int cuantos)
{
    int suma=0;
    *cant=0;
    int iguales,m,t;

    for (i=0;i<cuantos;i++)
    {
        if (vect[i].tipo!=0)
        {
            iguales=1;
            for (t=0;t<6;t++)
            {
                if (vect[i].patente[t]!=pat[t])
                    iguales=0;
            }
            if (iguales==1)
            {
                *cant=*cant+1;
                suma+=tipoacosto(vect[i].tipo);
                vect[i].tipo=0;

                for (m=0;m<6;m++)
                    vect[i].patente[m]=0;
            }
        }
    }
    return suma;
}
float tipoacosto (int tipo)
{
    switch (tipo)
    {
        case 1:
            tipo= 600;
            break;
        case 2:
            tipo= 1500;
            break;
        case 3:
            tipo =3000;
            break;
        case 4:
            tipo= 9000;
            break;
        case 5:
            tipo= 13000;
            break;
    }
    return tipo;
}
void cargar_archivo (FILE *total,FILE *txt,infraccion vect[maximo],Auto UnAuto,int *diez,int *once,int *doce,int cant_reg)
{
    int h,cant;
    char pat[6];
    for (j=0;j<cant_reg;j++)
    {
        if (vect[j].tipo!=0)
        {
            for (h=0;h<6;h++)
            {
                UnAuto.patente[h]=vect[j].patente[h];
                pat[h]=vect[j].patente[h];
            }

            UnAuto.monto= monto_multas_porauto (vect,pat,&cant,cant_reg);
            UnAuto.cantidad=cant;
            if (cant>1)
            {
                if (vect[j].anio==2010)
                    *diez+=1;
                if (vect[j].anio==2011)
                    *once+=1;
                if (vect[j].anio==2012)
                    *doce+=1;
            }
            fwrite (&UnAuto,sizeof(Auto),1,total);
            printf ("Patente: %s   Monto: %05d   Multas: %d\n",UnAuto.patente,UnAuto.monto,UnAuto.cantidad);
            fprintf (txt,"Patente: %s   Monto: %05d   Multas: %d\n",UnAuto.patente,UnAuto.monto,UnAuto.cantidad);
        }
    }

}
