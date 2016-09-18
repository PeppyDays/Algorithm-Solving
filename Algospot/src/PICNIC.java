import java.util.Scanner;

public class PICNIC {

	static int N, M;
	static boolean[][] Map;
	static boolean[] gathered;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for (int t = 0; t < T; t++) {
			N = sc.nextInt();
			M = sc.nextInt();
			Map = new boolean[N][N];
			gathered = new boolean[N];
			
			for (int i = 0; i < M; i++) {
				int u = sc.nextInt();
				int v = sc.nextInt();
				Map[u][v] = true;
				Map[v][u] = true;
			}
			
			System.out.println(makeGroup(gathered));
		}
		
		sc.close();
	}

	static int makeGroup(boolean[] gathered) {
		int c = getMinChild(gathered);
		if (c == -1)
			return 1;
		gathered[c] = true;
		
		int ret = 0;
		for (int i = 0; i < N; i++) {
			if (Map[c][i] && !gathered[i]) {
				gathered[i] = true;
				ret += makeGroup(gathered);
				gathered[i] = false;
			}
		}
		
		gathered[c] = false;
		return ret;
	}
	
	static int getMinChild(boolean[] c) {
		for (int i = 0; i < c.length; i++) {
			if (!c[i])
				return i;
		}
		
		return -1;
	}
}
