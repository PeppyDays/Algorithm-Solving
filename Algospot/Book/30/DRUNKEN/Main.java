import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Main {

    static int INF = Integer.MAX_VALUE;

    static int V, E;
    static int[][] D;
    static int[][] B, C;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] token;

        token = br.readLine().split(" ");
        V = Integer.parseInt(token[0]);
        E = Integer.parseInt(token[1]);

        D = new int[V][2];
        B = new int[V][V];
        C = new int[V][V];

        token = br.readLine().split(" ");
        for (int i = 0; i < V; i++) {
            D[i][0] = i;
            D[i][1] = Integer.parseInt(token[i]);
            Arrays.fill(B[i], INF);
            Arrays.fill(C[i], INF);
        }

        Arrays.sort(D, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[1] - o2[1];
            }
        });

        for (int i = 0; i < E; i++) {
            token = br.readLine().split(" ");
            int u = Integer.parseInt(token[0]) - 1;
            int v = Integer.parseInt(token[1]) - 1;
            int c = Integer.parseInt(token[2]);
            C[u][v] = c; C[v][u] = c;
            B[u][v] = c; B[v][u] = c;
        }

        for (int i = 0; i < V; i++) {
            C[i][i] = 0;
            B[i][i] = 0;
        }

        for (int k = 0; k < V; k++) {
            int w = D[k][0];
            int dw = D[k][1];

            for (int u = 0; u < V; u++) {
                if (C[u][w] == INF)
                    continue;

                for (int v = 0; v < V; v++) {
                    if (C[w][v] == INF)
                        continue;

                    C[u][v] = Math.min(C[u][v], C[u][w] + C[w][v]);
                    B[u][v] = Math.min(B[u][v], C[u][w] + dw + C[w][v]);
                }
            }
        }

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            token = br.readLine().split(" ");
            int u = Integer.parseInt(token[0]) - 1;
            int v = Integer.parseInt(token[1]) - 1;
            System.out.println(B[u][v]);
        }

        System.out.println();

        br.close();
    }
}
