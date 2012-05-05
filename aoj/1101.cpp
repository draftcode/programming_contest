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

  int N; cin >> N; cin.ignore();
  for (int _ = 0; _ < N; _++) {
    int pos = 0; string line;
    getline(cin, line);

    int C; cin >> C; cin.ignore();
    for (int __ = 0; __ < C; __++) {
      string command;
      getline(cin, command);
      if (command == "forward char") {
        if (pos != line.size()) pos++;
      } else if (command == "forward word") {
        while (pos != line.size() && line[pos] == ' ') pos++;
        while (pos != line.size() && line[pos] != ' ') pos++;
      } else if (command == "backward char") {
        if (pos != 0) pos--;
      } else if (command == "backward word") {
        while (pos > 0 && line[pos-1] == ' ') pos--;
        while (pos > 0 && line[pos-1] != ' ') pos--;
      } else if (command == "delete char") {
        if (pos < line.size())
          line = line.substr(0, pos) + line.substr(pos+1);
      } else if (command == "delete word") {
        int delend = pos;
        while (delend != line.size() && line[delend] == ' ') delend++;
        if (delend != line.size()) {
          while (delend != line.size() && line[delend] != ' ') delend++;
          line = line.substr(0, pos) + line.substr(delend);
        }
      } else {
        string inserted = command.substr(8, command.size() - 9);
        line = line.substr(0, pos) + inserted + line.substr(pos);
        pos += inserted.size();
      }
    }
    cout << line.substr(0, pos) << '^' << line.substr(pos) << endl;
  }
  return 0;
}
