#include <stdio.h>

int Descobre_Tamanho_String(char vet[])
{
    int i = 0;
    while(vet[i] != '\0')
    {
        i++;
    }
    return i;
}

void Imprime_Strings(char vet1[], char vet2[])
{
    int TAM1 = Descobre_Tamanho_String(vet1);
    int TAM2 = Descobre_Tamanho_String(vet2);
    
    int i, j, igual = 0;
    for(i = 0; i < TAM1; i++)
    {
        for(j = i; j < TAM2; j++)
        {
            if(vet2[j] == vet1[i])
            {
                igual++;
                if(igual == TAM1)
                {
                    printf("PODE!\n");
                    return;
                }
                break;
            }
        }
        if(!igual)
        {
            printf("NAO PODE!\n");
            return;
        }
    }
    printf("NAO PODE!\n");
    return;
}

int EhMaiuscula(char car)
{
    if(car >= 'A' && car <= 'Z')
    {
        return 1;
    }
    return 0;
}

void Transforma_Em_Minusculo(char vet[])
{
    int i = 0;
    while(vet[i] != '\0')
    {
        if(EhMaiuscula(vet[i]))
        {
            vet[i] = vet[i] + 32;
        }
        i++;
    }
}

int main()
{
    int casos;
    scanf("%d", &casos);

    int c = 0;

    char str1[401];
    char str2[401];

    while(c < casos)
    {
        scanf("%400s", str1);
        scanf("%400s", str2);

        Transforma_Em_Minusculo(str1); Transforma_Em_Minusculo(str2);
        Imprime_Strings(str1, str2);
   
        c++;
    }

    return 0;
}