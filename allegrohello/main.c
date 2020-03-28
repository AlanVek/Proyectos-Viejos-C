#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,i,p;
    printf ("Ingrese un numero del 1 al 10: ");
    scanf ("%d",&a);
    while (a<1 || a>10)
    {
        printf ("Debe estar entre 1 y 10. Intente de nuevo: ");
        scanf ("%d",&a);
    }
    a=a*a;
    a+=8;
    a=a-3;
    p=a;
    for (i=0;i<p;i++)
    {
        a+=i;
    }
    printf ("El valor final es: %d",a);
    return 0;
}
