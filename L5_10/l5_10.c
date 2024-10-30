#include <stdio.h>

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

int Acha_Menor(int vet[], int TAM, int i)
{
    int menor = vet[i];
    int idex = i;

    for(i = i + 1; i < TAM; i++)
    {
        if(vet[i] < menor)
        {
            idex = i;
            menor = vet[i];
        }
    }
    return idex;
}

void OrdenaCrescente(int vet[], int qtd)
{
    int i, idex, aux;

    for(i = 0; i < qtd - 1; i++)
    {
        idex = Acha_Menor(vet, qtd, i + 1);
        if(vet[idex] < vet[i])
        {
            //swap
            aux = vet[i];
            vet[i] = vet[idex];
            vet[idex] = aux;

        }
    }
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

OrdenaCrescente(num, TAM);
ImprimeDadosDoVetor(num, TAM);

return 0;

}