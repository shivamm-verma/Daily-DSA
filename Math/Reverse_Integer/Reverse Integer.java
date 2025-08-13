public class Solution {
    public int reverse(int x) {
        int rev = 0;
        boolean isNegative = false;

        if (x < 0) {
            isNegative = true;
            if (x == Integer.MIN_VALUE) // special case to avoid overflow
                return 0;
            x = -x;
        }

        while (x > 0) {
            int digit = x % 10;

            // Overflow check before multiplying
            if (rev > Integer.MAX_VALUE / 10 || (rev == Integer.MAX_VALUE / 10 && digit > 7))
                return 0;

            rev = rev * 10 + digit;
            x /= 10;
        }

        return isNegative ? -rev : rev;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int ans = sol.reverse(-123);
        System.out.println(ans);
    }
}
