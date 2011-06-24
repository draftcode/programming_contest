#include <iostream>
#include <cstdio>
using namespace std;

int L = 10;
int n = 3;
int x[] = {2, 6, 7};

void solve(int L, int n, int x[]) {
    int minl = 0, maxl = 0;
    for (int i = 0; i < n; i++) {
        minl = max(minl, min(L-x[i], x[i]));
        maxl = max(maxl, max(L-x[i], x[i]));
    }

    cout << minl << " " << maxl << endl;
}

int main(void) {
    int probs;
    scanf("%d", &probs);
    for (int i = 0; i < probs; i++) {
        int L, n;
        scanf("%d %d", &L, &n);
        int x[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", x+j);
        }
        solve(L, n, x);
    }
    return 0;
}

