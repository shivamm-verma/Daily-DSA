
public class Optimal {
    public static int findPeakElement(int[] nums) {
        if(nums.length==1) return 0;
        int start = 0;
        int end = nums.length-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if((mid-1>=0?nums[mid-1]:Integer.MIN_VALUE)<nums[mid] && nums[mid]>(mid+1<nums.length?nums[mid+1]:Integer.MIN_VALUE)){
                return mid;
            }
            else if(mid+1<nums.length && nums[mid]<nums[mid+1]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        int[] nums1 = {1, 2, 3, 1};
        int[] nums2 = {1, 2, 1, 3, 5, 6, 4};

        System.out.println("Peak index in nums1: " + findPeakElement(nums1)); // Expected: 2
        System.out.println("Peak index in nums2: " + findPeakElement(nums2)); // Expected: 1 or 5
    }
}
