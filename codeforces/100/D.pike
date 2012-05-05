int main() {
  int k;
  sscanf(Stdio.stdin->gets(), "%d", k);
  string i = Stdio.stdin->gets();
  string f = Stdio.stdin->gets();

  string prefix = String.common_prefix(({i, f}));
  int need = strlen(i) - 2 * strlen(prefix) + strlen(f);
  // if (k >= need && (k - need) % 2 == 0) {
  if (k >= need) {
    write("Yes\n");
  } else {
    write("No\n");
  }

  return 0;
}

