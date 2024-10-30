#include <stdio.h>

typedef struct{
    
    int identificador_msg; //3 digitos
    int identificador_pacote; //3 digitos
    int tamanho_msg; //1 digito
    char mensagem[9];
    int cod_erro; //4 digitos

} tPacote;

tPacote LePacote();

void ImprimePacote(tPacote pacote);

int Verifica_Erro_Cod(tPacote pacote);

int main()
{
    int qtd_pacotes;
    scanf("%d", &qtd_pacotes);
    scanf("%*c");

    tPacote pacotes[qtd_pacotes];

    int p = 0;
    while(p < qtd_pacotes)
    {
        pacotes[p] = LePacote();
        scanf("%*c");
        p++;
    }

    for(p = 0; p < qtd_pacotes; p++)
    {
        if(!Verifica_Erro_Cod(pacotes[p]))
        {
            printf("FALHA!\n");
        } else {
            ImprimePacote(pacotes[p]);
        }
        
    }

    return 0;
}


tPacote LePacote()
{
    tPacote pacote;

    scanf("%3d %3d %1d", &pacote.identificador_msg, &pacote.identificador_pacote, &pacote.tamanho_msg);

    int n = 0;
    while(n < 9)
    {
        scanf("%c", &pacote.mensagem[n]);
        n++;
    }

    scanf(" %4d", &pacote.cod_erro);

    return pacote;

}

void ImprimePacote(tPacote pacote)
{
    printf("PCT: ");
    printf("%d,%d,%d,", pacote.identificador_msg, pacote.identificador_pacote, pacote.tamanho_msg);

    int i = 0;
    while(i < pacote.tamanho_msg)
    {
        printf("%c", pacote.mensagem[i]);
        i++;
    }

    printf(",%d", pacote.cod_erro);
    printf("\n");

}

int Verifica_Erro_Cod(tPacote pacote)
{
    int soma = 0;

    soma = pacote.identificador_msg + pacote.identificador_pacote + pacote.tamanho_msg;

    int a = 0;
    while(a < pacote.tamanho_msg)
    {
        soma = soma + (int)pacote.mensagem[a];
        a++;
    }

    if(soma != pacote.cod_erro)
    {
        return 0;
    }
    return 1;
}