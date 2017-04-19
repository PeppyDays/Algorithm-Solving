import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class P1111 {

	static int[][] delta = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
	static int INF = Integer.MAX_VALUE;
	
	static int N;
	static int Top;
	static int[][] Mountain;
	static ArrayList<Pair>[] Map;
	static int[] distances;
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		Top = (sc.nextInt() - 1) * N + (sc.nextInt() - 1);
		Mountain = new int[N][N];
		Map = new ArrayList[N*N];
		distances = new int[N*N];
		Arrays.fill(distances, INF);
		
		for (int i = 0; i < N*N; i++) {
			Map[i] = new ArrayList<Pair>();
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				Mountain[i][j] = sc.nextInt();
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int idx = coorToIdx(i, j);
				int[] nearIdx = getNearIdx(i, j);
				
				for (int k = 0; k < 4; k++) {
					if (nearIdx[k] == -1)
						continue;
					
					int diff = Mountain[i][j] - Mountain[i + delta[k][0]][j + delta[k][1]];
					Map[idx].add(new Pair(nearIdx[k], getPower(diff)));
				}
			}
		}
		
		dijkstra(Top);
		
		int Answer = INF;
		// 0행
		for (int i = 0; i < N; i++) {
			Answer = Math.min(Answer, distances[i] + Mountain[0][i] * Mountain[0][i]); 
		}
		// N-1행
		for (int i = 0; i < N; i++) {
			Answer = Math.min(Answer, distances[N*(N-1) + i] + Mountain[N-1][i] * Mountain[N-1][i]);
		}
		// 0열
		for (int i = 1; i < N - 1; i++) {
			Answer = Math.min(Answer, distances[N*i] + Mountain[i][0] * Mountain[i][0]);
		}
		// N-1열
		for (int i = 1; i < N - 1; i++) {
			Answer = Math.min(Answer, distances[N*(i+1)-1] + Mountain[i][N-1] * Mountain[i][N-1]);
		}
		
		System.out.println(Answer);
		
		sc.close();
	}

	static void dijkstra(int start) {
		PriorityQueue<Pair> q = new PriorityQueue<Pair>();
		distances[start] = 0;
		q.add(new Pair(start, 0));
		
		while (!q.isEmpty()) {
			int here = q.peek().node;
			int dist_to_here = q.peek().dist;
			q.poll();
			
			if (distances[here] < dist_to_here)
				continue;
			
			for (int i = 0; i < Map[here].size(); i++) {
				int there = Map[here].get(i).node;
				int dist_here_to_there = Map[here].get(i).dist;
				
				if (distances[there] == -1 ||
						distances[there] > dist_to_here + dist_here_to_there) {
					distances[there] = dist_to_here + dist_here_to_there;
					q.add(new Pair(there, distances[there]));
				}
			}
		}
	}
	
	static int getPower(int diff) {
		if (diff == 0)
			return 0;
		else if (diff > 0)
			return diff * diff;
		else
			return -diff;
	}
	
	static int coorToIdx(int i, int j) {
		return i * N + j;
	}
	
	static int[] getNearIdx(int i, int j) {
		int[] ret = new int[4];
		Arrays.fill(ret, -1);
		
		int Idx = coorToIdx(i, j);
		int leftIdx = Idx - 1;
		int rightIdx = Idx + 1;
		
		if ((int)(leftIdx / N) == (int)(Idx / N))
			ret[0] = leftIdx;
		
		if ((int)(rightIdx / N) == (int)(Idx / N))
			ret[1] = rightIdx;
		
		int upperIdx = Idx - N;
		int lowerIdx = Idx + N;
		
		if (upperIdx >= 0)
			ret[2] = upperIdx;
		
		if (lowerIdx < N * N)
			ret[3] = lowerIdx;
		
		return ret;
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
		
		@Override
		public String toString() {
			return "P{N(" + this.node + "), D(" + this.dist + ")}";
		}
	}
}
