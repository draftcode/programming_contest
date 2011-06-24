#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <climits>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(c,it) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int var, con;

void solve(string& str) {
    int sign = 1;
    int rev = 1;
    int num = 0;
    for (unsigned int i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) {
            num *= 10;
            num += str[i] - '0';
        } else if (str[i] == '+') {
            con += sign * rev * num;
            num = 0;
            sign = 1;
        } else if (str[i] == '-') {
            con += sign * rev * num;
            num = 0;
            sign = -1;
        } else if (str[i] == 'x') {
            if (num == 0) num = 1;
            var += sign * rev * num;
            num = 0;
            sign = 1;
        } else if (str[i] == '=') {
            con += sign * rev * num;
            num = 0;
            sign = 1;
            rev = -1;
        }
    }
    con += sign * rev * num;
    con *= -1;
}

int main(void) {
    int n;
    cin >> n;
    rep (i, n) {
        string str;
        cin >> str;

        var = 0; con = 0;
        solve(str);
        if (var == 0 && con == 0) {
            cout << "IDENTITY" << endl;
        } else if (var == 0 && con != 0) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << int(floor(con*1.0/var*1.0)) << endl;
        }
    }
    return 0;
}
