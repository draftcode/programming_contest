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

struct tree {
  tree *parent;
  vector<tree *> childs;
  tree *further(void) {
    tree *ret = new tree();
    ret->parent = this;
    childs.push_back(ret);

    return ret;
  }
  tree *back(void) {
    return parent;
  }
}

int main(void) {

  return 0;
}
