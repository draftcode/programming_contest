#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
using namespace std;

typedef vector<complex<int> > vc;

vc input(void) {/*{{{*/
    vc ret;
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int j, k;
        scanf("%d %d", &j, &k);
        ret.push_back(complex<int>(j, k));
    }

    complex<int> diff = ret[0];
    for (vc::iterator it = ret.begin(); it != ret.end(); it++) {
        *it = *it - diff;
    }

    while (ret[1].real() != 0 || ret[1].imag() < 0) {
        for (int i = 0; i < m; i++) {
            ret[i] *= complex<int>(0, 1);
        }
    }

    return ret;
}/*}}}*/

bool compare(vc v0, vc vn) {/*{{{*/
    if (v0.size() != vn.size()) return false;

    for (unsigned int i = 0; i < v0.size(); i++) {
        if (v0[i] != vn[i]) return false;
    }

    return true;
}/*}}}*/

vc reverse(vc vn) {/*{{{*/
    vc ret;
    complex<int> diff = vn.back();
    for (vc::reverse_iterator it = vn.rbegin(); it != vn.rend(); it++) {
        ret.push_back(*it - diff);
    }

    while (ret[1].real() != 0 || ret[1].imag() < 0) {
        for (unsigned int i = 0; i < ret.size(); i++) {
            ret[i] *= complex<int>(0, 1);
        }
    }

    return ret;
}/*}}}*/

int main(void) {/*{{{*/
    for (;;) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;

        vc v0 = input();
        for (int i = 0; i < n; i++) {
            vc vn = input();
            if (compare(v0, vn)) {
                printf("%d\n", i + 1);
            } else if (compare(v0, reverse(vn))) {
                printf("%d\n", i + 1);
            }
        }
        printf("+++++\n");
    }

    return 0;
}/*}}}*/

