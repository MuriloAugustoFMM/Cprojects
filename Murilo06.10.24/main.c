#include <stdio.h>
#include <stdlib.h>

void inverter(char vetor[])
{
    if(vetor[0] != '\0')
    {
        inverter(vetor[1]);
        printf("%c",vetor[0]);
    }
    exit(0);
}

int fatorial (int n)
{
    //
    printf("%d",n);
    if( n == 0 )
        return 1;
    n = n * fatorial(n-1);
    //printf("%d",n);
    return n ;
}

int main()
{
    char vetor[20];
    int n, res = 1;
    scanf("%d",&n);
    //gets(vetor);
    //inverter(vetor);
    printf("%d",fatorial(n));
    while(n > 0)
    {
        res = res * n;
        n = n - 1;
    }
    //printf("%d",res);



    return 0;
}
