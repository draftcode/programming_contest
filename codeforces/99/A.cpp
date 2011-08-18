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
  char s1[1024], s2[1024];
  scanf("%[^.].%s", s1, s2);
  int l = strlen(s1)-1;

  if (s1[l] == '9') {
    printf("GOTO Vasilisa.\n");
    return 0;
  }
  if (s2[0] > '4') s1[l]++;
  printf("%s\n", s1);
  return 0;
}
