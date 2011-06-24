#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void solve_hol(int h, int m, int s) {
    char c[19];
    for (int i = 5; i >= 0; i--) {
        c[3*i] = '0' + (h % 2);
        c[3*i + 1] = '0' + (m % 2);
        c[3*i + 2] = '0' + (s % 2);
        h /= 2;
        m /= 2;
        s /= 2;
    }
    c[18] = '\0';
    printf(c);
}

void solve_vert(int h, int m, int s) {
    char c[7];
    c[6] = '\0';
    for (int i = 5; i >= 0; i--) {
        c[i] = '0' + (h % 2);
        h /= 2;
    }
    printf(c);

    for (int i = 5; i >= 0; i--) {
        c[i] = '0' + (m % 2);
        m /= 2;
    }
    printf(c);

    for (int i = 5; i >= 0; i--) {
        c[i] = '0' + (s % 2);
        s /= 2;
    }
    printf(c);
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int h,m,s;
        scanf("%d:%d:%d", &h, &m, &s);

        printf("%d ", i + 1);
        solve_hol(h, m, s);
        printf(" ");
        solve_vert(h, m, s);
        printf("\n");
    }
    return 0;
}


