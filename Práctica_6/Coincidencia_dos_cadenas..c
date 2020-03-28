#include <stdio.h>

int main()

{
    char cad1[100],cad2[100];
    int j,i,t,m,s,k,l,h,iguales,g,f,q;
    printf ("Ingrese la primera cadena: ");
    scanf ("%s",cad1);
    printf ("\nIngrese la segunda cadena: ");
    scanf ("%s",cad2);
    printf ("\n");
    i=0;
    while (i<100)
    {
        if (cad1[i]==0)
        {
            break;
        }
        i++;
    }

    for (j=i-1;j>=0;j--)
    {
        printf ("%c",cad1[j]);
    }
    printf ("\nSu longitud es %d\n\n",i);

    t=0;
    while (t<100)
    {
        if (cad2[t]==0)
        {
            break;
        }
        t++;
    }

    for (j=t-1;j>=0;j--)
    {
        printf ("%c",cad2[j]);
    }
    printf ("\nSu longitud es %d\n\n",t);

    for (m=0;m<t;m++)
    {
        for (h=0;h<i;h++)
        {
            if (cad1[h]==cad2[m])
            {
                s=m;
                g=m;
                for (l=h;l<i;l++)
                {
                    if (cad1[l]!=cad2[g])
                    {
                        k=g;
                        break;
                    }
                    else
                    {
                        if (l==i-1)
                            k=g+1;
                        else
                            g++;
                    }
                }
                if ((k-s)>1)
                {
                    printf ("Son iguales desde la posicion %d de la segunda cadena hasta la posición %d.",s,k-1);
                    printf ("\nLa coincidencia es: ");
                    for (f=s;f<k;f++)
                    {
                        printf ("%c",cad2[f]);
                    }
                    q=1;
                    break;
                }
            }

            if (q==1)
                break;
        }
    }
}


