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
  int n; cin >> n;
  cin.ignore();
  for (int _ = 0; _ < n; _++) {
    string line;
    getline(cin, line);
    int size = line.size();
    for (int i = 0; i < size; i++) {
      if (line.compare(i, 7, "Hoshino") == 0) {
        line.replace(i, 7, "Hoshina");
      }
    }
    cout << line << endl;
  }
  return 0;
}
