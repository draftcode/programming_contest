int main() {
  int n;
  sscanf(Stdio.stdin->gets(), "%d", n);

  array(int) arr = ({ });
  foreach (Stdio.stdin->gets()/",", string s) {
    int k;
    sscanf(s, "%d", k);
    arr = arr + ({k});
  }

  for (int x = 0; x < n; x++) {
    for (int y = x; y < n; y++) {
      if (arr[x] % arr[y] != 0 && arr[y] % arr[x] != 0) {
        write("NOT FRIENDS\n");
        return 0;
      }
    }
  }
  write("FRIENDS\n");

  return 0;
}
