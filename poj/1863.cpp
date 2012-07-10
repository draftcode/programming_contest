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
typedef unsigned long long ll;
typedef pair<int, int> P;

string add(string s, string t) {
  if (s.size() < t.size()) {
    s = string(t.size() - s.size(), '0') + s;
  } else if (s.size() > t.size()) {
    t = string(s.size() - t.size(), '0') + t;
  }
  // cout << s << " + " << t << " = ";

  int addr = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    int k = (s[i] - '0') + (t[i] - '0') + addr;
    s[i] = (k % 10) + '0';
    addr = k / 10;
  }
  if (addr != 0) {
    s = string(1, addr + '0') + s;
  }

  // cout << s << endl;
  return s;
}

string sub(string s, string t) {
  if (s.size() < t.size()) {
    s = string(t.size() - s.size(), '0') + s;
  } else if (s.size() > t.size()) {
    t = string(s.size() - t.size(), '0') + t;
  }
  // cout << s << " - " << t << " = ";

  int addr = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    int k = (s[i] - '0') - (t[i] - '0') - addr;
    while (k < 0) {
      addr++;
      k += 10;
    }
    s[i] = k + '0';
  }

  // cout << s << endl;
  return s;
}

string get_position(const string &num, int dec) {
  string ret = "0";
  int i = 1;
  int sz = num.size();
  for (; i < sz; i++) {
    stringstream sstr; sstr << i*9;
    ret = add(ret, sstr.str() + string(i-1, '0'));
  }

  if (num[sz-i] > '1') {
    stringstream sstr; sstr << (num[sz-i] - '1') * sz;
    ret = add(ret, sstr.str() + string(i-1, '0'));
  }

  for (i--; i > 0; i--) {
    if (num[sz-i] > '0') {
      stringstream sstr; sstr << (num[sz-i] - '0') * sz;
      ret = add(ret, sstr.str() + string(i-1, '0'));
    }
  }

  if (dec == -1) {
    ret = add(ret, "2");
  } else if (dec == 0) {
    ret = add(ret, "1");
  } else {
    stringstream sstr; sstr << dec-1;
    ret = sub(ret, sstr.str());
  }
  return ret;
}

string part_next_number(string target_number) {
  for (int i = target_number.size() - 1; i >= 0; i--) {
    if (target_number[i] == '9') {
      target_number[i] = '0';
    } else {
      target_number[i]++;
      return target_number;
    }
  }
  return target_number;
}

string prev_number(string target_number) {
  if (target_number[0] == '0') return "-";
  if (target_number == "1") return "0";
  for (int i = target_number.size() - 1; i >= 0; i--) {
    if (target_number[i] == '0') {
      target_number[i] = '9';
    } else {
      target_number[i]--;
      break;
    }
  }
  if (target_number == string(target_number.size(), '9')) return "-";

  int i = 0;
  while (i < target_number.size() && target_number[i] == '0') {
    i++;
  }
  if (i == target_number.size())
    return "-";
  else
    return target_number.substr(i);
}

string next_number(string target_number) {
  for (int i = target_number.size() - 1; i >= 0; i--) {
    if (target_number[i] == '9') {
      target_number[i] = '0';
    } else {
      target_number[i]++;
      return target_number;
    }
  }
  return "1" + target_number;
}

bool check_previous(const string &input, string target_number, int end_pos) {
  if (end_pos <= 0) return true;
  if (end_pos < target_number.size()) {
    if (target_number.substr(target_number.size() - end_pos)
        != input.substr(0, end_pos)) return false;
  } else {
    if (target_number != input.substr(end_pos - target_number.size(),
                                      target_number.size())) return false;
  }
  return check_previous(input, prev_number(target_number), end_pos - target_number.size());
}

bool check_next(const string input, string target_number, int start_pos) {
  if (input.size() <= start_pos) return true;
  if (start_pos + target_number.size() >= input.size()) {
    string t = input.substr(start_pos);
    if (target_number.substr(0, t.size()) != t) return false;
  } else {
    if (target_number != input.substr(start_pos, target_number.size())) return false;
  }
  return check_next(input, next_number(target_number), start_pos + target_number.size());
}

int main(void) {
  ios::sync_with_stdio(false);
  string input; cin >> input;
  int input_len = input.size();

  string ans_num(999, '9');
  int ans_pos = 0;
  for (int start_number_size = 1;
       start_number_size <= input_len && ans_num.size() == 999;
       start_number_size++)
  {
    for (int start_number_pos = 0;
         start_number_pos < start_number_size;
         start_number_pos++)
    {
      if (input[start_number_pos] == '0') continue;
      if (start_number_pos + start_number_size <= input_len) {
        // ...|...SSSSS..|.......
        string target_number = input.substr(start_number_pos, start_number_size);
        if (!check_previous(input, prev_number(target_number), start_number_pos)) {
          continue;
        }
        if (!check_next(input, next_number(target_number), start_number_pos+start_number_size)) {
          continue;
        }
        if (ans_num > target_number) {
          ans_num = target_number;
          ans_pos = start_number_pos;
        } else if (ans_num == target_number) {
          ans_pos = min(ans_pos, start_number_pos);
        }
      } else {
        // ...|...SSSSSSS|SSSS...
        // start_number_pos = 3
        // start_number_size = 11
        // input_len = 10
        // hidden_digits_size = 4
        int hidden_digits_size = start_number_pos + start_number_size - input_len;
        if (hidden_digits_size > start_number_pos) {
          //     vvv====1====vvv
          // ...|...SSSSSSS|SSSS...
          //                0
          // ...|...SSSSSSS|SSSS...
          //                1000
          // ...|999SSSSSSS|SSSS...
          string target_number_prefix = input.substr(start_number_pos);
          string target_number_postfix = part_next_number(
              input.substr(0, start_number_pos));
          string target_number_middle(start_number_size
                                      - target_number_prefix.size()
                                      - target_number_postfix.size(), '0');
          if (target_number_postfix == string(target_number_postfix.size(), '0')) {
            target_number_middle[target_number_middle.size()-1] = '1';
          }
          string target_number = (target_number_prefix +
                                  target_number_middle +
                                  target_number_postfix);
          if (ans_num > target_number) {
            ans_num = target_number;
            ans_pos = start_number_pos;
          } else if (ans_num == target_number) {
            ans_pos = min(ans_pos, start_number_pos);
          }
        } else {
          //     vv======vv
          // ...|......SSSS|SSSS...
          //     vv===1==vv
          // ...|..9999SSSS|SSSS...
          //       vvvv==1==vvvv
          // ...|......SSSS|SSSS...

          string target_number_prefix = input.substr(start_number_pos);
          if (target_number_prefix[0] == '0') continue;
          string target_number_postfix = part_next_number(input.substr(
              start_number_pos - hidden_digits_size, hidden_digits_size));
          string check_digits =
              input.substr(0, start_number_pos - hidden_digits_size);
          if (target_number_postfix == string(target_number_postfix.size(), '0')) {
            check_digits = part_next_number(check_digits);
          }
          if (check_digits != input.substr(input_len - check_digits.size())) {
            continue;
          }
          string target_number = target_number_prefix + target_number_postfix;
          if (ans_num > target_number) {
            ans_num = target_number;
            ans_pos = start_number_pos;
          } else if (ans_num == target_number) {
            ans_pos = min(ans_pos, start_number_pos);
          }
        }
      }
    }
  }

  if (ans_num.size() == 999) {
    if (input[0] == '0') {
      ans_num = "1" + input;
      ans_pos = -1;
    } else {
      ans_num = input;
      ans_pos = 0;
    }
  }
  cout << get_position(ans_num, ans_pos) << endl;
  return 0;
}
