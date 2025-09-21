from collections import Counter

def containsAll(sub, t):
    count = Counter(sub)
    for c in t:
        count[c] -= 1
        if count[c] < 0:
            return False
    return True

def minWindowBrute(s, t):
    n = len(s)
    ans, minLen = "", float("inf")
    for i in range(n):
        for j in range(i, n):
            sub = s[i:j+1]
            if containsAll(sub, t) and len(sub) < minLen:
                ans, minLen = sub, len(sub)
    return ans

if __name__ == "__main__":
    s, t = "ADOBECODEBANC", "ABC"
    print(minWindowBrute(s, t))  # Expected: BANC
