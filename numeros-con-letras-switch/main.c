/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int n;
    printf ("Ingrese entero entre 0 y 10: ");
    scanf ("%d",&n);
    while ((n<0)||(n>10))
    {
        printf ("Debe estar entre 0 y 10. Intente de nuevo: ");
        scanf ("%d",&n);
    }
    
    printf ("\n");
    switch(n)
    {
        case 0: printf ("Cero.");
            break;
        case 1: printf ("Uno.");
            break;
        case 2: printf ("Dos.");
            break;
        case 3: printf ("Tres.");
            break;
        case 4: printf ("Cuatro.");
            break;
        case 5: printf ("Cinco.");
            break;
        case 6: printf ("Seis.");
            break;
        case 7: printf ("Siete.");
            break;
        case 8: printf ("Ocho.");
            break;
        case 9: printf ("Nueve.");
            break;
        default: printf ("Diez.");
            break;
    }
        
    return 0;
}
