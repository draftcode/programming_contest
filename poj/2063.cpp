#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(c,it) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define clear(v) memset(v, 0, sizeof(v))

int A, Y;
int N, M;
int tab[50000]; // interest
int bonds[10][2]; // amount, interest

void calc_tab(void) {/*{{{*/
    rep(i, 50000) {
        int in = 0;
        rep(j,M) {
            if (i >= bonds[j][0]) {
                in = max(in, tab[i-bonds[j][0]] + bonds[j][1]);
            }
        }
        tab[i] = in;
    }
}/*}}}*/
void solve(void) {
    rep(i,Y) {
        A += tab[A/1000];
    }
    cout << A << endl;
}

int main(void) {
    cin >> N;
    rep(i,N) {
        clear(tab);
        clear(bonds);

        cin >> A >> Y >> M;
        rep(j,M) {
            int b, in;
            cin >> b >> in;
            bonds[j][0] = b / 1000;
            bonds[j][1] = in;
        }
        calc_tab();
        solve();
    }
    return 0;
}


