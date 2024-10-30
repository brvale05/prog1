#include <stdio.h> 
#include <stdlib.h> 
 
void ConcatenaString(char * str1, char * str2, char * strOut)
{
    int i = 0, j = 0;

    for(i = 0; str1[i] != '\0'; i++)
    {
        strOut[i] = str1[i];
    }

    for(j = 0; str2[j] != '\0'; j++, i++)
    {
        strOut[i] = str2[j];
    }

    strOut[i] = '\0';

}
 
int main(){ 
 char nome[1000]; 
 char sobrenome[1000]; 
 char nomeCompleto[2000]; 
   
 while ( scanf("%s", sobrenome) == 1 && scanf("%s", nome) == 1){ 
  ConcatenaString(nome, sobrenome, nomeCompleto); 
 
  printf("%s\n", nomeCompleto); 
 } 
  
    return 0;     
}