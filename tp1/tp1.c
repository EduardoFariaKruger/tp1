/* Arquivo MAIN que usa o TAD racionais */

/* coloque seus includes aqui */

#include <stdio.h>
#include "racionais.h"
#include <stdlib.h>


int n, max, i;
struct racional r1, r2, soma, subtracao, multiplicacao, divisao;

int main (){

    srand(0);
    scanf("%d", &n);
    scanf("%d", &max);
    

    for (i = 1 ; i<=n; i++)
    {
        printf("%d: \n", i);
        r1 = sorteia_r(max);
        r2 = sorteia_r(max);
        imprime_r(r1);
        imprime_r(r2);
        if ((!valido_r(r1)) || (!valido_r(r2)))
        {
            printf("NUMERO INVALIDO\n");
            return 1;
        }
        soma = soma_r(r1, r2);
        subtracao = subtrai_r(r1, r2);
        multiplicacao = multiplica_r(r1, r2);
        divisao = divide_r(r1, r2);
        if (!valido_r(divisao))
        {
            printf("NUMERO INVALIDO\n");
            return 1;
        }
        imprime_r(soma);
        imprime_r(subtracao);
        imprime_r(multiplicacao);
        imprime_r(divisao);
        printf("\n");
    }

    return 0;
}
