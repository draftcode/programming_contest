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
int token[20000];
bool used[20000];
int visit[10000];

int check_x(int x, int region) {
  if (x > 0 && (region == 1 || region == 4)) {
    return true;
  } else if (x < 0 && (region == 2 || region == 3)) {
    return true;
  }
  return false;
}

int check_y(int y, int region) {
  if (y > 0 && (region == 1 || region == 2)) {
    return true;
  } else if (y < 0 && (region == 3 || region == 4)) {
    return true;
  }
  return false;
}

int sign[] = {-1, 1};

vector<P> rep(int k, int x, int y) {
  vector<P> ret;

  for (int dxi = 0; dxi < 2*N; dxi++)
    if (!used[dxi])
      for (int signx = 0; signx < 2; signx++) {
        int nx = x + token[dxi] * sign[signx];
        if (check_x(nx, visit[k])) {
          for (int dyi = dxi+1; dyi < 2*N; dyi++)
            if (!used[dyi])
              for (int signy = 0; signy < 2; signy++) {
                int ny = y + token[dyi] * sign[signy];
                if (check_y(ny, visit[k])) {
                  if (k+1 == N) {
                    ret.push_back(
                        P(token[dxi]*sign[signx],
                          token[dyi]*sign[signy]));
                    return ret;
                  } else {
                    used[dxi] = true;
                    used[dyi] = true;
                    ret = rep(k+1, nx, ny);
                    used[dxi] = false;
                    used[dyi] = false;
                    if (ret.size() > 0) {
                      ret.push_back(
                          P(token[dxi]*sign[signx],
                            token[dyi]*sign[signy]));
                      return ret;
                    }
                  }
                }
              }
        }
      }

  return ret;
}

int main(void) {
  scanf("%d", &N);
  for (int i = 0; i < 2*N; i++) {
    scanf("%d", token+i);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", visit+i);
  }
  sort(token, token+N);

  vector<P> ans = rep(0, 0, 0);
  if (ans.size() != 0) {
    for (int i = N-1; i >= 0; i--) {
      P p = ans[i];
      if (p.first >= 0) {
        putchar('+');
      }
      printf("%d ", p.first);
      if (p.second >= 0) {
        putchar('+');
      }
      printf("%d\n", p.second);
    }
  } else {
    printf("0\n");
  }
  return 0;
}
