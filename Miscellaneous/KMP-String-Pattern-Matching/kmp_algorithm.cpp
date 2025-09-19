#include <iostream>
#include <vector>
#include <string>
using namespace std;

class KMPAlgorithm {
private:
    /**
     * Build the Longest Proper Prefix which is also Suffix (LPS) array
     * This preprocessing step is crucial for KMP algorithm efficiency
     * 
     * @param pattern: The pattern string to preprocess
     * @return: LPS array where lps[i] = length of longest proper prefix 
     *          of pattern[0..i] which is also suffix of pattern[0..i]
     */
    vector<int> computeLPS(const string& pattern) {
        int m = pattern.length();
        vector<int> lps(m, 0);
        int len = 0;  // Length of previous longest prefix suffix
        int i = 1;    // Always start from index 1, lps[0] is always 0
        
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    // Don't increment i here, we'll check pattern[i] with pattern[lps[len-1]]
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

public:
    /**
     * KMP Search Algorithm - finds all occurrences of pattern in text
     * Time Complexity: O(n + m) where n = text length, m = pattern length
     * Space Complexity: O(m) for LPS array
     * 
     * @param text: The text string to search in
     * @param pattern: The pattern string to search for
     * @return: Vector containing starting indices of all pattern occurrences
     */
    vector<int> search(const string& text, const string& pattern) {
        vector<int> result;
        int n = text.length();
        int m = pattern.length();
        
        // Edge case: empty pattern
        if (m == 0) return result;
        
        // Preprocess pattern to build LPS array
        vector<int> lps = computeLPS(pattern);
        
        int i = 0;  // Index for text
        int j = 0;  // Index for pattern
        
        while (i < n) {
            // Characters match, advance both pointers
            if (pattern[j] == text[i]) {
                i++;
                j++;
            }
            
            // Found complete pattern match
            if (j == m) {
                result.push_back(i - j);  // Add starting index of match
                j = lps[j - 1];          // Use LPS to find next possible match
            }
            // Mismatch after some matches
            else if (i < n && pattern[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1];      // Use LPS to avoid redundant comparisons
                } else {
                    i++;                 // No matches so far, just advance text pointer
                }
            }
        }
        
        return result;
    }
    
    /**
     * Utility function to display the LPS array for educational purposes
     */
    void displayLPS(const string& pattern) {
        vector<int> lps = computeLPS(pattern);
        cout << "Pattern: " << pattern << endl;
        cout << "Index  : ";
        for (int i = 0; i < pattern.length(); i++) {
            cout << i << " ";
        }
        cout << endl;
        cout << "LPS    : ";
        for (int val : lps) {
            cout << val << " ";
        }
        cout << endl;
    }
};

/**
 * Test function with multiple test cases
 */
void runTests() {
    KMPAlgorithm kmp;
    
    cout << "=== KMP String Pattern Matching Algorithm Tests ===" << endl;
    
    // Test Case 1: Basic pattern matching
    cout << "\n--- Test Case 1: Basic Pattern Matching ---" << endl;
    string text1 = "ABABDABACDABABCABCABCABCABC";
    string pattern1 = "ABABCABCABCABC";
    
    cout << "Text: " << text1 << endl;
    cout << "Pattern: " << pattern1 << endl;
    kmp.displayLPS(pattern1);
    
    vector<int> matches1 = kmp.search(text1, pattern1);
    if (matches1.empty()) {
        cout << "Pattern not found" << endl;
    } else {
        cout << "Pattern found at indices: ";
        for (int idx : matches1) {
            cout << idx << " ";
        }
        cout << endl;
    }
    
    // Test Case 2: Multiple occurrences
    cout << "\n--- Test Case 2: Multiple Occurrences ---" << endl;
    string text2 = "AABAACAADAABAABA";
    string pattern2 = "AABA";
    
    cout << "Text: " << text2 << endl;
    cout << "Pattern: " << pattern2 << endl;
    kmp.displayLPS(pattern2);
    
    vector<int> matches2 = kmp.search(text2, pattern2);
    cout << "Pattern found at indices: ";
    for (int idx : matches2) {
        cout << idx << " ";
    }
    cout << endl;
    
    // Test Case 3: Overlapping patterns
    cout << "\n--- Test Case 3: Overlapping Patterns ---" << endl;
    string text3 = "AAAAAAA";
    string pattern3 = "AAA";
    
    cout << "Text: " << text3 << endl;
    cout << "Pattern: " << pattern3 << endl;
    kmp.displayLPS(pattern3);
    
    vector<int> matches3 = kmp.search(text3, pattern3);
    cout << "Pattern found at indices: ";
    for (int idx : matches3) {
        cout << idx << " ";
    }
    cout << endl;
    
    // Test Case 4: Pattern not found
    cout << "\n--- Test Case 4: Pattern Not Found ---" << endl;
    string text4 = "ABCDEFGH";
    string pattern4 = "XYZ";
    
    cout << "Text: " << text4 << endl;
    cout << "Pattern: " << pattern4 << endl;
    
    vector<int> matches4 = kmp.search(text4, pattern4);
    if (matches4.empty()) {
        cout << "Pattern not found" << endl;
    }
    
    // Test Case 5: Single character pattern
    cout << "\n--- Test Case 5: Single Character Pattern ---" << endl;
    string text5 = "ABACABAD";
    string pattern5 = "A";
    
    cout << "Text: " << text5 << endl;
    cout << "Pattern: " << pattern5 << endl;
    
    vector<int> matches5 = kmp.search(text5, pattern5);
    cout << "Pattern found at indices: ";
    for (int idx : matches5) {
        cout << idx << " ";
    }
    cout << endl;
}

int main() {
    runTests();
    
    cout << "\n=== Interactive Mode ===" << endl;
    cout << "Enter your own text and pattern to test:" << endl;
    
    string text, pattern;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pattern);
    
    KMPAlgorithm kmp;
    vector<int> matches = kmp.search(text, pattern);
    
    if (matches.empty()) {
        cout << "Pattern not found in the text" << endl;
    } else {
        cout << "Pattern found at indices: ";
        for (int idx : matches) {
            cout << idx << " ";
        }
        cout << endl;
    }
    
    return 0;
}