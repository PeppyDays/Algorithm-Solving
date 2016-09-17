import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;

public class P1208 {

	static int INF = Integer.MAX_VALUE;
	
	static int V = 52;
	static int E;
	static int[][] Map;
	static int[] distances;
	
	static int start = 51;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] token;
		
		Map = new int[V][V];
		distances = new int[V];
		
		Arrays.fill(distances, INF);
		for (int i = 0; i < V; i++) {
			Arrays.fill(Map[i], INF);
			Map[i][i] = 0;
		}
		
		E = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < E; i++) {
			token = br.readLine().split(" ");
			
			int u = charToInt(token[0].charAt(0));
			int v = charToInt(token[1].charAt(0));
			int c = Integer.parseInt(token[2]);
			
			if (u != v && Map[v][u] > c) {
				Map[v][u] = c;
				Map[u][v] = c;
			}
		}
		
		dijkstra(start);
		
		int AnswerDist = INF;
		int AnswerNode = -1;
		
		for (int i = 26; i < V - 1; i++) {
			if (distances[i] < AnswerDist) {
				AnswerDist = distances[i];
				AnswerNode = i;
			}
		}
		
		System.out.println(intToChar(AnswerNode) + " " + AnswerDist);
		
		br.close();
	}
	
	static void dijkstra(int start) {
		PriorityQueue<Pair> q = new PriorityQueue<Pair>();
		distances[start] = 0;
		q.add(new Pair(start, 0));
		
		while (!q.isEmpty()) {
			int here = q.peek().node;
			int dist_to_here = q.peek().dist;
			q.remove();
			
			if (distances[here] < dist_to_here)
				continue;
			
			for (int there = 0; there < V; there++) {
				if (Map[here][there] == INF)
					continue;
				
				int dist_here_to_there = Map[here][there];
				
				if (distances[there] == INF ||
						distances[there] > dist_to_here + dist_here_to_there) {
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
		public String toString() {
			return "P{N(" + this.node + "), D(" + this.dist + ")}";
		}
		
		@Override
		public int compareTo(Pair p) {
			return this.dist - p.dist;
		}
	}
	
	// a = 0, z = 25, A = 26, Z = 51
	static int charToInt(char a) {
		int n = (int)a;
		return (n >= 97)? n - 97: n - 39;
	}
	
	static char intToChar(int n) {
		int a = (n <= 25)? n + 97: n + 39;
		return (char)a;
	}
}
