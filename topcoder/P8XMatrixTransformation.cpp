// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly 
// if viewed outside of the applet.
// 
// You are given two vector <string>s original and target, which are two 
// rectangular matrices with the same dimensions. Each character in the 
// matrices will be either '0' or '1'. You want to transform original into 
// target. You are only allowed to use one type of operations: Pick either a 
// single row or a single column, and permute all its characters arbitrarily. 
// You may use as many operations as you want to, one after another.
// 
// Is it possible to transform original into target by using the allowed 
// operations only? Return "YES" if it's possible, "NO" otherwise (quotes for 
// clarity).
// 
// DEFINITION
// Class:P8XMatrixTransformation
// Method:solve
// Parameters:vector <string>, vector <string>
// Returns:string
// Method signature:string solve(vector <string> original, vector <string> 
// target)
// 
// 
// NOTES
// -Permuting the characters means rearranging them into a new order.
// 
// 
// CONSTRAINTS
// -original will contain between 1 and 50 elements, inclusive.
// -Each element of original will contain between 1 and 50 characters, inclusive.
// -All the elements of original will contain the same number of characters.
// -Each character in each element of original will be either '0' or '1'.
// -target will contain exactly R elements, where R is the number of elements 
// in original.
// -Each element of target will contain exactly C characters, where C is the 
// number of characters in original[0].
// -Each character in each element of target will be either '0' or '1'.
// 
// 
// EXAMPLES
// 
// 0)
// {"01"
// ,"11"}
// {"11"
// ,"10"}
// 
// Returns: "YES"
// 
// For example, you can apply the following operations:
// 
// That is, you can first permute the first row and then the second column in 
// the way shown above.
// 
// 1)
// {"0111"
// ,"0011"}
// {"1011"
// ,"1100"}
// 
// Returns: "YES"
// 
// 
// 
// 2)
// {"0"}
// {"1"}
// 
// Returns: "NO"
// 
// 
// 
// 3)
// {"1111"
// ,"1111"
// ,"0000"
// ,"0000"}
// {"1111"
// ,"1111"
// ,"0000"
// ,"0000"}
// 
// Returns: "YES"
// 
// 
// 
// 4)
// {"0110"
// ,"1001"
// ,"0110"}
// {"1111"
// ,"0110"
// ,"0000"}
// 
// Returns: "YES"
// 
// 
// 
// 5)
// {"0000"
// ,"1111"
// ,"0000"}
// {"1111"
// ,"0000"
// ,"1111"}
// 
// Returns: "NO"
// 
// 
// 
*/
// END CUT HERE
#line 117 "P8XMatrixTransformation.cpp"
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

class P8XMatrixTransformation {
  public:
    string solve(vector <string> original, vector <string> target) {
      int a = 0, b = 0;
      for (int i = 0; i < original.size(); i++) {
        for (int j = 0; j < original[0].size(); j++) {
          if (original[i][j] == '1') a++;
        }
      }

      for (int i = 0; i < target.size(); i++) {
        for (int j = 0; j < target[0].size(); j++) {
          if (target[i][j] == '1') b++;
        }
      }

      if (a == b) {
        return "YES";
      } else {
        return "NO";
      }
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"01"
,"11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"11"
,"10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YES"; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"0111"
,"0011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1011"
,"1100"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YES"; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"1111"
,"1111"
,"0000"
,"0000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1111"
,"1111"
,"0000"
,"0000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YES"; verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"0110"
,"1001"
,"0110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1111"
,"0110"
,"0000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YES"; verify_case(4, Arg2, solve(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"0000"
,"1111"
,"0000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1111"
,"0000"
,"1111"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(5, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  P8XMatrixTransformation ___test;
  ___test.run_test(-1);
}
// END CUT HERE
