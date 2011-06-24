#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int steps = 0;
int ram[1001][3];
int reg[10];

void input() {/*{{{*/
    int n, pos;
    pos = 0;
    while (cin >> n) {
        ram[pos][0] = n / 100; n %= 100;
        ram[pos][1] = n / 10;  n %= 10;
        ram[pos][2] = n;
        pos++;
    }
}/*}}}*/

void solve(int pos) {/*{{{*/
    int tempval;
    while (true) {
        int arg1, arg2;
        arg1 = ram[pos][1];
        arg2 = ram[pos][2];
        steps++;
        switch (ram[pos][0]) {
            case 1:
                printf("%d\n", steps);
                return;
            case 2:
                reg[arg1] = arg2;
                reg[arg1] %= 1000;
                pos++;
                break;
            case 3:
                reg[arg1] += arg2;
                reg[arg1] %= 1000;
                pos++;
                break;
            case 4:
                reg[arg1] *= arg2;
                reg[arg1] %= 1000;
                pos++;
                break;
            case 5:
                reg[arg1] = reg[arg2];
                reg[arg1] %= 1000;
                pos++;
                break;
            case 6:
                reg[arg1] += reg[arg2];
                reg[arg1] %= 1000;
                pos++;
                break;
            case 7:
                reg[arg1] *= reg[arg2];
                reg[arg1] %= 1000;
                pos++;
                break;
            case 8:
                reg[arg1] =
                    ram[reg[arg2]][0] * 100 +
                    ram[reg[arg2]][1] * 10 +
                    ram[reg[arg2]][2];
                pos++;
                break;
            case 9:
                tempval = reg[arg1];
                ram[reg[arg2]][0] = tempval / 100; tempval %= 100;
                ram[reg[arg2]][1] = tempval / 10 ; tempval %= 10;
                ram[reg[arg2]][2] = tempval;
                pos++;
                break;
            case 0:
                if (reg[arg2] == 0) {
                    pos++;
                } else {
                    pos = reg[arg1];
                }
                break;
        }
    }
}/*}}}*/

int main(void) {
    memset(ram, 0, sizeof(ram));
    memset(reg, 0, sizeof(reg));

    input();
    solve(0);

    return 0;
}


