#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int n;
string segments[10];
int map[10][10];
int len[10];

void make_map(void) {/*{{{*/
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int leni = len[i];
            int lenj = len[j];
            for (int k = 1; k <= leni && k <= lenj; k++) {
                if (segments[i].compare(leni-k, k, segments[j], 0, k) == 0) {
                    map[i][j] = k;
                }
            }
        }
    }
}/*}}}*/

void solve(void) {/*{{{*/
    int m = 0;
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    do {
        int t = 0;
        for (int i = 0; i < n - 1; i++) {
            t += map[arr[i]][arr[i+1]];
        }
        m = max(t, m);
    } while (next_permutation(arr, arr+n));

    cout << accumulate(len, len+n, 0) - m << endl;
}/*}}}*/

int main(void) {/*{{{*/
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> segments[j];
            len[j] = segments[j].length();
        }
        memset(map, 0, sizeof(map));
        make_map();
        solve();
    }
    return 0;
}/*}}}*/


