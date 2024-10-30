#include <stdio.h>
#define TAM_MAX 6

typedef struct
{

    int ID;
    int l;
    int matriz[TAM_MAX][TAM_MAX];

} tCartela;

typedef struct 
{
    
    tCartela cartelas[100];
    int TAM;

} tPartida;


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

tPartida  LeCartelasPartida()
{
    int qtd_cartelas;
    scanf("%d", &qtd_cartelas);

    tPartida partida;

    int n = 0;
    while(n < qtd_cartelas)
    {
        partida.cartelas[n] = LeCartela();
        n++;
    }
    partida.TAM = qtd_cartelas;

    return partida;
}

void ImprimeInvCartelasPartida(tPartida partida)
{
    int i;
    for(i = partida.TAM - 1; i >= 0; i--)
    {
        ImprimeCartela(partida.cartelas[i]);
    }
}

int main()
{
    tPartida partida; 
  
    partida = LeCartelasPartida(); 
  
    ImprimeInvCartelasPartida(partida); 
 
    return 0;
}