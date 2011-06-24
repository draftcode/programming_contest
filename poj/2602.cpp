#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long ll;

int main(void) {
    ll n;
    scanf("%lld", &n);
    int prev = -1;
    ll nines = 0;

    for (ll i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a + b >= 10) {
            if (prev != -1) putchar('0' + prev + 1);
            for (ll k = 0; k < nines; k++) {
                putchar('0');
            }
            nines = 0;
            prev = (a + b) % 10;
        } else if (a + b == 9) {
            nines++;
        } else {
            if (prev != -1) putchar('0' + prev);
            for (ll k = 0; k < nines; k++) {
                putchar('9');
            }
            nines = 0;
            prev = a + b;
        }
    }
    if (prev != -1) putchar('0' + prev);
    for (ll k = 0; k < nines; k++) {
        putchar('9');
    }
    putchar('\n');
    return 0;
}


