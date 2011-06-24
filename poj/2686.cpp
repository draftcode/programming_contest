#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>
using namespace std;

int n, m, p, a, b;
int t[8];

int dist[30][8]; // distance, tickets
int parent[30][8]; // distance, tickets
vector<pair<int,int> > paths[30];

// distance, tickets, city
typedef pair<int, pair<int, int> > state;
int distance(state s) { return s.first; }
int tickets(state s) { return s.second.first; }
int city(state s) { return s.second.second; }

double calc(int d, int c, int i) {/*{{{*/
    vector<int> dists;

    for (int ticket = i - 1; ticket >= 0; ticket--) {
        dists.push_back(d - dist[c][ticket]);
        d = dist[c][ticket];
        c = parent[c][ticket];
    }

    dists.push_back(d);
    sort(dists.begin(), dists.end(), greater<int>());
    double cost = 0.0;
    for (unsigned int j = 0; j < dists.size(); j++) {
        cost += double(dists[j]) / double(t[j]);
    }
    return cost;
}/*}}}*/

void solve(void) {/*{{{*/
    double ret = HUGE_VAL;

    priority_queue<state, vector<state>, greater<state> > que;
    que.push(make_pair(0, make_pair(0, a - 1)));
    while (!que.empty()) {
        state p = que.top();
        que.pop();
        if (tickets(p) == n) continue;

        for (unsigned int i = 0; i < paths[city(p)].size(); i++) {
            pair<int, int> next = paths[city(p)][i];
            if (next.first == b - 1) {
                ret = min(ret, calc(distance(p) + next.second, city(p), tickets(p)));
            } else if (dist[next.first][tickets(p)] == -1 || dist[next.first][tickets(p)] > distance(p) + next.second) {
                dist[next.first][tickets(p)] = distance(p) + next.second;
                parent[next.first][tickets(p)] = city(p);

                que.push(make_pair(distance(p) + next.second,
                            make_pair(tickets(p) + 1, next.first)));
            }
        }
    }

    if (ret == HUGE_VAL) {
        printf("Impossible\n");
    } else {
        printf("%.3f\n", ret);
    }
}/*}}}*/

void input(void) {/*{{{*/
    scanf("%d %d %d %d %d", &n, &m, &p, &a, &b);
    if (n == 0 && m == 0 && p == 0 && a == 0 && b == 0) {
        exit(0);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", t + i);
    }
    sort(t, t + n, greater<int>());

    for (int i = 0; i < p; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        paths[x-1].push_back(make_pair(y-1, z));
        paths[y-1].push_back(make_pair(x-1, z));
    }
}/*}}}*/

int main(void) {/*{{{*/
    for (;;) {
        memset(dist, -1, sizeof(dist));
        memset(parent, -1, sizeof(parent));
        input();
        solve();

        for (int i = 0; i < m; i++) {
            paths[i].clear();
        }
    }
    return 0;
}/*}}}*/


