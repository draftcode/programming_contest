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

int N, M;
int hol_min[10000];
int ver_min[10000];
int diag1_min[25000];
int diag2_min[25000];

int hol_max[10000];
int ver_max[10000];
int diag1_max[25000];
int diag2_max[25000];

int hol_count[10000];
int ver_count[10000];
int diag1_count[25000];
int diag2_count[25000];
vector<P> queens;

int check(int count[], int mi[], int mx[], int i, int check) {
  if (count[i] == 1) {
    return 0;
  } else if (count[i] == 2) {
    return 1;
  } else {
    if (mi[i] == check || mx[i] == check) return 1;
    return 2;
  }
}

int ans[9];

int main(void) {
  ios::sync_with_stdio(false);
  fill_n(hol_min, 10000, INT_MAX);
  fill_n(ver_min, 10000, INT_MAX);
  fill_n(diag1_min, 25000, INT_MAX);
  fill_n(diag2_min, 25000, INT_MAX);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int y, x; cin >> y >> x; y--; x--;
    queens.push_back(P(y, x));
    hol_count[y]++;
    ver_count[x]++;
    diag1_count[x+y]++;
    diag2_count[(N-x-1)+y]++;

    hol_min[y] = min(hol_min[y], x);
    ver_min[x] = min(ver_min[x], y);
    diag1_min[x+y] = min(diag1_min[x+y], x);
    diag2_min[(N-x-1)+y] = min(diag2_min[(N-x-1)+y], x);

    hol_max[y] = max(hol_max[y], x);
    ver_max[x] = max(ver_max[x], y);
    diag1_max[x+y] = max(diag1_max[x+y], x);
    diag2_max[(N-x-1)+y] = max(diag2_max[(N-x-1)+y], x);
  }

  for (int i = 0; i < M; i++) {
    P p = queens[i];
    int y = p.first, x = p.second;
    int a = 0;
    a += check(hol_count   , hol_min   , hol_max   , y         , x);
    a += check(ver_count   , ver_min   , ver_max   , x         , y);
    a += check(diag1_count , diag1_min , diag1_max , x+y       , x);
    a += check(diag2_count , diag2_min , diag2_max , (N-x-1)+y , x);
    ans[a]++;
  }

  for (int i = 0; i < 9; i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
  return 0;
}
