#include <stdio.h>
#include <assert.h>

int visiveis (int *v, int N){
    int r = 0;
    int i = 0;
    int max = 0;
    for(; i < N; i++){
        if(v[i] > max){
            max = v[i];
            r++;
        }
    }
    return r;
}

int main() {
    int n;
    assert(scanf("%d",&n)==1);
    int i = 0;
    int array[10000] ;
    while (i <n){
        int k;
        assert(scanf("%d",&k)==1);
        int j = 0;
        while (j < k){
            int q;
            assert(scanf("%d",&q) == 1);
            array[j] = q;
            j++;
        }
        printf("%d\n",visiveis(array,k));
        i++;
    }
    return 0;
}
