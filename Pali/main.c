#include <stdio.h>
#include <stdlib.h>
#include "Cadenas.h"
int main()
{
	char Palabra1[1000],Palabra2[1000];
	int Anagramas, Incluye, Palindromo1, Palindromo2;

	printf ("Ingrese la primera frase: ");
	gets (Palabra1);

	printf ("\nIngrese la segunda frase: ");
	gets (Palabra2);

    printf ("\nPrimera Frase Dada Vuelta: ");
    Dar_Vuelta_Palabra(Palabra1);
    printf ("\n\nSegunda Frase Dada Vuelta: ");
    Dar_Vuelta_Palabra(Palabra2);

	printf ("\n\n¿Son Anagramas? ");

	Anagramas = Son_Anagramas(Palabra1,Palabra2);

	if (Anagramas == 1)
        printf ("Sí.\n");
    else
        printf ("No.\n");

    Incluye = Una_Incluye_A_Otra(Palabra1,Palabra2);
    printf ("\n¿La primera Incluye a la Segunda? ");
    if (Incluye == 1)
        printf ("Si.\n");
    else
        printf ("No.\n");

    Palindromo1 = Es_Palindromo(Palabra1);
    Palindromo2 = Es_Palindromo(Palabra2);

    printf ("\n¿Son Palindromos? ");
    if (Palindromo1 == 1 && Palindromo2 == 1)
        printf ("Si.\n");
    else
        {
            if (Palindromo1 == 1 && Palindromo2 ==0)
                printf ("La primera, si. La segunda, no.\n");
            else
            {
                if (Palindromo1 == 0 && Palindromo2 == 1)
                    printf ("La primera, no. La segunda, si.\n");
                else
                    printf ("No.\n");
            }
        }

	return 0;
}
