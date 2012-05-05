// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
For strings x and y, we say y is a subsequence of x if y can be obtained from x by erasing some (possibly all or none) of the letters in x. For example, "tpcdr" is a subsequence of "topcoder", while "rt" is not. 

Given a string s, return the lexicographically largest subsequence of s. 


DEFINITION
Class:LargestSubsequence
Method:getLargest
Parameters:string
Returns:string
Method signature:string getLargest(string s)


NOTES
-For strings x and y, x is said to be lexicographically larger than y if y is a prefix of x or y has a smaller character than x at the first position where they differ. Order of characters is defined as the order of ASCII codes: 'a' < 'b' < ... < 'z'. 


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive. 
-Each character in s will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"test"

Returns: "tt"

All subsequences listed in lexicographical order are "" (empty string), "e", "es", "est", "et", "s", "st", "t", "te", "tes", "test", "tet", "ts", "tst" and "tt". So return "tt".

1)
"a"

Returns: "a"

There are only two subsequences, "" and "a". 

2)
"example"

Returns: "xple"



3)
"aquickbrownfoxjumpsoverthelazydog"

Returns: "zyog"



*/
// END CUT HERE
#line 60 "LargestSubsequence.cpp"
#include <sstream>
#include <algorithm>
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

class LargestSubsequence {
  public:
    string getLargest(string s) {
      string ret = "";
      each (it, s) {
        if (ret.size() == 0) {
          ret.push_back(*it);
        } else {
          string next_ret = "";
          bool inserted = false;
          each (iit, ret) {
            if (*iit < *it) {
              inserted = true;
              next_ret.push_back(*it);
              break;
            } else {
              next_ret.push_back(*iit);
            }
          }
          if (!inserted) {
            next_ret.push_back(*it);
          }
          ret = next_ret;
        }
      }
      return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "test"; string Arg1 = "tt"; verify_case(0, Arg1, getLargest(Arg0)); }
	void test_case_1() { string Arg0 = "a"; string Arg1 = "a"; verify_case(1, Arg1, getLargest(Arg0)); }
	void test_case_2() { string Arg0 = "example"; string Arg1 = "xple"; verify_case(2, Arg1, getLargest(Arg0)); }
	void test_case_3() { string Arg0 = "aquickbrownfoxjumpsoverthelazydog"; string Arg1 = "zyog"; verify_case(3, Arg1, getLargest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  LargestSubsequence ___test;
  ___test.run_test(-1);
}
// END CUT HERE
