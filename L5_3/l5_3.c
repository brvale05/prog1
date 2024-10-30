#include <stdio.h>

void Imprime_Pares(int TAM, int alturas[], int maior_dif)
{

    int n = 0, dif;
    while(n < TAM - 1)
    {
        dif = alturas[n] - alturas[n + 1];

        if(dif < 0)
        {
            dif = dif * -1;
        }

        if(dif == maior_dif)
        {
            printf(" (%d %d)", n, n + 1);
        }
        n++;
    }
}

int main()
{
    int TAM;
    scanf("%d", &TAM);

    int alturas[TAM];

    int n = 0;

    while(n < TAM)
    {
        scanf("%d", &alturas[n]);
        n++;
    }

    if(n == 1)
    {
        printf("IMPOSSIVEL");
        return 0;
    }

    int difabsoluta, maior_dif;

    for(n = 0; n < TAM - 1; n++)
    {
        if(n == 0)
        {
            difabsoluta = alturas[n] - alturas[n + 1];
            if(difabsoluta < 0)
            {
                difabsoluta = difabsoluta * -1;
            }

    maior_dif = difabsoluta;

        }

        difabsoluta = alturas[n] - alturas[n + 1];

        if(difabsoluta < 0)
        {
                difabsoluta = difabsoluta * -1;
        }

        if(difabsoluta > maior_dif)
        {
            maior_dif = difabsoluta;
        }

    }

    Imprime_Pares(TAM, alturas, maior_dif);

    return 0;

}