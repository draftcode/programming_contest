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

int primes[16384];
void calc_primes(void) {
  primes[0] = 2;
  int count = 1;
  for (ll i = 3; i < (1 << 30) && count < 16384; i+=2) {
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

int main(void) {
  ios::sync_with_stdio(false);
  calc_primes();
  int a, b;
  while (cin >> a >> b, a != 0 && b != 0) {
    vector<int> va, vb;
    int i = 0;
    while (a != 1) {
      if (a % primes[i] == 0) {
        while (a % primes[i] == 0) {
          a /= primes[i];
        }
        va.push_back(primes[i]);
      } else {
        i++;
      }
    }
    i = 0;
    while (b != 1) {
      if (b % primes[i] == 0) {
        while (b % primes[i] == 0) {
          b /= primes[i];
        }
        vb.push_back(primes[i]);
      } else {
        i++;
      }
    }

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    int ma = va[va.size()-1];
    for (int i = 0; i < va.size()-1; i++) {
      ma -= va[i];
    }
    int mb = vb[vb.size()-1];
    for (int i = 0; i < vb.size()-1; i++) {
      mb -= vb[i];
    }

    if (ma > mb) {
      cout << 'a' << endl;
    } else {
      cout << 'b' << endl;
    }
  }
  return 0;
}
