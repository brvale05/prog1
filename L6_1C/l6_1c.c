#include <stdio.h>

typedef struct
{

    int identificador_msg; //3 digitos
    int identificador_pacote; // 3 digitos
    int tamanho_msg; //1 digito
    char mensagem[9];
    int cod_erro; // 4 digitos

} tPacote;

typedef struct
{

    tPacote pacotes[101];

} tMensagens;

tPacote LePacote();

void ImprimePacote(tPacote pacote);

int Verifica_Erro_Cod(tPacote pacote);

tMensagens Preenche_tMensagem(tPacote pacotes[], int TAM);

tMensagens Ordena_Pacotes(tPacote pacotes[], int TAM);

void Imprime_Mensagens(tMensagens mensagens, int TAM);

int main()
{
    int qtd_pacotes;
    scanf("%d", &qtd_pacotes);
    scanf("%*c");

    tPacote pacotes[qtd_pacotes];
    tMensagens mensagens;

    int p = 0;
    while (p < qtd_pacotes)
    {
        pacotes[p] = LePacote();
        scanf("%*c");
        p++;
    }

    mensagens = Ordena_Pacotes(pacotes, qtd_pacotes);
    Imprime_Mensagens(mensagens, qtd_pacotes);

    return 0;
}


tPacote LePacote()
{
    tPacote pacote;

    scanf("%3d %3d %1d", &pacote.identificador_msg, &pacote.identificador_pacote, &pacote.tamanho_msg);

    int n = 0;
    while (n < 9)
    {
        scanf("%c", &pacote.mensagem[n]);
        n++;
    }

    scanf(" %4d", &pacote.cod_erro);

    return pacote;
}

void ImprimePacote(tPacote pacote)
{

    int i = 0;
    while (i < pacote.tamanho_msg)
    {
        printf("%c", pacote.mensagem[i]);
        i++;
    }
}

int Verifica_Erro_Cod(tPacote pacote)
{
    int soma = 0;

    soma = pacote.identificador_msg + pacote.identificador_pacote + pacote.tamanho_msg;

    int a = 0;
    while (a < pacote.tamanho_msg)
    {
        soma = soma + (int)pacote.mensagem[a];
        a++;
    }

    if (soma != pacote.cod_erro)
    {
        return 0;
    }
    return 1;
}

tMensagens Preenche_tMensagem(tPacote pacotes[], int TAM)
{
    int i = 0;
    tMensagens mensagens;
    while (i < TAM)
    {
        mensagens.pacotes[i] = pacotes[i];
        i++;
    }

    return mensagens;
}

tMensagens Ordena_Pacotes(tPacote pacotes[], int TAM)
{
    int i, j;
    tPacote aux;
    tMensagens mensagens;
    for (i = 0; i < TAM - 1; i++)
    {
        for (j = i + 1; j < TAM; j++)
        {
            if (pacotes[j].identificador_msg < pacotes[i].identificador_msg)
            {
                aux = pacotes[j];
                pacotes[j] = pacotes[i];
                pacotes[i] = aux;
            }
            if (pacotes[j].identificador_msg == pacotes[i].identificador_msg)
            {
                if (pacotes[j].identificador_pacote < pacotes[i].identificador_pacote)
                {
                    aux = pacotes[j];
                    pacotes[j] = pacotes[i];
                    pacotes[i] = aux;
                }
            }
        }
    }
    mensagens = Preenche_tMensagem(pacotes, TAM);
    return mensagens;
}

void Imprime_Mensagens(tMensagens mensagens, int TAM)
{
    int verificada[TAM], i, flag_imprime_unica_vez = 0;
    tPacote pacotes[TAM];
    for (i = 0; i < TAM; i++)
    {
        verificada[i] = 0;
        pacotes[i] = mensagens.pacotes[i];
    }

    int j;
    for (i = 0; i < TAM; i++)
    {
        if(i == TAM - 1)
        {
            if(!Verifica_Erro_Cod(pacotes[i]))
            {
                printf("##FALHA##");
            } else {
                ImprimePacote(pacotes[i]);
            }
            break;
        }

        if(!Verifica_Erro_Cod(pacotes[i]))
        {
            printf("##FALHA##");
        } else {
            ImprimePacote(pacotes[i]);
        }
        if(pacotes[i].identificador_msg != pacotes[i + 1].identificador_msg)
        {
            printf("\n");
        }
    }
}
