#include <stdio.h>

int main()
{
    int TAM;
    scanf("%d", &TAM);

    int num[TAM];

    int n = 0;
    while(n < TAM)
    {
        scanf("%d", &num[n]);
        n++;
    }

    int a, b;
    scanf("%d %d", &a, &b);
    //printf("AQUI: %d %d\n", a, b);

    int dentro = 0, fora = 0;

    for(n = 0; n < TAM; n++)
    {
        if(num[n] <= b && num[n] >= a)
        {
            dentro++;
        } else {
            fora++;
        }
    }

    printf("%d %d", dentro, fora);

    return 0;
}