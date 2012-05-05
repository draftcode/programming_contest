// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
// Given a set of points in the XY plane and an integer n, a subset P of those 
// points is called n-squared if it is not empty and there exists a square of 
// side n in the XY plane with its sides parallel to the axes such that a point 
// is in P if and only if it is contained within the square. A point lying on a 
// side or a vertex of the square is considered to be contained in it.
// 
// You will be given n as explained in the input. You will also be given two 
// vector <int>s x and y such that the coordinates of point i are (x[i],y[i]). 
// Return the number of n-squared subsets in the input set described by x and y.
// 
// 
// DEFINITION
// Class:SquaredSubsets
// Method:countSubsets
// Parameters:int, vector <int>, vector <int>
// Returns:long long
// Method signature:long long countSubsets(int n, vector <int> x, vector <int> y)
// 
// 
// CONSTRAINTS
// -n will be between 1 and 100000000 (10^8), inclusive.
// -x and y will contain between 1 and 50 elements, inclusive.
// -x and y will contain the same number of elements.
// -Each element of x and y will be between -100000000 (-10^8) and 100000000 
// (10^8), inclusive.
// -All described points will be different.
// 
// 
// EXAMPLES
// 
// 0)
// 5
// {-5,0,5}
// {0,0,0}
// 
// Returns: 5
// 
// The following subsets are squared: {(-5,0)}, {(0,0)}, {(5,0)}, {(-5,0),
// (0,0)}, {(0,0),(5,0)}.
// 
// 1)
// 10
// {-5,0,5}
// {0,0,0}
// 
// Returns: 5
// 
// The following subsets are squared: {(-5,0)}, {(5,0)}, {(0,0),(5,0)}, {(-5,0),
// (0,0)}, {(-5,0),(0,0),(5,0)}.
// 
// 2)
// 100000000
// {-1,-1,-1,0,1,1,1}
// {-1,0,1,1,-1,0,1}
// 
// Returns: 21
// 
// 
// 
// 3)
// 5
// {5,3,6,2,1,6,4,4,7,-1,-4,-7,2,-2,0}
// {0,-1,8,-5,2,5,-8,8,-6,4,3,2,7,3,5}
// 
// Returns: 66
// 
// 
// 
// 4)
// 1
// {-1,0}
// {0,0}
// 
// Returns: 3
// 
// 
// 
*/
// END CUT HERE
#line 85 "SquaredSubsets.cpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <climits>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

class SquaredSubsets {
  public:
    long long countSubsets(int n, vector <int> x, vector <int> y) {
      int sz = x.size();

      for (int ur = 0; ur < sz; ur++) {
        int urx = x[ur], ury = y[ur];
        for (int i = 0; i < sz; i++) {
          if (urx < x[i] && ury < y[i]) {
          }
        }
      }

      ll ans = 0;
      for (int points = 1; points < sz; points++) {
        for (int i = 0; i + points <= sz; i++) {
          int x_min = INT_MAX, x_max = 0, y_min = INT_MAX, y_max = 0;
          for (int r = i; r < i+points; r++) {
            x_min = min(v[r].first, x_min);
            x_max = max(v[r].first, x_max);
            y_min = min(v[r].second, y_min);
            y_max = max(v[r].second, y_max);
          }

          if (x_max - x_min <= n && y_max - y_min <= n) {
            for (int k = 0; k < i; k++) {
              if (
            }
            ans++;
          }
        }
      }
      return ans;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {-5,0,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 5LL; verify_case(0, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {-5,0,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 5LL; verify_case(1, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 100000000; int Arr1[] = {-1,-1,-1,0,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-1,0,1,1,-1,0,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 21LL; verify_case(2, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arr1[] = {5,3,6,2,1,6,4,4,7,-1,-4,-7,2,-2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,-1,8,-5,2,5,-8,8,-6,4,3,2,7,3,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 66LL; verify_case(3, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arr1[] = {-1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 3LL; verify_case(4, Arg3, countSubsets(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  SquaredSubsets ___test;
  ___test.run_test(-1);
}
// END CUT HERE
