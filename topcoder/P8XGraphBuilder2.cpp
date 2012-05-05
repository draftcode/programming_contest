// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly 
// if viewed outside of the applet.
// 
// You want to build a graph consisting of N nodes and N-1 edges. The graph 
// must be connected. That is, for each pair of nodes there must be some 
// sequence of edges that connects them. For example, the following picture 
// shows a connected graph with N=5 nodes (dots) and N-1=4 edges (lines 
// connecting pairs of dots):
// 
// 
// 
// An edge is adjacent to the two nodes that it connects. The degree of a node 
// in the graph is equal to the number of edges adjacent to the node. For 
// example, the degree of node A in the picture above is 3, while the degree of 
// node B is 1. Note that in your graph the degree of each node will be between 
// 1 and N-1, inclusive.
// 
// You are given a vector <int> scores with N-1 elements. The score of a node 
// with degree d is scores[d-1]. The score of a graph is the sum of the scores 
// of its nodes.
// 
// Your method should compute and return the maximum possible score for a graph 
// you can construct.
// 
// 
// DEFINITION
// Class:P8XGraphBuilder
// Method:solve
// Parameters:vector <int>
// Returns:int
// Method signature:int solve(vector <int> scores)
// 
// 
// NOTES
// -In your solution, the number of nodes N in your graph can be determined as 
// one plus the length of scores.
// -In your graph, there must be at most one edge connecting any pair of nodes, 
// and an edge cannot connect a node with itself.
// 
// 
// CONSTRAINTS
// -scores will contain between 1 and 50 elements, inclusive.
// -Each element in scores will be between 0 and 10,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {1, 3, 0}
// 
// Returns: 8
// 
// As scores contains 3 elements, we are building a graph with N=4 nodes. Nodes 
// of degree 1 have score 1, nodes of degree 2 have score 3, and nodes of 
// degree 3 have score 0.
// One possible graph with the highest score looks as follows:
// 
// 
// 
// In this graph the degrees of the nodes are 1, 2, 2, 1, respectively. The sum 
// of their scores is 1+3+3+1 = 8.
// 
// 1)
// {0, 0, 0, 10}
// 
// Returns: 10
// 
// One possible solution for this test case is:
// 
// 
// 2)
// {1, 2, 3, 4, 5, 6}
// 
// Returns: 12
// 
// 
// 
// 3)
// {5, 0, 0}
// 
// Returns: 15
// 
// 
// 
// 4)
// {1, 3, 2, 5, 3, 7, 5}
// 
// Returns: 20
// 
// 
// 
*/
// END CUT HERE
#line 98 "P8XGraphBuilder.cpp"
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

class P8XGraphBuilder {
  int nsize;
  public:
    int f(vector<int> &scores, int nv, int ne) {
      if (nv == nsize) return scores[ne];

      int ret = 0;
      for (int i = 0; i <= ne; i++) {
        ret = max(ret, scores[i]+f(scores, nv+1, ne-i));
      }
      return ret;
    }
    int solve(vector <int> scores) {
      int nVertex = scores.size() + 1;
      int nEdge = nVertex;
      nsize = nVertex-1;
      int osx = nVertex-2;

      return f(scores, 0, osx);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 3, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 0, 0, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { int Arr0[] = {5, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 3, 2, 5, 3, 7, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(4, Arg1, solve(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  P8XGraphBuilder ___test;
  ___test.run_test(-1);
}
// END CUT HERE
