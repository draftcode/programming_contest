#include <iostream>
#include <gmpxx.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  vector<int>v;
  for (int i = 0; i < 10; i++) {
    v.push_back(i);
  }

  for (int i = 0; i < 999999; i++) {
    next_permutation(v.begin(), v.end());
  }

  for (int i = 0; i < 10; i++) {
    cout << v[i];
  }
  cout << endl;

  return 0;
}

