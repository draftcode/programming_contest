#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int cards[13];

void parse(const string &s) {
  int number = 0;
  for (string::const_iterator it = s.begin(); it != s.end(); it++) {
    if (*it == ',') {
      cards[number-1]++;
      number = 0;
    } else {
      number *= 10;
      number += *it - '0';
    }
  }
  cards[number-1]++;
}

bool straight(void) {
  for (int i = 0; i < 10; i++) {
    bool isstraight = true;
    for (int k = 0; k < 5; k++) {
      if (cards[(i+k) % 13] != 1) {
        isstraight = false;
        break;
      }
    }

    if (isstraight) return true;
  }
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  string s;
  while (cin >> s) {
    fill_n(cards, sizeof(cards)/sizeof(cards[0]), 0);
    parse(s);

    int pairs[6];
    fill_n(pairs, sizeof(pairs)/sizeof(pairs[0]), 0);
    for (int i = 0; i < 13; i++) pairs[cards[i]]++;

    if (pairs[4] == 1) {
      cout << "four card" << endl;
    } else if (pairs[2] == 1 && pairs[3] == 1) {
      cout << "full house" << endl;
    } else if (straight()) {
      cout << "straight" << endl;
    } else if (pairs[3] == 1) {
      cout << "three card" << endl;
    } else if (pairs[2] == 2) {
      cout << "two pair" << endl;
    } else if (pairs[2] == 1) {
      cout << "one pair" << endl;
    } else {
      cout << "null" << endl;
    }
  }
  return 0;
}
