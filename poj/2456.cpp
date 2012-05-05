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
int v[100001];

bool C(int d) {
  int last = 0;
  for (int i = 1; i < M; i++) {
    int crt = last + 1;
    while (crt < N && v[crt] - v[last] < d) {
      crt++;
    }
    if (crt == N) return false;
    last = crt;
  }

  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  sort(v, v+N);

  int lb = v[0], ub = v[N-1];

  while (ub > lb + 1) {
    int mid = (lb + ub) / 2;
    if (C(mid)) {
      lb = mid;
    } else {
      ub = mid;
    }
  }

  cout << lb << endl;

  return 0;
}
