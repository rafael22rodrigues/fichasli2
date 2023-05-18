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


    REQUISITO: Dados o número de jogadas, e os registos de jogadas pela respetiva ordem, inzel e cmd, deve ser imprimido na tela os resultados das jogadas,
    pela respetiva ordem (separados por espaços), vezes que a arquitetura inzel ganhou, vezes que a arquitetura cmd ganhou e a quantidade de vezes em que
    as arquiteturas acabaram empatadas
*/


int main() {
    int n; // número de jogos
    assert(scanf("%d", &n) == 1);
    int i = 0;// admite-se que o número de comandos é um número inteiro positivo maior que 0, caso contrário o ciclo "do-while" a seguir não é realizado imprimindo no final "0 0 0"
    int empates = 0, cmd_ganha = 0, inzel_ganha = 0; // empates, cmd_ganha e inzel_ganha representam as vezes as arquiteturas empataram, a cmd ganhou e a que a inzel ganhou, respetivamente
    char jogo[3]; //string que será lida e atualizada no ciclo "do-while" a seguir
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
        assert(scanf("%s", jogo)); //lê uma string
        /*
            com a função strstr já definida em string.h verifica se uma das strings constantes definidas acima são iguais à string que acabou de ser inserida
            Caso a string lida não seja igual a uma das constantes definidas acima os valores de empates, cmd_ganha e inzel_ganha não serão atualizados
        */
        if (strstr(jogo,a) || strstr(jogo,e) || strstr(jogo,j)) empates++; //caso as arquiteturas empatem, aumenta-se uma unidade a empates 
        else if (strstr(jogo,c) || strstr(jogo,d) || strstr(jogo,h)) cmd_ganha++; //caso a arquiteturas inzel ganhe, aumenta-se uma unidade a cmd_ganha 
        else if(strstr(jogo,b) || strstr(jogo,f) || strstr(jogo,g)) inzel_ganha++; //caso a arquitetura cmd ganhe, aumenta-se uma unidade a inzel_ganha 
        i++;
    } while(i < n);
    printf("%d %d %d\n", inzel_ganha, cmd_ganha, empates); // imprime-se os resultados finais
    //Fim do programa
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






