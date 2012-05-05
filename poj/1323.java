import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int T = 1;
    while (true) {
      int M = scanner.nextInt();
      int N = scanner.nextInt();
      if (M == 0 && N == 0) break;

      int[] cards = new int[N];
      boolean[] used = new boolean[M*N+1];
      Arrays.fill(used, false);
      for (int i = 0; i < N; i++) {
        cards[i] = scanner.nextInt();
        used[cards[i]] = true;
      }
      Arrays.sort(cards);

      int min = 0;
      int usedIdx = 1;
      int ans = 0;
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M-2; j++) {
          while (used[usedIdx]) usedIdx++;
          used[usedIdx] = true;
        }
        int maxCard = cards[min];
        for (int j = maxCard; j <= M*N; j++) {
          if (!used[j]) {
            maxCard = j;
            break;
          }
        }
        if (maxCard == cards[min]) {
          while (used[usedIdx]) usedIdx++;
          used[usedIdx] = true;
          ans++;
        } else {
          used[maxCard] = true;
        }
        min++;
      }

      System.out.printf("Case %d: %d\n", T, ans);
      T++;
    }
  }
}

