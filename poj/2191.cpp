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
typedef unsigned long long ull;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int primes[64];
void calc_primes(void) {
  primes[0] = 2;
  int count = 1;
  for (ll i = 3; i < (1 << 15) && count < 64; i+=2) {
    bool isprime = true;
    for (int k = 0; k < count; k++) {
      if (primes[k] * primes[k] > i) break;
      if (i % primes[k] == 0) {
        isprime = false;
        break;
      }
    }

    if (isprime) {
      primes[count++] = i;
    }
  }
}

bool lucas_test(int p, ll mersenne) {
  if (p == 2) return true;
  
  ull s = 4;
  rep (i, p-2) {
    s = s*s - 2;
    cerr << s << endl;
  }
  
  if (s % mersenne == 0) {
    return true;
  } else {
    cout << s << endl;
    return false;
  }
}

int main(void) {
  calc_primes();
  int N;
  cin >> N;
  
  int idx = 0;
  for (int i = 0; primes[i] < N; i++) {
    ull mersenne = (1ULL << primes[i]) - 1;
    if (!lucas_test(primes[i], mersenne)) {
      cout << mersenne << endl;
    }
  }
  return 0;
}
