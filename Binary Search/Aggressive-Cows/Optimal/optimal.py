def canPlace(stalls, cows, dist):
    count = 1
    lastPos = stalls[0]

    for i in range(1, len(stalls)):
        if stalls[i] - lastPos >= dist:
            count += 1
            lastPos = stalls[i]
        if count >= cows:
            return True
    return False

def aggressiveCows(stalls, cows):
    stalls.sort()
    low, high = 1, stalls[-1] - stalls[0]
    ans = 0

    while low <= high:
        mid = (low + high) // 2
        if canPlace(stalls, cows, mid):
            ans = mid
            low = mid + 1  # Try bigger distance
        else:
            high = mid - 1  # Try smaller distance
    return ans

if __name__ == "__main__":
    stalls = [1, 2, 8, 4, 9]
    cows = 3
    print("Maximum Minimum Distance:", aggressiveCows(stalls, cows))

"""
Time Complexity:
- Sorting: O(N log N)
- Binary Search: O(log(maxDistance))
- Placement Check: O(N) each iteration
Overall: O(N log N + N log(maxDistance))

Space Complexity: O(1)
"""
