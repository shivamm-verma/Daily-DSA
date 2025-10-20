class Solution
{
    public int minCut(String s)
    {
        // If the string is empty, return 0 cuts.
        if (s.length() == 0) return 0;
        
        int n = s.length();
      
        // isPalindrome[i][j] indicates whether substring s[i...j] is a palindrome
        boolean[][] isPalindrome = new boolean[n][n];
      
        // Initialize all entries as true 
        for (boolean[] row : isPalindrome)
        {
            Arrays.fill(row, true);
        }
      
        // Build palindrome table using dynamic programming
        // Start from the end and work backwards to ensure smaller subproblems are solved first
        for (int start = n - 1; start >= 0; start--)
        {
            for (int end = start + 1; end < n; end++)
            {
                // A substring is a palindrome if:
                // 1. First and last characters match
                // 2. The substring between them is also a palindrome
                isPalindrome[start][end] = (s.charAt(start) == s.charAt(end)) 
                                          && isPalindrome[start + 1][end - 1];
            }
        }
      
        // minCuts[i] represents the minimum cuts needed for substring s[0...i]
        int[] minCuts = new int[n];
      
        // Initialize with worst case: cut after every character
        for (int i = 0; i < n; i++)
        {
            minCuts[i] = i;
        }
      
        // Calculate minimum cuts for each position
        for (int end = 1; end < n; end++)
        {
            // Check all possible starting positions for the last palindrome partition
            for (int start = 0; start <= end; start++)
            {
                // If s[start...end] is a palindrome
                if (isPalindrome[start][end])
                {
                    // If the palindrome starts at index 0, no cuts needed for this substring
                    // Otherwise, we need 1 cut plus the minimum cuts for s[0...start-1]
                    minCuts[end] = Math.min(minCuts[end], 
                                           start > 0 ? 1 + minCuts[start - 1] : 0);
                }
            }
        }
      
        // Return minimum cuts needed for the entire string
        return minCuts[n - 1];
    }
}
