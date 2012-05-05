import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  static String rep(String s, String endString) {
    for (int i = 0; i < 10; i++) {
      String t = Integer.toString(i).concat(s);
      BigInteger powed = new BigInteger(t).pow(3);

      if (powed.toString().endsWith(endString)) {
        return t;
      }
    }
    return "";
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    for (int i = 0; i < n; i++) {
      String s = scanner.next();

      String answer = "";
      for (int j = 1; j <= s.length(); j++) {
        answer = rep(answer, s.substring(s.length()-j));
      }

      while (answer.charAt(0) == '0') {
        answer = answer.substring(1);
      }
      System.out.println(answer);
    }
  }
}

