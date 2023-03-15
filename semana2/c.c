#include <stdio.h>
#include <assert.h>
#include <string.h>

/*
    Pretende-se pôr duas IA's de arquitetura inzel e cmd a simular um jogo de pedra, papel, tesoura.
    O programa serve para armazenar os resultados obtidos ao longo das partidas.

    A representação dos simbolos que representam o pedra, papel, tesoura consegue ser visto na tabela abaixo

        Inzel    Cmd
Pedra    @        *
Papel    |        -
Tesoura  X        +
*/


int main() {
    int n; // número de comandos
    assert(scanf("%d", &n) == 1);
    int i = 0;// admite-se que o número de comandos é um número inteiro positivo maior que 0, caso contrário o ciclo "do-while" a seguir não é realizado imprimindo no final "0 0 0"
    int r = 0, k = 0, l = 0; // r, k e l representam as vezes as arquiteturas empataram, a cmd ganhou e a que a inzel ganhou, respetivamente
    char s[3]; //string que será lida e atualizada no ciclo "do-while" a seguir
    //as próximas strings de a a j são todas as combinações possíveis que pode sair de um jogo de pedra papel tesoura entre as arquiteturas inzel e cmd
    char *a = "@*";
    char *b = "@-";
    char *c = "@+";
    char *d = "|*";
    char *e = "|-";
    char *f = "|+";
    char *g = "X*";
    char *h = "X-";
    char *j = "X+";

    do {
        assert(scanf("%s", s)); //lê uma string
        /*
            com a função strstr já definida em string.h verifica se uma das strings constantes definidas acima são iguais à string que acabou de ser inserida
            Caso a string lida não seja igual a uma das constantes definidas acima os valores de r, k e l não serão atualizados
        */
        if (strstr(s,a) || strstr(s,e) || strstr(s,j)){
            r++; //caso as arquiteturas empatem r aumenta uma unidade 
        } else if (strstr(s,c) || strstr(s,d) || strstr(s,h)){
            l++; //caso a arquiteturas inzel ganhe l aumenta uma unidade 
        } else if(strstr(s,b) || strstr(s,f) || strstr(s,g)){
            k++; //caso a arquitetura cmd ganhe k aumenta uma unidade 
        }
        i++;
    } while(i < n);
    printf("%d %d %d\n", l, k, r); // imprime-se os resultados finais
    return 0;
}

/*
Input:
10
@-
X+
|-
@*
@+
X*
X-
|*
|+
@+


Output:
4 3 3

Input:
7
@*
@-
|+
X-
X*
X- 
X+


Output:
2 3 2

*/






