// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You are given a string s.  Return the shortest string which contains s as a contiguous substring twice.

Note that two occurrences of s may overlap. For example, "ababa" contains "aba" twice.


DEFINITION
Class:TwiceString
Method:getShortest
Parameters:string
Returns:string
Method signature:string getShortest(string s)


NOTES
-The shortest string which contains s as a contiguous substring twice is always unique.


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive. 
-Each character in s will be a lowercase letter ('a'-'z').  


EXAMPLES

0)
"aba"

Returns: "ababa"

This is the example shown in the problem statement. 

1)
"xxxxx"

Returns: "xxxxxx"



2)
"topcoder"

Returns: "topcodertopcoder"



3)
"abracadabra"

Returns: "abracadabracadabra"



*/
// END CUT HERE
#line 60 "TwiceString.cpp"
#include <algorithm>
#include <sstream>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <vector>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

class TwiceString {
  public:
    string getShortest(string s) {
      int len = s.size();
      string t = s;
      for (int i = 1; i < len; i++) {
        if (s.substr(len-i,i) == s.substr(0,i)) {
          t = s.substr(i, len);
        }
      }
      return s+t;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aba"; string Arg1 = "ababa"; verify_case(0, Arg1, getShortest(Arg0)); }
	void test_case_1() { string Arg0 = "xxxxx"; string Arg1 = "xxxxxx"; verify_case(1, Arg1, getShortest(Arg0)); }
	void test_case_2() { string Arg0 = "topcoder"; string Arg1 = "topcodertopcoder"; verify_case(2, Arg1, getShortest(Arg0)); }
	void test_case_3() { string Arg0 = "abracadabra"; string Arg1 = "abracadabracadabra"; verify_case(3, Arg1, getShortest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char* argv[])
{
  TwiceString ___test;
  ___test.run_test(-1);
}
// END CUT HERE
