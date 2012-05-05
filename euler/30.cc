#include <iostream>
#include <gmpxx.h>
using namespace std;

int tab[] = {0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049};

int main(void) {
  int sum = 0;
#pragma omp parallel for reduction(+:sum)
  for (int p = 10; p < 1000000; p++) {
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

