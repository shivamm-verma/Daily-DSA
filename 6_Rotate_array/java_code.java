package 5_Rotate_array;

public class java_code {
    public void rotate(int[] nums, int k) {
        // after n rotations original arrat wil be restored
        int n = nums.length;
        k = k%n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);

    }

    void reverse(int[] nums,int st,int end){
        while(st<=end){
            int temp = nums[st];
            nums[st] = nums[end];
            nums[end] = temp;
            st++;
            end--;
        }
    }
}
