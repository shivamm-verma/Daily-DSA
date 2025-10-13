import java.util.*;

public class Solution {
    public int[] sumZero(int n) {
        int[] a = new int[n];
        if (n == 1) return new int[] {0};

        for (int i = 0; i < n / 2; i++) {
            a[i] = i + 1;
            a[n - 1 - i] = -(i + 1);
        }

        if (n % 2 != 0) {
            a[n / 2] = 0;
        }

        return a;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the value of n: ");
        int n = sc.nextInt();

        Solution sol = new Solution();
        int[] result = sol.sumZero(n);

        System.out.println("Array with sum zero:");
        System.out.println(Arrays.toString(result));
    }
}
