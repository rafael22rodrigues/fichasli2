#include <stdio.h>
#include <assert.h>

int emtalhora (int *v1, int *v2, int x, int N){
    int i, r=0;
    for (i = 0; i < N ; i++) {
        if(x>=v1[i] && x<=v2[i]) r++;
    }
    return r;
}
void retira_rep(int v[], int *N){
    int i, j;
    for (i = 1; i < *N; i++) {
        if (v[i] == v[i-1]) {
            for (j = i; j < *N-1; j++) {
                v[j] = v[j+1];
            }
            (*N)--;
            i--;
        }
    }
}

int main() {
    int vigia;
    assert(scanf("%d",&vigia)==1);
    int n;
    assert(scanf("%d",&n)==1);
    int i = 0;
    int agente, hi, hf;
    int agentes[n], his[n], hfs[n];
    while(i<n){
        assert(scanf("%d", &agente)==1);
        if(agente>vigia) return 0;
        assert(scanf("%d %d", &hi, &hf) == 2);
        agentes[i] = agente;
        his[i] = hi;
        hfs[i] = hf;
        i++;
    }
    int j = 0;
    int res[24];
    while(j<24){
        res[j] = emtalhora(his,hfs,j,n);
        j++;
    }
    int l = 0;
    int resultado[n];
    while(l<24) {
        if(res[l] != 0 && res[l] != 1){
            printf("%d", l);
            int p = 0;
            for (int k = 0; k < n; k++) {
                if(l<=hfs[k] && l>=his[k]){
                    resultado[p] = agentes[k];
                    p++;
                }
            }
            int a, aux;
            for (a = 1; a < p; a++) {
                for (i = 0; i < p - 1; i++) {
                    if (resultado[i] > resultado[i + 1]) {
                        aux = resultado[i];
                        resultado[i] = resultado[i + 1];
                        resultado[i + 1] = aux;
                    }
                }
            }
            retira_rep(resultado,&p);
            for (int k = 0; k < p; k++) {
                printf(" %d", resultado[k]);
            }
            printf("\n");
        }
        l++;
    }
    return 0;
}

