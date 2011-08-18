#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
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

int compare(char *s, char *t) {
  if (strlen(s) != strlen(t)) {
    return strlen(s) - strlen(t);
  } else {
    return strcmp(s, t);
  }
}

int main(void) {
  char in[16];
  scanf("%s", in);
  int c = strlen(in);
  if (c % 2 == 1) c++;

  char s[128];
  for (;;) {
    rep (i, c/2) { s[i+c/2] = '7'; s[i] = '4'; }
    s[c] = '\0';
    do {
      if (compare(s, in) >= 0) {
        cout << s << endl;
        return 0;
      }
    } while (next_permutation(s, s+c));
    c += 2;
  }

  return 0;
}

