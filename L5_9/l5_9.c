#include <stdio.h>

void InverteVetor(int * vet, int qtd)
{
    int i, flag_inverte = qtd - 1, aux;

    if(!qtd%2)
    {
        qtd = qtd%2;
    } else {
        qtd = (qtd%2 + qtd/2);
    }

    for(i = 0; i < qtd; i++)
    {
        
        aux = vet[i];
        vet[i] = vet[flag_inverte];
        vet[flag_inverte] = aux;

        flag_inverte--;

    }
}

void ImprimeDadosDoVetor(int vet[], int qtd)
{
    int i;

    printf("{");

    for(i = 0; i < qtd; i++)
    {
        if(!i)
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

    InverteVetor(num, TAM);
    ImprimeDadosDoVetor(num, TAM);

    return 0;

}