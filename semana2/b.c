#include <stdio.h>
#include <assert.h>
/*
    Um elevador tem 2 botões, o de subir um andar e o de descer um andar.

    Com este programa pretende-se descobrir qual é a posição final desse elevador.
    Consideremos o botão de subida com o valor 1 e o de descida com o valor -1.

    REQUISITO: Dado, pela respetiva ordem, os numeros, do andar onde o elevador começa o percurso, o último andar da respetiva construção, o número de comandos 
    e por fim as etapas ao longo do percurso (o número de etapas tem que ser o mesmo que o de comandos)  
*/
int main() {
    int andar_inicial;
    //lê-se o número do andar inicial através do scanf, já o assert verifica se o andar_inicial é mesmo um número inteiro
    assert(scanf("%d", &andar_inicial) == 1);
    int ultimo_andar;
    //lê-se o número do último andar através do scanf, já o assert verifica se o ultimo_andar é mesmo um número inteiro
    assert(scanf("%d", &ultimo_andar)==1);
    int n;
    //lê-se o número de comandos através do scanf, já o assert verifica se o numero de comandos é mesmo um número inteiro
    assert(scanf("%d", &n) == 1);
    int i = 0, etapa; // admite-se que o número de comandos é um número inteiro positivo caso contrário imprime-se na tela o andar inicial
    int percurso[n];//o percurso do tamanho do número de comandos
    while (i < n){
        //lê-se o número da etapa através do scanf, já o assert verifica se o valor da etapa é mesmo um número inteiro
        assert(scanf("%d", &etapa) == 1);
        //o valor de etapa só pode ser 1 ou -1 caso contrário o programa encerra retornando 0
        if(etapa == 1 || etapa == -1){
            percurso[i] = etapa; // o  armazena todos os valores das etapas ao longo do ciclo
            i++;
        } else return 0;
    }
    int paragem = andar_inicial; //começa no andar inicial definido anteriormente
    for (int j = 0; j < n; j++) {
        if (percurso[j] == -1 && paragem > 0) paragem--;     // se na posição j está o valor -1 e a paragem atual é um número positivo, a paragem diminui uma unidade (ou seja, o elevador desceu 1 andar)         
        else if (percurso[j] == 1 && paragem < ultimo_andar) paragem ++; // se na posição j está o valor 1 e a paragem atual é um número menor que a (o último andar), a paragem aumenta uma unidade (ou seja, o elevador subiu 1 andar)
    }
    printf("%d\n", paragem);// imprime-se o valor final onde o elevador para
    return 0;
}

/*

Testes (Cenários Testados):

Input:
3
8
7
1
-1
-1
-1
1
1
1

Output:
4

Input:
3
6
4
1
1
1
1

Output:
6

Input:
1
4
5
-1
1
-1
-1
1

Output:
1

*/



