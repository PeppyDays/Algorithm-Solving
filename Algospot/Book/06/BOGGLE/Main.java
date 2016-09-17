import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

	static int[] dx = {-1, -1, -1,  1,  1,  1,  0,  0};
	static int[] dy = {-1,  0,  1, -1,  0,  1, -1,  1};
	static char[][] Board = new char[5][5];
	static int[][][] Cache = new int[5][5][10];
	
	static int N;
	static String Word;
	
	public static void main(String[] args) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for (int t = 0; t < T; t++) {
			
			for (int i = 0; i < 5; i++) {
				String token = br.readLine();
				
				for (int j = 0; j < 5; j++) {
					Board[i][j] = token.charAt(j);
				}
			}
			
			N = Integer.parseInt(br.readLine());
			for (int i = 0; i < N; i++) {
				Word = br.readLine();
				System.out.println(Word + " " + hasWord());
			}
		}
		
		br.close();
	}
	
	static String hasWord() {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				Arrays.fill(Cache[i][j], -1);
			}
		}
		
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (hasWord(i, j, 0) == 1)
					return "YES";
			}
		}
		
		return "NO";
	}
	
	static int hasWord(int x, int y, int idx) {
		if (x >= 5 || y >= 5 || x < 0 || y < 0 || Board[x][y] != Word.charAt(idx))
			return 0;
		
		if (Word.length()-1 == idx)
			return 1;
		
		if (Cache[x][y][idx] != -1)
			return Cache[x][y][idx];
		
		int ret = 0;
		
		for (int i = 0; i < 8; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			ret = hasWord(nextX, nextY, idx + 1);
			
			if (ret == 1)
				break;
		}
		
		Cache[x][y][idx] = ret;
		
		return ret;
	}
}
