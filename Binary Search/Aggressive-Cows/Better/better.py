def can_place(stalls, cows, dist):
    count = 1
    last = stalls[0]
    for i in range(1, len(stalls)):
        if stalls[i] - last >= dist:
            count += 1
            last = stalls[i]
        if count >= cows:
            return True
    return False

def aggressive_cows(stalls, cows):
    stalls.sort()
    low, high = 1, stalls[-1] - stalls[0]
    ans = 0

    for dist in range(high, 0, -1):  # start from max possible distance
        if can_place(stalls, cows, dist):
            ans = dist
            break
    return ans

stalls = [1, 2, 8, 4, 9]
cows = 3
print(aggressive_cows(stalls, cows))

"""
Time Complexity: O(N * (max(stall) - min(stall))) worst case,
but faster in practice due to early stopping.
Space Complexity: O(1)
"""
