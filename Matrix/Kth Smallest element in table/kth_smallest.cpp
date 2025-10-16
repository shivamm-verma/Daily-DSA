#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int findKthNumber(int m, int n, int k)
    {
        // Binary search on the answer range [1, m*n]
        int left = 1;
        int right = m * n;
      
        while (left < right) 
        {
            // Calculate middle value
            int mid = left + (right - left) / 2;
          
            // Count how many numbers in the multiplication table are <= mid
            int count = 0;
            for (int row = 1; row <= m; ++row)
            {
                // For each row i, elements are: i*1, i*2, ..., i*n
                // Number of elements <= mid in row i is min(mid/i, n)
                count += std::min(mid / row, n);
            }
          
            // If count >= k, the kth smallest number is at most mid
            if (count >= k)
            {
                right = mid;
            }
            
            else
            {
                // Otherwise, the kth smallest number is greater than mid
                left = mid + 1;
            }
        }
        // left == right, which is the kth smallest number
        return left;
    }
};