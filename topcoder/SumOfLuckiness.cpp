// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Mr. Dengklek once told you that 4 and 7 are lucky numbers. He also defined 
// the luckiness of a positive integer as the absolute difference between the 
// number of 7s in its decimal representation and the number of 4s in its 
// decimal representation. For example, for each of the numbers 23, 47 and 
// 47714 the luckiness is 0, and for each of the numbers 4474 and 7070 the 
// luckiness is 2.
// 
// You are given two ints A and B. Return the sum of luckiness of all integers 
// between A and B, inclusive.
// 
// 
// DEFINITION
// Class:SumOfLuckiness
// Method:theSum
// Parameters:int, int
// Returns:ll
// Method signature:ll theSum(int A, int B)
// 
// 
// CONSTRAINTS
// -A will be between 1 and 2,000,000,000, inclusive.
// -B will be between A and 2,000,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// 10
// 
// Returns: 2
// 
// The luckiness of 4 is 1. The luckiness of 7 is 1. The luckiness of the other 
// numbers is 0. So, the sum of luckiness is 2.
// 
// 1)
// 40
// 47
// 
// Returns: 8
// 
// The luckiness of 40, 41, 42, 43, 45, and 46 is 1. The luckiness of 44 is 2. 
// The luckiness of 47 is 0.
// 
// 2)
// 58
// 526
// 
// Returns: 231
// 
// 
// 
// 3)
// 4444
// 7777
// 
// Returns: 2338
// 
// 
// 
// 4)
// 585858585
// 858585858
// 
// Returns: 287481025
// 
// 
// 
*/
// END CUT HERE
#line 75 "SumOfLuckiness.cpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

class SumOfLuckiness {
  public:
    ll pow8[11];
    ll C[11][11];
    ll howmany(int n4, int n7, int B) {
      ostringstream os; os << B; string s = os.str();
      int n = s.size();
      ll sum = 0;
      for (int i = 0; i < n; i++) {
        for (char d = '0'; d < s[i]; d++) {
          int r4 = n4;
          int r7 = n7;

          if (d == '4') r4--;
          if (d == '7') r7--;

          int rem = n - i - 1;
          if (r4 >= 0 && r7 >= 0 && r4+r7 <= rem) {
            sum += C[rem][r4] * C[rem-r4][r7] * pow8[rem-r4-r7];
          }
        }
        if (s[i] == '4') n4--;
        if (s[i] == '7') n7--;
      }
      cerr << sum << endl;
      return sum;
    }

    ll sum(int B) {
      ll sum = 0;
      for (int n4 = 0; n4 <= 10; n4++) {
        for (int n7 = 0; n4+n7 <= 10; n7++) {
          sum += abs(n7 - n4) * howmany(n4, n7, B+1);
        }
      }
      return sum;
    }

    ll theSum(int A, int B) {
      pow8[0] = 1;
      for (int i = 1; i <= 10; i++) {
        pow8[i] = 8 * pow8[i-1];
      }

      for (int i = 0; i <= 10; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
          C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
      }
      return sum(B) - sum(A-1);
    }

    // BEGIN CUT HERE
  public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
  private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const ll &Expected, const ll &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 1; int Arg1 = 10; ll Arg2 = 2LL; verify_case(0, Arg2, theSum(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 40; int Arg1 = 47; ll Arg2 = 8LL; verify_case(1, Arg2, theSum(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 58; int Arg1 = 526; ll Arg2 = 231LL; verify_case(2, Arg2, theSum(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 4444; int Arg1 = 7777; ll Arg2 = 2338LL; verify_case(3, Arg2, theSum(Arg0, Arg1)); }
    void test_case_4() { int Arg0 = 585858585; int Arg1 = 858585858; ll Arg2 = 287481025LL; verify_case(4, Arg2, theSum(Arg0, Arg1)); }

    // END CUT HERE

};

// BEGIN CUT HERE
int main() {
  SumOfLuckiness ___test;
  ___test.run_test(-1);
}
// END CUT HERE
