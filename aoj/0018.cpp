#include <algorithm>
#include <iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int v[5];
  for (int i = 0; i < 5; i++) cin >> v[i];
  sort(v, v+5, greater<int>());
  cout << v[0];
  for (int i = 1; i < 5; i++) cout << ' ' << v[i];
  cout << endl;
  return 0;
}
