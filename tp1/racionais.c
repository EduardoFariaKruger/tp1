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


/*
 * Essa função gera um número aleatório dentro do intervalo [min..max].
*/
int aleat(int min, int max)
{
    return (min + rand() % (max - min + 1));
}

/*
 * Essa função calcula o MDC de dois números a e b usando o método de euclides.
*/
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

/*
 * Essa função usa do método do produto pelo quociente para calcular o MMC entre a e b usando do MDS entre a e b.\
*/
int mmc(int a, int b)
{
    return a * (b / mdc(a, b));
}

/*
 * Nessa função, a simplificação é feita dividindo tanto o numerador quando o denominador pelo MDC entre eles.
*/
struct racional simplifica_r(struct racional r)
{
    int maiorDivisor = mdc(r.num, r.den);
    r.num = r.num / maiorDivisor;
    r.den = r.den / maiorDivisor;
    return r;
}

/*
 * Essa função gera dois valores aleatórios no intervalo [0..n] para serem o numerador e o denominador de um número fracionário.
*/
struct racional sorteia_r(int n)
{
    struct racional r;
    r.num = aleat(0, n);
    r.den = aleat(0, n);
    if (r.den == 0)
    {
        r.valido = 0;
    }
    return simplifica_r(r);
}

/*
 * Essa função recebe 2 valores "numerador" e "denominador" e os coloca em uma struct de número racional.
*/
struct racional cria_r(int numerador, int denominador)
{
    struct racional r;
    r.num = numerador;
    r.den = denominador;
    if (r.den == 0)
    {
        r.valido = 0;
        return r;
    }
    return simplifica_r(r);
}

/*
 * Essa função usa dos valores de num e den de uma struct para imprimir um número racional no formato "num/den".
 * Como as outras funções retornam os valores simplificados, caso o racional recebido esteja na forma 1/1, o algoritmo dessa função o retornará como sendo apenas 1
 * E como as outras funções retornam os racionais simplificados, essa função não precisa trabalhar com casos do tipo numerador = denominador, pois eles já entrarão na forma 1/1
*/
void imprime_r(struct racional r)
{
    if ((r.num == 0) || (r.den == 1))
    {
        printf("%d  ", r.num);
        return;
    }
    if ((r.den == (-1)) && (r.num > 0))
    {
        printf("%d ", r.num*(-1));
    }
    if ((r.den < (-1)) && (r.num < 0))
    {
        printf("%d/%d ", r.num*(-1), r.den*(-1));
    }
    if ((r.den < (-1)) && (r.num > 0))
    {
        printf("%d/%d ", r.num*(-1), r.den*(-1));
    }
    else
    {
        printf("%d/%d ", r.num, r.den);
    }
}

/*
 * Essa função retorna 1 se o denominador for diferente de zero e 0 se o denominador for igual a zero.
*/
int valido_r(struct racional r)
{
    return (r.den != 0);
}

/*
 * Essa função realiza a soma de frações usando o conceito de MMC e retorna o resultado simplificado
*/
struct racional soma_r(struct racional r1, struct racional r2)
{
    int minMC = mmc(r1.den, r2.den);
    r1.num = minMC/r1.den*r1.num + minMC/r2.den*r2.num;
    r1.den = minMC;
    simplifica_r(r1);
    return r1;
}
struct racional subtrai_r(struct racional r1, struct racional r2)
{
    int minMC = mmc(r1.den, r2.den);
    r1.num = minMC/r1.den*r1.num - minMC/r2.den*r2.num;
    r1.den = minMC;
    return simplifica_r(r1);
}

/*
 * Essa função realiza a operação de multiplicação entre fraçoes e retorna o resultado na forma simplificada.
*/
struct racional multiplica_r(struct racional r1, struct racional r2)
{
    r1.num = r1.num * r2.num;
    r1.den = r1.den * r2.den;
    return simplifica_r(r1);
}

/*
 * Essa função realiza a operação usando da definição de divisão de frações, retornando o resultado na forma simplificada.
*/
struct racional divide_r(struct racional r1, struct racional r2)
{
    r1.num = r1.num * r2.den;
    r1.den = r1.den * r2.num;
    if (r1.den == 0)
    {
        r1.valido = 0;
        return r1;
    }
    return simplifica_r(r1);
}