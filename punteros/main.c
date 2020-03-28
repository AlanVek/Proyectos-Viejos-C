#include <stdio.h>
#include <stdlib.h>
int sumar (int *a, int *b);
int main()
{
    int a,b,c;
    a=16;
    b=18;
    c=sumar(&a,&b);
    printf ("La suma es %d",c);
    printf ("\na vale %d",a);
    printf ("\nb vale %d",b);
}
int sumar (int *a, int *b)
{
    *a=2;
    *b=15;
    return *a+*b;
}
