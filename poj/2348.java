import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    while (true) {
      int A = scanner.nextInt();
      int B = scanner.nextInt();
      if (A == 0 && B == 0) break;
      if (A > B) {
        int t = A;
        A = B;
        B = t;
      }
      boolean[][][] dp = new boolean[A+1][B+1][2];

      for (int b = 1; b <= B; b++) {
        for (int a = 0; a <= b && a <= A; a++) {
          for (int i = 0; i < 2; i++) {
            if (a == 0) {
              dp[a][b][i] = false;
            } else if (b / a == 1) {
              dp[a][b][i] = !dp[b-a][a][(i+1)%2];
            } else {
              dp[a][b][i] = dp[a][b-a][(i+1)%2] && dp[b%a][a][(i+1)%2];
            }
          }
        }
      }

      if (dp[A][B][0]) {
        System.out.println("Ollie wins");
      } else {
        System.out.println("Stan wins");
      }
    }
  }
}

