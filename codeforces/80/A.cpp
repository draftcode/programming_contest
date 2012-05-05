#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

vector<int> primes;

void ready_prime(void) {
  primes.push_back(2);
  for (int i = 3; i < 100; i += 2) {
    bool isprime = true;
    each (it, primes) {
      if (i % (*it) == 0) {
        isprime = false;
        break;
      }
    }

    if (isprime) primes.push_back(i);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  ready_prime();

  int n, m;
  cin >> n >> m;
  vector<int>::iterator it = lower_bound(primes.begin(), primes.end(), n);
  it++;

  if (*it == m) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
