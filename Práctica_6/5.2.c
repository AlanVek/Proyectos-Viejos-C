#include <stdio.h>
int longitud (char n[]);
int i;
int main()

{
    char cad1[100],cad2[100];
    int j,t;
    printf ("Ingrese la primera cadena: ");
    scanf ("%s",cad1);
    printf ("\nIngrese la segunda cadena: ");
    scanf ("%s",cad2);
    printf ("\n");

    t=longitud(cad1);
    for (j=t-1;j>=0;j--)
    {
        printf ("%c",cad1[j]);
    }

    printf ("\nSu longitud es %d\n\n",t);


    t=longitud(cad2);
    for (j=t-1;j>=0;j--)
    {
        printf ("%c",cad2[j]);
    }

    printf ("\nSu longitud es %d\n\n",t);
    return 0;
}
int longitud (char n[])
{
    i=0;
    while (i<100)
    {
        if (n[i]==0)
        {
            break;
        }
        i++;
    }
    return i;

}
