import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class CutEdge {

	static int V, E;
	static ArrayList<Integer>[] map;
	static int[] discovered;
	static int counter;
	static ArrayList<Edge> Answer;
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		V = sc.nextInt();
		E = sc.nextInt();
		map = new ArrayList[V];
		discovered = new int[V];
		Arrays.fill(discovered, -1);
		counter = 0;
		Answer = new ArrayList<Edge>();
		
		for (int i = 0; i < V; i++)
			map[i] = new ArrayList<Integer>();
		
		for (int i = 0; i < E; i++) {
			int u = sc.nextInt();
			int v = sc.nextInt();
			map[u].add(new Integer(v));
			map[v].add(new Integer(u));
		}
		
		dfs(0, -1);
		
		System.out.println(Answer);
		
		sc.close();
	}

	static int dfs(int here, int parent) {
		discovered[here] = counter++;
		int ret = discovered[here];
		int there = -1;
		
		for (int i = 0; i < map[here].size(); i++) {
			there = map[here].get(i);
			
			if (there == parent)
				continue;
			
			if (discovered[there] == -1) {
				int subRet = dfs(there, here);
				
				if (subRet > discovered[here]) {
					Answer.add(new Edge(here, there));
				}
				
				ret = Math.min(ret, subRet);
			}
			else {
				ret = Math.min(ret, discovered[there]);
			}
		}

		return ret;
	}
	
	static class Edge implements Comparable<Edge> {
		int u;
		int v;
		
		Edge(int u, int v) {
			this.u = Math.min(u, v);
			this.v = Math.max(u, v);
		}
		
		@Override
		public String toString() {
			return "E(" + this.u + ", " + this.v + ")";
		}

		@Override
		public int compareTo(Edge e) {
			if (this.u != e.u)
				return this.u - e.u;
			else
				return this.v - e.v;
		}
	}
}
