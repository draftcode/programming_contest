import java.math.BigInteger;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int pages = sc.nextInt();

    int[] week = new int[7];
    for (int i = 0; i < 7; i++) {
      week[i] = sc.nextInt();
    }

    int i = -1;
    while (pages > 0) {
      i = (i+1)%7;
      pages -= week[i];
    }
    System.out.println(i+1);
  }
}

