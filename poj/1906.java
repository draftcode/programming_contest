import java.math.BigInteger;
import java.util.*;

public class Main {
  static List<BigInteger> list;
  static void ensure(int n) {
    if (list.size()-1 < n) {
      for (int i = list.size(); i <= n; i++) {
        list.add(list.get(i-1).multiply(BigInteger.valueOf(3)));
      }
    }
  }

  public static void main(String[] args) {
    list = new ArrayList<BigInteger>();
    list.add(BigInteger.ONE);

    Scanner scanner = new Scanner(System.in);
    while (true) {
      BigInteger bi = scanner.nextBigInteger();
      if (bi.equals(BigInteger.ZERO)) break;

      bi = bi.subtract(BigInteger.ONE);
      if (bi.equals(BigInteger.ZERO)) {
        System.out.println("{ }");
      } else {
        boolean isfirst = true;
        int bitLength = bi.bitLength();
        for (int i = 0; i < bitLength; i++) {
          if (bi.testBit(i)) {
            if (isfirst) {
              System.out.print("{ ");
              isfirst = false;
            } else {
              System.out.print(", ");
            }
            ensure(i);
            System.out.print(list.get(i));
          }
        }
        System.out.println(" }");
      }
    }
  }
}

