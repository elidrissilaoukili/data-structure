#include <stdio.h>
#include <math.h>


// somme de x^i = x^(i-1) * x

float func(float x, int n)
{
    float somme = 0;
    for (int i = 1; i <= n; i++)
    {
        somme += powf(x, i-1) * x;
    }
    return somme;
}

int main()
{
    printf("Somme: %f", func(2, 3));
    return 0;
}