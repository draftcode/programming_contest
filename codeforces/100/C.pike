int main() {
  string s = Stdio.stdin->gets();
  string t = Stdio.stdin->gets();
  string r = "";

  int ls = strlen(s) - 1;
  int lt = strlen(t) - 1;

  int left = 0;
  while (ls != -1 || lt != -1) {
    int is = 0, it = 0;
    if (ls != -1) {
      is = (int)s[ls] - 48;
      ls--;
    }
    if (lt != -1) {
      it = (int)t[lt] - 48;
      lt--;
    }

    int x = is + it + left;
    if (x >= 10) {
      left = 1;
      x = x - 10;
    } else {
      left = 0;
    }
    r = sprintf("%d%s", x, r);
  }

  if (left == 1) {
    write("1%s\n", r);
  } else {
    write("%s\n", r);
  }

  return 0;
}
