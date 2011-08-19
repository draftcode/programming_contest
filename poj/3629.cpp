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

int N, K, P;
bool cards[100000];

int main(void) {
  zclear(cards);
  cin >> N >> K >> P;

  vector<int> positions;
  int dealt = 0;
  int top = 0;
  while (1) {
    // search not dealt cards.
    while (cards[top]) {
      top = (top + 1) % K;
    }

    // 0 is the first cow, N-1 is Bessie.
    if (dealt % N == N - 1) {
      positions.push_back(top);
    }

    cards[top] = true;
    dealt += 1;
    if (dealt == K) break;

    // skip P cards.
    int skips = P;
    if (K - dealt <= P) {
      skips = P % (K-dealt);
    }
    rep (i, skips) {
      // search not dealt cards.
      while (cards[top]) {
        top = (top + 1) % K;
      }
      // skip the card.
      top = (top + 1) % K;
    }
  }

  sort(positions.begin(), positions.end());

  each(it, positions) {
    cout << *it + 1 << endl;
  }

  return 0;
}
