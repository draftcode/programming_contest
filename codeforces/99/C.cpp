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

void normalize_top(char in[6]) {
  char *mi = min_element(in, in+6);
  if (mi == in)     { return; }
  if (mi == in + 1) { rotate(in, {}); return; }
  if (mi == in + 2) { rotate(in, {}); return; }
  if (mi == in + 3) { rotate(in, {}); return; }
  if (mi == in + 4) { rotate(in, {}); return; }
  if (mi == in + 5) { rotate(in, {}); return; }
}

void rotate(char dice[6], char dir[6]) {
  char temp[6];
  rep (i, 6) temp[i] = dice[dir[i]-1];
  rep (i, 6) dice[i] = temp[i];
}

int main(void) {
  char str[7];
  char in[6];
  cin >> str;
  rep (i, 6) {
    switch (str[i]) {
      case 'R': in[i] = 0; break;
      case 'O': in[i] = 1; break;
      case 'Y': in[i] = 2; break;
      case 'G': in[i] = 4; break;
      case 'B': in[i] = 8; break;
      case 'V': in[i] = 16; break;
    }
  }
  sort(in, in+6);

  do {
  } while (next_permutation(in, in+6));
  return 0;
}
