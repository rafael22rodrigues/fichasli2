#include <stdio.h>
#include <assert.h>
#include <string.h>


int main() {
    int n;
    assert(scanf("%d", &n) == 1);
    int i = 0;
    int r = 0, k = 0, l = 0;
    char s[3];
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
        assert(scanf("%s", s));
        if (strstr(s,a) || strstr(s,e) || strstr(s,j)){
            r++;
        } else if (strstr(s,c) || strstr(s,d) || strstr(s,h)){
            l++;
        } else if(strstr(s,b) || strstr(s,f) || strstr(s,g)){
            k++;
        }
        i++;
    } while(i < n);
    printf("%d %d %d\n", l, k, r);
    return 0;
}

