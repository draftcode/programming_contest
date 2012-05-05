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

int main(void) {
  ios::sync_with_stdio(false);
  vector<pair<string, string> > shelve;
  map<string, string> books;
  for (;;) {
    string s;
    getline(cin, s);
    if (s == "END") break;

    int i;
    for (i = 1; s[i] != '"'; i++);
    shelve.push_back(make_pair(s.substr(i+5), s.substr(0, i+1)));
    books.insert(make_pair(s.substr(0, i+1), s.substr(i+5)));
  }
  sort(shelve.begin(), shelve.end());

  vector<int> borrowed(books.size(), 0);
  vector<pair<string, string> > returned;
  for (;;) {
    string s;
    getline(cin, s);
    if (s == "END") break;

    if (s[0] == 'S') {
      sort(returned.begin(), returned.end());
      for (int i = 0; i < returned.size(); i++) {
        string book = returned[i].second;
        int pos;
        for (pos = 0; pos < shelve.size(); pos++) {
          if (shelve[pos].second == book) break;
        }

        int prev;
        for (prev = pos-1; prev != -1 && borrowed[prev]; prev--);
        if (prev == -1) {
          cout << "Put " << book << " front" << endl;
        } else {
          cout << "Put " << book << " after " << shelve[prev].second << endl;
        }
        borrowed[pos] = 0;
      }
      returned.clear();
      cout << "END" << endl;
    } else {
      string book = s.substr(7);
      if (s[0] == 'B') {
        int pos;
        for (pos = 0; pos < shelve.size(); pos++) {
          if (shelve[pos].second == book) break;
        }
        borrowed[pos] = 1;
      } else if (s[0] == 'R') {
        returned.push_back(make_pair(books[book], book));
      }
    }
  }
  return 0;
}
