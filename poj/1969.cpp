#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>
#include <map>
#include <set>

#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(void) {
  ios::sync_with_stdio(false);
  int T;
  while (cin >> T) {
    int i = 1;
    int sum = 0;
    while (sum + i < T) {
      sum += i++;
    }
    // i numbers in the row.
    int from_left = i - (T - sum - 1);
    int from_right = i - from_left + 1;

    int down, up;
    if (i % 2 == 0) {
      down = from_left;
      up = from_right;
    } else {
      up = from_left;
      down = from_right;
    }

    cout << "TERM " << T << " IS " << up << '/' << down << endl;
  }
  return 0;
}
