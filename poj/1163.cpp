#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int n;
int vv[102][102];
int dp[102][102];

int solve(int row, int col) {
    if (dp[row][col] != -1) return dp[row][col];
    if (row >= n) {
        dp[row][col] = 0;
    } else {
        dp[row][col] = vv[row][col] + max(solve(row+1, col), solve(row+1, col+1));
    }

    return dp[row][col];
}

int main(void) {
    memset(dp, -1, 102*102*sizeof(int));
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int k;
            scanf("%d", &k);
            vv[i][j] = k;
        }
    }
    printf("%d\n", solve(0, 0));
    return 0;
}

