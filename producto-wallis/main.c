/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int i;
    float a,b,c;
    
    i=1;
    a=1;
    while (i<32000)
    {   
        b=4*i*i;
        a*=(float)(b/(b-1));
        i+=1;
    }
    c=a*2;
    printf ("La aproximaciC3n de pi es %f.",c);
    
    return 0;
}

