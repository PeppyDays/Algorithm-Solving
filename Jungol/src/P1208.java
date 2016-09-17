
public class P1208 {

	public static void main(String[] args) {
		
		
		
		
		
		
	}

	// a = 0, z = 25, A = 26, Z = 51
	static int charToInt(char a) {
		int n = (int)a;
		return (n >= 97)? n - 97: n - 39;
	}
	
	static char intToChar(int n) {
		int a = (n <= 25)? n + 97: n + 39;
		return (char)a;
	}
}
