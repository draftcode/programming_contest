#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  vector<int> primes;
  primes.push_back(2);
  int count = 1;

  for (int i = 3;; i += 2) {
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
      cout << i << endl;
      primes.push_back(i);
      count++;
      if (count == 10001) {
        return 0;
      }
    }
  }

  return 0;
}
