import java.util.HashMap;

public class Solution {
    public static int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char currentChar = s.charAt(right);

            // If character was seen and is inside the current window
            if (map.containsKey(currentChar) && map.get(currentChar) >= left) {
                left = map.get(currentChar) + 1;  // move left to avoid duplicate
            }

            map.put(currentChar, right);  // update last seen index
            maxLen = Math.max(maxLen, right - left + 1);  // update max length
        }

        return maxLen;
    }

    public static void main(String[] args) {
        String input = "abcabcbb";
        int result = lengthOfLongestSubstring(input);
        System.out.println("Length of longest substring without repeating characters: " + result);
    }
}
