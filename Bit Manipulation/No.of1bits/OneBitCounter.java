import java.util.Scanner;

public class OneBitCounter {
    public static int noOfOneBits(int n) {
        int cnt = 0;
        for (int i = 0; i < 31; i++) {
            if ((n & (1 << i)) != 0) {
                cnt++;
            }
        }
        return cnt;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();
        System.out.println("Number of 1-bits: " + noOfOneBits(n));
    }
}
