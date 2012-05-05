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
  vector<string> buf;
  string yankbuf;

  for (;;) {
    string s;
    getline(cin, s);
    if (s == "END_OF_TEXT") break;
    buf.push_back(s);
  }

  int line_no = 0, line_pos = 0;
  for (;;) {
    string command; cin >> command; if (command == "-") break;

    if (command[0] == 'a') {
      line_pos = 0;

    } else if (command[0] == 'e') {
      line_pos = buf[line_no].size();

    } else if (command[0] == 'p') {
      if (line_no != 0) line_no--;
      line_pos = 0;

    } else if (command[0] == 'n') {
      if (line_no != buf.size()-1) line_no++;
      line_pos = 0;

    } else if (command[0] == 'f') {
      if (line_pos != buf[line_no].size()) {
        line_pos++;
      } else if (line_no != buf.size()-1) {
        line_no++;
        line_pos = 0;
      }

    } else if (command[0] == 'b') {
      if (line_pos != 0) {
        line_pos--;
      } else if (line_no != 0) {
        line_no--;
        line_pos = buf[line_no].size();
      }

    } else if (command[0] == 'd') {
      if (line_pos != buf[line_no].size()) {
        buf[line_no].erase(line_pos, 1);
      } else if (line_no != buf.size()-1) {
        buf[line_no] += buf[line_no+1];
        buf.erase(buf.begin() + (line_no+1));
      }

    } else if (command[0] == 'k') {
      if (line_pos == buf[line_no].size()) {
        if (line_no != buf.size()-1) {
          buf[line_no] += buf[line_no+1];
          buf.erase(buf.begin() + (line_no+1));
          yankbuf = string(1, '\n');
        }
      } else {
        yankbuf = buf[line_no].substr(line_pos);
        buf[line_no].erase(line_pos);
      }

    } else if (command[0] == 'y') {
      if (yankbuf.size() == 0) {
      } else if (yankbuf[0] == '\n') {
        string newline = buf[line_no].substr(line_pos);
        buf[line_no].erase(line_pos);
        line_no++;
        buf.insert(buf.begin() + line_no, newline);
        line_pos = 0;

      } else {
        if (line_pos == buf[line_no].size()) {
          buf[line_no].insert(line_pos, yankbuf);
          line_pos = buf[line_no].size();
        } else {
          buf[line_no].insert(line_pos, yankbuf);
          line_pos += yankbuf.size();
        }
      }

    }
  }

  for (vector<string>::const_iterator it = buf.begin(); it != buf.end(); it++) {
    cout << *it << endl;
  }
  return 0;
}
