#include <stdio.h>
int longitud(char n[]);
int sacar_espacios(char n[],char m[],int largo);
int es_palindromo(char m[],int largo);
int main()
{
   char n[500],m[500];
   int pal,j,h;

   printf ("\nIngrese palabra: ");
   gets(n);

   j=longitud(n);
   h=sacar_espacios(n,m,j);
   pal=es_palindromo(m,h);

   if (pal==1)
       printf ("\nEs palindromo.\n");
   else
       printf ("\nNo es palindromo.\n");

   return 0;
}
int longitud(char n[])
{
    int i=0,longit=0;
    while (n[i]!=0)
    {
        longit+=1;
        i+=1;
    }
    return longit;
}
int sacar_espacios(char n[],char m[],int largo)
{
    int i,h=0;
    for (i=0;i<largo;i++)
    {
        if (n[i]!=' ')
        {
            m[h]=n[i];
            h++;
        }
    }
    return h;
}
int es_palindromo(char m[],int largo)
{
    int i,b,pal=1;
    for (i=0;i<largo;i++)
    {
        b=largo-i-1;
        if (m[i]!=m[b])
        {
            pal=0;
            break;
        }
    }
    return pal;
}
