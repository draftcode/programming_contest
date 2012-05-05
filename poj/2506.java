import java.math.BigInteger;
import java.util.*;

public class Main {
  static BigInteger[] dp;
  public static void main(String[] args) {
    dp = new BigInteger[251];

    Arrays.fill(dp, BigInteger.ONE);
    dp[1] = BigInteger.ONE;
    dp[2] = BigInteger.valueOf(3);

    for (int len = 3; len <= 250; len++) {
      dp[len] = dp[len-1].add(dp[len-2].multiply(BigInteger.valueOf(2)));
    }

    Scanner sc = new Scanner(System.in);
    while (sc.hasNext()) {
      int N = sc.nextInt();
      System.out.println(dp[N].toString());
    }
  }
}

