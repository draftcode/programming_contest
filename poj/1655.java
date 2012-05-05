import java.math.BigInteger;
import java.util.*;

public class Main {
  static List<List<Integer>> list;
  static int[] rank;

  static void calc(int i) {
    rank[i] = 1;
    for (int child : list.get(i)) {
      if (rank[child] == 0) {
        calc(child);
        rank[i] += rank[child];
      }
    }
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int T = scanner.nextInt();
    for (int t = 0; t < T; t++) {
      int N = scanner.nextInt();
      list = new ArrayList<List<Integer>>();
      for (int i = 0; i < N; i++) {
        list.add(new ArrayList<Integer>());
      }

      for (int i = 0; i < N-1; i++) {
        int a = scanner.nextInt() - 1;
        int b = scanner.nextInt() - 1;
        list.get(a).add(b);
        list.get(b).add(a);
      }

      rank = new int[N];
      calc(1);

      int ans = 0;
      int balance = Integer.MAX_VALUE;
      for (int i = 0; i < N; i++) {
        int b = 0;
        for (int child : list.get(i)) {
          if (rank[child] > rank[i]) {
            b = Math.max(b, N-rank[i]);
          } else {
            b = Math.max(b, rank[child]);
          }
        }
        if (balance > b) {
          ans = i;
          balance = b;
        }
      }

      System.out.printf("%d %d\n", ans+1, balance);
    }
  }
}

