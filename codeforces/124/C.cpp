#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int primes[500];
void calc_primes(void) {
  primes[0] = 2;
  int count = 1;
  for (int i = 3; i < 1000 && count < 500; i+=2) {
    bool isprime = true;
    for (int k = 0; k < count; k++) {
      if (primes[k] * primes[k] > i) break;
      if (i % primes[k] == 0) {
        isprime = false;
        break;
      }
    }

    if (isprime) {
      primes[count++] = i;
    }
  }
}

string s;
int len;
int counts[26];

int main(void) {
  ios::sync_with_stdio(false);
  calc_primes();

  cin >> s;
  len = s.size();
  string ans(len, ' ');

  int max_count = 0;
  char max_char = ' ';
  for (int i = 0; i < len; i++) {
    counts[s[i]-'a']++;
    if (counts[s[i]-'a'] > max_count) {
      max_count = counts[s[i]-'a'];
      max_char = s[i];
    }
  }

  for (int i = 1; i*2 <= len; i++) {
    ans[2*i-1] = max_char;
    counts[max_char-'a']--;
    if (counts[max_char-'a'] < 0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  for (int k = 1; k < 500; k++) {
    if (primes[k]*2 > len) {
      break;
    }
    for (int i = 1; i*primes[k] <= len; i++) {
      if (ans[i*primes[k]-1] == ' ') {
        ans[i*primes[k]-1] = max_char;
        counts[max_char-'a']--;
        if (counts[max_char-'a'] < 0) {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
  }
  cout << "YES" << endl;

  char c = 'a';
  for (int i = 0; i < len; i++) {
    if (ans[i] == ' ') {
      while (counts[c-'a'] == 0) {
        c++;
      }
      ans[i] = c;
      counts[c-'a']--;
    }
  }
  cout << ans << endl;

  return 0;
}
