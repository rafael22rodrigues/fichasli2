#include <stdio.h>
#include <assert.h>

/*
    Três dos soldados da Rainha de Copas tiveram que formar diante do sargento. 
    O sargento sabe que a Rainha de Copas odeia a desordem. 
    Os soldados pordem estar por ordem crescente ou decrescente de alturas. 
    Essas duas formações são toleráveis para a rainha. 
    Se não estivem por ordem crescente ou decrescente: Cortem-Ihes a cabeça! 
*/



int crescente (int soldados[]){ // a função crescente serve para descobrir se os soldados estão ordenados por ordem crescente de altura ou se têm a mesma altura
    if ((soldados[0] <= soldados [1]) && (soldados[1] <= soldados[2])){
        return 1;       // a função devolve 1 se ficar confirmado que os 3 soldados estão por ordem crescente de alturas ou se têm todos a mesma altura
    } else{return 0;}  //  devolve 0 caso contrário
}

int decrescente(int soldados[]){ // a função isCrescent serve para descobrir se um array de inteiros está por ordem decrescente ou é todo igual
    if ((soldados[0] >= soldados[1])&&(soldados[1] >= soldados[2])){
        return 1;   // devolve 1 se ficar confirmado que os 3 elementos do array estão por ordem decrescente ou são todos iguais
    }
    else{return 0;} // devolve 0 caso contrário
}

/*
    O programa deve ler uma linha para cada soldado. 
    Cada linha contém um número inteiro positivo.

    Depois de ler os números, o programa deve imprimir uma linha com a palavra OK, caso esteja ordenado por ordem crescente, decrescente ou sejam todos iguais, ou a palavra NAO, caso contrário.
*/

int main() {
    int soldadoA, soldadoB, soldadoC;
    assert(scanf("%d %d %d", &soldadoA, &soldadoB, &soldadoC) == 3); //através do scanf são lidos as 3 alturas correspondentes aos soldados e através do assert verifica se são realmente números inteiros
    int soldados[3] = {soldadoA, soldadoB, soldadoC}; // as alturas dos soldados lidos são convertidos numa lista (array) de 3 elementos com a mesma ordem pela qual foram inseridos
    int cr = crescente(soldados);
    int d = decrescente(soldados);
    if(cr == 1 || d == 1){   // caso se verifique que os soldados estão por ordem crescente ou decrescente de altura ou se têm todos os mesmo tamanho, imprime-se na tela a palavra "OK"
        printf("%s\n", "OK");
    } else { printf("%s\n", "NAO");} // caso contrário imprime-se a palavra "NAO"
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
