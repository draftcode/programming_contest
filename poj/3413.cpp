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

int N, D;
int a[10];
int b[10];
int s[10];
double dp[1<<10];
int parent[1<<10];

int main(void) {
  scanf("%d%d", &N, &D);
  for (int i = 0; i < N; i++) {
    scanf("%d%d%d", a+i, b+i, s+i);
  }
  dp[0] = 1.0;
  set<int> prev;
  prev.insert(0);
  for (int i = 0; i < N; i++) {
    set<int> next;
    for (set<int>::iterator it = prev.begin(); it != prev.end(); it++) {
      int current_solved = *it;
      int current_xp = D;
      for (int k = 0; k < N; k++) {
        if (current_solved & (1 << k)) {
          current_xp += s[k];
        }
      }

      for (int stage = 0; stage < N; stage++) {
        if ((current_solved & (1 << stage)) == 0) {
          int next_solved = current_solved | (1 << stage);
          double next_dp = 0.0;
          if (current_xp < a[stage]) {
            next_dp = 0.0;
          } else if (current_xp >= b[stage]) {
            next_dp = dp[current_solved];
          } else {
            next_dp = dp[current_solved] * ((current_xp - a[stage])/((double)(b[stage] - a[stage])));
          }
          if (dp[next_solved] <= next_dp) {
            dp[next_solved] = next_dp;
            parent[next_solved] = stage;
            next.insert(next_solved);
          }
        }
      }
    }
    prev = next;
  }
  printf("%.3f\n", dp[(1<<N)-1]);
  vector<int> solved;
  int curr = (1<<N)-1;
  while (curr) {
    int p = parent[curr];
    solved.push_back(p);
    curr = (curr ^ (1 << p));
  }
  printf("%d", solved[N-1]+1);
  for (int i = N-2; i >= 0; i--) {
    printf(" %d", solved[i]+1);
  }
  putchar('\n');
  return 0;
}

