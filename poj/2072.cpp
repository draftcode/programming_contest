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

struct Node {
  vector<int> next;
  Node() : next(26, 0) {};
};

int N, me;
vector<Node> table;

P dfs(int turn, int table_idx, int curr_min) {
  if (turn > curr_min) return P(-1, curr_min);
  vector<int> &node = table[table_idx].next;
  if (turn % N == me) {
    int ret = -1;
    for (int i = 0; i < 26; i++) {
      if (node[i] != -1 && node[i] != 0) {
        // cout << "In " << turn << " choose " << (char)('a' + i) << endl;
        P r = dfs(turn+1, node[i], curr_min);
        if (r.first != -1 && r.second < curr_min) {
          // cout << "In " << turn << " choose " << (char)('a' + i) << " GOOD" << endl;
          curr_min = r.second;
          ret = i;
        }
      }
    }
    if (ret == -1) {
      return P(-1, INT_MAX);
    } else {
      return P(ret, curr_min);
    }
  } else {
    bool may_fault = false;
    for (int i = 0; i < 26; i++) {
      if (node[i] != -1 && node[i] != 0) {
        // cout << "EE " <<  turn << " choose " << (char)('a' + i) << endl;
        P ret = dfs(turn+1, node[i], curr_min);
        if (ret.first == -1) {
          // cout << "EE " <<  turn << " choose " << (char)('a' + i) << " GOOD " << endl;
          return P(-1, INT_MAX);
        } else {
          curr_min = ret.second;
        }
      } else if (node[i] == -1) {
        may_fault = true;
      }
    }
    if (may_fault) {
      return P(0, turn);
    } else {
      return P(0, curr_min);
    }
  }
}

void solve(vector<string> &words, int max_len, string &start) {
  table = vector<Node>(1);
  for (unsigned int i = 0; i < words.size(); i++) {
    string &s = words[i];
    int table_idx = 0;
    for (unsigned int k = 0; k < s.size() -1; k++) {
      int j = s[k] - 'a';
      if (table[table_idx].next[j] == 0) {
        table.push_back(Node());
        table[table_idx].next[j] = table.size() - 1;
        table_idx = table.size() - 1;
      } else if (table[table_idx].next[j] == -1) {
        break;
      } else {
        table_idx = table[table_idx].next[j];
      }
    }
    table[table_idx].next[s[s.size()-1] - 'a'] = -1;
  }

  int table_idx = 0;
  for (unsigned int k = 0; k < start.size(); k++) {
    int j = start[k] - 'a';
    if (table[table_idx].next[j] == 0) {
      cout << start << ' ' << "Challenge" << endl;
      return;
    } else if (table[table_idx].next[j] == -1) {
      // couldn't be happened.
    } else {
      table_idx = table[table_idx].next[j];
    }
  }

  me = (start.size()+1) % N;
  int curr_min = INT_MAX;
  P c = dfs(start.size()+1, table_idx, curr_min);
  if (c.first == -1) {
    cout << start << " Bluff" << endl;
  } else {
    cout << start << ' ' << (char)('a' + c.first) << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  while (true) {
    cin >> N;
    if (N == 0) break;
    cin.ignore();

    size_t l = 0;
    vector<string> v;
    while (true) {
      string s; getline(cin, s);
      if (s == "") break;
      v.push_back(s);
      l = max(l, s.size());
    }

    string s; getline(cin, s);
    solve(v, l, s);
  }
  return 0;
}
