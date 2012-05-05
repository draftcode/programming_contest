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

int N, T;
vector<int> v;
set<int> s[100][100];

int main(void) {
  scanf("%d%d", &N, &T);
  v.resize(N, 0);
  for (int i = 0; i < N; i++) {
    int t; scanf("%d", &t); v[i] = t;
    s[i][i].insert(t);
  }

  for (int width = 1; width <= N; width++) {
    for (int start = 0; start+width < N; start++) {
      int end = start+width;
      set<int> &se = s[start][end];
      for (int first_end = start; first_end < end; first_end++) {
        set<int> &first_set = s[start][first_end];
        set<int> &second_set = s[first_end+1][end];
        for (set<int>::iterator first = first_set.begin(); first != first_set.end(); first++) {
          for (set<int>::iterator second = second_set.begin(); second != second_set.end(); second++) {
            se.insert(*first - *second);
          }
        }
      }
    }
  }

  for (set<int>::iterator it = s[0][N-1].begin(); it != s[0][N-1].end(); it++) {
    cout << *it << endl;
  }

  return 0;
}
