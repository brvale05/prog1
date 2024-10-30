#include <stdio.h>

typedef struct 
{
    int id;
    int qtd_psg;
    char tipo[100];
    int km;
    int alugado; 

} tCarro;

typedef struct 
{
    tCarro carros[100];
    int TAM;

} tConcessionaria;


tCarro LeCarro()
{
    tCarro carro;

    scanf("%d %d", &carro.id, &carro.qtd_psg);
    scanf(" %s", carro.tipo);
    scanf(" %d\n", &carro.km);
    carro.alugado = 0;

    return carro;

}

tConcessionaria LeCarrosConcessionaria()
{
    int qtd;
    
    scanf("%d\n", &qtd);

    tConcessionaria concessionaria;

    int n = 0;
    while(n < qtd)
    {
        concessionaria.carros[n] = LeCarro();
        n++;
    }

    concessionaria.TAM = qtd;

    return concessionaria;

}

void ImprimeCarroDevolvido(tCarro carro, int cliente)
{
    printf("Devolvido (cliente %d) -> ", cliente);
}

void ImprimeCarroAlugado(tCarro carro)
{
    printf("Alugado (cliente %d) -> ", carro.alugado);
}

void ImprimeCarro(tCarro carro)
{
    printf("CARRO (%d): %s de %d passageiros e com %d km\n", carro.id, carro.tipo, carro.qtd_psg, carro.km);
}

int ObtemNumPassageirosCarro(tCarro carro)
{
    return carro.qtd_psg;
}

int ObtemKmCarro(tCarro  carro)
{
    return carro.km;
}
        

tCarro AlugaCarro(tCarro carro, int cliente)
{
    carro.alugado = cliente;
    return carro;
}

int ObtemClienteAlugouCarro(tCarro carro)
{
    return carro.alugado;
}

int EstaDisponivelCarro(tCarro carro)
{
    if(!ObtemClienteAlugouCarro(carro))
    {
        return 1;
    }
    return 0;
}

tCarro DevolveCarro(tCarro carro)
{
    carro.alugado = 0;
    return carro;
}

tConcessionaria AlugaCarroConcessionaria(tConcessionaria concessionaria, int cliente, int pass, int km)
{
    int i, aux = 0;
    for(i = 0; i < concessionaria.TAM; i++)
    {
        if(pass != -1 && km != -1)
        {
            if(ObtemNumPassageirosCarro(concessionaria.carros[i]) == pass && ObtemKmCarro(concessionaria.carros[i]) <= km)
            {
                if(EstaDisponivelCarro(concessionaria.carros[i]) > 0)
                {
                    concessionaria.carros[i] = AlugaCarro(concessionaria.carros[i], cliente);
                    ImprimeCarroAlugado(concessionaria.carros[i]);
                    ImprimeCarro(concessionaria.carros[i]);
                    aux++;
                    break;
                }
            }
        } else
        if(pass == -1 && km == -1)
        {
            if(EstaDisponivelCarro(concessionaria.carros[i]) > 0)
            {
                concessionaria.carros[i] = AlugaCarro(concessionaria.carros[i], cliente);
                ImprimeCarroAlugado(concessionaria.carros[i]);
                ImprimeCarro(concessionaria.carros[i]);
                aux++;
                break;
            }
        } else
        if(pass == -1)
        {
            if(ObtemKmCarro(concessionaria.carros[i]) <= km)
            {
                if(EstaDisponivelCarro(concessionaria.carros[i]) > 0)
                {
                    concessionaria.carros[i] = AlugaCarro(concessionaria.carros[i], cliente);
                    ImprimeCarroAlugado(concessionaria.carros[i]);
                    ImprimeCarro(concessionaria.carros[i]);    
                    aux++;
                    break;
                }
            }
        } else
        if(km == -1)
        {
            if(ObtemNumPassageirosCarro(concessionaria.carros[i]) == pass)
            {
                if(EstaDisponivelCarro(concessionaria.carros[i]) > 0)
                {
                    concessionaria.carros[i] = AlugaCarro(concessionaria.carros[i], cliente);
                    ImprimeCarroAlugado(concessionaria.carros[i]);
                    ImprimeCarro(concessionaria.carros[i]);
                    aux++;
                    break;
                }
            }
        }
    }

    if(!aux)
    {
        printf("Carro Indisponivel\n");
    }

    return concessionaria;

}

tConcessionaria DevolveCarroConcessionaria(tConcessionaria concessionaria, int cliente)
{
    int i;
    for(i = 0; i < concessionaria.TAM; i++)
    {
        if(ObtemClienteAlugouCarro(concessionaria.carros[i]) == cliente)
        {
            concessionaria.carros[i] = DevolveCarro(concessionaria.carros[i]);
            ImprimeCarroDevolvido(concessionaria.carros[i], cliente);
            ImprimeCarro(concessionaria.carros[i]);
            break;
        }
    }
    return concessionaria;
}


int main()
{
    tConcessionaria concessionaria;

    concessionaria = LeCarrosConcessionaria();

    int qtdPassageiros, km, i = 0;

    char letra; int id_cliente;

    while (scanf("%d,%c\n", &id_cliente, &letra) == 2)
    {
        if(letra == 'A')
        {
            scanf("%d,%d\n", &qtdPassageiros, &km);
            concessionaria = AlugaCarroConcessionaria(concessionaria, id_cliente, qtdPassageiros, km);
        }

        if(letra == 'D')
        {
           concessionaria = DevolveCarroConcessionaria(concessionaria, id_cliente);
        }
    }

    return 0;
}
