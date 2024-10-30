#include <stdio.h>

int main()
{
    int TAM;
    scanf("%d", &TAM);

    int n = 0;
    int num[TAM];

    while(n < TAM)
    {
        scanf("%d", &num[n]);
        n++;
    }

    int dif_absoluta, aux;

    int igual = 0;

    for(n = TAM - 1; n > 0; n--)
    {
        if(n == TAM - 1)
        {
            dif_absoluta = num[n] - num[n - 1];

            igual++;

        } else {
            aux = num[n] - num[n - 1];
            
            if(aux == dif_absoluta)
            {
                igual++;
            }

        }
    }

    if(igual < 1)
    {
        printf("NAO");
    } else
    if(igual == TAM - 1)
    {
        printf("RESP:%d", dif_absoluta);
    } else {
        printf("NAO");
    }

    return 0;

}