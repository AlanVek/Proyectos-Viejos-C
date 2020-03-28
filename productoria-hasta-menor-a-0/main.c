/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    float a,prod;

    printf ("Ingrese:\n");
    scanf ("%f",&a);
    if (a<0)
    {
        printf ("Fin.");
    }
    else
    {
        prod=1;
         while (a>=0)
        {
            prod=prod*a;
            printf ("Ingrese: \n");
            scanf ("%f",&a);
        }

        printf ("El producto es %.2f.\n\nFin.",prod);
    }

    return 0;
}



