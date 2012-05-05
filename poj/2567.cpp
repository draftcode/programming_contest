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

int cnt;
vector<int> v[50];
bool used[50];

void parse(string &s, int &i, int parent) {
  if (s[i] == '\0') return;

  if (s[i] == '(') {
    i++;
    int n = s[i++] - '0';
    if (isdigit(s[i])) {
      n = n*10 + s[i++] - '0';
    }
    while (isspace(s[i])) i++;
    cnt++;

    if (parent != -1) {
      v[parent].push_back(n-1);
      v[n-1].push_back(parent);
    }

    while (s[i] != ')') {
      parse(s, i, n-1);
      while (isspace(s[i])) i++;
    }
    i++;

  } else if (isdigit(s[i])) {
    int n = s[i++] - '0';
    if (isdigit(s[i])) {
      n = n*10 + s[i++] - '0';
    }
    while (isspace(s[i])) i++;
    cnt++;

    if (parent != -1) {
      v[parent].push_back(n-1);
      v[n-1].push_back(parent);
    }

  }
}

int main(void) {
  ios::sync_with_stdio(false);
  while (true) {
    {
      for (int i = 0; i < 50; i++) {
        used[i] = false;
        v[i].clear();
      }
      cnt = 0;
    }
    {
      string s;
      int i = 0;
      getline(cin, s);
      if (s == "") break;
      parse(s, i, -1);
    }

    for (int _ = 0; _ < cnt-1; _++) {

      int pos = INT_MAX, par = INT_MAX;
      for (int i = 0; i < 50; i++) {
        if (used[i] || v[i].size() == 0) continue;
        int ct = 0;
        int pr = 0;
        for (int j = 0; j < v[i].size(); j++) {
          if (!used[v[i][j]]) {
            ct++;
            pr = v[i][j];
          }
        }

        if (ct == 1 && pos > i) {
          pos = i;
          par = pr;
        }
      }
      cout << par + 1 << ' ';
      used[pos] = true;
    }
    cout << endl;
  }
  return 0;
}

