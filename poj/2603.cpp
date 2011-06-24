#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int table[100001];

int main(void) {
    for (int i = 1; i < 10001; i++) {
        table[i] = 0;
    }
    for (int i = 0; i < 10; i++) {
        int n;
        scanf("%d", &n);
        while (n != 1) {
            for (int k = 2; k <= n; k++) {
                if (n % k == 0) {
                    table[k]++;
                    n /= k;
                    break;
                }
            }
        }
    }

    unsigned long long count = 1;
    for (int i = 2; i < 10001; i++) {
        if (table[i] > 0) {
            count *= table[i] + 1;
        }
    }
    printf("%llu\n", count % 10);
    return 0;
}


