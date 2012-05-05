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

#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int N;

vector<int> g(int target, int prev_j) {
  vector<int> ret;
  if (target < 10) {
    if (target != 0 && target == prev_j) {
      ret.push_back(target);
    }
    return ret;
  }

  if ((target%10) - prev_j >= 0) {
    int next_j = (target%10) - prev_j;
    vector<int> v = g(target/10, next_j);
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
      ret.push_back(*it * 10 + prev_j);
    }
  } else {
    int next_j = (target%10) - prev_j + 10;
    target -= 10;
    vector<int> v = g(target/10, next_j);
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
      ret.push_back(*it * 10 + prev_j);
    }
  }
  return ret;
}

vector<int> f(int target) {
  vector<int> ret;
  if (target < 10) {
    if (target != 0) {
      ret.push_back(target);
    }
    return ret;
  }

  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      if ((i+j)%10 == target%10) {
        if (i == j) {
          vector<int> v = f(target/10 - (i+j)/10);
          for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
            ret.push_back(*it * 10 + i);
          }
        } else {
          vector<int> v = g(target/10 - (i+j)/10, j);
          for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
            ret.push_back(*it * 10 + i);
          }
        }
      }
    }
  }

  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin >> N;
  vector<int> v = f(N);
  sort(v.begin(), v.end());

  printf("%lu\n", v.size());
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    int len = 0;
    int a = *it;
    while (a != 0) {
      a /= 10;
      len++;
    }

    int b = N - *it;
    while (b != 0) {
      b /= 10;
      len--;
    }

    printf("%d + ", *it);
    for (int i = 1; i < len; i++) {
      putchar('0');
    }
    if (N-*it != 0) {
      printf("%d = %d\n", N - *it, N);
    } else {
      printf(" = %d\n", N);
    }
  }

  return 0;
}
