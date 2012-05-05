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

int N;
int total_v[15];
int total_h[15];
int solved_v[15];
int solved_h[15];
int field[15][15];

void solve_total(int *total, int *solved, int mx) {
  int m = INT_MAX;
  int temp1[15];
  int temp2[15];
  for (int start = 0; start < N; start++) {
    int zero_count = 0;

    for (int i = 0; i < N; i++) {
      temp1[i] = 0;
      temp2[i] = total[i];
    }

    int i = start;
    for (int _ = 0; _ < mx + 7*4; _++) {
      if (zero_count == N) break;
      if (temp2[i] != 0) {
        temp1[(i+1)%N] += temp2[i];
        temp2[(i+1)%N] = temp2[(i+1)%N] - temp2[i];
        if (temp2[(i+1)%N] < 0) temp2[(i+1)%N] += 7;
        temp2[(i+2)%N] = temp2[(i+2)%N] - temp2[i];
        if (temp2[(i+2)%N] < 0) temp2[(i+2)%N] += 7;
        temp2[i] = 0;
        zero_count = 1;
      } else {
        zero_count++;
      }
      i = (i + 1) % N;
    }

    if (zero_count == N) {
      int count = 0;
      for (int i = 0; i < N; i++) {
        temp1[i] %= 7;
        count += temp1[i];
      }
      if (count < m) {
        m = count;
        for (int i = 0; i < N; i++) {
          solved[i] = temp1[i];
        }
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  while (cin >> N, N != 0) {
    fill_n(total_v, sizeof(total_v)/sizeof(int), 0);
    fill_n(total_h, sizeof(total_h)/sizeof(int), 0);
    fill_n(solved_v, sizeof(solved_v)/sizeof(int), 0);
    fill_n(solved_h, sizeof(solved_h)/sizeof(int), 0);
    fill_n(field[0], sizeof(field)/sizeof(int), 0);
    int whole_total = 0;
    for (int y = 0; y < N; y++) {
      for (int x = 0; x < N; x++) {
        cin >> field[y][x];
        total_v[y] += field[y][x];
        total_h[x] += field[y][x];
      }
      while (total_v[y] % 3 != 0) {
        total_v[y] += 7;
      }

      total_v[y] /= 3;
      whole_total += total_v[y];
    }

    if (whole_total % 3 != 0) {
      cout << -1 << endl;
      continue;
    }

    for (int x = 0; x < N; x++) {
      while (total_h[x] % 3 != 0) {
        total_h[x] += 7;
      }
      total_h[x] /= 3;
    }

    solve_total(total_v, solved_v, whole_total / 3);
    solve_total(total_h, solved_h, whole_total / 3);
    for (int i = 0; i < N; i++) {
      cout << solved_v[i] << ' ' << solved_h[i] << endl;
    }
    cout << endl;
  }
  return 0;
}
