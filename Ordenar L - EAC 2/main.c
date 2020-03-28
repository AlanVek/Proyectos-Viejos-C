#include <stdio.h>
#include <stdlib.h>
void Ordenar_Vector (float vector[], int cantidad);
int main()
{
    FILE *txt;
    int i,j,cantidad=0;
    float vector[400];
    int vector_frec[11];
    txt = fopen ("Valores_Finales.txt", "rt");
    if (txt==NULL)
    {
        printf ("No se puede abrir el archivo.\n");
        exit(9);
    }
    fscanf (txt,"%f\n",&vector[cantidad]);
    while (!(feof(txt)))
    {
        cantidad++;
        fscanf (txt,"%f\n",&vector[cantidad]);
    }
    cantidad++;
    //Ordenar_Vector(vector,cantidad);
    fclose(txt);
    //txt = fopen ("Valores_Finales.txt","wt");
    /*for (i=0;i<cantidad;i++)
    {
        fprintf (txt,"%f\n",vector[i]);
    }*/
    //fclose (txt);
    for (i=0;i<11;i++)
        vector_frec[i]=0;

    for (i=0;i<400;i++)
    {
        if (vector[i]<100)
        {
            vector_frec[0]++;
        }
        else
        {
            if (vector[i]<150)
                vector_frec[1]++;
            else
            {
                if (vector[i]<200)
                    vector_frec[2]++;
                else
                {
                    if (vector[i]<300)
                        vector_frec[3]++;
                    else
                    {
                        if (vector[i]<400)
                            vector_frec[4]++;
                        else
                        {
                            if (vector[i]<500)
                                vector_frec[5]++;
                            else
                            {
                                if (vector[i]<950)
                                    vector_frec[6]++;
                                else
                                    vector_frec[7]++;
                            }
                        }
                    }
                }
            }
        }
    }

    for (i=0;i<8;i++)
    {
        printf ("%d\n",vector_frec[i]);
    }

    return 0;
}
void Ordenar_Vector (float vector[], int cantidad)
{
    float aux;
    int i,j;
    for (i=0;i<cantidad-1;i++)
    {
        for (j=i+1;j<cantidad;j++)
        {
            if (vector[j]<vector[i])
            {
                aux=vector[j];
                vector[j]=vector[i];
                vector[i]=aux;
            }
        }
    }
}
