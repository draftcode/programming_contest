#include <map>
#include <iostream>
using namespace std;

int main(void) {
  map<long, long> m;

  long ans = 0;
  long ans2 = 0;
  for (long num = 1; num < 1000000; num++) {
    long k = num;
    long count = 0;
    while (k != 1) {
      if (m.find(k) != m.end()) {
        count += m[k];
        break;
      } else {
        count++;
        if (k % 2 == 0) {
          k /= 2;
        } else {
          k = 3*k + 1;
        }
      }
    }
    m[num] = count;
    if (ans < count) {
      ans = count;
      ans2 = num;
    }
  }
  cout << ans2 << endl;
}
