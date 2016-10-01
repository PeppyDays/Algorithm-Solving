import java.util.Scanner;

public class P1021 {

	public static int N, M;
	public static int[][] MakePart;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		MakePart = new int[M][3];
		
		for (int i = 0; i < M; i++) {
			MakePart[i][0] = sc.nextInt();
			MakePart[i][1] = sc.nextInt();
			MakePart[i][2] = sc.nextInt();
		}
		
		int[] result = findPartCnt(N);
		
		for (int i = 0; i < N; i++)
			if (result[i] != 0)
				System.out.println(i + " " + result[i]);

		sc.close();
	}

	public static int[] findPartCnt(int partNo) {
		int[] partCnt = new int[N];
		
		boolean isBase = true;
		
		for (int i = 0; i < M; i++) {
			if (MakePart[i][0] == partNo) {
				isBase = false;
				break;
			}
		}
		
		if (isBase) {
			partCnt[partNo] = 1;
			return partCnt;
		}
			
		for (int i = 0; i< M; i++) {
			if (MakePart[i][0] == partNo) {
				int subPartNo = MakePart[i][1];
				int subPartCnt = MakePart[i][2];
				
				int[] subPartCntArray = findPartCnt(subPartNo);
				partCnt = sumCompArray(partCnt, multiCompArray(subPartCntArray, subPartCnt));
			}
		}
		
		return partCnt;
	}
	
	public static int[] sumCompArray(int[] x, int[] y) {
		int[] result = new int[x.length];
		
		for (int i = 0; i < result.length; i++)
			result[i] = x[i] + y[i];
		
		return result;
	}
	
	public static int[] multiCompArray(int[] x, int m) {
		int[] result = new int[x.length];
		
		for (int i = 0; i < result.length; i++)
			result[i] = m * x[i];
		
		return result;
	}
}
