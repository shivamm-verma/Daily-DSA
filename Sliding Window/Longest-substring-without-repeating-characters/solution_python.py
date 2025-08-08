def lengthOfLongestSubstring(s):
    last_seen = {}
    left = 0
    max_len = 0

    for right, char in enumerate(s):
        # If character is in window, move left
        if char in last_seen and last_seen[char] >= left:
            left = last_seen[char] + 1

        last_seen[char] = right  # update last seen index
        max_len = max(max_len, right - left + 1)

    return max_len

# Example usage
s = "abcabcbb"
print("Length of longest substring without repeating characters:", lengthOfLongestSubstring(s))
