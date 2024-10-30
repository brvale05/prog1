#include <stdio.h>

int main()
{
    int TAM;
    scanf("%d", &TAM);

    int num[TAM];

    int n = 0;
    while(n < TAM)
    {
        scanf("%d", &num[n]);
        n++;
    }

    if(n == 1)
    {
        printf("CRESCENTE&DECRESCENTE");
        return 0;
    }

    int decrescente = 0, crescente = 0;

    for(n = 0; n < TAM - 1; n++)
    {
        if(num[n] < num[n + 1])
        {
            crescente++;
        }

        if(num[n] > num[n + 1])
        {
            decrescente++;
        }
    }

    if(crescente > 0 && decrescente > 0)
    {
        printf("DESORDENADO");
    } else 
    if(decrescente == 0 && crescente == 0)
    {
        printf("CRESCENTE&DECRESCENTE");
    } else
    if(crescente > 0)
    {
        printf("CRESCENTE");
    } else
    if(decrescente > 0)
    {
        printf("DECRESCENTE");
    }  

    return 0;

}