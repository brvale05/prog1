#include <stdio.h>

void Procura_Padrao_Vertical(int padrao, int l, int c, char matriz[l][c])
{
    int i1, j1, i2, j2, contido = 1, contador = 0;

    for(i1 = 0; i1 <= l - padrao; i1++)
    {
        for(j1 = 0; j1 < c; j1++)
        {
            contido = 1;

                for(i2 = 0; i2 < padrao; i2++)
                {
                    if(matriz[i1 + i2][j1] != 'X')
                    {
                        contido = 0;
                    }
                }

                if(contido)
                {
                    contador++;
                }                
        }
    }

    printf("CONT: V %d\n", contador);

}

void Procura_Padrao_Horizontal(int padrao, int l, int c, char matriz[l][c])
{
    int i1, j1, i2, j2, contido = 1, contador = 0;

    for(i1 = 0; i1 < l; i1++)
    {
        for(j1 = 0; j1 <= c - padrao; j1++)
        {
            contido = 1;

            for(j2 = 0; j2 < padrao; j2++)
            {
                if(matriz[i1][j1 + j2] != 'X')
                {
                    contido = 0;
                }
            }

            if(contido)
            {
                contador++;
            }            
        }
    }

    printf("CONT: H %d\n", contador);

}

int main()
{
    int num_padrao;
    char padrao;

    scanf("%d%c\n", &num_padrao, &padrao);

    int l, c;
    scanf("%d %d\n", &l, &c);

    c = c + 1;

    char matriz[l][c];

    int i;
    for(i = 0; i < l; i++)
    {
        scanf("%s", matriz[i]);
        scanf("%*c");
    }

    if(padrao == 'H')
    {
        Procura_Padrao_Horizontal(num_padrao, l, c, matriz);
    } else
    {
        Procura_Padrao_Vertical(num_padrao, l, c, matriz);
    }

    return 0;

}