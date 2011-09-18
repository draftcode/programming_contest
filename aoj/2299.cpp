#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int M, N;
char field[500][500];

void find(int x, int y, P *a) {
  int dx[] = {0, 1, 0, -1};
  int dy[] = {1, 0, -1, 0};
  
  rep (i, 4) {
    int k = 1;
    for (;;) {
      if (x+k*dx[i] < 0 || x+k*dx[i] >= N || y+k*dy[i] < 0 || y+k*dy[i] >= M) {
        a[i] = P(-1, -1);
        break;
      } else if (field[y+k*dy[i]][x+k*dx[i]] != '.') {
        a[i] = P(x+k*dx[i], y+k*dy[i]);
        break;
      } else {
        k++;
      }
    }
  }
}

bool check_and_fill(P a, P b) {
  if (a == P(-1, -1) || b == P(-1, -1)) {
    return false;
  } else if (field[a.second][a.first] == '.') {
    return false;
  } else if (field[a.second][a.first] != field[b.second][b.first]) {
    return false;
  } else {
    field[a.second][a.first] = '.';
    field[b.second][b.first] = '.';
    return true;
  }
}

int main(void) {
  scanf("%d%d", &M, &N);
  vector<P> v;
  rep (y, M) {
    scanf("%s", field[y]);
    rep (x, N) {
      if (field[y][x] == '.'){
        v.push_back(P(x,y));
      }
    }
  }
  
  int point = 0;
  bool changed = true;
  while (changed) {
    changed = false;
    vector<P> next_v;
    each (pp, v) {
      P p = *pp;
      P a[4];
      find(p.first, p.second, a);
      if (a[0] != P(-1, -1) || a[1] != P(-1, -1) || a[2] != P(-1, -1) || a[3] != P(-1, -1)) {
        next_v.push_back(p);
      }
      if (check_and_fill(a[0], a[1])) { next_v.push_back(a[0]); next_v.push_back(a[1]); changed = true; point += 2; }
      if (check_and_fill(a[0], a[2])) { next_v.push_back(a[0]); next_v.push_back(a[2]); changed = true; point += 2; }
      if (check_and_fill(a[0], a[3])) { next_v.push_back(a[0]); next_v.push_back(a[3]); changed = true; point += 2; }
      if (check_and_fill(a[1], a[2])) { next_v.push_back(a[1]); next_v.push_back(a[2]); changed = true; point += 2; }
      if (check_and_fill(a[1], a[3])) { next_v.push_back(a[1]); next_v.push_back(a[3]); changed = true; point += 2; }
      if (check_and_fill(a[2], a[3])) { next_v.push_back(a[2]); next_v.push_back(a[3]); changed = true; point += 2; }
    }
    v = next_v;
  }
  cout << point << endl;
  
  return 0;
}

