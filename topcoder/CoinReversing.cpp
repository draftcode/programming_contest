// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You initially have N coins on the table, all with heads up. 
Given vector <int> a containing K integers, you first randomly choose a[0] coins and reverse them (from head to tail, or from tail to head), then randomly choose a[1] coins and reverse them, ..., and finally randomly choose a[K-1] coins and reverse them. 
Calculate and return the expected number of heads after these operations.

DEFINITION
Class:CoinReversing
Method:expectedHeads
Parameters:int, vector <int>
Returns:double
Method signature:double expectedHeads(int N, vector <int> a)


NOTES
-When you choose a specified number (say x) of coins, each combination of x coins has the same probability of being chosen. 
-The returned value must have an absolute or relative error less than 1e-9. 


CONSTRAINTS
-N will be between 1 and 1000, inclusive.
-a will contain between 1 and 50 elements, inclusive.
-Each element in a will be between 1 and N, inclusive.


EXAMPLES

0)
3
{2,2}

Returns: 1.6666666666666667

You first reverse 2 coins from heads to tails. Then you randomly choose 2 coins and reverse them. There are two possible situations that can occur on the second operation: 

Choosing 2 tails (which occurs with probability 1/3): it results in 3 heads. 
Choosing 1 head and 1 tail (which occurs with probability 2/3): it results in 1 head. 

So the expected number of heads is 1/3*3+2/3*1=5/3. 

1)
10
{10,10,10}

Returns: 0.0

You reverse every coin three times, so after the operations there will be 10 tails and no heads. 

2)
10
{2,7,1,8,2,8}

Returns: 4.792639999999999



3)
1000
{916,153,357,729,183,848,61,672,295,936}

Returns: 498.1980774932278



*/
// END CUT HERE
#line 69 "CoinReversing.cpp"
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

class CoinReversing {
  public:
    double expectedHeads(int N, vector <int> a) {
      double H = 1.0;
      each (it, a) {
        double P = (double)(*it)/N;
        H = H*(1.0-P) + (1.0-H)*P;
      }
      return H*N;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.6666666666666667; verify_case(0, Arg2, expectedHeads(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {10,10,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(1, Arg2, expectedHeads(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arr1[] = {2,7,1,8,2,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 4.792639999999999; verify_case(2, Arg2, expectedHeads(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1000; int Arr1[] = {916,153,357,729,183,848,61,672,295,936}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 498.1980774932278; verify_case(3, Arg2, expectedHeads(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  CoinReversing ___test;
  ___test.run_test(-1);
}
// END CUT HERE
