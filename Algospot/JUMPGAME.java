import java.util.Scanner;

public class JUMPGAME {

	static int N;
	static int[][] Board;
	static int[][] Cache;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int t = 0; t < T; t++) {
			N = sc.nextInt();
			Board = new int[N][N];
			Cache = new int[N][N];

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					Board[i][j] = sc.nextInt();
				}
			}

			findLastPoint(0, 0);
			System.out.println((Cache[0][0] == 1)? "YES": "NO");
		}

		sc.close();
	}

	public static int findLastPoint(int x, int y) {
		if (x < 0 || x >= N || y < 0 || y >= N)
			return -1;

		if (x == N - 1 && y == N - 1)
			return 1;

		if (Cache[x][y] != 0)
			return Cache[x][y];

		int ret;
		int delta = Board[x][y];

		int subRet1 = findLastPoint(x + delta, y);
		int subRet2 = findLastPoint(x, y + delta);

		if (subRet1 == 1 || subRet2 == 1)
			ret = 1;
		else
			ret = -1;

		Cache[x][y] = ret;

		return ret;
	}
}
