#include <stdio.h>
#include <assert.h>

/*
    Três dos soldados da Rainha de Copas tiveram que formar diante do sargento. 
    O sargento sabe que a Rainha de Copas odeia a desordem. 
    Os soldados pordem estar por ordem crescente ou decrescente de alturas. 
    Essas duas formações são toleráveis para a rainha. 
    Se não estivem por ordem crescente ou decrescente: Cortem-Ihes a cabeça! 

/*
    O programa deve ler uma linha para cada soldado. 
    Cada linha contém um número inteiro positivo.

    Depois de ler os números, o programa deve imprimir uma linha com a palavra OK, caso esteja ordenado por ordem crescente, decrescente ou sejam todos iguais, ou a palavra NAO, caso contrário.
*/

int main() {
    int soldadoA, soldadoB, soldadoC;
    assert(scanf("%d %d %d", &soldadoA, &soldadoB, &soldadoC) == 3); //através do scanf são lidos as 3 alturas correspondentes aos soldados e através do assert verifica se são realmente números inteiros
    if(((soldadoA <= soldadoB) && (soldadoB <= soldadosC)) || ((soldadoA >= soldadoB)&&(soldadoB >= soldadosC)))printf("%s\n", "OK"); // caso se verifique que os soldados estão por ordem crescente ou decrescente de altura ou se têm todos os mesmo tamanho, imprime-se na tela a palavra "OK"
    else printf("%s\n", "NAO"); // caso contrário imprime-se a palavra "NAO"
    return 0;
}

/*
Input:
97
97
97

Output:
OK

Input:
100
90
101

Output:
NAO

Input:
100
110
120

Output:
OK

*/
