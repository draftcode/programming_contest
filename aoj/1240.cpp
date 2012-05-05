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

void rotate_right(string &message) {
  message = message.substr(message.size()-1) + message.substr(0, message.size()-1);
}

void rotate_left(string &message) {
  message = message.substr(1) + message.substr(0, 1);
}

void swap_half(string &message) {
  if (message.size() % 2 == 0) {
    message = message.substr(message.size()/2)
      + message.substr(0, message.size()/2);
  } else {
    message = message.substr(message.size()/2+1)
      + message.substr(message.size()/2, 1)
      + message.substr(0, message.size()/2);
  }
}

void reverse_all(string &message) {
  reverse(message.begin(), message.end());
}

void decrement_digit(string &message) {
  for (int i = 0; i < message.size(); i++) {
    if (isdigit(message[i])) {
      int t = message[i] - '0' - 1;
      if (t < 0) t += 10;
      message[i] = t + '0';
    }
  }
}

void increment_digit(string &message) {
  for (int i = 0; i < message.size(); i++) {
    if (isdigit(message[i])) {
      int t = message[i] - '0' + 1;
      message[i] = (t % 10) + '0';
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  int N; cin >> N;
  for (int _ = 0; _ < N; _++) {
    string command, message;
    cin >> command >> message;
    for (int c = command.size()-1; c >= 0; c--) {
      switch (command[c]) {
        case 'J': rotate_right(message); break;
        case 'C': rotate_left(message); break;
        case 'E': swap_half(message); break;
        case 'A': reverse_all(message); break;
        case 'P': decrement_digit(message); break;
        case 'M': increment_digit(message); break;
      }
    }
    cout << message << endl;
  }
  return 0;
}
