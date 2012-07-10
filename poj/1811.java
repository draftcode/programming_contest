import java.math.BigInteger;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for (int i = 0; i < T; i++) {
      BigInteger I = sc.nextBigInteger();
      if (I.isProbablePrime(10)) {
        System.out.println("Prime");
      } else {
        BigInteger P = BigInteger.valueOf(2);
        while (true) {
          if (I.mod(P) == BigInteger.ZERO) {
            System.out.println(P.toString());
            break;
          } else {
            P = P.nextProbablePrime();
          }
        }
      }
    }
  }
}

