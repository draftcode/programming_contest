import java.math.BigInteger;
import java.util.Scanner;
import java.util.*;

public class Main {
  static void warshallFloyd(int N) {
    for (int k = 0; k < N; k++) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          int v1 = dist[i][k];
          int v2 = dist[k][j];

          if (v1 != Integer.MAX_VALUE && v2 != Integer.MAX_VALUE) {
            dist[i][j] = Math.min(dist[i][j], v1+v2);
          }
        }
      }
    }
  }

  static int[][] edges;
  static List<List<Integer>> towns;
  static int[][] dist;

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int numRegions = scanner.nextInt();
    int numTowns = scanner.nextInt();
    int numMembers = scanner.nextInt();

    int[] initTown = new int[numMembers];
    for (int i = 0; i < numMembers; i++) {
      initTown[i] = scanner.nextInt()-1;
    }

    towns = new ArrayList<List<Integer>>();
    for (int i = 0; i < numTowns; i++) {
      towns.add(new ArrayList<Integer>());
    }

    dist = new int[numRegions][numRegions];
    for (int i = 0; i < numRegions; i++) {
      Arrays.fill(dist[i], Integer.MAX_VALUE);
      dist[i][i] = 0;
    }

    edges = new int[numTowns][numTowns];
    for (int i = 0; i < numTowns; i++) {
      Arrays.fill(edges[i], -1);
    }

    for (int i = 0; i < numRegions; i++) {
      List<Integer> list = new ArrayList<Integer>();
      int k = scanner.nextInt();
      for (int j = 0; j < k; j++) {
        int town = scanner.nextInt()-1;
        towns.get(town).add(i);
        list.add(town);
      }
      for (int j = 0; j < k; j++) {
        int a = list.get(j);
        int b = list.get((j+1)%k);
        if (b < a) {
          int t = b;
          b = a;
          a = t;
        }

        if (edges[a][b] == -1) {
          edges[a][b] = i;
        } else {
          dist[edges[a][b]][i] = 1;
          dist[i][edges[a][b]] = 1;
        }
      }
    }

    warshallFloyd(numRegions);

    int ans = Integer.MAX_VALUE;
    for (int i = 0; i < numRegions; i++) {
      int regionDistance = 0;
      for (int town : initTown) {
        int distance = Integer.MAX_VALUE;
        for (int fromRegion : towns.get(town)) {
          distance = Math.min(distance, dist[i][fromRegion]);
        }
        if (distance == Integer.MAX_VALUE) {
          regionDistance = distance;
          break;
        }
        regionDistance += distance;
      }
      ans = Math.min(ans, regionDistance);
    }

    System.out.println(ans);
  }
}

