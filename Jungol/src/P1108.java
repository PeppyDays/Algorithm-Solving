import java.util.Arrays;
import java.util.Scanner;

public class P1108 {

	static int INF = Integer.MAX_VALUE;
	static int maxV = 500;
	
	static int V, E;
	static int[][] map = new int[maxV][maxV];
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		E = sc.nextInt();
		V = -1;
		
		for (int i = 0; i < maxV; i++) {
			Arrays.fill(map[i], INF);
			map[i][i] = 0;
		}
		
		for (int i = 0; i < E; i++) {
			int u = sc.nextInt() - 1;
			int v = sc.nextInt() - 1;
			if (u != v)
				map[u][v] = 1;
			
			V = Math.max(V, u);
			V = Math.max(V, v);
		}
		
		V += 1;
		
		for (int k = 0; k < V; k++) {
			for (int u = 0; u < V; u++) {
				if (map[u][k] == INF)
					continue;
				
				for (int v = 0; v < V; v++) {
					if (map[k][v] == INF)
						continue;
					
					map[u][v] = Math.min(map[u][v], map[u][k] + map[k][v]);
				}
			}
		}
		
		double Answer = 0.0;
		
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				Answer += map[i][j];
			}
		}
		
		Answer /= (V * (V - 1));
		
		System.out.format("%.3f\n", Math.round(Answer * 1000.0)/1000.0);
		
		sc.close();
	}
}
