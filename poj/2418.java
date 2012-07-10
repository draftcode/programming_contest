import java.math.BigInteger;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    HashMap<String, Integer> h = new HashMap<String, Integer>();
    int count = 0;
    while (sc.hasNextLine()) {
      String s = sc.nextLine();
      count += 1;
      Integer l = h.get(s);
      if (l == null) {
        l = Integer.valueOf(0);
      }
      h.put(s, l + 1);
    }
    Object[] keys = h.keySet().toArray();
    Arrays.sort(keys);
    double base = 100.0/count;
    for (int i = 0; i < keys.length; i++) {
      System.out.printf("%s %.4f\n", keys[i], h.get(keys[i])*base);
    }
  }
}

