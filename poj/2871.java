import java.math.BigInteger;
import java.math.BigDecimal;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    boolean first = true;
    BigDecimal prev = BigDecimal.valueOf(0);
    while (true) {
      BigDecimal i = sc.nextBigDecimal();
      if (i.equals(BigDecimal.valueOf(999))) {
        System.out.println("End of Output");
        break;
      }
      if (first) {
        first = false;
      } else {
        System.out.println(i.subtract(prev).setScale(2, BigDecimal.ROUND_HALF_UP).toString());
      }
      prev = i;
    }
  }
}

