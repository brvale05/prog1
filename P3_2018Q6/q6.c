#include <stdio.h>

void Procura_Erros(int l1, int c1, char m1[l1][c1], int l2, int c2, char m2[l2][c2])
{
    int i1, i2, j1, j2, contida = 1, erros = 0;
    c1 = c1 - 1;
    c2 = c2 - 1;

    for(i1 = 0; i1 < l1 - l2 + 1; i1++)
    {
        for(j1 = 0; j1 < c1 - c2 + 1; j1++)
        {
            contida = 1;

            for(i2 = 0; i2 < l2; i2++)
            {
                for(j2 = 0; j2 < c2; j2++)
                {
                    if(m1[i1 + i2][j1 + j2] != m2[i2][j2])
                    {
                        contida = 0;
                    }
                }
            }
            if(contida > 0)
            {
                erros++;
            }
        }
    }
    printf("RESP:%d", erros);
}

int main()
{
    int l, c;
    scanf("%d %d\n", &l, &c);

    c = c + 1;

    int i;
    char matriz1[l][c];
    for(i = 0; i < l; i++)
    {
        scanf("%[^\n]", matriz1[i]);
        scanf("%*c");
    }

    int l2, c2;
    scanf("%d %d\n", &l2, &c2);

    c2 = c2 + 1;

    char matriz2[l2][c2];
    for(i = 0; i < l2; i++)
    {
        scanf("%[^\n]", matriz2[i]);
        scanf("%*c");
    }

    Procura_Erros(l, c, matriz1, l2, c2, matriz2);

    return 0;
}