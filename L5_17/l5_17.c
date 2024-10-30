#include <stdio.h>

int main()
{
    char matriz[500][501];

    int i = 0;

    while(scanf("%[A-Za-z]", matriz[i]) == 1)
    {
        i++;
        scanf("%*[^A-Za-z]");
        if (i == 500)
        {
            break;
        }
    }

    int j;

    for(j = i; j >= 0; j--)
    {
        printf("%s ", matriz[j]);
    }

    return 0;
}