#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

/**
 * Z-Algorithm for Pattern Matching
 * Time Complexity: O(n + m) where n = text length, m = pattern length
 * Space Complexity: O(n + m)
 */
class ZAlgorithm {
public:
    /**
     * Create Z-array for the given string.
     * Z[i] = length of longest substring starting from i that matches prefix
     */
    vector<int> createZArray(const string& s) {
        int n = s.length();
        vector<int> z(n, 0);
        
        // Z[0] is always 0 as it's the entire string
        z[0] = n;
        
        // Initialize left and right boundaries of the Z-box
        int left = 0, right = 0;
        
        for (int i = 1; i < n; i++) {
            if (i > right) {
                // We're outside the Z-box, need to match from scratch
                left = right = i;
                while (right < n && s[right - left] == s[right]) {
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
                    while (right < n && s[right - left] == s[right]) {
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
     * Returns vector of starting indices where pattern is found.
     */
    vector<int> findPatternOccurrences(const string& text, const string& pattern) {
        vector<int> occurrences;
        
        if (pattern.empty()) {
            return occurrences;
        }
        
        // Create combined string: pattern + '$' + text
        // '$' is a special character that doesn't appear in pattern or text
        string combined = pattern + "$" + text;
        vector<int> zArray = createZArray(combined);
        
        int patternLength = pattern.length();
        
        // Check Z-values in the text part (after the '$')
        for (int i = patternLength + 1; i < zArray.size(); i++) {
            if (zArray[i] == patternLength) {
                // Found a match starting at position (i - patternLength - 1) in text
                int textIndex = i - patternLength - 1;
                occurrences.push_back(textIndex);
            }
        }
        
        return occurrences;
    }
    
    /**
     * Optimized version with early termination and better variable names.
     */
    vector<int> findPatternOccurrencesOptimized(const string& text, const string& pattern) {
        vector<int> result;
        
        if (pattern.empty()) {
            return result;
        }
        
        int m = pattern.length();
        int n = text.length();
        
        if (m > n) {
            return result;
        }
        
        // Create Z-array for pattern + '$' + text
        string s = pattern + "$" + text;
        vector<int> z(s.length(), 0);
        z[0] = s.length();
        
        int l = 0, r = 0; // left and right boundaries of Z-box
        
        for (int i = 1; i < s.length(); i++) {
            if (i > r) {
                // Outside Z-box, expand from current position
                l = r = i;
                while (r < s.length() && s[r - l] == s[r]) {
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
                    while (r < s.length() && s[r - l] == s[r]) {
                        r++;
                    }
                    z[i] = r - l;
                    r--;
                }
            }
            
            // Check if we found a pattern match in the text part
            if (i > m && z[i] == m) {
                result.push_back(i - m - 1);
            }
        }
        
        return result;
    }
    
    /**
     * Alternative implementation using const references for better performance
     */
    vector<int> findPatternOccurrencesConstRef(const string& text, const string& pattern) {
        vector<int> result;
        
        if (pattern.empty()) {
            return result;
        }
        
        int m = pattern.length();
        int n = text.length();
        
        if (m > n) {
            return result;
        }
        
        // Reserve space for better performance
        result.reserve(n / m + 1);
        
        // Create Z-array for pattern + '$' + text
        string s;
        s.reserve(m + 1 + n);
        s = pattern + "$" + text;
        
        vector<int> z(s.length(), 0);
        z[0] = s.length();
        
        int l = 0, r = 0;
        
        for (int i = 1; i < s.length(); i++) {
            if (i > r) {
                l = r = i;
                while (r < s.length() && s[r - l] == s[r]) {
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
                    while (r < s.length() && s[r - l] == s[r]) {
                        r++;
                    }
                    z[i] = r - l;
                    r--;
                }
            }
            
            if (i > m && z[i] == m) {
                result.push_back(i - m - 1);
            }
        }
        
        return result;
    }
    
    /**
     * Print vector of integers
     */
    void printVector(const vector<int>& vec) {
        cout << "[";
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i];
            if (i < vec.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
    }
};

/**
 * Main function for testing
 */
int main() {
    ZAlgorithm zAlgo;
    
    cout << "=== Z-Algorithm Pattern Matching ===\n\n";
    
    // Test Case 1: Basic example
    string text1 = "ababcababa";
    string pattern1 = "aba";
    cout << "Test Case 1:\n";
    cout << "Text: '" << text1 << "'\n";
    cout << "Pattern: '" << pattern1 << "'\n";
    vector<int> result1 = zAlgo.findPatternOccurrences(text1, pattern1);
    cout << "Occurrences at indices: ";
    zAlgo.printVector(result1);
    cout << "\nExpected: [0, 5, 7]\n\n";
    
    // Test Case 2: No matches
    string text2 = "abcdefgh";
    string pattern2 = "xyz";
    cout << "Test Case 2:\n";
    cout << "Text: '" << text2 << "'\n";
    cout << "Pattern: '" << pattern2 << "'\n";
    vector<int> result2 = zAlgo.findPatternOccurrences(text2, pattern2);
    cout << "Occurrences at indices: ";
    zAlgo.printVector(result2);
    cout << "\nExpected: []\n\n";
    
    // Test Case 3: Pattern at beginning and end
    string text3 = "hellohello";
    string pattern3 = "hello";
    cout << "Test Case 3:\n";
    cout << "Text: '" << text3 << "'\n";
    cout << "Pattern: '" << pattern3 << "'\n";
    vector<int> result3 = zAlgo.findPatternOccurrences(text3, pattern3);
    cout << "Occurrences at indices: ";
    zAlgo.printVector(result3);
    cout << "\nExpected: [0, 5]\n\n";
    
    // Test Case 4: Overlapping patterns
    string text4 = "aaaaaa";
    string pattern4 = "aa";
    cout << "Test Case 4:\n";
    cout << "Text: '" << text4 << "'\n";
    cout << "Pattern: '" << pattern4 << "'\n";
    vector<int> result4 = zAlgo.findPatternOccurrences(text4, pattern4);
    cout << "Occurrences at indices: ";
    zAlgo.printVector(result4);
    cout << "\nExpected: [0, 1, 2, 3, 4]\n\n";
    
    // Test Case 5: Single character pattern
    string text5 = "programming";
    string pattern5 = "m";
    cout << "Test Case 5:\n";
    cout << "Text: '" << text5 << "'\n";
    cout << "Pattern: '" << pattern5 << "'\n";
    vector<int> result5 = zAlgo.findPatternOccurrences(text5, pattern5);
    cout << "Occurrences at indices: ";
    zAlgo.printVector(result5);
    cout << "\nExpected: [6, 7]\n\n";
    
    // Test Case 6: Empty pattern
    string text6 = "hello";
    string pattern6 = "";
    cout << "Test Case 6:\n";
    cout << "Text: '" << text6 << "'\n";
    cout << "Pattern: '" << pattern6 << "' (empty)\n";
    vector<int> result6 = zAlgo.findPatternOccurrences(text6, pattern6);
    cout << "Occurrences at indices: ";
    zAlgo.printVector(result6);
    cout << "\nExpected: []\n\n";
    
    // Test Case 7: Pattern longer than text
    string text7 = "abc";
    string pattern7 = "abcdef";
    cout << "Test Case 7:\n";
    cout << "Text: '" << text7 << "'\n";
    cout << "Pattern: '" << pattern7 << "'\n";
    vector<int> result7 = zAlgo.findPatternOccurrences(text7, pattern7);
    cout << "Occurrences at indices: ";
    zAlgo.printVector(result7);
    cout << "\nExpected: []\n\n";
    
    // Performance comparison
    cout << "=== Performance Test ===\n";
    
    // Large text for performance testing
    string largeText;
    largeText.reserve(40000); // Reserve space for better performance
    
    for (int i = 0; i < 10000; i++) {
        largeText += "ab";
    }
    for (int i = 0; i < 10000; i++) {
        largeText += "cd";
    }
    
    string largePattern = "ab";
    
    auto start = chrono::high_resolution_clock::now();
    vector<int> resultLarge = zAlgo.findPatternOccurrences(largeText, largePattern);
    auto end = chrono::high_resolution_clock::now();
    
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    
    cout << "Large text length: " << largeText.length() << "\n";
    cout << "Pattern: '" << largePattern << "'\n";
    cout << "Found " << resultLarge.size() << " occurrences\n";
    cout << "Time taken: " << duration.count() << " microseconds\n";
    
    cout << "First 10 occurrences: ";
    for (int i = 0; i < min(10, (int)resultLarge.size()); i++) {
        cout << resultLarge[i];
        if (i < min(10, (int)resultLarge.size()) - 1) {
            cout << ", ";
        }
    }
    cout << "\n\n";
    
    // Test optimized version
    cout << "=== Testing Optimized Version ===\n";
    start = chrono::high_resolution_clock::now();
    vector<int> resultOptimized = zAlgo.findPatternOccurrencesOptimized(largeText, largePattern);
    end = chrono::high_resolution_clock::now();
    
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    
    cout << "Optimized version time: " << duration.count() << " microseconds\n";
    cout << "Results match: " << (resultLarge == resultOptimized ? "Yes" : "No") << "\n";
    
    // Test const reference version
    cout << "\n=== Testing Const Reference Version ===\n";
    start = chrono::high_resolution_clock::now();
    vector<int> resultConstRef = zAlgo.findPatternOccurrencesConstRef(largeText, largePattern);
    end = chrono::high_resolution_clock::now();
    
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    
    cout << "Const reference version time: " << duration.count() << " microseconds\n";
    cout << "Results match: " << (resultLarge == resultConstRef ? "Yes" : "No") << "\n";
    
    return 0;
}
