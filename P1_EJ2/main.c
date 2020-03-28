#include <stdio.h>
#include <stdlib.h>
int es_suma(int n1, int n2, int n3);
int main()
{
    int n1,n2,n3;
    printf ("Ingrese primer numero: ");
    scanf ("%d",&n1);
    printf ("Ingrese segundo numero: ");
    scanf ("%d",&n2);
    printf ("Ingrese tercer numero: ");
    scanf ("%d",&n3);
    while (!(n1==0 && n2==0 && n3==0))
    {
        if (es_suma(n1,n2,n3)==1)
        {
            printf ("\n%d es suma de %d y %d\n",n1,n2,n3);
        }
        else
        {
            if (es_suma(n2,n1,n3)==1)
            {
                printf ("\n%d es suma de %d y %d\n",n2,n1,n3);
            }
            else
            {
                if (es_suma(n3,n2,n1)==1)
                {
                    printf ("\n%d es suma de %d y %d\n",n3,n2,n1);
                }
                else
                {
                    printf ("\nNinguno es suma de los otros dos.\n");
                }
            }
        }
        printf ("\n\n");
        printf ("Ingrese primer numero: ");
        scanf ("%d",&n1);
        printf ("Ingrese segundo numero: ");
        scanf ("%d",&n2);
        printf ("Ingrese tercer numero: ");
        scanf ("%d",&n3);
    }
    printf ("\n\n//Hasta luego//\n\n");
    return 0;
}
int es_suma(int n1, int n2, int n3)
{
    if (n1==n2+n3)
        return 1;
    else
        return 0;
}
