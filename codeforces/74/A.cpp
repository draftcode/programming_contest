#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cfloat>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int main(void) {
  ios::sync_with_stdio(false);
  int n; cin >> n;

  string top_name;
  int top_score = INT_MIN;
  rep (_, n) {
    string name; int score = 0;
    int plus, minus, a, b, c, d, e;
    cin >> name >> plus >> minus >> a >> b >> c >> d >> e;
    score += plus * 100;
    score -= minus * 50;
    score += a + b + c + d + e;

    if (score > top_score) {
      top_name = name;
      top_score = score;
    }
  }
  cout << top_name << endl;
  return 0;
}
