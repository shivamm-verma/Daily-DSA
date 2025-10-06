"""
KMP (Knuth-Morris-Pratt) String Pattern Matching Algorithm
Author: Khushi Patel
Time Complexity: O(n + m)
Space Complexity: O(m)
"""

class KMPAlgorithm:
    def compute_lps(self, pattern):
        """Compute Longest Prefix Suffix (LPS) array."""
        m = len(pattern)
        lps = [0] * m
        length, i = 0, 1
        while i < m:
            if pattern[i] == pattern[length]:
                length += 1
                lps[i] = length
                i += 1
            elif length:
                length = lps[length - 1]
            else:
                i += 1
        return lps

    def search(self, text, pattern):
        """Return all starting indices where pattern is found in text."""
        n, m = len(text), len(pattern)
        if m == 0:
            return []

        lps = self.compute_lps(pattern)
        res, i, j = [], 0, 0

        while i < n:
            if text[i] == pattern[j]:
                i += 1
                j += 1
            if j == m:
                res.append(i - j)
                j = lps[j - 1]
            elif i < n and text[i] != pattern[j]:
                j = lps[j - 1] if j else i + 1 - i
                if j == 0:
                    i += 1
        return res


if __name__ == "__main__":
    text = input("Enter text: ").strip()
    pattern = input("Enter pattern: ").strip()

    kmp = KMPAlgorithm()
    matches = kmp.search(text, pattern)

    if matches:
        print("Pattern found at indices:", *matches)
    else:
        print("Pattern not found")
