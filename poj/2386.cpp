#include <iostream>
#include <cstdio>
using namespace std;

int n, m;
char f[100][101];

void bfs(int x, int y) {
    f[x][y] = '.';

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            int nx = x + i;
            int ny = y + j;
            if (0 <= nx && nx < n) {
                if (0 <= ny && ny < m) {
                    if (f[nx][ny] == 'W') {
                        bfs(nx, ny);
                    }
                }
            }
        }
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", f[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (f[i][j] == 'W') {
                ans++;
                bfs(i,j);
            }
        }
    }

    cout << ans << endl;
}

