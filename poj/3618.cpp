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

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int T, N;

int compare(int x, int y) {
  return abs(x) < abs(y);
}

int main(void) {
  vector<int> v;
  cin >> T >> N;
  rep (i, N) {
    int t;
    cin >> t;
    v.push_back(t);
  }
  sort(v.begin(), v.end(), compare);
  
  int now = 0;
  int current_pos = 0;
  int i = 0;
  while (now <= T && i < N) {
    now += abs(current_pos - v[i]);
    current_pos = v[i];
    i++;
  }
  
  if (now > T) i--;
  cout << i << endl;
  return 0;
}
