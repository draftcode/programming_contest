// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Mr. Dengklek introduced you to an online programming contest called SRM 
// (Special Round Match)!
// 
// You are now in the coding phase of the contest. There are 3 problems in the 
// contest. You have practiced a lot before in practice rooms, so you are sure 
// that you can solve the first problem in skills[0] minutes, the second 
// problem in skills[1] minutes and the third problem is skills[2] minutes.
// 
// You have exactly 75 minutes to solve the problems. Before submitting a 
// solution to a problem, you must first open the problem. If you submit a 
// solution to a problem t minutes after you open the problem, you will receive:
// 
// (points[0] - 2t) points for the first problem, or
// (points[1] - 4t) points for the second problem, or
// (points[2] - 8t) points for the third problem.
// 
// 
// In your strategy, you only submit a solution to a problem after you solve 
// the problem. If you don't submit a solution to a problem, you will receive 
// zero points for the problem.
// 
// It is well-known that luck plays an important role in a contest. A fortune-
// teller told you that you have luck points of luck. You may use these points 
// to decrease the amount of time you need to solve the problems, in minutes. 
// Of course, you don't have to use all the points. Each point is worth one 
// minute per problem. So, if you initially can solve a problem in t minutes, 
// by using x points of luck (where x is a positive integer and 0 < x < t), you 
// can solve the problem in (t - x) minutes (it is impossible to use t or more 
// points of luck on the problem).
// 
// Arrange your strategy in this coding phase. Return the maximum total score 
// you can achieve in this coding phase.
// 
// DEFINITION
// Class:SRMCodingPhase
// Method:countScore
// Parameters:vector <int>, vector <int>, int
// Returns:int
// Method signature:int countScore(vector <int> points, vector <int> skills, 
// int luck)
// 
// 
// CONSTRAINTS
// -points will contain exactly 3 elements.
// -points[0] will be between 250 and 300, inclusive.
// -points[1] will be between 450 and 600, inclusive.
// -points[2] will be between 900 and 1100, inclusive.
// -skills will contain exactly 3 elements.
// -Each element of skills will be between 1 and 100, inclusive.
// -luck will be between 0 and 100, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {250, 500, 1000}
// {10, 25, 40}
// 0
// 
// Returns: 1310
// 
// You don't have any luck points. However, you can solve all the problems in 
// exactly 75 minutes.
// 
// 1)
// {300, 600, 900}
// {30, 65, 90}
// 25
// 
// Returns: 680
// 
// Use 25 luck points on the 600-point problem, and then solve the 300- and 600-
// point problems.
// 
// 2)
// {250, 550, 950}
// {10, 25, 40}
// 75
// 
// Returns: 1736
// 
// Using the large amount of luck points, solve each problem in only 1 minute.
// 
// 3)
// {256, 512, 1024}
// {35, 30, 25}
// 0
// 
// Returns: 1216
// 
// 
// 
// 4)
// {300, 600, 1100}
// {80, 90, 100}
// 4
// 
// Returns: 0
// 
// 
// 
*/
// END CUT HERE
#line 108 "SRMCodingPhase.cpp"
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

class SRMCodingPhase {
  public:
    int countScore(vector <int> points, vector <int> skills, int luck) {
      int max_point = 0;
      rep (i, 8) {
        int time_to_solve = 0;
        int point = 0;
        if ((i & 1) != 0) {
          time_to_solve += skills[0];
          point += points[0];
        }
        if ((i & 2) != 0) {
          time_to_solve += skills[1];
          point += points[1];
        }
        if ((i & 4) != 0) {
          time_to_solve += skills[2];
          point += points[2];
        }

        int luck_left = luck;
        if ((i & 4) != 0) {
          if (luck_left >= skills[2]) {
            luck_left -= skills[2] - 1;
            point -= 8;
            time_to_solve -= skills[2] - 1;
          } else {
            int t = skills[2] - luck_left;
            time_to_solve -= luck_left;
            luck_left = 0;
            point -= 8 * t;
          }
        }
        if ((i & 2) != 0) {
          if (luck_left >= skills[1]) {
            luck_left -= skills[1] - 1;
            point -= 4;
            time_to_solve -= skills[1] - 1;
          } else {
            int t = skills[1] - luck_left;
            time_to_solve -= luck_left;
            luck_left = 0;
            point -= 4 * t;
          }
        }
        if ((i & 1) != 0) {
          if (luck_left >= skills[0]) {
            luck_left -= skills[0] - 1;
            point -= 2;
            time_to_solve -= skills[0] - 1;
          } else {
            int t = skills[0] - luck_left;
            time_to_solve -= luck_left;
            luck_left = 0;
            point -= 2 * t;
          }
        }

        if (time_to_solve <= 75) {
          max_point = max(max_point, point);
        }
      }
      return max_point;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {250, 500, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 25, 40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 1310; verify_case(0, Arg3, countScore(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {300, 600, 900}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {30, 65, 90}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25; int Arg3 = 680; verify_case(1, Arg3, countScore(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {250, 550, 950}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 25, 40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 75; int Arg3 = 1736; verify_case(2, Arg3, countScore(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {256, 512, 1024}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {35, 30, 25}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 1216; verify_case(3, Arg3, countScore(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {300, 600, 1100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {80, 90, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 0; verify_case(4, Arg3, countScore(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {300, 600, 1100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100, 100, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = 1092; verify_case(5, Arg3, countScore(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  SRMCodingPhase ___test;
  ___test.run_test(-1);
}
// END CUT HERE
