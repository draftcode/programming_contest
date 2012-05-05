// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
// You have several squares arranged in a single row. Each square is currently 
// painted red or green. You can choose any of the squares and paint it over 
// with either color. The goal is that, after painting, every red square is 
// further to the left than any of the green squares. We want you to do it 
// repainting the minimum possible number of squares.
// 
// Squares are numbered from left to right. You will be given the initial 
// arrangement as a string row, such that character i is 'R' if square i is red 
// or 'G' if square i is green. Return the minimum number of repaints needed to 
// achieve the goal.
// 
// 
// DEFINITION
// Class:RedAndGreen
// Method:minPaints
// Parameters:string
// Returns:int
// Method signature:int minPaints(string row)
// 
// 
// CONSTRAINTS
// -row will contain between 1 and 50 characters, inclusive.
// -Each character of row will be either 'R' or 'G'.
// 
// 
// EXAMPLES
// 
// 0)
// "RGRGR"
// 
// Returns: 2
// 
// Paint the squares in the marked positions in the picture below with the 
// opposite color. There are other ways with 2 total paints.
// 
// RGRGR
//  |  |
// RRRGG
// 
// 
// 1)
// "RRRGGGGG"
// 
// Returns: 0
// 
// There is no need to paint anything.
// 
// 2)
// "GGGGRRR"
// 
// Returns: 3
// 
// Paint all the red squares green.
// 
// 3)
// "RGRGRGRGRGRGRGRGR"
// 
// Returns: 8
// 
// 
// 
// 4)
// "RRRGGGRGGGRGGRRRGGRRRGR"
// 
// Returns: 9
// 
// 
// 
*/
// END CUT HERE
#line 76 "RedAndGreen.cpp"
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

class RedAndGreen {
  public:
    int minPaints(string row) {
      int m = 100;
      rep (greens, row.size() + 1) {
        int cost = 0;

        rep (i, row.size()) {
          if (i < greens) {
            if (row[i] == 'G') {
              cost++;
            }
          } else {
            if (row[i] == 'R') {
              cost++;
            }
          }
        }
        m = min(cost,m);
      }
      return m;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RGRGR"; int Arg1 = 2; verify_case(0, Arg1, minPaints(Arg0)); }
	void test_case_1() { string Arg0 = "RRRGGGGG"; int Arg1 = 0; verify_case(1, Arg1, minPaints(Arg0)); }
	void test_case_2() { string Arg0 = "GGGGRRR"; int Arg1 = 3; verify_case(2, Arg1, minPaints(Arg0)); }
	void test_case_3() { string Arg0 = "RGRGRGRGRGRGRGRGR"; int Arg1 = 8; verify_case(3, Arg1, minPaints(Arg0)); }
	void test_case_4() { string Arg0 = "RRRGGGRGGGRGGRRRGGRRRGR"; int Arg1 = 9; verify_case(4, Arg1, minPaints(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  RedAndGreen ___test;
  ___test.run_test(-1);
}
// END CUT HERE
