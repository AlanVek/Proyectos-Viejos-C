/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int a,b,c,d,i;
    printf ("Ingrese cantidad: ");
    scanf ("%d",&i);
    if (i==1)
    printf ("0\n");
    else
    printf ("0\n1\n");
    a=2;
    c=0;
    b=1;
    
    while (a<i)
    {
        d=b+c;
        printf ("%d\n",d);
        if (b>c)
        {
            c=d;
        }
        else
        {
            b=d;        
        }
        a++;
    }

    return 0;
}
