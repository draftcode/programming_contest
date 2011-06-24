#include <cstdio>
#include <algorithm>
using namespace std;

int parse(char *s) {/*{{{*/
    int ret = 0;
    int p = 1;
    for (char c = *s++; c; c = *s++) {
        if (c == 'm') {
            ret += 1000 * p;
            p = 1;
        } else if (c == 'c') {
            ret += 100 * p;
            p = 1;
        } else if (c == 'x') {
            ret += 10 * p;
            p = 1;
        } else if (c == 'i') {
            ret += p;
            p = 1;
        } else {
            p = c - '0';
        }
    }
    return ret;
}/*}}}*/

void out(int i) {
    int k;
    if (k = i / 1000) {
        if (k > 1) putchar(k+'0');
        putchar('m');
        i %= 1000;
    }
    if (k = i / 100) {
        if (k > 1) putchar(k+'0');
        putchar('c');
        i %= 100;
    }
    if (k = i / 10) {
        if (k > 1) putchar(k+'0');
        putchar('x');
        i %= 10;
    }
    if (i) {
        if (i > 1) putchar(i+'0');
        putchar('i');
    }
    putchar('\n');
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char c1[9], c2[9];
        scanf("%s %s", c1, c2);

        int x, y;
        x = parse(c1);
        y = parse(c2);
        out(x+y);
    }
    return 0;
}





