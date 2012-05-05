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
typedef pair<int, int> P;

void parse(string &s, int &a, int &b, int &c) {
  a = b = c = 0;
  int i = 0;

  int exp = 1;
  while (s[i] != '+') {
    a += exp * (s[i] - '0');
    exp *= 10;
    i++;
  }
  i++;

  exp = 1;
  while (s[i] != '=') {
    b += exp * (s[i] - '0');
    exp *= 10;
    i++;
  }
  i++;

  exp = 1;
  while (s[i] != '\0') {
    c += exp * (s[i] - '0');
    exp *= 10;
    i++;
  }
  i++;
}

int main(void) {
  ios::sync_with_stdio(false);
  while (true) {
    string s;
    getline(cin, s);
    if (s == "") break;

    int a, b, c;
    parse(s, a, b, c);
    if (a + b == c) {
      cout << "True" << endl;
    } else {
      cout << "False" << endl;
    }
  }
  return 0;
}
