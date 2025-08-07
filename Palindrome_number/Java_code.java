import java.util.Scanner;
import java.util.Stack;
public class Java_code {
    public static boolean isPalindrome(int num) {
        if (num < 0) {
            return false;
        }
        if (num == 0) {
            return true;
        }
        Stack<Integer> stack = new Stack<>();
        int originalNum = num;
        while (num > 0) {
            stack.push(num % 10);
            num = num / 10;
        }
        while (!stack.isEmpty()) {
            if (stack.pop() != originalNum % 10) {
                return false;
            }
            originalNum = originalNum / 10;
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter an integer: ");
        int num = scanner.nextInt();
         if (isPalindrome(num)) {
            System.out.println(num + " is a palindrome.");
        } else {
            System.out.println(num + " is not a palindrome.");
        }
        scanner.close();
    }
} 