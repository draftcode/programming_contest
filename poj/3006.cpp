#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

bool notprimes[1000000];
void make_prime(void) {
    notprimes[0] = true;
    notprimes[1] = true;
    for (int i = 2; i < 1000000; i++) {
        if (notprimes[i] == false) {
            for (int k = 2*i; k < 1000000; k+=i) {
                notprimes[k] = true;
            }
            if (i*i > 1000000) break;
        }
    }
}

int main(void) {
    make_prime();
    for (;;) {
        int a, d, n;
        cin >> a >> d >> n;
        if (a == 0 && d == 0 && n == 0) break;

        int last = 0;
        while (n > 0) {
            if (!notprimes[a]) {
                last = a;
                n--;
            }
            a += d;
        }
        cout << last << endl;
    }
    return 0;
}
