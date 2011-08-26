#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int> > ppp;
ppp make_ppp(int id, int salary, int tall) { return make_pair(salary, make_pair(tall, id)); }
int get_id(ppp p) { return p.second.second; }
int get_tall(ppp p) { return p.second.first; }
int get_salary(ppp p) { return p.first; }

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int cases;
int inputs, queries;
ppp v[30000];
int ids[30000];
int bosses[30000];
int subordinaries[30000];

void input(void) {
  rep (i, inputs) {
    int id, salary, tall;
    cin >> id >> salary >> tall;
    v[i] = make_ppp(id, salary, tall);
    ids[i] = id;
  }
}

void calc(void) {
  zclear(bosses);
  zclear(subordinaries);

  rep (i, inputs - 1) {
    int id = get_id(v[i]);
    int k = lower_bound(ids, ids+inputs, id) - ids;

    int boss = i + 1;
    while (get_salary(v[boss]) < get_salary(v[i]) ||
        get_tall(v[boss]) < get_tall(v[i])) {
      boss++;
    }
    int boss_id = get_id(v[boss]);
    int boss_k = lower_bound(ids, ids+inputs, boss_id) - ids;

    bosses[k] = boss_id;
    subordinaries[boss_k] += 1 + subordinaries[k];
  }
}

void query(int id) {
  int k = lower_bound(ids, ids+inputs, id) - ids;
  cout << bosses[k] << ' ' << subordinaries[k] << endl;
}

int main(void) {
  cin >> cases;
  rep (i, cases) {
    cin >> inputs >> queries;
    input();
    sort(v, v+inputs);
    sort(ids, ids+inputs);
    calc();

    rep (k, queries) {
      int query_id;
      cin >> query_id;
      query(query_id);
    }
  }
  return 0;
}
