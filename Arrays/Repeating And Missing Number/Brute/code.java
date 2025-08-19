public class code {
    public static int[] findNumbers(int[] nums) {
        int n = nums.length;
        int repeating = -1, missing = -1;

        for(int i=1;i<=n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(nums[j] == i) count++;
            }
            if(count == 0) missing = i;
            if(count > 1) repeating = i;
        }
        return new int[]{repeating, missing};
    }

    public static void main(String[] args) {
        int[] nums = {3,1,2,5,3};
        int[] ans = findNumbers(nums);
        System.out.println("Repeating: " + ans[0] + ", Missing: " + ans[1]);
    }
}
