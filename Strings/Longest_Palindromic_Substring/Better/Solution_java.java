class Solution {
    // Helper to expand around center
    private String expandAroundCenter(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return s.substring(left + 1, right);
    }

    public String longestPalindrome(String s) {
        String longest = "";
        for (int i = 0; i < s.length(); i++) {
            String odd = expandAroundCenter(s, i, i);     // Odd length
            String even = expandAroundCenter(s, i, i + 1); // Even length

            String candidate = odd.length() > even.length() ? odd : even;
            if (candidate.length() > longest.length()) {
                longest = candidate;
            }
        }
        return longest;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.longestPalindrome("babad")); // "bab" or "aba"
        System.out.println(sol.longestPalindrome("cbbd"));  // "bb"
    }
}
