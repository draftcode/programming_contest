#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int main(void) {
    int n;
    char s[1024];
    scanf("%d", &n);
    
    map<int, int> m;
    rep (__i, n) {
        scanf("%s", s);

        int number = 0;
        for (unsigned int i = 0; i < strlen(s); i++) {
            if (isdigit(s[i])) {
                number *= 10;
                number += s[i] - '0';
            } else if ('A' <= s[i] && s[i] <= 'C') {
                number *= 10;
                number += 2;
            } else if ('D' <= s[i] && s[i] <= 'F') {
                number *= 10;
                number += 3;
            } else if ('G' <= s[i] && s[i] <= 'I') {
                number *= 10;
                number += 4;
            } else if ('J' <= s[i] && s[i] <= 'L') {
                number *= 10;
                number += 5;
            } else if ('M' <= s[i] && s[i] <= 'O') {
                number *= 10;
                number += 6;
            } else if ('P' <= s[i] && s[i] <= 'S') {
                number *= 10;
                number += 7;
            } else if ('T' <= s[i] && s[i] <= 'V') {
                number *= 10;
                number += 8;
            } else if ('W' <= s[i] && s[i] <= 'Y') {
                number *= 10;
                number += 9;
            }
        }

        pair<map<int,int>::iterator, bool> p = m.insert(make_pair(number, 1));
        if (p.second == false) {
            p.first->second += 1;
        }
    }

    vector<pair<int, int> > v;
    each (it, m) {
        if (it->second > 1) {
            v.push_back(*it);
        }
    }
    if (v.size() == 0) {
        printf("No duplicates.\n");
    } else {
        sort(v.begin(), v.end());

        each (it, v) {
            int num = it->first;
            int count = it->second;
            printf("%03d-%04d %d\n", num / 10000, num % 10000, count);
        }
    }
    return 0;
}
