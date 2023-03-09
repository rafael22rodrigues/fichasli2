#include <stdio.h>
#include <assert.h>
#define MAX 1000

int arraydigitos(char *s, int N){
    int i;
    for (i = 0; i < N; i++) {
        if (s[i] < 48 || s[i] > 57) return 0;
    }
    return 1;
}

int tamanho(char *s){
    int i;
    for (i = 0; s[i] != 0; i++)
        ;
    return i;
}

int divisiveis(char *s, int x, int y){
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

void funcaoc(char *s, char *a, int x, int y){
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


int main() {
    int i = 0;
    char s[MAX];
    char a[9];
    while(i<8){
        char c;
        assert(scanf("%c",&c) == 1);
        if (c == '\n'){
            break;
        } else{
            a[i] = c;
        }
        i++;
    }
    if (arraydigitos(a, i) == 0) return 0;
    int ar[9];
    for (int k = 0; k < i; k++) {
        ar[k] = a[k] - '0' ;
    }
    int splitInterval = i;
    assert(scanf("%s",s));
    int a1 = divisiveis(s,splitInterval,1);
    int a2 = divisiveis(s,splitInterval,2);
    int a3 = divisiveis(s,splitInterval,3);
    int a4 = divisiveis(s,splitInterval,4);
    int a5 = divisiveis(s,splitInterval,5);
    int a6 = divisiveis(s,splitInterval,6);
    int a7 = divisiveis(s,splitInterval,7);
    int a8 = divisiveis(s,splitInterval,8);
    char s1[a1];
    char s2[a2];
    char s3[a3];
    char s4[a4];
    char s5[a5];
    char s6[a6];
    char s7[a7];
    char s8[a8];
    funcaoc(s,s1,splitInterval,1);
    funcaoc(s,s2,splitInterval,2);
    funcaoc(s,s3,splitInterval,3);
    funcaoc(s,s4,splitInterval,4);
    funcaoc(s,s5,splitInterval,5);
    funcaoc(s,s6,splitInterval,6);
    funcaoc(s,s7,splitInterval,7);
    funcaoc(s,s8,splitInterval,8);

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

