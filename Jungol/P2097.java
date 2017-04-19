import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class P2097 {

	static int INF = Integer.MAX_VALUE;
	static int N, M;
	static int[][] Map;
	
	static int start = 0;
	static int finish = 0;
	static int[] discovered;
	static int[] parent;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		M = sc.nextInt();
		Map = new int[N][N];
		discovered = new int[N];
		parent = new int [N];
		Arrays.fill(discovered, INF);
		Arrays.fill(parent, -1);
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				Map[i][j] = sc.nextInt();
			}
		}
		
		start = 0;
		finish = M - 1;
		
		dijkstra(start);
		
		System.out.println(discovered[finish]);
		
		int here = finish;
		ArrayList<Integer> path = new ArrayList<Integer>();
		path.add(here);
		
		while (parent[here] != here) {
			here = parent[here];
			path.add(here);
		}
		
		Collections.reverse(path);
		
		for (int i = 0; i < path.size(); i++) {
			System.out.print(path.get(i).intValue() + 1);
			if (i < path.size() - 1)
				System.out.print(" ");
		}
		
		System.out.println();
		
		sc.close();
	}
	
	static void dijkstra(int start) {
		PriorityQueue<Pair> q = new PriorityQueue<Pair>();
		discovered[start] = 0;
		parent[start] = start;
		
		q.add(new Pair(start, 0));
		
		while (!q.isEmpty()) {
			int here = q.peek().node;
			int dist_to_here = q.peek().dist;
			q.poll();
			
			if (discovered[here] < dist_to_here)
				continue;
			
			for (int there = 0; there < N; there++) {
				int dist_here_to_there = Map[here][there];
				if (dist_here_to_there > 0) {
					if (discovered[there] == -1 || discovered[there] > dist_to_here + dist_here_to_there) {
						discovered[there] = dist_to_here + dist_here_to_there;
						q.add(new Pair(there, discovered[there]));
						parent[there] = here;
					}
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
