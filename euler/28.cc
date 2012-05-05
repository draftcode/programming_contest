#include <iostream>
#include <gmpxx.h>
using namespace std;

int main(void) {
  mpz_class ans(1);
  int curr = 1;
  for (int i = 1; i < 1000; i += 2) {
    curr += i + 1;
    ans += curr;
    curr += i + 1;
    ans += curr;
    curr += i + 1;
    ans += curr;
    curr += i + 1;
    ans += curr;
  }
  cout << ans << endl;
  return 0;
}

