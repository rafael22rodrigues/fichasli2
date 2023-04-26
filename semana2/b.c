#include <stdio.h>
#include <assert.h>
/*
    Um elevador tem 2 botões, o de subir um andar e o de descer um andar.

    Com este programa pretende-se descobrir qual é a posição final desse elevador.
    Consideremos o botão de subida com o valor 1 e o de descida com o valor -1.
*/
int main() {
    int c;// andar inicial
    assert(scanf("%d", &c) == 1);
    int a;// último andar
    assert(scanf("%d", &a)==1);
    int n;//número de comandos
    assert(scanf("%d", &n) == 1);
    int i = 0, b; // admite-se que o número de comandos é um número inteiro positivo caso contrário imprime-se na tela o andar inicial
    int array[n];//array do tamanho do número de comandos
    while (i < n){
        assert(scanf("%d", &b) == 1);//o valor de b só pode ser 1 ou -1 caso contrário o programa encerra retornando 0
        if(b == 1 || b == -1){
            array[i] = b; // o array armazena todos os valores de b ao longo do ciclo
            i++;
        } else return 0;
    }
    int r = c;//começa no andar inicial definido anteriormente
    for (int j = 0; j < n; j++) {
        if (array[j] == -1 && r > 0) r--;     // se na posição j está o valor -1 e o r atual é um número positivo, r diminui uma unidade (ou seja, o elevador desceu 1 andar)         
        else if (array[j] == 1 && r < a) r++; // se na posição j está o valor 1 e o r atual é um número menor que a (o último andar), r aumenta uma unidade (ou seja, o elevador subiu 1 andar)
    }
    printf("%d\n", r);// imprime-se o valor final de r
    return 0;
}

/*
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



