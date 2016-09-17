import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class EdgeType {

	static int V, E;
	static ArrayList<Integer>[] map;
	static int[] discovered;
	static boolean[] finished;
	static int counter;
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		V = sc.nextInt();
		E = sc.nextInt();
		
		counter = 0;
		discovered = new int[V];
		finished = new boolean[V];
		Arrays.fill(discovered, -1);
		map = new ArrayList[V];
		for (int i = 0; i < V; i++)
			map[i] = new ArrayList<Integer>();
		
		for (int i = 0; i < E; i++) {
			int u = sc.nextInt();
			int v = sc.nextInt();
			
			map[u].add(v);
		}
		
		dfs(0);
		
		sc.close();
	}

	static void dfs(int here) {
		discovered[here] = counter;
		counter += 1;
		
		for (int i = 0; i < map[here].size(); i++) {
			int there = map[here].get(i);
			
			if (discovered[there] == -1) {
				System.out.println(here + " > " + there + ": tree edge");
				dfs(there);
			}
			else if (discovered[here] < discovered[there])
				System.out.println(here + " > " + there + ": forward edge");
			else if (finished[there])
				System.out.println(here + " > " + there + ": cross edge");
			else
				System.out.println(here + " > " + there + ": back edge");
		}
		
		finished[here] = true;
	}
}
