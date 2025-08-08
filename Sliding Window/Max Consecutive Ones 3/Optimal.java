class Optimal {
    public int longestOnes(int[] nums, int k) {
        //slidingwindow approach-optimal
        int zeros=0;
        int max=0;
        int i=0;
        int j=0;
        int n=nums.length;
        while(i<n && j<n){
            if(nums[j]==1)j++;
            else if(nums[j]==0){
                zeros++;
                j++;
            }
            while(i<n && zeros>k){
                if(nums[i]==0)zeros--;
                i++;
            }
            max=Math.max(max,j-i);
        }
        return max;
    }
}