package 10_maximum_subarray_sum;

public class java_code {
    public int maxSubArray(int[] arr) {
        int maxSum = Integer.MIN_VALUE;
        int currSum = 0;
        for(int i : arr){
            currSum += i;
            maxSum = currSum>maxSum ? currSum : maxSum;
            if(currSum < 0){
                currSum = 0;
            }
        }

        return maxSum;
    }
}
