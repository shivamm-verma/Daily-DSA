import java.util.Scanner;
public class Java_code {
    public static int diagonalSum(int[][] matrix, int n) {
        int sum=0;
        if (n<=0) {
            return 0;
        }
        for(int i=0;i<n;i++) {
            sum+=matrix[i][i];
            if(i!=n-1-i){
                sum+=matrix[i][n-1-i];
            }
        }
        return sum;
    }
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        System.out.print("Enter the size of the square matrix (n): ");
        int n=scanner.nextInt();
        if(n<=0){
            System.out.println("Invalid matrix size. Please enter a positive integer.");
            return;
        }
        int[][] matrix = new int[n][n];
        System.out.println("Enter the elements of the matrix:");
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                System.out.printf("Enter element at position [%d][%d]: ", i, j);
                matrix[i][j]=scanner.nextInt();
            }
        }
        int totalSum=diagonalSum(matrix, n);
        System.out.println("The sum of the main and anti-diagonals is: " + totalSum);
        scanner.close();
    }
}