/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void main()
{
    float a,b,c,d,menor,mayor,medio1,medio2;
    printf ("Ingrese uno: ");
    scanf ("%f",&a);
    mayor=a;
    menor=a;
    printf ("Ingrese otro: ");
    scanf ("%f",&b);
    if (b>a)
        mayor=b;
    if (b<=a)
        menor=b;
    
    printf ("Ingrese otro: ");
    scanf ("%f",&c);
    if (c>mayor)
    {
        medio1=mayor;
        mayor=c;
    }
    else
    {
        if (c<=menor)
        {    
            medio1=menor;
            menor=c;
        }
        else
        {
            medio1=c;
        }
    }
    printf ("Ingrese otro: ");
    scanf ("%f",&d);
    if (d<=menor)
    {    
        medio2=menor;
        menor=d;
    }
    else
    {
        
        if (d>mayor)
        {
            medio2=mayor;
            mayor=d;
        }
        else
        {
            medio2=d;
        }
    }
    if (medio2<medio1)
        printf ("\nDe menor a mayor: %.2f,%.2f,%.2f,%.2f",menor,medio2,medio1,mayor);
    else
        printf ("\nDe menor a mayor: %.2f,%.2f,%.2f,%.2f",menor,medio1,medio2,mayor);

    return 0;
}

