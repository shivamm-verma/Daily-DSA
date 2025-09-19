"""
KMP (Knuth-Morris-Pratt) String Pattern Matching Algorithm
Author: Khushi Patel
Difficulty: Hard/Optimized
Time Complexity: O(n + m) where n = text length, m = pattern length
Space Complexity: O(m) for LPS array
"""

class KMPAlgorithm:
    def __init__(self):
        """Initialize KMP Algorithm class"""
        pass
    
    def compute_lps(self, pattern):
        """
        Compute the Longest Proper Prefix which is also Suffix (LPS) array.
        This preprocessing step is crucial for KMP algorithm efficiency.
        
        Args:
            pattern (str): The pattern string to preprocess
            
        Returns:
            list: LPS array where lps[i] = length of longest proper prefix 
                  of pattern[0..i] which is also suffix of pattern[0..i]
        """
        m = len(pattern)
        lps = [0] * m  # Initialize LPS array
        length = 0     # Length of previous longest prefix suffix
        i = 1          # Always start from index 1, lps[0] is always 0
        
        while i < m:
            if pattern[i] == pattern[length]:
                length += 1
                lps[i] = length
                i += 1
            else:
                if length != 0:
                    # Don't increment i here, check pattern[i] with pattern[lps[length-1]]
                    length = lps[length - 1]
                else:
                    lps[i] = 0
                    i += 1
        
        return lps
    
    def search(self, text, pattern):
        """
        KMP Search Algorithm - finds all occurrences of pattern in text.
        
        Args:
            text (str): The text string to search in
            pattern (str): The pattern string to search for
            
        Returns:
            list: List containing starting indices of all pattern occurrences
        """
        n = len(text)
        m = len(pattern)
        
        # Edge case: empty pattern
        if m == 0:
            return []
        
        # Preprocess pattern to build LPS array
        lps = self.compute_lps(pattern)
        
        result = []
        i = 0  # Index for text
        j = 0  # Index for pattern
        
        while i < n:
            # Characters match, advance both pointers
            if pattern[j] == text[i]:
                i += 1
                j += 1
            
            # Found complete pattern match
            if j == m:
                result.append(i - j)  # Add starting index of match
                j = lps[j - 1]       # Use LPS to find next possible match
            # Mismatch after some matches
            elif i < n and pattern[j] != text[i]:
                if j != 0:
                    j = lps[j - 1]   # Use LPS to avoid redundant comparisons
                else:
                    i += 1           # No matches so far, just advance text pointer
        
        return result
    
    def display_lps(self, pattern):
        """
        Utility function to display the LPS array for educational purposes.
        
        Args:
            pattern (str): Pattern to compute and display LPS for
        """
        lps = self.compute_lps(pattern)
        print(f"Pattern: {pattern}")
        print("Index  :", " ".join(str(i) for i in range(len(pattern))))
        print("LPS    :", " ".join(str(val) for val in lps))
        print()
    
    def search_with_details(self, text, pattern):
        """
        Search with detailed step-by-step output for educational purposes.
        
        Args:
            text (str): Text to search in
            pattern (str): Pattern to search for
            
        Returns:
            list: Indices where pattern is found
        """
        print(f"Searching for pattern '{pattern}' in text '{text}'")
        print("-" * 60)
        
        # Show LPS array
        self.display_lps(pattern)
        
        # Perform search
        matches = self.search(text, pattern)
        
        if matches:
            print(f"Pattern found at indices: {matches}")
            for idx in matches:
                print(f"Match at index {idx}: '{text[idx:idx+len(pattern)]}'")
        else:
            print("Pattern not found in text")
        
        return matches

def run_comprehensive_tests():
    """Run comprehensive test cases for KMP algorithm"""
    kmp = KMPAlgorithm()
    
    print("=" * 60)
    print("KMP STRING PATTERN MATCHING ALGORITHM - TEST SUITE")
    print("=" * 60)
    
    test_cases = [
        {
            "name": "Basic Pattern Matching",
            "text": "ABABDABACDABABCABCABCABCABC",
            "pattern": "ABABCABCABCABC",
            "description": "Standard pattern matching with complex pattern"
        },
        {
            "name": "Multiple Occurrences",
            "text": "AABAACAADAABAABA",
            "pattern": "AABA",
            "description": "Pattern appears multiple times in text"
        },
        {
            "name": "Overlapping Patterns",
            "text": "AAAAAAA",
            "pattern": "AAA",
            "description": "Pattern overlaps with itself"
        },
        {
            "name": "Pattern Not Found",
            "text": "ABCDEFGHIJK",
            "pattern": "XYZ",
            "description": "Pattern does not exist in text"
        },
        {
            "name": "Single Character Pattern",
            "text": "ABACABAD",
            "pattern": "A",
            "description": "Single character repeated pattern"
        },
        {
            "name": "Pattern Same as Text",
            "text": "HELLO",
            "pattern": "HELLO",
            "description": "Pattern matches entire text"
        },
        {
            "name": "Empty Pattern",
            "text": "HELLO WORLD",
            "pattern": "",
            "description": "Edge case: empty pattern"
        },
        {
            "name": "Pattern Longer than Text",
            "text": "HI",
            "pattern": "HELLO",
            "description": "Edge case: pattern longer than text"
        }
    ]
    
    for i, test in enumerate(test_cases, 1):
        print(f"\nTest Case {i}: {test['name']}")
        print(f"Description: {test['description']}")
        print("-" * 40)
        
        matches = kmp.search_with_details(test['text'], test['pattern'])
        print()

def performance_comparison():
    """Compare KMP with naive string matching for performance analysis"""
    import time
    import random
    import string
    
    def naive_search(text, pattern):
        """Naive string matching algorithm for comparison"""
        matches = []
        n, m = len(text), len(pattern)
        
        for i in range(n - m + 1):
            j = 0
            while j < m and text[i + j] == pattern[j]:
                j += 1
            if j == m:
                matches.append(i)
        
        return matches
    
    print("\n" + "=" * 60)
    print("PERFORMANCE COMPARISON: KMP vs NAIVE ALGORITHM")
    print("=" * 60)
    
    # Generate test data
    text_sizes = [1000, 5000, 10000]
    kmp = KMPAlgorithm()
    
    for size in text_sizes:
        # Generate random text and pattern
        text = ''.join(random.choices('ABCD', k=size))
        pattern = ''.join(random.choices('ABCD', k=10))
        
        print(f"\nText size: {size}, Pattern size: {len(pattern)}")
        
        # Time KMP algorithm
        start_time = time.time()
        kmp_matches = kmp.search(text, pattern)
        kmp_time = time.time() - start_time
        
        # Time naive algorithm
        start_time = time.time()
        naive_matches = naive_search(text, pattern)
        naive_time = time.time() - start_time
        
        print(f"KMP Time: {kmp_time:.6f} seconds")
        print(f"Naive Time: {naive_time:.6f} seconds")
        print(f"KMP is {naive_time/kmp_time:.2f}x faster")
        print(f"Matches found: {len(kmp_matches)}")
        
        # Verify both algorithms give same result
        assert kmp_matches == naive_matches, "Algorithm results don't match!"

def interactive_mode():
    """Interactive mode for user input"""
    kmp = KMPAlgorithm()
    
    print("\n" + "=" * 60)
    print("INTERACTIVE MODE - Test Your Own Inputs")
    print("=" * 60)
    
    while True:
        try:
            text = input("\nEnter text (or 'quit' to exit): ").strip()
            if text.lower() == 'quit':
                break
            
            pattern = input("Enter pattern: ").strip()
            
            print()
            matches = kmp.search_with_details(text, pattern)
            
        except KeyboardInterrupt:
            print("\nExiting...")
            break
        except Exception as e:
            print(f"Error: {e}")

if __name__ == "__main__":
    # Run all tests
    run_comprehensive_tests()
    
    # Performance comparison
    try:
        performance_comparison()
    except ImportError:
        print("Performance comparison requires additional modules")
    
    # Interactive mode
    interactive_mode()