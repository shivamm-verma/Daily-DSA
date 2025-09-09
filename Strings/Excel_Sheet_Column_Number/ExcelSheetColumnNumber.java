import java.util.Scanner;

public class Solution {
    public int titleToNumber(String columnTitle) {
        int result = 0;
        for (int i = 0; i < columnTitle.length(); i++) {
            result = result * 26 + (columnTitle.charAt(i) - 'A' + 1);
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Excel column title (e.g., 'AB'): ");
        String columnTitle = sc.nextLine();
        Solution solution = new Solution();
        System.out.println("Column Number is: " + solution.titleToNumber(columnTitle));
        sc.close();
    }
}
