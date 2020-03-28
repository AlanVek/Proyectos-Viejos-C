float suma (float vector[], int cantidad)
{
    int i;
    float sum=0;
    for (i=0;i<cantidad;i++)
    {
        sum+=vector[i];
    }
    return sum;
}
