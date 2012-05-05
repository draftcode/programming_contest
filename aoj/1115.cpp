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

string lines[100];
int Plen, Cnum, Width, CSpace;
int main(void) {
  ios::sync_with_stdio(false);
  while (cin.peek() != '0') {
    cin >> Plen >> Cnum >> Width >> CSpace; cin.ignore();
    for (int i = 0; i < Plen; i++) {
      lines[i].clear();
    }

    int current_line = 0;
    int current_column = 0;
    for (;;) {
      string line; getline(cin, line);
      if (line == "?") break;

      for (int i = line.size()-1; i >= 0; i--) {
        if (line[i] == ' ') {
          line[i] = '.';
        } else {
          break;
        }
      }

      if (line.size() == 0 || line.size() % Width != 0) {
        line += string(Width - (line.size() % Width), '.');
      }
      for (int i = 0; i < line.size(); i += Width) {
        if (current_column == 0) {
          lines[current_line] += line.substr(i, Width);
        } else {
          lines[current_line] += string(CSpace, '.') + line.substr(i, Width);
        }

        current_line++;
        if (current_line == Plen) {
          current_line = 0;
          current_column++;
          if (current_column == Cnum) {
            current_column = 0;
          }
        }
      }
    }

    if (lines[0].size() != 0) {
      int page_width = Cnum*Width + CSpace*(Cnum-1);
      int whole_width = lines[0].size();
      if (lines[0].size() % page_width != 0)
        whole_width += page_width - (lines[0].size() % page_width);
      for (int i = 0; i < Plen; i++) {
        if (lines[i].size() != whole_width) {
          lines[i] += string(whole_width - lines[i].size(), '.');
        }
      }

      for (int page = 0; page < lines[0].size(); page += page_width) {
        for (int i = 0; i < Plen; i++) {
          cout << lines[i].substr(page, page_width) << endl;
        }
        cout << '#' << endl;
      }
    }
    cout << '?' << endl;
  }
  return 0;
}
