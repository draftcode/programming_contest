#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>
#include <list>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int main(void) {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep (i, T) {
    int M, C, W;
    cin >> M >> C >> W;
    list<P> v;
    v.push_back(P(1,M));

    rep (c, C) {
      int A, B;
      cin >> A >> B;
      
      list<P>::iterator begin;
      list<P>::iterator end;
      int cards_before_it;
      int cards_from_begin_after_it;
      // {{{
      cards_before_it = 0;
      list<P>::iterator it = v.begin();
      for (;;) {
        int cards_in_it = it->second - it->first + 1;
        if (cards_before_it + cards_in_it < A) {
          it++;
          cards_before_it += cards_in_it;
        } else {
          begin = it;
          cards_from_begin_after_it = cards_before_it + cards_in_it - A + 1;
          break;
        }
      }
      // }}}
      // {{{
      end = it;
      while (cards_from_begin_after_it < B) {
        end++;
        int cards_in_it = end->second - end->first + 1;
        cards_from_begin_after_it += cards_in_it;
      }
      // }}}

      if (begin == end) {
        int moved_first = begin->first + (A - cards_before_it - 1);
        int moved_second = begin->first + (A - cards_before_it + B - 2);
        if (moved_first == begin->first && moved_second == begin->second) {
          v.push_front(*begin);
          v.erase(begin);
        } else if (moved_first == begin->first) {
          v.push_front(P(moved_first, moved_second));
          end->first = moved_second + 1;
        } else if (moved_second == begin->second) {
          v.push_front(P(moved_first, moved_second));
          end->second = moved_first - 1;
        } else {
          v.push_front(P(moved_first, moved_second));
          v.insert(begin, P(begin->first, moved_first-1));
          end->first = moved_second + 1;
        }
      } else {
        int moved_end_second = end->second - (cards_from_begin_after_it - B);
        if (moved_end_second != end->second) {
          v.push_front(P(end->first, moved_end_second));
          end->first = end->second - (cards_from_begin_after_it - B - 1);
          end--;
        }
        while (end != begin) {
          v.push_front(*end);
          end = v.erase(end);
          end--;
        }

        int moved_begin_first = begin->first + (A - cards_before_it - 1);
        if (moved_begin_first == begin->first) {
          v.push_front(*begin);
          v.erase(begin);
        } else {
          v.push_front(P(moved_begin_first, begin->second));
          begin->second = moved_begin_first - 1;
        }
      }

      // each (iit, v) {
      //   cout << iit->first << " to " << iit->second << endl;
      // }
      // cout << endl;
    }

    int cards_before_it = 0;
    list<P>::iterator it = v.begin();
    for (;;) {
      int cards_in_it = it->second - it->first + 1;
      if (cards_before_it + cards_in_it < W) {
        it++;
        cards_before_it += cards_in_it;
      } else {
        cout << "Case #" << i+1 << ": " << it->first + W - cards_before_it - 1 << endl;
        break;
      }
    }
  }
  return 0;
}
