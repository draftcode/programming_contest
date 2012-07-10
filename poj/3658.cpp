#include <iostream>
#include <limits>
#include <map>

using namespace std;
typedef long long ll;

#define MAX_N 100000

int N, ALT_N;
int width[MAX_N], height[MAX_N], seg_height[2*MAX_N-1], acc_width[MAX_N+1];
ll ans[MAX_N];
map<int, int> height_idx;

int query(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l)
    return 0;
  else if (a <= l && r <= b)
    return seg_height[k];
  else {
    int mid = (l + r) / 2;
    int vl = query(a, b, k * 2 + 1, l, mid);
    int vr = query(a, b, k * 2 + 2, mid, r);
    return max(vl, vr);
  }
}

ll process(int start, int end, ll sofar) {
  if (start >= end) return sofar;
  int adjheight;
  if (start == 0 && end == N) {
    adjheight = 0;
  } else if (start == 0) {
    adjheight = height[end];
  } else if (end == N) {
    adjheight = height[start-1];
  } else {
    adjheight = min(height[start-1], height[end]);
  }

  if (start + 1 == end) {
    ans[start] = sofar + width[start] * 1;
    return sofar + width[start] * (adjheight - height[start]);
  } else {
    int maxidx = height_idx[query(start, end, 0, 0, ALT_N)];
    int width = (acc_width[end] - acc_width[start]);

    if (maxidx == start) {
      sofar = process(start + 1, end, sofar);
    } else if (maxidx == end - 1) {
      sofar = process(start, end - 1, sofar);
    } else {
      sofar = process(start, maxidx, sofar);
      sofar = process(maxidx + 1, end, sofar);
    }
    ans[maxidx] = sofar + width * 1;
    return sofar + width * (adjheight - height[maxidx]);
  }
}

int construct(int i) {
  if (i >= ALT_N-1) {
    return seg_height[i];
  } else {
    seg_height[i] = max(construct(i*2+1), construct(i*2+2));
    return seg_height[i];
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin >> N;
  ALT_N = N;
  if (N % 2 == 1) ALT_N++;
  acc_width[0] = 0;
  for (int i = 0; i < N; i++) {
    cin >> width[i] >> height[i];
    seg_height[ALT_N-1+i] = height[i];
    height_idx[height[i]] = i;
    acc_width[i+1] = acc_width[i] + width[i];
  }
  construct(0);
  process(0, N, 0);
  for (int i = 0; i < N; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
