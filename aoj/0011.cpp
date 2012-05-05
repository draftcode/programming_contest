#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <vector>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int v[31];

int main(void) {
  ios::sync_with_stdio(false);
  int w, n;
  cin >> w >> n;
  rep (i, w) v[i+1] = i+1;
  
  rep (i, n) {
    char c;
    int a, b;
    cin >> a >> c >> b;
    swap(v[a], v[b]);
  }
  
  rep (i, w) cout << v[i+1] << endl;
  return 0;
}
