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
#include <cctype>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

string convert_col(int col) {
  string ret;
  while (col != 0) {
    char c = 'A' + (col % 26) - 1;
    col /= 26;
    if (c == '@') {
      c = 'Z';
      col--;
    }
    ret.push_back(c);
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  rep (i, n) {
    string s;
    cin >> s;
    int cpos = s.find_first_of('C');
    if (cpos > 0 && isdigit(s[cpos-1])) {
      int row = 0, col = 0;
      int pos = 1;
      while (s[pos] != 'C') {
        row = row * 10 + s[pos] - '0';
        pos++;
      }
      pos++;
      while (pos != s.size()) {
        col = col * 10 + s[pos] - '0';
        pos++;
      }
      cout << convert_col(col) << row << endl;
    } else {
      int row = 0, col = 0;
      int pos = 0;
      while (!isdigit(s[pos])) {
        col = col * 26 + s[pos] - 'A' + 1;
        pos++;
      }
      while (pos != s.size()) {
        row = row * 10 + s[pos] - '0';
        pos++;
      }
      cout << 'R' << row << 'C' << col << endl;
    }
  }
  return 0;
}
