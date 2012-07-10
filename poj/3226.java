import java.math.BigInteger;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    for (;;) {
      int N = sc.nextInt();
      if (N == 0) break;
      String s = sc.next();

      int used = 0;
      BigInteger ans = BigInteger.ZERO;

      int cur = 26;
      for (int k = 0; k < N; k++) {
        int c = s.charAt(k) - 'A';
        int use_mask = 1 << c;
        int pos = 0;
        for (int i = 0; i < c; i++) {
          if ((used & (1 << i)) == 0) {
            pos++;
          }
        }
        used |= use_mask;
        ans = ans.multiply(BigInteger.valueOf(cur)).add(BigInteger.valueOf(pos));
        cur--;
      }

      System.out.println(ans);
    }
  }
}

