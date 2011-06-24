#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool getbool(int k, char c) {/*{{{*/
    k = (k >> (c - 'a'));
    if (k % 2 == 0) {
        return false;
    } else {
        return true;
    }
}/*}}}*/

bool solve(int k, char *s, char **e) {/*{{{*/
    bool stk[1000];
    int stktop = 0;
    while (*s != '\0') {
        if ('0' <= *s && *s <= '9') {
            stk[stktop++] = getbool(k, *s);
        } else if (*s == '^') {
            bool val2 = stk[--stktop];
            bool val1 = stk[--stktop];
            stk[stktop++] = val1 ^ val2;
        } else if (*s == '&') {
            bool val2 = stk[--stktop];
            bool val1 = stk[--stktop];
            stk[stktop++] = val1 & val2;
        } else if (*s == '|') {
            bool val2 = stk[--stktop];
            bool val1 = stk[--stktop];
            stk[stktop++] = val1 | val2;
        } else if (*s == '~') {
            bool val = stk[--stktop];
            stk[stktop++] = !val;
        } 
        s++;
    }
    return stk[stktop--];
}/*}}}*/

void convert(char *str) {/*{{{*/
    char ret[1000];
    int retpos = 0;

    char temp_not[1000];
    int temp_not_pos = 0;

    char temp_and[1000];
    int temp_and_pos = 0;

    char temp_or[1000];
    int temp_or_pos = 0;

    char temp_xor[1000];
    int temp_xor_pos = 0;

    char *s = str;
    while (*s != '\0') {
        if (*s == '~') {
            temp_not[temp_not_pos++] = '~';
        } else if (*s == '&') {
            temp_and[temp_and_pos++] = '&';
        } else if (*s == '^') {
            temp_xor[temp_xor_pos++] = '^';
        } else if (*s == '|') {
            temp_or[temp_or_pos++] = '|';
        } else if (*s == '(') {
            temp_or[temp_or_pos++] = 'p';
            temp_xor[temp_xor_pos++] = 'p';
            temp_and[temp_and_pos++] = 'p';
            temp_not[temp_not_pos++] = 'p';
        } else if (*s == ')') {
            while (temp_not_pos > 0 && temp_not[temp_not_pos-1] != 'p') {
                ret[retpos++] = temp_not[--temp_not_pos];
            }
            while (temp_and_pos > 0 && temp_and[temp_and_pos-1] != 'p') {
                ret[retpos++] = temp_and[--temp_and_pos];
            }
            while (temp_xor_pos > 0 && temp_xor[temp_xor_pos-1] != 'p') {
                ret[retpos++] = temp_xor[--temp_xor_pos];
            }
            while (temp_or_pos > 0 && temp_or[temp_or_pos-1] != 'p') {
                ret[retpos++] = temp_or[--temp_or_pos];
            }
            temp_not_pos--;
            temp_and_pos--;
            temp_xor_pos--;
            temp_or_pos--;
        } else {
            ret[retpos++] = *s;
            while (temp_not_pos > 0 && temp_not[temp_not_pos-1] != 'p') {
                ret[retpos++] = temp_not[--temp_not_pos];
            }

            bool done = false;
            if (!done && temp_and_pos > 0 && temp_and[temp_and_pos-1] != 'p') {
                done = true;
                ret[retpos++] = temp_and[--temp_and_pos];
            }
            if (!done && temp_xor_pos > 0 && temp_xor[temp_xor_pos-1] != 'p') {
                done = true;
                ret[retpos++] = temp_xor[--temp_xor_pos];
            }
            if (!done && temp_or_pos > 0 && temp_or[temp_or_pos-1] != 'p') {
                done = true;
                ret[retpos++] = temp_or[--temp_or_pos];
            }
        }
        s++;
    }
    while (temp_not_pos > 0 && temp_not[temp_not_pos-1] != 'p') {
        ret[retpos++] = temp_not[--temp_not_pos];
    }
    while (temp_and_pos > 0 && temp_and[temp_and_pos-1] != 'p') {
        ret[retpos++] = temp_and[--temp_and_pos];
    }
    while (temp_xor_pos > 0 && temp_xor[temp_xor_pos-1] != 'p') {
        ret[retpos++] = temp_xor[--temp_xor_pos];
    }
    while (temp_or_pos > 0 && temp_or[temp_or_pos-1] != 'p') {
        ret[retpos++] = temp_or[--temp_or_pos];
    }
    
    for (int i = 0; i < retpos; i++) {
        *str++ = ret[i];
    }
    *str = '\0';
}/*}}}*/

void input(char *s1, char *s2, int *n) {/*{{{*/
    int maxnum = 0;
    int paren = 0;
    bool cont = true;
    char *s = s1;

    char m[26];
    memset(m, 0, sizeof(m));

    while (true) {
        int c = getchar();
        if (c == '&' || c == '^' || c == '|') {
            cont = true;
            *s++ = c;
        } else if (c == '~') {
            if (cont == false && paren == 0) {
                s = s2;
            }
            *s++ = c;
            cont = true;
        } else if (c == '\r' || c == '\n') {
            if (s != s1) {
                break;
            }
        } else if (c == '(') {
            if (cont == false && paren == 0) {
                s = s2;
            }
            paren++;
            *s++ = c;
            cont = true;
        } else if (c == ')') {
            paren--;
            *s++ = c;
            cont = false;
        } else if (c == ' ') {
        } else {
            if (cont == false && paren == 0) {
                s = s2;
            }
            if ('a' <= c && c <= 'z') {
                if (m[c - 'a'] == 0) {
                    m[c - 'a'] = ++maxnum;
                }
                *s++ = '0' + m[c - 'a'] - 1;
            } else {
                *s++ = c;
            }
            cont = false;
        }
    }
    *n = maxnum;
}/*}}}*/

int main(void) {
    int n;
    scanf("%d", &n);

    char s1[1000], s2[1000];
    for (int i = 0; i < n; i++) {
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        int m = 0;
        input(s1, s2, &m);
        convert(s1);
        printf("%s\n", s1);
        
        // bool t = true;
        // for (int k = 0; k < (1 << m); k++) {
        //     bool v1, v2;
        //     char *dummy;
        //     v1 = solve(k, s1, &dummy);
        //     v2 = solve(k, s2, &dummy);
        //     if (v1 != v2) {
        //         t = false;
        //         break;
        //     }
        // }

        // if (t) {
        //     printf("Data set %d: Equivalent\n", i + 1);
        // } else {
        //     printf("Data set %d: Different\n", i + 1);
        // }
    }
    return 0;
}


