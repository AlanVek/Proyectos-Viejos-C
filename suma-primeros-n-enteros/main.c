/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int i,a,b;
    printf ("Ingrese: ");
    scanf ("%d",&a);
    b=a;
    for (i=0;i<a;i++)
    {
        b+=i;
    }
    printf ("La suma de los primeros %d enteros es %d",a,b);
    return 0;
}
