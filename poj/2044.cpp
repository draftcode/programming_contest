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

int N;
vector<vector<int> >V;

const int table[][5] = {
  {0, 1, 2, 3, 6},
  {1, 0, 2, 4, 7},
  {2, 0, 1, 5, 8},
  {3, 0, 6, 4, 5},
  {4, 1, 3, 5, 7},
  {5, 2, 3, 4, 8},
  {6, 0, 3, 7, 8},
  {7, 1, 4, 6, 8},
  {8, 2, 5, 6, 7},
};

bool dfs(int d, int days[], int pos) {
  if (d == N) return true;

  if (V[d][pos] == 1) return false;
  if (pos != 0 && days[0] == 6) return false;
  if (pos != 2 && days[1] == 6) return false;
  if (pos != 6 && days[2] == 6) return false;
  if (pos != 8 && days[3] == 6) return false;

  int saved = days[pos];
  for (int i = 0; i < 4; i++) {
    days[i]++;
  }
  if (pos == 0) days[0] = 0;
  if (pos == 2) days[1] = 0;
  if (pos == 6) days[2] = 0;
  if (pos == 8) days[3] = 0;

  for (int i = 0; i < 5; i++) {
    if (dfs(d+1, days, table[pos][i])) {
      return true;
    }
  }

  for (int i = 0; i < 4; i++) {
    days[i]--;
  }
  days[pos] = saved;
  return false;
}

int main(void) {
  for (;;) {
    scanf("%d", &N); if (N == 0) break;

    V.resize(N, vector<int>(9, 0));
    for (int j = 0; j < N; j++) {
      int v[16];
      for (int i = 0; i < 16; i++)
        scanf("%d", v+i);
      V[j][0] = v[0] | v[1] | v[4] | v[5];
      V[j][1] = v[1] | v[2] | v[5] | v[6];
      V[j][2] = v[2] | v[3] | v[6] | v[7];

      V[j][3] = v[4] | v[5] | v[8] | v[9];
      V[j][4] = v[5] | v[6] | v[9] | v[10];
      V[j][5] = v[6] | v[7] | v[10] | v[11];

      V[j][6] = v[8] | v[9] | v[12] | v[13];
      V[j][7] = v[9] | v[10] | v[13] | v[14];
      V[j][8] = v[10] | v[11] | v[14] | v[15];
    }

    int initv[] = {0, 0, 0, 0};
    if (dfs(0, initv, 4)) {
      printf("1\n");
    } else {
      printf("0\n");
    }
  }
  return 0;
}

