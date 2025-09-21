from collections import Counter

def allCovered(need):
    return all(x == 0 for x in need.values())

def minWindowBetter(s, t):
    n = len(s)
    ans, minLen = "", float("inf")
    for i in range(n):
        need = Counter(t)
        for j in range(i, n):
            if need[s[j]] > 0:
                need[s[j]] -= 1
            if allCovered(need):
                if j - i + 1 < minLen:
                    ans, minLen = s[i:j+1], j - i + 1
                break
    return ans

if __name__ == "__main__":
    s, t = "ADOBECODEBANC", "ABC"
    print(minWindowBetter(s, t))  # Expected: BANC
