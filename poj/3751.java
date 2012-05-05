import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int T = scanner.nextInt();
    for (int t = 0; t < T; t++) {
      String s = scanner.next().replaceAll("/", " ").replaceAll("-", " ").replaceAll(":", " ");
      Scanner sc = new Scanner(s);

      int year = sc.nextInt();
      int month = sc.nextInt();
      int day = sc.nextInt();
      int hour = sc.nextInt();
      int min = sc.nextInt();
      int sec = sc.nextInt();

      String ampm = "am";
      if (hour == 0) {
        hour = 12;
      } else if (hour == 12) {
        ampm = "pm";
      } else if (hour > 12) {
        hour -= 12;
        ampm = "pm";
      }

      System.out.printf("%02d/%02d/%4d-%02d:%02d:%02d%s\n", month, day, year, hour, min, sec, ampm);
    }
  }
}

