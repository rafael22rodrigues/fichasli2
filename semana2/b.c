#include <stdio.h>
#include <assert.h>

int main() {
    int c;
    assert(scanf("%d", &c) == 1);
    int a;
    assert(scanf("%d", &a)==1);
    int n;
    assert(scanf("%d", &n) == 1);
    int i = 0, b;
    int array[n];
    while (i < n){
        assert(scanf("%d", &b) == 1);
        if(b == 1 || b == -1){
            array[i] = b;
            i++;
        } else return 0;

    }
    int r = c;
    for (int j = 0; j < n; j++) {
        if (array[j] == -1 && r > 0){
            r--;
        } else if (array[j] == 1 && r < a){
            r++;
        }
    }
    printf("%d\n", r);

    return 0;
}
