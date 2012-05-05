#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <vector>

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
  int n;
  cin >> n;
  
  string str;
  getline(cin, str);
  rep (_i, n) {
    getline(cin, str);
    cout << "Case #" << _i + 1 << ": ";

    int end = str.size();
    while (end != -1) {
      int start = end-1;
      while (str[start] != ' ' && start != -1) start--;
      
      int next_end = start;
      start++;
      while (start != end) {
        cout << str[start];
        start++;
      }
      
      end = next_end;
      if (end != -1) cout << ' ';
    }
    cout << endl;
  }
  return 0;
}
