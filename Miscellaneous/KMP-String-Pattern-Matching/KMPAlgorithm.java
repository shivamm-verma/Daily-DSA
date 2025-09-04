/**
 * KMP (Knuth-Morris-Pratt) String Pattern Matching Algorithm
 * 
 * Difficulty: Hard/Optimized
 * Time Complexity: O(n + m) where n = text length, m = pattern length
 * Space Complexity: O(m) for LPS array
 * 
 * This implementation provides an efficient solution for string pattern matching
 * with linear time complexity, avoiding the quadratic time of naive approaches.
 */

import java.util.*;
import java.util.stream.Collectors;

public class KMPAlgorithm {
    
    /**
     * Compute the Longest Proper Prefix which is also Suffix (LPS) array.
     * This preprocessing step is crucial for KMP algorithm efficiency.
     * 
     * @param pattern The pattern string to preprocess
     * @return LPS array where lps[i] = length of longest proper prefix 
     *         of pattern[0..i] which is also suffix of pattern[0..i]
     */
    private static int[] computeLPS(String pattern) {
        int m = pattern.length();
        int[] lps = new int[m];
        int len = 0;  // Length of previous longest prefix suffix
        int i = 1;    // Always start from index 1, lps[0] is always 0
        
        while (i < m) {
            if (pattern.charAt(i) == pattern.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    // Don't increment i here, check pattern[i] with pattern[lps[len-1]]
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        return lps;
    }
    
    /**
     * KMP Search Algorithm - finds all occurrences of pattern in text.
     * 
     * @param text The text string to search in
     * @param pattern The pattern string to search for
     * @return List containing starting indices of all pattern occurrences
     */
    public static List<Integer> search(String text, String pattern) {
        List<Integer> result = new ArrayList<>();
        int n = text.length();
        int m = pattern.length();
        
        // Edge case: empty pattern
        if (m == 0) return result;
        
        // Preprocess pattern to build LPS array
        int[] lps = computeLPS(pattern);
        
        int i = 0;  // Index for text
        int j = 0;  // Index for pattern
        
        while (i < n) {
            // Characters match, advance both pointers
            if (pattern.charAt(j) == text.charAt(i)) {
                i++;
                j++;
            }
            
            // Found complete pattern match
            if (j == m) {
                result.add(i - j);  // Add starting index of match
                j = lps[j - 1];     // Use LPS to find next possible match
            }
            // Mismatch after some matches
            else if (i < n && pattern.charAt(j) != text.charAt(i)) {
                if (j != 0) {
                    j = lps[j - 1];  // Use LPS to avoid redundant comparisons
                } else {
                    i++;             // No matches so far, just advance text pointer
                }
            }
        }
        
        return result;
    }
    
    /**
     * Utility function to display the LPS array for educational purposes.
     * 
     * @param pattern Pattern to compute and display LPS for
     */
    public static void displayLPS(String pattern) {
        int[] lps = computeLPS(pattern);
        System.out.println("Pattern: " + pattern);
        System.out.print("Index  : ");
        for (int i = 0; i < pattern.length(); i++) {
            System.out.print(i + " ");
        }
        System.out.println();
        System.out.print("LPS    : ");
        for (int val : lps) {
            System.out.print(val + " ");
        }
        System.out.println();
        System.out.println();
    }
    
    /**
     * Search with detailed step-by-step output for educational purposes.
     * 
     * @param text Text to search in
     * @param pattern Pattern to search for
     * @return List of indices where pattern is found
     */
    public static List<Integer> searchWithDetails(String text, String pattern) {
        System.out.printf("Searching for pattern '%s' in text '%s'%n", pattern, text);
        System.out.println("-".repeat(60));
        
        // Show LPS array
        displayLPS(pattern);
        
        // Perform search
        List<Integer> matches = search(text, pattern);
        
        if (!matches.isEmpty()) {
            System.out.println("Pattern found at indices: " + matches);
            for (int idx : matches) {
                String matchedText = text.substring(idx, idx + pattern.length());
                System.out.printf("Match at index %d: '%s'%n", idx, matchedText);
            }
        } else {
            System.out.println("Pattern not found in text");
        }
        
        return matches;
    }
    
    /**
     * Test case class to organize test data
     */
    static class TestCase {
        String name;
        String text;
        String pattern;
        String description;
        
        TestCase(String name, String text, String pattern, String description) {
            this.name = name;
            this.text = text;
            this.pattern = pattern;
            this.description = description;
        }
    }
    
    /**
     * Run comprehensive test cases for KMP algorithm
     */
    public static void runComprehensiveTests() {
        System.out.println("=".repeat(60));
        System.out.println("KMP STRING PATTERN MATCHING ALGORITHM - TEST SUITE");
        System.out.println("=".repeat(60));
        
        List<TestCase> testCases = Arrays.asList(
            new TestCase("Basic Pattern Matching", 
                        "ABABDABACDABABCABCABCABCABC", "ABABCABCABCABC",
                        "Standard pattern matching with complex pattern"),
            
            new TestCase("Multiple Occurrences", 
                        "AABAACAADAABAABA", "AABA",
                        "Pattern appears multiple times in text"),
            
            new TestCase("Overlapping Patterns", 
                        "AAAAAAA", "AAA",
                        "Pattern overlaps with itself"),
            
            new TestCase("Pattern Not Found", 
                        "ABCDEFGHIJK", "XYZ",
                        "Pattern does not exist in text"),
            
            new TestCase("Single Character Pattern", 
                        "ABACABAD", "A",
                        "Single character repeated pattern"),
            
            new TestCase("Pattern Same as Text", 
                        "HELLO", "HELLO",
                        "Pattern matches entire text"),
            
            new TestCase("Empty Pattern", 
                        "HELLO WORLD", "",
                        "Edge case: empty pattern"),
            
            new TestCase("Pattern Longer than Text", 
                        "HI", "HELLO",
                        "Edge case: pattern longer than text")
        );
        
        for (int i = 0; i < testCases.size(); i++) {
            TestCase test = testCases.get(i);
            System.out.printf("%nTest Case %d: %s%n", i + 1, test.name);
            System.out.println("Description: " + test.description);
            System.out.println("-".repeat(40));
            
            List<Integer> matches = searchWithDetails(test.text, test.pattern);
            System.out.println();
        }
    }
    
    /**
     * Naive string matching algorithm for performance comparison
     */
    public static List<Integer> naiveSearch(String text, String pattern) {
        List<Integer> matches = new ArrayList<>();
        int n = text.length();
        int m = pattern.length();
        
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && text.charAt(i + j) == pattern.charAt(j)) {
                j++;
            }
            if (j == m) {
                matches.add(i);
            }
        }
        
        return matches;
    }
    
    /**
     * Compare KMP with naive string matching for performance analysis
     */
    public static void performanceComparison() {
        System.out.println("\n" + "=".repeat(60));
        System.out.println("PERFORMANCE COMPARISON: KMP vs NAIVE ALGORITHM");
        System.out.println("=".repeat(60));
        
        int[] textSizes = {1000, 5000, 10000};
        Random random = new Random(42); // Fixed seed for reproducibility
        
        for (int size : textSizes) {
            // Generate random text and pattern
            StringBuilder textBuilder = new StringBuilder();
            String chars = "ABCD";
            for (int i = 0; i < size; i++) {
                textBuilder.append(chars.charAt(random.nextInt(chars.length())));
            }
            String text = textBuilder.toString();
            
            StringBuilder patternBuilder = new StringBuilder();
            for (int i = 0; i < 10; i++) {
                patternBuilder.append(chars.charAt(random.nextInt(chars.length())));
            }
            String pattern = patternBuilder.toString();
            
            System.out.printf("%nText size: %d, Pattern size: %d%n", size, pattern.length());
            
            // Time KMP algorithm
            long startTime = System.nanoTime();
            List<Integer> kmpMatches = search(text, pattern);
            long kmpTime = System.nanoTime() - startTime;
            
            // Time naive algorithm
            startTime = System.nanoTime();
            List<Integer> naiveMatches = naiveSearch(text, pattern);
            long naiveTime = System.nanoTime() - startTime;
            
            System.out.printf("KMP Time: %.6f seconds%n", kmpTime / 1_000_000_000.0);
            System.out.printf("Naive Time: %.6f seconds%n", naiveTime / 1_000_000_000.0);
            System.out.printf("KMP is %.2fx faster%n", (double) naiveTime / kmpTime);
            System.out.printf("Matches found: %d%n", kmpMatches.size());
            
            // Verify both algorithms give same result
            if (!kmpMatches.equals(naiveMatches)) {
                throw new RuntimeException("Algorithm results don't match!");
            }
        }
    }
    
    /**
     * Interactive mode for user input
     */
    public static void interactiveMode() {
        System.out.println("\n" + "=".repeat(60));
        System.out.println("INTERACTIVE MODE - Test Your Own Inputs");
        System.out.println("=".repeat(60));
        
        Scanner scanner = new Scanner(System.in);
        
        while (true) {
            try {
                System.out.print("\nEnter text (or 'quit' to exit): ");
                String text = scanner.nextLine().trim();
                
                if ("quit".equalsIgnoreCase(text)) {
                    break;
                }
                
                System.out.print("Enter pattern: ");
                String pattern = scanner.nextLine().trim();
                
                System.out.println();
                List<Integer> matches = searchWithDetails(text, pattern);
                
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
        
        scanner.close();
    }
    
    /**
     * Main method to run all tests and demonstrations
     */
    public static void main(String[] args) {
        // Run comprehensive tests
        runComprehensiveTests();
        
        // Performance comparison
        performanceComparison();
        
        // Interactive mode
        interactiveMode();
    }
}