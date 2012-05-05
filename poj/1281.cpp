#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <iterator>
#include <vector>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

bool not_zero(int i) {
  return i != 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  int M, L;
  while (cin >> M) {
    vector<int> processes(M+1, 0);

    cin >> L;
    vector<int> removal_list;
    rep (i, L) {
      int k; cin >> k;
      removal_list.push_back(k);
    }

    int policy = 1;
    vector<int> removed;

    for (;;) {
      string command;
      cin >> command;
      if (command[0] == 'a') {
        int k; cin >> k;
        processes[k-1]++;
      } else if (command[0] == 'r') {
        int cost = -1;
        if (policy == 1) {
          vector<int>::iterator it = find_if(processes.begin(), processes.end(), not_zero);
          if (it != processes.end()) {
            cost = distance(processes.begin(), it) + 1;
            (*it)--;
          }
        } else {
          vector<int>::reverse_iterator it = find_if(processes.rbegin(), processes.rend(), not_zero);
          if (it != processes.rend()) {
            cost = distance(it, processes.rend());
            (*it)--;
          }
        }

        removed.push_back(cost);
      } else if (command[0] == 'p') {
        cin >> policy;
      } else if (command[0] == 'e') {
        break;
      }
    }

    each (it, removal_list) {
      cout << removed[(*it)-1] << endl;
    }
    cout << endl;
  }
  return 0;
}
