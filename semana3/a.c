#include <stdio.h>
#include <assert.h>
#define MAX 1000

/*
  Os anões querem enviar mensagens secretas mas não sabem como fazer 
  utilizando um computador e por isso pediram-te ajuda. 
  O sistema deles reordena o texto utilizando uma dada ordem.

  Se tivermos a ordem 31254 então formamos blocos de 5 letras no texto e imprimimos os caracteres pela ordem dada, 
  isto é, primeiro selecionamos/imprimimos o 3º caractere de cada bloco, depois o 1º de cada bloco, o 2º e assim sucessivamente.
*/

int arraydigitos(char *s, int N){ // a função arraydigitos indica se uma string é toda composta por digitos 
    int i;
    for (i = 0; i < N; i++) {
        if (s[i] < 48 || s[i] > 57) return 0; // retorna o valor 0 se achar um carater que não seja um dígito 
    }
    return 1; // retorna o valor 1 caso ao fim do ciclo não consiga achar um carater que não seja digitos, ou seja todos os elementos da string são digitos
}

int tamanho(char *s){ // função que determina o tamanho total de uma string
    int i;
    for (i = 0; s[i] != '\0'; i++)
        ;
    return i;
}

int divisiveis(char *s, int x, int y){ //a função divisiveis determina quantas posições numa string, numa divisã exata com x tem resto de y-1
    int i, r=0;
    for (i = 0; i < tamanho(s); i++)
    {
        if (i%x == y-1)
        {
            r++;
        }
    }
    return r;
}

void funcaoc(char *s, char *a, int x, int y){ // é selecionado o carater de ordem y que será copiado para a bloco de tal ordem  
    int i;
    int l = 0;
    for (i = 0; i < tamanho(s); i++)
    {
        if (i%x == y-1)
        {
            a[l]=s[i];
            l++;
        }
    }
}

/*
    Requisitos:
    O programa lê:

    -uma linha com as posições das letras (no máximo são 8 posições). Cada posição aparece uma só vez na lista
    -uma linha com a mensagem (a mensagem tem no máximo 1000 caracteres)

    NOTA: o programa só funciona sem erros se não faltar nenhum número natural entre 1 e o máximo que for definido
    Ou seja, se programa receber de input: 1256, não irá imprimir 5º e nem o 6º elemento de cada bloco já que o programa
    lê que deve dividir em 4 partes e não 6 
*/
int main() {
    int i = 0;
    char s[MAX];
    char a[9];
    while(i<8){
        char c;
        assert(scanf("%c",&c) == 1);
        if (c == '\n'){// Quando mudar de linha é declarado o fim o fim da string com os dígitos
            break;
        } else{
            a[i] = c;
        }
        i++;
    }
    if (arraydigitos(a, i) == 0) return 0; // verifica se a é uma string só de digitos, caso contrário o programa encerra retornando 0
    int ar[9];
    for (int k = 0; k < i; k++) {//converte a string de digitos num array de inteiros de 1 a i
        ar[k] = a[k] - '0' ;
    }
    int splitInterval = i;
    assert(scanf("%s",s)); // lê a mensagem a ser convertida 
    int a1 = divisiveis(s,splitInterval,1); //calcula o tamanho do primeiro bloco
    int a2 = divisiveis(s,splitInterval,2); //calcula o tamanho do segunda bloco
    int a3 = divisiveis(s,splitInterval,3); //calcula o tamanho do terceiro bloco
    int a4 = divisiveis(s,splitInterval,4); //calcula o tamanho do quarto bloco
    int a5 = divisiveis(s,splitInterval,5); //calcula o tamanho do quinto bloco
    int a6 = divisiveis(s,splitInterval,6); //calcula o tamanho do sexto bloco
    int a7 = divisiveis(s,splitInterval,7); //calcula o tamanho do sétimo bloco
    int a8 = divisiveis(s,splitInterval,8); //calcula o tamanho do oitavo bloco
    /*
        NOTA: os valores acima só são calculados caso o valor de i seja menor ou igual à sua ordem, senão a função divisíveis irá retornar 0
        O mesmo é válido para as strings definidas abaixo que corresponde aos blocos possíveis
    */
    char s1[a1]; //primeiro bloco
    char s2[a2]; //segundo bloco
    char s3[a3]; //terceiro bloco
    char s4[a4]; //quarto bloco
    char s5[a5]; //quinto bloco
    char s6[a6]; //sexto bloco
    char s7[a7]; //sétimo bloco
    char s8[a8]; //oitavo bloco
    //pela função funcaoc a string principal s é dividida pelos blocos acima definidos
    funcaoc(s,s1,splitInterval,1);
    funcaoc(s,s2,splitInterval,2);
    funcaoc(s,s3,splitInterval,3);
    funcaoc(s,s4,splitInterval,4);
    funcaoc(s,s5,splitInterval,5);
    funcaoc(s,s6,splitInterval,6);
    funcaoc(s,s7,splitInterval,7);
    funcaoc(s,s8,splitInterval,8);

    //Imprime-se os blocos pela ordem definida acima
    for (int j = 0; j < splitInterval; j++) {
        if(ar[j] == 1){
            for (int q = 0; q < a1; q++)
            {
                printf("%c",s1[q]);
            }
        }
        else if (ar[j] == 2){
            for (int q = 0; q < a2; q++)
            {
                printf("%c",s2[q]);
            }

        }
        else if (ar[j] == 3){
            for (int q = 0; q < a3; q++)
            {
                printf("%c",s3[q]);
            }
        }
        else if (ar[j] == 4){
            for (int q = 0; q < a4; q++)
            {
                printf("%c",s4[q]);
            }
        }
        else if (ar[j] == 5){
            for (int q = 0; q < a5; q++)
            {
                printf("%c",s5[q]);
            }
        }
        else if (ar[j] == 6){
            for (int q = 0; q < a6; q++)
            {
                printf("%c",s6[q]);
            }
        }
        else if (ar[j] == 7){
            for (int q = 0; q < a7; q++)
            {
                printf("%c",s7[q]);
            }
        }
        else if (ar[j] == 8){
            for (int q = 0; q < a8; q++)
            {
                printf("%c",s8[q]);
            }
        }
    }
    printf("\n");
    return 0;
}
/*
Input:
31254
ATACAMOSAOAMANHECERPREPAREMAAGUARDENTEEAMANTEIGA

Output:
ASAEPARENAAMAEREUNMITOMCEMATAGAOHPRGEAECANRAADET

Input:
132456
WZOHKOYJMVBMIBKPJOBCXIBLNEJFBCZJOURDENIFCCMUHKBQVNYEAZQIOATMJMCPGYVUYSABTNKMBARSIBXJCXDPRNWWDBXCULSCTKAWDROZTQTQUVDEYQACTKWSGAHFOBIGBSNWSYZ

Output:
WYIBNZEMVQJVTRCWUATDTHBZOMKXJOIHYOCYKIDDSDTYWONZJBCEJNUNIMUNSXWLWQEKFSHVPIFUFKEAPSMBPBCRQQSBWKBJBBRCBATGABXRXTOUAGISOMOLCDCQZMYBAJNCKZVCAGY

Input:
71234865
TVQMXKYZRHXUKHVUJRKYTTNNZXLOMYHKZDVPPKQVSWWJZDEVNKXDWZBVMFINWNGLZACTCFODOBHXMXTEKOGWVTJRXUDSQYYXSBAXAPLYTMHOSZULSWVXMODWCWVQ

Output:
YVNHQEBGOTJYLUDTRJZZSNMZOKXSTSCVHRXDWKFABOUBMWWQXKLVWXICHGDAHVVMUYOPJDNTXWSXOXQZUNKVVVLDERXYLWKHTYKDZNFXTYPZOXKTMPZWWCMVQASM

Input:
32154
HTAUBAKVILVUMHBNYGRRKCQWZLGBAJIDFQXUOGISLZZURUDQCNCKATJYTEXKTSUQAKYKAQMSMBUFNTJIBDHHURULUVXXBFWENMQETAACAVJIMATWCEAQTAYCRNPOHQMUGAORFYETPVFZGGA

Output:
AVMGQBFGZQAEUKMTHLBMAICAPUFVATKUYCGDOZDKTSYSNDUXNAJWTNMRPGHAVNKLIULUCYTKMFBRXETVTQRQOTGBLBRZJXSRNJKAQUIUVWEAAACHAEZUIHRWAQIUCTXQABJHUFQCMEYOGYF




*/
