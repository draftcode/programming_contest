#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

string reverse(string s) {
  reverse(all(s));
  return s;
}

int main(void) {
  int m;
  scanf("%d", &m);
  char str[80];
  char a[80];
  char b[80];
  char reva[80];
  char revb[80];
  char temp[80];
  rep (_i, m) {
    set<string> s;
    scanf("%s", str);
    int sz = strlen(str);

    s.insert(string(str));
    for (int i = 1; i < sz; i++) {
      for (int k = 0; k < i; k++) {
        a[k] = str[k];
        reva[k] = str[i-k-1];
      }
      a[i] = '\0';
      reva[i] = '\0';
      for (int k = i; k < sz; k++) {
        b[k-i] = str[k];
        revb[k-i] = str[sz+i-k-1];
      }
      b[sz-i] = '\0';
      revb[sz-i] = '\0';
      strcpy(temp, a); strcat(temp, revb);
      s.insert(string(temp));
      strcpy(temp, reva); strcat(temp, b);
      s.insert(string(temp));
      strcpy(temp, reva); strcat(temp, revb);
      s.insert(string(temp));

      strcpy(temp, b); strcat(temp, a);
      s.insert(string(temp));
      strcpy(temp, b); strcat(temp, reva);
      s.insert(string(temp));
      strcpy(temp, revb); strcat(temp, a);
      s.insert(string(temp));
      strcpy(temp, revb); strcat(temp, reva);
      s.insert(string(temp));
    }

    printf("%lu\n", s.size());
  }
  return 0;
}
