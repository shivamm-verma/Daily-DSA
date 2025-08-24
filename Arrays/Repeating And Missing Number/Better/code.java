public class code {
    public static int[] findNumbers(int[] nums) {
        int n = nums.length;
        int[] freq = new int[n+1];
        int repeating = -1, missing = -1;

        for(int x: nums) freq[x]++;

        for(int i=1;i<=n;i++){
            if(freq[i]==0) missing = i;
            if(freq[i]>1) repeating = i;
        }
        return new int[]{repeating, missing};
    }

    public static void main(String[] args) {
        int[] nums = {3,1,2,5,3};
        int[] ans = findNumbers(nums);
        System.out.println("Repeating: " + ans[0] + ", Missing: " + ans[1]);
    }
}
