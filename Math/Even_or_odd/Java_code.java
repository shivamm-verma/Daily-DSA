import java.util.Scanner;
public class Java_code {
    public static boolean isEven(int num) {
        return (num & 1) == 0;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = scanner.nextInt();
        if (isEven(num)) {
            System.out.println(num + " is even.");
        } else {
            System.out.println(num + " is odd.");
        }
        scanner.close();
    }
} 