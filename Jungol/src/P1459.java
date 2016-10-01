import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class P1459 {

	static int N;
	static int[] numbers = new int[101];
	static boolean[] visited = new boolean[101];
	
	public static void main(String[] args) throws IOException {
		long startTime = System.currentTimeMillis();
		
		FileInputStream fis = new FileInputStream("samples/P1459.in");
		System.setIn(fis);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		Arrays.fill(visited, 1, N + 1, false);
		for (int i = 1; i <= N; i++)
			numbers[i] = Integer.parseInt(br.readLine());
		
		int Answer = 0;
		
		for (int i = 1; i <= N; i++) {
			// 현재 노드가 이미 이전 노드에 의해 루프가 검색되어서 발견되었거나,
			// 현재 노드의 값이 이전 노드에 의해 루프가 검색되어서 발견되었거나,
			// 현재 노드의 값이 이전 노드일 경우 (이전 노드와 연결되어있다면, 이전 노드에서 루프를 찾았을 때 검색이 되었어야 한다.)
			if (visited[i] || visited[numbers[i]] || numbers[i] < i)
				continue;
			
			// 현재 노드 == 현재 노드의 값이면, 바로 루프에 추가한다.
			if (i == numbers[i]) {
				visited[i] = true;
				Answer++;
				continue;
			}
			
			// 루프를 찾아서, 루프에 속한 노드의 개수를 추가한다.
			Answer += getLoop(numbers[i], 1, i);
		}
		
		System.out.println(Answer);
		for (int i = 1; i <= N; i++)
			if (visited[i])
				System.out.println(i);
		
		long endTime = System.currentTimeMillis();
		System.out.println( "Duration(s): " + (endTime - startTime) / 1000.0 );
		
		br.close();
	}
	
	static int getLoop(int here, int counter, int first) {
		// 현재 노드가 루프를 찾기 시작한 노드라면, 방문을 성공시키고 횟수카운터를 리턴한다.
		if (here == first) {
			visited[here] = true;
			return counter;
		}
		
		// 현재 노드가 이미 방문된 노드라면, 루프를 찾기 실패했으므로 0을 리턴한다.
		if (visited[here])
			return 0;
		
		// 현재 노드를 방문했다고 치고, 다음 노드를 검색한다.
		visited[here] = true;
		int ret = getLoop(numbers[here], counter + 1, first);
		
		// 만약 ret 가 0 이면 루프 찾기가 실패한 것이므로, 현재 노드의 방문을 취소시킨다.
		if (ret == 0)
			visited[here] = false;
		
		return ret;
	}
}
