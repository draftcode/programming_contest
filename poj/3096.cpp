#include <iostream>
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

int tab[26][26];

int main(void) {
    char str[100];
    for (;;) {
        scanf("%s", str);
        if (str[0] == '*') break;
        for (int d = 1; str[d]; d++) {
            zclear(tab);
            for (int i = 0; str[i+d]; i++) {
                if (tab[str[i]-'A'][str[i+d]-'A'] != 0) {
                    printf("%s is NOT surprising.\n", str);
                    goto fin;
                } else {
                    tab[str[i]-'A'][str[i+d]-'A'] = 1;
                }
            }
        }
        printf("%s is surprising.\n", str);
fin: ;
    }

    return 0;
}
