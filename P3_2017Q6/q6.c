#include <stdio.h>

void Imprime_Coordenadas(int l1, int c1, int matriz1[l1][c1], int l2, int c2, int matriz2[l2][c2])
{
    int i1, i2, j1, j2, verificada;

    for(i1 = 0; i1 < l1 - l2 + 1; i1++)
    {
        for(j1 = 0; j1 < c1 - c2 + 1; j1++)
        {
            verificada = 1;

            for(i2 = 0; i2 < l2; i2++)
            {
                for(j2 = 0; j2 < c2; j2++)
                {
                    if(matriz1[i1 + i2][j1 + j2] != matriz2[i2][j2])
                    {
                        verificada = 0;
                    }
                }
            }
            if(verificada)
            {
                printf("%d,%d\n", j1, i1);
            }
        }
    }
}

int main()
{
    int l1, c1;
    scanf("%d %d", &l1, &c1);
    
    int matriz1[l1][c1];

    int i, j;
  
    for(i = 0; i < l1; i++)
    {
        for(j = 0; j < c1; j++)
        {
            scanf("%1d", &matriz1[i][j]);
        }
    }

    int l2, c2;
    scanf("%d %d", &l2, &c2);

    int matriz2[l2][c2];

    for(i = 0; i < l2; i++)
    {
        for(j = 0; j < c2; j++)
        {
            scanf("%1d", &matriz2[i][j]);
        }
    }

    Imprime_Coordenadas(l1, c1, matriz1, l2, c2, matriz2);
    
    return 0;
}