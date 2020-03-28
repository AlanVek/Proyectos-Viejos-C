#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n[100],max,a,producto;
    int i,j;
    i=0;
    while (i<100)
    {
        printf ("Ingrese dato: ");
        scanf ("%f",&a);
        if (a<0)
            break;
        else
        {
            n[i]=a;
            i++;
        }
    }

    producto=1;
    for (j=0;j<i;j++)
    {
        producto=producto*n[j];
    }
    printf ("El producto es %.2f",producto);
}
