#include <iostream>
#include <cstdio>
#include <climits>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> ip;
typedef vector<int> iv;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(c,it) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

struct edge {
    char begin;
    char end;
    int len;
    bool used;
    edge() {};
    edge(char b, char e, int l) : begin(b), end(e), len(l), used(false) {};
    bool operator <(edge& rhs) const {
        return begin < rhs.begin;
    }
};

int N;
int cost[367];
int parent[367];
edge edges[1001];

int main(void) {
    for (;;) {
        scanf("%d", &N);
        if (N == 0) break;

        // input
        rep (i, N) {
            char b, e; int l;
            scanf("%d%d%d", &b, &e, &l);
            edges[i] = edge(b,e,l);
        }
        sort(edges, edges+N);

        // solve
        int ret = 0, pos = 0;

        zclear(cost);
        zclear(parent);
        priority_queue<ip> que;
        rep (i, 366) {
            while (edges[i].begin == i) {
                if (it->used) continue;
                if (cost[it->end + 1] < cost[i] + it->len) {
                    cost[it->end + 1] = cost[i] + it->len;
                    parent[it->end + 1] = i;
                    que.push(it->end + 1);
                }
            }

            if (cost[i + 1] < cost[i]) {
                cost[i + 1] = cost[i];
                parent[i + 1] = parent[i];
            }
        }
        ret = cost[365];

        

        
    }

    return 0;
}
