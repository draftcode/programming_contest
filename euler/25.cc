#include <iostream>
#include <gmpxx.h>
using namespace std;

int main(void) {
  mpz_class a(1);
  for (int i = 0; i < 999; i++) {
    a *= 10;
  }

  mpz_class f1(1);
  mpz_class f2(1);
  int count = 2;

  while (f2 <= a) {
    mpz_class f3(f1+f2);
    f1 = f2;
    f2 = f3;
    count++;
  }
  cout << count << endl;

  return 0;
}

