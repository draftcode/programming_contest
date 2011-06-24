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

bool comp(char a, char b) {
  char a_ = tolower(a), b_ = tolower(b);
  if (a_ == b_) {
    return a < b;
  } else {
    return a_ < b_;
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  rep (i, n) {
    char str[16];
    scanf("%s", str);
    int len = strlen(str);
    sort(str, str+len, comp);
    do {
      printf("%s\n", str);
    } while (next_permutation(str, str+len, comp));
  }
  return 0;
}
