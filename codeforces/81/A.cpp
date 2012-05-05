#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <list>
#include <vector>

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
  string s;
  cin >> s;
  list<char> l(s.begin(), s.end());

  list<char>::iterator prev = l.begin();
  list<char>::iterator curr = l.begin(); curr++;
  while (curr != l.end()) {
    if (*prev == *curr) {
      curr = l.erase(prev, ++curr);
      prev = curr;
      prev--;
    } else {
      prev++;
      curr++;
    }
  }

  each (it, l) {
    cout << *it;
  }
  cout << endl;

  return 0;
}
