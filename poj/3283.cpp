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

char parse(char *t) {
  char ret = 0;
  int i = 0;
  if (t[i] == '1') {
    ret = 10;
    i += 2;
  } else if (isdigit(t[i])) {
    ret = t[i] - '0';
    i++;
  } else if (t[i] == 'A') {
    ret = 1;
    i++;
  } else if (t[i] == 'J') {
    ret = 11;
    i++;
  } else if (t[i] == 'Q') {
    ret = 12;
    i++;
  } else if (t[i] == 'K') {
    ret = 13;
    i++;
  }

  if (t[i] == 'C') {
  } else if (t[i] == 'D') {
    ret += 13;
  } else if (t[i] == 'H') {
    ret += 26;
  } else if (t[i] == 'S') {
    ret += 39;
  }

  return ret;
}

int main(void) {
  for (;;) {
    int N; scanf("%d", &N); if (N == 0) break;

    set<string> s;
    for (int n = 0; n < N; n++) {
      int K; scanf("%d", &K);

      string cards(K, ' ');
      for (int k = 0; k < K; k++) {
        char t[4]; scanf("%s", t);
        char c = parse(t);
        cards[k] = c;
      }

      for (int i = 0; i < cards.size(); i++) {
        pair<set<string>::iterator, bool> p = s.insert(cards.substr(i));
        if (p.second == false) {
          break;
        }
      }
    }

    printf("%lu\n", s.size());
  }
  return 0;
}
