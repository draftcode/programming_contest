#include <iostream>
#include <sstream>
#include <gmpxx.h>
using namespace std;

int main(void) {
  mpz_class a(1);
  a <<= 1000;

  ostringstream os;
  os << a;
  string s = os.str();

  int ans = 0;
  for (string::const_iterator it = s.begin(); it != s.end(); it++) {
    ans += *it - '0';
  }
  cout << ans << endl;
}
