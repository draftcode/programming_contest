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

int H, W, P;
string field[10];
bool used[10][10];
vector<string> words;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool init_rep(int w);
bool rep(int x, int y, int w, int pos) {
  used[y][x] = true;

  if (words[w].size() == pos) {
    bool ret = init_rep(w+1);
    if (ret) return ret;
  } else {
    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      if (0 <= nx && nx < W && 0 <= ny && ny < H) {
        if (!used[ny][nx] && field[ny][nx] == words[w][pos]) {
          bool ret = rep(nx, ny, w, pos+1);
          if (ret) return ret;
        }
      }
    }
  }

  used[y][x] = false;
  return false;
}

bool init_rep(int w) {
  if (w == words.size()) return true;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (!used[y][x] && field[y][x] == words[w][0]) {
        bool ret = rep(x, y, w, 1);
        if (ret) return ret;
      }
    }
  }
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin >> H >> W >> P;
  words.resize(P);
  for (int i = 0; i < H; i++) cin >> field[i];
  for (int i = 0; i < P; i++) cin >> words[i];
  fill(used[0], used[10], false);

  init_rep(0);
  string ans;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (!used[y][x]) ans.push_back(field[y][x]);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
