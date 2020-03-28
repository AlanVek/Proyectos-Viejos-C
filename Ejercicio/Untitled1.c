#include <stdio.h>
#include <time.h>
main()
{
    srand (time(NULL));
    int m=rand()%10;
    printf ("%d",m);
}
