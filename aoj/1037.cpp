#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <set>
#include <vector>

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
class ParseError {};

int N;
string s;
char leafs[10];

vector<char> parse(State &begin) {
  while (*begin == ' ') begin++;
  if (*begin == '(') {
    begin++;
    vector<char> left = parse(begin);
    vector<char> right = parse(begin);
    while (*begin == ' ') begin++;
    if (*begin == ')') {
      begin++;
      vector<char> ret;
      for (vector<char>::const_iterator left_it = left.begin(); left_it != left.end(); left_it++) {
        for (vector<char>::const_iterator right_it = right.begin(); right_it != right.end(); right_it++) {
          ret.push_back((*left_it) & (*right_it));
          ret.push_back((*left_it) | (*right_it));
          ret.push_back((*left_it) ^ (*right_it));
        }
      }
      return ret;
    } else {
      throw ParseError();
    }
  } else if (isdigit(*begin)) {
    int idx = *begin - '1';
    vector<char> ret;
    ret.push_back(leafs[idx]);
    begin++;
    return ret;
  } else {
    throw ParseError();
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  while (!cin.eof()) {
    getline(cin, s);
    if (s == "END") break;
    cin >> N;
    for (int n = 0; n < N; n++) {
      int number = 0;
      int temp;
      for (int i = 0; i < 4; i++) {
        int k = 1 << i;
        cin >> temp;
        if (temp == 1) {
          number |= k;
        }
      }
      leafs[n] = number;
    }

    State begin = s.begin();
    vector<char> s = parse(begin);

    int ans = 0;
    for (vector<char>::const_iterator it = s.begin(); it != s.end(); it++) {
      if (*it == 1 + 2 + 4 + 8) {
        ans++;
      }
    }
    cout << ans << endl;

    cin.ignore(); cin.peek();
  }
  return 0;
}
