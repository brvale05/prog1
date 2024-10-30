#include <stdio.h>

int main()
{
    int X;
    scanf("%d", &X);

    int TAM;
    scanf("%d", &TAM);

    int num[TAM];
    int n = 0, flag = 0;

    while(n < TAM)
    {
        scanf("%d", &num[n]);
        if(num[n] == X)
        {
            printf("RESP:%d", n);
            flag++;
            break;
        }
        n++;
    }

    if(flag < 1)
    {
        printf("RESP:%d", TAM);
    }

    return 0;

}