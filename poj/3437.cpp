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

int current_top;
vector<int> trees[10000];

int parse(int current, string::const_iterator &it, int height) {
  int ret = height;
  while (*it != '\0') {
    if (*it == 'd') {
      it++;
      int child = current_top++;
      trees[child].clear();
      trees[current].push_back(child);
      ret = max(ret, parse(child, it, height+1));
    } else if (*it == 'u') {
      it++;
      return ret;
    }
  }
  return ret;
}

int convert(int current, int height) {
  int ret = height;

  int childs_size = trees[current].size();
  if (childs_size != 0) {
    for (int i = childs_size-1; i >= 0; i--) {
      ret = max(ret, convert(trees[current][i], height+i+1));
    }
  }
  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  for (int t = 1; ; t++) {
    string s; cin >> s;
    if (s[0] == '#') break;

    string::const_iterator it = s.begin();
    current_top = 1;
    trees[0].clear();
    int before_height = parse(0, it, 0);

    int after_height = convert(0, 0);
    cout << "Tree " << t << ": " << before_height << " => " << after_height << endl;
  }
  return 0;
}
