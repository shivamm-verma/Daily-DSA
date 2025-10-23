import java.util.*;

public class Check_ith_bit_set_or_not {
    public static boolean isBitSet(int n, int i) {
        // Shift 1 to the left i times and perform bitwise AND
        return (n & (1 << i)) != 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int i = sc.nextInt();

        if (isBitSet(n, i))
            System.out.println("Yes");
        else
            System.out.println("No");

        sc.close();
    }
}

/*
Time Complexity: O(1)
Space Complexity: O(1)
*/

