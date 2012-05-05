#include <iostream>
#include <gmpxx.h>
#include <vector>
using namespace std;

bool tab[28124];

int main(void) {
  vector<int> v;
  for (int i = 1; i < 28123; i++) {
    int s = 0;
    for (int k = 1; k < i; k++) {
      if (i % k == 0) {
        s += k;
      }
    }

    if (s > i) {
      v.push_back(i);
    }
  }

  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v.size(); j++) {
      if (v[i] + v[j] <= 28123) {
        tab[v[i] + v[j]] = true;
      }
    }
  }

  int sum = 0;
  for (int i = 0; i < 28123; i++) {
    if (!tab[i]) {
      sum += i;
    }
  }
  cout << sum << endl;
  return 0;
}

