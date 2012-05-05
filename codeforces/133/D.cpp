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

int H, W, N;

string field[50];

// int dx[] = {1, 0, -1, 0};
// int dy[] = {0, -1, 0, 1};
P dp_dirs[] = {P(1,0), P(0,1), P(-1,0), P(0,-1)};
P cp_false_dirs[] = {P(0,-1), P(1,0), P(0,1), P(-1,0)};
P cp_true_dirs[] = {P(0,1), P(-1,0), P(0,-1), P(1,0)};

P operator +(const P a, const P b) {
  return P(a.first+b.first, a.second+b.second);
}

void operator +=(P &a, const P b) {
  a.first += b.first;
  a.second += b.second;
}

void operator -=(P &a, const P b) {
  a.first -= b.first;
  a.second -= b.second;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin >> H >> N;
  for (int i = 0; i < H; i++) {
    cin >> field[i];
  }
  W = field[0].size();

  P bp(0, 0);
  int dp = 0;
  bool cp = false;
  for (int i = 0; i < N; i++) {
    P dp_dir = dp_dirs[dp];
    P cp_dir;
    if (cp)
      cp_dir = cp_true_dirs[dp];
    else
      cp_dir = cp_false_dirs[dp];

    P edge_bp = bp + dp_dir;
    while (edge_bp.first != W && edge_bp.first != -1
       && edge_bp.second != H && edge_bp.second != -1)
    {
      if (field[edge_bp.second][edge_bp.first] != field[bp.second][bp.first])
        break;
      edge_bp += dp_dir;
    }
    edge_bp -= dp_dir;

    edge_bp += cp_dir;
    while (edge_bp.first != W && edge_bp.first != -1
       && edge_bp.second != H && edge_bp.second != -1)
    {
      if (field[edge_bp.second][edge_bp.first] != field[bp.second][bp.first])
        break;
      edge_bp += cp_dir;
    }
    edge_bp -= cp_dir;

    P next_block = edge_bp + dp_dir;
    if (next_block.first == W || next_block.second == H
     || next_block.first == -1 || next_block.second == -1
     || field[next_block.second][next_block.first] == '0')
    {
      if (!cp) {
        cp = true;
      } else {
        cp = false;
        dp = (dp+1) % 4;
      }
    } else {
      bp = next_block;
    }
  }
  cout << field[bp.second][bp.first] << endl;
  return 0;
}
