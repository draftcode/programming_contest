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

int board_length, board_weight, packages_num;
double board_left_torque, board_right_torque;

vector<P> packages;
vector<P> answer;
bool visited[1<<20];
bool memo[1<<20];

bool check(int state) {
  double left_torque = board_left_torque, right_torque = board_right_torque;
  for (int i = 0; i < packages_num; i++) {
    if ((state & (1 << i)) == 0) {
      right_torque += (packages[i].first-1.5)*packages[i].second;
      left_torque += (packages[i].first+1.5)*packages[i].second;
    }
  }
  return (left_torque >= 0 && right_torque <= 0);
}

bool rep(int state) {
  if (state+1 == (1 << packages_num)) return true;
  if (visited[state]) return memo[state];

  visited[state] = true;
  for (int i = 0; i < packages_num; i++) {
    if ((state & (1 << i)) == 0) {
      int next_state = state | (1 << i);
      if (check(next_state)) {
        bool ret = rep(next_state);
        if (ret) {
          answer.push_back(packages[i]);
          memo[state] = true;
          return true;
        }
      }
    }
  }
  memo[state] = false;
  return false;
}

int main(void) {
  int T = 1;
  for (;;) {
    scanf("%d%d%d", &board_length, &board_weight, &packages_num);
    if (board_length == 0) break;

    fill_n(visited, 1<<packages_num, false);
    packages.resize(packages_num);
    answer.clear();

    board_left_torque =
      0.5*pow(board_length/2.0+1.5, 2)*(board_weight/(board_length/2.0+1.5))
    - 0.5*pow(board_length/2.0-1.5, 2)*(board_weight/(board_length/2.0-1.5));
    board_right_torque = -board_left_torque;

    for (int i = 0; i < packages_num; i++) {
      int pos, weight;
      scanf("%d%d", &pos, &weight);
      packages[i] = P(pos, weight);
    }

    printf("Case %d:\n", T);
    if (check(0) && rep(0)) {
      for (int i = packages_num-1; i >= 0; i--) {
        printf("%d %d\n", answer[i].first, answer[i].second);
      }
    } else {
      printf("Impossible\n");
    }
    T++;
  }
  return 0;
}
