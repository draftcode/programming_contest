#include <iostream>
#include <gmpxx.h>
using namespace std;

int tab[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int main(void) {
  int sum = 0;
#pragma omp parallel for reduction(+:sum)
  for (int p = 3; p < 10000000; p++) {
    int s = 0;
    int i = p;
    while (i != 0) {
      s += tab[i%10];
      i /= 10;
    }

    if (s == p) {
      sum += p;
    }
  }

  cout << sum << endl;
  return 0;
}

