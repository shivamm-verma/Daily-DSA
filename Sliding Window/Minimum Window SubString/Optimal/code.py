from collections import Counter, defaultdict

def minWindowOptimal(s, t):
    if len(s) < len(t): return ""
    need = Counter(t)
    window = defaultdict(int)
    have, needCount = 0, len(need)
    l, start, minLen = 0, 0, float("inf")

    for r, c in enumerate(s):
        window[c] += 1
        if window[c] == need[c]:
            have += 1
        while have == needCount:
            if (r - l + 1) < minLen:
                start, minLen = l, r - l + 1
            window[s[l]] -= 1
            if window[s[l]] < need[s[l]]:
                have -= 1
            l += 1
    return "" if minLen == float("inf") else s[start:start+minLen]

if __name__ == "__main__":
    s, t = "ADOBECODEBANC", "ABC"
    print(minWindowOptimal(s, t))  # Expected: BANC
