import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class TopoplogicalSort {

	static int V, E;
	static ArrayList<Integer>[] map;
	static boolean[] visited;
	static ArrayList<Integer> tSort;
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		V = sc.nextInt();
		E = sc.nextInt();
		
		tSort = new ArrayList<Integer>();
		visited = new boolean[V];
		map = new ArrayList[V];
		for (int i = 0; i < V; i++) {
			map[i] = new ArrayList<Integer>();
		}
		
		for (int i = 0; i < E; i++) {
			int u = sc.nextInt();
			int v = sc.nextInt();
			map[u].add(v);
		}
		
		for (int i = 0; i < V; i++) {
			if (!visited[i])
				dfs(i);
		}
		
		Collections.reverse(tSort);
		System.out.println(tSort);
		
		sc.close();
	}
	
	public static void dfs(int here) {
		visited[here] = true;
		
		for (int i = 0; i < map[here].size(); i++) {
			int there = map[here].get(i);
			if (!visited[there])
				dfs(there);
		}
		
		tSort.add(here);
	}
}
