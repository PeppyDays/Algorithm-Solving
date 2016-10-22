import java.util.Arrays;
import java.util.Scanner;

public class QUANTIZE {

	static int INF = Integer.MAX_VALUE;
	
	static int N, S;
	static int[] number;
	static int[][] cache;
	static int[] sum;
	static int[] squareSum;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for (int t = 0; t < T; t++) {
			N = sc.nextInt();
			S = sc.nextInt();
			
			number = new int[N];
			cache = new int[N][S + 1];
			sum = new int[N];
			squareSum = new int[N];
			
			for (int i = 0; i < N; i++)
				number[i] = sc.nextInt();
			
			Arrays.sort(number);
			for (int i = 0; i < N; i++)
				Arrays.fill(cache[i], -1);
			
			sum[0] = number[0];
			squareSum[0] = number[0] * number[0];
			
			for (int i = 1; i < N; i++) {
				sum[i] = number[i] + sum[i - 1];
				squareSum[i] = number[i] * number[i] + squareSum[i - 1];
			}
			
			int Answer = quantization(0, S);
			System.out.println(Answer);
		}
		
		sc.close();
	}
	
	static int quantization(int start, int groups) {
		if (cache[start][groups] != -1)
			return cache[start][groups];
		
		if (groups == 1) {
			cache[start][groups] = variation(start, N);
			return cache[start][groups];
		};
		
		int ret = INF;
		
		for (int amount = 1; amount < N - start; amount++) {
			int subRet = quantization(start + amount, groups - 1);
			ret = Math.min(ret, variation(start, start + amount) + subRet);
		}
		
		cache[start][groups] = ret;
		return ret;
	}
	
	static int variation(int s, int e) {
		int sumDiff = sum[e - 1] - (s == 0 ? 0 : sum[s - 1]);
		int squareSumDiff = squareSum[e - 1] - (s == 0 ? 0 : squareSum[s - 1]);
		int mean = Math.round(sumDiff / (e - s));
		
		return squareSumDiff - 2 * mean * sumDiff + mean * mean;
	}
}
