#include <iostream>
#include <vector>
#include <gmp.h>
using namespace std;

int main(void) {
  vector<int> primes;
  primes.push_back(2);
  mpz_t ans;
  mpz_init_set_ui(ans, 2);

  for (int i = 3; i < 2000000; i += 2) {
    bool isprime = true;
    for (vector<int>::const_iterator it = primes.begin(); it != primes.end(); it++) {
      if ((*it) * (*it) > i) {
        break;
      } else if (i % *it == 0) {
        isprime = false;
        break;
      }
    }

    if (isprime) {
      primes.push_back(i);
      mpz_add_ui(ans, ans, i);
    }
  }

  gmp_printf("%Zd\n", ans);

  return 0;
}

