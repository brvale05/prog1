#include <stdio.h>

void Imprime_Vetores(int vet1[], int vet2[], int TAM1, int TAM2)
{
    int i = 0, j = 0;
    while((i + j) < (TAM1 + TAM2))
    {
        if(vet1[i] <= vet2[j] && i < TAM1)
        {
            printf("A");
            i++;
        } else {
            
            if(j >= TAM2)
            {
                break;
            }

            printf("B");
            j++;

        }
    }
    while(i < TAM1)
    {
        printf("A");
        i++;
    }
}

void Ordena_Crescente(int vet[], int TAM)
{
    int i, j, aux;
    for(i = 0; i < TAM - 1; i++)
    {
        for(j = i + 1; j < TAM; j++)
        {
            if(vet[j] < vet[i])
            {
                //swap
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

int main()
{
    int TAM1;
    scanf("%d", &TAM1);

    int vet1[TAM1];
    int n1 = 0;
    while(n1 < TAM1)
    {
        scanf("%d", &vet1[n1]);
        n1++;
    }

    char c;
    scanf("%c", &c);

    int TAM2;
    scanf("%d", &TAM2);

    int vet2[TAM2];
    int n2 = 0;
    while(n2 < TAM2)
    {
        scanf("%d", &vet2[n2]);
        n2++;
    }
    
    Ordena_Crescente(vet1, TAM1);
    Ordena_Crescente(vet2, TAM2);

    Imprime_Vetores(vet1, vet2, TAM1, TAM2);

    return 0;

}