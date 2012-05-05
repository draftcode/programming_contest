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

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

struct UnionFind {
  vector<int> data;
  int groups;
  UnionFind(int size) : data(size, -1), groups(size) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
      groups--;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

vector<int> primes;

void calc_prime(void) {
  for (int p = 2; p <= 1000000; p++) {
    bool prime = true;
    each (it, primes) {
      if (p % *it == 0) {
        prime = false;
        break;
      }
    }
    if (prime) primes.push_back(p);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  calc_prime();

  int C;
  cin >> C;
  rep (i, C) {
    ll A, B, P;
    cin >> A >> B >> P;
    UnionFind uf(B-A+1);
    
    vector<int>::iterator it = lower_bound(primes.begin(), primes.end(), P);
    while (it != primes.end() && *it <= B) {
      int k = A/(*it);
      if (k*(*it) != A) k++;
      int first_k = k++;
      for (; k*(*it) <= B; k++) {
        uf.unionSet(first_k*(*it) - A, k*(*it) - A);
      }
      it++;
    }

    cout << "Case #" << i+1 << ": " << uf.groups << endl;
  }
  return 0;
}
