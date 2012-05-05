import java.math.BigInteger;
import java.util.Scanner;

public class B {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int T = scanner.nextInt();
    for (int t = 1; t <= T; t++) {
      BigInteger A, C;
      int B;
      A = scanner.nextBigInteger();
      B = scanner.nextInt();
      C = scanner.nextBigInteger();

      for (int b = 0; b < B; b++) {
        BigInteger m = A;
        if (b == 1) {
          m = m.remainder(C);
        }
        BigInteger ans = A;
        for (BigInteger a = new BigInteger("1"); !a.equals(A); a = a.add(BigInteger.ONE)) {
          ans = ans.multiply(m);
        }
        A = ans;
      }

      System.out.printf("Case #%d: %s\n", t, A.remainder(C).toString());
    }
  }
}

