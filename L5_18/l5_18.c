#include <stdio.h>

void Multiplica_Matrizes(int l1, int l2, int c1, int c2, int matriz1[l1][c1], int matriz2[l2][c2])
{

    int i1, i2, j1, j2;

    int soma_resultante = 0;

    if (c1 != l2)
    {
        printf("IMPOSSIVEL");
        printf("\n");
        return;
    }

    for (i1 = 0; i1 < l1; i1++)
    {
        for (j2 = 0; j2 < c2; j2++)
        {
            for (j1 = 0; j1 < c1; j1++)
            {
            soma_resultante = soma_resultante + (matriz1[i1][j1] * matriz2[j1][j2]);
            }
            printf("%d ", soma_resultante);
            soma_resultante = 0;
        }

        printf("\n");
        
    }
    
}

int main()
{
    int qtd_pares;
    scanf("%d", &qtd_pares);

    int p = 0;

    int i, j;

    int l1, c1, l2, c2;

    int num;

    while (p < qtd_pares)
    {
        scanf("%d %d", &c1, &l1);
        int matriz1[l1][c1];
        for (i = 0; i < l1; i++)
        {
            for (j = 0; j < c1; j++)
            {
                scanf("%d", &num);
                matriz1[i][j] = num;
            }
        }

        scanf("%d %d", &c2, &l2);
        int matriz2[l2][c2];
        for (i = 0; i < l2; i++)
        {
            for (j = 0; j < c2; j++)
            {
                scanf("%d", &num);
                matriz2[i][j] = num;
            }
        }
        Multiplica_Matrizes(l1, l2, c1, c2, matriz1, matriz2);
        printf("\n");
        p++;
    }
    return 0;
}