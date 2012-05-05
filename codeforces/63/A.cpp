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
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int main(void) {
  ios::sync_with_stdio(false);
  int n; cin >> n;

  vector<string> captain;
  vector<string> man;
  vector<string> woman;
  vector<string> rat;

  rep (_, n) {
    string name, position;
    cin >> name >> position;
    if (position == "captain") {
      captain.push_back(name);
    } else if (position == "man") {
      man.push_back(name);
    } else if (position == "woman" || position == "child") {
      woman.push_back(name);
    } else if (position == "rat") {
      rat.push_back(name);
    }
  }

  each (it, rat) cout << *it << endl;
  each (it, woman) cout << *it << endl;
  each (it, man) cout << *it << endl;
  each (it, captain) cout << *it << endl;
  return 0;
}
