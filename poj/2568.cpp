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

vector<int> v;
set<int> should_parent;
vector<int> childs[51];
set<int> joined;
int current_delete_target;

void get_input() {
  int i = 0;
  string s;
  getline(cin, s);
  while (s[i] != '\0') {
    int n = s[i++] - '0';
    if (isdigit(s[i])) n = n*10 + s[i++] - '0';
    v.push_back(n);
    should_parent.insert(n);
    while (isspace(s[i])) i++;
  }
}

void print_tree(vector<int> childs[], int root) {
  cout << '(' << root;
  vector<int> &v = childs[root];
  for (int i = 0; i < v.size(); i++) {
    cout << ' ';
    print_tree(childs, v[i]);
  }
  cout << ')';
}


bool f(int i) {
  if (i == v.size()) return true;
  if (joined.find(v[i]) == joined.end()) {
    // まだ入っていないので、どこかで消される。
    if (v[i] > current_delete_target) {
      if (should_parent.find(current_delete_target) != should_parent.end()) {
        childs[current_delete_target].push_back(v[i]);
        joined.insert(v[i]);
        int saved_target = current_delete_target;
        current_delete_target = v[i];
        if (f(i+1)) {
          return true;
        } else {
          current_delete_target = saved_target;
          joined.erase(v[i]);
          childs[current_delete_target].pop_back();
          return false;
        }
      } else {
        return false;
      }
    } else {
      // どこにつけてもよさげ、適当にルートにつけとくか
      for (int k = 0; k < i; k++) {
        childs[k].push_back(v[i]);
        joined.insert(v[i]);
        int saved_target = current_delete_target;
        current_delete_target = v[i];
        if (f(i+1)) {
          return true;
        } else {
          current_delete_target = saved_target;
          joined.erase(v[i]);
          childs[k].pop_back();
        }
      }
      return false;
    }
  } else {
    // もう入っているということは、current_delete_targetになんか新しいノード
    // をつけないといけない。
    // とりあえず先にある新しくつけるべきノードを探して勝手につける。
    for (int k = i+1; k < v.size(); k++) {
      if (joined.find(v[k]) == joined.end()) {
        childs[current_delete_target].push_back(v[k]);
        joined.insert(v[k]);
        int saved_target = current_delete_target;
        current_delete_target = v[k];
        if (f(i+1)) {
          return true;
        } else {
          current_delete_target = saved_target;
          joined.erase(v[k]);
          childs[current_delete_target].pop_back();
        }
      }
    }

    // 見つからなかったら、これは必ず current_delete_target よりも小さい何
    // かがついていたはずなので、current_delete_targetよりも小さい、まだ
    // joinされていないノードを作ってつける。このとき、この作られたノード
    // になにかがつけられてはいけないことに注意。
    for (int k = 1; k < 51; k++) {
      if (should_parent.find(k) == should_parent.end()
       && joined.find(k) == joined.end())
      {
        childs[v[i]].push_back(k);
        joined.insert(k);
        int saved_target = current_delete_target;
        current_delete_target = k;
        if (f(i+1)) {
          return true;
        } else {
          current_delete_target = saved_target;
          joined.erase(k);
          childs[v[i]].pop_back();
        }
      }
    }
    return false;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  while (true) {
    {
      v.clear();
      should_parent.clear();
      joined.clear();
      for (int i = 0; i < 50; i++) {
        childs[i].clear();
      }
    }

    {
      get_input();
      if (v.size() == 0) break;
      reverse(v.begin(), v.end());
    }

    childs[v[0]].push_back(v[1]);
    joined.insert(v[0]);
    joined.insert(v[1]);
    current_delete_target = v[1];

    if (f(2)) {
      childs[current_delete_target].push_back(0);
      print_tree(childs, v[0]);
      cout << endl;
    } else {
      cout << "something went wrong!" << endl;
    }
    return 0;
  }
  return 0;
}
