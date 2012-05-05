import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    while (true) {
      String s = scanner.nextLine();
      if (s.equals("#")) break;
      System.out.println(s.replaceAll("%", "%25").replaceAll(" ", "%20").replaceAll("!", "%21").replaceAll("\\$", "%24").replaceAll("\\(", "%28").replaceAll("\\)", "%29").replaceAll("\\*", "%2a"));
    }
  }
}

