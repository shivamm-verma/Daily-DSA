import java.util.Scanner;
class Java_Code{
    public int sumOfGoodNumbers(int[] nums,int k) {
        int s=0;
        for(int i=0;i<nums.length;i++){
            if(((i-k<0)||(nums[i]>nums[i-k]))&&
                    ((i+k>=nums.length)||(nums[i]>nums[i+k]))){
                s+=nums[i];
            }
        }
        return s;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the array elements (space-separated): ");
        String[] numsString = scanner.nextLine().split(" ");
        int[] nums=new int[numsString.length];
        for (int i=0;i<numsString.length;i++) {
            nums[i]=Integer.parseInt(numsString[i]);
        }
        System.out.print("Enter the value of k: ");
        int k = scanner.nextInt();
        Java_Code solution=new Java_Code();
        int result=solution.sumOfGoodNumbers(nums, k);
        System.out.println("Sum of good numbers: " + result);
        scanner.close();
    }
} 