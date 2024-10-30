#include <stdio.h>

int main()
{
    int TAM1;
    scanf("%d", &TAM1);

    int seq1[TAM1];
    int n;

    for(n = 0; n < TAM1; n++)
    {
        scanf("%d", &seq1[n]);
    }

    scanf("\n");

    int TAM2;
    scanf("%d", &TAM2);
    
    int seq2[TAM2];

    for(n = 0; n < TAM2; n++)
    {
        scanf("%d", &seq2[n]);
    }

    int i, j;

    int igual = 0;
    for(i = 0; i < TAM1; i++)
    {
        for(j = 0; j < TAM2; j++)
        {
            if(seq1[i] == seq2[j])
            {
                igual++;
                break;
            }
        }
    }

    if(igual == TAM1)
    {
        printf("TODOS");
    } else
    if(igual > 0)
    {
        printf("PARCIAL");
    } else {
        printf("NENHUM");
    }

    return 0;
}