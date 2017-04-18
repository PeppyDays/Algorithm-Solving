import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int rslt = 1;
        int roomNum = 1;
        int addNum = 6;
        while (true) {
            if (n <= roomNum) {
                break;
            }
            roomNum += addNum;
            addNum += 6;
            rslt++;
        }
        System.out.println(rslt);
    }
}

