#include <stdio.h>
#include <assert.h>
#define MAX 100

int presente (int *a, int x, int n){
    int i, r = 0;
    for (i = 0; i < n; i++) {
        if(a[i] == x) r++;
    }
    if(r == 1) return 1;
    return 0;
}

void resultado (int *a, int x){
    int l = x, p = 0, v[MAX];
    while(a[l-1] != 0){
        if(presente(v,a[l-1],p) == 1){
            printf("%s", " CICLO INFERNAL");
            break;
        }
        v[p]=l;
        p++;
        printf(" %d",a[l-1]);
        l=a[l-1];
    }
}


int main() {
    int casos;
    assert(scanf("%d", &casos)==1);
    int i = 0;
    int k, guincheinicial, guinches[100];
    while (i<casos){
        assert(scanf("%d",&k)==1);
        assert(scanf("%d",&guincheinicial)==1);
        int j = 0;
        while(j < k){
            int identificador;
            assert(scanf("%d",&identificador)==1);
            guinches[j] = identificador;
            j++;
        }
        printf("%d",guincheinicial);
        resultado(guinches,guincheinicial);
        printf("\n");
        i++;
    }

    return 0;
}
