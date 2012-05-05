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

vector<int> primes;
void calc(void) {
  primes.push_back(2);
  for (int i = 3; i < 1000000; i+=2) {
    bool is_prime = true;
    each(it, primes) {
      if ((i % *it) == 0) {
        is_prime = false;
        break;
      } else if ((*it)*(*it) > i) {
        break;
      }
    }
    
    if (is_prime) {
      primes.push_back(i);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  int n;
  calc();

  while (cin >> n) {
    vector<int>::iterator it = upper_bound(primes.begin(), primes.end(), n);
    cout << it - primes.begin() << endl;
  }
  return 0;
}
