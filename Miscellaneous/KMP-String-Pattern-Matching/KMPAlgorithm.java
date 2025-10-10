/**
 * KMP (Knuth-Morris-Pratt) String Pattern Matching Algorithm
 * Time Complexity: O(n + m)
 * Space Complexity: O(m)
 */

import java.util.*;

public class KMPAlgorithm {

    // Compute LPS (Longest Prefix Suffix) array
    private static int[] computeLPS(String pattern) {
        int m = pattern.length();
        int[] lps = new int[m];
        int len = 0, i = 1;
        while (i < m) {
            if (pattern.charAt(i) == pattern.charAt(len))
                lps[i++] = ++len;
            else if (len != 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
        return lps;
    }

    // KMP search algorithm
    public static List<Integer> search(String text, String pattern) {
        List<Integer> res = new ArrayList<>();
        int n = text.length(), m = pattern.length();
        if (m == 0) return res;

        int[] lps = computeLPS(pattern);
        int i = 0, j = 0;

        while (i < n) {
            if (text.charAt(i) == pattern.charAt(j)) {
                i++; j++;
            }
            if (j == m) {
                res.add(i - j);
                j = lps[j - 1];
            } else if (i < n && text.charAt(i) != pattern.charAt(j)) {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }
        return res;
    }

    // Interactive mode
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter text: ");
        String text = sc.nextLine();
        System.out.print("Enter pattern: ");
        String pattern = sc.nextLine();

        List<Integer> matches = search(text, pattern);
        if (matches.isEmpty())
            System.out.println("Pattern not found");
        else
            System.out.println("Pattern found at indices: " + matches);
        sc.close();
    }
}
