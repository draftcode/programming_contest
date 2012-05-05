import java.math.BigInteger;
import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.ArrayList;

public class Main {
  static int N;
  static ArrayList<Integer> v;

  public static void parse(String s) {
    int i = 1;
    N = 0;
    v = new ArrayList<Integer>();

    while (Character.isDigit(s.charAt(i))) {
      N *= 10;
      N += s.charAt(i) - '0';
      i++;
    }
    i += 2;

    while (Character.isDigit(s.charAt(i))) {
      int k = 0;
      while (Character.isDigit(s.charAt(i))) {
        k *= 10;
        k += s.charAt(i) - '0';
        i++;
      }
      i++;

      v.add(k-1);
    }
  }

  public static BigInteger rec(int level) {
    if (level == v.size()) return BigInteger.ONE;

    BigInteger subtree_size = BigInteger.ONE;
    for (int k = v.size()-level-1; k > 0; k--) {
      subtree_size = subtree_size.multiply(BigInteger.valueOf(k));
    }

    BigInteger left_size = subtree_size.multiply(BigInteger.valueOf(v.get(level)));

    for (int k = level+1; k < v.size(); k++) {
      if (v.get(k) > v.get(level)) v.set(k, v.get(k)-1);
    }

    return left_size.add(rec(level+1));
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    boolean first = true;
    while (true) {
      String input = scanner.next();
      if (input.charAt(0) == '-') break;
      parse(input);

      if (first) {
        first = false;
        System.out.print(rec(0));
      } else {
        System.out.print(',');
        System.out.print(rec(0));
      }
    }
    System.out.println();
  }
}

