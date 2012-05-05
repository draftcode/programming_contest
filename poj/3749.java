import java.math.BigInteger;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while (true) {
      String s = sc.nextLine();
      if (s.equals("ENDOFINPUT")) break;

      s = sc.nextLine();
      while (!s.equals("END")) {
        byte[] c = s.getBytes();
        for (int i = 0; i < c.length; i++) {
          if ('A' <= c[i] && c[i] <= 'Z') {
            c[i] = (byte)((((c[i] - 'A') + 21) % 26) + 'A');
          }
        }
        System.out.println(new String(c));
        s = sc.nextLine();
      }
    }
  }
}

