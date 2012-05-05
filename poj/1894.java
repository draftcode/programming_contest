import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int base = scanner.nextInt();
    BigInteger bi = scanner.nextBigInteger();
    char [] s = bi.toString(base).toCharArray();
    if (s.length == 1 && s[0] == '0') {
    } else {
      boolean prev_zero = false;
      for (int i = s.length-1; i >= 0; i--) {
        if (s[i] == '0' && !prev_zero) {
          s[i] += base;
          prev_zero = true;
        } else if (s[i] == '0' && prev_zero) {
          s[i] += base - 1;
        } else if (prev_zero) {
          s[i]--;
          if (i != 0 && s[i] == '0') {
            s[i] += base;
          } else {
            prev_zero = false;
          }
        }
      }
      for (int i = 0; i < s.length; i++) {
        if (s[i] != '0') {
          System.out.print(s[i]);
        }
      }
    }
    System.out.println();
  }
}
