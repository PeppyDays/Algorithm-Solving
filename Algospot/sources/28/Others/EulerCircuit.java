import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class EulerCircuit {

	static int V, E;
	static Queue<Integer>[] map;
	static ArrayList<Integer> circuit;
	static int[] inDegree, outDegree;
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		V = sc.nextInt();
		E = sc.nextInt();
		
		circuit = new ArrayList<Integer>();
		inDegree = new int[V];
		outDegree = new int[V];
		map = new LinkedList[V];
		for (int i = 0; i < V; i++) {
			map[i] = new LinkedList<Integer>();
		}
		
		for (int i = 0; i < E; i++) {
			int u = sc.nextInt();
			int v = sc.nextInt();
			map[u].add(v);
			inDegree[v] += 1;
			outDegree[u] += 1;
		}
		
		if (isEuler()) {
			dfs(0);
			Collections.reverse(circuit);
			System.out.println(circuit);
		}
		else {
			System.out.println("Impossible!");
		}
		
		sc.close();
	}

	public static boolean isEuler() {
		boolean ret = true;
		
		for (int i = 0; i < V; i++) {
			if (inDegree[i] != outDegree[i] || inDegree[i] == 0 || outDegree[i] == 0) {
				ret = false;
				break;
			}
		}
		
		return ret;
	}
	
	public static void dfs(int here) {
		while (!map[here].isEmpty()) {
			int there = map[here].poll();
			dfs(there);
		}
		
		circuit.add(here);
	}
}
