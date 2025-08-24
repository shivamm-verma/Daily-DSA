public class code {
    public static int[] findNumbers(int[] nums) {
        int n = nums.length;
        long Sn = (long)n*(n+1)/2;
        long S2n = (long)n*(n+1)*(2L*n+1)/6;

        long S=0, S2=0;
        for(int x: nums){
            S += x;
            S2 += (long)x*x;
        }

        long diff = S - Sn;           // x - y
        long sqDiff = S2 - S2n;       // (x-y)(x+y)

        long sum = sqDiff / diff;     // x + y

        long x = (diff + sum)/2;
        long y = x - diff;

        return new int[]{(int)x,(int)y};
    }

    public static void main(String[] args) {
        int[] nums = {3,1,2,5,3};
        int[] ans = findNumbers(nums);
        System.out.println("Repeating: " + ans[0] + ", Missing: " + ans[1]);
    }
}
