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

int main(void) {
  int count = 0;
  int current = 0;
  int a, b, c, d;
  for (;;) {
    cin >> a >> b >> c >> d;
    if (a == 0 && b == 0 && c == 0 && d == 0) break;
    count = 80;
    current = a;

    // first number.
    if (current <= b) {
      count += 40 + current - b;
    } else {
      count += current - b;
    }
    current = b;

    count += 40;

    // turn the dial counter-clockwise until the 2nd number.
    if (current >= c) {
      count += 40 - current + c;
    } else {
      count += c - current;
    }
    current = c;

    // turn the dial clockwise until the 3rd number.
    if (current <= d) {
      count += 40 + current - d;
    } else {
      count += current - d;
    }

    // output
    cout << count * 9 << endl;
  }

  return 0;
}
