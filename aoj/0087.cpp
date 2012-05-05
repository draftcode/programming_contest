#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <stack>

#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(void) {
  string line;
  while (getline(cin, line)) {
    stack<double> stk;
    string::const_iterator it = line.begin();
    while (it != line.end()) {
      if (isdigit(*it) || (*it == '-' && isdigit(*(it+1)))) {
        int inverse = 1;
        if (*it == '-') {
          inverse = -1; it++;
        }
        int num = 0;
        while (isdigit(*it)) {
          num *= 10; num += *it - '0'; it++;
        }
        stk.push(num*inverse);
      } else if (*it == ' ') {
        it++;
      } else {
        double b = stk.top(); stk.pop();
        double a = stk.top(); stk.pop();
        if (*it == '+') {
          stk.push(a+b);
        } else if (*it == '-') {
          stk.push(a-b);
        } else if (*it == '*') {
          stk.push(a*b);
        } else if (*it == '/') {
          stk.push(a/b);
        }
        it++;
      }
    }
    printf("%.6f\n", stk.top());
  }
  return 0;
}
