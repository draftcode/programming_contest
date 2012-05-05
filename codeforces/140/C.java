import java.math.BigInteger;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Map<Integer, Integer> m = new TreeMap<Integer, Integer>();
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    for (int i = 0; i < N; i++) {
      int ball = scanner.nextInt();
      Integer e = m.get(ball);
      if (e == null) {
        m.put(ball, 1);
      } else {
        m.put(ball, e+1);
      }
    }
    int ans = 0;
    while (true) {
      for (Map.Entry<Integer, Integer> k : m.entrySet()) {
      }
    }
  }
}

