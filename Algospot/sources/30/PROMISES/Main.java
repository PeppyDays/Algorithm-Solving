import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    static int INF = Integer.MAX_VALUE;
    static int MaxV = 200;

    static int V, M, N;
    static int[][] map;

    static int Answer;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        String[] token;

        for (int t = 0; t < T; t++) {
            token = br.readLine().split(" ");
            V = Integer.parseInt(token[0]);
            M = Integer.parseInt(token[1]);
            N = Integer.parseInt(token[2]);
            map = new int[V][V];

            for (int i = 0; i < V; i++) {
                Arrays.fill(map[i], INF);
                map[i][i] = 0;
            }

            for (int k = 0; k < M; k++) {
                token = br.readLine().split(" ");
                int u = Integer.parseInt(token[0]);
                int v = Integer.parseInt(token[1]);
                int c = Integer.parseInt(token[2]);

                if (map[u][v] > c) {
                    map[u][v] = c;
                    map[v][u] = c;

                    for (int i = 0; i < V; i++) {
                        for (int j = 0; j < V; j++) {
                            if (map[i][u] != INF && map[u][j] != INF)
                                map[i][j] = Math.min(map[i][j], map[i][u] + map[u][j]);

                            if (map[i][v] != INF && map[v][j] != INF)
                                map[i][j] = Math.min(map[i][j], map[i][v] + map[v][j]);
                        }
                    }
                }
            }

            Answer = 0;

            for (int l = 0; l < N; l++) {
                token = br.readLine().split(" ");
                int u = Integer.parseInt(token[0]);
                int v = Integer.parseInt(token[1]);
                int c = Integer.parseInt(token[2]);

                if (map[u][v] <= c) {
                    Answer += 1;
                    continue;
                }

                map[u][v] = c;
                map[v][u] = c;

                for (int i = 0; i < V; i++) {
                    for (int j = 0; j < V; j++) {
                        if (map[i][u] != INF && map[u][j] != INF)
                            map[i][j] = Math.min(map[i][j], map[i][u] + map[u][j]);

                        if (map[i][v] != INF && map[v][j] != INF)
                            map[i][j] = Math.min(map[i][j], map[i][v] + map[v][j]);
                    }
                }
            }

            System.out.println(Answer);
        }

        br.close();
    }
}
