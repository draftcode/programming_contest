#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void solve(vector<int> v) {
    sort(v.begin(), v.end());
    int ret = accumulate(v.begin() + 1, v.end() - 1, 0);
    printf("%ld\n", ret / (v.size() - 2));
}

int main(void) {
    for (;;) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;

        vector<int> v;
        for(int i = 0; i < n; i++) {
            int k;
            scanf("%d", &k);
            v.push_back(k);
        }
        solve(v);
    }
    return 0;
}


