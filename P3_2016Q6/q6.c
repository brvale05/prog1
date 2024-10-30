#include <stdio.h>

int Eh_Verdadeiro(int i, int j, int l, int c, char matriz[l][c])
{
    // mesma linha
    if (matriz[i][j + 1] == '1' || matriz[i][j - 1] == '1')
    {
        return 1;
    }
    // linha de cima/baixo mesma coluna
    if (matriz[i - 1][j] == '1' || matriz[i + 1][j] == '1')
    {
        return 1;
    }
    // linha de baixo e coluna esquerda/direita
    if (matriz[i - 1][j + 1] == '1' || matriz[i - 1][j - 1] == '1')
    {
        return 1;
    }
    // linha de cima e coluna esquerda/direita
    if (matriz[i + 1][j + 1] == '1' || matriz[i + 1][j - 1] == '1')
    {
        return 1;
    }
    return 0;
}

void Imprime_Resposta(int l, int c, char matriz[l][c])
{
    int i, j, muro = 0;

    for (i = 0; i < l - 1; i++)
    {
        for (j = 0; j < c - 1; j++)
        {
            if (matriz[i][j] == '0')
            {
                if(Eh_Verdadeiro(i, j, l, c, matriz))
                {
                    muro++;
                }
            }
        }
    }
    printf("%d\n", muro);
}

int main()
{
    int c, l;
    scanf("%d %d", &c, &l);
    scanf("%*c");

    int i, j;
    c = c + 1;
    char matriz[l][c];

    for (i = 0; i < l; i++)
    {
        scanf("%[^\n]", matriz[i]);
        scanf("%*c");
    }

    Imprime_Resposta(l, c, matriz);

    return 0;
}