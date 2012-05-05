#include <iostream>
#include <gmpxx.h>
using namespace std;

int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
const int C = 7;

int f(int amount, int cmax) {
  if (amount <= 1) return 1;
  int ret = 0;
  for (int c = cmax; c >= 0; c--) {
    if (coins[c] <= amount) {
      ret += f(amount - coins[c], c);
    }
  }
  return ret;
}

int main(void) {
  cout << f(200, C) << endl;
}

