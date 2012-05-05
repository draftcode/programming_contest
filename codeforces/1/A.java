import java.math.BigInteger;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long n = sc.nextLong();
    long m = sc.nextLong();
    long a = sc.nextLong();;

    long nreq, mreq;
    nreq = n/a;
    if (n%a != 0) nreq++;
    mreq = m/a;
    if (m%a != 0) mreq++;

    System.out.println(nreq * mreq);
  }
}

