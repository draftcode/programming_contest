#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

unsigned char m1, m2, m3, m4;
unsigned char b1, b2, b3, b4;

void parse(string s, unsigned char &b1, unsigned char &b2, unsigned char &b3, unsigned char &b4) {
  int i1, i2, i3, i4;
  sscanf(s.c_str(), "%d.%d.%d.%d", &i1, &i2, &i3, &i4);
  b1 = i1;
  b2 = i2;
  b3 = i3;
  b4 = i4;
}

void make_top(unsigned char &m) {
  unsigned char b = 0xff;
  while (m != b) {
    b <<= 1;
    m &= b;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  m1 = m2 = m3 = m4 = 0xff;

  string s;
  int n;
  cin >> n;

  cin >> s;
  parse(s, b1, b2, b3, b4);

  for (int i = 1; i < n; i++) {
    unsigned char i1, i2, i3, i4;
    cin >> s;
    parse(s, i1, i2, i3, i4);
    m1 &= ~(b1 ^ i1);
    m2 &= ~(b2 ^ i2);
    m3 &= ~(b3 ^ i3);
    m4 &= ~(b4 ^ i4);
  }

  if (m1 != 0xff) {
    make_top(m1);
    m2 = m3 = m4 = 0;
  } else if (m2 != 0xff) {
    make_top(m2);
    m3 = m4 = 0;
  } else if (m3 != 0xff) {
    make_top(m3);
    m4 = 0;
  } else if (m4 != 0xff) {
    make_top(m4);
  }

  b1 &= m1;
  b2 &= m2;
  b3 &= m3;
  b4 &= m4;

  printf("%d.%d.%d.%d\n", b1, b2, b3, b4);
  printf("%d.%d.%d.%d\n", m1, m2, m3, m4);
  return 0;
}
