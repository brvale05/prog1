#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    char sobrenome[21];
    char nome[21];
    int nota;
    int idade;
} tCandidato;

tCandidato LeCandidato();
void ImprimeCandidato(tCandidato candidato);

int ComparaString(char *str1, char *str2)
{
    int i = 0;

    while(str1[i] != '\0')
    {
        i++;
    }

    int j = 0;

    while(str2[j] != '\0')
    {
        j++;
    }

    if(j != i)
    {
        return 0;
    }

    int aux = 0;
    for(i = 0; str1[i] != '\0'; i++)
    {
        if(str1[i] != str2[i])
        {
            return 0;
        }
    }

    return 1;
}

void Procura_Sobrenomes_Repetidos(tCandidato candidatos[], int TAM)
{
    int i, j, flag_imprime_primeiro = 0;

    int verificada[TAM];
    for(i = 0; i < TAM; i++)
    {
        verificada[i] = 0;
    }

    for(i = 0; i < TAM - 1; i++)
    {
        for(j = i + 1; j < TAM; j++)
        {
            if(!verificada[j])
            {
                if(ComparaString(candidatos[i].sobrenome, candidatos[j].sobrenome))
                {
                    if(!flag_imprime_primeiro)
                    {
                        ImprimeCandidato(candidatos[i]);
                        flag_imprime_primeiro = 1;
                    }
                    ImprimeCandidato(candidatos[j]);
                    verificada[j] = 1;
                }
            }
        }
        flag_imprime_primeiro = 0;
    }
}

int main()
{
    int qtdCand, i = 0;

    scanf("%d", &qtdCand);
    tCandidato candidatos[qtdCand];

    for (i = 0; i < qtdCand; i++)
    {
        candidatos[i] = LeCandidato();
    }

    Procura_Sobrenomes_Repetidos(candidatos, qtdCand);

    return 0;
}

tCandidato LeCandidato()
{
    tCandidato candidato;
    scanf("%*[^{]");
    scanf("%*[{ ]");
    scanf("%d", &candidato.codigo);
    scanf("%*[, ]");
    scanf("%[^,],", candidato.sobrenome);
    scanf("%*[ ]");
    scanf("%[^,],", candidato.nome);
    scanf("%d", &candidato.nota);
    scanf("%*[, ]");
    scanf("%d", &candidato.idade);
    scanf("%*[^\n]\n");
    return candidato;
}

void ImprimeCandidato(tCandidato candidato)
{
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n", candidato.codigo, candidato.nome, candidato.sobrenome, candidato.nota, candidato.idade);
}