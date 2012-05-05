// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Your task is to find the minimal positive integer x such that:
// 
// 1. x is an integer multiple of N.
// 
// 2. The decimal representation of x doesn't contain any forbidden digits.
// 
// You will be given the forbidden digits as a vector <int> forbiddenDigits.
// 
// 
// 
// If there is no solution, you should return the string "IMPOSSIBLE" (quotes 
// for clarity). 
// 
// If there is a solution and its number of digits is strictly less than 9, you 
// should return a string containing the integer x in base 10, with no leading 
// zeros.
// 
// Otherwise, you should return a string of the form "abc...def(g digits)" 
// (quotes for clarity). In the return value, abc are the first three digits of 
// the smallest valid integer x, def are its last three digits, and g is the 
// number of digits in x (a base-10 integer with no leading zeros). 
// 
// DEFINITION
// Class:MultiplesWithLimit
// Method:minMultiples
// Parameters:int, vector <int>
// Returns:string
// Method signature:string minMultiples(int N, vector <int> forbiddenDigits)
// 
// 
// CONSTRAINTS
// -N will be between 1 and 10000, inclusive.
// -forbiddenDigits will contain between 0 and 10 elements, inclusive.
// -Each element of forbiddenDigits will be between 0 and 9, inclusive.
// -The elements of forbiddenDigits will be pairwise distinct.
// 
// 
// EXAMPLES
// 
// 0)
// 8
// {2,3,4,5,6,7,8,9}
// 
// Returns: "1000"
// 
// The smallest positive multiple of 8 that only contains digits 0 and 1 is 1000.
// 
// 1)
// 9
// {1,3,4,5,6,7,8,9}
// 
// Returns: "222...222(9 digits)"
// 
// 
// 
// 2)
// 524
// {5,2,4}
// 
// Returns: "3668"
// 
// 
// 
// 3)
// 10000
// {0}
// 
// Returns: "IMPOSSIBLE"
// 
// 
// 
// 4)
// 1
// {0,1,2,3,4,5,6,7,8,9}
// 
// Returns: "IMPOSSIBLE"
// 
// 
// 
*/
// END CUT HERE
#line 86 "MultiplesWithLimit.cpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>
#include <set>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

class MultiplesWithLimit {
  int try_width(int N, int past, int w, vector<int> &usable) {
    if (w == 0) {
      if (past % N == 0) return past; else return 0;
    }

    past *= 10;
    for (vector<int>::const_iterator it = usable.begin(); it != usable.end(); it++) {
      int ret = try_width(N, past+(*it), w-1, usable);
      if (ret != 0) return ret;
    }

    return 0;
  }
  public:
    string minMultiples(int N, vector <int> forbiddenDigits) {
      int width = 0;
      int k = N;
      while (k != 0) {
        k /= 10; width++;
      }

      sort(forbiddenDigits.begin(), forbiddenDigits.end());
      vector<int>::const_iterator it = forbiddenDigits.begin();

      vector<int> usable;
      for (int i = 0; i < 10; i++) {
        if (*it == i) {
          it++;
        } else {
          usable.push_back(i);
        }
      }
      if (usable.size() == 0) return "IMPOSSIBLE";

      set<int> usable_set(usable.begin(), usable.end());
      int last_digit = N % 10;
      if (last_digit == 5) {
        if (usable_set.find(0) == usable_set.end()) {
          if (usable_set.find(5) == usable_set.end()) {
            return "IMPOSSIBLE";
          }
        }
      } else if (last_digit == 0) {
        if (usable_set.find(0) == usable_set.end()) {
          return "IMPOSSIBLE";
        }
      } else if (last_digit % 2 == 0) {
        if (usable_set.find(0) == usable_set.end()) {
          if (usable_set.find(2) == usable_set.end()) {
            if (usable_set.find(4) == usable_set.end()) {
              if (usable_set.find(6) == usable_set.end()) {
                if (usable_set.find(8) == usable_set.end()) {
                  return "IMPOSSIBLE";
                }
              }
            }
          }
        }
      }

      for (int w = width; w < 20; w++) {
        int t = try_width(N, 0, w, usable);
        if (t != 0) {
          ostringstream os;
          os << t;
          string ret = os.str();

          if (w < 9) {
            return ret;
          } else {
            ostringstream os;
            os << ret.substr(0,3) + "..." + ret.substr(ret.size()-3);
            os << '(' << ret.size() << " digits)";
            return os.str();
          }
        }
      }

      return "IMPOSSIBLE";
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; int Arr1[] = {2,3,4,5,6,7,8,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "1000"; verify_case(0, Arg2, minMultiples(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 9; int Arr1[] = {1,3,4,5,6,7,8,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "222...222(9 digits)"; verify_case(1, Arg2, minMultiples(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 524; int Arr1[] = {5,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "3668"; verify_case(2, Arg2, minMultiples(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10000; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "IMPOSSIBLE"; verify_case(3, Arg2, minMultiples(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 9116; int Arr1[] = {2,3,4,5,6,7,8,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "IMPOSSIBLE"; verify_case(4, Arg2, minMultiples(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  MultiplesWithLimit ___test;
  ___test.run_test(-1);
}
// END CUT HERE
