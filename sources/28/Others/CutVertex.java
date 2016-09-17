import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class CutVertex {

	static int V, E;
	static ArrayList<Integer>[] map;
	static int[] discovered;
	static int counter;
	static boolean[] isCut;
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		V = sc.nextInt();
		E = sc.nextInt();
		map = new ArrayList[V];
		discovered = new int[V];
		isCut = new boolean[V];
		Arrays.fill(discovered, -1);
		counter = 0;
		
		for (int i = 0; i < V; i++)
			map[i] = new ArrayList<Integer>();
		
		for (int i = 0; i < E; i++) {
			int u = sc.nextInt();
			int v = sc.nextInt();
			map[u].add(new Integer(v));
			map[v].add(new Integer(u));
		}
		
		dfs(0, true);
		
		System.out.println(Arrays.toString(isCut));
		
		sc.close();
	}

	static int dfs(int here, boolean isRoot) {
		discovered[here] = counter++;
		int ret = discovered[here];
		int childCnt = 0;
		
		for (int i = 0; i < map[here].size(); i++) {
			int there = map[here].get(i);
			
			if (discovered[there] == -1) {
				int subRet = dfs(there, false);
				childCnt += 1;
				
				if (!isRoot && subRet >= discovered[here])
					isCut[here] = true;
				
				ret = Math.min(ret, subRet);
			}
			else {
				ret = Math.min(ret, discovered[there]);
			}
		}
		
		if (childCnt >= 2)
			isCut[here] = true;
		
		return ret;
	}	
}
