import java.util.*;

/**
 * Z-Algorithm for Pattern Matching
 * Time Complexity: O(n + m) where n = text length, m = pattern length
 * Space Complexity: O(n + m)
 */
public class ZAlgorithm {
    
    /**
     * Create Z-array for the given string.
     * Z[i] = length of longest substring starting from i that matches prefix
     */
    public int[] createZArray(String s) {
        int n = s.length();
        int[] z = new int[n];
        
        // Z[0] is always 0 as it's the entire string
        z[0] = n;
        
        // Initialize left and right boundaries of the Z-box
        int left = 0, right = 0;
        
        for (int i = 1; i < n; i++) {
            if (i > right) {
                // We're outside the Z-box, need to match from scratch
                left = right = i;
                while (right < n && s.charAt(right - left) == s.charAt(right)) {
                    right++;
                }
                z[i] = right - left;
                right--;
            } else {
                // We're inside the Z-box
                int k = i - left;
                
                if (z[k] < right - i + 1) {
                    // Z[k] is completely inside the Z-box
                    z[i] = z[k];
                } else {
                    // Z[k] extends beyond the Z-box, need to check further
                    left = i;
                    while (right < n && s.charAt(right - left) == s.charAt(right)) {
                        right++;
                    }
                    z[i] = right - left;
                    right--;
                }
            }
        }
        
        return z;
    }
    
    /**
     * Find all occurrences of pattern in text using Z-algorithm.
     * Returns list of starting indices where pattern is found.
     */
    public List<Integer> findPatternOccurrences(String text, String pattern) {
        List<Integer> occurrences = new ArrayList<>();
        
        if (pattern == null || pattern.isEmpty()) {
            return occurrences;
        }
        
        // Create combined string: pattern + '$' + text
        // '$' is a special character that doesn't appear in pattern or text
        String combined = pattern + "$" + text;
        int[] zArray = createZArray(combined);
        
        int patternLength = pattern.length();
        
        // Check Z-values in the text part (after the '$')
        for (int i = patternLength + 1; i < zArray.length; i++) {
            if (zArray[i] == patternLength) {
                // Found a match starting at position (i - patternLength - 1) in text
                int textIndex = i - patternLength - 1;
                occurrences.add(textIndex);
            }
        }
        
        return occurrences;
    }
    
    /**
     * Optimized version with early termination and better variable names.
     */
    public List<Integer> findPatternOccurrencesOptimized(String text, String pattern) {
        List<Integer> result = new ArrayList<>();
        
        if (pattern == null || pattern.isEmpty()) {
            return result;
        }
        
        int m = pattern.length();
        int n = text.length();
        
        if (m > n) {
            return result;
        }
        
        // Create Z-array for pattern + '$' + text
        String s = pattern + "$" + text;
        int[] z = new int[s.length()];
        z[0] = s.length();
        
        int l = 0, r = 0; // left and right boundaries of Z-box
        
        for (int i = 1; i < s.length(); i++) {
            if (i > r) {
                // Outside Z-box, expand from current position
                l = r = i;
                while (r < s.length() && s.charAt(r - l) == s.charAt(r)) {
                    r++;
                }
                z[i] = r - l;
                r--;
            } else {
                // Inside Z-box
                int k = i - l;
                if (z[k] < r - i + 1) {
                    z[i] = z[k];
                } else {
                    l = i;
                    while (r < s.length() && s.charAt(r - l) == s.charAt(r)) {
                        r++;
                    }
                    z[i] = r - l;
                    r--;
                }
            }
            
            // Check if we found a pattern match in the text part
            if (i > m && z[i] == m) {
                result.add(i - m - 1);
            }
        }
        
        return result;
    }
    
    /**
     * Alternative implementation using StringBuilder for better performance
     */
    public List<Integer> findPatternOccurrencesStringBuilder(String text, String pattern) {
        List<Integer> result = new ArrayList<>();
        
        if (pattern == null || pattern.isEmpty()) {
            return result;
        }
        
        int m = pattern.length();
        int n = text.length();
        
        if (m > n) {
            return result;
        }
        
        // Use StringBuilder for better performance
        StringBuilder sb = new StringBuilder();
        sb.append(pattern).append('$').append(text);
        String combined = sb.toString();
        
        int[] z = new int[combined.length()];
        z[0] = combined.length();
        
        int l = 0, r = 0;
        
        for (int i = 1; i < combined.length(); i++) {
            if (i > r) {
                l = r = i;
                while (r < combined.length() && combined.charAt(r - l) == combined.charAt(r)) {
                    r++;
                }
                z[i] = r - l;
                r--;
            } else {
                int k = i - l;
                if (z[k] < r - i + 1) {
                    z[i] = z[k];
                } else {
                    l = i;
                    while (r < combined.length() && combined.charAt(r - l) == combined.charAt(r)) {
                        r++;
                    }
                    z[i] = r - l;
                    r--;
                }
            }
            
            if (i > m && z[i] == m) {
                result.add(i - m - 1);
            }
        }
        
        return result;
    }
    
    /**
     * Main method for testing
     */
    public static void main(String[] args) {
        ZAlgorithm zAlgo = new ZAlgorithm();
        
        System.out.println("=== Z-Algorithm Pattern Matching ===\n");
        
        // Test Case 1: Basic example
        String text1 = "ababcababa";
        String pattern1 = "aba";
        System.out.println("Test Case 1:");
        System.out.println("Text: '" + text1 + "'");
        System.out.println("Pattern: '" + pattern1 + "'");
        List<Integer> result1 = zAlgo.findPatternOccurrences(text1, pattern1);
        System.out.println("Occurrences at indices: " + result1);
        System.out.println("Expected: [0, 5, 7]");
        System.out.println();
        
        // Test Case 2: No matches
        String text2 = "abcdefgh";
        String pattern2 = "xyz";
        System.out.println("Test Case 2:");
        System.out.println("Text: '" + text2 + "'");
        System.out.println("Pattern: '" + pattern2 + "'");
        List<Integer> result2 = zAlgo.findPatternOccurrences(text2, pattern2);
        System.out.println("Occurrences at indices: " + result2);
        System.out.println("Expected: []");
        System.out.println();
        
        // Test Case 3: Pattern at beginning and end
        String text3 = "hellohello";
        String pattern3 = "hello";
        System.out.println("Test Case 3:");
        System.out.println("Text: '" + text3 + "'");
        System.out.println("Pattern: '" + pattern3 + "'");
        List<Integer> result3 = zAlgo.findPatternOccurrences(text3, pattern3);
        System.out.println("Occurrences at indices: " + result3);
        System.out.println("Expected: [0, 5]");
        System.out.println();
        
        // Test Case 4: Overlapping patterns
        String text4 = "aaaaaa";
        String pattern4 = "aa";
        System.out.println("Test Case 4:");
        System.out.println("Text: '" + text4 + "'");
        System.out.println("Pattern: '" + pattern4 + "'");
        List<Integer> result4 = zAlgo.findPatternOccurrences(text4, pattern4);
        System.out.println("Occurrences at indices: " + result4);
        System.out.println("Expected: [0, 1, 2, 3, 4]");
        System.out.println();
        
        // Test Case 5: Single character pattern
        String text5 = "programming";
        String pattern5 = "m";
        System.out.println("Test Case 5:");
        System.out.println("Text: '" + text5 + "'");
        System.out.println("Pattern: '" + pattern5 + "'");
        List<Integer> result5 = zAlgo.findPatternOccurrences(text5, pattern5);
        System.out.println("Occurrences at indices: " + result5);
        System.out.println("Expected: [6, 7]");
        System.out.println();
        
        // Test Case 6: Empty pattern
        String text6 = "hello";
        String pattern6 = "";
        System.out.println("Test Case 6:");
        System.out.println("Text: '" + text6 + "'");
        System.out.println("Pattern: '" + pattern6 + "' (empty)");
        List<Integer> result6 = zAlgo.findPatternOccurrences(text6, pattern6);
        System.out.println("Occurrences at indices: " + result6);
        System.out.println("Expected: []");
        System.out.println();
        
        // Test Case 7: Pattern longer than text
        String text7 = "abc";
        String pattern7 = "abcdef";
        System.out.println("Test Case 7:");
        System.out.println("Text: '" + text7 + "'");
        System.out.println("Pattern: '" + pattern7 + "'");
        List<Integer> result7 = zAlgo.findPatternOccurrences(text7, pattern7);
        System.out.println("Occurrences at indices: " + result7);
        System.out.println("Expected: []");
        System.out.println();
        
        // Performance comparison
        System.out.println("=== Performance Test ===");
        
        // Large text for performance testing
        StringBuilder largeTextBuilder = new StringBuilder();
        for (int i = 0; i < 10000; i++) {
            largeTextBuilder.append("ab");
        }
        for (int i = 0; i < 10000; i++) {
            largeTextBuilder.append("cd");
        }
        String largeText = largeTextBuilder.toString();
        String largePattern = "ab";
        
        long startTime = System.nanoTime();
        List<Integer> resultLarge = zAlgo.findPatternOccurrences(largeText, largePattern);
        long endTime = System.nanoTime();
        
        System.out.println("Large text length: " + largeText.length());
        System.out.println("Pattern: '" + largePattern + "'");
        System.out.println("Found " + resultLarge.size() + " occurrences");
        System.out.println("Time taken: " + (endTime - startTime) / 1_000_000.0 + " ms");
        System.out.println("First 10 occurrences: " + resultLarge.subList(0, Math.min(10, resultLarge.size())));
        
        // Test optimized version
        System.out.println("\n=== Testing Optimized Version ===");
        startTime = System.nanoTime();
        List<Integer> resultOptimized = zAlgo.findPatternOccurrencesOptimized(largeText, largePattern);
        endTime = System.nanoTime();
        
        System.out.println("Optimized version time: " + (endTime - startTime) / 1_000_000.0 + " ms");
        System.out.println("Results match: " + resultLarge.equals(resultOptimized));
    }
}
