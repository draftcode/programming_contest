import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    while (scanner.hasNext()) {
      String s = scanner.next();
      BigDecimal ans = BigDecimal.ZERO;
      for (int i = s.length()-1; i >= 2; i--) {
        ans = ans.divide(BigDecimal.valueOf(8)).add(BigDecimal.valueOf(s.charAt(i) - '0'));
      }
      System.out.print(s);
      System.out.print(" [8] = ");
      System.out.print(ans.divide(BigDecimal.valueOf(8)).toString());
      System.out.println(" [10]");
    }
  }
}

