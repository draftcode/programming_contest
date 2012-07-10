#include <iostream>
#include <vector>
#include <map>

#include <cassert>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int find_frac(map<ll, int> &m, vector<P> &fracs, ll N) {
  if (m.find(N) != m.end()) {
    return m[N];
  }
  for (vector<P>::iterator it = fracs.begin(); it != fracs.end(); it++) {
    if (N % it->second == 0) {
      m[N] = it - fracs.begin();
      return it - fracs.begin();
    }
  }
  return 0;
}

void calc(int m) {
  ll N;
  int k; cin >> N >> k;
  map<ll, int> mp;
  vector<P> fracs(k);
  for (int i = 0; i < k; i++) {
    int denom, numer;
    cin >> numer >> denom;
    fracs[i] = P(numer, denom);
  }

  int count = 0;
  int lc = 0;
  while (count != m) {
    P frac = fracs[find_frac(mp, fracs, N)];
    N = frac.first * N / frac.second;
    cerr << N << endl;

    int M = N;
    int c = 0;
    while ((M & 1) == 0) {
      c++;
      M >>= 1;
    }

    if (M == 1) {
      cout << c << ' ';
      count++;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  for (;;) {
    int m;
    cin >> m;
    if (m == 0) break;
    calc(m);
    cout << endl;
  }
  return 0;
}
