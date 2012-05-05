#include <iostream>
#include <gmpxx.h>
using namespace std;

int main(void) {
  mpz_class ans(0);
  for (int i = 1; i < 1001; i++) {
    mpz_class a(0);
    mpz_ui_pow_ui(a.get_mpz_t(), i, i);
    ans += a;
  }
  cout << ans << endl;
  return 0;
}

