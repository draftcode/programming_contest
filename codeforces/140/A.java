import java.math.BigInteger;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    double R = sc.nextDouble();
    double r = sc.nextDouble();

    if (n == 1) {
      if (r <= R) {
        System.out.println("YES");
      } else {
        System.out.println("NO");
      }
      return;
    }

    double theta = Math.asin(r/(R-r));
    double t = Math.PI / n - theta;
    if (t > 0 || Math.abs(t) < 1.0e-10) {
      System.out.println("YES");
    } else {
      System.out.println("NO");
    }
  }
}

