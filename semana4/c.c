#include <stdio.h>
#include <assert.h>

int countingchar(char *s, int x){
    int i, j;

    for (i = 0; i < x && s[i] != '\0'; i++) {
        for (j = i + 1; j < x && s[j] != '\0'; j++) {
            if (s[i] == s[j]) {
                return 1;
            }
        }
    }

    return 0;
}

int tamanho (char *s){
    int i;
    for (i = 0; s[i] != '\0'; i++)
        ;
    return i;
}



int fstposicao(char *s, int x){
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if(tamanho(s+i) < x) return -1;
        if(countingchar(s+i,x) == 0) return i;
    }
    return -1;
}

int main() {
    int n;
    assert(scanf("%d",&n)==1);
    int i = 0;
    char s[1000];
    int ar[n];
    while (i <n){
        int k;
        assert(scanf("%d",&k)==1);
        assert(scanf("%s",s));
        int r = fstposicao(s,k);
        ar[i] = r;
        i++;
    }
    for (int j = 0; j < n; j++) {
        printf("%d\n",ar[j]);
    }
    return 0;
}
