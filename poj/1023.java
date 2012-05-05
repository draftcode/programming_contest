import java.math.BigInteger;
import java.util.Scanner;
import java.util.Arrays;

public class Main {
  static boolean[] bits;
  static String s;
  static int K;
  static BigInteger num;

  private static boolean f(int i, BigInteger left, BigInteger pos_window, BigInteger neg_window) {
    if (left.equals(BigInteger.ZERO)) return true;
    if (i == K) return true;
    if (left.compareTo(pos_window) == 1) return false;
    if (left.compareTo(neg_window) == -1) return false;

    BigInteger t = BigInteger.ONE.shiftLeft(K - i - 1);
    if (s.charAt(i) == 'p') {
      pos_window = pos_window.subtract(t);
      if (f(i+1, left.subtract(t), pos_window, neg_window)) {
        bits[i] = true;
      } else if (f(i+1, left, pos_window, neg_window)) {
        bits[i] = false;
      } else {
        return false;
      }
    } else {
      neg_window = neg_window.add(t);
      if (f(i+1, left.add(t), pos_window, neg_window)) {
        bits[i] = true;
      } else if (f(i+1, left, pos_window, neg_window)) {
        bits[i] = false;
      } else {
        return false;
      }
    }
    return true;
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int T = scanner.nextInt();
    for (int _ = 0; _ < T; _++) {
      K = scanner.nextInt();
      s = scanner.next();
      num = scanner.nextBigInteger();

      bits = new boolean[K];
      BigInteger pos_window = BigInteger.ZERO;
      BigInteger neg_window = BigInteger.ZERO;
      BigInteger t = BigInteger.ONE;
      for (int i = K-1; i >= 0; i--) {
        if (s.charAt(i) == 'p') {
          pos_window = pos_window.add(t);
        } else {
          neg_window = neg_window.subtract(t);
        }
        t = t.shiftLeft(1);
      }

      if (f(0, num, pos_window, neg_window)) {
        for (int i = 0; i < K; i++) {
          if (bits[i]) {
            System.out.print(1);
          } else {
            System.out.print(0);
          }
        }
        System.out.println();
      } else {
        System.out.println("Impossible");
      }
    }
  }
}

