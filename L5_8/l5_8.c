#include <stdio.h>

void TrocaParEImpar(int vet[], int qtd)
{
    int i;

    int aux;

    for(i = 0; i < qtd - 1; i++)
    {

        if(!(i%2))
        {
        aux = vet[i];
        vet[i] = vet[i + 1];
        vet[i + 1] = aux;
        }

    }
}

void ImprimeDadosDoVetor(int vet[], int qtd)
{
    int i;

    printf("{");

    for(i = 0; i < qtd; i++)
    {
        if(i < 1)
        {
            printf("%d", vet[i]);
        } else {
            printf(", %d", vet[i]);
        }
    }

    printf("}");

}

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

    TrocaParEImpar(num, TAM);
    ImprimeDadosDoVetor(num, TAM);

    return 0;
}