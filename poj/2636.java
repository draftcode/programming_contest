import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int T = scanner.nextInt();
    for (int t = 0; t < T; t++) {
      int K = scanner.nextInt();
      int ans = 0;
      for (int i = 0; i < K; i++) {
        ans += scanner.nextInt() - 1;
      }
      System.out.println(ans+1);
    }
  }
}

