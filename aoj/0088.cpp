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
  table1[' ']  = "101";
  table1['\''] = "000000";
  table1[',']  = "000011";
  table1['-']  = "10010001";
  table1['.']  = "010001";
  table1['?']  = "000001";
  table1['A']  = "100101";
  table1['B']  = "10011010";
  table1['C']  = "0101";
  table1['D']  = "0001";
  table1['E']  = "110";
  table1['F']  = "01001";
  table1['G']  = "10011011";
  table1['H']  = "010000";
  table1['I']  = "0111";
  table1['J']  = "10011000";
  table1['K']  = "0110";
  table1['L']  = "00100";
  table1['M']  = "10011001";
  table1['N']  = "10011110";
  table1['O']  = "00101";
  table1['P']  = "111";
  table1['Q']  = "10011111";
  table1['R']  = "1000";
  table1['S']  = "00110";
  table1['T']  = "00111";
  table1['U']  = "10011100";
  table1['V']  = "10011101";
  table1['W']  = "000010";
  table1['X']  = "10010010";
  table1['Y']  = "10010011";
  table1['Z']  = "10010000";

  map<string, char> table2;
  table2["00000"] = 'A';
  table2["00001"] = 'B';
  table2["00010"] = 'C';
  table2["00011"] = 'D';
  table2["00100"] = 'E';
  table2["00101"] = 'F';
  table2["00110"] = 'G';
  table2["00111"] = 'H';
  table2["01000"] = 'I';
  table2["01001"] = 'J';
  table2["01010"] = 'K';
  table2["01011"] = 'L';
  table2["01100"] = 'M';
  table2["01101"] = 'N';
  table2["01110"] = 'O';
  table2["01111"] = 'P';
  table2["10000"] = 'Q';
  table2["10001"] = 'R';
  table2["10010"] = 'S';
  table2["10011"] = 'T';
  table2["10100"] = 'U';
  table2["10101"] = 'V';
  table2["10110"] = 'W';
  table2["10111"] = 'X';
  table2["11000"] = 'Y';
  table2["11001"] = 'Z';
  table2["11010"] = ' ';
  table2["11011"] = '.';
  table2["11100"] = ',';
  table2["11101"] = '-';
  table2["11110"] = '\'';
  table2["11111"] = '?';

  string s;
  while (getline(cin, s)) {
    string t;
    for (string::const_iterator it = s.begin(); it != s.end(); it++) {
      t += table1[*it];
    }
    if ((t.size() % 5) != 0) {
      t += string(5 - (t.size()%5), '0');
    }

    string ans;
    for (int i = 0; i < (t.size()/5); i++) {
      ans.push_back(table2[t.substr(i*5, 5)]);
    }
    cout << ans << endl;
  }

  return 0;
}

