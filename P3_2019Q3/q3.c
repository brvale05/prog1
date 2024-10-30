#include <stdio.h>

typedef struct 
{
    int id;
    int qtd_psg;
    char tipo[100];
    int km;

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

void ListaCarrosConcessionaria(tConcessionaria concessionaria, int pass, int km)
{
    int i;
    for(i = 0; i < concessionaria.TAM; i++)
    {
        if(pass != -1 && km != -1)
        {
            if(ObtemNumPassageirosCarro(concessionaria.carros[i]) == pass && ObtemKmCarro(concessionaria.carros[i]) <= km)
            {
                ImprimeCarro(concessionaria.carros[i]);
            }
        } else
        if(pass == -1 && km == -1)
        {
            ImprimeCarro(concessionaria.carros[i]);
        } else
        if(pass == -1)
        {
            if(ObtemKmCarro(concessionaria.carros[i]) <= km)
            {
                ImprimeCarro(concessionaria.carros[i]);
            }
        } else
        if(km == -1)
        {
            if(ObtemNumPassageirosCarro(concessionaria.carros[i]) == pass)
            {
                ImprimeCarro(concessionaria.carros[i]);
            }
        }
    }
}


int main()
{
    tConcessionaria concessionaria;

    concessionaria = LeCarrosConcessionaria();

    int qtdPassageiros, km, i = 0;
    while (scanf("%d,%d", &qtdPassageiros, &km) == 2)
    {
        printf("Caso %d:\n", ++i);
        ListaCarrosConcessionaria(concessionaria, qtdPassageiros, km);
    }

    return 0;
}
