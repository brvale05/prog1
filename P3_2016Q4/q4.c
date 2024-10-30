#include <stdio.h>

void Imprime_Resultado(int TAM, int vet[])
{
    int i, j, maior = 0;
    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < TAM; j++)
        {
            if(vet[j] > vet[i])
            {
                maior++;
            }
        }
        printf("%d ", maior);
        maior = 0;
    }
    printf("\n");
}


int main()
{
    int casos;
    scanf("%d", &casos);

    int c = 0;

    int TAM;
    while(c < casos)
    {
        scanf("%d", &TAM);
        int vet[TAM];
        
        int i;
        for(i = 0; i < TAM; i++)
        {
            scanf("%d", &vet[i]);
        }

        Imprime_Resultado(TAM, vet);
        c++;
    }
    return 0;
}