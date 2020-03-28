#include <stdio.h>
#include <stdlib.h>
#define cantidad 500

int longitud_1 (char vector[]);
void uno_despues_otro_2 (char vector1[],char vector2[]);
void uno_dentro_otro_3 (char vector1[],char vector2[],char vector_copia[],int posicion);
int comparar_strcmp_4(char vector1[],char vector2[]);
int string_dentro_otro_5 (char vector1[],char vector2[]);
void mayus_o_min_6 (char vector1[],int cual);
void limpiar_vector (char vector[]);
int i;
int main()
{
    int opcion,posic,mayomin;
    char cadena1[cantidad],cadena2[cantidad],cadena_copia[cantidad];

    while (1==1)
    {
        limpiar_vector(cadena1);
        limpiar_vector(cadena2);
        limpiar_vector(cadena_copia);

        printf ("0- Salir.\n");
        printf ("1- Dar longitud de string.\n");
        printf ("2- Copiar un string despues de otro.\n");
        printf ("3- Insertar un string dentro de otro.\n");
        printf ("4- Comparar dos strings segun norma strcmp.\n");
        printf ("5- Buscar un string dentro de otro.\n");
        printf ("6- Convertir string a mayuscula o minuscula.\n");

        printf ("\n\nOpcion: ");
        scanf ("%d",&opcion);

        while (opcion<0 || opcion>6)
        {
            printf ("\nNo ingreso una opcion correcta. Intente de nuevo: ");
            scanf ("%d",&opcion);
        }

        switch (opcion)
        {
            case 1:
            {
                gets (cadena1);
                printf ("\nIngrese cadena: ");
                gets (cadena1);
                printf ("\nSu longitud es: %d",longitud_1(cadena1));
                break;
            }
            case 2:
            {
                gets (cadena1);
                printf ("\nIngrese cadena 1: ");
                gets (cadena1);
                printf ("\nIngrese cadena 2: ");
                gets (cadena2);
                uno_despues_otro_2 (cadena1,cadena2);
                printf ("\n%s",cadena1);
                break;
            }
            case 3:
            {
                gets (cadena1);
                printf ("\nIngrese cadena 1: ");
                gets (cadena1);
                printf ("\nIngrese cadena 2: ");
                gets (cadena2);
                printf ("\nIngrese posicion: ");
                scanf ("%d",&posic);
                uno_dentro_otro_3 (cadena1,cadena2,cadena_copia,posic);
                printf ("\n%s",cadena_copia);
                break;
            }
            case 4:
            {
                gets (cadena1);
                printf ("\nIngrese cadena 1: ");
                gets (cadena1);
                printf ("\nIngrese cadena 2: ");
                gets (cadena2);
                printf ("\nResultado de comparacion: %d",comparar_strcmp_4(cadena1,cadena2));
                break;
            }
            case 5:
            {
                gets (cadena1);
                printf ("\nIngrese cadena 1: ");
                gets (cadena1);
                printf ("\nIngrese cadena 2: ");
                gets (cadena2);
                printf ("\nPosicion: %d",string_dentro_otro_5 (cadena1,cadena2));
                break;
            }
            case 6:
            {
                gets (cadena1);
                printf ("\nIngrese cadena: ");
                gets (cadena1);
                printf ("\nIngrese 1 para convertir a mayusculas o 2 para minusculas: ");
                scanf ("%d",&mayomin);
                while (mayomin<1||mayomin>2)
                {
                    printf ("\nDebe ingresar 1 o 2. Intente de nuevo: ");
                    scanf ("%d",&mayomin);
                }
                mayus_o_min_6 (cadena1,mayomin);
                printf ("\n%s",cadena1);
                break;
            }
        }
        if (opcion==0)
            break;
        printf ("\n\n");
    }
    printf ("\nHasta luego.\n");
    return 0;
}
int longitud_1 (char vector[])
{
    i=0;
    while (vector[i]!=0)
    {
        i+=1;
    }
    return i;
}
void uno_despues_otro_2 (char vector1[],char vector2[])
{
    int largo1=longitud_1(vector1);
    int largo2=longitud_1(vector2);
    int t;
    for (t=0;t<largo2;t++)
    {
        vector1[t+largo1]=vector2[t];
    }
}
void uno_dentro_otro_3 (char vector1[],char vector2[],char vector_copia[],int posicion)
{
    int j;
    int largo1=longitud_1(vector1);
    int largo2=longitud_1(vector2);

    for (j=0;j<posicion;j++)
    {
        vector_copia[j]=vector1[j];
    }
    for (j=posicion;j<(posicion+largo2);j++)
    {
        vector_copia[j]=vector2[j-posicion];
    }
    for (j=(posicion+largo2);j<(largo2+largo1);j++)
    {
        vector_copia[j]=vector1[j-largo2];
    }
    vector_copia[largo1+largo2]=0;
}
int comparar_strcmp_4(char vector1[],char vector2[])
{
    while (vector1[i]==vector2[i])
    {
        i+=1;
    }
     return vector1[i]-vector2[i];
}
int string_dentro_otro_5 (char vector1[],char vector2[])
{
    int contador1,t,iguales=0;
    int largo1=longitud_1(vector1);
    int largo2=longitud_1(vector2);

    for (contador1=0;contador1<largo1;contador1++)
    {
        if (vector1[contador1]==vector2[0])
        {
            iguales=1;
            for (t=contador1+1;t<largo2+contador1;t++)
            {
                if (!(vector1[t]==vector2[t-contador1]))
                {
                    iguales=0;
                }
            }
        }
        if (iguales==1)
        {
            return contador1;
            break;
        }
    }
    if (iguales==0)
        return -1;
}
void mayus_o_min_6 (char vector1[],int cual)
{
    int largo1=longitud_1(vector1);
    if (cual==1)
    {
        for (i=0;i<largo1;i++)
        {
            if (vector1[i]>96 && vector1[i]<123)
            {
                vector1[i]-=32;
            }
        }
    }
    if (cual==2)
    {
        for (i=0;i<largo1;i++)
        {
            if (vector1[i]<91 && vector1[i]>64)
            {
                vector1[i]+=32;
            }
        }
    }
}
void limpiar_vector (char vector[])
{
    int largo=longitud_1(vector);
    for (i=0;i<largo;i++)
    {
        vector[i]=0;
    }
}
