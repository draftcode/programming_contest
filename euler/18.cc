#include <iostream>
#include <sstream>
#include <gmpxx.h>
using namespace std;

int table[15][15];
int memo[15][15];

int find(int y, int x) {
  if (y == 14) return table[y][x];
  if (memo[y][x] != -1) return memo[y][x];

  int ret = 0;
  ret = max(ret, table[y][x] + find(y+1, x));
  ret = max(ret, table[y][x] + find(y+1, x+1));
  memo[y][x] = ret;
  return ret;
}

int main(void) {
  string input(
      " 75"
      " 95 64"
      " 17 47 82"
      " 18 35 87 10"
      " 20  4 82 47 65"
      " 19  1 23 75  3 34"
      " 88  2 77 73  7 63 67"
      " 99 65  4 28  6 16 70 92"
      " 41 41 26 56 83 40 80 70 33"
      " 41 48 72 33 47 32 37 16 94 29"
      " 53 71 44 65 25 43 91 52 97 51 14"
      " 70 11 33 28 77 73 17 78 39 68 17 57"
      " 91 71 52 38 17 14 91 43 58 50 27 29 48"
      " 63 66  4 68 89 53 67 30 73 16 69 87 40 31"
      "  4 62 98 27 23  9 70 98 73 93 38 53 60  4 23");
  istringstream is(input);

  for (int y = 0; y < 15; y++) {
    for (int x = 0; x <= y; x++) {
      is >> table[y][x];
      memo[y][x] = -1;
    }
  }

  cout << find(0, 0) << endl;
  return 0;
}

