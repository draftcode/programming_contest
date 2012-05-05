#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int parse(string s) {
  int num, suit;
  switch (s[0]) {
    case 'T': num = 8; break;
    case 'J': num = 9; break;
    case 'Q': num = 10; break;
    case 'K': num = 11; break;
    case 'A': num = 12; break;
    default: num = s[0] - '2'; break;
  }
  switch (s[1]) {
    case 'C': suit = 0; break;
    case 'D': suit = 1; break;
    case 'S': suit = 2; break;
    default: suit = 3; break;
  }
  return num*4 + suit;
}

int main(void) {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep (t, T) {
    vector<int> enemy_cards;
    vector<int> my_cards;

    int cards;
    cin >> cards;
    rep (i, cards) {
      string s; cin >> s;
      enemy_cards.push_back(parse(s));
    }
    rep (i, cards) {
      string s; cin >> s;
      my_cards.push_back(parse(s));
    }
    sort(enemy_cards.begin(), enemy_cards.end(), greater<int>());
    sort(my_cards.begin(), my_cards.end(), greater<int>());
    vector<int>::iterator mit = my_cards.begin(), eit = enemy_cards.begin();

    int win = 0;
    while (eit != enemy_cards.end() && mit != my_cards.end()) {
      if (*eit < *mit) {
        win++;
        mit++;
      }
      eit++;
    }
    cout << win << endl;
  }
  return 0;
}
