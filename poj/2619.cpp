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

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int main(void) {
  int M, N;
  scanf("%d%d", &M, &N);
  if (M > N) swap(M,N);

  int Mrow, Mcol, Nrow, Ncol;
  Mrow = sqrt(M); if (Mrow*Mrow != M) Mrow++;
  Nrow = sqrt(N); if (Nrow*Nrow != N) Nrow++;
  Mcol = M - (Mrow-1)*(Mrow-1);
  Ncol = N - (Nrow-1)*(Nrow-1);

  int count = 0;
  while (Mrow != Nrow) {
    if (Mcol % 2 == 1) {
      Mrow++;
      Mcol++;
      count++;
    } else {
      if (Mcol < Ncol) {
        Mcol++;
      } else {
        Mcol--;
      }
      count++;
    }
  }
  count += abs(Mcol - Ncol);
  printf("%d\n", count);
  return 0;
}
