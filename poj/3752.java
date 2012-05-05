import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int Y = scanner.nextInt();
    int X = scanner.nextInt();
    char[][] ans = new char[Y][X];
    int[] dx = {1,0,-1,0};
    int[] dy = {0,1,0,-1};
    int x = 0, y = 0, d = 0;
    for (int i = 0; i < X*Y-1; i++) {
      ans[y][x] = (char)('A' + (i%26));
      while (y+dy[d] < 0 || Y <= y+dy[d] || x+dx[d] < 0 || X <= x+dx[d]
          || ans[y+dy[d]][x+dx[d]] != 0) {
        d = (d+1)%4;
      }
      y += dy[d];
      x += dx[d];
    }
    ans[y][x] = (char)('A' + ((X*Y-1)%26));

    for (y = 0; y < Y; y++) {
      for (x = 0; x < X; x++) {
        System.out.printf("   %c", ans[y][x]);
      }
      System.out.println();
    }
  }
}

