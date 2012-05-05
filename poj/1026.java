import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  static int N;
  static int[] keys;
  static int[] cycles;

  private static void calculateCycle() {
    for (int i = 0; i < N; i++) {
      int k = keys[i];
      int n = 1;
      while (k != i) {
        k = keys[k];
        n++;
      }
      cycles[i] = n;
    }
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    while (true) {
      N = scanner.nextInt();
      if (N == 0) break;
      keys = new int[N];
      cycles = new int[N];

      for (int i = 0; i < N; i++) {
        keys[i] = scanner.nextInt() - 1;
      }
      calculateCycle();

      while (true) {
        int K = scanner.nextInt();
        if (K == 0) break;
        scanner.skip(" ");
        char[] s = scanner.nextLine().toCharArray();
        char[] a = new char[N];
        int max_key = 0;
        for (int i = 0; i < s.length; i++) {
          int key = keys[i];
          for (int k = (K-1) % cycles[i]; k > 0; k--) {
            key = keys[key];
          }
          a[key] = s[i];
          max_key = Math.max(max_key, key);
        }
        for (int i = 0; i < N; i++) {
          if (a[i] == 0) a[i] = ' ';
        }
        System.out.println(a);
      }

      System.out.println();
    }
  }
}

