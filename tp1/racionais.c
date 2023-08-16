#include "racionais.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
/* acrescente demais includes que voce queira ou precise */

/* 
 * Implemente aqui as funcoes definidas no racionais.h 
 * caso queira, você pode definir neste arquivo funcoes
 * adicionais que serao internas e so podem ser usadas
 * aqui.
*/

int aleat(int min, int max)
{
    srand(time(NULL));
    return (min + rand() % (max - min + 1));
}
int mdc(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int mmc(int a, int b)
{
    return a * (b / mdc(a, b));
}
struct racional simplifica_r(struct racional r)
{
    int val = 2;
    while ((val < r.num) && (val < r.den))
    {
        if (((r.num % val) == 0) && ((r.den % val) == 0))
        {
            r.num = r.num / val;
            r.den = r.den / val;
        }
        val++;
    }
    return r;
}
struct racional sorteia_r(int n)
{
    struct racional teste;
    teste.num = 2;
    teste.den = 2;
    return teste;
}
struct racional cria_r(int numerador, int denominador)
{
    struct racional teste;
    teste.num = 2;
    teste.den = 2;
    return teste;
}
void imprime_r(struct racional r)
{
    printf("%d / %d", r.num, r.den);
}
int valido_r(struct racional r)
{
    return (r.den != 0);
}
struct racional soma_r(struct racional r1, struct racional r2)
{
    return r1;
}
struct racional multiplica_r(struct racional r1, struct racional r2)
{
    r1.num = r1.num * r2.num;
    r1.den = r1.den * r2.den;
    simplifica_r(r1);
    return r1;
}
struct racional divide_r(struct racional r1, struct racional r2)
{
    r1.num = r1.num * r2.den;
    r1.den = r1.den * r2.num;
    simplifica_r(r1);
    return r1;
}