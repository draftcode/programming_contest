int main() {
  int n;
  sscanf(Stdio.stdin->gets(), "%d", n);

  int idx = 0;
  array(int) arr = allocate(n);
  foreach (Stdio.stdin->gets()/" ", string s) {
    if (s == "on") {
      arr[idx] = 1;
    } else {
      arr[idx] = 0;
    }
    idx++;
  }

  int k;
  sscanf(Stdio.stdin->gets(), "%d", k);

  foreach (Stdio.stdin->gets()/" ", string s) {
    int i;
    sscanf(s, "%d", i);
    for (int x = i; x <= n; x += i) {
      arr[x-1]++;
    }
  }

  for (int i = 0; i < n; i++) {
      if (arr[i] % 2 == 0) {
        write("off");
      } else {
        write("on");
      }

      if (i != n-1) {
        write(" ");
      }
  }
  write("\n");

  return 0;
}

