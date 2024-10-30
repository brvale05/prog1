#include <stdio.h>

void Imprime_Palavra(char str[]);

void Imprime_Consoantes(char str[]);

void Imprime_Vogais(char str[]);

int Eh_Numero(char car);

int Eh_Vogal(char car);

void Conta_Vogal_E_Consoante(char str[]);


int main()
{
    char str[100];

    while(scanf("%99s", str) == 1)
    {
        Conta_Vogal_E_Consoante(str);
        printf("\n");
    }
    return 0;
}


void Imprime_Palavra(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        printf("%c", str[i]);
        i++;
    }      
}

void Imprime_Consoantes(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(!Eh_Vogal(str[i]))
        {
            if(!Eh_Numero(str[i]))
            printf("%c", str[i]);
        }
        i++;
    }   
}

void Imprime_Vogais(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(Eh_Vogal(str[i]))
        {
            printf("%c", str[i]);
        }
        i++;
    }
}

int Eh_Numero(char car)
{
    if(car >= '0' && car <= '9')
    {
        return 1;
    }
    return 0;
}

int Eh_Vogal(char car)
{
    if(car == 'a' || car == 'A' || car == 'e' || car == 'E')
    {
        return 1;
    }
    if(car == 'i' || car == 'I' || car == 'o' || car == 'O')
    {
        return 1;
    }
    if(car == 'u' || car == 'U')
    {
        return 1;
    }
    return 0;
}

void Conta_Vogal_E_Consoante(char str[])
{
    int i = 0, vogal = 0, consoante = 0;
    while(str[i] != '\0')
    {
        if(Eh_Vogal(str[i]))
        {
            vogal++;
        } else {
            if(!Eh_Numero(str[i]))
            {
                consoante++;
            }
        }
        i++;
    }
    
    if(vogal > consoante)
    {
        Imprime_Vogais(str);
    } 
    else
    if(consoante > vogal)
    {
        Imprime_Consoantes(str);
    } 
    else 
    {
        Imprime_Palavra(str);
    }
}