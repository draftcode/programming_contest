import java.math.BigInteger;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    int[][] field = new int[7][7];
    int[][] parent = new int[7][7];
    for (int y = 0; y < 7; y++) Arrays.fill(field[y], 1);

    Scanner scanner = new Scanner(System.in);
    for (int y = 1; y < 6; y++) {
      for (int x = 1; x < 6; x++) {
        field[y][x] = scanner.nextInt();
      }
    }

    int[] dy = {0, 1, 0, -1};
    int[] dx = {1, 0, -1, 0};

    Queue<Integer> q = new ArrayDeque<Integer>();
    q.add(1*6+1);
    while (q.size() != 0) {
      int i = q.remove();
      int y = i / 6;
      int x = i % 6;

      if (y == 5 && x == 5) break;

      for (int z = 0; z < 4; z++) {
        int ny = y + dy[z];
        int nx = x + dx[z];
        int ni = ny*6+nx;
        if (parent[ny][nx] == 0 && field[ny][nx] == 0) {
          parent[ny][nx] = i;
          q.add(ni);
        }
      }
    }
    List<Integer> l = new ArrayList<Integer>();
    int x = 5*6+5;
    while (x != 1*6+1) {
      l.add(x);
      x = parent[x/6][x%6];
    }

    System.out.println("(0, 0)");
    for (int i = l.size() - 1; i >= 0; i--) {
      System.out.printf("(%d, %d)\n", l.get(i)/6-1, l.get(i)%6-1);
    }
  }
}

