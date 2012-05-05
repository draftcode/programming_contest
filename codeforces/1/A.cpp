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

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int main(void) {
  ll n, m, a;
  cin >> n >> m >> a;

  ll nreq, mreq;
  nreq = n/a;
  if (n%a != 0) nreq++;
  mreq = m/a;
  if (m%a != 0) mreq++;

  cout << nreq * mreq << endl;
  return 0;
}
