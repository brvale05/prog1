#include <stdio.h>

void Imprime_Vetor(int vet[], int TAM)
{
    int i;
    for(i = 0; i < TAM; i++)
    {
        printf("%d", vet[i]);
        if(i != TAM - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void Desloca_Vetor(int vet[], int TAM, int deslocador)
{
    int i = 0, nova_seq[TAM], soma = 0;

    while(i < TAM)
    {   

        soma = i + deslocador;

        if(soma >= TAM)
        {
            soma = soma%TAM;
        }

        nova_seq[soma] = vet[i];

        i++;

    }

    for(i = 0; i < TAM; i++)
    {
        vet[i] = nova_seq[i];
    }

}

int main()
{
    int TAM, deslocamento;

    while(scanf("%d", &TAM) == 1)
    {
        int vet[TAM];
        int i;

        for(i = 0; i < TAM; i++)
        {
            scanf("%d", &vet[i]);
        }

        while(1)
        {
            scanf("%d", &deslocamento);

            if(deslocamento == - 1)
            {
                break;
            }

            Desloca_Vetor(vet, TAM, deslocamento);
            Imprime_Vetor(vet, TAM);
        }
    }
    return 0;
}