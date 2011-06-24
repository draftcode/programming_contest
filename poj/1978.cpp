#include <cstdio>
#include <algorithm>
using namespace std;
int v[50];
int temp[50];

void swap(int p, int c) {
    for (int i = 0; i < c; i++) {
        temp[i] = v[p-1+i];
    }

    for (int i = p - 2; i >= 0; i--) {
        v[i + c] = v[i];
    }

    for (int i = 0; i < c; i++) {
        v[i] = temp[i];
    }
}

int main(void) {
    for (;;) {
        int n, r;
        scanf("%d %d", &n, &r);
        if (n == 0 && r == 0) break;
        for (int i = 0; i < n; i++) {
            v[i] = n - i;
        }

        for (int i = 0; i < r; i++) {
            int p, c;
            scanf("%d %d", &p, &c);
            swap(p, c);
        }

        printf("%d\n", v[0]);
    }
    return 0;
}




