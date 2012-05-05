import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  static int gcd(int a, int b) {
    if (a > b) {
      int t = b;
      b = a;
      a = t;
    }
    while (a != 0) {
      int t = b % a;
      b = a;
      a = t;
    }
    return b;
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    while (scanner.hasNext()) {
      String s = scanner.next();
      int a = s.charAt(0)-'0';
      int b = s.charAt(2)-'0';
      int c = s.charAt(4)-'0';
      int d = s.charAt(6)-'0';
      int de;
      if (s.charAt(3) == '-') {
        de = a*d - b*c;
      } else {
        de = a*d + b*c;
      }
      int nu = b*d;
      int e = gcd(Math.abs(de), nu);
      if (de % nu == 0) {
        System.out.println(de/nu);
      } else {
        System.out.printf("%d/%d\n", de/e, nu/e);
      }
    }
  }
}

