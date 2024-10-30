#include <stdio.h> 

void Imprime_Pares(int tam1, int tam2, int vet1[], int vet2[])
{
    int i = 0, j = 0;

    printf("PARES:\n");

    while(i < tam1)
    {
        if(j == tam2)
        {
            j = 0;
        }

        printf("%d - %d\n", vet1[i], vet2[j]);

        i++;
        j++;

    }
}

int main()
{
    int qtd1;
    scanf("%d", &qtd1);

    int vet1[qtd1];
    int n = 0;

    while(n < qtd1)
    {
        scanf("%d", &vet1[n]);
        n++;
    }

    n = 0;

    int qtd2;
    scanf("%d", &qtd2);

    int vet2[qtd2];

    while(n < qtd2)
    {
        scanf("%d", &vet2[n]);
        n++;
    }

    Imprime_Pares(qtd1, qtd2, vet1, vet2);

    return 0;

}