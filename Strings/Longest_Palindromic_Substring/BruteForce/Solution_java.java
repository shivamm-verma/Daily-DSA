class Solution {
    // Helper function to check palindrome
    private boolean isPalindrome(String str, int l, int r) {
        while (l < r) {
            if (str.charAt(l) != str.charAt(r)) return false;
            l++;
            r--;
        }
        return true;
    }

    public String longestPalindromeBrute(String s) {
        int n = s.length();
        String longest = "";

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    if (j - i + 1 > longest.length()) {
                        longest = s.substring(i, j + 1);
                    }
                }
            }
        }
        return longest;
    }

    // Main function to test
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.longestPalindromeBrute("babad")); // "bab" or "aba"
        System.out.println(sol.longestPalindromeBrute("cbbd"));  // "bb"
    }
}
