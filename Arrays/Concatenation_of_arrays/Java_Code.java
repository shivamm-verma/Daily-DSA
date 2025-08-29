import java.util.Scanner;
class Java_Code {
    public int[] getConcatenation(int[] nums) {
        int n=nums.length;
        int[] ans=new int[2*n];
        for (int i=0;i<n;i++) {
            ans[i]=nums[i];
            ans[i+n]=nums[i];
        }
        return ans;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();
        int nums[]=new int[n];
        System.out.println("Enter the elements of the array:");
        for (int i=0;i<n;i++) {
            nums[i]=sc.nextInt();
        }
        Java_Code j=new Java_Code();
        int[] result=j.getConcatenation(nums);
        System.out.print("The concatenated array is: ");
        for (int i=0;i<result.length;i++) {
            System.out.print(result[i] + " ");
        }
        System.out.println();
        sc.close();
    }
}