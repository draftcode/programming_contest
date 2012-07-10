import java.math.BigInteger;
import java.util.*;

public class Main {
  int m, k;
  List<BigInteger> numers, denoms;
  Map<BigInteger, Integer> cache;

  Main(int m, int k, List<BigInteger> numers, List<BigInteger> denoms) {
    this.m = m;
    this.k = k;
    this.numers = numers;
    this.denoms = denoms;
    this.cache = new HashMap<BigInteger, Integer>();
  }

  int find_frac(BigInteger N) {
    Integer I = cache.get(N);
    if (I != null) { return I; }

    for (int i = 0; i < k; i++) {
      if (N.mod(denoms.get(i)) == BigInteger.ZERO) {
        cache.put(N, i);
        return i;
      }
    }
    return 0;
  }

  void solve(BigInteger N) {
    int count = 0;
    if (N.bitCount() == 1) {
      System.out.printf("%d", N.getLowestSetBit());
      count++;
      if (count != m) System.out.printf(" ");
    }
    while (count != m) {
      int pos = find_frac(N);
      N = N.divide(denoms.get(pos)).multiply(numers.get(pos));

      if (N.bitCount() == 1) {
        System.out.printf("%d", N.getLowestSetBit());
        count++;
        if (count != m) System.out.printf(" ");
      }
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while (true) {
      int m = sc.nextInt();
      if (m == 0) break;
      BigInteger N = sc.nextBigInteger();
      int k = sc.nextInt();
      List<BigInteger> numers = new ArrayList<BigInteger>();
      List<BigInteger> denoms = new ArrayList<BigInteger>();
      for (int i = 0; i < k; i++) {
        numers.add(sc.nextBigInteger());
        denoms.add(sc.nextBigInteger());
      }

      Main obj = new Main(m, k, numers, denoms);
      obj.solve(N);
      System.out.println("");
    }
  }
}

