class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.length > nums2.length) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.length, n = nums2.length;
        int total = m + n;
        int half = total / 2;

        int left = 0, right = m;
        while (left <= right) {
            int mid1 = (left + right) / 2;
            int mid2 = half - mid1;

            int l1 = (mid1 > 0) ? nums1[mid1 - 1] : Integer.MIN_VALUE;
            int r1 = (mid1 < m) ? nums1[mid1] : Integer.MAX_VALUE;
            int l2 = (mid2 > 0) ? nums2[mid2 - 1] : Integer.MIN_VALUE;
            int r2 = (mid2 < n) ? nums2[mid2] : Integer.MAX_VALUE;

            if (l1 <= r2 && l2 <= r1) {
                if (total % 2 == 0) {
                    return (Math.max(l1, l2) + Math.min(r1, r2)) / 2.0;
                } else {
                    return Math.min(r1, r2);
                }
            } else if (l1 > r2) {
                right = mid1 - 1; // move left
            } else {
                left = mid1 + 1;  // move right
            }
        }
        return 0.0; // should never reach here
    }
}

public static void main(String[] args) {
    Solution sol = new Solution();
    int[] nums1 = {1, 3};
    int[] nums2 = {2};
    System.out.println(sol.findMedianSortedArrays(nums1, nums2)); // Output: 2.0

    nums1 = new int[]{1, 2};
    nums2 = new int[]{3, 4};
    System.out.println(sol.findMedianSortedArrays(nums1, nums2)); // Output: 2.5
}