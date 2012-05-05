import java.math.BigInteger;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    for (int i = 4; i <= n; i++) {
      if (Integer.valueOf(i).toString().replaceAll("4", "").replaceAll("7", "").equals("")) {
        if (n % i == 0) {
          System.out.println("YES");
          return;
        }
      }
    }
    System.out.println("NO");
  }
}

