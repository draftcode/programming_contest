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

const int A = 0;
const int B = 1;
const int C = 2;
const int D = 3;
const int E = 4;
const int It = 5;

const int Divine = 0;
const int Human = 1;
const int Evil = 2;
const int Lying = 3;
const int Day = 4;
const int Night = 5;

struct Question {
  int speaker;
  int target;
  bool inverse;
  int kind;
  Question(int s, int t, bool i, int k) : speaker(s), target(t), inverse(i), kind(k) {}
};

bool check(vector<Question> &q, vector<int> &fact) {
  for (vector<Question>::iterator it = q.begin(); it != q.end(); it++) {
    bool is_ = true;
    if (fact[it->speaker] == Evil || (fact[it->speaker] == Human && fact[It] == Night)) {
      is_ = false;
    }
    if (it->inverse) {
      is_ = !is_;
    }

    if (it->kind == Lying) {
      if ((   (fact[it->target] == Evil)
           || (fact[it->target] == Human && fact[It] == Night)) == is_) {
        continue;
      }
    } else {
      if ((fact[it->target] == it->kind) == is_) {
        continue;
      }
    }
    return false;
  }
  return true;
}

int main(void) {
  int conv = 1;
  for (;; conv++) {
    int N; cin >> N; if (N == 0) break;

    vector<Question> q;
    for (int i = 0; i < N; i++) {
      string s;
      cin >> s;
      char who = s[0] - 'A';

      cin >> s;
      if (s == "It") {
        cin >> s;
        cin >> s;
        if (s == "day.") {
          q.push_back(Question(who, It, false, Day));
        } else {
          q.push_back(Question(who, It, false, Night));
        }
      } else {
        char target;
        if (s == "I") {
          target = who;
        } else {
          target = s[0] - 'A';
        }
        cin >> s;
        cin >> s;
        bool inv = false;
        if (s == "not") {
          cin >> s;
          inv = true;
        }
        if (s == "divine.") {
          q.push_back(Question(who, target, inv, Divine));
        } else if (s == "human.") {
          q.push_back(Question(who, target, inv, Human));
        } else if (s == "evil.") {
          q.push_back(Question(who, target, inv, Evil));
        } else if (s == "lying.") {
          q.push_back(Question(who, target, inv, Lying));
        }
      }
    }

    vector<vector<int> > probs;
    for (int a = 0; a <= 2; a++)
      for (int b = 0; b <= 2; b++)
        for (int c = 0; c <= 2; c++)
          for (int d = 0; d <= 2; d++)
            for (int e = 0; e <= 2; e++)
              for (int day = 4; day <= 5; day++) {
                const int f[] = {a, b, c, d, e, day};
                vector<int> fact(f, f+6);
                if (check(q, fact)) {
                  probs.push_back(fact);
                }
              }

    printf("Conversation #%d\n", conv);
    if (probs.size() == 0) {
      printf("This is impossible.\n");
    } else {
      int fixcount = 0;
      for (int i = 0; i < 5; i++) {
        bool fix = true;
        for (int k = 1; k < probs.size(); k++) {
          if (probs[k-1][i] != probs[k][i]) {
            fix = false;
            break;
          }
        }

        if (fix) {
          fixcount++;
          const char names[] = {'A', 'B', 'C', 'D', 'E'};
          const char* const kinds[] = {"divine", "human", "evil"};
          printf("%c is %s.\n", names[i], kinds[probs[0][i]]);
        }
      }
      {
        bool fix = true;
        for (int k = 1; k < probs.size(); k++) {
          if (probs[k-1][It] != probs[k][It]) {
            fix = false;
            break;
          }
        }
        if (fix) {
          fixcount++;
          if (probs[0][It] == Day) {
            printf("It is day.\n");
          } else {
            printf("It is night.\n");
          }
        }
      }

      if (fixcount == 0) {
        printf("No facts are deducible.\n");
      }
    }
    printf("\n");
  }
  return 0;
}
