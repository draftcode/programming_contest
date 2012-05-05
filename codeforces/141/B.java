import java.math.BigInteger;
import java.util.*;

public class Main {
  static void single(int a, int x, int num) {
      if (a % 2 == 0 && x == a/2) {
        System.out.println(-1);
        return;
      } else if (a/2.0 > Math.abs(x)) {
        System.out.println(num);
      } else {
        System.out.println(-1);
      }
  }
  static void dbl(int a, int x, int left) {
    if (-a < x && x < 0) {
      System.out.println(left);
    } else if (0 < x && x < a) {
      System.out.println(left+1);
    } else {
      System.out.println(-1);
    }
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int x = sc.nextInt();
    int y = sc.nextInt();

    if (y % a == 0) {
      System.out.println(-1);
      return;
    }
    int row = y / a;
    if (row == 0) {
      single(a, x, 1);
    } else {
      if (row % 2 == 1) {
        single(a, x, 2 + (row/2)*3);
      } else {
        dbl(a, x, (row/2)*3);
      }
    }
  }
}

