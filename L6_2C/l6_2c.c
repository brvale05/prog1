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
    tCartela cartelas_inicias[100];
    int TAM;
    int partida_acabou; 

} tPartida;


tCartela LeCartela();

void  ImprimeCartela(tCartela  cartela);

tPartida  LeCartelasPartida();

int VenceuCartela(tCartela cartela);

tCartela Marca_Cartela(tCartela cartela, int i, int j);

tPartida Roda_Cartelas(tPartida partida, int num);

tPartida JogaPartida(tPartida partida);

tPartida ResetaPartida(tPartida partida);

tCartela ResetaCartela(tCartela cartela, tCartela cartela_inicial);

int main()
{
    tPartida partida; 
    int qtdPartidas, i; 
  
    partida = LeCartelasPartida(); 
  
    scanf("%d", &qtdPartidas); 

    for(i = 0; i < qtdPartidas; i++)
    {
        if ( i!=0 ) printf("\n"); 

        printf("PARTIDA %d\n", i+1); 

        partida = ResetaPartida(partida);

        partida = JogaPartida(partida); 
    } 
 
    return 0;
}

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
    partida.partida_acabou = 0;

    int n = 0;
    while(n < qtd_cartelas)
    {
        partida.cartelas[n] = LeCartela();
        n++;
    }
    n = 0;
    while(n < qtd_cartelas)
    {
        partida.cartelas_inicias[n] = partida.cartelas[n];
        n++;
    }
    partida.TAM = qtd_cartelas;

    return partida;
}

int VenceuCartela(tCartela cartela)
{
    int i, j;
    
    for(i = 0; i < cartela.l; i++)
    {
        for(j = 0; j < cartela.l; j++)
        {
            if(cartela.matriz[i][j] != -2)
            {
                return 0;
            }
        }
    }
    return 1;
}

tCartela Marca_Cartela(tCartela cartela, int i, int j)
{
    cartela.matriz[i][j] = -2;
    return cartela;
}

tPartida Roda_Cartelas(tPartida partida, int num)
{
    int p = 0, i, j;
    int flag = 0;
    tCartela cartela;
    for(p = 0; p < partida.TAM; p++)
    {
        cartela = partida.cartelas[p];
        
        for(i = 0; i < cartela.l; i++)
        {
            for(j = 0; j < cartela.l; j++)
            {
                if(num == cartela.matriz[i][j])
                {
                    cartela = Marca_Cartela(cartela, i, j);
                    break;
                }
            }
        }
        if(VenceuCartela(cartela))
        {
            partida.partida_acabou = 1;
            if(flag < 1)
            {
                printf("COM VENCEDOR\n");
            }
            ImprimeCartela(partida.cartelas_inicias[p]);
            flag++;
        }
        partida.cartelas[p] = cartela;
    }
    return partida;
}

tPartida JogaPartida(tPartida partida)
{
    int num, i;
    
    while(1)
    {
        scanf("%d", &num);

        if(num == -1)
        {
            printf("SEM VENCEDOR\n");
            partida.partida_acabou = 0;
            break;
        }

        partida = Roda_Cartelas(partida, num);
        if(partida.partida_acabou > 0)
        {
            scanf("%*[^\n]");
            scanf("%*c");
            break;
        } 
        
    }
}

tPartida ResetaPartida(tPartida partida)
{
    int p = 0;
    while(p < partida.TAM)
    {
        partida.cartelas[p] = ResetaCartela(partida.cartelas[p], partida.cartelas_inicias[p]);
        p++;
    }
    return partida;
}

tCartela ResetaCartela(tCartela cartela, tCartela cartela_inicial)
{
    cartela = cartela_inicial;
    return cartela;
}