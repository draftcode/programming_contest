#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>
#include <map>

#include <cctype>
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
typedef vector<vector<int> > matrix;
class ParseError {};
const int mod = 1 << 15;

matrix expr(State &begin);
matrix term(State &begin);
matrix factor(State &begin);
matrix primary(State &begin);
matrix mat(State &begin);
matrix row(State &begin);

void consume(State &s, char c) {
  if (*s == c) s++; else {
    cerr << "Expect " << c << " but got " << *s << endl;
    cerr << "Rest string is ";
    while (*s != '\0') {
      cerr << *s++;
    }
    cerr << endl;
    throw ParseError();
  }
}

map<char, matrix> m;
matrix expr(State &begin) {
  matrix ret = term(begin);
  for (;;) {
    if (*begin == '+') {
      consume(begin, '+');
      matrix right = term(begin);
      for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
          ret[i][j] += right[i][j];
          if (ret[i][j] < 0) ret[i][j] += mod;
          ret[i][j] %= mod;
        }
      }
    } else if (*begin == '-') {
      consume(begin, '-');
      matrix right = term(begin);
      for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
          ret[i][j] -= right[i][j];
          if (ret[i][j] < 0) ret[i][j] += mod;
          ret[i][j] %= mod;
        }
      }
    } else {
      break;
    }
  }
  return ret;
}

matrix term(State &begin) {
  matrix ret = factor(begin);
  for (;;) {
    if (*begin == '*') {
      consume(begin, '*');
      matrix right = term(begin);
      if (ret.size() == 1 && ret[0].size() == 1) swap(ret, right);
      if (right.size() == 1 && right[0].size() == 1) {
        int k = right[0][0];
        for (int i = 0; i < ret.size(); i++) {
          for (int j = 0; j < ret[i].size(); j++) {
            ret[i][j] *= k;
            if (ret[i][j] < 0) ret[i][j] += mod;
            ret[i][j] %= mod;
          }
        }
      } else {
        matrix new_ret;
        for (int i = 0; i < ret.size(); i++) {
          vector<int> v;
          for (int j = 0; j < right[0].size(); j++) {

            int n = 0;
            for (int k = 0; k < ret[i].size(); k++) {
              n += ret[i][k] * right[k][j];
              if (n < 0) n += mod;
              n %= mod;
            }
            v.push_back(n);

          }
          new_ret.push_back(v);
        }
        ret = new_ret;
      }
    } else {
      break;
    }
  }

  return ret;
}

matrix factor(State &begin) {
  if (*begin == '-') {
    consume(begin, '-');
    matrix ret = factor(begin);
    for (int i = 0; i < ret.size(); i++) {
      for (int j = 0; j < ret[i].size(); j++) {
        ret[i][j] *= -1;
        if (ret[i][j] < 0) ret[i][j] += mod;
        ret[i][j] %= mod;
      }
    }
    return ret;
  } else {
    return primary(begin);
  }
}

matrix primary(State &begin) {
  matrix ret;
  if (isdigit(*begin)) {
    int num = 0;
    while (isdigit(*begin)) {
      num *= 10;
      num += *begin - '0';
      begin++;
    }
    vector<int> v; v.push_back(num);
    ret.push_back(v);
  } else if ('A' <= *begin && *begin <= 'Z') {
    ret = m[*begin];
    begin++;
  } else if (*begin == '[') {
    ret = mat(begin);
  } else if (*begin == '(') {
    consume(begin, '(');
    ret = expr(begin);
    consume(begin, ')');
  }

  for (;;) {
    if (*begin == '(') {
      consume(begin, '(');
      matrix y = expr(begin);
      consume(begin, ',');
      matrix x = expr(begin);
      consume(begin, ')');

      int vert = x[0].size(), hol = y[0].size();

      matrix new_ret;
      for (int i = 0; i < hol; i++) {
        vector<int> v;

        for (int j = 0; j < vert; j++) {
          v.push_back(ret[y[0][i]-1][x[0][j]-1]);
        }

        new_ret.push_back(v);
      }
      ret = new_ret;
    } else if (*begin == '\'') {
      consume(begin, '\'');
      int vert = ret[0].size(), hol = ret.size();

      matrix new_ret;
      for (int i = 0; i < vert; i++) {
        vector<int> v;

        for (int j = 0; j < hol; j++) {
          v.push_back(ret[j][i]);
        }

        new_ret.push_back(v);
      }
      ret = new_ret;
    } else {
      break;
    }
  }
  return ret;
}

matrix mat(State &begin) {
  consume(begin, '[');
  matrix ret = row(begin);
  for (;;) {
    if (*begin == ';') {
      consume(begin, ';');
      matrix next_row = row(begin);
      for (int i = 0; i < next_row.size(); i++) {
        ret.push_back(next_row[i]);
      }
    } else {
      break;
    }
  }
  consume(begin, ']');
  return ret;
}

matrix row(State &begin) {
  matrix ret = expr(begin);
  for (;;) {
    if (*begin == ' ') {
      consume(begin, ' ');
      matrix next_seq = expr(begin);
      for (int i = 0; i < next_seq.size(); i++) {
        for (int j = 0; j < next_seq[i].size(); j++) {
          ret[i].push_back(next_seq[i][j]);
        }
      }
    } else {
      break;
    }
  }
  return ret;
}

char assignment(State &begin) {
  char var = *begin;
  begin++;
  consume(begin, '=');
  matrix mat = expr(begin);
  consume(begin, '.');
  m[var] = mat;
  return var;
}

int main(void) {
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n, n != 0) {
    cin.ignore();
    m.clear();
    for (int i = 0; i < n; i++) {
      string s;
      getline(cin, s);
      State begin = s.begin();
      char var = assignment(begin);

      matrix ret = m[var];
      for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
          if (j != 0) cout << ' ';
          cout << ret[i][j];
        }
        cout << endl;
      }
    }
    cout << "-----" << endl;
  }
  return 0;
}

