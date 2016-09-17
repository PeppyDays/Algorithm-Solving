import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class FIRETRUCKS {

    static int maxV = 1001;
    static int maxE = maxV*(maxV-1)/2;
    static int INF = Integer.MAX_VALUE;

    static int V, E;
    static int n, m;

    @SuppressWarnings("unchecked")
    static ArrayList<Pair>[] map = new ArrayList[maxV];
    static int distances[] = new int[maxV];
    static int fires[] = new int[maxV];
    static int stations[] = new int[maxV];

    public static void main(String[] args) throws NumberFormatException, IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        int u, v, c;
        String[] temp;

        for (int t = 0; t < T; t++) {
            temp = br.readLine().split(" ");
            V = Integer.parseInt(temp[0]);
            E = Integer.parseInt(temp[1]);
            // n: 화재난 장소의 개수, m: 소방서 개수
            n = Integer.parseInt(temp[2]);
            m = Integer.parseInt(temp[3]);

            for (int i = 0; i < V + 1; i++) {
                if (map[i] == null)
                    map[i] = new ArrayList<Pair>();
                else
                    map[i].clear();
            }

            Arrays.fill(distances, 0, V + 1, INF);

            for (int i = 0; i < E; i++) {
                temp = br.readLine().split(" ");
                u = Integer.parseInt(temp[0]);
                v = Integer.parseInt(temp[1]);
                c = Integer.parseInt(temp[2]);
                map[u].add(new Pair(v, c));
                map[v].add(new Pair(u, c));
            }

            temp = br.readLine().split(" ");
            for (int i = 0; i < temp.length; i++) {
                fires[i] = Integer.parseInt(temp[i]);
            }

            temp = br.readLine().split(" ");
            for (int i = 0; i < temp.length; i++) {
                stations[i] = Integer.parseInt(temp[i]);
            }

            // 0 -> 소방서를 연결하고, 거리는 0 으로 한다.
            for (int i = 0; i < m; i++) {
                map[0].add(new Pair(stations[i], 0));
            }

            // 0 -> fires 위치 까지의 최단 거리의 합을 구한다.
            int Answer = 0;

            dijkstra();

            for (int i = 0; i < n; i++) {
                Answer += distances[fires[i]];
            }

            System.out.println(Answer);
        }
    }

    static void dijkstra() {
        PriorityQueue<Pair> q = new PriorityQueue<Pair>();
        q.add(new Pair(0, 0));
        distances[0] = 0;

        while (!q.isEmpty()) {
            int here = q.peek().node;
            int dist_to_here = q.peek().dist;
            q.poll();

            if (distances[here] < dist_to_here)
                continue;

            for (int i = 0; i < map[here].size(); i++) {
                int there = map[here].get(i).node;
                int dist_here_to_there = map[here].get(i).dist;

                if (distances[there] > dist_to_here + dist_here_to_there) {
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
    }
}
