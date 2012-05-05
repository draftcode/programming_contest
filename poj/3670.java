import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  static int[][] dp;
  static int[] v;
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    dp = new int[N][3];
    v = new int[N];
    for (int i = 0; i < N; i++) {
      v[i] = scanner.nextInt() - 1;
    }

    for (int k = 0; k < 3; k++) {
      if (v[0] == k) {
        dp[0][k] = 0;
      } else {
        dp[0][k] = 1;
      }
    }

    for (int i = 1; i < N; i++) {
      for (int k = 0; k < 3; k++) {
        int min = Integer.MAX_VALUE;
        for (int j = 0; j <= k; j++) {
          min = Math.min(min, dp[i-1][j]);
        }
        dp[i][k] = min;
        if (v[i] != k) {
          dp[i][k]++;
        }
      }
    }

    int ans = Math.min(Math.min(dp[N-1][0], dp[N-1][1]), dp[N-1][2]);

    for (int k = 0; k < 3; k++) {
      if (v[N-1] == k) {
        dp[N-1][k] = 0;
      } else {
        dp[N-1][k] = 1;
      }
    }

    for (int i = N-2; i >= 0; i--) {
      for (int k = 0; k < 3; k++) {
        int min = Integer.MAX_VALUE;
        for (int j = 0; j <= k; j++) {
          min = Math.min(min, dp[i+1][j]);
        }
        dp[i][k] = min;
        if (v[i] != k) {
          dp[i][k]++;
        }
      }
    }

    ans = Math.min(Math.min(Math.min(dp[0][0], dp[0][1]), dp[0][2]), ans);

    System.out.println(ans);
  }
}

