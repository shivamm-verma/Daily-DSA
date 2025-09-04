/**
 * KMP (Knuth-Morris-Pratt) String Pattern Matching Algorithm - C Implementation
 * 
 * Difficulty: Hard/Optimized
 * Time Complexity: O(n + m) where n = text length, m = pattern length
 * Space Complexity: O(m) for LPS array
 * 
 * This implementation provides an efficient solution for string pattern matching
 * with linear time complexity, avoiding the quadratic time of naive approaches.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEXT_SIZE 10000
#define MAX_PATTERN_SIZE 1000
#define MAX_MATCHES 1000

/**
 * Structure to hold search results
 */
typedef struct {
    int* indices;
    int count;
    int capacity;
} SearchResult;

/**
 * Initialize search result structure
 */
SearchResult* createSearchResult() {
    SearchResult* result = (SearchResult*)malloc(sizeof(SearchResult));
    result->capacity = MAX_MATCHES;
    result->indices = (int*)malloc(result->capacity * sizeof(int));
    result->count = 0;
    return result;
}

/**
 * Free search result structure
 */
void freeSearchResult(SearchResult* result) {
    if (result) {
        free(result->indices);
        free(result);
    }
}

/**
 * Add index to search result
 */
void addMatch(SearchResult* result, int index) {
    if (result->count < result->capacity) {
        result->indices[result->count++] = index;
    }
}

/**
 * Compute the Longest Proper Prefix which is also Suffix (LPS) array.
 * This preprocessing step is crucial for KMP algorithm efficiency.
 * 
 * @param pattern The pattern string to preprocess
 * @param m Length of the pattern
 * @param lps Array to store LPS values (must be allocated by caller)
 */
void computeLPS(const char* pattern, int m, int* lps) {
    int len = 0;  // Length of previous longest prefix suffix
    int i = 1;    // Always start from index 1, lps[0] is always 0
    
    lps[0] = 0;   // First element is always 0
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
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
}

/**
 * KMP Search Algorithm - finds all occurrences of pattern in text.
 * 
 * @param text The text string to search in
 * @param pattern The pattern string to search for
 * @return SearchResult structure containing all match indices
 */
SearchResult* kmpSearch(const char* text, const char* pattern) {
    SearchResult* result = createSearchResult();
    int n = strlen(text);
    int m = strlen(pattern);
    
    // Edge case: empty pattern
    if (m == 0) {
        return result;
    }
    
    // Allocate and compute LPS array
    int* lps = (int*)malloc(m * sizeof(int));
    computeLPS(pattern, m, lps);
    
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
            addMatch(result, i - j);  // Add starting index of match
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
    
    free(lps);
    return result;
}

/**
 * Display the LPS array for educational purposes
 */
void displayLPS(const char* pattern) {
    int m = strlen(pattern);
    int* lps = (int*)malloc(m * sizeof(int));
    
    computeLPS(pattern, m, lps);
    
    printf("Pattern: %s\n", pattern);
    printf("Index  : ");
    for (int i = 0; i < m; i++) {
        printf("%d ", i);
    }
    printf("\n");
    printf("LPS    : ");
    for (int i = 0; i < m; i++) {
        printf("%d ", lps[i]);
    }
    printf("\n\n");
    
    free(lps);
}

/**
 * Search with detailed output for educational purposes
 */
SearchResult* searchWithDetails(const char* text, const char* pattern) {
    printf("Searching for pattern '%s' in text '%s'\n", pattern, text);
    printf("------------------------------------------------------------\n");
    
    // Show LPS array
    displayLPS(pattern);
    
    // Perform search
    SearchResult* result = kmpSearch(text, pattern);
    
    if (result->count > 0) {
        printf("Pattern found at indices: ");
        for (int i = 0; i < result->count; i++) {
            printf("%d ", result->indices[i]);
        }
        printf("\n");
        
        // Show matched substrings
        int patternLen = strlen(pattern);
        for (int i = 0; i < result->count; i++) {
            int idx = result->indices[i];
            printf("Match at index %d: '", idx);
            for (int j = 0; j < patternLen; j++) {
                printf("%c", text[idx + j]);
            }
            printf("'\n");
        }
    } else {
        printf("Pattern not found in text\n");
    }
    
    return result;
}

/**
 * Test case structure
 */
typedef struct {
    char* name;
    char* text;
    char* pattern;
    char* description;
} TestCase;

/**
 * Run comprehensive test cases for KMP algorithm
 */
void runComprehensiveTests() {
    printf("============================================================\n");
    printf("KMP STRING PATTERN MATCHING ALGORITHM - TEST SUITE (C)\n");
    printf("============================================================\n");
    
    TestCase testCases[] = {
        {
            "Basic Pattern Matching",
            "ABABDABACDABABCABCABCABCABC",
            "ABABCABCABCABC",
            "Standard pattern matching with complex pattern"
        },
        {
            "Multiple Occurrences",
            "AABAACAADAABAABA",
            "AABA",
            "Pattern appears multiple times in text"
        },
        {
            "Overlapping Patterns",
            "AAAAAAA",
            "AAA",
            "Pattern overlaps with itself"
        },
        {
            "Pattern Not Found",
            "ABCDEFGHIJK",
            "XYZ",
            "Pattern does not exist in text"
        },
        {
            "Single Character Pattern",
            "ABACABAD",
            "A",
            "Single character repeated pattern"
        },
        {
            "Pattern Same as Text",
            "HELLO",
            "HELLO",
            "Pattern matches entire text"
        },
        {
            "Empty Pattern",
            "HELLO WORLD",
            "",
            "Edge case: empty pattern"
        },
        {
            "Single Character Text and Pattern",
            "A",
            "A",
            "Minimal case: single character match"
        }
    };
    
    int numTests = sizeof(testCases) / sizeof(TestCase);
    
    for (int i = 0; i < numTests; i++) {
        printf("\nTest Case %d: %s\n", i + 1, testCases[i].name);
        printf("Description: %s\n", testCases[i].description);
        printf("----------------------------------------\n");
        
        SearchResult* result = searchWithDetails(testCases[i].text, testCases[i].pattern);
        freeSearchResult(result);
        printf("\n");
    }
}

/**
 * Naive string matching algorithm for performance comparison
 */
SearchResult* naiveSearch(const char* text, const char* pattern) {
    SearchResult* result = createSearchResult();
    int n = strlen(text);
    int m = strlen(pattern);
    
    if (m == 0) return result;
    
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) {
            addMatch(result, i);
        }
    }
    
    return result;
}

/**
 * Generate random string for performance testing
 */
void generateRandomString(char* str, int length, const char* charset) {
    int charsetSize = strlen(charset);
    for (int i = 0; i < length; i++) {
        str[i] = charset[rand() % charsetSize];
    }
    str[length] = '\0';
}

/**
 * Compare KMP with naive algorithm for performance analysis
 */
void performanceComparison() {
    printf("\n============================================================\n");
    printf("PERFORMANCE COMPARISON: KMP vs NAIVE ALGORITHM\n");
    printf("============================================================\n");
    
    int textSizes[] = {1000, 5000, 10000};
    int numSizes = sizeof(textSizes) / sizeof(int);
    const char* charset = "ABCD";
    
    srand(42); // Fixed seed for reproducibility
    
    for (int i = 0; i < numSizes; i++) {
        int size = textSizes[i];
        
        // Allocate memory for test strings
        char* text = (char*)malloc((size + 1) * sizeof(char));
        char* pattern = (char*)malloc(11 * sizeof(char)); // Pattern size = 10
        
        // Generate random strings
        generateRandomString(text, size, charset);
        generateRandomString(pattern, 10, charset);
        
        printf("\nText size: %d, Pattern size: %d\n", size, (int)strlen(pattern));
        
        // Time KMP algorithm
        clock_t start = clock();
        SearchResult* kmpResult = kmpSearch(text, pattern);
        clock_t kmpTime = clock() - start;
        
        // Time naive algorithm
        start = clock();
        SearchResult* naiveResult = naiveSearch(text, pattern);
        clock_t naiveTime = clock() - start;
        
        printf("KMP Time: %.6f seconds\n", (double)kmpTime / CLOCKS_PER_SEC);
        printf("Naive Time: %.6f seconds\n", (double)naiveTime / CLOCKS_PER_SEC);
        
        if (kmpTime > 0) {
            printf("KMP is %.2fx faster\n", (double)naiveTime / kmpTime);
        }
        printf("Matches found: %d\n", kmpResult->count);
        
        // Verify both algorithms give same result
        if (kmpResult->count != naiveResult->count) {
            printf("ERROR: Algorithm results don't match!\n");
        } else {
            // Check if all indices match
            int match = 1;
            for (int j = 0; j < kmpResult->count; j++) {
                if (kmpResult->indices[j] != naiveResult->indices[j]) {
                    match = 0;
                    break;
                }
            }
            if (!match) {
                printf("ERROR: Algorithm results don't match!\n");
            }
        }
        
        // Cleanup
        freeSearchResult(kmpResult);
        freeSearchResult(naiveResult);
        free(text);
        free(pattern);
    }
}

/**
 * Interactive mode for user input
 */
void interactiveMode() {
    printf("\n============================================================\n");
    printf("INTERACTIVE MODE - Test Your Own Inputs\n");
    printf("============================================================\n");
    
    char text[MAX_TEXT_SIZE];
    char pattern[MAX_PATTERN_SIZE];
    char input[10];
    
    while (1) {
        printf("\nEnter text (or 'quit' to exit): ");
        
        // Clear input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        
        if (fgets(text, sizeof(text), stdin) == NULL) {
            break;
        }
        
        // Remove newline character
        size_t len = strlen(text);
        if (len > 0 && text[len - 1] == '\n') {
            text[len - 1] = '\0';
        }
        
        if (strcmp(text, "quit") == 0) {
            break;
        }
        
        printf("Enter pattern: ");
        if (fgets(pattern, sizeof(pattern), stdin) == NULL) {
            break;
        }
        
        // Remove newline character
        len = strlen(pattern);
        if (len > 0 && pattern[len - 1] == '\n') {
            pattern[len - 1] = '\0';
        }
        
        printf("\n");
        SearchResult* result = searchWithDetails(text, pattern);
        freeSearchResult(result);
    }
}

/**
 * Display algorithm information
 */
void displayAlgorithmInfo() {
    printf("============================================================\n");
    printf("KMP (Knuth-Morris-Pratt) String Pattern Matching Algorithm\n");
    printf("============================================================\n");
    printf("Difficulty: Hard/Optimized\n");
    printf("Time Complexity: O(n + m)\n");
    printf("Space Complexity: O(m)\n");
    printf("Where n = text length, m = pattern length\n\n");
    
    printf("Key Features:\n");
    printf("• Linear time complexity - no backtracking in text\n");
    printf("• Uses preprocessing to build failure function (LPS array)\n");
    printf("• Efficient for finding multiple occurrences\n");
    printf("• Handles overlapping patterns correctly\n");
    printf("• Optimal for large text processing\n\n");
}

/**
 * Main function - entry point of the program
 */
int main() {
    displayAlgorithmInfo();
    
    // Run comprehensive tests
    runComprehensiveTests();
    
    // Performance comparison
    performanceComparison();
    
    // Interactive mode
    interactiveMode();
    
    printf("\nThank you for using KMP Algorithm implementation!\n");
    return 0;
}