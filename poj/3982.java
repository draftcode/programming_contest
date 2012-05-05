import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    while (scanner.hasNext()) {
      BigInteger a = scanner.nextBigInteger();
      BigInteger b = scanner.nextBigInteger();
      BigInteger c = scanner.nextBigInteger();
      for (int i = 2; i < 99; i++) {
        BigInteger d = a.add(b).add(c);
        a = b;
        b = c;
        c = d;
      }
      System.out.println(c);
    }
  }
}

