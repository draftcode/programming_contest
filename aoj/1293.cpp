#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

typedef string::const_iterator State;
class ParseError {};

ostream& operator<<(ostream &os, const vector<int> v) {
  bool output = false;
  for (int i = 9; i >= 0; i--) {
    if (v[i] != 0) {
      if (v[i] > 0 && output) os << '+';
      if (v[i] < 0) os << '-';
      if (abs(v[i]) != 1 || i == 0) os << abs(v[i]);
      if (i > 0) os << 'x';
      if (i > 1) os << '^' << i;
      output = true;
    }
  }

  if (!output) os << 0;
  return os;
}

vector<int> multiply(vector<int> a, vector<int> b) {
  vector<int> ret(10, 0);

  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      if (i + j < 10) ret[i+j] += a[i] * b[j];

  return ret;
}

vector<int> expr(State &begin);
vector<int> term(State &begin);
vector<int> factor(State &begin);

vector<int> expr(State &begin) {
  vector<int> ret = term(begin);

  for (;;) {
    if (*begin == '+') {
      begin++;
      vector<int> right = term(begin);
      for (int i = 0; i < 10; i++) ret[i] += right[i];
    } else if (*begin == '-') {
      begin++;
      vector<int> right = term(begin);
      for (int i = 0; i < 10; i++) ret[i] -= right[i];
    } else {
      break;
    }
  }

  return ret;
}

vector<int> term(State &begin) {
  vector<int> ret = factor(begin);

  for (;;) {
    if (*begin == '(') {
      vector<int> right = factor(begin);
      ret = multiply(ret, right);
    } else {
      break;
    }
  }

  return ret;
}

vector<int> factor(State &begin) {
  bool minus = false;
  if (*begin == '-') {
    begin++;
    minus = true;
  }

  int coeff = 1;
  if (isdigit(*begin)) {
    coeff = 0;
    while (isdigit(*begin)) {
      coeff *= 10;
      coeff += *begin - '0';
      begin++;
    }
  }

  if (minus) coeff *= -1;

  vector<int> base(10, 0);
  if (*begin == '(') {
    begin++;
    base = expr(begin);
    begin++;
  } else if (*begin == 'x') {
    begin++;
    base[1] = 1;
  } else {
    base[0] = 1;
  }

  int degree = 1;
  if (*begin == '^') {
    begin++;
    degree = 0;
    while (isdigit(*begin)) {
      degree *= 10;
      degree += *begin - '0';
      begin++;
    }
  }

  vector<int> ret = base;
  for (int i = 1; i < degree; i++) ret = multiply(ret, base);
  for (int i = 0; i < 10; i++) ret[i] *= coeff;

  return ret;
}

bool compare(const vector<int> &a, const vector<int> &b) {
  for (int i = 9; i >= 0; i--) {
    if (a[i] == 0 && b[i] != 0) {
      return false;
    } else if (a[i] != 0 && b[i] == 0) {
      return true;
    } else if (a[i] != b[i]) {
      return a[i] > b[i];
    }
  }
  return true;
}

bool iszero(const vector<int> &a) {
  for (int i = 9; i >= 0; i--) if (a[i] != 0) return false;
  return true;
}

int gcd(int a, int b) {
  if (b > a) swap(a,b);

  while (b != 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}

void coeff_gcd(vector<int> &a) {
  int g = 0;
  for (int i = 0; i < 10; i++) {
    g = gcd(g, a[i]);
  }
  for (int i = 0; i < 10; i++) {
    a[i] /= g;
  }
}

vector<int> gcm(vector<int> a, vector<int> b) {
  if (compare(b, a)) swap(a, b);

  while (!iszero(b)) {
    int k;
    for (k = 9; k >= 0; k--) if (b[k] != 0) break;
    coeff_gcd(b);
    while (compare(a, b)) {
      coeff_gcd(a);
      int i;
      for (i = 9; i >= 0; i--) if (a[i] != 0) break;

      int first_a = a[i];
      for (int l = 9; l >= 0; l--) a[l] *= b[k];
      for (int j = 0; i-j >= 0 && k-j >= 0; j++) {
        a[i-j] -= b[k-j]*first_a;
      }
    }
    swap(a, b);
  }

  coeff_gcd(a);
  return a;
}

int main(void) {
  ios::sync_with_stdio(false);
  for (;;) {
    string s, t;
    cin >> s >> t;
    if (s[0] == '.') break;

    State begin1 = s.begin();
    vector<int> parsed1 = expr(begin1);
    State begin2 = t.begin();
    vector<int> parsed2 = expr(begin2);

    vector<int> ans = gcm(parsed1, parsed2);

    int i;
    for (i = 9; i >= 0; i--) if (ans[i] != 0) break;
    if (ans[i] < 0) {
      for (i = 9; i >= 0; i--) ans[i] *= -1;
    }

    cout << ans << endl;
  }
  return 0;
}
