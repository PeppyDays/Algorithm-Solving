import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class NTHLON {

    static int maxM = 500;
    static int maxDelta = 200;
    static int maxN = 2 * (maxDelta + 1);

    static int M, D, N;
    static int[][] Games = new int[maxM][2];
    @SuppressWarnings("unchecked")
    static ArrayList<Pair>[] map = new ArrayList[maxN];
    static int[] distances = new int[maxN];

    public static void main(String[] args) throws NumberFormatException, IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int C = Integer.parseInt(br.readLine());

        String[] temp;

        for (int c = 0; c < C; c++) {

            M = Integer.parseInt(br.readLine());

            for (int i = 0; i < M; i++) {
                temp = br.readLine().split(" ");
                Games[i][0] = Integer.parseInt(temp[0]);
                Games[i][1] = Games[i][0] - Integer.parseInt(temp[1]);
            }

            D = -1;
            for (int i = 0; i < M; i++) {
                D = Math.max(D, Math.abs(Games[i][1]));
            }

            N = 2 * (D + 1);
            for (int i = 0; i < N; i++) {
                if (map[i] == null) {
                    map[i] = new ArrayList<Pair>();
                }
                else {
                    map[i].clear();
                }

                distances[i] = -1;
            }

            for (int u = 0; u < N - 1; u++) {
                for (int v = 0; v < M; v++) {
                    if (u + Games[v][1] == D) {
                        map[u].add(new Pair(N - 1, Games[v][0]));
                    }
                    else if (u + Games[v][1] >= (N - 1) || u + Games[v][1] < 0) {
                        continue;
                    }
                    else {
                        map[u].add(new Pair(u + Games[v][1], Games[v][0]));
                    }
                }
            }

            dijkstra();

            System.out.println((distances[N - 1]==-1)? "IMPOSSIBLE":distances[N - 1]);
        }
    }

    static void dijkstra() {
        PriorityQueue<Pair> q = new PriorityQueue<Pair>();
        q.add(new Pair(D, 0));
        distances[D] = 0;

        while (!q.isEmpty()) {
            Pair p = q.poll();
            int here = p.node;
            int dist_to_here = p.dist;

            if (here == N - 1) {
                break;
            }

            if (distances[here] != -1 && distances[here] < dist_to_here) {
                continue;
            }

            for (int i = 0; i < map[here].size(); i++) {
                int there = map[here].get(i).node;
                int dist_here_to_there = map[here].get(i).dist;

                if (distances[there] == -1 || distances[there] > dist_to_here + dist_here_to_there) {
                    distances[there] = dist_to_here + dist_here_to_there;
                    q.add(new Pair(there, distances[there]));
                }
            }
        }
    }

    static class Pair implements Comparable<Pair> {
        int node;
        int dist;

        Pair(int node, int dist) {
            this.node = node;
            this.dist = dist;
        }

        @Override
        public int compareTo(Pair p) {
            return this.dist - p.dist;
        }

        public String toString() {
            return "{Node: " + this.node + ", Dist: " + this.dist + "}";
        }
    }
}
