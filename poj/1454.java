import java.math.BigInteger;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int i = sc.nextInt();
    while (i != 0) {
      BigInteger ans = BigInteger.valueOf(1);
      for (int k = 1; k <= i; k++) {
        ans = ans.multiply(BigInteger.valueOf(k));
      }

      int[] v = new int[10];
      String s = ans.toString();
      for (int k = 0; k < s.length(); k++) v[s.charAt(k) - '0']++;

      System.out.printf("%d! --\n", i);
      for (int k = 0; k < 5; k++) {
        System.out.printf("   (%d)%5d", k, v[k]);
        if (k != 4) System.out.printf(" ");
      }
      System.out.printf("\n");
      for (int k = 5; k < 10; k++) {
        System.out.printf("   (%d)%5d", k, v[k]);
        if (k != 9) System.out.printf(" ");
      }
      System.out.printf("\n");

      i = sc.nextInt();
    }
  }
}

