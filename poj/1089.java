import java.math.BigInteger;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.Map;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    TreeMap<Integer, Integer> m = new TreeMap<Integer, Integer>();

    int N = scanner.nextInt();
    for (int i = 0; i < N; i++) {
      int begin = scanner.nextInt();
      int end = scanner.nextInt();
      if (!m.containsKey(begin) || end > m.get(begin)) {
        m.put(begin, end);
      }
    }

    int v = 0;
    for (Map.Entry<Integer, Integer> entry : m.entrySet()) {
      if (v < entry.getKey()) {
        if (v != 0) {
          System.out.println(v);
        }
        System.out.print(entry.getKey());
        System.out.print(' ');
      }
      v = Math.max(v, entry.getValue());
    }
    System.out.println(v);
  }
}

