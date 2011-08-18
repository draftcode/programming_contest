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

char s[16];
int b, w;
int bh, bv, bc;
int wh, wv, wc;
int winb, winw;

#define win(x,a,b,c) ((a) == (x) && (a) == (b) && (b) == (c))
void calc(void) {
  b = w = 0;
  rep (i, 9) {
    if (s[i] == 'X') {
      b++;
    } else if (s[i] == 'O') {
      w++;
    }
  }

  bh = bv = bc = wh = wv = wc = 0;
  if (win('X', s[0], s[1], s[2])) bh++;
  if (win('X', s[3], s[4], s[5])) bh++;
  if (win('X', s[6], s[7], s[8])) bh++;
  if (win('O', s[0], s[1], s[2])) wh++;
  if (win('O', s[3], s[4], s[5])) wh++;
  if (win('O', s[6], s[7], s[8])) wh++;
  if (win('X', s[0], s[3], s[6])) bv++;
  if (win('X', s[1], s[4], s[7])) bv++;
  if (win('X', s[2], s[5], s[8])) bv++;
  if (win('O', s[0], s[3], s[6])) wv++;
  if (win('O', s[1], s[4], s[7])) wv++;
  if (win('O', s[2], s[5], s[8])) wv++;
  if (win('X', s[0], s[4], s[8])) bc++;
  if (win('X', s[6], s[4], s[2])) bc++;
  if (win('O', s[0], s[4], s[8])) wc++;
  if (win('O', s[6], s[4], s[2])) wc++;
  winb = bh + bv + bc;
  winw = wh + wv + wc;
}

int main(void) {
  for(;;) {
    scanf("%s", s);
    if (s[0] == 'e') break;

    calc();
    // not yet ended
    if (winb == 0 && winw == 0 && b + w != 9) {
      printf("invalid\n");
      continue;
    }
    // two winners
    if (winb * winw != 0) {
      printf("invalid\n");
      continue;
    }
    // number
    if (!(b == w || (b == w+1 && winw == 0))) {
      printf("invalid\n");
      continue;
    }

    printf("valid\n");
  }
  return 0;
}
