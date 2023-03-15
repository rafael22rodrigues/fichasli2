#include <stdio.h>
#include <assert.h>

/*
    Três dos soldados da Rainha de Copas tiveram que formar diante do sargento. 
    O sargento sabe que a Rainha de Copas odeia a desordem. 
    Os soldados pordem estar por ordem crescente ou decrescente de alturas. 
    Essas duas formações são toleráveis para a rainha. 
    Se não estivem por ordem crescente ou decrescente: Cortem-Ihes a cabeça! 
    A tarefa é, tendo as alturas dos três soldados, descobrir se os soldados estão por ordem crescente, decrescente ou desordenados.
*/



int isCrescent (int s[]){ // a função isCrescent serve para descobrir se um array de inteiros está por ordem crescente ou é todo igual 
    if ((s[0] <= s [1]) && (s[1] <= s[2])){
        return 1;       // devolve 1 se ficar confirmado que os 3 elementos do array estão por ordem crescente ou são todos iguais
    } else{return 0;}  //  devolve 0 caso contrário
}

int isDecrescent(int s[]){ // a função isCrescent serve para descobrir se um array de inteiros está por ordem decrescente ou é todo igual
    if ((s[0] >= s[1])&&(s[1] >= s[2])){
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
    int a, b, c;
    assert(scanf("%d %d %d", &a, &b, &c) == 3); //através do scanf são lidos 3 números inteiros positivos e através do assert verifica se são realmente números inteiros
    int array[4] = {a, b, c}; // os números lidos são convertidos num array de 3 elementos com a mesma ordem pela qual foram inseridos
    int cr = isCrescent(array);
    int d = isDecrescent(array);
    if(cr == 1 || d == 1){   // caso se verifique que o array está por ordem crescente, decrescente ou se todos elementos são iguais imprime-se na tela a palavra "OK"
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
