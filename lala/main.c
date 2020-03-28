#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    char nombre;
    int anio;
    int cantidad;

} Hotel;

char cargar_archivo (FILE *bin, Hotel vector[],int cualanio,int *Barcelona, int *BA,int *Calafate,int *SC,int *Paris,float *prom);
char mayor_cant_hab (FILE *bin,int *Barcelona, int *BA,int *Calafate,int *SC,int *Paris);
void archivo_de_texto (FILE *bin, FILE *txt);
char mayor_prom (int Barcelona, int BA,int Calafate,int SC,int Paris);
void cambio (char a);
int contar_letra(FILE *txt,char a);
int i,j;
int main()
{
    srand(time(NULL));
    FILE *bin,*txt;
    Hotel Vector[5];
    char a;
    int minbar=200,minba=200,minsc=200,minca=200,minpa=200,t;
    int aniominbar, aniominba, aniominsc, aniominca, aniominpa;
    float prom,total=0;
    int Barcelona=0, BA=0, Calafate=0, SC=0, Paris=0;
    bin=fopen ("hotelesporanio.bin","w+b");
    txt=fopen ("hoteles.doc","w+t");
    for (t=2010;t<2018;t++)
    {
        a=cargar_archivo (bin,Vector,t, &Barcelona, &BA, &Calafate, &SC, &Paris,&prom);
        for (i=0;i<5;i++)
        {
            total+=Vector[i].cantidad;
        }
        if (minbar>Vector[0].cantidad)
        {
            minbar=Vector[0].cantidad;
            aniominbar=t;
        }

        if (minba>Vector[1].cantidad)
        {
            aniominba=t;
            minba=Vector[1].cantidad;
        }
        if (minca>Vector[2].cantidad)
        {
            aniominca=t;
            minca=Vector[2].cantidad;
        }
        if (minsc>Vector[3].cantidad)
        {
            aniominsc=t;
            minsc=Vector[3].cantidad;
        }
        if (minpa>Vector[4].cantidad)
        {
            aniominpa=t;
            minpa=Vector[4].cantidad;
        }

        total=total/5;
        //printf ("\nEn el anio %d, el que tuvo mayor cantidad de hab fue: ",t);
        //cambio (a);
        printf ("\nPromedio de %d: %.2f\n",t,prom);

    }
    fseek(bin,0,SEEK_SET);
    printf ("\nHotel con mas habitaciones ocupadas en los 8 anios: ");
    cambio (mayor_cant_hab (bin,&Barcelona, &BA,&Calafate,&SC,&Paris));

    archivo_de_texto(bin,txt);
    printf ("\nMinimo de Barcelona: %d",aniominbar);
    printf ("\nMinimo de Buenos Aires: %d",aniominba);
    printf ("\nMinimo de Calafate: %d",aniominca);
    printf ("\nMinimo de Santiago de Chile: %d",aniominsc);
    printf ("\nMinimo de Paris: %d\n",aniominpa);
    printf ("\n\nIngrese cadena a buscar: ");
    char k;
    fflush(stdin);
    k=getch();
    fseek(txt,0,SEEK_SET);
    printf ("%c",k);
    printf ("\n\nCantidad de veces que aparece en el archivo: %d\n\n",contar_letra(txt,k));

    fclose (bin);
    fclose (txt);


   return 0;
}

char cargar_archivo (FILE *bin, Hotel vector[],int cualanio,int *Barcelona, int *BA,int *Calafate,int *SC,int *Paris,float *prom)
{
    int cantidad,B,A,C,S,P;
    for (i=0;i<5;i++)
    {
        cantidad=rand()%76;
        cantidad+=75;
        vector[i].cantidad=cantidad;
        vector[i].anio=cualanio;
            if (i==0)
            {
                vector[i].nombre='B';
                B=cantidad;
                *Barcelona+=cantidad;

            }
            if (i==1)
            {
                vector[i].nombre='A';
                A=cantidad;
                *BA+=cantidad;

            }
            if (i==2)
            {
                vector[i].nombre='C';
                C=cantidad;
                *Calafate+=cantidad;

            }
            if (i==3)
            {
                vector[i].nombre='S';
                S=cantidad;
                *SC+=cantidad;

            }
           if (i==4)
           {
                vector[i].nombre='P';
                P=cantidad;
                *Paris+=cantidad;
           }
           fwrite (&vector[i],sizeof(Hotel),1,bin);

    }
    *prom=(A+B+C+S+P)/5;
    int avector[5],aux;
    avector[0]=B;
    avector[1]=A;
    avector[2]=S;
    avector[3]=C;
    avector[4]=P;
    for (i=0;i<4;i++)
    {
        for (j=i+1;j<5;j++)
        {
            if (avector[i]<avector[j])
            {
                aux=avector[i];
                avector[i]=avector[j];
                avector[j]=aux;
            }
        }
    }
    if (avector[0]==B)
        return ('B');
    if (avector[0]==A)
        return ('A');
    if (avector[0]==S)
        return ('S');
    if (avector[0]==C)
        return ('C');
    if (avector[0]==P)
        return ('P');
}
char mayor_cant_hab (FILE *bin,int *Barcelona, int *BA,int *Calafate,int *SC,int *Paris)
{
    int avector[5],aux;
    avector[0]=*Barcelona;
    avector[1]=*BA;
    avector[2]=*SC;
    avector[3]=*Calafate;
    avector[4]=*Paris;
    for (i=0;i<4;i++)
    {
        for (j=i+1;j<5;j++)
        {
            if (avector[i]<avector[j])
            {
                aux=avector[i];
                avector[i]=avector[j];
                avector[j]=aux;
            }
        }
    }
    if (avector[0]==*Barcelona)
        return ('B');
    if (avector[0]==*BA)
        return ('A');
    if (avector[0]==*SC)
        return ('S');
    if (avector[0]==*Calafate)
        return ('C');
    if (avector[0]==*Paris)
        return ('P');
}
void archivo_de_texto (FILE *bin, FILE *txt)
{
    Hotel a;
    for (i=0;i<40;i++)
    {
        fread (&a,sizeof(Hotel),1,bin);
        switch (a.nombre)
        {
        case 'B':
            fprintf (txt,"%d,Barcelona         ,%d\n",a.anio,a.cantidad);
            break;
        case 'A':
            fprintf (txt,"%d,Buenos Aires      ,%d\n",a.anio,a.cantidad);
            break;
        case 'C':
            fprintf (txt,"%d,Calafate          ,%d\n",a.anio,a.cantidad);
            break;
        case 'S':
            fprintf (txt,"%d,Santiago de Chile ,%d\n",a.anio,a.cantidad);
            break;
        case 'P':
            fprintf (txt,"%d,Paris             ,%d\n",a.anio,a.cantidad);
            break;
        }
    }
}
char mayor_prom (int Barcelona, int BA,int Calafate,int SC,int Paris)
{
    int avector[5],aux;
    avector[0]=Barcelona;
    avector[1]=BA;
    avector[2]=SC;
    avector[3]=Calafate;
    avector[4]=Paris;
    for (i=0;i<4;i++)
    {
        for (j=i+1;j<5;j++)
        {
            if (avector[i]<avector[j])
            {
                aux=avector[i];
                avector[i]=avector[j];
                avector[j]=aux;
            }
        }
    }
    if (avector[0]==Barcelona)
        return ('B');
    if (avector[0]==BA)
        return ('A');
    if (avector[0]==SC)
        return ('S');
    if (avector[0]==Calafate)
        return ('C');
    if (avector[0]==Paris)
        return ('P');
}
void cambio (char a)
{
   switch (a)
    {
        case 'B':
            printf ("Barcelona\n");
            break;
        case 'A':
            printf ("Buenos Aires\n");
            break;
        case 'C':
            printf ("Calafate\n");
            break;
        case 'S':
            printf ("Santiago de Chile\n");
            break;
        case 'P':
            printf ("Paris\n");
            break;
    }
}
int contar_letra(FILE *txt,char a)
{
    int c;
    char nombre[18];
    int suma=0;
    fflush(stdin);
    fscanf(txt,"%d",&c);
    fgetc(txt);
    fgets (nombre,17,txt);
    fgetc(txt);
    fscanf (txt,"%d",&c);
    while (!(feof(txt)))
    {
        i=0;
        while (nombre[i]!=0)
        {
            if (nombre[i]==a)
                suma+=1;
            i+=1;
        }
        fscanf(txt,"%d",&c);
        fgetc(txt);
        fgets (nombre,17,txt);
        fgetc(txt);
        fscanf (txt,"%d",&c);
    }
    return suma;
}
