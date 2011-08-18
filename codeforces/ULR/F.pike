int main() {
  int n;
  sscanf(Stdio.stdin->gets(), "%d", n);

  array(int) arr = allocate(n, 0);
  for (int i = 0; i < n; i++) {
    int a;
    sscanf(Stdio.stdin->gets(), "%d", a);
    
    for (int k = i; k > 0; k--) {
      arr[k] = arr[k] + a * arr[k-1];
    }
    arr[0] += a;
  }

  if (n == 1) {
    write("X");
  } else {
    write("X^%d", n);
  }

  for (int i = 0; i < n-2; i++) {
    if (arr[i] > 1) {
      write("+%d*X^%d", arr[i], n - i - 1);
    } else if (arr[i] == 1) {
      write("+X^%d", n - i - 1);
    } else if (arr[i] == -1) {
      write("-X^%d", n - i - 1);
    } else if (arr[i] < -1) {
      write("%d*X^%d", arr[i], n - i - 1);
    }
  }

  if (n >= 2) {
    if (arr[n-2] > 1) {
      write("+%d*X", arr[n-2]);
    } else if (arr[n-2] == 1) {
      write("+X");
    } else if (arr[n-2] == -1) {
      write("-X");
    } else if (arr[n-2] < -1) {
      write("%d*X", arr[n-2]);
    }
  }

  if (arr[n-1] >= 1) {
    write("+%d", arr[n-1]);
  } else if (arr[n-1] < 0) {
    write("%d", arr[n-1]);
  }
  write("\n");

  return 0;
}


