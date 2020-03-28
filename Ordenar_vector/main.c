#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n[]={5,8,9,3,2,17,-4},i,j,t,aux;

    i=sizeof(n)/sizeof(n[0]);

    for (t=0;t<i-1;t++)
    {
        for (j=t+1;j<i;j++)
        {
            if (n[j]>n[t])
            {
                aux=n[t];
                n[t]=n[j];
                n[j]=aux;
            }
        }
    }
    for (t=0;t<i;t++)
        printf ("%d\n",n[t]);
    return 0;
}
