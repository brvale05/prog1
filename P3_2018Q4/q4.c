#include <stdio.h>
#include <string.h>

int Conta_Letras(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}

int Descobre_MAX(char str[], int indice, int maior)
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    if(i > maior)
    {
        return indice;
    }
    return -1;
}

void Imprime_Maior(char str1[], char str2[])
{

    int i = Conta_Letras(str1);
    int j = Conta_Letras(str2);

    if(i > j)
    {
        printf("%s\n", str1);
    } 
    if(j > i)
    {
        printf("%s\n", str2);
    }
}

int main()
{
    char str[50][50];
    int i = 0;

    while(scanf("%s", str[i]) == 1)
    {
        i++;
    }

    int TAM = i, igual = 0;
    for(i = 0; i < TAM; i++)
    {
        Imprime_Maior(str[i], str[i + 1]);
        if(Conta_Letras(str[i]) == Conta_Letras(str[i + 1]))
        {
            igual++;
        }
        i++;
    }

    int maior = 0, idemaior;
    for(i = 0; i < TAM; i++)
    {
        if(i < 1)
        {
            maior = Conta_Letras(str[i]);
            idemaior = i;
        }
        if(Conta_Letras(str[i]) > maior)
        {
            idemaior = i;
            maior = Conta_Letras(str[i]);
        }
    }

    if(igual == TAM/2)
    {
        printf("MAX:--\n");
    } else {
        printf("MAX:%s\n", str[idemaior]);
    }
    return 0;
}