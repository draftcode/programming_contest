#include <vector>
#include <iostream>
using namespace std;

int main (void) {
  int num = 0;
  for (int i = 1;; i++) {
    num += i;

    int count = 1;
    int t = num;
    bool first = true;
    for (int k = 2; t != 1; k++) {
      int kcount = 1;
      while (t % k == 0) {
        kcount++;
        t /= k;
      }

      count *= kcount;
    }

    if (count >= 500) {
      cout << num << ' ' << count << endl;
      return 0;
    } else {
      cout << num << ' ' << count << endl;
    }
  }
  return 1;
}
