#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>
#include <map>
#include <set>

#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

const ull ull_max = 18446744073709551615ULL;
const ll ll_min = -9223372036854775808ULL;

int K;
string s;
ll num;
bool bits[64];

bool f(int i, bool neg, ull left, ull pos_window, ull neg_window) {
  // cerr << neg << ' ' << left << ' ' << pos_window << endl;
  if (left == 0) return true;
  if (i == K) return true;
  if (!neg && left > pos_window) return false;
  if (neg && left > neg_window) return false;

  ull t = (ull)1 << (K - i - 1);
  if (s[i] == 'p') {
    pos_window -= t;
    if (f(i+1, neg || (left < t), neg ? left + t : (left > t ? left-t : t-left), pos_window, neg_window)) {
      bits[i] = true;
    } else if (f(i+1, neg, left, pos_window, neg_window)) {
      bits[i] = false;
    } else {
      return false;
    }
  } else {
    neg_window -= t;
    if (f(i+1, neg && (left > t), !neg ? left + t : (left > t ? left-t : t-left), pos_window, neg_window)) {
      bits[i] = true;
    } else if (f(i+1, neg, left, pos_window, neg_window)) {
      bits[i] = false;
    } else {
      return false;
    }
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  int T; cin >> T;
  for (int _ = 0; _ < T; _++) {
    cin >> K;
    cin >> s;
    cin >> num;
    fill_n(bits, K, 0);

    ull pos_window = 0, neg_window = 0;
    ull t = 1;
    for (int i = K-1; i > 0; i--) {
      if (s[i] == 'p') {
        pos_window += t;
      } else {
        neg_window += t;
      }
      t <<= 1;
    }

    bool ans = false;
    if (f(1, num < 0, num < 0 ? -num : num, pos_window, neg_window)) {
      ans = true;
    } else {
      if (s[0] == 'p' && ull_max - num < t) {
      } else if (s[0] == 'n' && ll_min + t > num) {
      } else {
        if (s[0] == 'p') {
          num += t;
        } else {
          num -= t;
        }

        if (f(1, num < 0, num < 0 ? -num : num, pos_window, neg_window)) {
          bits[0] = true;
          ans = true;
        }
      }
    }

    if (ans) {
      for (int i = 0; i < K; i++) {
        cout << (int)bits[i];
      }
      cout << endl;
    } else {
      cout << "Impossible" << endl;
    }
  }
  return 0;
}

