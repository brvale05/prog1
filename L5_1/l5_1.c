#include <stdio.h>
#include <math.h>

float Calcula_Media(int TAM, int vet[])
{
    int i, soma = 0;

    for(i = 0; i < TAM; i++)
    {
        soma = soma + vet[i];
    }
    return (float)soma/TAM;
}

float Desvio_Padrao(int N, int notas[], float media)
{
    int i;
    float somatorio = 0;

    for(i = 0; i < N; i++)
    {
        somatorio = somatorio + ((notas[i] - media)*(notas[i] - media));
    }

    float desvio = somatorio/N;

    desvio = sqrt(desvio);

    return desvio;
}

int main()
{
    int TAM;
    scanf("%d", &TAM);

    int notas[TAM];
    int n = 0;

    while(n < TAM)
    {
        scanf("%d", &notas[n]);
        n++;
    }

    int menor, maior, reprovados = 0;

    float media;

    media = Calcula_Media(TAM, notas);

    int qtd_alunos_acimaMedia = 0;

    for(n = 0; n < TAM; n++)
    {

        if(n == 0)
        {
            menor = notas[n];
            maior = notas[n];
        }

        if(notas[n] > maior)
        {
            maior = notas[n];
        }

        if(notas[n] < menor)
        {
            menor = notas[n];
        }

        if(notas[n] < 70)
        {
            reprovados++;
        }

        if(notas[n] > media)
        {
            qtd_alunos_acimaMedia++;
        }

    }

    float desvio = Desvio_Padrao(TAM, notas, media);

    printf("MENOR:%d, MAIOR:%d, MEDIA:%.2f, ", menor, maior, media);
    printf("STD:%.2f, ACIMA_MEDIA_CONC:%d, REPROV:%d", desvio, qtd_alunos_acimaMedia, reprovados);

}