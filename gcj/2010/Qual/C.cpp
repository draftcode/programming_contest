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

int number[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
int counts[26] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};

int main(void) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  
  string str;
  getline(cin, str);
  rep (_i, n) {
    getline(cin, str);
    cout << "Case #" << _i + 1 << ": ";
    
    int prev_number = -1;
    each (it, str) {
      int num, cnt;
      if (*it == ' ') {
        num = 0; cnt = 1;
      } else {
        num = number[*it-'a'];
        cnt = counts[*it-'a'];
      }

      if (prev_number == num) cout << ' ';
      rep (i, cnt) cout << num;
      prev_number = num;
    }
    cout << endl;
  }
  return 0;
}
