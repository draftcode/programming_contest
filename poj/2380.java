import java.math.BigInteger;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    Map<Integer, Map<Integer, Integer>> m = new HashMap<Integer, Map<Integer, Integer>>();
    Set<Integer> points = new TreeSet<Integer>();
    Set<Integer> items = new TreeSet<Integer>();
    int N = sc.nextInt();
    for (int i = 0; i < N; i++) {
      int point, item, count;
      item = sc.nextInt();
      point = sc.nextInt();
      count = sc.nextInt();
      Map<Integer, Integer> mm = m.get(point);
      if (mm == null) {
        mm = new HashMap<Integer, Integer>();
        m.put(point, mm);
        points.add(point);
      }

      Integer ii = mm.get(item);
      if (ii == null) {
        ii = Integer.valueOf(0);
        items.add(item);
      }
      ii += count;
      mm.put(item, ii);
    }

    System.out.print("-1");
    for (int item : items) System.out.printf(" %d", item);
    System.out.println();
    for (int point : points) {
      System.out.printf("%d", point);
      Map<Integer, Integer> mm = m.get(point);
      for (int item : items) {
        Integer ii = mm.get(item);
        if (ii == null) {
          System.out.print(" 0");
        } else {
          System.out.printf(" %d", ii);
        }
      }
      System.out.println();
    }
  }
}

