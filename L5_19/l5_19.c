#include <stdio.h>

int Verifica_Agua_Ao_Redor(int i, int j, int l, int c, char mapa[l][c]);

void Imprime_Zeros(int l, int c, char mapa[l][c]);

void Avanca_Mare(int l, int c, char mapa[l][c]);

void AUX_Substitui_Terra(int l, int c, char mapa[l][c]);

int main()
{
    int horas;
    scanf("%d", &horas);

    int c, l;
    scanf("%d %d", &c, &l);
    scanf("%*c");

    c = c + 1;

    char matriz[l][c];

    int i;
    for(i = 0; i < l; i++)
    {
        scanf("%[^\n]", matriz[i]);
        scanf("%*c");
    }

    Imprime_Zeros(l, c, matriz);

    int n = 0;
    while(n < horas)
    {
        AUX_Substitui_Terra(l, c, matriz);
        Avanca_Mare(l, c, matriz);
        n++;
    }
    printf(" ");
    Imprime_Zeros(l, c, matriz);
    printf("\n");

    return 0;
    
}

int Verifica_Agua_Ao_Redor(int i, int j, int l, int c, char mapa[l][c])
{
    if(mapa[i][j + 1] == '1' || mapa[i][j - 1] == '1')
    {
        return 1;
    }
    if(mapa[i + 1][j] == '1' || mapa[i - 1][j] == '1')
    {
        return 1;
    }
    return 0;
}

void Imprime_Zeros(int l, int c, char mapa[l][c])
{
    int zero = 0, i, j;
    for(i = 0; i < l; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(mapa[i][j] == '0')
            {
                zero++;
            }
        }
    }
    printf("%d", zero);
}

void Avanca_Mare(int l, int c, char mapa[l][c])
{
    int i, j;
    for(i = 0; i < l; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(mapa[i][j] == '2')
            {
                mapa[i][j] = '1';
            }
        }
    }
}

void AUX_Substitui_Terra(int l, int c, char mapa[l][c])
{
    int i, j;
    for(i = 1; i < l - 1; i++)
    {
        for(j = 1; j < c - 1; j++)
        {
            if(mapa[i][j] == '0')
            {
                if(Verifica_Agua_Ao_Redor(i, j, l, c, mapa))
                {
                    mapa[i][j] = '2';
                }
            }
        }
    }
}