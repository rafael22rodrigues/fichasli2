#include <stdio.h>
#include <assert.h>

/*
    Três dos soldados da Rainha de Copas tiveram que formar diante do sargento. 
    O sargento sabe que a Rainha de Copas odeia a desordem. 
    Os soldados pordem estar por ordem crescente ou decrescente de alturas. 
    Essas duas formações são toleráveis para a rainha. 
    Se não estivem por ordem crescente ou decrescente: Cortem-Ihes a cabeça! 
    
    REQUISITO: Dadas as alturas dos 3 soldados verificar se estão por uma ordem em especifico (crescente, decrescente, ou se são todos iguais)
    e imprimir na tela "OK", se ficar provado que está por uma ordem em específico, ou "NAO" caso contrário

    Cenários Possiveis(EX's):
    - 1 2 3 -> OK (Estão por ordem crescente)
    - a b c -> Assertion failed (As alturas inseridas não são válidas uma vez que não são números inteiros e por isso o programa dá erro)
    - 3 3 3 -> OK (Todos têm o mesmo tamanho)
    - 3 2 1 -> OK (Estão por ordem decrescente)
    - 3 1 2 -> NAO (Não estão por uma ordem em específico)
    - ...
*/

int main() {
    int soldadoA, soldadoB, soldadoC;
    //através do scanf são lidos as 3 alturas correspondentes aos soldados e através do assert verifica se são realmente números inteiros
    assert(scanf("%d %d %d", &soldadoA, &soldadoB, &soldadoC) == 3); 
    //caso se verifique que os soldados estão por ordem crescente ou decrescente de altura ou se têm todos os mesmo tamanho, imprime-se na tela (através do printf) a palavra "OK"
    if(((soldadoA <= soldadoB) && (soldadoB <= soldadoC)) || ((soldadoA >= soldadoB)&&(soldadoB >= soldadoC))) printf("%s\n", "OK"); 
    //caso contrário imprime-se a palavra "NAO"
    else printf("%s\n", "NAO"); 
    //e assim o programa termina
    return 0;
}

/*
Testes (Cenários Testados):

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
