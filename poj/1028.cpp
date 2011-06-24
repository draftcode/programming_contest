#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
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
  char s[100];

  stack<string> forward, backward;
  string current = "http://www.acm.org/";
  for (;;) {
    scanf("%s", s);
    if (strcmp(s, "VISIT") == 0) {
      backward.push(current);
      scanf("%s", s);
      current = s;
      while (!forward.empty()) forward.pop();
      printf("%s\n", current.c_str());
    } else if (strcmp(s, "BACK") == 0) {
      if (backward.empty()) {
        printf("%s\n", "Ignored");
      } else {
        forward.push(current);
        current = backward.top(); backward.pop();
        printf("%s\n", current.c_str());
      }
    } else if (strcmp(s, "FORWARD") == 0) {
      if (forward.empty()) {
        printf("%s\n", "Ignored");
      } else {
        backward.push(current);
        current = forward.top(); forward.pop();
        printf("%s\n", current.c_str());
      }
    } else if (strcmp(s, "QUIT") == 0) {
      break;
    }
  }
  return 0;
}
