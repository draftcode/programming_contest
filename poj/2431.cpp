#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int main(void) {
  int N, pos, tank;
  vector<pair<int, int> > stops;
  stops.push_back(make_pair(0, 0));

  cin >> N;
  rep (i, N) {
    int distance, fuel;
    cin >> distance >> fuel;
    stops.push_back(make_pair(distance, fuel));
  }
  cin >> pos >> tank;
  sort(stops.begin(), stops.end());

  int count = 0;
  priority_queue<int> fuels;
  for (__typeof(stops.rbegin()) stop = stops.rbegin(); stop != stops.rend(); stop++) {
    int distance = pos - stop->first;

    while (distance > tank) {
      if (fuels.empty()) {
        cout << -1 << endl;
        return 0;
      }
      tank += fuels.top();
      fuels.pop();
      count++;
    }

    tank -= distance;
    pos = stop->first;
    fuels.push(stop->second);
  }
  cout << count << endl;
  
  return 0;
}
