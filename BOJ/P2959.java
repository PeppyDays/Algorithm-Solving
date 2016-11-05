import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int[] D = new int[4];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < 4; i++)
            D[i] = -1 * sc.nextInt();

        Arrays.sort(D);

        System.out.println(D[1] * D[3]);

        sc.close();
    }
}

