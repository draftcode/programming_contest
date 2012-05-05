import java.math.BigInteger;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int[] v = new int[26];
    byte[] s = sc.next().getBytes();
    for (byte c : s) {
      v[c - 'A']++;
    }

    s = sc.next().getBytes();
    for (byte c : s) {
      v[c - 'A']++;
    }

    s = sc.next().getBytes();
    for (byte c : s) {
      v[c - 'A']--;
    }

    boolean ans = true;
    for (int i : v) {
      if (i != 0) {
        ans = false;
        break;
      }
    }

    if (ans) {
      System.out.println("YES");
    } else {
      System.out.println("NO");
    }
  }
}

