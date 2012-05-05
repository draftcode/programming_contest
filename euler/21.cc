#include <iostream>
#include <gmpxx.h>
using namespace std;

int am[10000];

int main(void) {
  for (int i = 1; i < 10000; i++) {
    int sum = 1;
    for (int k = 2; k <= i/2; k++) {
      if (i % k == 0) sum += k;
    }

    if (sum < 10000 && sum != i) am[i] = sum;
  }

  long ans = 0;
  for (int i = 1; i < 10000; i++) {
    if (am[am[i]] == i) ans += i;
  }
  cout << ans << endl;
  return 0;
}

