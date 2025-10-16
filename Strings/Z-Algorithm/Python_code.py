# Z-Algorithm for Pattern Matching
# Time Complexity: O(n + m) where n = text length, m = pattern length
# Space Complexity: O(n + m)

from typing import List

class ZAlgorithm:
    def __init__(self):
        pass
    
    def create_z_array(self, s: str) -> List[int]:
        """
        Create Z-array for the given string.
        Z[i] = length of longest substring starting from i that matches prefix
        """
        n = len(s)
        z = [0] * n
        
        # Z[0] is always 0 as it's the entire string
        z[0] = n
        
        # Initialize left and right boundaries of the Z-box
        left, right = 0, 0
        
        for i in range(1, n):
            if i > right:
                # We're outside the Z-box, need to match from scratch
                left = right = i
                while right < n and s[right - left] == s[right]:
                    right += 1
                z[i] = right - left
                right -= 1
            else:
                # We're inside the Z-box
                k = i - left
                
                if z[k] < right - i + 1:
                    # Z[k] is completely inside the Z-box
                    z[i] = z[k]
                else:
                    # Z[k] extends beyond the Z-box, need to check further
                    left = i
                    while right < n and s[right - left] == s[right]:
                        right += 1
                    z[i] = right - left
                    right -= 1
        
        return z
    
    def find_pattern_occurrences(self, text: str, pattern: str) -> List[int]:
        """
        Find all occurrences of pattern in text using Z-algorithm.
        Returns list of starting indices where pattern is found.
        """
        if not pattern:
            return []
        
        # Create combined string: pattern + '$' + text
        # '$' is a special character that doesn't appear in pattern or text
        combined = pattern + '$' + text
        z_array = self.create_z_array(combined)
        
        pattern_length = len(pattern)
        occurrences = []
        
        # Check Z-values in the text part (after the '$')
        for i in range(pattern_length + 1, len(z_array)):
            if z_array[i] == pattern_length:
                # Found a match starting at position (i - pattern_length - 1) in text
                text_index = i - pattern_length - 1
                occurrences.append(text_index)
        
        return occurrences
    
    def find_pattern_occurrences_optimized(self, text: str, pattern: str) -> List[int]:
        """
        Optimized version with early termination and better variable names.
        """
        if not pattern:
            return []
        
        m, n = len(pattern), len(text)
        if m > n:
            return []
        
        # Create Z-array for pattern + '$' + text
        s = pattern + '$' + text
        z = [0] * len(s)
        z[0] = len(s)
        
        l, r = 0, 0  # left and right boundaries of Z-box
        result = []
        
        for i in range(1, len(s)):
            if i > r:
                # Outside Z-box, expand from current position
                l = r = i
                while r < len(s) and s[r - l] == s[r]:
                    r += 1
                z[i] = r - l
                r -= 1
            else:
                # Inside Z-box
                k = i - l
                if z[k] < r - i + 1:
                    z[i] = z[k]
                else:
                    l = i
                    while r < len(s) and s[r - l] == s[r]:
                        r += 1
                    z[i] = r - l
                    r -= 1
            
            # Check if we found a pattern match in the text part
            if i > m and z[i] == m:
                result.append(i - m - 1)
        
        return result

def main():
    """Test the Z-Algorithm implementation with various test cases."""
    z_algo = ZAlgorithm()
    
    print("=== Z-Algorithm Pattern Matching ===\n")
    
    # Test Case 1: Basic example
    text1 = "ababcababa"
    pattern1 = "aba"
    print(f"Test Case 1:")
    print(f"Text: '{text1}'")
    print(f"Pattern: '{pattern1}'")
    result1 = z_algo.find_pattern_occurrences(text1, pattern1)
    print(f"Occurrences at indices: {result1}")
    print(f"Expected: [0, 5, 7]")
    print()
    
    # Test Case 2: No matches
    text2 = "abcdefgh"
    pattern2 = "xyz"
    print(f"Test Case 2:")
    print(f"Text: '{text2}'")
    print(f"Pattern: '{pattern2}'")
    result2 = z_algo.find_pattern_occurrences(text2, pattern2)
    print(f"Occurrences at indices: {result2}")
    print(f"Expected: []")
    print()
    
    # Test Case 3: Pattern at beginning and end
    text3 = "hellohello"
    pattern3 = "hello"
    print(f"Test Case 3:")
    print(f"Text: '{text3}'")
    print(f"Pattern: '{pattern3}'")
    result3 = z_algo.find_pattern_occurrences(text3, pattern3)
    print(f"Occurrences at indices: {result3}")
    print(f"Expected: [0, 5]")
    print()
    
    # Test Case 4: Overlapping patterns
    text4 = "aaaaaa"
    pattern4 = "aa"
    print(f"Test Case 4:")
    print(f"Text: '{text4}'")
    print(f"Pattern: '{pattern4}'")
    result4 = z_algo.find_pattern_occurrences(text4, pattern4)
    print(f"Occurrences at indices: {result4}")
    print(f"Expected: [0, 1, 2, 3, 4]")
    print()
    
    # Test Case 5: Single character pattern
    text5 = "programming"
    pattern5 = "m"
    print(f"Test Case 5:")
    print(f"Text: '{text5}'")
    print(f"Pattern: '{pattern5}'")
    result5 = z_algo.find_pattern_occurrences(text5, pattern5)
    print(f"Occurrences at indices: {result5}")
    print(f"Expected: [6, 7]")
    print()
    
    # Test Case 6: Empty pattern
    text6 = "hello"
    pattern6 = ""
    print(f"Test Case 6:")
    print(f"Text: '{text6}'")
    print(f"Pattern: '{pattern6}' (empty)")
    result6 = z_algo.find_pattern_occurrences(text6, pattern6)
    print(f"Occurrences at indices: {result6}")
    print(f"Expected: []")
    print()
    
    # Test Case 7: Pattern longer than text
    text7 = "abc"
    pattern7 = "abcdef"
    print(f"Test Case 7:")
    print(f"Text: '{text7}'")
    print(f"Pattern: '{pattern7}'")
    result7 = z_algo.find_pattern_occurrences(text7, pattern7)
    print(f"Occurrences at indices: {result7}")
    print(f"Expected: []")
    print()
    
    # Performance comparison
    print("=== Performance Test ===")
    import time
    
    # Large text for performance testing
    large_text = "ab" * 10000 + "cd" * 10000
    large_pattern = "ab"
    
    start_time = time.time()
    result_large = z_algo.find_pattern_occurrences(large_text, large_pattern)
    end_time = time.time()
    
    print(f"Large text length: {len(large_text)}")
    print(f"Pattern: '{large_pattern}'")
    print(f"Found {len(result_large)} occurrences")
    print(f"Time taken: {(end_time - start_time):.6f} seconds")
    print(f"First 10 occurrences: {result_large[:10]}")

if __name__ == "__main__":
    main()
