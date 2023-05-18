#include <stdio.h>
#include <assert.h>
#include <string.h>
#define MAX 1000

/*
  Os anões querem enviar mensagens secretas mas não sabem como fazer 
  utilizando um computador e por isso pediram-te ajuda. 
  O sistema deles reordena o texto utilizando uma dada ordem.

  Se tivermos a ordem 31254 então formamos blocos de 5 letras no texto e imprimimos os caracteres pela ordem dada, 
  isto é, primeiro selecionamos/imprimimos o 3º caractere de cada bloco, depois o 1º de cada bloco, o 2º e assim sucessivamente.
*/

int arraydigitos(char *s, int N){ // a função arraydigitos verifica se todos os digitos inseridos são válidos  
    for (int i = 0; i < N; i++) {
        if (s[i] < 49 || s[i] > 56) return 0; // retorna o valor 0 se achar um carater que não seja um dígito 
    }
    return 1; // retorna o valor 1 caso ao fim do ciclo não consiga achar um carater que não seja digitos, ou seja todos os elementos da string são digitos
}
/*
    Requisitos: Dado um conjunto de números (de 1 a 8) e uma mensagem, o programa deve retornar a mensagem com as partes trocadas, como está descrito no enunciado acima

    NOTA: o programa só funciona sem erros se não faltar nenhum número natural entre 1 e o máximo que for definido
    Ou seja, se programa receber de input: 1256, não irá imprimir 5º e nem o 6º elemento de cada bloco já que o programa
    lê que deve dividir em 4 partes e não 6 
*/
int main() {
    int i = 0; // variável auxiliar que será usada para registar os digitos 
    char mensagem[MAX];
    char ordem_em_carateres[9];
    while(i<8){
        char bloco;
        //através da seguinte função, são lidos os digitos, e armazenados na string ordem_em_carateres
        assert(scanf("%c",&bloco) == 1);
        if (bloco == '\n') break;// Quando mudar de linha é declarado o fim da string com os dígitos
        else ordem_em_carateres[i] = bloco;
        i++;
    }
    if (arraydigitos(ordem_em_carateres, i) == 0) return 0; // verifica se a é a string ordem_em_carateres é só de digitos, caso contrário o programa encerra retornando 0
    int ordem_dos_blocos[9];
    for (int k = 0; k < i; k++) ordem_dos_blocos[k] = ordem_em_carateres[k] - '0' ;//converte a string de digitos numa lista de inteiros de 1 a i
    int blocos_de_mensagens = i;
    assert(scanf("%s",mensagem)); // lê a mensagem a ser convertida 
    //através do ciclo a seguir a mensagem é convertida pelos critérios definidos acima no enunciado
    for (int j = 0; j < blocos_de_mensagens; j++) {
        for (i = 0; i < strlen(mensagem); i++) if (i%blocos_de_mensagens == ordem_dos_blocos[j]-1) printf("%c",mensagem[i]);
    }
    //O Programa acaba mudando de linha
    printf("\n");
    return 0;
}cd
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
