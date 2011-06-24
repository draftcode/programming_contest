#include <iostream>
#include <cstdio>
#include <climits>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(c,it) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define clear(v) memset(v, 0, sizeof(v))

typedef long long ll;
typedef pair<int, int> edge;   // to, dist

const int Nmax = 50000;
const int Mmax = 200000;
const int Vmax = 1000;

int n, m, v;
ll dists[Nmax + 2];
int vertices_x[Nmax + 2];
int vertices_y[Nmax + 2];
vector<vector<edge> > edges(Nmax + 2);

ll sqr(ll i) { return i * i; }
bool far(int from, int to) {/*{{{*/
    if (to == n + 1) return true;

    if (dists[from] < dists[to]) {
        return true;
    }
    return false;
}/*}}}*/
bool safe(int i, ll time) {/*{{{*/
    if (i == n + 1) return true;
    if (dists[i] <= sqr(time * v)) {
        return false;
    }
    return true;
}/*}}}*/
void solve(void) {/*{{{*/
    typedef pair<ll,int> state; // time, x

    vector<ll> visit(n+2, LLONG_MAX);

    priority_queue<state , vector<state>, greater<state> > que;
    que.push(make_pair(0,0));
    while (!que.empty()) {
        state s = que.top(); que.pop();
        if (visit[s.second] != LLONG_MAX) continue;
        visit[s.second] = s.first;

        if (s.second == n + 1) {
            cout << s.first << endl;
            return;
        }
        for(vector<edge>::iterator it = edges[s.second].begin(); it != edges[s.second].end(); ++it) {
            edge e = *it;
            ll ndist = s.first + e.second;
            if (visit[e.first] > ndist) {
                if (far(s.second, e.first) && safe(e.first, ndist)) {
                    que.push(make_pair(ndist, e.first));
                }
            }
        }
    }
    cout << "Impossible" << endl;
}/*}}}*/
int main(void) {/*{{{*/
    scanf("%d%d%d", &n, &m, &v);

    rep(i, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        vertices_x[i+1] = x;
        vertices_y[i+1] = y;
    }

    rep(i, m) {
        int x, y, dist;
        scanf("%d%d%d", &x, &y, &dist);
        edges[x].push_back(make_pair(y, dist));
        edges[y].push_back(make_pair(x, dist));
    }

    int xs, ys, xg, yg;
    scanf("%d%d%d%d", &xs, &ys, &xg, &yg);
    vertices_x[0] = xs;
    vertices_y[0] = ys;
    vertices_x[n+1] = xg;
    vertices_y[n+1] = yg;

    rep(i, n + 2) {
        ll x, y;
        x = vertices_x[i] - vertices_x[0];
        y = vertices_y[i] - vertices_y[0];
        dists[i] = x*x + y*y;
    }
    solve();
    return 0;
}/*}}}*/

