#include <stdio.h>
#define TAM_MAX 6

typedef struct
{

    int ID;
    int l;
    int matriz[TAM_MAX][TAM_MAX];

} tCartela;

tCartela LeCartela()
{
    int ID, linha;
    tCartela cartela;
    
    scanf("%d %d", &ID, &linha);

    int matriz[linha][linha];

    int l, c;
    for(l = 0; l < linha; l++)
    {
        for(c = 0; c < linha; c++)
        {
            scanf("%d", &cartela.matriz[l][c]);
        }
    }

    cartela.ID = ID;
    cartela.l = linha;

    return cartela;

}

void  ImprimeCartela(tCartela  cartela)
{
    int i, j;

    printf("ID:%d\n", cartela.ID);

    for(i = 0; i < cartela.l; i++)
    {
        for(j = 0; j < cartela.l; j++)
        {
            if(j > 0)
            {
                printf("|%03d", cartela.matriz[j][i]);
            } else {
                printf("%03d", cartela.matriz[j][i]);
            }
        }
        printf("\n");
    }
}

int main()
{
    tCartela cartela; 
  
    cartela = LeCartela(); 
  
    ImprimeCartela(cartela); 
 
    return 0;
}