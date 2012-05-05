#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>
#include <map>
#include <set>

#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

enum TestResult {
  Permit, Deny, NotFiltered
};

struct Filter {
  string in, out;
  bool permit;
  Filter(string in, string out, bool permit) : in(in), out(out), permit(permit) {}

  TestResult test(string testin, string testout) {
    for (int i = 0; i < in.size(); i++) {
      if (in[i] != '?' && in[i] != testin[i]) {
        return NotFiltered;
      }
    }

    for (int i = 0; i < out.size(); i++) {
      if (out[i] != '?' && out[i] != testout[i]) {
        return NotFiltered;
      }
    }

    if (permit) {
      return Permit;
    } else {
      return Deny;
    }
  }
};

int N, M;
vector<Filter> filters;
int main(void) {
  ios::sync_with_stdio(false);
  for (;;) {
    cin >> N >> M;
    if (N == 0 && M == 0) break;
    filters.clear();

    for (int i = 0; i < N; i++) {
      string permit, in, out; bool p;
      cin >> permit >> in >> out;
      p = (permit == "permit");
      filters.push_back(Filter(in, out, p));
    }

    int output = 0;
    ostringstream os;
    for (int m = 0; m < M; m++) {
      string in, out, message;
      cin >> in >> out >> message;
      enum TestResult res = NotFiltered;
      for (int i = filters.size()-1; i >= 0; i--) {
        res = filters[i].test(in, out);
        if (res != NotFiltered) break;
      }

      if (res == Permit) {
        output++;
        os << in << ' ' << out << ' ' << message << endl;
      }
    }

    cout << output << endl << os.str();
  }
  return 0;
}
