#include <stdio.h>

void Imprime_Vetor_Resultante(int vet[], int TAM)
{
    int i;
    for(i = TAM - 1; i >= 0; i--)
    {
        printf("%d", vet[i]);
    }
    printf("\n");
}

void Soma_Vetores(int vet1[], int TAM1, int vet2[], int TAM2)
{
    int i = TAM1 - 1;
    int j = TAM2 - 1;

    int vet_resultado[100], aux = 0, mais_um = 0, soma = 0;

    while(j >= 0)
    {
        soma = vet1[i] + vet2[j] + mais_um;

        mais_um = 0;

        if(soma >= 10)
        {
            soma = soma%10;
            mais_um = 1;
        }

        vet_resultado[aux] = soma;
        aux++;

        i--;
        j--;
    }

    while(i >= 0)
    {
        soma = vet1[i] + mais_um;

        mais_um = 0;

        if(soma >= 10)
        {
            soma = soma%10;
            mais_um = 1;
        }

        vet_resultado[aux] = soma;
        aux++;

        i--;
    }

    if(mais_um > 0)
    {
        printf("%d", mais_um);
    }

    Imprime_Vetor_Resultante(vet_resultado, aux);

}

int main()
{
    int pares;
    scanf("%d", &pares);

    int vet1[100];
    int vet2[100];

    int p = 0, i = 0, j = 0;
    while(p < pares)
    {
        int num;
        i = 0;
        j = 0;

        while(1)
        {
            scanf("%d", &num);

            if(num == -1)
            {
                break;
            }
            vet1[i] = num;
            i++;
        }

        while(1)
        {
            scanf("%d", &num);

            if(num == -1)
            {
                break;
            }
            vet2[j] = num;
            j++;
        }

        Soma_Vetores(vet1, i, vet2, j);
        p++;
    }
    return 0;
}