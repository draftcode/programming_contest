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

  map<char, string> table1;
  table1['A'] = "00000";
  table1['B'] = "00001";
  table1['C'] = "00010";
  table1['D'] = "00011";
  table1['E'] = "00100";
  table1['F'] = "00101";
  table1['G'] = "00110";
  table1['H'] = "00111";
  table1['I'] = "01000";
  table1['J'] = "01001";
  table1['K'] = "01010";
  table1['L'] = "01011";
  table1['M'] = "01100";
  table1['N'] = "01101";
  table1['O'] = "01110";
  table1['P'] = "01111";
  table1['Q'] = "10000";
  table1['R'] = "10001";
  table1['S'] = "10010";
  table1['T'] = "10011";
  table1['U'] = "10100";
  table1['V'] = "10101";
  table1['W'] = "10110";
  table1['X'] = "10111";
  table1['Y'] = "11000";
  table1['Z'] = "11001";
  table1[' '] = "11010";
  table1['.'] = "11011";
  table1[','] = "11100";
  table1['-'] = "11101";
  table1['\''] = "11110";
  table1['?'] = "11111";

  map<string, char> table2;
  table2["000000"]   = '\'';
  table2["000001"]   = '?';
  table2["000010"]   = 'W';
  table2["000011"]   = ',';
  table2["0001"]     = 'D';
  table2["00100"]    = 'L';
  table2["00101"]    = 'O';
  table2["00110"]    = 'S';
  table2["00111"]    = 'T';
  table2["010000"]   = 'H';
  table2["010001"]   = '.';
  table2["01001"]    = 'F';
  table2["0101"]     = 'C';
  table2["0110"]     = 'K';
  table2["0111"]     = 'I';
  table2["1000"]     = 'R';
  table2["10010000"] = 'Z';
  table2["10010001"] = '-';
  table2["10010010"] = 'X';
  table2["10010011"] = 'Y';
  table2["100101"]   = 'A';
  table2["10011000"] = 'J';
  table2["10011001"] = 'M';
  table2["10011010"] = 'B';
  table2["10011011"] = 'G';
  table2["10011100"] = 'U';
  table2["10011101"] = 'V';
  table2["10011110"] = 'N';
  table2["10011111"] = 'Q';
  table2["101"]      = ' ';
  table2["110"]      = 'E';
  table2["111"]      = 'P';

  string s;
  while (getline(cin, s)) {
    string t;
    for (string::const_iterator it = s.begin(); it != s.end(); it++) {
      t += table1[*it];
    }

    string answer;
    int size = t.size();
    int start = 0;
    while (start < size) {
      int w = 1;
      for (; start + w <= size; w++) {
        if (table2.find(t.substr(start, w)) != table2.end()) {
          answer.push_back(table2[t.substr(start, w)]);
          break;
        }
      }
      start += w;
    }
    cout << answer << endl;
  }

  return 0;
}
