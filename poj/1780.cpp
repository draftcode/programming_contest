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

#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

bool used[1000001];

int calc(int N) {
  int cut = 1;
  for (int i = 0; i < N; i++) {
    cut *= 10;
    putchar('0');
  }
  memset(used, 0, sizeof(used));

  int curr = 0;
  int count = 1;
  used[0] = true;
  int set9 = 1;
  while (count != cut + N - 1) {
    curr *= 10;
    curr %= cut;
    int i;
    for (i = 0; i < 10; i++) {
      if (!used[curr + i]) break;
    }
    if (i == 10) return count;

    if ((curr / 10) % 10 == 9) {
      i += set9;
      set9++;
      set9 %= 10;
    }
    putchar('0' + i);
    used[curr + i] = true;

    curr += i;
    count++;
  }
  return count;
}

int main(void) {
  while (true) {
    int N;
    scanf("%d", &N);
    if (N == 0) break;
    cerr << calc(N) << endl;
    putchar('\n');
  }
  return 0;
}
