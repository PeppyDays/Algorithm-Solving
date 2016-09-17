import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class ROUTING {

    static int N, M;
    static ArrayList<Node>[] map = new ArrayList[10000];
    static PriorityQueue<Node> q = new PriorityQueue<Node>();
    static double[] distances = new double[10000];

    static double Answer;

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        int from, to;
        double dist;
        String[] temp;

        for (int t = 0; t < T; t++) {
            temp = br.readLine().split(" ");
            N = Integer.parseInt(temp[0]);
            M = Integer.parseInt(temp[1]);

            for (int i = 0; i < N; i++) {
                if (map[i] != null) {
                    map[i].clear();
                }
                else {
                    map[i] = new ArrayList<Node>();
                }
            }

            Arrays.fill(distances, Double.MAX_VALUE);
            q.clear();

            for (int i = 0; i < M; i++) {
                temp = br.readLine().split(" ");
                from = Integer.parseInt(temp[0]);
                to = Integer.parseInt(temp[1]);
                dist = Double.parseDouble(temp[2]);

                map[from].add(new Node(to, dist));
                map[to].add(new Node(from, dist));
            }

            dijkstra();

            System.out.format("%.10f", distances[N - 1]);
            System.out.println();
        }
    }

    static void dijkstra() {
        q.add(new Node(0, 1.0));
        distances[0] = 1.0;

        while (!q.isEmpty()) {
            int here = q.peek().node;
            double dist_to_here = q.peek().dist;

            q.poll();

            if (distances[here] < dist_to_here || map[here] == null)
                continue;

            if (here == N - 1)
                break;

            for (int i = 0; i < map[here].size(); i++) {
                int there = map[here].get(i).node;
                double dist_here_to_there = map[here].get(i).dist;

                if (distances[there] > dist_to_here * dist_here_to_there) {
                    distances[there] = dist_to_here * dist_here_to_there;
                    q.add(new Node(there, distances[there]));
                }
            }
        }
    }

    static class Node implements Comparable<Node> {
        public int node;
        public double dist;

        Node(int node, double dist) {
            this.node = node;
            this.dist = dist;
        }

        @Override
        public int compareTo(Node n) {
            if (this.dist > n.dist)
                return 1;
            else
                return -1;
        }
    }
}
