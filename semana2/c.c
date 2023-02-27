#include <stdio.h>
#include <assert.h>
#include <string.h>



int main() {
    int n;
    assert(scanf("%d", &n) == 1);
    int i = 0;
    char str[3];
    int r = 0, k = 0, l = 0;
    while (i<n){
        assert(scanf("%s", &str) == 1);
        int ret1 = strstr(str, "@*");
        int ret2 = strstr(str, "@-");
        int ret3 = strstr(str, "@+");
        int ret4 = strstr(str, "|*");
        int ret5 = strstr(str, "|-");
        int ret6 = strstr(str, "|+");
        int ret7 = strstr(str, "X*");
        int ret8 = strstr(str, "X-");
        int ret9 = strstr(str, "X+");
        if (ret1 || ret2 || ret3 || ret4 || ret5 || ret6 || ret7 || ret8 || ret9){
            if (ret1 || ret5 || ret9){
                r++;
            }
            if (ret2 || ret6 || ret7){
                k++;
            }
            if (ret3 || ret4 || ret8){
                l++;
            }
            i++;
        }
        else return 0;
    }
    printf("%d %d %d\n", l, k, r);
    return 0;
}
