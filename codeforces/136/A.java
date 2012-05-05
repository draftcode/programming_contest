import java.math.BigInteger;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int[] v = new int[N];
    for (int i = 0; i < N; i++) {
      int k = sc.nextInt()-1;
      v[k] = i+1;
    }

    System.out.print(v[0]);
    for (int i = 1; i < N; i++) {
      System.out.printf(" %d", v[i]);
    }
    System.out.println();
  }
}

