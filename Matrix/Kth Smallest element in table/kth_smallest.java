class Solution
{
    public int findKthNumber(int m, int n, int k) {
        // Initialize binary search range
        // Minimum possible value is 1 (1*1), maximum is m*n
        int left = 1;
        int right = m * n;
      
        // Binary search for the kth smallest number
        while (left < right)
        {
            // Calculate middle value using unsigned right shift to avoid overflow
            int mid = (left + right) >>> 1;
          
            // Count how many numbers in the multiplication table are <= mid
            int count = 0;
            for (int row = 1; row <= m; row++) {
                // For each row i, elements are: i*1, i*2, ..., i*n
                // Count of elements <= mid in row i is min(mid/i, n)
                count += Math.min(mid / row, n);
            }
          
            // Adjust search range based on count
            if (count >= k) {
                // If count >= k, the kth number is at most mid
                right = mid;
            } else {
                // If count < k, the kth number must be greater than mid
                left = mid + 1;
            }
        }
      
        // When left == right, we've found the kth smallest number
        return left;
    }
}
