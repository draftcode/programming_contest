// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Mr. Dengklek introduced you to an online programming contest called SRM 
// (Special Round Match)!
// 
// There are N coders in the contest, including you. Each coder has a skill 
// measurement called rating. This information is given in ratings, where 
// ratings[0] is your rating and ratings[1] through ratings[N-1] are the 
// ratings of the other coders. Ratings of all coders are pairwise distinct.
// 
// You are now in the room assignment phase of the contest. There are K 
// available rooms. Each coder will be assigned to exactly one room in the 
// following way: the coders, in descending order of their ratings, are 
// assigned one-by-one to rooms 1, 2, ..., K, 1, 2, ..., K, ... and so on in 
// that order. See the examples for further clarification.
// 
// You wish to win your room, so you wonder how many stronger competitors you 
// have. Return the number of coders in your room who have higher ratings than 
// yours.
// 
// DEFINITION
// Class:SRMRoomAssignmentPhase
// Method:countCompetitors
// Parameters:vector <int>, int
// Returns:int
// Method signature:int countCompetitors(vector <int> ratings, int K)
// 
// 
// CONSTRAINTS
// -ratings will contain between 2 and 50 elements, inclusive.
// -Each element of ratings will be between 0 and 1199, inclusive.
// -All elements of ratings will be distinct.
// -K will be between 1 and the number of elements in ratings, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {491, 981, 1199, 763, 994, 879, 888}
// 3
// 
// Returns: 2
// 
// Here is the room assignment for all coders.
// 
// Room 1 coders' ratings:
// 
// 1199
// 888
// 491
// 
// 
// Room 2 coders' ratings:
// 
// 994
// 879
// 
// 
// Room 3 coders' ratings:
// 
// 981
// 763
// 
// 
// You are in Room 1, and there are 2 coders with greater ratings than yours.
// 
// 
// 
// 1)
// {1024, 1000, 600}
// 1
// 
// Returns: 0
// 
// You are the highest rated coder in Room 1.
// 
// 2)
// {505, 679, 900, 1022}
// 2
// 
// Returns: 1
// 
// You are the lowest rated coder in Room 2.
// 
// 3)
// {716, 58, 1000, 1004, 912, 822, 453, 1100, 558}
// 3
// 
// Returns: 1
// 
// You are the second highest rated coder in Room 3.
// 
// 4)
// {422, 623, 1023, 941, 882, 776, 852, 495, 803, 622, 618, 532, 751, 500}
// 4
// 
// Returns: 3
// 
// 
// 
// 5)
// {1197, 1198, 1196, 1195, 1199}
// 1
// 
// Returns: 2
// 
// 
// 
*/
// END CUT HERE
#line 113 "SRMRoomAssignmentPhase.cpp"
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

class SRMRoomAssignmentPhase {
  public:
    int countCompetitors(vector <int> ratings, int K) {
      int myself = ratings[0];
      sort(ratings.begin(), ratings.end());
      vector<int>::iterator it = lower_bound(ratings.begin(), ratings.end(), myself);
      int ans = 0;
      while (it != ratings.end()) {
        bool b = true;
        rep (i, K) {
          it++;
          if (it == ratings.end()) {
            b = false;
            break;
          }
        }
        if (b) {
          ans++;
        } else {
          break;
        }
      }
      return ans;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {491, 981, 1199, 763, 994, 879, 888}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; verify_case(0, Arg2, countCompetitors(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1024, 1000, 600}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, countCompetitors(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {505, 679, 900, 1022}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; verify_case(2, Arg2, countCompetitors(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {716, 58, 1000, 1004, 912, 822, 453, 1100, 558}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 1; verify_case(3, Arg2, countCompetitors(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {422, 623, 1023, 941, 882, 776, 852, 495, 803, 622, 618, 532, 751, 500}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; verify_case(4, Arg2, countCompetitors(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1197, 1198, 1196, 1195, 1199}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(5, Arg2, countCompetitors(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  SRMRoomAssignmentPhase ___test;
  ___test.run_test(-1);
}
// END CUT HERE
