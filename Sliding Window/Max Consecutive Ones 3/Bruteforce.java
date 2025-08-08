class Bruteforce {
    public int longestOnes(int[] nums, int k) {
        int max = 0;
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            int zeros = 0;

            for (int j = i; j < n; j++) {
                if (nums[j] == 0) {
                    zeros++;
                }

                if (zeros > k) {
                    break;
                }

                max = Math.max(max, j - i + 1);
            }
        }

        return max;
    }
}
