#include <iostream>
#include <vector>
using namespace std;
const double EPS = 0.0000001;

double expectation() {
  int N, M; cin >> N >> M;
  double prob = 0.0;
  vector<int> values;
  vector<double> probs;
  for (int i = 0; i < M; i++) {
    int V; double R; cin >> V >> R;
    values.push_back(V);
    probs.push_back(R);
    prob += R;
  }
  double exp = 0.0;
  for (int i = 0; i < M; i++) {
    exp += double(values[i]) * (probs[i] / prob);
  }
  return exp;
}

int main(void) {
  int T; cin >> T;

  double max_expectation = 0.0;
  for (int _ = 0; _ < T; _++)
    max_expectation = max(max_expectation, expectation());
  double exp = expectation();

  if (max_expectation - exp >= EPS) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
