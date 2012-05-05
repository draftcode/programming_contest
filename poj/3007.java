import java.util.*;

public class Main {
  static String reverse(String s) {
    return (new StringBuilder(s)).reverse().toString();
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int T = scanner.nextInt();
    for (int t = 0; t < T; t++) {
      Set<String> set = new HashSet<String>();
      String s = scanner.next();

      for (int i = 0; i < s.length(); i++) {
        String A = s.substring(0, i);
        String B = s.substring(i);
        String revA = reverse(A);
        String revB = reverse(B);

        set.add(A+B);
        set.add(B+A);
        set.add(revA+B);
        set.add(B+revA);
        set.add(A+revB);
        set.add(revB+A);
        set.add(revA+revB);
        set.add(revB+revA);
      }

      System.out.println(set.size());
    }
  }
}

