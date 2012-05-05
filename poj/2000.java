import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  static final int DAYS = 10000;
  static int[] coins;
  public static void main(String[] args) {
    coins = new int[DAYS+1];
    int days = 1;
    int coin = 1;
    for (int i = 1; i <= DAYS; i++) {
      coins[i] = coins[i-1] + coin;
      days--;
      if (days == 0) {
        coin++;
        days = coin;
      }
    }

    Scanner scanner = new Scanner(System.in);
    while (true) {
      int day = scanner.nextInt();
      if (day == 0) break;
      System.out.printf("%d %d\n", day, coins[day]);
    }
  }
}

