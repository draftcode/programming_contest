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
#include <list>

#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

struct Ball {
  int num;
  int size;

  bool operator <(const Ball &rhs) const {
    if (num == rhs.num) {
      return size > rhs.size;
    } else {
      return num > rhs.num;
    }
  }
};

int N;

int main(void) {
  scanf("%d", &N);
  map<int, int> m;
  for (int i = 0; i < N; i++) {
    int size;
    scanf("%d", &size);
    map<int, int>::iterator it = m.find(size);
    if (it != m.end()) {
      it->second++;
    } else {
      m.insert(make_pair(size, 1));
    }
  }

  list<Ball> v;
  for (map<int, int>::const_iterator it = m.begin(); it != m.end(); ++it) {
    v.push_back((Ball){it->second, it->first});
  }
  v.sort();

  int ans = 0;
  ostringstream os;
  printf("%d\n%s", ans, os.str().c_str());
  return 0;
}
