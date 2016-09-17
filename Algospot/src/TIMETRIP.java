import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class TIMETRIP {

    static int maxV = 100;
    static int maxE = 1000;
    static int INF = Integer.MAX_VALUE;
    static int NINF = Integer.MIN_VALUE;

    static int V, E;
    static Edge[] edges = new Edge[maxE];
    static int[] upper = new int[maxV];
    static int[] lower = new int[maxV];
    static boolean[][] reachable = new boolean[maxV][maxV];

    static int start = 0;
    static int finish = 1;

    public static void main(String[] args) throws NumberFormatException, IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        int u, v, c;
        String[] tokens;

        for (int t = 0; t < T; t++) {
            tokens = br.readLine().split(" ");
            V = Integer.parseInt(tokens[0]);
            E = Integer.parseInt(tokens[1]);

            Arrays.fill(upper, 0, V, INF);
            Arrays.fill(lower, 0, V, NINF);

            for (int i = 0; i < V; i++) {
                Arrays.fill(reachable[i], 0, V, false);
                reachable[i][i] = true;
            }

            for (int i = 0; i < E; i++) {
                tokens = br.readLine().split(" ");
                u = Integer.parseInt(tokens[0]);
                v = Integer.parseInt(tokens[1]);
                c = Integer.parseInt(tokens[2]);
                edges[i] = new Edge(u, v, c);
                reachable[u][v] = true;
            }

            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    for (int k = 0; k < V; k++) {
                        reachable[j][k] = reachable[j][k] || (reachable[j][i] && reachable[i][k]);
                    }
                }
            }

            if (!reachable[start][finish]) {
                System.out.println("UNREACHABLE");
                continue;
            }

            upper[start] = 0;
            lower[start] = 0;

            for (int i = 0; i < V - 1; i++) {
                for (int j = 0; j < E; j++) {
                    int here = edges[j].u;
                    int there = edges[j].v;
                    int dist_here_to_there = edges[j].c;

                    if (upper[here] != INF && upper[there] > upper[here] + dist_here_to_there) {
                        upper[there] = upper[here] + dist_here_to_there;
                    }

                    if (lower[here] != NINF && lower[there] < lower[here] + dist_here_to_there) {
                        lower[there] = lower[here] + dist_here_to_there;
                    }
                }
            }

            for (int j = 0; j < E; j++) {
                int here = edges[j].u;
                int there = edges[j].v;
                int dist_here_to_there = edges[j].c;

                if (upper[here] != INF && upper[there] > upper[here] + dist_here_to_there) {
                    if ((reachable[start][here] && reachable[here][finish]) ||
                            (reachable[start][there] && reachable[there][finish])   ) {
                        upper[finish] = NINF;
                        break;
                    }
                }
            }

            for (int j = 0; j < E; j++) {
                int here = edges[j].u;
                int there = edges[j].v;
                int dist_here_to_there = edges[j].c;

                if (lower[here] != NINF && lower[there] < lower[here] + dist_here_to_there) {
                    if ((reachable[start][here] && reachable[here][finish]) ||
                            (reachable[start][there] && reachable[there][finish])   ) {
                        lower[finish] = INF;
                        break;
                    }
                }
            }

            if (upper[finish] == INF)
                System.out.print("UNREACHABLE");
            else if (upper[finish] == NINF)
                System.out.print("INFINITY");
            else
                System.out.print(upper[finish]);

            if (lower[finish] == NINF)
                System.out.println();
            else if (lower[finish] == INF)
                System.out.println(" INFINITY");
            else
                System.out.println(" " + lower[finish]);
        }
    }

    static class Edge {
        int u;
        int v;
        int c;

        Edge(int u, int v, int c) {
            this.u = u;
            this.v = v;
            this.c = c;
        }

        @Override
        public String toString() {
            return "{" + this.u + ">" + this.v + ": " + this.c + "}";
        }
    }
}
