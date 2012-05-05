#include <iostream>
#include <map>
#include <gmpxx.h>
using namespace std;

int main(void) {
  map<mpz_class, bool> m;
  for (int a = 2; a <= 100; a++) {
    for (int b = 2; b <= 100; b++) {
      mpz_class c;
      mpz_ui_pow_ui(c.get_mpz_t(), a, b);
      m[c] = true;
    }
  }
  cout << m.size() << endl;
  return 0;
}

