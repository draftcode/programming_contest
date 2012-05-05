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

int convert(char c) {
  switch (c) {
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    case 'T': return 10;
    case 'J': return 11;
    case 'Q': return 12;
    case 'K': return 13;
    case 'A': return 14;
  }
  return 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  string tramp, first, second;
  cin >> tramp >> first >> second;

  if (first[1] == tramp[0] && second[1] != tramp[0]) {
    cout << "YES" << endl;
    return 0;
  }

  if (first[1] == second[1]) {
    if (convert(first[0]) > convert(second[0])) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  return 0;
}
