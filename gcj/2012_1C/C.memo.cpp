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
ll An[100];
ll Bn[100];
int At[100];
int Bt[100];

ll memo[100][100];

ll f(int a, int b) {
  if (a == N || b == M) return 0;

  ll &ans = memo[a][b];
  if (ans != -1) {
    return ans;
  } else if (At[a] != Bt[b]) {
    return ans = max(f(a+1, b), f(a, b+1));
  } else {
    ll sum_a = 0;
    for (int n = a; n < N; n++) {
      if (At[a] == At[n]) {
        sum_a += An[n];

        ll sum_b = 0;
        for (int m = b; m < M; m++) {
          if (At[a] == Bt[m]) {
            sum_b += Bn[m];
            ans = max(ans, f(n+1, m+1) + min(sum_a, sum_b));
          }
        }
      }
    }

    return ans;
  }
}

void calc(void) {
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> An[i] >> At[i];
  for (int i = 0; i < M; i++) cin >> Bn[i] >> Bt[i];

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      memo[i][j] = -1;

  cout << f(0, 0);
}

int main(void) {
  ios::sync_with_stdio(false);
  int T; cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    calc();
    cout << endl;
  }
  return 0;
}
