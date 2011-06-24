#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <map>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(c,it) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int main(void) {
    int l, n;
    cin >> l >> n;

    map<string,string> m;
    rep (i, l) {
        string s,t;
        cin >> s >> t;
        m.insert(make_pair(s,t));
    }

    rep (i, n) {
        string s;
        cin >> s;
        map<string,string>::iterator p;
        p = m.find(s);
        if (p != m.end()) { cout << p->second << endl; }
        else {
            char c1 = s[s.size()-1];
            char c2 = '\0';
            if (s.size() >= 2) {
                c2 = s[s.size()-2];
            }
            if (c1 == 'y' &&
                c2 != 'a' && c2 != 'i' && c2 != 'u' && c2 != 'e' && c2 != 'o') {
                cout << s.substr(0, s.size() - 1) << "ies" << endl;
            } else if (c1 == 'o'
                    || c1 == 's'
                    || (c2 == 'c' && c1 == 'h')
                    || (c2 == 's' && c1 == 'h')
                    || c1 == 'x') {
                cout << s << "es" << endl;
            } else {
                cout << s << "s" << endl;
            }
        }
    }

    return 0;
}
